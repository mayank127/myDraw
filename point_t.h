#ifndef POINT_T_H
#define POINT_T_H

#include "object_t.h"
#include "pen_t.h"

//Class for point object
class point_t : public object_t{
	int x;
	int y;
	public:
		//constructor for point class
		point_t(int,int,pen_t);
		point_t();		//x,y,pen= 0,0,pen_t()

		int getX() const;			//Returns X of point
		int setX(int);		//sets and Returns new X of point
		int getY() const;			//Returns Y of point
		int setY(int);		//sets and Returns new Y of point

		void draw();	//draw function override to draw a point
};
#endif
