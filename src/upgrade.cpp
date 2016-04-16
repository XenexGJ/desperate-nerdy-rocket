#include "upgrade.h"

Upgrade::Upgrade(int price,int type,float boost,int coolness,float aerodynamic,std::string name,std::string assetPath)
{
	this->price = price;
	this->type = type;
	this->assetPath = assetPath;
	this->boost = boost;
	this->coolness = coolness; 
	this->aerodynamic = aerodynamic;
	this->name = name;
	
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



