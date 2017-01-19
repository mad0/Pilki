#include "Item.h"
#include <iostream>
Item::Item() {
	ruch = sf::Vector2f(3, 3);
	for (int x=0;x<30;x++)
		pojemnik.push_back(std::make_unique<sf::CircleShape>());
	//pojemnik.push_back(std::unique_ptr<sf::CircleShape>(new sf::CircleShape()));
	//utowrzenie wskaznika do obiektu o nazwie poje2
	//std::unique_ptr<sf::CircleShape>poje2(new sf::CircleShape);
	//inicjalizacja wczesniej utworzonego wskaznika
	//poje = std::unique_ptr<sf::CircleShape>(new sf::CircleShape);
	std::cout << "Ilosc obiektow w kontenerze: " << pojemnik.size() << "\n";
	pojemnik[0]->setRadius(20.0f);
	pojemnik[0]->setPointCount(20);
	pojemnik[0]->setFillColor(sf::Color::Green);
	pojemnik[0]->setPosition(540.0f,231);
	pojemnik[1]->setRadius(20.0f);
	pojemnik[1]->setPointCount(20);
	pojemnik[1]->setFillColor(sf::Color::Green);
	pojemnik[1]->setPosition(600.0f, 400);
	
	/*poje->setRadius(20.0f);
	poje->setPointCount(20);
	poje->setFillColor(sf::Color::Green);
	poje->setPosition(540.0f, 231);
	*/

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
	//pojemnik.erase(pojemnik.end() - 1);
	//pojemnik.clear();
	//std::cout << "Ilosc obiektow w kontenerze: " << pojemnik.size() << "\n";
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(line1);
	target.draw(line2);
	target.draw(line3);
	target.draw(line4);
	target.draw(*pojemnik[0]);
	target.draw(*pojemnik[1]);

}

void Item::update() {
	collision();
}

void Item::collision() {
	if ((pojemnik[0]->getPosition().x > 960) || (pojemnik[0]->getPosition().x<50))
		ruch.x *= -1;
	if ((pojemnik[0]->getPosition().y > 660) || (pojemnik[0]->getPosition().y<50))
		ruch.y *= -1;
	if((pojemnik[1]->getPosition().x > 960) || (pojemnik[1]->getPosition().x<50))
		ruch.x *= -1;
	if ((pojemnik[1]->getPosition().y > 660) || (pojemnik[1]->getPosition().y<50))
		ruch.y *= -1;
	pojemnik[1]->move(ruch.x, ruch.y);
}