#include "Okaerinasai.hpp"
#include "Sprite.hpp"

Okaerinasai::Okaerinasai(Utility* utility)
	: utility(utility),
	mid(fromOsu(314, 294)), 
	path({
		fromOsu(100, 480),
		mid,
		fromOsu(520, 480)
	}),
	plants({
		fromOsu(-108, 380),
		fromOsu(748, 380),
		fromOsu(748, 480),
		fromOsu(-108, 480)
	}),
	flowers({
		fromOsu(-108, 294),
		fromOsu(748, 294),
		fromOsu(748, 450),
		fromOsu(-108, 450)
	}),
	clouds({
		fromOsu(-108, 208),
		fromOsu(170, 145),
		fromOsu(227, 167),
		fromOsu(337, 28),
		fromOsu(440, 141),
		fromOsu(410, 194),
		fromOsu(553, 228),
		fromOsu(748, 205),
		fromOsu(748, 294),
		fromOsu(-108, 294)
	}),
	leftMountains({
		fromOsu(-108, 261),
		fromOsu(111, 252),
		mid,
		fromOsu(-108, 294)
	}),
	rightMountains({
		mid,
		fromOsu(503, 269),
		fromOsu(748, 280),
		fromOsu(748, 294)
	}) {
	Time start("03:59:105");
	Time end("04:24:041");
	BoundingRectangle bounds({
		Vector2(-427, 0),
		Vector2(0, 240),
		Vector2(427, 0),
		Vector2(0, -240)
	});
	int numRects = 25;

	for (auto t = start.ms; t < end.ms; t += utility->mspf) {
		for (int i = 0; i < numRects; i++) {
			auto pos = bounds.GeneratePoint();

			Color color;
			//Polygon path;
			//Polygon plants;
			//Polygon flowers;
			//Polygon clouds;
			//Polygon leftMountains;
			//Polygon rightMountains;
			if (path.Contains(pos)) {
				color = Color(228,186,161);
			}
			else if (flowers.Contains(pos)) {
				color = Color(255,228,137);
			}
			else if (plants.Contains(pos)) {
				color = Color(48,43,37);
			}
			else if (leftMountains.Contains(pos)) {
				color = Color(54,109,139);
			}
			else if (rightMountains.Contains(pos)) {
				color = Color(54, 109, 139);
			}
			else if (clouds.Contains(pos)) {
				color = Color(254,244,242);
			}
			else {
				color = Color(25,60,114);
			}

			auto sprite = new Sprite("sprite/solidblock.png", pos);
			sprite->Fade(t, end.ms, 0, 1, Easing::QuadIn);
			sprite->Fade(end.ms, Time("04:29:885").ms, 1, 0, Easing::Linear);

			auto scale = rand() % 5 + 10;
			sprite->Scale(t, t, scale, scale);

			auto rotation = (rand() % 314) / 100.0f;
			sprite->Rotate(t, t, rotation, rotation, Easing::Linear, 1);

			sprite->Color(t, t, color, color);
		}
	}
}

Vector2 Okaerinasai::fromOsu(float x, float y) {
	return Vector2(x - 320, 240 - y);
}