#include "Engine.h"
#include <iostream>

Engine::Engine() {
	std::cout << "Engine start...\n";
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	okno.create(sf::VideoMode(1024,768),"Pilki...", sf::Style::Default, settings);
	okno.setFramerateLimit(60);
	okno.setVerticalSyncEnabled(true);
}
Engine::~Engine(){
	std::cout << "Engine stop...\n";
}

void Engine::start() {
	std::cout << "metoda START...\n";
	while (okno.isOpen()) {
		sf::Event zdarz;
		while (okno.pollEvent(zdarz)) {
			if (zdarz.type == sf::Event::Closed)
				okno.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				okno.close();
		}
		update();
		draw();
	}

}

void Engine::update() {
	pierwsze.update();
}

void Engine::draw() {
	okno.clear(sf::Color::Magenta);
	okno.draw(pierwsze);
	okno.display();
}