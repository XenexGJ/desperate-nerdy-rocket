#include "rocket.h"

Rocket::Rocket(){}

Rocket::Rocket(std::vector<Upgrade*> upgradeList)
{
	if (!texture.loadFromFile("assets/rocket_basic.png"))
	{
    	//TODO
    }
    
   	rocketbody = NULL;
    rocketgoggles  = NULL;
    rocketwings  = NULL;
    rocketbooster  = NULL;
    rockettail  = NULL;
    
    //std::cout << "ittt\n";
    
    
    
    for(std::vector<Upgrade*>::iterator it = upgradeList.begin(); it != upgradeList.end(); ++it) 
	{
		std::cout<<"blub\n";
		if((*it)->price == 0)
		{
			std::cout<<"blub";
			switch ((*it)->type)
			{
				case UPGRADE_BODY:
					if(rocketbody == NULL)
					{
						rocketbody = &**it;
						std::cout << "it\n";
					}
				break;
				case UPGRADE_GOGGLES:
					if(rocketgoggles == NULL)
					{
						rocketgoggles = &**it;
						std::cout << "it\n";
					}
				break;
				case UPGRADE_WINGS:
					if(rocketwings == NULL)
					{
						rocketwings = &**it;
						std::cout << "it\n";
					}
				break;
				case UPGRADE_BOOSTER:
					if(rocketbooster == NULL)
					{
						rocketbooster = &**it;
						std::cout << "it\n";
					}
				break;
				case UPGRADE_TAIL:
					if(rockettail == NULL)
					{
						rockettail = &**it;
						std::cout << "it\n";
					}
				break;
			}
		}
	}
}

//zeichne
void Rocket::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
/*	sf::Sprite sprite_rocket;
	sprite_rocket.setTexture(texture);
	sprite_rocket.setPosition(position);
	target.draw(sprite_rocket,states);*/
	if(rocketbody != NULL)
	{
		rocketbody->setPosition(position);
		target.draw(*rocketbody,states);
	}
	if(rocketgoggles != NULL)
	{
		rocketgoggles->setPosition(position);
		target.draw(*rocketgoggles,states);
	}
	if(rocketwings != NULL)
	{
		rocketwings->setPosition(position);
		target.draw(*rocketwings,states);
	}
	if(rocketbooster != NULL)
	{
		rocketbooster->setPosition(position);
		target.draw(*rocketbooster,states);
	}
	if(rockettail != NULL)
	{
		rockettail->setPosition(position);
		target.draw(*rockettail,states);
	}
}

void Rocket::setLocation(sf::Vector2f loc)
{
	position = loc;
}
 
float Rocket::getBoost()
{
	float boost = 0.0f;
	if(rocketbody)
		boost += rocketbody->boost;
	if(rocketgoggles)
		boost += rocketgoggles->boost;
	if(rocketwings)
		boost += rocketwings->boost;
	if(rocketbooster)
		boost += rocketbooster->boost;
	if(rockettail)
		boost += rockettail->boost;

	return boost;
}
float Rocket::getCoolness()
{
	float coolness = 0.0f;
	if(rocketbody)
		coolness += rocketbody->coolness;
	if(rocketgoggles)
		coolness += rocketgoggles->coolness;
	if(rocketwings)
		coolness += rocketwings->coolness;
	if(rocketbooster)
		coolness += rocketbooster->coolness;
	if(rockettail)
		coolness += rockettail->coolness;

	return coolness;
}
float Rocket::getAerodynamic()
{
	float aerodynamic = 0.0f;
	if(rocketbody)
		aerodynamic += rocketbody->aerodynamic;
	if(rocketgoggles)
		aerodynamic += rocketgoggles->aerodynamic;
	if(rocketwings)
		aerodynamic += rocketwings->aerodynamic;
	if(rocketbooster)
		aerodynamic += rocketbooster->aerodynamic;
	if(rockettail)
		aerodynamic += rockettail->aerodynamic;

	return aerodynamic;
}
