#ifndef FILL_T_H
#define FILL_T_H

#include "object_t.h"
#include "pen_t.h"
#include "point_t.h"

#include <fstream>
#include <vector>
using namespace std;
//Class for fill object
class fill_t : public object_t{
	pen_t pen1, pen2;
	bool fillType;		//0 = solid, 1 = checkboard
	point_t point;		//point inside bounded region
	public:
		//constructor for fill class
		fill_t(pen_t,point_t);	//directly square fill pen1=pen2
		fill_t(pen_t,pen_t,bool,point_t);
		fill_t(const fill_t&);
		fill_t();		//fillType,pen= 0,pen_t()

		pen_t getPen() const;			//Returns pen1 of fill
		pen_t setPen(pen_t);		//sets and Returns new pen1,pen2 of fill
		pen_t getPen1() const;			//Returns pen1 of fill
		pen_t setPen1(pen_t);		//sets and Returns new pen1 of fill
		pen_t getPen2() const;			//Returns pen2 of fill only if fillType checkbox
		pen_t setPen2(pen_t);		//sets and Returns new pen1 of fill
		bool getFillType() const;			//Returns fillType of fill
		bool setFillType(bool);		//sets and Returns new fillType of fill
		point_t getPoint() const;		// returns point of fill
		point_t setPoint(point_t);		//sets and returns point of fill

		void draw(vector<vector<bool> >&);	//draw function override to draw a fill
		void print(fstream&);
};
#endif
