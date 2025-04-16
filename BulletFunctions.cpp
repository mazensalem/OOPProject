#include <iostream>
#include <sstream>
#include <cmath>

#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"

/*

void DrawBullet(window& w, int x, int y) {

	w.SetPen(SANDYBROWN);
	w.SetBrush(BROWN);
	w.DrawTriangle(x-1, y, x + 4, y - 5, x + 9, y);
	w.SetPen(LIGHTGOLDENRODYELLOW);
	w.SetBrush(GOLD);
	w.DrawRectangle(x-1, y, x + 10, y + 20);
}

void ClearBullet(window&w ) {
	w.SetBrush(WHITE);
	w.SetPen(WHITE);
	w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight());
}*/
/*
int main() {
	window w(800, 600);
	int x = w.GetWidth() /2 ;

	keytype keyinput;
	char data;
	w.FlushKeyQueue();
	do {
		keyinput = w.GetKeyPress(data);
		if (keyinput == ESCAPE) {
			return 0;
		}
		if (keyinput == ASCII) {
			ostringstream stream;
			stream << data;
			string s = stream.str();
			if (s == " ") {
				for (int i = w.GetHeight(); i > 0; i--) {
					ClearBullet(w);
					DrawBullet(w, x, i);
					Pause(10);
				}
			}
		}
	} while (true);
}
*/