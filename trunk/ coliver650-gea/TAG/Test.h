#pragma once
#include <cassert>
#include <stdlib.h>
#include "Clock.h"
#include "Game.h"
#include "Point.h"

class Test {
private:

public:
	Test();
	~Test();

	void test_Clock_class();
	void test_Game_class();
	void test_Point_class();
};