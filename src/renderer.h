#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "game_state.h"
#include "rocket.h"
//für fmod
#include <cmath>


class Renderer
{
public:
	Renderer(sf::RenderWindow *window, GameState *state);
	void drawGame();
	void drawShop();
private:
	sf::RenderWindow *m_wnd;
	GameState *m_gst;
	
	//Main Menue
	sf::Texture m_texture_play;
	sf::Texture m_texture_help;
	sf::Texture m_texture_quit;
	
	
	//Main Game
	sf::Texture m_texture_background;
	sf::Texture m_texture_background2;
	sf::Texture m_texture_player;
	sf::Texture m_texture_dodgecoin;
	sf::Texture m_texture_startBg;
	sf::Texture m_texture_papa;
	//Shop
	sf::Texture m_texture_shopbackground;
	sf::Texture m_texture_graffitti;
	sf::Texture m_texture_buy;
	sf::Texture m_texture_upgrade_bought;
	sf::Texture m_texture_fappsy;
	sf::Texture m_texture_takeoff;
	sf::Texture m_texture_menu;
	sf::Texture m_texture_item_bg;
	
	//Nils game
	sf::Texture m_texture_minibackground;
	sf::Texture m_texture_mower;
	sf::Texture m_texture_jung_und_geld;
	//Credits
	
	//Fonts
	sf::Font m_normal_font;
	sf::Font m_bold_font;
	sf::Font m_funk;
	
	std::vector<Upgrade*> upgrades;
};

#endif
