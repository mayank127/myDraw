#include "point_t.h"

point_t::point_t(int x, int y,pen_t pen) :object_t(pen){
	this->x = x;
	this->y = y;
}

point_t::point_t() :object_t(){
	this->x = 0;
	this->y = 0;
}

int point_t::getX() const{
	return x;
}

int point_t::setX(int x){
	this->x = x;
	return x;
}

int point_t::getY() const{
	return y;
}

int point_t::setY(int y){
	this->y = y;
	return y;
}

void point_t::draw() {
	glColor3f(pen.getColor().r/255,pen.getColor().g/255,pen.getColor().b/255);
	glPointSize(pen.getSize());
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}