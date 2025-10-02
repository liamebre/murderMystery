#include "textBox.h"

textBox::~textBox()
{
	position = Vector2f(0.f, 0.f);
	size = Vector2f(0.f, 0.f);

	baseBox.setSize(size);
	baseBox.setPosition(position);
	baseBox.setFillColor(Color::Black);
	baseBox.setOutlineColor(Color::White);

	textArea.setSize(size);
	textArea.setPosition(position);
}

textBox::textBox( Vector2f _size,Text& _text,Font _font)
{
	size = { _size.x - 100, _size.y / 4};
	position = { 50, size.y * 3 - 30};
	font = _font;
	isActive = false;

	baseBox.setSize({ size.x, size.y});
	baseBox.setPosition({ position.x, position.y });
	baseBox.setFillColor(Color::Black);
	baseBox.setOutlineColor(Color::White);
	baseBox.setOutlineThickness(5.f);

	textArea.setSize(Vector2f(size.x - 20.f, size.y - 20.f));
	textArea.setPosition(Vector2f(position.x + 10.f, position.y + 10.f));
	textArea.setFillColor(Color::White);

	_text.setCharacterSize(75);
	_text.setPosition(Vector2f(position.x + 20.f, position.y + 20.f));
	_text.setFillColor(Color::Black);
	_text.setString("                                 hello world");

}

void textBox::nextline(Time gt)
{
	if (gt.asMilliseconds() - lastInputsTime.asMilliseconds() < 300) {
		return;
	}
	else {
		nextLine = true;
		lastInputsTime = gt;
	}
}

void textBox::update(Text& _text,vector<String> lines, int line)
{
	if (isActive && nextLine) {
		_text.setString(changeText(lines,line));
		line++;
		nextLine = false;
	}
}

String textBox::changeText(vector<String> texts, int line)
{
	if (line >= texts.size()) {
		// Hide the textbox when we've reached the end
		isActive = false;
		line = static_cast<int>(texts.size()) - 1; // Stay on last message
		return texts[line];
	}
	return texts[line];
}

void textBox::getTextBox(RenderWindow& _window, Text& _text)
{
	if (isActive) {
		_window.draw(baseBox);
		_window.draw(textArea);
		_window.draw(_text);
		Text temp(font, "(Press enter to continue)",25U );
		temp.setFillColor({ 128, 128, 128, 175 });
		temp.setPosition(Vector2f(position.x + size.x - 275.f, position.y + size.y - 45.f));
		_window.draw(temp);
	}
}

void textBox::activate()
{
	isActive = true;
}