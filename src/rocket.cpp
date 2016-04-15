#include "rocket.h"

Rocket::Rocket(GameState *state)
{
	if (!texture.loadFromFile("assets/rocket_basic.png"))
	{
    	//TODO
    }
    m_gst = state;
}

void Rocket::draw(sf::RenderTarget& target,sf::RenderStates states)const
{

	
	sf::Sprite sprite_rocket;
	sprite_rocket.setTexture(texture);
	sprite_rocket.setPosition(m_gst->getPlayerLocation());
	target.draw(sprite_rocket,states);
}
 

/*void move()
{

}*/


