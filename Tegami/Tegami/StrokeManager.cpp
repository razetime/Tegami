#include "StrokeManager.hpp"
#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <sstream>

namespace fs = std::experimental::filesystem;

StrokeManager::StrokeManager(std::string directory) {
	for (auto& dirEntry : fs::recursive_directory_iterator(directory)) {
		std::stringstream ss;
		ss << dirEntry;

		std::string fileName = ss.str();
		std::ifstream file(fileName);

		std::string tag;

		std::vector<Stroke> strokes;
		int numStrokes;

		file >> tag >> numStrokes;

		for (int i = 0; i < numStrokes; i++) {

			std::vector<Vector2> points;
			int numPoints;

			file >> tag >> tag >> numPoints;

			for (int j = 0; j < numPoints; j++) {
				int xPoint;
				int yPoint;

				file >> xPoint >> yPoint;
				xPoint -= 250;
				yPoint = 250 - yPoint;

				Vector2 point(xPoint, yPoint);
				points.push_back(point);
			}
			Stroke stroke(points);
			strokes.push_back(stroke);
		}
		Character character(strokes);
		int startIndex = directory.size() + 1;
		int numChars = fileName.size()-3-startIndex;


		std::string keyName = fileName.substr(startIndex, numChars);
		characters[keyName] = character;

	}
 }

Character StrokeManager::Get(std::string key) {
	return characters[key];
}