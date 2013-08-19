#ifndef POLYGON_T_H
#define POLYGON_T_H

#include <list>
using namespace std;
#include "object_t.h"
#include "point_t.h"
#include "fill_t.h"

//Class for polygon object
class polygon_t : public object_t{
	list<point_t> vertices;
	bool isFilled;
	fill_t fill;
	public:
		//constructor for polygon class
		polygon_t(pen_t);	//empty vertices and pen only with no fill
		polygon_t(list<point_t>,pen_t); 	//manually putting a list of vertices with no fill
		polygon_t(pen_t,bool,fill_t);		//constructor with fill information
		polygon_t(list<point_t>,pen_t,bool,fill_t);
		polygon_t();		//vertices,pen= empty,pen_t()

		list<point_t> getVertices() const;			//Returns vertices of polygon
		list<point_t> setVertices(list<point_t>);		//sets and Returns new vertices of polygon
		bool getIsFilled() const;			//Returns isFilled of polygon
		bool setIsFilled(bool);		//sets and Returns new isFilled of polygon
		fill_t getFill() const;			//Returns fill of polygon
		fill_t setFill(fill_t);		//sets and Returns new fill of polygon


		list<point_t> addVertex(point_t);			//adds a new point in vertices list and return vertex list
		void draw();	//draw function override to draw a polygon
};
#endif
