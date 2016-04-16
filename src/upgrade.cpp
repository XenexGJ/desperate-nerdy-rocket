#include "upgrade.h"

Upgrade::Upgrade(int price,int type,std::string assetPath)
{
	this->price = price;
	this->type = type;
	this->assetPath = assetPath;
	this->boost = price; //TODO
	this->coolness = price; //TODO
	this->aerodynamic = price; //TODO
	
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


