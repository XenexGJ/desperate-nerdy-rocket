#ifndef ROCKET_H
#define ROCKET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "upgrade.h"

class Rocket : public sf::Drawable
{
public:
	Rocket();
	Rocket(std::vector<Upgrade*> upgradeList);
	//void move() = 0;
//	sf::Vector2f getPosition();
	void setLocation(sf::Vector2f loc);
	
	//berechnet den boost aus den upgrades
	float getBoost();

private:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	float movementSpeed;
	sf::Vector2f position;
	sf::Texture texture;
	std::vector<Upgrade*> myUpgradeList;
	
	

	//Upgrades
	Upgrade* rocketbody;
    Upgrade* rocketgoggles;
    Upgrade* rocketwings;
    Upgrade* rocketbooster;
    Upgrade* rockettail;

};

#endif
