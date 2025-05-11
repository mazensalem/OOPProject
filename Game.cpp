#include "Game.h"

using namespace std;


point p = { -1, -1 };
Game::Game(): 
	player(this, p, 100, 100),
	F1(this, p),
	En(this)
{
	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	//createToolbar();

	//3 - create and draw the backgroundPlayingArea
	BG.Draw(*pWind, 3, .7);
	BG.settreey(50);


	//4- Create the Plane
	player.setx(550);
	player.sety(450);

	//5- Create the Bullet
	//TODO: Add code to create and draw the Bullet
	F1.setxrand(280, 920);
	F1.sety(-90);
	player.drawbullets();

	//6- Create the enemies
	//TODO: Add code to create and draw enemies in random places
	En.update(0, 2);

	//7- Create and clear the status bar
	Drawstatusbar(*pWind, 0, 5, 5, 50);
	// clearStatusBar();
	updateobjs();
}

Game::~Game()
{
}


void Game::DrawGame() {
	// Backgroung
	BG.Draw(*pWind, 3, .7);
	
	// Fuel
	// The place of the drawing must be changed
	F1.draw();

	// Bullets
	player.drawbullets();

	// Player
	player.draw();

	// Enemies
	En.view(*pWind);

	// stauts bar
	Drawstatusbar(*pWind, 0, 5, 5, 50);

	// Tool bar
	T1.Draw(*pWind);
}


void Game::MoveForward(int speed) {
	if (BG.gettreey() > pWind->GetHeight()) {
		BG.settreey(-90);
	}

	if (F1.gety() > pWind->GetHeight()) {
		F1.sety(-90);
		F1.setxrand(280,920);
		updateobjs();
	}

	if (En.isout(*pWind)) {
		En.clearEnemy();
		En.update(0, 2);
		updateobjs();
	}

	BG.settreey(BG.gettreey() + speed);
	En.moveForward(speed);
	player.movebullets(speed);
	F1.move(speed);
}

void Game::updateobjs()
{
	objs.clear();
	objs.push_back(&F1);
	objs.push_back(&player);
	for (int i = 0; i < player.getBulletCount(); i++) {
		objs.push_back(
			&(*player.getBulletsPtr())[i]
		);
	}
	for (int i = 0; i < En.getAllEnemies().size(); i++) {
		Enemy* E = const_cast<Enemy*>(En.getAllEnemies()[i]);
		objs.push_back(E);
	}
}

clicktype Game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click

}

string Game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

window* Game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}

/*void Game::createToolbar()
{
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new Toolbar(this, toolbarUpperleft, 0, config.toolBarHeight);
	gameToolbar->draw();
}
*/

void Game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

void Game::printMessage(string msg) const
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);

}

window* Game::getWind() const
{
	return pWind;
}

void Game::go()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	// FROM YOUSSEF
	pWind->SetBuffering(true);
	const int window_width = pWind->GetWidth();
	const int window_height = pWind->GetHeight();
	const color playerPlaneColor = DARKBLUE;
	const double size = 0.25;
	int num_segments = 7;
	int difficulty = 2;
	int segment_width = window_width / num_segments;
	int playerPlaneYCoord = window_height - 100;
	int playerPlaneXCoord = pWind->GetWidth() / 2;
	int static_move_y = 0;
	// END FROM YOUSSEF


	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - River Raid (CIE101-project) - - - - - - - - - -");
	pWind->FlushKeyQueue();
	keytype keyinput;
	do
	{
		// FROM YOUSSEF
		char key;
		keytype keyinput = pWind->GetKeyPress(key);
		
		if (keyinput == ARROW) {
			if (key == 6) {
				player.setx(player.getx() + 5);
			}
			else if (key == 4) {
				player.setx(player.getx() - 5);
			}
			else if (key == 8) {
				//Forward
				MoveForward(config.fastspeed);
			}
			else if (key == 2) {
				//Backward
				MoveForward(config.slowspeed);

			}

		}
		if (keyinput == ASCII) {
			ostringstream stream;
			stream << key;
			string s = stream.str();
			cout << s;
			if (s == " ") {
				player.firebullet();
			}
		}

		DrawGame();
		MoveForward(config.normalspeed);
		// END FROM YOUSEF
		/*
		for (int i = 0; i < objs.size(); i++) {
			for (int j = 0; j < objs.size() && i != j; j++) {
				
				if (objs[i]->CollisionDetection(*objs[j])) {
					objs[i]->collisionAction(objs[j]);
					objs[j]->collisionAction(objs[i]);
				}
				
			}
		}
		*/
		pWind->UpdateBuffer();
		for (int i = 0; i < (*(player.getBulletsPtr())).size(); i++)
		{
			if (!((*(player.getBulletsPtr()))[i].isInside())) {
				(*(player.getBulletsPtr())).erase((*(player.getBulletsPtr())).begin() + i);
				player.decreaseBulletCount();
			}
		}
		cout << (*(player.getBulletsPtr())).size() << "\n";
		Pause(20);

		//printMessage("Ready...");
		//getMouseClick(x, y);	//Get the coordinates of the user click
		//if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		//{
			//[1] If user clicks on the Toolbar
		//if (y >= 0 && y < config.toolBarHeight)
		//{
			//isExit = gameToolbar->handleClick(x, y);
		//}
		//}

	} while (!isExit);
}

