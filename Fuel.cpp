#include "Fuel.h"
#include <time.h>

void Fuel::DrawFuel(window &w) const {
	w.SetPen(LIGHTYELLOW);
	w.SetBrush(YELLOW);
	w.DrawRectangle(x, y, x + 20, y + 60);

	w.SetPen(BLACK);
	w.SetFont(15, BOLD, BY_NAME, "Arial");
	w.DrawString(x + 6, y + 8, "F");
	w.DrawString(x + 5, y + 19, "U");
	w.DrawString(x + 6, y + 30, "E");
	w.DrawString(x + 6, y + 42, "L");
}

void Fuel::setxrand(int min, int max)
{
	x = min + rand() % (max - min -1);
}

