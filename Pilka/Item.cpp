#include "Item.h"
#include <iostream>
Item::Item() {
	ruch = sf::Vector2f(3, 3);

	pojemnik.emplace_back(std::make_unique<sf::CircleShape>());
	std::cout<<"Ilosc obiektow w kontenerze: "<<pojemnik.size()<<"\n";
	pojemnik[0]->setRadius(20.0f);
	pojemnik[0]->setPointCount(20);
	pojemnik[0]->setFillColor(sf::Color::Green);
	pojemnik[0]->setPosition(540.0f,231);

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
	//pojemnik.clear();
	std::cout << "Ilosc obiektow w kontenerze: " << pojemnik.size() << "\n";
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(line1);
	target.draw(line2);
	target.draw(line3);
	target.draw(line4);
	target.draw(*pojemnik[0]);

}

void Item::update() {
	collision();
}

void Item::collision() {
	if ((pojemnik[0]->getPosition().x > 960) || (pojemnik[0]->getPosition().x<50))
		ruch.x *= -1;
	if ((pojemnik[0]->getPosition().y > 660) || (pojemnik[0]->getPosition().y<50))
		ruch.y *= -1;
	pojemnik[0]->move(ruch.x, ruch.y);
}