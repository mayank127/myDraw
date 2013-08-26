#ifndef CANVAS_T_H
#define CANVAS_T_H

#include <vector>
#include "drawing_t.h"
#include "pen_t.h"
using namespace std;

//Class for canvas object
class canvas_t {
	pen_t currentPen;
	int width;
	int height;
	pen_t bgColor;

	public:
		//constructor for canvas_t
		drawing_t drawing;
		vector<vector<bool> >  twoDArray;
		canvas_t(int, int, pen_t);
		canvas_t(drawing_t, int, int, pen_t);
		canvas_t(drawing_t, int, int, pen_t, pen_t);
		canvas_t();

		drawing_t getDrawing() const;			//Returns drawing of pen
		drawing_t setDrawing(drawing_t);		//sets and Returns new drawing of pen
		pen_t getBGColor() const;		//Returns bgcolor of pen
		pen_t setBGColor(pen_t);	//sets and returns new bgcolor of pen
		int getWidth() const;		//Returns width  of pen
		int setWidth(int);	//sets and returns width  of pen
		int getHeight() const;		//Returns height  of pen
		int setHeight(int);	//sets and returns height  of pen
		pen_t getCurrentPen() const; //Returns current pen of pen
		pen_t setCurrentPen(pen_t); //sets and returns current pen

		void clear();	//clears canvas
		void draw();
};
#endif
