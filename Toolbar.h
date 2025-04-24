#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"

class ToolBar {
private:
	image RestartImage;
	image PauseImage;
	image ResumeImage;
	image LoadImage;
	image SaveImage;
public:
	ToolBar();
	void Draw(window& w);


};