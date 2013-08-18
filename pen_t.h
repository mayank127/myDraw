#include "color_t.h"

#ifndef PEN_T_H
#define PEN_T_H
//class for pen object
class pen_t {
	int size;
	color_t color;
	bool eraseMode;	//Not sure about this.
	public:
		//Constructors for pen class
		pen_t(int, color_t, bool);
		pen_t();			//size,color,eraseMode = 0,color_t(), false

		int getSize() const;			//Returns size of pen
		int setSize(int);		//sets and Returns new size of pen
		color_t getColor() const;		//Returns color of pen
		color_t setColor(color_t);	//sets and returns new color of pen
		bool getEraseMode() const;		//Returns erase mode of pen
		bool setEraseMode(bool);	//sets and returns erase mode of pen
};
#endif