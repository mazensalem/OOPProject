#include "Fuel.h"
#include "Game.h"
#include <time.h>

void Fuel::draw() const {
	window *w = pGame->getWind();

	w->SetPen(LIGHTYELLOW);
	w->SetBrush(YELLOW);
	w->DrawRectangle(RefPoint.x, RefPoint.y, RefPoint.x + width, RefPoint.y + height);

	w->SetPen(BLACK);
	w->SetFont(15, BOLD, BY_NAME, "Arial");
	w->DrawString(RefPoint.x + 6, RefPoint.y + 8, "F");
	w->DrawString(RefPoint.x + 5, RefPoint.y + 19, "U");
	w->DrawString(RefPoint.x + 6, RefPoint.y + 30, "E");
	w->DrawString(RefPoint.x + 6, RefPoint.y + 42, "L");
}

void Fuel::setxrand(int min, int max)
{
	RefPoint.x = min + rand() % (max - min - 1);
}

void Fuel::collisionAction(GameObject* other)
{
}

