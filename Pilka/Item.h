#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
class Item: public sf::Drawable, sf::Transformable{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::CircleShape kolo;
	sf::VertexArray line1,line2,line3,line4;
	void collision();
	sf::Vector2f ruch;
	//utworzenie pojemnika na wskazniki, dla obiektow 
	//std::vector<std::unique_ptr<sf::CircleShape>> pojemnik;
	//utworzenie jednego pustego wskaznika;
	std::unique_ptr<sf::CircleShape>poje;
public:
	Item();
	~Item();
	void update();

	

};