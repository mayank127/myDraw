#include "object_t.h"
#include "point_t.h"
#include <list>

#ifndef POLYGON_T_H
#define POLYGON_T_H
//Class for polygon object
class polygon_t : public object_t{
	list<point_t> vertices;

	public:
		//constructor for polygon class
		polygon_t(pen_t);	//empty vertices and pen only
		polygon_t(list<point_t>, pen_t); 	//manually putting a list of vertices
		polygon_t();		//vertices,pen= empty,pen_t()

		list<point_t> getVertices() const;			//Returns vertices of polygon
		list<point_t> setP1(list<point_t>);		//sets and Returns new vertices of polygon

		list<point_t> addVertex(point_t);			//adds a new point in vertices list and return vertex list
		void draw();	//draw function override to draw a polygon
};
#endif