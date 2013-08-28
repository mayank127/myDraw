#include "line_t.h"
#include <GL/glut.h>
#include <cmath>

using namespace std;

line_t::line_t(point_t p1,point_t p2, pen_t pen) :object_t(pen){
	this->p1 = p1;
	this->p2 = p2;
	this->p1.setPen(pen);
	this->p2.setPen(pen);
}
line_t::line_t(const line_t& line) :object_t(line.pen){
	this->p1 = line.p1;
	this->p2 = line.p2;
	this->p1.setPen(line.pen);
	this->p2.setPen(line.pen);
}

line_t::line_t() :object_t(){
	p1 = point_t();
	p2 = point_t();
}

point_t line_t::getP1() const{
	return p1;
}

point_t line_t::setP1(point_t p1){
	this->p1 = p1;
	return p1;
}

point_t line_t::getP2() const{
	return p2;
}

point_t line_t::setP2(point_t p2){
	this->p2 = p2;
	return p2;
}

void swap (int &x, int &y)
{
  int temp = x;
  x = y; y = temp;
}

void line_t::draw(vector<vector<bool> >& twoDArray){
	glColor3f((float)pen.getColor().r/255,(float)pen.getColor().g/255,(float)pen.getColor().b/255);
	int x0 = p1.getX(), x1 = p2.getX(), y0 = p1.getY(), y1 = p2.getY();
	bool steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep){
		swap(x0, y0);
		swap(x1, y1);
	}
	if (x0 > x1){
		swap(x0, x1);
		swap(y0, y1);
	}
	int deltax = x1 - x0;
	int deltay = abs(y1 - y0);

	float error = 0.0;
	float deltaerr = (float)deltay / (float)deltax;

	int ystep;
	int y = y0;

	if (y0 <= y1) ystep = 1; else ystep = -1;

	point_t tempPoint = point_t();
	tempPoint.setPen(this->pen);

	for (int x=x0; x <= x1; x++){
		if (steep){
			tempPoint.setX(y);
			tempPoint.setY(x);
		}
		else{
			tempPoint.setX(x);
			tempPoint.setY(y);
		}
		tempPoint.draw(twoDArray);
		error = error + deltaerr;
		if (error >= 0.5){
			y = y + ystep;
			error = error - 1.0;
		}
	}
}

void line_t::print(fstream& fs){
	fs<<"line "<<p1.getX()<<" "<<p1.getY()<<" "<<p2.getX()<<" "<<p2.getY()<<" "<<pen.getColor().r<<" "<<pen.getColor().g<<" "<<pen.getColor().b<<" "<<pen.getSize()<<" "<<pen.getEraseMode()<<endl;
}