#pragma
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game* G, point p): GameObject(G, p, 10, 25, BLACK, BLACK) {
		p.x = 600;
		p.y = 580;
		bcc[0] = BROWN;
		bcc[1] = GOLD;
		brc[0] = SANDYBROWN;
		brc[1] = LIGHTGOLDENRODYELLOW;
}

void Bullet::draw() const {
	window *w = pGame->getWind();

	w->SetPen(brc[0]);
	w->SetBrush(bcc[1]);
	w->DrawTriangle(
		RefPoint.x, RefPoint.y + .2 * height,
		RefPoint.x + width / 2, RefPoint.y,
		RefPoint.x + width, RefPoint.y + .2 * height);
	w->SetPen(brc[1]);
	w->SetBrush(bcc[1]);
	w->DrawRectangle(
		RefPoint.x, RefPoint.y + .2 * height,
		RefPoint.x + width, RefPoint.y + .8 * height);
}