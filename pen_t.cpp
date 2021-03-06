#include "pen_t.h"

pen_t::pen_t(int size,color_t color,bool eraseMode){
	this->size = size;
	this->color = color;
	this->eraseMode = eraseMode;
}
pen_t::pen_t(const pen_t& pen){
	this->size = pen.size;
	this->color = pen.color;
	this->eraseMode = pen.eraseMode;
}
pen_t::pen_t(){
	this->size = 1;
	this->color = color_t();
	this->eraseMode = false;
}
int pen_t::getSize() const{
	return size;
}

int pen_t::setSize(int size){
	this->size = size;
	return size;
}

color_t pen_t::getColor() const{
	return color;
}

color_t pen_t::setColor(color_t color){
	this->color = color;
	return color;
}

bool pen_t::getEraseMode() const{
	return eraseMode;
}

bool pen_t::setEraseMode(bool eraseMode){
	this->eraseMode = eraseMode;
	return eraseMode;
}
