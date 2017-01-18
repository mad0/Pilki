#pragma once
#include <SFML\Graphics.hpp>
class Item: public sf::Drawable, sf::Transformable{
private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::CircleShape kolo;
	sf::VertexArray line1;
	void collision();
public:
	Item();
	~Item();
	void update();

};