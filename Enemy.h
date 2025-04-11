#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include <time.h>

class Tank
{
public:
	Tank(int ux=0, int uy=0, double usize=0, color c=BLACK) {
		x = ux;
		y = uy;
		size = usize;
		tcolor = c;
	}
	void draw(window& mainwin) const;
	
	void set_x(int ux) { x = ux; }
	void set_y(int uy) { y = uy; }
	void set_size(int usize) { size = usize; }
	void set_color(color ucolor) { tcolor = ucolor; }

	double get_size() const { return size; }
	int get_x() const { return x; }
	int get_y() const { return y; }
	color get_color() const { return tcolor; }

private:
	int x, y;
	double size;
	color tcolor;
};

class Bridge
{
public:
	Bridge(int ux = 0, int uy = 0, double usize = 0, color c = BLACK) {
		x = ux;
		y = uy;
		size = usize;
		bcolor = c;
	}
	void draw(window& mainwin) const;

	void set_x(int ux) { x = ux; }
	void set_y(int uy) { y = uy; }
	void set_size(int usize) { size = usize; }
	void set_color(color ucolor) { bcolor = ucolor; }

	double get_size() const { return size; }
	int get_x() const { return x; }
	int get_y() const { return y; }
	color get_color() const { return bcolor; }

private:
	int x, y;
	double size;
	color bcolor;

};

class Ship
{
public:
	Ship(int ux = 0, int uy = 0, double usize = 0, color c = BLACK) {
		scolor = c;
		x = ux;
		y = uy;
		size = usize;
	}
	void draw(window& mainwin) const;

	void set_x(int ux) { x = ux; }
	void set_y(int uy) { y = uy; }
	void set_size(int usize) { size = usize; }
	void set_color(color ucolor) { scolor = ucolor; }

	double get_size() const { return size; }
	int get_x() const { return x; }
	int get_y() const { return y; }
	color get_color() const { return scolor; }
private:
	color scolor;
	int x, y;
	double size;
};

class Enemy {
public:
	void setlevel(int level) { Enemy::level = level; }
	void setspeed(int speed) { Enemy::speed = speed; }

	void view(window& mainwin);
	void update(int nspeed, int nlevel);

private:
	int level=0, speed=0,
		tanknum = 0, brigesnum = 0, shipsnum = 0;
	Tank tanks[30];
	Bridge bridges[30];
	Ship ships[30];
	int min_x = 0, min_y = 0, global_max_x = 1200, global_max_y = 600;
	int min_size = 50, max_size = 300;

	color colors[4] = { BLACK, BLUE, RED, GREEN };

};