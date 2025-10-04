#pragma once
#include "player.h"
class item
{
public:
	RectangleShape body;
	Vector2f position;
	Vector2f size;

	item(Vector2f _pos, Vector2f _size );
	~item();
	void update(Time dt);
	void itemCollision(player& p);
};

