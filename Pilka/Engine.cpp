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
	for (int x = 0; x < 300; x++) {
		pojemnik.push_back(std::unique_ptr<Item>(new Item));
	}
	
	std::cout << pojemnik.size()<< "\n";
}
Engine::~Engine(){
	std::cout << "Engine stop...\n";
	//pojemnik.erase(pojemnik.begin()+3);
	std::cout << pojemnik.size() << "\n";
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				std::cout << pojemnik.size() << "\n";
				pojemnik.clear();
			}
		}
		
			
		update();
		okno.clear(sf::Color::Black);
		if (pojemnik.size() > 0) {
			for (int x = 0; x<300; x++)
				okno.draw(*pojemnik[x]);
		}
		
		//std::cout << typeid(pojemnik[0]).name() << "\n";
		okno.display();
		//draw();
	}

}

void Engine::update() {
	for (int x = 0; x < 300; x++)
		pojemnik[x]->collision();
}

void Engine::draw() {
	okno.clear(sf::Color::Black);
	//for (int x=0;x<30;x++)
	//	okno.draw(*pojemnik[x]);
	okno.display();
}