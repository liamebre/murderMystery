#pragma once
#include "inc.h"

class player
{
public:
	RectangleShape body;
	Vector2f position;
	Vector2f size;
	int speed;
	string name = "john player";
	vector<bool> directions = { false,false,false,false };//up,down,left,right
	vector<String> sayings = { "p line 1","p line 2","p line 3 " };
	int currSay = 0; // keeps track of the current saying to display

	player(Vector2f _pos = { 0,0 }, Vector2f _size = { 0,0 }); // <-- Add default values
	~player();

	void moveup();
	void movedown();
	void moveleft();
	void moveright();

	void update(Time dt);
};

