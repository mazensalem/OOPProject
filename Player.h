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
	void decreaseBulletCount() { bulletcount--; }
	void decreaseNumLives() { numLives--; }
	void increaseFuel() { fuel += 10; }
	void setscore(int uscore) { score = uscore; }

	int getx() const { return RefPoint.x; }
	int gety() const { return RefPoint.y; }
	int getNumLives() const { return numLives; }
	int getBulletCount() const { return bulletcount; }
	vector<Bullet>* getBulletsPtr() { return &bullets; }
	int getlevel() const { return level; }
	int getspeed() const { return speed; }
	int getscore() const { return score; }
	int getfuel() const { return fuel; }

	void firebullet();

	void movebullets(int pspeed);
	void drawbullets() const;
	void collisionAction(GameObject* other) override;

	

private:
	int bulletcount = 0, maxbulletcapacity = 100000, numLives = 3, fuel = 100, level=2, speed=1, score=0;
	vector<Bullet> bullets;
};
