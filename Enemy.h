#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"


class Tank
{
public:
	Tank(int ux, int uy, double usize, color c) {
		x = ux;
		y = uy;
		size = usize;
		tcolor = c;
	}
	void draw(window& mainwin) const;

private:
	int x, y;
	double size;
	color tcolor;
};

class Bridge
{
public:
	Bridge(int ux, int uy, double usize, color c) {
		x = ux;
		y = uy;
		size = usize;
		bcolor = c;
	}
	void draw(window& mainwin) const;

private:
	int x, y;
	double size;
	color bcolor;

};

class Ship
{
public:
	Ship(int ux, int uy, double usize, color c) {
		scolor = c;
		x = ux;
		y = uy;
		size = usize;
	}
	void draw(window& mainwin) const;
private:
	color scolor;
	int x, y;
	double size;
};