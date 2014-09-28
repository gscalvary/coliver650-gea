#include "Point.h"

// Point:
// EFFECT: Creates a point object in memory with x and y components both set to 0.
// Example: see test class.
Point::Point() {
	x = 0;
	y = 0;
}
// ~Point:
// EFFECT: De-allocates the memory reserved for a Point object.
Point::~Point() {

}
// getPointx: -> int
// Takes no input but returns a number representing the x coordinate of the point in 2D space.
// Example: see test class.
int Point::getPointx() {
	return x;
}
// getPointy: -> int
// Takes no input but returns a number representing the y coordinate of the point in 2D space.
// Example: see test class.
int Point::getPointy() {
	return y;
}
// updatePointx: int ->
// Takes a number and sets the x coordinate of the point to it.
// Example: see test class.
void Point::updatePointx(int newx) {
	x = newx;
}
// updatePointy: int ->
// Takes a number and sets the y coordinate of the point to it.
// Example: see test class.
void Point::updatePointy(int newy) {
	y = newy;
}