#ifndef UPGRADE_H
#define UPGRADE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_state.h"

class Upgrade : public sf::Drawable
{
public:
	Upgrade();
	void setPosition(sf::Vector2f pos);

private:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	sf::Vector2f position;

};

#endif
