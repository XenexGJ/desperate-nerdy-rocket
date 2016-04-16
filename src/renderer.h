#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "game_state.h"
#include "rocket.h"

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
	sf::Texture m_texture_screws;
	sf::Texture m_texture_shopbackground;
	sf::Texture m_texture_slot1;
	sf::Texture m_texture_upgrade_bought;
	sf::Texture m_texture_fappsy;
	sf::Font m_normal_font;
	sf::Font m_bold_font;
	sf::Font m_funk;
	Rocket rocket;
};

#endif
