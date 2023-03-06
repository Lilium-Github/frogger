#include <SFML/Graphics.hpp>
#include <iostream>
#include"globals.h"
#include"frog.h"

using namespace std;

int main()
{
	// game variables and setup
	srand(time(NULL)); // seed our rand function
	bool keys[] = { false, false, false, false};

	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger");

	frog player;

	int timer = 0;

	while (screen.isOpen()) { // #GAMELOOP #################################
		// recieve input -----------------
		sf::Event event;
		while (screen.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				screen.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				keys[UP] = true;
			else keys[UP] = false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				keys[DOWN] = true;
			else keys[DOWN] = false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				keys[LEFT] = true;
			else keys[LEFT] = false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				keys[RIGHT] = true;
			else keys[RIGHT] = false;
		}

		// update ------------------------
		timer++;
		if (timer > 240) {
			timer = 0;
			player.jump(keys);
		}
		// render ------------------------
		screen.clear();
		player.draw(screen);
		screen.display();
	}
	 // end game loop ######################################################

	cout << "game over." << endl;
	return 0;
}