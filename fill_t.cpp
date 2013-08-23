#include "fill_t.h"

fill_t::fill_t(pen_t pen, point_t point) :object_t(pen){
	this->pen1 = pen;
	this->pen2 = pen;
	this->point = point;
	this->fillType = 0;
}
fill_t::fill_t(const fill_t& fill) :object_t(fill.pen){
	this->pen1 = fill.pen;
	this->pen2 = fill.pen;
	this->point = fill.point;
	this->fillType = fill.fillType;
}
fill_t::fill_t(pen_t pen1, pen_t pen2,bool fillType, point_t point) :object_t(pen){
	this->pen1 = pen1;
	if(fillType)
		this->pen2 = pen2;
	else
		this->pen2 = pen1;
	this->point = point;
	this->fillType = fillType;
}
fill_t::fill_t() :object_t(){
	this->pen1 = pen_t();
	this->pen2 = pen_t();
	this->point = point_t();
	this->fillType = 0;
}

pen_t fill_t::getPen() const{
	return pen1;
}
pen_t fill_t::setPen(pen_t pen){
	this->pen1 = pen;
	this->pen2 = pen;
	return pen;
}
pen_t fill_t::getPen1() const{
	return pen1;
}
pen_t fill_t::setPen1(pen_t pen){
	this->pen1 = pen;
	return pen;
}
pen_t fill_t::getPen2() const{
	return pen2;
}
pen_t fill_t::setPen2(pen_t pen){
	this->pen2 = pen;
	return pen;
}
bool fill_t::getFillType() const{
	return fillType;
}
bool fill_t::setFillType(bool fillType){
	this->fillType = fillType;
	return fillType;
}
point_t fill_t::getPoint() const{
	return point;
}
point_t fill_t::setPoint(point_t point){
	this->point = point;
	return point;
}

void fill_t::draw(){
	//draw method for fill
}