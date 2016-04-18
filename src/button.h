#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

//define upgradetypes
#define UPGRADE_BODY 1
#define UPGRADE_GOGGLES 2
#define UPGRADE_WINGS 3
#define UPGRADE_BOOSTER 4
#define UPGRADE_TAIL 5
#define UPGRADE_DUMMY 0

class Button : public sf::Drawable
{
public:
	Button();
	Button(sf::Vector2f position,sf::Vector2f bounds,std::string text,std::string assetPath);
	//void setPosition(sf::Vector2f pos);
	//sf::Vector2f position;
	std::string text;
	bool checkClick(sf::Vector2i click);
	
private:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	sf::Vector2f position;
	sf::Vector2f bounds;
	
	sf::Texture texture;

	//std::string assetPath;
	//std::string text;

};

#endif
