#pragma once
class Point
{
private:
	int x;
	int y;

public:
	Point();
	~Point();
	int getPointx();
	int getPointy();
	void updatePointx(int x);
	void updatePointy(int y);
};

