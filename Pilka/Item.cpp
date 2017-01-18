#include "Item.h"
#include <iostream>
Item::Item() {
	kolo.setRadius(20.0f);
	kolo.setPointCount(20);
	kolo.setFillColor(sf::Color::Green);
	kolo.setPosition(700.0f,100);

	line1.setPrimitiveType(sf::Lines);
	line1.append(sf::Vertex(sf::Vector2f(1000, 50), sf::Color::Red));
	line1.append(sf::Vertex(sf::Vector2f(1000, 700), sf::Color::Yellow));
}

Item::~Item() {

}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(line1);
	target.draw(kolo);
	
}

void Item::update() {
	collision();
	kolo.move(1, 0);
}

void Item::collision() {
	sf::FloatRect collKolo = kolo.getGlobalBounds();
	sf::FloatRect collLine (1000, 50, 1, 700);
	if (collKolo.intersects(collLine))
		std::cout << "kolizja\n";
}