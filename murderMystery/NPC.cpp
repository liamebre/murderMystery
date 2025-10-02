#include "NPC.h"

NPC::NPC(Vector2f _pos, Vector2f _size)
{
	size = _size;
	body.setSize(size);
	body.setOrigin({ size.x / 2,size.y / 2 });
	position = _pos;
	body.setPosition(position);
	body.setFillColor(Color::Red);
	body.setOutlineColor(Color::White);
	body.setOutlineThickness(size.x / 15);
	speed = 200;
}

NPC::~NPC()
{
	size = { 0,0 };
	position = { 0,0 };
	speed = 0;

	body.setSize(size);
	body.setPosition(position);
}

void NPC::dectectPlayer(player& p, textBox& tb)
{

	if (abs(position.x - p.position.x) < (size.x / 2 + p.size.x / 2 + 30) &&
		abs(position.y - p.position.y) < (size.y / 2 + p.size.y / 2 + 30))
	{
		// Player is within interaction range
		currSay = 0; // Reset to the first line of dialogue
		tb.activate();
	}
	else {
		tb.isActive = false;
	}
}

vector<String> NPC::dialogue(player& p, textBox& tb, vector<String> lines)
{
	if (tb.isActive) {
		lines = sayings;
	}
	return lines;
}

void NPC::update(Time dt, player& p, textBox& tb, vector<String> lines)
{
	dectectPlayer(p, tb);
	dialogue(p, tb, lines);
}

