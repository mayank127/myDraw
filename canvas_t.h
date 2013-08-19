#ifndef CANVAS_T_H
#define CANVAS_T_H

#include "drawing_t.h"
#include "pen_t.h"
#include "color_t.h"

//Class for canvas object
class canvas_t {
	drawing_t drawing;
	pen_t currentPen;
	int width;
	int height;
	color_t bgColor;

	public:
		//constructor for canvas_t
		canvas_t(int, int, color_t);
		canvas_t(drawing_t, int, int, color_t);
		canvas_t();

		drawing_t getDrawing() const;			//Returns drawing of pen
		drawing_t setDrawing(drawing_t);		//sets and Returns new drawing of pen
		color_t getBGColor() const;		//Returns bgcolor of pen
		color_t setBGColor(color_t);	//sets and returns new bgcolor of pen
		int getWidth() const;		//Returns width  of pen
		int setWidth(int);	//sets and returns width  of pen
		int getHeight() const;		//Returns height  of pen
		int setHeight(int);	//sets and returns height  of pen
		pen_t getCurrenPen() const; //Returns current pen of pen
		pen_t setCurrentPen(pen_t); //sets and returns current pen

		void clear();	//clears canvas
};
#endif
