#include "Player.h"
#include "Game.h"


Player::Player(Game* G, point p, int w, int h): GameObject(G, p, w, h, BLACK, BLACK) {}

void Player::draw() const {
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
		x[i] *= (double)width / xtotal;
		y[i] *= (double)height / ytotal;
	}

	for (int i = 0; i < 5; i++) {
		x1[i] *= (double)width / xtotal;
		y1[i] *= (double)height / ytotal;
	}

	for (int i = 0; i < 3; i++) {
		x2[i] *= (double)width / xtotal;
		y2[i] *= (double)height / ytotal;
	}

	//Shift
	for (int i = 0; i < 28; i++) {
		x[i] += RefPoint.x;
		y[i] += RefPoint.y;
	}

	for (int i = 0; i < 5; i++) {
		x1[i] += RefPoint.x;
		y1[i] += RefPoint.y;
	}

	for (int i = 0; i < 3; i++) {
		x2[i] += RefPoint.x;
		y2[i] += RefPoint.y;
	}

	window *mainwin = pGame->getWind();

	mainwin->SetPen(BLACK, 1);
	mainwin->SetBrush(BLACK);
	mainwin->DrawPolygon(x, y, 28);

	mainwin->SetPen(BLUE, 1);
	mainwin->SetBrush(BLUE);
	mainwin->DrawPolygon(x1, y1, 5);

	mainwin->SetPen(BLUE, 1);
	mainwin->SetBrush(BLUE);
	mainwin->DrawPolygon(x2, y2, 3);
}

void Player::firebullet() {
	//if (bulletcount != maxbulletcapacity) { 
		bulletcount++;
	//}
		point p;
		p.x = (RefPoint.x + width / 2) - 5;
		p.y = RefPoint.y;
		Bullet B(pGame, p);
		bullets.push_back(B);
}

void Player::movebullets(int bspeed) {
	for (int i = 0; i < bulletcount; i++) {
		bullets[i].sety(bullets[i].gety() - bspeed);
	}
}

void Player::drawbullets(window& mainwin) const {
	for (int i = 0; i < bulletcount; i++) {
		bullets[i].draw();
	}
}
