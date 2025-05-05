#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Bullet.h"
#include<vector>

class Player: public GameObject
{
public:
	Player(Game* G, point p, int w, int h);
	void draw() const override;

	void setx(int ux) { RefPoint.x = ux; }
	void sety(int uy) { RefPoint.y = uy; }

	int getx() const { return RefPoint.x; }
	int gety() const { return RefPoint.y; }

	void firebullet();

	void movebullets(int pspeed);
	void drawbullets(window& mainwin) const;


private:
	int bulletcount=0, maxbulletcapacity= 100000;
	vector<Bullet> bullets;
};
