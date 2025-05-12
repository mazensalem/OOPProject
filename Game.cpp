#include "Game.h"
#include <fstream>
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

	file.open("save.txt");

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

	player.save(file);
	for (int i = 0; i < En.getTanks().size(); i++)
	{
		En.getTanks()[i].save(file);
	}
	for (int i = 0; i < En.getShips().size(); i++)
	{
		En.getShips()[i].save(file);
	}
	for (int i = 0; i < En.getEnemyPlanes().size(); i++)
	{
		En.getEnemyPlanes()[i].save(file);
	}
	for (int i = 0; i < En.getEnemyHelicopters().size(); i++)
	{
		En.getEnemyHelicopters()[i].save(file);
	}
	for (int i = 0; i < En.getBridges().size(); i++)
	{
		En.getBridges()[i].save(file);
	}
	file.close();

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
	Drawstatusbar(*pWind, player.getscore(), player.getspeed(), player.getNumLives(), player.getfuel());

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
	double viewpercent = En.precentempty(*pWind);
	if (viewpercent > 0 && (1 - viewpercent)*10 <= player.getlevel()) 
	{
		En.update(player.getspeed(), player.getlevel());
		updateobjs();
	}

	En.cleanUp(pWind);
	BG.settreey(BG.gettreey() + speed);
	En.moveForward(speed);
	
	player.movebullets(speed);
	player.decreasefuel();

	F1.move(speed);
}

void Game::updateobjs()
{
	objs.clear();
	objs.push_back(&F1);
	for (int i = 0; i < En.getAllEnemies().size(); i++) {
		Enemy* E = const_cast<Enemy*>(En.getAllEnemies()[i]);
		objs.push_back(E);
	}
}

void Game::increasescore(int inc)
{
	player.setscore(player.getscore() + inc); 
	if (player.getspeed() < 5) {
		if ((player.getscore() / 1000) + 1 > player.getspeed()) {
			player.setspeed((player.getscore() / 500) + 1);
		}
	}
	if (player.getlevel() < 4) {
		if ((player.getscore() / 1500) + 1 > player.getlevel()) {
			player.setlevel((player.getscore() / 1000) + 1);
		}
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

void Game::exit() {isExit = true;}

void Game::go()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;

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
				MoveForward(player.getspeed() * config.fastspeed);
			}
			else if (key == 2) {
				//Backward
				MoveForward(player.getspeed() * config.slowspeed);

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
			else if (s == "p" || s == "P") {
				isPaused = true;
			}
		}

		DrawGame();
		MoveForward(player.getspeed() * config.normalspeed);
		
		// END FROM YOUSEF
		// collision checks
		for (int i = 0; i < player.getBulletsPtr()->size(); i++) {
			Bullet& B = (*player.getBulletsPtr())[i];
			for (int j = 0; j < objs.size(); j++) {
				if (objs[j]->CollisionDetection(B)) {
					objs[j]->collisionAction(&B);
					B.collisionAction(objs[j]);
					player.getBulletsPtr()->erase(
						player.getBulletsPtr()->begin() + i
					);
					i--;
					if (objs[j]->getdeletedscore() > 0) {
						Enemy* DE = dynamic_cast<Enemy*>(objs[j]);
						En.deleteenemy(DE);
						j--;
					}
					else {
						F1.sety(-90);
						F1.setxrand(280, 920);
					}
					updateobjs();
				}
			}
		}
		
		for (int i = 0; i < objs.size(); i++) {
			if (objs[i]->CollisionDetection(player)) {
				if (objs[i]->getdeletedscore() > 0) {
					Enemy* DE = dynamic_cast<Enemy*>(objs[i]);
					En.deleteenemy(DE);
					player.hit();
					i--;
				}
				else {
					F1.sety(-90);
					F1.setxrand(280, 920);
					player.refuel();
				}
				updateobjs();
			}
		}

		// Clean up the bullets
		for (int i = 0; i < (*(player.getBulletsPtr())).size(); i++)
		{
			if (!((*(player.getBulletsPtr()))[i].isInside())) {
				(*(player.getBulletsPtr())).erase((*(player.getBulletsPtr())).begin() + i);
			}
		}



		// Tool bar checks
		while (isPaused) {
			pWind->WaitMouseClick(x, y);	//Wait for mouse click
			
			// load
			if (x < 199 && x>151 && y < 56 && y>9)
			{
				loadFile.open("save.txt");
				string line;
				vector<Tank> tanks;
				vector<Ship> ships;
				vector<EnemyPlane> jets;
				vector<EnemyHelicopter> helis;
				vector<Bridge> bridges;
				while (getline(loadFile, line)) {
					istringstream iss(line);
					string type;
					iss >> type;
					if (type == "player") {
						int x, y, lives, fuel;
						iss >> x >> y >> lives >> fuel;
						player.setx(x);
						player.sety(y);
						player.setNumLives(lives);
						player.setfuel(fuel);
					}
					else if (type == "tank") {
						int x, y, width, height;
						unsigned char r, g, b;
						iss >> x >> y >> width >> height >> r >> g >> b;
						color c(r, g, b);
						Tank T(this, { x, y }, width, height, c);
						T.set_x(x);
						T.set_y(y);
						tanks.push_back(T);
					}
					else if (type == "ship") {
						int x, y, width, height;
						int r, g, b;
						iss >> x >> y >> width >> height >> r >> g >> b;
						color c(r, g, b);
						Ship S(this, { x, y }, width, height, c);
						S.set_x(x);
						S.set_y(y);
						ships.push_back(S);
					}
					else if (type == "enemyPlane") {
						int x, y, width, height;
						int r, g, b;
						iss >> x >> y >> width >> height >> r >> g >> b;
						color c(r, g, b);
						EnemyPlane E(this, { x, y }, width, height, c);
						E.set_x(x);
						E.set_y(y);
						jets.push_back(E);
					}
					else if (type == "enemyHelicopter") {
						int x, y, width, height;
						int r, g, b;
						iss >> x >> y >> width >> height >> r >> g >> b;
						color c(r, g, b);
						EnemyHelicopter H(this, { x, y }, width, height, c);
						H.set_x(x);
						H.set_y(y);
						helis.push_back(H);
					}
					else if (type == "bridge") {
						int x, y, width, height;
						int r, g, b;
						iss >> x >> y >> width >> height >> r >> g >> b;
						color c(r, g, b);
						Bridge B(this, { x, y }, width, height, c);
						B.set_x(x);
						B.set_y(y);
						bridges.push_back(B);
					}
				}
				En.setmanual(tanks, bridges, ships, jets, helis);
				loadFile.close();
				DrawGame();
			}
			//save
			else if (x < 248 && x>205 && y < 56 && y>9) {
				player.save(saveFile);
				for (int i = 0; i < En.getTanks().size(); i++)
				{
					En.getTanks()[i].save(saveFile);
				}
				for (int i = 0; i < En.getShips().size(); i++)
				{
					En.getShips()[i].save(saveFile);
				}
				for (int i = 0; i < En.getEnemyPlanes().size(); i++)
				{
					En.getEnemyPlanes()[i].save(saveFile);
				}
				for (int i = 0; i < En.getEnemyHelicopters().size(); i++)
				{
					En.getEnemyHelicopters()[i].save(saveFile);
				}
				for (int i = 0; i < En.getBridges().size(); i++)
				{
					En.getBridges()[i].save(saveFile);
				}
				saveFile.close();
			}
			
			else {
				isPaused = false;
			}
		}


		pWind->UpdateBuffer();
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

