#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Bullet.h"
#include <ctime>
#include<vector>

class Player: public GameObject
{
public:
	Player(Game* G, point p, int w, int h);
	void draw() const override;

	void setx(int ux) { RefPoint.x = ux; }
	void sety(int uy) { RefPoint.y = uy; }
	void decreaseNumLives() { numLives--; }
	void increaseFuel() { fuel += 10; }
	void setscore(int uscore) { score = uscore; }
	void setspeed(int uspeed) { speed = uspeed; }
	void setlevel(int ulevel) { level = ulevel; }
	void decreasefuel();
	void setfuel(int ufuel) { fuel = ufuel; };
	void setNumLives(int lives) { numLives = lives; }

	int getx() const { return RefPoint.x; }
	int gety() const { return RefPoint.y; }
	int getNumLives() const { return numLives; }
	int getBulletCount() const { return bullets.size(); }
	vector<Bullet>* getBulletsPtr() { return &bullets; }
	int getlevel() const { return level; }
	int getspeed() const { return speed; }
	int getscore() const { return score; }
	int getfuel() const { return fuel; }

	void firebullet();

	void movebullets(int pspeed);
	void drawbullets() const;
	void collisionAction(GameObject* other) override;

	void save(ofstream& file) const override;

	void hit();
	void refuel() { stime = time(NULL); }

	

private:
	int bulletcount = 0, maxbulletcapacity = 100000, numLives = 5, fuel = 100, level = 2, speed = 1, score = 0,
		flyingtime = 0;
	time_t stime;
	vector<Bullet> bullets;
};
