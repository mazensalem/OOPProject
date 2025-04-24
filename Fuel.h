#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"

class Fuel
{
public:
	void DrawFuel(window& w) const;
	void setx(int ux) { x = ux; }
	void sety(int uy) { y = uy; }

	int gety()const { return y; }

	void move(int speed) { y += speed; }

	void setxrand(int min, int max);
private:
	int x, y;
};

