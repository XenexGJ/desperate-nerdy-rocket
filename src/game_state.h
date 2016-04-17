#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "upgrade.h"
#include "rocket.h"
#include "nils.h"
#include "sound_handler.h"

#define STATE_MENU 0
#define STATE_PLAYING 1
#define STATE_SHOP 2
#define STATE_MINI 3
#define STATE_CREDITS 4
#define STATE_PAUSE 5
#define STATE_CONTROLS 6
#define STATE_READY_TO_LAUNCH 7

#define DIRECTION_NONE 0
#define DIRECTION_LEFT 1
#define DIRECTION_RIGHT 2
#define DIRECTION_UP 3
#define DIRECTION_DOWN 4

#define ROBOT_WIDTH 80
#define ROBOT_HEIGHT 80
#define COIN_WIDTH 96
#define COIN_HEIGHT 56

#define COIN_SPAWN_THRESHOLD 30

class GameState
{
public:
	GameState(int x, int y);
	int getGameState();
	void startPlaying();
	void startShop();
	void shopMouseHandling(sf::Vector2i location);
	void menuMouseHandling(sf::Vector2i location);
	void updateGameState();
	void setPlayerMovementDirection(int direction);
	void setPlayerLocation(sf::Vector2f location);
	void setGameState(int state);

	void startMini();
	void updateMini();
	
	sf::Vector2f getPlayerLocation();
	float getVelocity();

	std::vector<sf::Vector2f> getDodgecoinLocations();
	int getCollectedDodgecoinCount();
	void addDodgecoin();
	int getTotalDodgecoins();
	void setTotalDodgecoins(int totalCount);
	
	std::vector<Upgrade*> *getUpgradeList();
	Rocket rocket;
	Nils nils;
private:
	int m_game_state;
	int m_size_x;
	int m_size_y;
	int total_dodgecoins;
	int m_player_direction;
	int m_dodgecoins_collected;

	float gravity;
	float m_velocity;

	sf::Vector2f m_player_location;
	std::vector<sf::Vector2f> m_dodgecoin_locations;
	float m_new_screw_threshold;
	
	std::vector<Upgrade*> upgradeList;
	void loadUpgrades();
	bool upgradesLoaded;
	SoundHandler* s;
		
};

#endif
