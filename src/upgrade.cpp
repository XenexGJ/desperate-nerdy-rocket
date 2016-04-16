#include "upgrade.h"

Upgrade::Upgrade(int prize,int type,std::string assetPath)
{
	this->prize = prize;
	this->type = type;
	this->assetPath = assetPath;
   
}

void Upgrade::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
	/*sf::Sprite sprite_rocket;
	sprite_rocket.setTexture(texture);
	sprite_rocket.setPosition(m_gst->getPlayerLocation());
	target.draw(sprite_rocket,states);*/
}

void Upgrade::setPosition(sf::Vector2f pos)
{
	position = pos;
}


/*void move()
{

}*/


