#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
class Item: public sf::Drawable, sf::Transformable{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::VertexArray line1,line2,line3,line4;
	sf::Vector2f ruch;
	//utworzenie pojemnika na wskazniki, dla obiektow 
	//std::vector<std::unique_ptr<sf::CircleShape>> pojemnik;
	//utworzenie jednego pustego wskaznika;
	//std::unique_ptr<sf::CircleShape>poje;
	sf::CircleShape kula;
	static int ile;
public:
	
	Item();
	~Item();
	void update();
	void collision();
};