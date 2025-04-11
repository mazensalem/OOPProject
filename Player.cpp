#include "Player.h"

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
	int xtotal = 343, ytotal = 640;


	int bx[] = { 120, 140, 150, 170, 190, 200, 225, 226, 342, 329, 214, 212, 284, 283, 209, 204, 178, 170,164, 139, 132, 57,56, 127, 127, 12, -1, 116 };
	int by[] = { 220, 220, 70, 0, 65, 220, 221, 265, 471, 522, 407, 441, 555, 585, 567, 584, 586, 638, 586,585, 568, 585, 556, 442, 407, 523, 470, 266 };


	int x[] = { 120, 140, 150, 170, 190, 200, 225, 225, 340, 330, 215, 210, 285, 285, 210, 205, 180, 170, 165, 140, 130, 55, 55, 125, 125, 10, 0, 115 };
	int y[] = { 220, 220, 70, 0   , 65 , 220, 220, 265, 470, 520, 405, 440, 555, 585, 565, 585, 585, 640, 585,585, 570, 585, 555, 440, 405, 525, 470, 265 };

	int x1[] = { 140, 150, 170, 190, 200 };
	int y1[] = { 220, 70, 0, 65, 220, 220 };

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