#include "CMUgraphicsLib\CMUgraphics.h"
#include "Player.h"
#include <time.h>



/*void followMousePlayerPlane(window& w, color tcolor, double size, Player P1) {
	w.SetBuffering(true);
	bool MOVE = true;
	int x, y;
	char key;

	while (true) {
		
		w.WaitMouseClick(x, y);
		w.GetMouseCoord(x, y);

		clear(w);
		P1.draw(w);

		if (w.GetKeyPress(key) == ASCII) {
			MOVE = false;
			break;
		}
		w.UpdateBuffer();
	}
	w.SetBuffering(false);
}

void movablePlayerPlaneArrows(window& w, int x, int y, color color, double size, Player P1) {
	w.SetBuffering(true);
	int treey = 0;
	P1.draw(w);
	w.SetBrush(BLACK);
	w.SetPen(BLACK);
	w.SetFont(24, BOLD, MODERN);
	w.DrawString(0, 0, "Press on any of the arrows!");
	bool MOVE = true;
	while (MOVE = true) {
		char key;
		if (w.GetKeyPress(key) == ARROW) {
			if (key == 6) {
				Background(w, 7, 2, treey);
				x += 5;
				P1.setx(x);
			}
			else if (key == 4) {
				Background(w, 7, 2, treey);
				x -= 5;
				P1.setx(x);
			}
			else if (key == 8) {
				y -= 5;
				treey += 5;
				Background(w, 7, 2, treey);
				P1.sety(y);
			}
			else if (key == 2) {
				y += 5;
				treey -= 5;
				Background(w, 7, 2, treey);
				P1.sety(y);
			}
			P1.draw(w);

		}
		else if (w.GetKeyPress(key) == ESCAPE) {
			MOVE = false;
			break;
		}
		w.UpdateBuffer();
	}
	w.SetBuffering(false);
}
*/