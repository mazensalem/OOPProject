#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include <time.h>

class Tank
{
public:
	Tank(int ux=0, int uy=0, double usize=0, color c=BLACK) {
		/*
		* ux the position
		* uy the position
		* usize the number of pixels for x and y
		* c is the color
		*/
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
		/*
		* ux the position
		* uy the position
		* usize the number of pixels for x and y
		* c is the color
		*/
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
		/*
		* ux the position
		* uy the position
		* usize the number of pixels for x and y
		* c is the color
		*/
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



class EnemyPlane {
public:
	void draw(window& w) const;

	void set_x(int ux) { x = ux; }
	void set_y(int uy) { y = uy; }
	void set_size(int usize) { size = usize; }
	void set_color(color ucolor) { pcolor = ucolor; }

	double get_size() const { return size; }
	int get_x() const { return x; }
	int get_y() const { return y; }
	color get_color() const { return pcolor; }

private:
	int x, y;
	color pcolor=DARKRED;
	double size = .25;
};



class EnemyHelicopter {
public:
	void draw(window& w) const;
	
	void set_x(int ux) { x = ux; }
	void set_y(int uy) { y = uy; }
	void set_size(int usize) { size = usize; }
	void set_color(color ucolor) { hcolor = ucolor; }

	double get_size() const { return size; }
	int get_x() const { return x; }
	int get_y() const { return y; }
	color get_color() const { return hcolor; }

private:
	int x, y;
	color hcolor=DARKRED;
	double size=.25;
};



class Enemy
{
public:
	void setlevel(int level) { Enemy::level = level; }
	void setspeed(int speed) { Enemy::speed = speed; }
	void moveForward(int speed);

	void clearEnemy() { tanknum = 0; brigesnum = 0; shipsnum = 0; jetsnum = 0; helisnum = 0; }

	void view(window& mainwin) const;
	void update(int nspeed, int nlevel);

	bool isout(window &mainwin) {
		return min_current_y > mainwin.GetHeight();
	}

private:
	int level=0, speed=0,
		tanknum = 0, brigesnum = 0, shipsnum = 0, jetsnum=0, helisnum=0;
	Tank tanks[10];
	Bridge bridges[10];
	Ship ships[10];
	EnemyHelicopter helis[10];
	EnemyPlane jets[10];
	int min_x = 280, min_y = -900, global_max_x = 920, global_max_y = 0;
	int min_size = 50, max_size = 300;

	color colors[4] = { BLACK, BLUE, RED, GREENYELLOW };

	// This is the hiegts point of all enemys that are on the screen 
	int min_current_y;
};