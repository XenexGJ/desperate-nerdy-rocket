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
	void setLocation(sf::Vector2f loc);
	
	float boost;
	float aerodynamic;
	int coolness;
	float movementSpeed;

	//berechnet den boost aus den upgrades
	void updateStats();
	
private:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	
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
