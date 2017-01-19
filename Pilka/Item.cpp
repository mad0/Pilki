#include "Item.h"
#include <iostream>
int Item::ile = 0;
Item::Item() {
	ile++;
	std::cout << ile << "\n";
	pozx = (rand() % 984) + 40;
	pozy = (rand() % 728) + 40;
	ruch = sf::Vector2f(3, 3);
	//pojemnik.push_back(std::make_unique<sf::CircleShape>());
	//pojemnik.push_back(std::unique_ptr<sf::CircleShape>(new sf::CircleShape()));
	//utowrzenie wskaznika do obiektu o nazwie poje2
	//std::unique_ptr<sf::CircleShape>poje2(new sf::CircleShape);
	//inicjalizacja wczesniej utworzonego wskaznika
	//kula = std::unique_ptr<sf::CircleShape>(new sf::CircleShape);
	kula.setRadius(20.0f);
	kula.setPointCount(20);
	kula.setFillColor(sf::Color::Green);
	kula.setPosition(540.0f,231);
	kula.setRadius(20.0f);
	kula.setPointCount(20);
	kula.setFillColor(sf::Color::Green);
	kula.setPosition(pozx,pozy);
	
	/*poje->setRadius(20.0f);
	poje->setPointCount(20);
	poje->setFillColor(sf::Color::Green);
	poje->setPosition(540.0f, 231);
	*/

	/*line1.setPrimitiveType(sf::Lines);
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
	*/
}

Item::~Item() {
	//pojemnik.erase(pojemnik.end() - 1);
	//pojemnik.clear();
	//std::cout << "Ilosc obiektow w kontenerze: " << pojemnik.size() << "\n";
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	/*target.draw(line1);
	target.draw(line2);
	target.draw(line3);
	target.draw(line4);
	*/
	target.draw(kula,states);
}

void Item::update() {
}

void Item::collision() {
		if ((kula.getPosition().x > 960) || (kula.getPosition().x<50))
			ruch.x *= -1;
		if ((kula.getPosition().y > 660) || (kula.getPosition().y<50))
			ruch.y *= -1;
		kula.move(ruch.x, ruch.y);
}
