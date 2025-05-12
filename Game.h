#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	
#include "Toolbar.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Fuel.h"
#include "GameConfig.h"
#include "StatusBar.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>


class Game
{
private:
	window* pWind;	//Pointer to the CMU graphics window
	point p = { -1, -1 };
	ToolBar T1;
	Background BG;
	EnemyManager En;
	Fuel F1;
	Player player;
	vector<GameObject*> objs;
	ofstream file;
	bool isExit = false;

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
	void updateobjs();
	void increasescore(int inc);
	void exit();
};

