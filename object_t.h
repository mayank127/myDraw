#ifndef OBJECT_T_H
#define OBJECT_T_H

#include "pen_t.h"

//Abstract class for drawable objects
class object_t {
	protected:
		pen_t pen;
	public:
		//Constructors for object abstract class
		object_t(pen_t);
		object_t();					//pen = pen_t()

		pen_t getPen() const;				//Returns pen of object
		pen_t setPen(pen_t);		//sets and Returns new pen of object

		virtual void draw() =0;		//virtual draw function for each object
};
#endif
