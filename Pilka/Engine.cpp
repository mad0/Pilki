#include "Engine.h"
#include <iostream>

Engine::Engine() {
	std::cout << "Engine start...\n";
	okno.create(sf::VideoMode(1024,768),"Pilki...");
}
Engine::~Engine(){
	std::cout << "Engine stop...\n";
}

void Engine::Start() {
	std::cout << "metoda START...\n";
	while (okno.isOpen()) {
		sf::Event zdarz;
		while (okno.pollEvent(zdarz)) {
			if (zdarz.type == sf::Event::Closed)
				okno.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				okno.close();
		}
		okno.clear(sf::Color::Black);
		okno.display();
	}

}