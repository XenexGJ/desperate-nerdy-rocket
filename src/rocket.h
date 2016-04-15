#ifndef ROCKET_H
#define ROCKET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_state.h"

class Rocket : public sf::Drawable
{
public:
	Rocket(GameState *state);
	//void move() = 0;
//	sf::Vector2f getPosition();

private:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	float movementSpeed;
	sf::Vector2f position;
	sf::Texture texture;
	GameState *m_gst;

};

#endif
