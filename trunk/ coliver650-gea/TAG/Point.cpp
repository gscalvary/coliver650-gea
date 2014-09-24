#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
}

Point::~Point() {

}

int Point::getPointx() {
	return x;
}

int Point::getPointy() {
	return y;
}

void Point::updatePointx(int newx) {
	x = newx;
}

void Point::updatePointy(int newy) {
	y = newy;
}