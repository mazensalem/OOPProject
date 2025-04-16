#include "StatusBar.h"
#include "GameConfig.h"


void Drawstatusbar(window& w, int points, int gamespeed, int lives, int fuelgauge) {
	int textheight = config.windHeight - (int)(0.85 * config.statusBarHeight);
	w.SetBrush(BLACK);
	w.SetPen(BLACK);
	w.DrawRectangle(0, w.GetHeight()-config.statusBarHeight, w.GetWidth(), w.GetHeight());
	
	w.SetPen(BLUE);
	w.SetFont(24, BOLD | ITALICIZED, BY_NAME, "Arial");


	w.DrawString(10, textheight, "points:");
	w.DrawInteger(80, textheight, points);
	w.DrawString(130, textheight, "game speed:");
	w.DrawInteger(250, textheight, gamespeed);
	w.DrawString(300, textheight, "lives:");
	w.DrawInteger(350, textheight, lives);
	w.DrawString(400, textheight, "fuel gauge:");
	w.DrawInteger(510, textheight, fuelgauge);
}
