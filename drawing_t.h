#ifndef DRAWING_T_H
#define DRAWING_T_H

#include "object_t.h"
#include "line_t.h"
#include "point_t.h"
#include "polygon_t.h"
#include "fill_t.h"

#include <list>
using namespace std;


//Class for drawing object
class drawing_t {
	list<object_t*> objects;
	public:
		//constructor for drawing_t
		drawing_t(list<object_t*>);
		drawing_t();

		list<object_t*> getObjects() const;		//returns list of objects
		list<object_t*> setObjects(list<object_t*>);	//sets list of objects
		list<object_t*> addObject(line_t);		//adds a line to list
		list<object_t*> addObject(point_t);		//adds a point to list
		list<object_t*> addObject(polygon_t);		//adds a polygon to list
		list<object_t*> addObject(fill_t);		//adds a fill to list
		void emptyObjectList();						//empties the list

		void draw();	//calls draw of all objects
};
#endif
