#include "object_t.h"

object_t::object_t(pen_t pen){
	this->pen = pen;
}

object_t::object_t(){
	this->pen = pen_t();
}

pen_t object_t::getPen() const{
	return pen;
}

pen_t object_t::setPen(pen_t pen){
	this->pen = pen_t(pen);
	return pen;
}
void object_t::draw(vector<vector<bool> >& twoDArray){

}

void object_t::print(fstream& fs){

}