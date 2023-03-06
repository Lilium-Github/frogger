#include "frog.h"
#include "globals.h"
#include <SFML/Graphics.hpp>
#include<Windows.h>

frog::frog() { // This is a constructor; it fills in all our class variables.
	xpos = 500;
	ypos = 954;
	lives = 5;
	xVel = 0;
	yVel = 0;
	speed = 50;
}

void frog::draw(sf::RenderWindow& window) {
	sf::RectangleShape FrogPic(sf::Vector2f(20, 20)); // creates a rectangle called frogpic
	FrogPic.setFillColor(sf::Color(50, 200, 50)); // makes frogpic green
	FrogPic.setPosition(xpos, ypos); // sets frogpics position to that of the frog object
	window.draw(FrogPic); // draws frogpic to the screen
}

void frog::jump(bool* keys) { // move function. takes a pointer to the array that holds key presses
	if (keys[UP])
		yVel = -1*speed;
	else if (keys[DOWN])
		yVel = speed;
	else
		yVel = 0;
	ypos += yVel;

	if (keys[LEFT])
		xVel = -1*speed;
	else if (keys[RIGHT])
		xVel = speed;
	else
		xVel = 0;
	xpos += xVel;
}

void frog::dead() {
	Beep(500, 500); // temp death sfx
	// TODO explosion animation. get on that
	lives--;
}