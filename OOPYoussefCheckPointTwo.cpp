#include <iostream>
#include <cmath>
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	


class Background {
	public:
		void draw(window& w, int num_segments, int difficulty) {
			int width = w.GetWidth();
			int height = w.GetHeight();
			int segment_width = width / num_segments;
			w.SetPen(GREEN);
			w.SetBrush(GREEN);
			w.DrawRectangle(0, 0, segment_width * difficulty, height);
			w.DrawRectangle(width - segment_width * difficulty, 0, width, height);
			w.SetPen(CYAN);
			w.SetBrush(CYAN);
			w.DrawRectangle(segment_width * difficulty, 0, width - segment_width * difficulty, height);
		}
}background;

class PlayerPlane {
	public:
		void draw(window& w, int x, int y, color color = DARKBLUE, double size = 0.25) {
			w.SetPen(BLACK);
			w.SetBrush(color);
			int width = 50 * size;
			int height = 190 * size;
			w.DrawRectangle(x, y, x + width, y + height);
			int x1[] = { x, x - 100 * size, x - 100 * size, x };
			int y1[] = { y + 20 * size, y + 40 * size, y + 100 * size, y + 80 * size };
			w.DrawPolygon(x1, y1, 4, FILLED);
			int x2[] = { x + (width - 1), x + (width - 1), x + (width + 100 * size - 1), x + (width + 100 * size - 1) };
			int y2[] = { y + 20 * size, y + 80 * size, y + 100 * size, y + 40 * size };
			w.DrawPolygon(x2, y2, 4, FILLED);
			int x3[] = { x, x - 50 * size, x - 50 * size, x };
			int y3[] = { y + height - 50 * size, y + height - 30 * size, y + height + 20 * size, y + height };
			w.DrawPolygon(x3, y3, 4, FILLED);
			int x4[] = { x + (width - 1), x + (width - 1), x + (width + 50 * size - 1), x + (width + 50 * size - 1) };
			int y4[] = { y + height - 50 * size, y + height, y + height + 20 * size, y + height - 30 * size };
			w.DrawPolygon(x4, y4, 4, FILLED);
		}
}playerPlane;


class EnemyShip {
	public:
		void draw(window& w, int x, int y, color color = DARKRED, double size = 0.25) {
			w.SetPen(BLACK);
			w.SetBrush(color);
			w.DrawRectangle(x, y, x + 200 * size, y + 30 * size);
			w.SetBrush(BLACK);
			w.DrawRectangle(x + 15 * size, y - 15 * size, x + 170 * size, y);
			w.DrawRectangle(x + 30 * size, y - 30 * size, x + 140 * size, y - 15 * size);
			w.DrawRectangle(x + 100 * size, y - 50 * size, x + 140 * size, y - 30 * size);
			w.SetBrush(CYAN);
			w.DrawRectangle(x + 10 * size, y + 30 * size, x + 140 * size, y + 50 * size);
		}
};



class Tree {
	public:
		void draw(window& w, int x, int y) {
			w.SetPen(BLACK);
			w.SetBrush(BROWN);
			w.DrawRectangle(x, y, x + 10, y + 60);
			w.SetPen(BLACK);
			w.SetBrush(DARKGREEN);
			w.DrawCircle(x + 5, y, 40);
		}
}tree;


/*void clear(window& w) {
	w.SetPen(WHITE);
	w.SetBrush(WHITE);
	w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight(), FILLED);
}*/



void gameLoop(window& w) {
	w.SetBuffering(true);
	const int window_width = w.GetWidth();
	const int window_height = w.GetHeight();
	const color playerPlaneColor = DARKBLUE;
	const double size = 0.25;
	int num_segments = 7;
	int difficulty = 2;
	int segment_width = window_width / num_segments;
	int playerPlaneYCoord = window_height - 100;
	int playerPlaneXCoord = w.GetWidth() / 2;
	int static_move_y = 0;
	playerPlane.draw(w, window_height/2, playerPlaneYCoord, playerPlaneColor, size);
	w.SetBrush(BLACK);
	w.SetPen(BLACK);
	w.SetFont(24, BOLD, MODERN);
	w.DrawString(playerPlaneXCoord, 0, "Press on any of the arrows!");
	bool MOVE = true;
	while (MOVE = true) {
		char key;
		if (w.GetKeyPress(key) == ARROW) {
			if (key == 6) {
				background.draw(w, num_segments, difficulty);
				tree.draw(w, (window_width / num_segments) * difficulty / 2, static_move_y);
				tree.draw(w, window_width - (window_width / num_segments) * difficulty / 2, static_move_y + 200);
				playerPlane.draw(w, playerPlaneXCoord, playerPlaneYCoord, playerPlaneColor, size);
				playerPlaneXCoord += 5;
			}
			else if (key == 4) {
				background.draw(w, num_segments, difficulty);
				tree.draw(w, (window_width / num_segments) * difficulty / 2, static_move_y);
				tree.draw(w, window_width - (window_width / num_segments) * difficulty / 2, static_move_y + 200);
				playerPlane.draw(w, playerPlaneXCoord, playerPlaneYCoord, playerPlaneColor, size);
				playerPlaneXCoord -= 5;
			}
			else if (key == 8) {
				//Forward
				background.draw(w, num_segments, difficulty);
				tree.draw(w, (window_width / num_segments) * difficulty / 2, static_move_y);
				tree.draw(w, window_width - (window_width / num_segments) * difficulty / 2, static_move_y + 200);
				playerPlane.draw(w, playerPlaneXCoord, playerPlaneYCoord, playerPlaneColor, size);
				static_move_y += 5;
			}
			else if (key == 2) {
				//Backward
				background.draw(w, num_segments, difficulty);
				tree.draw(w, (window_width / num_segments) * difficulty / 2, static_move_y);
				tree.draw(w, window_width - (window_width / num_segments) * difficulty / 2, static_move_y + 200);
				playerPlane.draw(w, playerPlaneXCoord, playerPlaneYCoord, playerPlaneColor, size);
				static_move_y += 1;
				Pause(20);
			}
			
		}
		else if (w.GetKeyPress(key) == ESCAPE) {
			MOVE = false;
			break;
		}
		else if (w.GetKeyPress(key) != ARROW && w.GetKeyPress(key) != ESCAPE) {
			background.draw(w, num_segments, difficulty);
			tree.draw(w, (window_width / num_segments) * difficulty / 2, static_move_y);
			tree.draw(w, window_width - (window_width / num_segments) * difficulty / 2, static_move_y + 200);
			playerPlane.draw(w, playerPlaneXCoord, playerPlaneYCoord, playerPlaneColor, size);
			static_move_y += 3;
			Pause(20);
		}
		if (static_move_y > window_height + 100) {
			static_move_y = -300;
		}
		w.UpdateBuffer();
	}
	w.SetBuffering(false);
	
}

/*
int main(){
	window w(1000, 800, 0, 0);
	gameLoop(w);
}
*/