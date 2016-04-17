#include "game_state.h"

GameState::GameState(int x, int y)
{
	// Initial game state
	m_game_state = STATE_MENU;

	// Size of the game area
	m_size_x = x;
	m_size_y = y;
	
	//schwerkraft
	gravity = 0.01;
	
	total_dodgecoins = 0;
	m_dodgecoins_collected = 0;

	// Set initial player movement and location
	setPlayerMovementDirection(DIRECTION_NONE);
	setPlayerLocation(sf::Vector2f(x/2-ROBOT_WIDTH/2,y/2-ROBOT_HEIGHT/2));
	
	// Initialize random seed
	srand (static_cast <unsigned> (time(0)));
	rocket = Rocket(upgradeList);
	m_dodgecoin_locations.clear();
	
	loadUpgrades();
}

int GameState::getGameState()
{
	return m_game_state;
}

void GameState::startPlaying()
{
	//m_game_state = STATE_PLAYING;

	// Reset all values
	m_dodgecoins_collected = 0;
	m_dodgecoin_locations.clear();

	setPlayerMovementDirection(DIRECTION_NONE);
	
	rocket = Rocket(upgradeList);
	rocket.updateStats();
	
	setPlayerLocation(sf::Vector2f(640, 700)); // Start zentriert auf Bodenhöhe
	
	m_velocity = rocket.boost;

	// Initialize random seed
	srand (static_cast <unsigned> (time(0)));

	
}


void GameState::startShop()
{
	m_game_state = STATE_SHOP;
	//loadUpgrades();
}

void GameState::shopMouseHandling(sf::Vector2i location)
{
	//Upgrade 1
	if (location.x >= 150 && location.x <= 280 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(0)->price && upgradeList.at(0)->price != 0)
		{
			upgradeList.at(0)->price = 0;
			std::cout << "gekauft\n";
		}
	}
	
	//Upgrade 2
	if (location.x >= 300 && location.x <= 430 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(1)->price && upgradeList.at(1)->price != 0)
		{
			upgradeList.at(1)->price = 0;
			std::cout << "gekauft\n";
		}
	}
	
	//Upgrade 3
	if (location.x >= 450 && location.x <= 580 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(2)->price && upgradeList.at(2)->price != 0)
		{
			upgradeList.at(2)->price = 0;
			std::cout << "gekauft\n";
		}
		else 
			std::cout << "zu teuer\n";
	}
	
	//Upgrade 4
	if (location.x >= 600 && location.x <= 730 && location.y >= 176 && location.y <= 223)
	{
		if (m_dodgecoins_collected >= upgradeList.at(3)->price && upgradeList.at(3)->price != 0)
		{
			upgradeList.at(3)->price = 0;
			std::cout << "gekauft\n";
		}
		else 
			std::cout << "zu teuer\n";
	}

	//Upgrade 5
	if (location.x >= 150 && location.x <= 280 && location.y >= 376 && location.y <= 423)
	{
		if (m_dodgecoins_collected >= upgradeList.at(4)->price && upgradeList.at(4)->price != 0)
		{
			upgradeList.at(4)->price = 0;
			std::cout << "gekauft\n";
		}
		else 
			std::cout << "zu teuer\n";
	}

	//Upgrade 6
	if (location.x >= 300 && location.x <= 430 && location.y >= 376 && location.y <= 423)
	{
		if (m_dodgecoins_collected >= upgradeList.at(5)->price && upgradeList.at(5)->price != 0)
		{
			upgradeList.at(5)->price = 0;
			std::cout << "gekauft\n";
		}
		else 
			std::cout << "zu teuer\n";
	}

	//Upgrade 7
	if (location.x >= 450 && location.x <= 580 && location.y >= 376 && location.y <= 423)
	{
		if (m_dodgecoins_collected >= upgradeList.at(6)->price && upgradeList.at(6)->price != 0)
		{
			upgradeList.at(6)->price = 0;
			std::cout << "gekauft\n";
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
	
	//Stats Updaten
	rocket.updateStats();

}

void GameState::menuMouseHandling(sf::Vector2i location)
{
	std::cout<<location.x << "  " << location.y << "\n";
	if (location.x >= 100 && location.x <= 238 && location.y >= 200 && location.y <= 256)
	{	
		startShop();
	}
	if (location.x >= 100 && location.x <= 238 && location.y >= 400 && location.y <= 456)
	{	
		m_game_state = STATE_CONTROLS;
	}
	if (location.x >= 100 && location.x <= 238 && location.y >= 600 && location.y <= 656)
	{	
		//m_wnd->close();;
		std::cout << "MACH MICH ZU DU SAU!!!!" << std::endl;
	}//*/

}

//start Minigame
void GameState::startMini()
{
	m_game_state = STATE_MINI;
	setTotalDodgecoins(total_dodgecoins + m_dodgecoins_collected);
	m_dodgecoins_collected = 0;
	//m_dodgecoin_locations.clear();

	//std::cout << "start mini" <<std::endl;
	setPlayerMovementDirection (DIRECTION_NONE);
	setPlayerLocation(sf::Vector2f (50,700));
	
	//ADD COIN
		for (int i=0; i<10; i++)
		{
			sf::Vector2f newcoin;
			m_dodgecoin_locations.push_back(sf::Vector2f(rand()%1280,getPlayerLocation().y));
		}
	
}

void GameState::updateGameState()
{
	// Do nothing if the game is not in playing state
	if(m_game_state == STATE_MENU)
	{
		SoundHandler* s = SoundHandler::getSoundHandler();
		s->setBgVolume(0);
		s->playSound(SOUND_INTRO);
	}
	else if (m_game_state == STATE_SHOP)
	{
		//TODO: START BUTTON (IM RENDERER BILD ERZEUGEN)
	}
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
//		std::cout<< "blub: " << m_velocity << "\n";
		
		// Apply delta to the player position
		sf::Vector2f new_location(getPlayerLocation() + delta);

		// Check if new position is inside the game area
		if(new_location.x < 0)
		{
			new_location.x = 0;
		}
		else if(new_location.x + ROBOT_WIDTH >= m_size_x)
		{
			new_location.x = m_size_x - ROBOT_WIDTH;
		}
		setPlayerLocation(new_location); // Update location
		
		if(new_location.y < 0 && m_velocity < 0)
		{
			setTotalDodgecoins(total_dodgecoins + m_dodgecoins_collected);
			m_dodgecoins_collected =0;
			std::cout << "totalcoins: " << total_dodgecoins <<std::endl;
			startShop();
			
		}
		// Bounding box of the player
		sf::FloatRect player_box(getPlayerLocation(),sf::Vector2f(ROBOT_WIDTH,ROBOT_HEIGHT));
		
		//ADD COIN
		addDodgecoin();
		
		std::vector<sf::Vector2f>::iterator s_it;
		s_it = m_dodgecoin_locations.begin();

		
		// Check for each coin location ...
		while(s_it != m_dodgecoin_locations.end())
		{
			// ... if the rocket is collecting the coin
			sf::FloatRect dodgecoin_box(*s_it,sf::Vector2f(COIN_WIDTH,COIN_HEIGHT));
			if(dodgecoin_box.intersects(player_box))
			{
				// Remove coin
				m_dodgecoin_locations.erase(s_it);
				m_dodgecoins_collected++;
				
			}
			else
			{
				// Advance iterator to next coin
				s_it++;
			}
		}
	}
	else if(m_game_state == STATE_MINI)
	{
		// Update the player location
		sf::Vector2f delta;
		
		
		switch(m_player_direction)
		{
			case DIRECTION_LEFT:
			delta = sf::Vector2f(-5,0);
			break;
			//std::cout << "leftmini" <<std::endl;
			
			case DIRECTION_RIGHT:
			delta = sf::Vector2f(5,0);
			break;
			//std::cout << "rightmini" <<std::endl;

			case DIRECTION_UP:
			delta = sf::Vector2f(0,0);
			break;

			case DIRECTION_DOWN:
			delta = sf::Vector2f(0,0);
			break;

			default:
			delta = sf::Vector2f(0,0);
			break;
		}
		
		// Apply delta to the player position
		sf::Vector2f new_location(getPlayerLocation() + delta);

		// Check if new position is inside the game area
		if(new_location.x >= 0 && new_location.x + ROBOT_WIDTH <= m_size_x)
		{
			setPlayerLocation(new_location); // Update location
			//std::cout << "neue position??" << std::endl;
		}
		if(new_location.x >=1200)
		{
			setTotalDodgecoins(total_dodgecoins + m_dodgecoins_collected);
			m_dodgecoins_collected =0;
			startShop();
		}	
		
		// Bounding box of the player
		sf::FloatRect player_box(getPlayerLocation(),sf::Vector2f(ROBOT_WIDTH,ROBOT_HEIGHT));
		
		std::vector<sf::Vector2f>::iterator s_it;
		s_it = m_dodgecoin_locations.begin();

		
		// Check for each coin location ...
		while(s_it != m_dodgecoin_locations.end())
		{
			// ... if the nils is collecting the coin
			sf::FloatRect dodgecoin_box(*s_it,sf::Vector2f(COIN_WIDTH,COIN_HEIGHT));
			if(dodgecoin_box.intersects(player_box))
			{
				// Remove coin
				m_dodgecoin_locations.erase(s_it);
				m_dodgecoins_collected++;
				//std::cout << "coooooooooooooiiiiin" << std::endl;
				//setTotalDodgecoins(total_dodgecoins + m_dodgecoins_collected);
				std::cout << "totalcoins: " << total_dodgecoins <<std::endl;
				std::cout << "collectedcoins: " << m_dodgecoins_collected <<std::endl;
				
			}
			else
			{
				// Advance iterator to next coin
				s_it++;
			}
	}
	}		
	else // Do nothing if the game is not in mini state
	{		
		return;
	}
	
}



//UMBAUEN
void GameState::setPlayerMovementDirection(int direction)
{
	m_player_direction = direction;
}

//CHECKEN 
// ggf. sauber das rocket.setlocation verschieben
void GameState::setPlayerLocation(sf::Vector2f location)
{
	m_player_location = location;
	
	rocket.setLocation(location);
}

sf::Vector2f GameState::getPlayerLocation()
{
	return m_player_location;
}

std::vector<sf::Vector2f> GameState::getDodgecoinLocations()
{
	return m_dodgecoin_locations;
}

//Ändern auf Coins
int GameState::getCollectedDodgecoinCount()
{
	return m_dodgecoins_collected;
}
float GameState::getVelocity()
{
	return m_velocity;
}

void GameState::addDodgecoin()
{
	sf::Vector2f newcoin;
	int random = rand()%100;
	if (random <= 10)
	{
		m_dodgecoin_locations.push_back(sf::Vector2f(rand()%1280,getPlayerLocation().y-1000));
	}
}

int GameState::getTotalDodgecoins()
{
	return total_dodgecoins;
}

void GameState::setTotalDodgecoins(int totalCount)
{
	total_dodgecoins = totalCount;
	//total_dodgecoins += totalCount;
	//total_dodgecoins = total_dodgecoins + totalCount ;
}

std::vector<Upgrade*> *GameState::getUpgradeList()
{	
	return &upgradeList;
}
void GameState::loadUpgrades()
{
	//EXPERIMENTELLES BALANCING! KOMMENTARE STEHEN LASSEN!!!!
	
	//Upgrade			 			 (int price,int type,float boost,int coolness,float aerodynamic,std::string name,std::string assetPath);
	//teure/bessere Upgrades oben
	//Bodies - Bietet Boost, Aerodynamic
	upgradeList.push_back(new Upgrade(500,UPGRADE_BODY,75,0,50,"COLA","assets/cola_anne.png"));
	upgradeList.push_back(new Upgrade(100,UPGRADE_BODY,50,0,25,"kawaii2","assets/kawaii_2.png"));
	upgradeList.push_back(new Upgrade(25,UPGRADE_BODY,25,0,10,"kawaii","assets/kawaii.png"));
	upgradeList.push_back(new Upgrade(0,UPGRADE_BODY,10,0,0,"Basis","assets/rocket_basic.png")); //Start
	
	//GOGGLES - Bietet Coolness
	//Sonnenbrille (500,UPGRADE_GOGGLES,0,8500,0,"Sonnenbrille",texturepath) -- Siegbedingung
	//BRILLE2 (100,UPGRADE_GOGGLES,0,50,0,"BRILLE2",texturepath)
	//Hornbrille (25,UPGRADE_GOGGLES,0,25,0,"Hornbrille",texturepath)
	
	//WINGS - Bietet Aerodynamic, Coolness
	//WINGEXTRA2 (500,UPGRADE_WINGS,0,501,50,"WINGEXTRA2",texturepath)
	//WINGEXTRA	(100,UPGRADE_WINGS,0,25,25,"WINGEXTRA",texturepath)
	//upgradeList.push_back(new Upgrade(25,UPGRADE_WINGS,0,10,10,"Waffen","assets/waffen.png"));
	upgradeList.push_back(new Upgrade(1,UPGRADE_WINGS,0,10,10,"Waffen","assets/waffen.png"));
	
	//BOOSTER Bietet Boost
	//TOPBOOSTER (500,UPGRADE_BOOSTER,25,0,0,"TOPBOOSTER",texturepath);
	//BOOSTER(100,UPGRADE_BOOSTER,15,0,0,"BOOSTER",texturepath);
	upgradeList.push_back(new Upgrade(25,UPGRADE_BOOSTER,5,0,0,"Balls","assets/rocket_balls.png"));
}

void GameState::setGameState(int state)
{
	m_game_state = state;
}

