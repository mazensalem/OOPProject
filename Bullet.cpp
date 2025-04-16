#include "Bullet.h"

void Bullet::DrawBullet(window& w) const {
	w.SetPen(SANDYBROWN);
	w.SetBrush(BROWN);
	w.DrawTriangle(x, y, x + 5, y - 5, x + 10, y);
	w.SetPen(LIGHTGOLDENRODYELLOW);
	w.SetBrush(GOLD);
	w.DrawRectangle(x, y, x + 10, y + 20);
}