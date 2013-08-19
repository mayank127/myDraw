#include "canvas_t.h"

canvas_t::canvas_t(int width, int height, color_t bgColor){
	this->drawing = drawing_t();
	this->width = width;
	this->height = height;
	this->bgColor = bgColor;
}
canvas_t::canvas_t(drawing_t drawing, int width, int height, color_t bgColor){
	this->drawing = drawing;
	this->width = width;
	this->height = height;
	this->bgColor = bgColor;
	this->currentPen = pen_t();
}
canvas_t::canvas_t(drawing_t drawing, int width, int height, color_t bgColor, pen_t currentPen){
	this->drawing = drawing;
	this->width = width;
	this->height = height;
	this->bgColor = bgColor;
	this->currentPen = currentPen;
}
canvas_t::canvas_t(){
	this->drawing = drawing_t();
	this->width = 0;
	this->height = 0;
	this->bgColor = color_t();
	this->currentPen = pen_t();
}

drawing_t canvas_t::getDrawing() const{
	return drawing;
}
drawing_t canvas_t::setDrawing(drawing_t drawing){
	this->drawing = drawing;
	return drawing;
}
color_t canvas_t::getBGColor() const{
	return bgColor;
}
color_t canvas_t::setBGColor(color_t bgColor){
	this->bgColor = bgColor;
	return bgColor;
}
int canvas_t::getWidth() const{
	return width;
}
int canvas_t::setWidth(int width){
	this->width = width;
	return width;
}
int canvas_t::getHeight() const{
	return height;
}
int canvas_t::setHeight(int height){
	this->height = height;
	return height;
}
pen_t canvas_t::getCurrentPen() const{
	return currentPen;
}
pen_t canvas_t::setCurrentPen(pen_t){
	this->currentPen = currentPen;
	return currentPen;
}

void canvas_t::clear(){
	drawing.emptyObjectList();
}