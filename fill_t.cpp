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

void fill_t::draw(vector<vector<bool> >& twoDArray){
	//draw method for fill
	pen1.setSize(1);
	pen2.setSize(1);
	fillHelper(point.getX(),point.getY(),twoDArray);
}


void fill_t::fillHelper(int x,int y,vector<vector<bool> >& twoDArray){
	int w = twoDArray.size();
	int h = twoDArray[0].size();
	if(x>w || x<0 || y>h ||y<0) return;

	if(twoDArray[x][y]==false){
		
		point_t tempPoint = point_t();
		if(fillType = 0)  tempPoint.setPen(this->pen1);
		else{
			if(x%8<=3 && y%8<=3 || x%8>=4 && y%8>=4) tempPoint.setPen(this->pen1);
			else tempPoint.setPen(this->pen2);
		}
		tempPoint.setX(x);
		tempPoint.setY(y);

		tempPoint.draw(twoDArray);
	
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(i==0 && j==0) continue;
				else fillHelper(x+i,y+j,twoDArray);
			}
		}
	}
}
