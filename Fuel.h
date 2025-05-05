#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameObject.h"

class Fuel: public GameObject
{
public:
	Fuel(Game* G, point p): GameObject(G, p, 20, 60, YELLOW, LIGHTYELLOW)  {

	}
	void draw() const override;
	void setx(int ux) { RefPoint.x = ux; }
	void sety(int uy) { RefPoint.y = uy; }

	int gety() const { return RefPoint.y; }

	void move(int speed) { RefPoint.y += speed; }

	void setxrand(int min, int max);
private:
};

