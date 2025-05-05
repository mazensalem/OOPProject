#include "Enemy.h"
#include "Game.h"

void Tank::draw() const {
	window *mainwin = pGame->getWind();
	mainwin->SetPen(fillColor, 3);
	mainwin->SetBrush(fillColor);

	// The main capane thierd layer
	int x1[] = {220, 240, 350, 370};
	int y1[] = {195, 145, 145, 195};

	// The canon long cylinder
	int x2[] = { 163, 227, 226, 163 };
	int y2[] = { 163, 164, 173, 174 };

	// The second layer
	int x3[] = { 171, 205, 417, 423 };
	int y3[] = { 229, 205, 205, 230 };

	// The first layer above the wheels
	int x4[] = { 65, 138, 425, 434, 419, 76 };
	int y4[] = { 271, 233, 234, 262, 289, 292 };

	int x5[] = { 101, 87, 134, 357, 416, 404, 355, 138};
	int y5[] = { 299, 299, 353, 354, 298, 297, 343, 344 };
	
	//Resize
	for (int i = 0; i < 4; i++) {
		x1[i] *= (double)width / basewidth;
		y1[i] *= (double)height / basehieght;
		x2[i] *= (double)width / basewidth;
		y2[i] *= (double)height / basehieght;
		x3[i] *= (double)width / basewidth;
		y3[i] *= (double)height / basehieght;
	}

	for (int i = 0; i < 6; i++) {
		x4[i] *= (double)width / basewidth;
		y4[i] *= (double)height / basehieght;
	}
	for (int i = 0; i < 8; i++) {
		x5[i] *= (double)width / basewidth;
		y5[i] *= (double)height / basehieght;
	}

	//Shift
	for (int i = 0; i < 4; i++) {
		x1[i] += RefPoint.x;
		y1[i] += RefPoint.y;
		x2[i] += RefPoint.x;
		y2[i] += RefPoint.y;
		x3[i] += RefPoint.x;
		y3[i] += RefPoint.y;
	}
	for (int i = 0; i < 6; i++) {
		x4[i] += RefPoint.x;
		y4[i] += RefPoint.y;
	}
	for (int i = 0; i < 8; i++) {
		x5[i] += RefPoint.x;
		y5[i] += RefPoint.y;
	}


	mainwin->DrawPolygon(x4, y4, 6);

	mainwin->DrawPolygon(x3, y3, 4);
	
	mainwin->DrawPolygon(x1, y1, 4);

	mainwin->DrawPolygon(x2, y2, 4);

	// The canon the short part
	int x = RefPoint.x, y=RefPoint.y;
	mainwin->DrawRectangle(
		(120 * width / basewidth) + x,
		(177 * height / basehieght) + y,
		(156 * width/ basewidth) + x,
		(156 * height / basehieght) + y
			);

	// The wheel frame
	mainwin->DrawPolygon(x5, y5, 8);

	// The wheels
	double r = sqrt(width*width + height*height);
	mainwin->DrawCircle(
		155 * width / basewidth + x,
		300 * height / basehieght + y,
		27 * r / basewidth);

	mainwin->DrawCircle(
		249 * width / basewidth + x, 
		300 * height / basehieght + y, 
		27 * r / basewidth);

	mainwin->DrawCircle(
		343 * width / basewidth + x, 
		300 * height / basehieght + y, 
		27 * r / basewidth);
}


void Bridge::draw() const {
	window* mainwin = pGame->getWind();
	mainwin->SetPen(fillColor, 3);
	mainwin->SetBrush(fillColor);
	int xtotal = 500, ytotal=500;

	// The lower part
	int x1[] = { 35, 35,460,460 };
	int y1[] = { 270, 240, 240, 270 };
	

	// The top part
	int x2[] = { 65,120,370,435,410,360,135,90};
	int y2[] = { 240,135,135,240,240,155,155,240};

	// The line points combination
	int lys[] = { 240, 150 };
	int lxs[] = { 135, 190, 250, 310, 360 };



	//Resize
	double sizey = height;
	for (int i = 0; i < 4; i++) {
		x1[i] *= (double)width / xtotal;
		y1[i] *= sizey / ytotal;
	}

	for (int i = 0; i < 8; i++) {
		x2[i] *= (double)width / xtotal;
		y2[i] *= sizey / ytotal;
	}
	for (int i = 0; i < 5; i++) {
		lxs[i] *= (double)width / xtotal;
	}
	lys[0] *= sizey / ytotal;
	lys[1] *= sizey / ytotal;


	//Shift
	int x = RefPoint.x, y = RefPoint.y;
	for (int i = 0; i < 4; i++) {
		x1[i] += x;
		y1[i] += y;
	}
	for (int i = 0; i < 8; i++) {
		x2[i] += x;
		y2[i] += y;
	}
	for (int i = 0; i < 5; i++) {
		lxs[i] += x;
	}
	lys[0] += y;
	lys[1] += y;


	mainwin->DrawPolygon(x1, y1, 4);
	mainwin->DrawPolygon(x2, y2, 8);

	// Connect the lines points
	for (int i = 0; i < 4; i++) {
		mainwin->DrawLine(lxs[i], lys[0], lxs[i], lys[1]);

		mainwin->DrawLine(lxs[i], lys[((i%2==0) ? 0  : 1)], lxs[i+1], lys[((i % 2 == 0) ? 1 : 0)]);

	}
	mainwin->DrawLine(lxs[4], lys[0], lxs[4], lys[1]);

}


void Ship::draw() const {
	window* mainwin = pGame->getWind();
	mainwin->SetPen(fillColor, 3);
	mainwin->SetBrush(fillColor);
	int xtotal = 500, ytotal = 251, 
		rtotal=sqrt(pow(xtotal, 2) + pow(ytotal, 2));
	// The main body
	int x1[] = {80,80,65,70,420,420,450,400,400,360,360,310,305,175, 170,145,145,105, 105  };
	int y1[] = {160,180,205,220,220,195,160,155,145,145,155,155,125,125, 155,155,140,140, 155 };
	
	// Resize
	for (int i = 0; i < 19; i++) {
		x1[i] *= (double)width / xtotal;
		y1[i] *= (double)height / ytotal;
	}
	
	// Shift
	for (int i = 0; i < 19; i++) {
		x1[i] += RefPoint.x;
		y1[i] += RefPoint.y;
	}
	
	mainwin->DrawPolygon(x1, y1, 19);

	// The two wepans
	int x = RefPoint.x, y = RefPoint.y, r = sqrt(width*width + height*height);
	mainwin->DrawCircle(
		125 * (double)width/ xtotal + x, 
		140 * (double)height / ytotal + y, 
		15 * (double)r / rtotal);
	mainwin->DrawCircle(
		380 * (double)width / xtotal + x,
		145 * (double)height / ytotal + y,
		15 * (double)r / rtotal);

	mainwin->DrawLine(
		385 * (double)width / xtotal + x, 
		140 * (double)height / ytotal + y, 
		420 * (double)width / xtotal + x, 
		115 * (double)height / ytotal + y);
	mainwin->DrawLine(
		120 * (double)width / xtotal + x, 
		135 * (double)height / ytotal + y, 
		85 * (double)width / xtotal + x,
		115 * (double)height / ytotal + y);


	// The satalite with its base
	int x2[] = {290, 285,215,215,185, 175 };
	int y2[] = {125, 105,105,85, 85, 125 };

	// Resize
	for (int i = 0; i < 6; i++) {
		x2[i] *= (double)width / xtotal;
		y2[i] *= (double)height / ytotal;
	}
	// Shift
	for (int i = 0; i < 6; i++) {
		x2[i] += x;
		y2[i] += y;
	}

	mainwin->DrawPolygon(x2, y2, 6);

	mainwin->DrawTriangle(
		195 * (double)width / xtotal + x, 
		85 * (double)height / ytotal + y,
		205 * (double)width / xtotal + x,
		50 * (double)height / ytotal + y,
		210 * (double)width / xtotal + x,
		85 * (double)height / ytotal + y, FRAME);

	mainwin->DrawArc(
		200 * (double)width / xtotal + x,
		10 * (double)height/ ytotal + y,
		240 * (double)width / xtotal + x,
		60 * (double)height / ytotal + y,
		180, 270);
	mainwin->DrawLine(
		200 * (double)width / xtotal + x,
		30 * (double)height / ytotal + y,
		225 * (double)width / xtotal + x,
		60 * (double)height / ytotal + y);
}

void EnemyManegar::moveForward(int speed) {
	min_current_y += speed;
	for (int i = 0; i < tanks.size(); i++) {
		tanks[i].set_y(tanks[i].get_y() + speed);
	}
	for (int i = 0; i < bridges.size(); i++) {
		bridges[i].set_y(bridges[i].get_y() + speed);
	}
	for (int i = 0; i < ships.size(); i++) {
		ships[i].set_y(ships[i].get_y() + speed);
	}

	for (int i = 0; i < jets.size(); i++) {
		jets[i].set_y(jets[i].get_y() + speed);
		jets[i].moveVertical();

	}
	for (int i = 0; i < helis.size(); i++) {
		helis[i].set_y(helis[i].get_y() + speed);
		helis[i].moveVertical();
	}
}

void EnemyManegar::view(window& mainwin) const {
	// View the tanks then briges then ships
	for (int i = 0; i < tanks.size(); i++) {
		tanks[i].draw();
	}
	for (int i = 0; i < bridges.size(); i++) {
		bridges[i].draw();
	}
	for (int i = 0; i < ships.size(); i++) {
		ships[i].draw();
	}

	for (int i = 0; i < jets.size(); i++) {
		jets[i].draw();
	}
	for (int i = 0; i < helis.size(); i++) {
		helis[i].draw();
	}
}

void EnemyManegar::update(int nspeed, int nlevel) {
	min_current_y = 100000;
	srand(time(0));
	speed = nspeed;
	level = nlevel;
	int otanknum = tanknum,
		obrigesum = brigesnum,
		oshipsnum = shipsnum,
		ojetsnum = jetsnum,
		ohelisnum = helisnum;
	// This formale needs to be changed
	tanknum = level + speed;
	brigesnum = level + speed;
	shipsnum = level + speed;
	jetsnum = level + speed;
	helisnum = level + speed;

	// Generates a randome size and x and y and color based on the conditions set for each object
	// notice i from otanknum to tanknum so that it would change the add ones only
	for (int i = 0; i < tanknum; i++) {
		point p{ 0,0 };
		tanks.push_back(Tank(game, p, 0, 0));

		int size = min_size + (rand() % (max_size - min_size - 1));
		tanks.back().set_size(size);

		int local_max_x = global_max_x;
		int local_max_y = global_max_y - tanks.back().get_height();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		tanks.back().set_x(x);
		tanks.back().set_y(y);

		int colori = floor(rand() % 4);
		tanks.back().set_color(colors[colori]);

		// Getting the value of the highest point in all enemyies
		if (tanks.back().get_y() < min_current_y) {
			min_current_y = tanks.back().get_y();
		}
	}

	for (int i = 0; i < brigesnum; i++) {
		point p{ 0,0 };
		int size = global_max_x - min_x;
		bridges.push_back(
			Bridge(game, p, size, .4 * (size))
		);

		int local_max_y = global_max_y - bridges.back().get_height();
		int x = min_x;
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		bridges.back().set_x(x);
		bridges.back().set_y(y);

		int colori = floor(rand() % 4);
		bridges.back().set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (bridges.back().get_y() < min_current_y) {
			min_current_y = bridges.back().get_y();
		}
	}
	
	for (int i = 0; i < shipsnum; i++) {
		point p{ 0,0 };
		ships.push_back(
			Ship(game, p, 0, 0)
		);
		
		int size = min_size + (rand() % (max_size - min_size + 1));
		ships.back().set_size(size);

		int local_max_x = global_max_x - ships.back().get_width();
		int local_max_y = global_max_y - ships.back().get_height();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		ships.back().set_x(x);
		ships.back().set_y(y);

		int colori = floor(rand()%4);
		ships.back().set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (ships.back().get_y() < min_current_y) {
			min_current_y = ships.back().get_y();
		}
	}
	
	for (int i = 0; i < jetsnum; i++) {
		//int size = min_size + (rand() % (max_size - min_size + 1));
		//jets[i].set_size(size);
		point p{ 0,0 };
		jets.push_back(
			EnemyPlane(game, p, 0, 0)
		);

		int local_max_x = -400;
		int local_max_y = global_max_y - jets.back().get_height();
		int x = -100;
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		jets.back().set_x(x);
		jets.back().set_y(y);

		int colori = floor(rand() % 4);
		jets.back().set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (jets.back().get_y() < min_current_y) {
			min_current_y = jets.back().get_y();
		}
	}

	for (int i = 0; i < helisnum; i++) {
		//int size = min_size + (rand() % (max_size - min_size + 1));
		//helis[i].set_size(size);
		point p{ 0,0 };
		helis.push_back(
			EnemyHelicopter(game, p, 0, 0)
		);


		int local_max_x = global_max_x - helis.back().get_width();
		int local_max_y = global_max_y - helis.back().get_height();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		helis.back().set_x(x);
		helis.back().set_y(y);

		int colori = floor(rand() % 4);
		helis.back().set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (helis.back().get_y() < min_current_y) {
			min_current_y = helis.back().get_y();
		}
	}

}

void EnemyPlane::draw() const {
	window *w = pGame->getWind();
	w->SetPen(BLACK);
	w->SetBrush(fillColor);
	int width = 50 * size;
	int height = 190 * size;
	int x = RefPoint.x, y = RefPoint.y;
	w->DrawRectangle(x-height, y - width, x, y);
	int x1[] = { x - 20 * size, x - 40 * size, x - 100 * size, x - 80 * size };
	int y1[] = { y, y + 100 * size, y + 100 * size, y };
	w->DrawPolygon(x1, y1, 4, FILLED);
	int x2[] = { x - 20 * size,
	x - 80 * size,
	x - 100 * size,
	x - 40 * size };
	int y2[] = { y - (width - 1),
	y - (width - 1),
	y - (width + 100 * size - 1),
	y - (width + 100 * size - 1) };
	w->DrawPolygon(x2, y2, 4, FILLED);
	int x3[] = { x - height + 50 * size,
	x - height + 30 * size,
	x - height - 20 * size,
	x - height };
	int y3[] = { y,
	y + 50 * size,
	y + 50 * size,
	y };
	w->DrawPolygon(x3, y3, 4, FILLED);
	int x4[] = { x - height + 50 * size,
	x - height,
	x - height - 20 * size,
	x - height + 30 * size };
	int y4[] = { y - (width - 1),
	y - (width - 1),
	y - (width + 50 * size - 1),
	y - (width + 50 * size - 1) };
	w->DrawPolygon(x4, y4, 4, FILLED);
}

void EnemyPlane::moveVertical()
{
	if (get_y() > 0)
		set_x(get_x() + verticalspeed);
}

void EnemyHelicopter::draw() const {
	window* w = pGame->getWind();
	int x = RefPoint.x, y = RefPoint.y;
	w->SetPen(BLACK);
	w->SetBrush(ORANGE);
	w->DrawRectangle(x - 80 * size, y - 70 * size, x + 80 * size, y - (70 - 20) * size);
	w->DrawRectangle(x - 10 * size, y - 80 * size, x + 10 * size, y + 80 * size);
	w->SetBrush(BLACK);
	w->DrawRectangle(x - 150 * size, y + 10 * size, x + 70 * size, y - 10 * size);
	w->DrawRectangle(x - 140 * size, y - 20 * size, x - 130 * size, y + 20 * size);
	w->DrawRectangle(x - 40 * size, y + 60 * size, x + 40 * size, y + 80 * size);
	w->SetPen(BLACK);
	w->SetBrush(fillColor);
	w->DrawCircle(x, y, 50 * size);
}

void EnemyHelicopter::moveVertical() {
	if (get_y() >= 0) {
		set_x(get_x() + verticalspeed);
		if (get_x() > config.endRiver || get_x() < config.startRiver) {
			verticalspeed = -verticalspeed;
		}
	}
}

