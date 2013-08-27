#include "color_t.h"

color_t::color_t(int r,int g,int b){
	this->r = r%256;
	this->g = g%256;
	this->b = b%256;
}

color_t::color_t(){
	this->r=0;
	this->g=0;
	this->b=0;
}

