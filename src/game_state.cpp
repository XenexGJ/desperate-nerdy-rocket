#include "game_state.h"

GameState::GameState(int x, int y)
{
	// Initial game state
	m_game_state = STATE_MENU;

	// Size of the game area
	m_size_x = x;
	m_size_y = y;
	
	//schwerkraft
	gravity = 10;

	// Set initial player movement and location
	setPlayerMovementDirection(DIRECTION_NONE);
	setPlayerLocation(sf::Vector2f(x/2-ROBOT_WIDTH/2,y/2-ROBOT_HEIGHT/2));

	// Initialize random seed
	srand (static_cast <unsigned> (time(0)));
	rocket = Rocket(upgradeList);
}

int GameState::getGameState()
{
	return m_game_state;
}

void GameState::startPlaying()
{
	m_game_state = STATE_PLAYING;

	// Reset all values
	m_dodgecoins_collected = 0;

	setPlayerMovementDirection(DIRECTION_NONE);
	setPlayerLocation(sf::Vector2f(600, 10)); // Start zentriert auf Bodenhöhe
	//m_screw_locations.clear();
	
	loadUpgrades();
	rocket = Rocket(upgradeList);
	rocket.updateStats();
	m_velocity = rocket.boost;
	// ADD COIN SPAWN
}


void GameState::startShop()
{
	m_game_state = STATE_SHOP;
}

void GameState::buyUpgrade(sf::Vector2i location)
{
	//Upgrade 1
	if (location.x >= 150 && location.x <= 280 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(0)->price && upgradeList.at(0)->price != 0)
		{
			upgradeList.at(0)->price = 0;
		}
	}
	
	//Upgrade 2
	if (location.x >= 300 && location.x <= 430 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(1)->price && upgradeList.at(1)->price != 0)
		{
			upgradeList.at(1)->price = 0;
		}
	}
	
	//Upgrade 3
	if (location.x >= 450 && location.x <= 580 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(2)->price && upgradeList.at(2)->price != 0)
		{
			upgradeList.at(2)->price = 0;
		}
	}
	
	//Upgrade 4
	if (location.x >= 600 && location.x <= 730 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(3)->price && upgradeList.at(3)->price != 0)
		{
			upgradeList.at(3)->price = 0;
		}
	}

	//Upgrade 5
	if (location.x >= 150 && location.x <= 280 && location.y >= 376 && location.y <= 423)
	{
		if (m_dodgecoins_collected >= upgradeList.at(4)->price && upgradeList.at(4)->price != 0)
		{
			upgradeList.at(4)->price = 0;
		}
	}

	//Upgrade 6
	if (location.x >= 300 && location.x <= 430 && location.y >= 376 && location.y <= 423)
	{
		if (m_dodgecoins_collected >= upgradeList.at(5)->price && upgradeList.at(5)->price != 0)
		{
			upgradeList.at(5)->price = 0;
		}
	}

	//Upgrade 7
	if (location.x >= 450 && location.x <= 580 && location.y >= 376 && location.y <= 423)
	{
		if (m_dodgecoins_collected >= upgradeList.at(6)->price && upgradeList.at(6)->price != 0)
		{
			upgradeList.at(6)->price = 0;
		}
	}
	
	//Upgrade 8
	if (location.x >= 600 && location.x <= 730 && location.y >= 376 && location.y <= 423)
	{
		if (m_dodgecoins_collected >= upgradeList.at(7)->price && upgradeList.at(7)->price != 0)
		{
			upgradeList.at(7)->price = 0;
		}
	}
	
	//Upgrade 9
	if (location.x >= 150 && location.x <= 280 && location.y >= 576 && location.y <= 623)
	{
		if (m_dodgecoins_collected >= upgradeList.at(8)->price && upgradeList.at(8)->price != 0)
		{
			upgradeList.at(8)->price = 0;
		}
	}
	
	//Upgrade 10
	if (location.x >= 300 && location.x <= 430 && location.y >= 576 && location.y <= 623)
	{
		if (m_dodgecoins_collected >= upgradeList.at(9)->price && upgradeList.at(9)->price != 0)
		{
			upgradeList.at(9)->price = 0;
		}
	}

	//Upgrade 11
	if (location.x >= 450 && location.x <= 580 && location.y >= 576 && location.y <= 623)
	{
		if (m_dodgecoins_collected >= upgradeList.at(10)->price && upgradeList.at(10)->price != 0)
		{
			upgradeList.at(10)->price = 0;
		}
	}
	
	//Upgrade 12
	if (location.x >= 600 && location.x <= 730 && location.y >= 576 && location.y <= 623)
	{
		if (m_dodgecoins_collected >= upgradeList.at(11)->price && upgradeList.at(11)->price != 0)
		{
			upgradeList.at(11)->price = 0;
		}
	}
	
	//STARTBUTTON 
	if (location.x >= 1000 && location.x <= 1130 && location.y >= 700 && location.y <= 747)
	{
		m_game_state = STATE_PLAYING;
	}
	//MenueBUTTON 
	if (location.x >= 100 && location.x <= 230 && location.y >= 700 && location.y <= 747)
	{
		m_game_state = STATE_MENU;
	}

}

void GameState::updateGameState()
{
	// Do nothing if the game is not in playing state
	if(m_game_state == STATE_MENU)
	{
		return;
	}
	/*else if (m_game_state == STATE_SHOP)
	{
		//TODO: START BUTTON (IM RENDERER BILD ERZEUGEN)
	}//*/
	else if(m_game_state == STATE_PLAYING)
	{
		// Update the player location
		sf::Vector2f delta;

		switch(m_player_direction)
		{
			case DIRECTION_LEFT:
			delta = sf::Vector2f(-5,0);
			break;

			case DIRECTION_RIGHT:
			delta = sf::Vector2f(5,0);
			break;

			default:
			delta = sf::Vector2f(0,0);
			break;
		}
		delta.y -= m_velocity;
		
		m_velocity -= gravity;
		std::cout<< "blub: " << m_velocity << "\n";
		if(m_velocity < -10)
		{
			startShop();
		}
		// Apply delta to the player position
		sf::Vector2f new_location(getPlayerLocation() + delta);

		// Check if new position is inside the game area
		if(new_location.x >= 0
			&& new_location.x + ROBOT_WIDTH <= m_size_x)
		{
			setPlayerLocation(new_location); // Update location
		}

		// Bounding box of the player
		sf::FloatRect player_box(getPlayerLocation(),sf::Vector2f(ROBOT_WIDTH,ROBOT_HEIGHT));

		std::vector<sf::Vector2f>::iterator s_it;
		s_it = m_screw_locations.begin();

		//NACHFOLGEND DURCH COINS ERSETZEN
		// Check for each screw location ...
		while(s_it != m_screw_locations.end())
		{
			// ... if the robot is "eating" the screw
			sf::FloatRect screw_box(*s_it,sf::Vector2f(SCREW_WIDTH,SCREW_HEIGHT));
			if(screw_box.intersects(player_box))
			{
				// Remove screw
				m_screw_locations.erase(s_it);
				m_screws_collected++;
			}
			else
			{
				// Advance iterator to next screw
				s_it++;
			}
		}
	}
	else // Do nothing if the game is not in playing state
		return;
}


//UMBAUEN
void GameState::setPlayerMovementDirection(int direction)
{
	m_player_direction = direction;
}

//CHECKEN 
void GameState::setPlayerLocation(sf::Vector2f location)
{
	m_player_location = location;
	
	rocket.setLocation(location);
}

sf::Vector2f GameState::getPlayerLocation()
{
	return m_player_location;
}

std::vector<sf::Vector2f> GameState::getScrewLocations()
{
	return m_screw_locations;
}

//Ändern auf Coins
int GameState::getCollectedScrewsCount()
{
	return m_screws_collected;
}
std::vector<Upgrade*> *GameState::getUpgradeList()
{	
	return &upgradeList;
}
void GameState::loadUpgrades()
{
	//Upgrade			 			 (int price,int type,float boost,int coolness,float aerodynamic,std::string name,std::string assetPath);
	//teure/bessere Upgrades oben
	upgradeList.push_back(new Upgrade(0,UPGRADE_WINGS,0,10,1,"Waffen","assets/waffen.png"));
	upgradeList.push_back(new Upgrade(0,UPGRADE_BODY,40,10,0,"kawaii2","assets/kawaii_2.png"));
	upgradeList.push_back(new Upgrade(0,UPGRADE_BODY,20,10,0,"kawaii","assets/kawaii.png"));
	upgradeList.push_back(new Upgrade(0,UPGRADE_BODY,10,10,0,"Basis","assets/rocket_basic.png"));
	upgradeList.push_back(new Upgrade(0,UPGRADE_BOOSTER,200,10,0,"Balls","assets/rocket_balls.png"));
}

void GameState::setGameState(int state)
{
	m_game_state = state;
}
