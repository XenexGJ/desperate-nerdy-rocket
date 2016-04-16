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
    	switch ((*it)->type)
    	{
    		case UPGRADE_BODY:
    			rocketbooster = &**it;
    			std::cout << "it\n";
    		break;
    		case UPGRADE_GOGGLES:
    			rocketbooster = &**it;
    			std::cout << "it\n";
    		break;
    		case UPGRADE_WINGS:
    			rocketbooster = &**it;
    			std::cout << "it\n";
    		break;
    		case UPGRADE_BOOSTER:
    			rocketbooster = &**it;
    			std::cout << "it\n";
    		break;
    		case UPGRADE_TAIL:
    			rocketbooster = &**it;
    			std::cout << "it\n";
    		break;
    	}
	}
}

//zeichne
void Rocket::draw(sf::RenderTarget& target,sf::RenderStates states)const
{
	sf::Sprite sprite_rocket;
	sprite_rocket.setTexture(texture);
	sprite_rocket.setPosition(position);
	target.draw(sprite_rocket,states);
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
 

