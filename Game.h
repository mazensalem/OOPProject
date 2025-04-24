#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	
#include "Toolbar.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Fuel.h"

class Game
{
private:
	window* pWind;	//Pointer to the CMU graphics window
	ToolBar T1;
	Background BG;
	Enemy En;
	Fuel F1;
	color pcs[3] = { BLUE, BLACK, BLUE };
	Player player = { 550, 450, 100, pcs };

public:
	Game();
	~Game();

	clicktype getMouseClick(int& x, int& y) const; //Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window
	//void createToolbar();
	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go();

	window* getWind() const;		//returns a pointer to the graphics window

	void DrawGame();
	void MoveForward(int speed);
};

