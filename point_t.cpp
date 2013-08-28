#include "point_t.h"
#include <GL/glut.h>
#include <iostream>

point_t::point_t(int x, int y,pen_t pen) :object_t(pen){
	this->x = x;
	this->y = y;
}

point_t::point_t(int x, int y) :object_t(){
	this->x = x;
	this->y = y;
}

point_t::point_t(const point_t& point) :object_t(point.pen){
	this->x = point.x;
	this->y = point.y;
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

void point_t::draw(vector<vector<bool> >& twoDArray) {
	glColor3f((float)pen.getColor().r/255,(float)pen.getColor().g/255,(float)pen.getColor().b/255);
	glBegin(GL_POINTS);

	int ps = pen.getSize();
	int w = twoDArray.size();
	if(w<=0) return ;
	int h = twoDArray[0].size();
	for(int i=x-ps/2 ; i<=x+ps/2 ; i++){
		if(i>=w) break;
		for(int j=y-ps/2 ; j<=y+ps/2 ; j++){
			if(j>=h) break;
			if(i>=0 && j>=0){
				if(!pen.getEraseMode())	twoDArray[i][j] = true;
				else	twoDArray[i][j] = false;
				glVertex2f(i,j);
			}
		}
	}
	glEnd();
}

void point_t::print(fstream& fs){
	fs<<"point "<<x<<" "<<y<<" "<<pen.getColor().r<<" "<<pen.getColor().g<<" "<<pen.getColor().b<<" "<<pen.getSize()<<" "<<pen.getEraseMode()<<endl;
}