#pragma once
#include "Item.h"
#include <SFML\Graphics.hpp>

class Engine {
private:
	sf::RenderWindow okno;
public:
	Engine();
	~Engine();
	void Start();

};