#include "upgrade.h"

Upgrade::Upgrade(int prize,int type,std::string assetPath)
{
	this->prize = prize;
	this->type = type;
	this->assetPath = assetPath;
   	if (!texture.loadFromFile(assetPath))
	{
    	//TODO
    }
}

void Upgrade::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
	sf::Sprite sprite_upgrade;
	sprite_upgrade.setTexture(texture);
	sprite_upgrade.setPosition(position);
	target.draw(sprite_upgrade,states);
}

void Upgrade::setPosition(sf::Vector2f pos)
{
	position = pos;
}


/*void move()
{

}*/


