#include "fill_t.h"
#include <iostream>
#include <GL/glut.h>
#include <queue>
using namespace std;
fill_t::fill_t(pen_t pen, point_t point) :object_t(pen){
	this->pen1 = pen;
	this->pen2 = pen;
	this->point = point;
	this->fillType = 0;
}
fill_t::fill_t(const fill_t& fill) :object_t(fill.pen){
	this->pen1 = fill.pen1;
	this->pen2 = fill.pen2;
	this->point = fill.point;
	this->fillType = fill.fillType;
}
fill_t::fill_t(pen_t pen1, pen_t pen2, bool fillType, point_t point) :object_t(pen1){
	this->pen1 = pen1;
	this->pen2 = pen2;
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
	this->pen1 = pen_t(pen);
	this->pen2 = pen_t(pen);
	return pen;
}
pen_t fill_t::getPen1() const{
	return pen1;
}
pen_t fill_t::setPen1(pen_t pen){
	this->pen1 = pen_t(pen);
	return pen;
}
pen_t fill_t::getPen2() const{
	return pen2;
}
pen_t fill_t::setPen2(pen_t pen){
	this->pen2 = pen_t(pen);
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

//draw method for fill
void fill_t::draw(vector<vector<bool> >& twoDArray){
	int w = twoDArray.size();
	if(w<=0) return;
	int h = twoDArray[0].size();
	pen1.setSize(1);
	pen2.setSize(1);

	queue<point_t> neighbours;		//keeping neighbours array
	vector<vector<bool> >  isSeen(w, vector<bool>(h, false));	//keeping count of seen neighbours
	int x = point.getX();
	int y = point.getY();
	if(x>=w || x<0 || y>=h ||y<0)return;
	if(twoDArray[x][y]==true) return;
	neighbours.push(point);
	while(!neighbours.empty()){
		point_t p = point_t(neighbours.front());
		x = p.getX();
		y = p.getY();
		if(!twoDArray[x][y] && !isSeen[x][y]){

			isSeen[x][y] = true;
			point_t tempPoint;
			if(!fillType) {
				glColor3f((float)pen1.getColor().r/255,(float)pen1.getColor().g/255,(float)pen1.getColor().b/255);
				tempPoint = point_t(x,y, pen1);
			}
			else{
				if((x%16<=7 && y%16<=7) || (x%16>=7 && y%16>=7)){
					glColor3f((float)pen1.getColor().r/255,(float)pen1.getColor().g/255,(float)pen1.getColor().b/255);
					tempPoint = point_t(x,y, pen1);
				}
				else{
					tempPoint = point_t(x,y,pen2);
					glColor3f((float)pen2.getColor().r/255,(float)pen2.getColor().g/255,(float)pen2.getColor().b/255);
				}
			}
			tempPoint.draw(twoDArray);
			twoDArray[x][y] = false;
			for(int i=-1;i<=1;i++){
				if(x+i>=w || x+i <0) continue;
				for(int j=-1;j<=1;j++){
					if(y+j>=h || y+j <0) continue;
					else if(i==j || i==-1*j) continue;
					else if(!twoDArray[x+i][y+j] && !isSeen[x+i][y+j]) neighbours.push(point_t(x+i,y+j));
				}
			}
		}
		neighbours.pop();
	}

}

//printing fill to fstream
//x, y, type, r1,g1,b1,r2,g2,b2
void fill_t::print(fstream& fs){
	fs<<"fill "<<point.getX()<<" "<<point.getY()<<" "<<" "<<fillType<<" "<<pen1.getColor().r<<" "<<pen1.getColor().g<<" "<<pen1.getColor().b<<" "<<pen2.getColor().r<<" "<<pen2.getColor().g<<" "<<pen2.getColor().b<<endl;
}
