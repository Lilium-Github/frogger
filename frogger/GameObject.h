#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"globals.h"

using namespace std;

class gameObject {
public:
	// virtual functions; placeholders in the parent class
	// defined by child classes, allows us to make a vector of all gameObjects
	// and access them like that

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void move() = 0;
	virtual void printInfo() = 0;
	virtual bool collide(int x, int y) = 0;

protected:
	// "protected" means that these variables can be accessed by classes that inherit from gameobject

	float xpos;
	float ypos;
	int green = rand() % 100;
	int blue = rand() % 200;
	int dir = RIGHT;
};

class car : public gameObject {
public:
	car(int x, int y, int d) {
		xpos = x;
		ypos = y;
		dir = d;
	}
	void draw(sf::RenderWindow& window);
	void move();
	bool collide(int x, int y);
	void printInfo() { cout << "I am car (" << xpos << "," << ypos << ")" << endl; }
};