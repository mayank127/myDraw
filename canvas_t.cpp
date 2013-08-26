#include "canvas_t.h"

canvas_t::canvas_t(int width, int height, pen_t bgColor) :twoDArray(width, vector<bool>(height, false)) {
	this->drawing = drawing_t();
	this->width = width;
	this->height = height;
	this->bgColor = bgColor;
}
canvas_t::canvas_t(drawing_t drawing, int width, int height, pen_t bgColor) :twoDArray(width, vector<bool>(height, false)) {
	this->drawing = drawing;
	this->width = width;
	this->height = height;
	this->bgColor = bgColor;
	this->currentPen = pen_t();
}
canvas_t::canvas_t(drawing_t drawing, int width, int height, pen_t bgColor, pen_t currentPen) :twoDArray(width, vector<bool>(height, false)) {
	this->drawing = drawing;
	this->width = width;
	this->height = height;
	this->bgColor = bgColor;
	this->currentPen = currentPen;
}
canvas_t::canvas_t():twoDArray(0, vector<bool>(0, false)){
	this->drawing = drawing_t();
	this->width = 0;
	this->height = 0;
	this->bgColor = pen_t();
	this->currentPen = pen_t();
}

drawing_t canvas_t::getDrawing() const{
	return drawing;
}
drawing_t canvas_t::setDrawing(drawing_t drawing){
	this->drawing = drawing;
	return drawing;
}
pen_t canvas_t::getBGColor() const{
	return bgColor;
}
pen_t canvas_t::setBGColor(pen_t bgColor){
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
pen_t canvas_t::setCurrentPen(pen_t currentPen){
	this->currentPen = currentPen;
	return currentPen;
}

void canvas_t::clear(){
	drawing.emptyObjectList();
}

void canvas_t::draw(){
	for(int i=0;i<width;i++)
		for(int j=0;j<height;j++)
			twoDArray[i][j]=false;
	drawing.draw(twoDArray);
}