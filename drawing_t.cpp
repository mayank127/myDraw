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
list<object_t*> drawing_t::addObject(line_t& line){
	objects.push_back(&line);
	return objects;
}
list<object_t*> drawing_t::addObject(point_t& point){
	objects.push_back(&point);
	return objects;
}
list<object_t*> drawing_t::addObject(polygon_t& polygon){
	objects.push_back(&polygon);
	return objects;
}
list<object_t*> drawing_t::addObject(fill_t& fill){
	objects.push_back(&fill);
	return objects;
}
void drawing_t::emptyObjectList(){
	objects.clear();
}

void drawing_t::draw(){
	cout<<"Drawing"<<endl;
	for (list<object_t*>::const_iterator iterator = objects.begin(), end = objects.end(); iterator != end; ++iterator) {
    	(*iterator)->draw();
	}
}