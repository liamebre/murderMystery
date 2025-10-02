#include "player.h"

player::player(Vector2f _pos, Vector2f _size)
{

	size = _size;
	body.setSize(size);
	body.setOrigin({ size.x / 2,size.y / 2 });

	position = _pos;
	body.setPosition(position);

	body.setFillColor(Color::Green);

	body.setOutlineColor(Color::White);
	body.setOutlineThickness(size.x / 15);

	speed = 300;
}

player::~player()
{
	size = Vector2f(0.f, 0.f);
	position = Vector2f(0.f, 0.f);
	body.setSize(size);
	body.setPosition(position);
	speed = 0;

}

void player::moveup()
{
	directions[0] = true;
}

void player::movedown()
{
	directions[1] = true;
}

void player::moveleft()
{
	directions[2] = true;
}

void player::moveright()
{
	directions[3] = true;
}
void player::update(Time dt)
{
    bool vertical = directions[0] || directions[1]; // up or down
    bool horizontal = directions[2] || directions[3]; // left or right

    float moveSpeed = speed;
    if (vertical && horizontal) {
        moveSpeed /=1.414 ; // Reduce speed for diagonal movement

    }

    if (directions[0]) position.y -= moveSpeed * dt.asSeconds(); // up
    if (directions[1]) position.y += moveSpeed * dt.asSeconds(); // down
    if (directions[2]) position.x -= moveSpeed * dt.asSeconds(); // left
    if (directions[3]) position.x += moveSpeed * dt.asSeconds(); // right

    body.setPosition(position);
    directions = { false, false, false, false };
}

