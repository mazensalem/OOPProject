#include "ToolBar.h"

ToolBar::ToolBar() :RestartImage("Restart.jpg"), PauseImage("Pause.jpg"), ResumeImage("Resume.jpg"), LoadImage("Load.jpg"), SaveImage("Save.jpg") 
{
}


void ToolBar::Draw(window& w)
{
	w.SetBrush(WHITE);
	w.SetPen(WHITE);
	w.DrawRectangle(0, 0, w.GetWidth(), 60);
	w.DrawImage(RestartImage, 0, 10, 50, 50);
	w.DrawImage(PauseImage, 50, 10, 50, 50);
	w.DrawImage(ResumeImage, 100, 10, 50, 50);
	w.DrawImage(LoadImage, 150, 10, 50, 50);
	w.DrawImage(SaveImage, 200, 10, 50, 50);
}
