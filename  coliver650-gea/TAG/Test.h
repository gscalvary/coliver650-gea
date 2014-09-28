#pragma once
#include <cassert>
#include <stdlib.h>
#include "Circle.h"
#include "Clock.h"
#include "Game.h"
#include "Message.h"
#include "Npc.h"
#include "Point.h"
#include "Player.h"

// An object created to facilitate testing, only one is created when the game runs in test mode.
class Test {
private:

public:
	// Test:
	// EFFECT: Creates a Test object in memory.
	// Example: Test testGame;
	Test();
	// ~Test:
	// EFFECT: De-allocates the memory reserved for a Test object.
	~Test();
	// test_Clock_class:
	// EFFECT: Allocates a Clock object and executes and validates the effects of all its functions.
	// Example: testGame.test_Clock_class();
	void test_Clock_class();
	// test_Game_class:
	// EFFECT: Allocates a Game object and any children objects and executes and validates the effects of all its functions.
	// Example: testGame.test_Game_class();
	void test_Game_class();
	// test_Point_class:
	// EFFECT: Allocates a Point object and executes and validates the effects of all its functions.
	// Example: testGame.test_Point_class();
	void test_Point_class();
	// test_Player_class:
	// EFFECT: Allocates a Player object and any children objects and executes and validates the effects of all its functions.
	// Example: testGame.test_Player_class();
	void test_Player_class();
	// test_Message_class:
	// EFFECT: Allocates a Message object and executes and validates the effects of all its functions.
	// Example: testGame.test_Message_class();
	void test_Message_class();
	// test_Npc_class:
	// EFFECT: Allocates an Npc object and any children objects and executes and validates the effects of all its functions.
	// Example: testGame.test_Npc_class();
	void test_Npc_class();
	// test_Circle_class:
	// EFFECT: Allocates a Circle object and any children objects and executes and validates the effects of all its functions.
	// Example: testGame.test_Circle_class();
	void test_Circle_class();
};