#include "drawing_t.h"
#include <iostream>
using namespace std;

drawing_t::drawing_t(list<object_t*> objects){
	this->objects = objects;
}
drawing_t::drawing_t(){
	this->objects = list<object_t*>();
}

list<object_t*> drawing_t::getObjects() const{
	return objects;
}
list<object_t*> drawing_t::setObjects(list<object_t*> objects){
	this->objects = objects;
	return objects;
}
list<object_t*> drawing_t::addObject(line_t line){
	objects.push_back(new line_t(line));
	return objects;
}
list<object_t*> drawing_t::addObject(point_t point){
	objects.push_back(new point_t(point));
	return objects;
}
list<object_t*> drawing_t::addObject(polygon_t polygon){
	objects.push_back(new polygon_t(polygon));
	return objects;
}
list<object_t*> drawing_t::addObject(fill_t fill){
	objects.push_back(new fill_t(fill));
	return objects;
}
void drawing_t::emptyObjectList(){
	objects.clear();
}
void drawing_t::removeLastObject(){
	objects.pop_back();
}
//this loops over objects list and draws all the objects in it
void drawing_t::draw(vector<vector<bool> >& twoDArray){
	for (list<object_t*>::iterator iterator = objects.begin(), end = objects.end(); iterator != end; ++iterator) {
    	(*iterator)->draw(twoDArray);
	}
}

//callls print function for fstream of every object
void drawing_t::print(fstream& fs){
	for (list<object_t*>::iterator iterator = objects.begin(), end = objects.end(); iterator != end; ++iterator) {
    	(*iterator)->print(fs);
	}
}
