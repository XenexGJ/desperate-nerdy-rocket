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
	sf::Texture m_texture_background;
	sf::Texture m_texture_player;
	sf::Texture m_texture_dodgecoin;
	sf::Texture m_texture_shopbackground;
	sf::Texture m_texture_minibackground;
	sf::Texture m_texture_slot1;
	sf::Texture m_texture_upgrade_bought;
	sf::Texture m_texture_fappsy;
	sf::Texture m_texture_mower;
	sf::Texture m_texture_jung_und_geld;
	sf::Texture m_texture_start;
	sf::Texture m_texture_menu;
	sf::Font m_normal_font;
	sf::Font m_bold_font;
	sf::Font m_funk;
	//Rocket rocket;
	
	std::vector<Upgrade*> upgrades;
};

#endif
