#include "Enemy.h"
#include "GameConfig.h"


void Tank::draw(window& mainwin) const {
	mainwin.SetPen(tcolor, 3);
	mainwin.SetBrush(tcolor);
	int xtotal = 500, ytotal = 500;
	int x1[] = {220, 240, 350, 370};
	int y1[] = {195, 145, 145, 195};

	int x2[] = { 163, 227, 226, 163 };
	int y2[] = { 163, 164, 173, 174 };
	int x3[] = { 171, 205, 417, 423 };
	int y3[] = { 229, 205, 205, 230 };

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

	mainwin.DrawRectangle(
		(120 * size / xtotal) + x,
		(177 * size / ytotal) + y,
		(156 * size / xtotal) + x,
		(156 * size / ytotal) + y
			);

	mainwin.DrawPolygon(x5, y5, 8);

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

	
	int x1[] = { 35, 35,460,460 };
	int y1[] = { 270, 240, 240, 270 };
	


	int x2[] = { 65,120,370,435,410,360,135,90};
	int y2[] = { 240,135,135,240,240,155,155,240};

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

	mainwin.DrawCircle(125 * size/ xtotal + x, 140 * size / ytotal + y, 15 * size / rtotal);
	mainwin.DrawCircle(380 * size / xtotal + x, 145 * size / ytotal + y, 15 * size / rtotal);

	mainwin.DrawLine(385 * size / xtotal + x, 140 * size / ytotal + y, 420 * size / xtotal + x, 115 * size / ytotal + y);
	mainwin.DrawLine(120 * size / xtotal + x, 135 * size / ytotal + y, 85 * size / xtotal + x, 115 * size / ytotal + y);


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


