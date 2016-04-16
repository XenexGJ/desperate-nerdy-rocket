#include "upgrade.h"

Upgrade::Upgrade(int prize,int type,std::string assetPath)
{
	this->prize = prize;
	this->type = type;
	this->assetPath = assetPath;
   
}

void Upgrade::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
	//if (!texture.loadFromFile(assetPath)
	{
    	//TODO
    }
    std::cout << "blub";
}

void Upgrade::setPosition(sf::Vector2f pos)
{
	position = pos;
}


/*void move()
{

}*/


