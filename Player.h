#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Bullet.h"

class Player
{
public:
	Player(int ux, int uy, double usize, color c[]);
	void draw(window& mainwin) const;

	void setx(int ux) { x = ux; }
	void sety(int uy) { y = uy; }

	int getx() const { return x; }
	int gety() const { return y; }

	void firebullet();

	void movebullets(int pspeed);
	void drawbullets(window& mainwin) const;


private:
	int x, y, bulletcount=0;
	double size;
	color* pcolor;
	Bullet bullets[10];
};
