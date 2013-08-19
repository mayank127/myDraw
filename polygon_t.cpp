#include "polygon_t.h"
#include "line_t.h"

polygon_t::polygon_t(pen_t pen) :object_t(pen){
	this->isFilled = false;
	this->fill = fill_t();
}

polygon_t::polygon_t(list<point_t> vertices,pen_t pen) :object_t(pen){
	this->vertices = vertices;
	this->isFilled = false;
	this->fill = fill_t();
}

polygon_t::polygon_t(pen_t pen,bool isFilled,fill_t fill) :object_t(pen){
	this->isFilled = isFilled;
	this->fill = fill;
}

polygon_t::polygon_t(list<point_t> vertices,pen_t pen,bool isFilled,fill_t fill) :object_t(pen){
	this->vertices = vertices;
	this->isFilled = isFilled;
	this->fill = fill;
}

polygon_t::polygon_t() :object_t(){
	this->fill = fill_t();
}

list<point_t> polygon_t::getVertices() const{
	return vertices;
}

list<point_t> polygon_t::setVertices(list<point_t>){
	this->vertices = vertices;
	return vertices;
}

bool polygon_t::getIsFilled() const{
	return isFilled;
}

bool polygon_t::setIsFilled(bool isFilled){
	this->isFilled = isFilled;
	return isFilled;
}

fill_t polygon_t::getFill() const{
	return fill;
}

fill_t polygon_t::setFill(fill_t fill){
	this->fill = fill;
	return fill;
}

list<point_t> polygon_t::addVertex(point_t p){
	vertices.push_back(p);
	return vertices;
}

void polygon_t::draw(){
	line_t tempLine = line_t();
	tempLine.setPen(this->getPen());
	for (list<point_t>::const_iterator iterator = vertices.begin(), end = vertices.end();;) {
    	tempLine.setP1(*iterator);
    	iterator++;
    	if(iterator!=end){
	    	tempLine.setP2(*(iterator));
	    	tempLine.draw();
	    }else{
	    	break;
	    }
	}
}
