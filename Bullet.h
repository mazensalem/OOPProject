#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameObject.h"

class Bullet: public GameObject
{
public:
	Bullet(Game* G, point p);
	void draw() const override;

	int getx() const { return RefPoint.x; }
	int gety() const { return RefPoint.y; }

	void setx(int ux) { RefPoint.x = ux; }
	void sety(int uy) { RefPoint.y = uy; }
	
	void setbcc(int ind, color c) { bcc[ind] = c; }
	void setbrc(int ind, color c) { brc[ind] = c; }



private:
	color bcc[2];
	color brc[2];
};
