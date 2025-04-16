#include "Enemy.h"
#include<iostream>
using namespace std;



void Tank::draw(window& mainwin) const {
	mainwin.SetPen(tcolor, 3);
	mainwin.SetBrush(tcolor);
	int xtotal = 500, ytotal = 500;
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
		x1[i] *= size / xtotal;
		y1[i] *= size / ytotal;
		x2[i] *= size / xtotal;
		y2[i] *= size / ytotal;
		x3[i] *= size / xtotal;
		y3[i] *= size / ytotal;
	}
	for (int i = 0; i < 6; i++) {
		x4[i] *= size / xtotal;
		y4[i] *= size / ytotal;
	}
	for (int i = 0; i < 8; i++) {
		x5[i] *= size / xtotal;
		y5[i] *= size / ytotal;
	}

	//Shift
	for (int i = 0; i < 4; i++) {
		x1[i] += x;
		y1[i] += y;
		x2[i] += x;
		y2[i] += y;
		x3[i] += x;
		y3[i] += y;
	}
	for (int i = 0; i < 6; i++) {
		x4[i] += x;
		y4[i] += y;
	}
	for (int i = 0; i < 8; i++) {
		x5[i] += x;
		y5[i] += y;
	}


	mainwin.DrawPolygon(x4, y4, 6);

	mainwin.DrawPolygon(x3, y3, 4);
	
	mainwin.DrawPolygon(x1, y1, 4);

	mainwin.DrawPolygon(x2, y2, 4);

	// The canon the short part
	mainwin.DrawRectangle(
		(120 * size / xtotal) + x,
		(177 * size / ytotal) + y,
		(156 * size / xtotal) + x,
		(156 * size / ytotal) + y
			);

	// The wheel frame
	mainwin.DrawPolygon(x5, y5, 8);

	// The wheels
	mainwin.DrawCircle(
		155 * size / xtotal + x,
		300 * size / ytotal + y,
		27 * size / xtotal);

	mainwin.DrawCircle(
		249 * size / xtotal + x, 300 * size / ytotal + y, 27 * size / xtotal);

	mainwin.DrawCircle(343 * size / xtotal + x, 300 * size / ytotal + y, 27 * size / xtotal);
}


void Bridge::draw(window& mainwin) const {
	mainwin.SetPen(bcolor, 3);
	mainwin.SetBrush(bcolor);
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
	for (int i = 0; i < 4; i++) {
		x1[i] *= size / xtotal;
		y1[i] *= size / ytotal;
	}

	for (int i = 0; i < 8; i++) {
		x2[i] *= size / xtotal;
		y2[i] *= size / ytotal;
	}
	for (int i = 0; i < 5; i++) {
		lxs[i] *= size / xtotal;
	}
	lys[0] *= size / ytotal;
	lys[1] *= size / ytotal;


	//Shift
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


	mainwin.DrawPolygon(x1, y1, 4);
	mainwin.DrawPolygon(x2, y2, 8);

	// Connect the lines points
	for (int i = 0; i < 4; i++) {
		mainwin.DrawLine(lxs[i], lys[0], lxs[i], lys[1]);

		mainwin.DrawLine(lxs[i], lys[((i%2==0) ? 0  : 1)], lxs[i+1], lys[((i % 2 == 0) ? 1 : 0)]);

	}
	mainwin.DrawLine(lxs[4], lys[0], lxs[4], lys[1]);

}


void Ship::draw(window& mainwin) const {
	mainwin.SetPen(scolor, 3);
	mainwin.SetBrush(scolor);
	int xtotal = 500, ytotal = 251, 
		rtotal=sqrt(pow(xtotal, 2) + pow(ytotal, 2));
	// The main body
	int x1[] = {80,80,65,70,420,420,450,400,400,360,360,310,305,175, 170,145,145,105, 105  };
	int y1[] = {160,180,205,220,220,195,160,155,145,145,155,155,125,125, 155,155,140,140, 155 };
	
	// Resize
	for (int i = 0; i < 19; i++) {
		x1[i] *= size / xtotal;
		y1[i] *= size / ytotal;
	}
	
	// Shift
	for (int i = 0; i < 19; i++) {
		x1[i] += x;
		y1[i] += y;
	}
	
	mainwin.DrawPolygon(x1, y1, 19);

	// The two wepans
	mainwin.DrawCircle(125 * size/ xtotal + x, 140 * size / ytotal + y, 15 * size / rtotal);
	mainwin.DrawCircle(380 * size / xtotal + x, 145 * size / ytotal + y, 15 * size / rtotal);

	mainwin.DrawLine(385 * size / xtotal + x, 140 * size / ytotal + y, 420 * size / xtotal + x, 115 * size / ytotal + y);
	mainwin.DrawLine(120 * size / xtotal + x, 135 * size / ytotal + y, 85 * size / xtotal + x, 115 * size / ytotal + y);


	// The satalite with its base
	int x2[] = {290, 285,215,215,185, 175 };
	int y2[] = {125, 105,105,85, 85, 125 };

	// Resize
	for (int i = 0; i < 6; i++) {
		x2[i] *= size / xtotal;
		y2[i] *= size / ytotal;
	}
	// Shift
	for (int i = 0; i < 6; i++) {
		x2[i] += x;
		y2[i] += y;
	}

	mainwin.DrawPolygon(x2, y2, 6);

	mainwin.DrawTriangle(195 * size / xtotal + x, 85 * size / ytotal + y, 205 * size / xtotal + x, 50 * size / ytotal + y, 210 * size / xtotal + x, 85 * size / ytotal + y, FRAME);

	mainwin.DrawArc(200 * size / xtotal + x, 10 * size / ytotal + y, 240 * size / xtotal + x, 60 * size / ytotal + y, 180, 270);
	mainwin.DrawLine(200 * size / xtotal + x, 30 * size / ytotal + y, 225 * size / xtotal + x, 60 * size / ytotal + y);
}

void Enemy::moveForward(int speed) {
	min_current_y += speed;
	for (int i = 0; i < tanknum; i++) {
		tanks[i].set_y(tanks[i].get_y() + speed);
	}
	for (int i = 0; i < brigesnum; i++) {
		bridges[i].set_y(bridges[i].get_y() + speed);
	}
	for (int i = 0; i < shipsnum; i++) {
		ships[i].set_y(ships[i].get_y() + speed);
	}

	for (int i = 0; i < jetsnum; i++) {
		jets[i].set_y(jets[i].get_y() + speed);
	}
	for (int i = 0; i < helisnum; i++) {
		helis[i].set_y(helis[i].get_y() + speed);
	}
}

void Enemy::view(window& mainwin) const {
	// View the tanks then briges then ships
	for (int i = 0; i < tanknum; i++) {
		tanks[i].draw(mainwin);
	}
	for (int i = 0; i < brigesnum; i++) {
		bridges[i].draw(mainwin);
	}
	for (int i = 0; i < shipsnum; i++) {
		ships[i].draw(mainwin);
	}

	for (int i = 0; i < jetsnum; i++) {
		jets[i].draw(mainwin);
	}
	for (int i = 0; i < helisnum; i++) {
		helis[i].draw(mainwin);
	}
}

void Enemy::update(int nspeed, int nlevel) {
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
	for (int i = otanknum; i < tanknum; i++) {
		int size = min_size + (rand() % (max_size - min_size - 1));
		tanks[i].set_size(size);

		int local_max_x = global_max_x - tanks[i].get_size();
		int local_max_y = global_max_y - tanks[i].get_size();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		tanks[i].set_x(x);
		tanks[i].set_y(y);

		int colori = floor(rand() % 4);
		tanks[i].set_color(colors[colori]);

		// Getting the value of the highest point in all enemyies
		if (tanks[i].get_y() < min_current_y) {
			min_current_y = tanks[i].get_y();
		}
	}
	
	for (int i = obrigesum; i < brigesnum; i++) {
		int size = min_size + (rand() % (max_size - min_size + 1));
		bridges[i].set_size(size);

		int local_max_x = global_max_x - bridges[i].get_size();
		int local_max_y = global_max_y - bridges[i].get_size();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		bridges[i].set_x(x);
		bridges[i].set_y(y);

		int colori = floor(rand() % 4);
		bridges[i].set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (bridges[i].get_y() < min_current_y) {
			min_current_y = bridges[i].get_y();
		}
	}
	
	for (int i = oshipsnum; i < shipsnum; i++) {
		int size = min_size + (rand() % (max_size - min_size + 1));
		ships[i].set_size(size);

		int local_max_x = global_max_x - ships[i].get_size();
		int local_max_y = global_max_y - ships[i].get_size();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		ships[i].set_x(x);
		ships[i].set_y(y);

		int colori = floor(rand()%4);
		ships[i].set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (ships[i].get_y() < min_current_y) {
			min_current_y = ships[i].get_y();
		}
	}
	
	for (int i = ojetsnum; i < jetsnum; i++) {
		//int size = min_size + (rand() % (max_size - min_size + 1));
		//jets[i].set_size(size);

		int local_max_x = global_max_x - jets[i].get_size();
		int local_max_y = global_max_y - jets[i].get_size();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		jets[i].set_x(x);
		jets[i].set_y(y);

		int colori = floor(rand() % 4);
		jets[i].set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (jets[i].get_y() < min_current_y) {
			min_current_y = jets[i].get_y();
		}
	}

	for (int i = ohelisnum; i < helisnum; i++) {
		//int size = min_size + (rand() % (max_size - min_size + 1));
		//helis[i].set_size(size);

		int local_max_x = global_max_x - helis[i].get_size();
		int local_max_y = global_max_y - helis[i].get_size();
		int x = min_x + (rand() % (local_max_x - min_x - 1));
		int y = min_y + (rand() % (local_max_y - min_y - 1));

		helis[i].set_x(x);
		helis[i].set_y(y);

		int colori = floor(rand() % 4);
		helis[i].set_color(colors[colori]);
		// Getting the value of the highest point in all enemyies
		if (helis[i].get_y() < min_current_y) {
			min_current_y = helis[i].get_y();
		}
	}
}

void EnemyPlane::draw(window& w) const {
	w.SetPen(BLACK);
	w.SetBrush(pcolor);
	int width = 50 * size;
	int height = 190 * size;
	w.DrawRectangle(x, y - height, x + width, y);
	int x1[] = { x, x - 100 * size, x - 100 * size, x };
	int y1[] = { y - 20 * size, y - 40 * size, y - 100 * size, y - 80 * size };
	w.DrawPolygon(x1, y1, 4, FILLED);
	int x2[] = { x + (width - 1), x + (width - 1), x + (width + 100 * size - 1), x + (width + 100 * size - 1) };
	int y2[] = { y - 20 * size, y - 80 * size, y - 100 * size, y - 40 * size };
	w.DrawPolygon(x2, y2, 4, FILLED);
	int x3[] = { x, x - 50 * size, x - 50 * size, x };
	int y3[] = { y - height + 50 * size, y - height + 30 * size, y - height - 20 * size, y - height };
	w.DrawPolygon(x3, y3, 4, FILLED);
	int x4[] = { x + (width - 1), x + (width - 1), x + (width + 50 * size - 1), x + (width + 50 * size - 1) };
	int y4[] = { y - height + 50 * size, y - height, y - height - 20 * size, y - height + 30 * size };
	w.DrawPolygon(x4, y4, 4, FILLED);
}

void EnemyHelicopter::draw(window& w) const {
	w.SetPen(BLACK);
	w.SetBrush(ORANGE);
	w.DrawRectangle(x - 80 * size, y - 70 * size, x + 80 * size, y - (70 - 20) * size);
	w.DrawRectangle(x - 10 * size, y - 80 * size, x + 10 * size, y + 80 * size);
	w.SetBrush(BLACK);
	w.DrawRectangle(x - 150 * size, y + 10 * size, x + 70 * size, y - 10 * size);
	w.DrawRectangle(x - 140 * size, y - 20 * size, x - 130 * size, y + 20 * size);
	w.DrawRectangle(x - 40 * size, y + 60 * size, x + 40 * size, y + 80 * size);
	w.SetPen(BLACK);
	w.SetBrush(hcolor);
	w.DrawCircle(x, y, 50 * size);
}

