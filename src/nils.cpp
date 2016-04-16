#include "nils.h"

Nils::Nils()
{
	if (!texture.loadFromFile("assets/mower.png"))
	{
    	//TODO
	}

	boost = 1;
	coolness = 1;
	grilll0rdlevel = 9001;
}

//zeichne/

void Nils::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
	sf::Sprite sprite_nils;
	sprite_nils.setTexture(texture);
	sprite_nils.setPosition(position);
	target.draw(sprite_nils,states);
}

void Nils::setLocation(sf::Vector2f loc)
{
	position = loc;
}
 
void Nils::updateStats()
{
}

