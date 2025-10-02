#include "textBox.h"
#include "player.h"
#include "NPC.h"

int main()
{
	float width = 1920;
	float height = 1080;
	Vector2u resolution = Vector2u(width,height);
	Vector2f screenSize = Vector2f(width, height);
	VideoMode vm(resolution);
	RenderWindow window(vm, "murderMystery",State::Fullscreen);	

	Font font;
	if (!font.openFromFile("fonts/tuffy.ttf")) { cerr << "Error: Could not load font!" << endl; }

	Text text(font," ",30);
	textBox tb(screenSize,text,font);

	vector<String> lines{ "filler 1" };
	int* currline;

	player p1({ width / 2,height / 2 }, { 30,60 });
	NPC npc1({ width / 4, height / 4 }, {30,60});

	Clock clock;
	Clock gameClock;

	//keeps window open
	while (window.isOpen()) {
		Time dt = clock.restart();
		Time gc = gameClock.getElapsedTime();
		while (const optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>() || Keyboard::isKeyPressed(Keyboard::Key::Escape))
				// Quit the game when the window is closed
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Enter) && tb.isActive) {
			tb.nextline(gc);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
			p1.moveup();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
			p1.movedown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
			p1.moveleft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
			p1.moveright();
		}
		lines = npc1.dialogue(p1, tb, lines);	

		npc1.update(dt, p1, tb, lines);
		p1.update(dt);
		tb.update(text, lines, npc1.currSay);
		// Update the game state
		window.clear();
		tb.getTextBox(window,text);
		window.draw(p1.body);
		window.draw(npc1.body);
		window.display();

	}//end of open window

}//end of main

