#include "item.h"
item::item(Vector2f _pos = { 50.0f,50.0f }, Vector2f size_ = {30.0f,30.0f})
{
	position = _pos;
	size = size_;
	body.setSize(size);
	body.setOrigin({ size.x / 2,size.y / 2 });
	body.setPosition(position);
}
item::~item()
{
	size = { 0,0 };
	position = { 0,0 };
	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(Color::Yellow);
}


void item::update(Time dt)
{
}

void item::itemCollision(player& p)
{
	if ((position.x + size.x > p.position.x > position.x)&&(position.y + size.y > p.position.y > position.y)) {
		cout << "collision" << endl;
	}
}
