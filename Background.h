#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include <time.h>

class Background
{
public:
	void clear(window& w) {
		w.SetPen(WHITE);
		w.SetBrush(WHITE);
		w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight(), FILLED);
	}

	void Draw(window& w, int num_segments, double difficulty) const;

	void Draw_trees(window& w, int x, int y) const;

	int gettreey() const { return treey; }
	void settreey(int uy) { treey = uy; }

private:
	int treey;
};
