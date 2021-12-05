#include "ChessPoint.h"

const char ChessPoint::get_x() const {
	return this->x;
}
const char ChessPoint::get_y() const {
	return this->y;
}
const Color ChessPoint::get_color() const {
	return this->color;
}

ChessPoint::ChessPoint() {
	//TODO
	//验证x,y的可用性；
}

ChessPoint::ChessPoint(const char x, const char y ,const Color color) {
	this->color = color;
	this->x = x;
	this->y = y;
}
