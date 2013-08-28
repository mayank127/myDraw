#ifndef POLYGON_T_H
#define POLYGON_T_H

#include "object_t.h"
#include "point_t.h"
#include <vector>
#include <list>

#include <fstream>
using namespace std;

//Class for polygon object
class polygon_t : public object_t{
	list<point_t> vertices;
	public:
		//constructor for polygon class
		polygon_t(pen_t);	//empty vertices and pen only with no fill
		polygon_t(list<point_t>,pen_t); 	//manually putting a list of vertices with no fill
		polygon_t(const polygon_t&);
		polygon_t();		//vertices,pen= empty,pen_t()

		list<point_t> getVertices() const;			//Returns vertices of polygon
		list<point_t> setVertices(list<point_t>);		//sets and Returns new vertices of polygon

		list<point_t> addVertex(point_t);			//adds a new point in vertices list and return vertex list
		list<point_t> done();				//completes the list by adding last vertex
		void draw(vector<vector<bool> >&);	//draw function override to draw a polygon
		void print(fstream&);
};
#endif
