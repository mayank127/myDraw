#include "line_t.h"

line_t::line_t(point_t p1,point_t p2, pen_t pen) :object_t(pen){
	this->p1 = p1;
	this->p2 = p2;
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

void line_t::draw(){

}
