#pragma once
#include "inc.h"
#include "player.h"

class textBox
{
public:
	RectangleShape baseBox;
	RectangleShape textArea;
	Vector2f size;
	Vector2f position;
	~textBox();
	textBox(Vector2f _size, Text& _text, Font _font);
	bool nextLine = false;
	bool isActive = true;
	Time lastInputsTime = Time::Zero;
	Font font;

	void getTextBox(RenderWindow& _window, Text& _text);
	void activate();
	void nextline(Time clock);
	void update(Text& _text, vector<String> lines, int& line);
	String changeText(vector<String> texts, int line);

};

