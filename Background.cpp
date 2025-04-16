#include "Background.h"
#include <iostream>
using namespace std;

void Background::Draw(window& w, int num_segments, double difficulty) const {
	// What is this condition for????
	if (difficulty < 0.5 * num_segments) {
		srand(time(0));
		int height = w.GetHeight();
		int width = w.GetWidth();
		int segment_width = width / (double)num_segments;

		int randomx = 0 + rand() % int(difficulty * segment_width - 1);
		w.SetBrush(GREEN);
		w.DrawRectangle(0, 0, difficulty * segment_width, height);
		w.SetBrush(DODGERBLUE);
		w.DrawRectangle(difficulty * segment_width, 0, width - difficulty * segment_width, height);
		w.SetBrush(GREEN);
		w.DrawRectangle(w.GetWidth() - difficulty * segment_width, 0, width, height);
		
		Draw_trees(w, 50, treey);
	}
}

void Background::Draw_trees(window& w, int x, int y) const {
	w.SetBrush(BROWN);
	w.DrawRectangle(x, y, x + 20, y + 60);
	w.SetBrush(DARKOLIVEGREEN);
	w.DrawCircle(x + 10, y, 20);
}