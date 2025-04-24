#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int ux, int uy, double usize, color c[]) {
	/*
	* ux the position
	* uy the position
	* usize the number of pixels for x and y
	* c is the color
	*/
	x = ux;
	y = uy;
	size = usize;
	pcolor = c;
}

void Player::draw(window& mainwin) const {
	// The total width and height of the original drawing
	int xtotal = 343, ytotal = 640;


	// The positions of x, y for all the orignal points on the plane
	int x[] = { 120, 140, 150, 170, 190, 200, 225, 225, 340, 330, 215, 210, 285, 285, 210, 205, 180, 170, 165, 140, 130, 55, 55, 125, 125, 10, 0, 115 };
	int y[] = { 220, 220, 70, 0   , 65 , 220, 220, 265, 470, 520, 405, 440, 555, 585, 565, 585, 585, 640, 585,585, 570, 585, 555, 440, 405, 525, 470, 265 };

	// The orignal position of the x, y for the cocapit of the plane
	int x1[] = { 140, 150, 170, 190, 200 };
	int y1[] = { 220, 70, 0, 65, 220, 220 };

	// The orignal position of the x, y for the flame of the plane
	int x2[] = { 180, 170, 165 };
	int y2[] = {585, 640, 585};

	//Resize
	for (int i = 0; i < 28; i++) {
		x[i] *= size / xtotal;
		y[i] *= size / ytotal;
	}

	for (int i = 0; i < 5; i++) {
		x1[i] *= size / xtotal;
		y1[i] *= size / ytotal;
	}

	for (int i = 0; i < 3; i++) {
		x2[i] *= size / xtotal;
		y2[i] *= size / ytotal;
	}

	//Shift
	for (int i = 0; i < 28; i++) {
		x[i] += Player::x;
		y[i] += Player::y;
	}

	for (int i = 0; i < 5; i++) {
		x1[i] += Player::x;
		y1[i] += Player::y;
	}

	for (int i = 0; i < 3; i++) {
		x2[i] += Player::x;
		y2[i] += Player::y;
	}



	mainwin.SetPen(pcolor[1], 1);
	mainwin.SetBrush(pcolor[1]);
	mainwin.DrawPolygon(x, y, 28);

	mainwin.SetPen(pcolor[0], 1);
	mainwin.SetBrush(pcolor[0]);
	mainwin.DrawPolygon(x1, y1, 5);

	mainwin.SetPen(pcolor[2], 1);
	mainwin.SetBrush(pcolor[2]);
	mainwin.DrawPolygon(x2, y2, 3);
}

void Player::firebullet() {
	if (bulletcount != maxbulletcapacity) { 
		bulletcount++;
	}
	bullets[bulletcount - 1].sety(y);
	bullets[bulletcount - 1].setx(x + size/2);
}

void Player::movebullets(int bspeed) {
	for (int i = 0; i < bulletcount; i++) {
		bullets[i].sety(bullets[i].gety() - bspeed);
	}
}

void Player::drawbullets(window& mainwin) const {
	for (int i = 0; i < bulletcount; i++) {
		bullets[i].DrawBullet(mainwin);
	}
}