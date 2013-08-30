#include "line_t.h"
#include <GL/glut.h>
#include <cmath>

using namespace std;

line_t::line_t(point_t p1,point_t p2, pen_t pen) :object_t(pen){
	this->p1 = p1;
	this->p2 = p2;
	this->p1.setPen(pen);
	this->p2.setPen(pen);
}
line_t::line_t(const line_t& line) :object_t(line.pen){
	this->p1 = line.p1;
	this->p2 = line.p2;
	this->p1.setPen(line.pen);
	this->p2.setPen(line.pen);
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

//draw function for bresenham in all integer
void line_t::draw(vector<vector<bool> >& twoDArray){
	glColor3f((float)pen.getColor().r/255,(float)pen.getColor().g/255,(float)pen.getColor().b/255);
	int x0 = p1.getX(), x1 = p2.getX(), y0 = p1.getY(), y1 = p2.getY();

	int x,y,dx,dy,dx1,dy1,newx,newy,xend,yend,i;
 	dx=x1-x0;
	dy=y1-y0;
 	dx1=abs(dx);
 	dy1=abs(dy);
 	newx=2*dy1-dx1;
 	newy=2*dx1-dy1;

 	point_t tempPoint = point_t();
	tempPoint.setPen(this->pen);

	if(dy1<=dx1){		//if line is not steep
		if(dx>=0){	//checking for coordinate with higher value of x
			x=x0;
			y=y0;
			xend=x1;
		}
		else{
			x=x1;
			y=y1;
			xend=x0;
		}
		tempPoint.setX(x);
		tempPoint.setY(y);
		tempPoint.draw(twoDArray);
		for(i=0;x<xend;i++){	//looping over x and till xend and updating according to bresenham
			x=x+1;
			if(newx<0){
				newx=newx+2*dy1;
			}
			else{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
					y=y+1;
				else
					y=y-1;
				newx=newx+2*(dy1-dx1);
			}
			tempPoint.setX(x);
			tempPoint.setY(y);
			tempPoint.draw(twoDArray);
		}
	}
	else{
		if(dy>=0){	//swapping of coordinates
			x=x0;
			y=y0;
			yend=y1;
		}
		else{
			x=x1;
			y=y1;
			yend=y0;
		}
		tempPoint.setX(x);
		tempPoint.setY(y);
		tempPoint.draw(twoDArray);
		for(i=0;y<yend;i++){
			y=y+1;
			if(newy<=0){
				newy=newy+2*dx1;
			}
			else{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
					x=x+1;
				else{
					x=x-1;
				}
				newy=newy+2*(dx1-dy1);
			}
			tempPoint.setX(x);
			tempPoint.setY(y);
			tempPoint.draw(twoDArray);
		}
	}
}

//printing line to fstream
//x0, y0, x1, y1, r, g, b, size, mode
void line_t::print(fstream& fs){
	fs<<"line "<<p1.getX()<<" "<<p1.getY()<<" "<<p2.getX()<<" "<<p2.getY()<<" "<<pen.getColor().r<<" "<<pen.getColor().g<<" "<<pen.getColor().b<<" "<<pen.getSize()<<" "<<pen.getEraseMode()<<endl;
}
