#ifndef NILS_H
#define NILS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
//#include "upgrade.h"

class Nils : public sf::Drawable
{
public:
	Nils();
	//Rocket(std::vector<Upgrade*> upgradeList);
	void setLocation(sf::Vector2f loc);
	
	float boost;
	int coolness;
	int grilll0rdlevel;

	//berechnet den boost aus den upgrades
	void updateStats();
	
private:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	
	sf::Vector2f position;
	sf::Texture texture;
	//std::vector<Upgrade*> myUpgradeList;
	
	
/*
	//Upgrades
	Upgrade* rocketbody;
    Upgrade* rocketgoggles;
    Upgrade* rocketwings;
    Upgrade* rocketbooster;
    Upgrade* rockettail;
*/
};

#endif
