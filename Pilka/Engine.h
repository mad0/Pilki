#pragma once
#include "Item.h"
#include <SFML\Graphics.hpp>

class Engine {
private:
	sf::RenderWindow okno;
	Item pierwsze;
	void draw();
	void update();
public:
	Engine();
	~Engine();
	void start();
	

};