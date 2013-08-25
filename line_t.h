#ifndef LINE_T_H
#define LINE_T_H

#include "object_t.h"
#include "point_t.h"

#include <vector>
using namespace std;

//Class for line object
class line_t : public object_t{
	point_t p1;
	point_t p2;

	public:
		//constructor for line class
		line_t(point_t,point_t,pen_t);
		line_t(const line_t&);
		line_t();		//p1,p2,pen= point_t(),point_t(),pen_t()

		point_t getP1() const;			//Returns P1 of line
		point_t setP1(point_t);		//sets and Returns new X of line
		point_t getP2() const;			//Returns Y of line
		point_t setP2(point_t);		//sets and Returns new Y of line

		void draw(vector<vector<bool> >&);	//draw function override to draw a line
};
#endif
