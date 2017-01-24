#include "Engine.h"
#include <iostream>
#include <typeinfo>

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
	//pojemnik.erase(pojemnik.begin()+3);
}

void Engine::start() {
	std::cout << "metoda START...\n";
	while (okno.isOpen()) {
		sf::Event zdarz;
			while (okno.pollEvent(zdarz)){

				if (zdarz.type == sf::Event::Closed)
					okno.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					okno.close();

				if (zdarz.type == sf::Event::KeyReleased) {
					if (zdarz.key.code == sf::Keyboard::D) {
						std::cout << "Wciskam D \n";
						if (pojemnik.size() > 0)
							pojemnik.erase(pojemnik.begin());
					}
					if (zdarz.key.code == sf::Keyboard::A) {
						std::cout << "Wciskam A \n";
						pojemnik.push_back(std::unique_ptr<Item>(new Item));
						std::cout << pojemnik.size() << "\n";
					}
				}
			}		
			update();
			draw();
			//std::cout << typeid(pojemnik[0]).name() << "\n";
	}
}

void Engine::update() {
	for (auto& p : pojemnik)
		p->collision();
}

void Engine::draw() {
	okno.clear(sf::Color::Black);
	for (auto& d : pojemnik)
		okno.draw(*d);
	okno.display();
}