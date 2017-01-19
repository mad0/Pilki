#pragma once
#include "Item.h"
#include <SFML\Graphics.hpp>

class Engine {
private:
	sf::RenderWindow okno;
	void draw();
	void update();
	std::vector<std::unique_ptr<Item>> pojemnik;
public:
	Engine();
	~Engine();
	void start();
	

};