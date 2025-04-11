#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"


class Player
{
public:
	Player(int ux, int uy, double usize, color c[]);
	void draw(window& mainwin) const;
private:
	int x, y;
	double size;
	color* pcolor;
};
