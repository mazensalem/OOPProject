#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameConfig.h"
#include "GameObject.h"
#include <time.h>
#include <vector>


class Enemy: public GameObject {
public:
	Enemy(Game* G, point p, int w, int h, color c) :GameObject(G, p, w, h, c, BLACK){}

	virtual void collisionAction(GameObject* other) override {};
	virtual void draw() const override {};
	void set_x(int ux) { RefPoint.x = ux; }
	void set_y(int uy) { RefPoint.y = uy; }
	void set_size(int usize) { 
		width =  usize;
		height = usize;
	}
	void set_color(color ucolor) { fillColor = ucolor; }

	double get_width() const { return width; }
	double get_height() const { return height; }
	int get_x() const { return RefPoint.x; }
	int get_y() const { return RefPoint.y; }
	color get_color() const { return fillColor; }

protected:
	double basewidth=0;
	double basehieght=0;
};


class Tank: public Enemy
{
public:
	Tank(Game* G, point p, int w, int h, color c = BLACK) :Enemy(G, p, w, h, c) {
		basehieght = 500, basewidth = 500;
	}
	void draw() const override;

private:
};

class Bridge: public Enemy
{
public:
	Bridge(Game* G, point p, int w, int h, color c = BLACK) :Enemy(G, p, w, h, c) {}
	void draw() const override;

private:
};

class Ship: public Enemy
{
public:
	Ship(Game* G, point p, int w, int h, color c = BLACK): Enemy(G, p, w, h, c) {}
	void draw() const override;
private:
};

class EnemyPlane: public Enemy {
public:
	EnemyPlane(Game* G, point p, int w, int h, color c = BLACK) : Enemy(G, p, w, h, c) {} 
	void draw() const override;
	void moveVertical();


private:
	int verticalspeed = 5;
	double size = .25;
};

class EnemyHelicopter : public Enemy {
public:
	EnemyHelicopter(Game* G, point p, int w, int h, color c = BLACK) : Enemy(G, p, w, h, c) {}
	void draw() const override;

	void moveVertical();
	
private:
	double size=.25;
	int verticalspeed = 5;
};



class EnemyManeger
{
public:
	EnemyManeger(Game *G) {
		game = G;
	}
	void setlevel(int level) { EnemyManeger::level = level; }
	void setspeed(int speed) { EnemyManeger::speed = speed; }
	void moveForward(int speed);

	vector<const Enemy*> getAllEnemies() const;

	void clearEnemy() { 
		tanks.clear();
		bridges.clear();
		ships.clear();
		jets.clear();
		helis.clear();
		tanknum = 0; brigesnum = 0; shipsnum = 0; jetsnum = 0; helisnum = 0; 
	}

	void view(window& mainwin) const;
	void update(int nspeed, int nlevel);

	bool isout(window &mainwin) {
		return min_current_y > mainwin.GetHeight();
	}

private:
	Game* game;
	int level=0, speed=0,
		tanknum = 0, brigesnum = 0, shipsnum = 0, jetsnum=0, helisnum=0;
	vector<Tank> tanks;
	vector<Bridge> bridges;
	vector<Ship> ships;
	vector<EnemyPlane> jets;
	vector<EnemyHelicopter> helis;
	int min_x = 280, min_y = -900, global_max_x = 920, global_max_y = 0;
	int min_size = 50, max_size = 125;

	color colors[4] = { BLACK, BLUE, RED, GREENYELLOW };

	// This is the hiegts point of all enemys that are on the screen 
	int min_current_y = 100000;
};