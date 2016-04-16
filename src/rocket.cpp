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
    		case UPGRADE_BOOSTER:
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
	if(rocketbooster != NULL)
	{
		target.draw(*rocketbooster,states);
	}
}

void Rocket::setLocation(sf::Vector2f loc)
{
	position = loc;
}
 

