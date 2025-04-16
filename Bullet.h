#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"

class Bullet
{
public:
	Bullet(int ux=600, int uy=580) {
		x = ux;
		y = uy;
	}
	void DrawBullet(window& w) const;

	int getx() const { return x; }
	int gety() const { return y; }

	void setx(int ux) { x = ux; }
	void sety(int uy) { y = uy; }

private:
	int x, y;
};
