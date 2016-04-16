#ifndef UPGRADE_H
#define UPGRADE_H

#include <SFML/Graphics.hpp>
#include <iostream>

//define upgradetypes
#define UPGRADE_BODY 1
#define UPGRADE_GOGGLES 2
#define UPGRADE_WINGS 3
#define UPGRADE_BOOSTER 4
#define UPGRADE_TAIL 5

class Upgrade : public sf::Drawable
{
public:
	Upgrade(int price,int type,std::string assetPath);
	void setPosition(sf::Vector2f pos);
	int type;
	int price;
	float boost;
	int coolness;
	int aerodynamic;

private:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	sf::Vector2f position;
	
	//if prize == 0 -> bought
	
	std::string assetPath;
	sf::Texture texture;
};

#endif
