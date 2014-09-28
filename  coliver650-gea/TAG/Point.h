#pragma once
class Point
{
private:
	int x;
	int y;

public:
	// Point:
	// EFFECT: Creates a point object in memory with x and y components both set to 0.
	// Example: see test class.
	Point();
	// ~Point:
	// EFFECT: De-allocates the memory reserved for a Point object.
	~Point();
	// getPointx: -> int
	// Takes no input but returns a number representing the x coordinate of the point in 2D space.
	// Example: see test class.
	int getPointx();
	// getPointy: -> int
	// Takes no input but returns a number representing the y coordinate of the point in 2D space.
	// Example: see test class.
	int getPointy();
	// updatePointx: int ->
	// Takes a number and sets the x coordinate of the point to it.
	// Example: see test class.
	void updatePointx(int x);
	// updatePointy: int ->
	// Takes a number and sets the y coordinate of the point to it.
	// Example: see test class.
	void updatePointy(int y);
};

