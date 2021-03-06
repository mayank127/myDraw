#ifndef OBJECT_T_H
#define OBJECT_T_H

#include "pen_t.h"
#include <vector>
#include <fstream>
using namespace std;

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

		virtual void draw(vector<vector<bool> >&);		//virtual draw function for each object
		virtual void print(fstream&);
};
#endif
