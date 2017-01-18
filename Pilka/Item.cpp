#include "Item.h"
#include <iostream>
Item::Item() {
	ruch = sf::Vector2f(3, 3);
	kolo.setRadius(20.0f);
	kolo.setPointCount(20);
	kolo.setFillColor(sf::Color::Green);
	kolo.setPosition(700.0f,100);

	line1.setPrimitiveType(sf::Lines);
	line1.append(sf::Vertex(sf::Vector2f(1000, 50), sf::Color::Red));
	line1.append(sf::Vertex(sf::Vector2f(1000, 700), sf::Color::Yellow));
	line2.setPrimitiveType(sf::Lines);
	line2.append(sf::Vertex(sf::Vector2f(50, 50), sf::Color::Red));
	line2.append(sf::Vertex(sf::Vector2f(50, 700), sf::Color::Yellow));
	line3.setPrimitiveType(sf::Lines);
	line3.append(sf::Vertex(sf::Vector2f(50, 50), sf::Color::Red));
	line3.append(sf::Vertex(sf::Vector2f(1000, 50), sf::Color::Yellow));
	line4.setPrimitiveType(sf::Lines);
	line4.append(sf::Vertex(sf::Vector2f(50, 700), sf::Color::Red));
	line4.append(sf::Vertex(sf::Vector2f(1000, 700), sf::Color::Yellow));
}

Item::~Item() {

}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(line1);
	target.draw(line2);
	target.draw(line3);
	target.draw(line4);
	target.draw(kolo);

}

void Item::update() {
	collision();
}

void Item::collision() {
	sf::Vector2f poz = kolo.getPosition();
	if ((kolo.getPosition().x > 960) || (kolo.getPosition().x<50))
		ruch.x *= -1;
	if ((kolo.getPosition().y > 660) || (kolo.getPosition().y<50))
		ruch.y *= -1;

	kolo.move(ruch.x, ruch.y);
}