#include "polygon_t.h"
#include "line_t.h"

polygon_t::polygon_t(pen_t pen) :object_t(pen){

}

polygon_t::polygon_t(list<point_t> vertices,pen_t pen) :object_t(pen){
	this->vertices = vertices;
}


polygon_t::polygon_t(const polygon_t& polygon) :object_t(polygon.pen){
	this->vertices = polygon.vertices;
}

polygon_t::polygon_t() :object_t(){

}

list<point_t> polygon_t::getVertices() const{
	return vertices;
}

list<point_t> polygon_t::setVertices(list<point_t>){
	this->vertices = vertices;
	return vertices;
}

list<point_t> polygon_t::addVertex(point_t p){
	p.setPen(this->pen);
	vertices.push_back(p);
	return vertices;
}

list<point_t> polygon_t::done(){
	this->vertices.push_back(this->vertices.front());
	return vertices;
}

//looping over all points two make lines and calling drawing fucntion from line
void polygon_t::draw(vector<vector<bool> >& twoDArray){
	line_t tempLine = line_t();
	tempLine.setPen(this->getPen());
	for (list<point_t>::const_iterator iterator = vertices.begin(), end = vertices.end();;) {
    	tempLine.setP1(*iterator);
    	iterator++;
    	if(iterator!=end){
	    	tempLine.setP2(*(iterator));
	    	tempLine.draw(twoDArray);
	    }else{
	    	break;
	    }
	}
}

//printing polygon to fstream
//n , n (x,y pairs), r, g, b, size, mode
void polygon_t::print(fstream& fs){
	fs<<"polygon "<<vertices.size()<<" ";
	for(list<point_t>::const_iterator it = vertices.begin(); it != vertices.end(); ++it)
		fs<<(*it).getX()<<" "<<(*it).getY()<<" ";
	fs<<pen.getColor().r<<" "<<pen.getColor().g<<" "<<pen.getColor().b<<" "<<pen.getSize()<<" "<<pen.getEraseMode()<<endl;
}
