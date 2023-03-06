#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;

class frog
{
private: // only visible by class members
	float xpos;
	float ypos;
	int lives;
	float xVel;
	float yVel;
	float speed;

public: // visible by anything
	frog();
	void draw(sf::RenderWindow & window);  // & returns the address of a pointer
	void jump(bool* keys); // * returns the value of a pointer

	float returnX() { return xpos; } // we're defining this function here instead of the cpp file because of its size
	float returnY() { return ypos; }

	void dead();

	int returnLives() { return lives; }
	void printInfo() { cout << "I am a frog and my position is " << xpos << ", " << ypos << endl; }
};

