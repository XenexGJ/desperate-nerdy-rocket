#include "renderer.h"

Renderer::Renderer(sf::RenderWindow *window, GameState *state)
{
	m_wnd = window;
	m_gst = state;

	// Load all the textures
	if (!m_texture_background.loadFromFile("assets/redplanet2.png"))
	{
    	m_wnd->close();
    }
    m_texture_background.setRepeated(true);

    if (!m_texture_player.loadFromFile("assets/rocket_basic.png"))
	{
    	m_wnd->close();
    }

    if (!m_texture_screws.loadFromFile("assets/screws.png"))
	{
    	m_wnd->close();
    }
	
	if (!m_texture_shopbackground.loadFromFile("assets/bg1.jpg"))
	{
    	m_wnd->close();
    }
	
    if (!m_texture_slot1.loadFromFile("assets/Kaufen.png"))
	{
    	m_wnd->close();
    }

    if (!m_texture_upgrade_bought.loadFromFile("assets/NV.png"))
	{
    	m_wnd->close();
    }

    // Load all the fonts
    if (!m_normal_font.loadFromFile("assets/Roboto-Regular.ttf"))
    {
    	m_wnd->close();
    }

    if (!m_bold_font.loadFromFile("assets/Roboto-Bold.ttf"))
    {
    	m_wnd->close();
    }
}

void Renderer::drawGame()
{
	m_wnd->clear();

    sf::Sprite sprite_background;
	sprite_background.setTexture(m_texture_background);
	sprite_background.setTextureRect(sf::IntRect(0,0,m_wnd->getSize().x,m_wnd->getSize().y));
	m_wnd->draw(sprite_background);

/*    sf::Sprite sprite_player;
	sprite_player.setTexture(m_texture_player);
	sprite_player.setPosition(m_gst->getPlayerLocation());
	m_wnd->draw(sprite_player); */

	
	m_wnd->draw(m_gst->rocket);	
	
	// Coins einfügen
    sf::Sprite sprite_screws;
	sprite_screws.setTexture(m_texture_screws);
	//Coin vector bauen
	std::vector<sf::Vector2f> screws = m_gst->getScrewLocations();
	std::vector<sf::Vector2f>::iterator s_it;

	for(s_it = screws.begin();s_it != screws.end();s_it++)
	{
		sprite_screws.setPosition(*s_it);
		m_wnd->draw(sprite_screws);
	}


	if(m_gst->getGameState() == STATE_MENU)
	{
		// Menu texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("ENIS ENIS ENIS ENIS");
		text_title.setCharacterSize(80);
		text_title.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_title.getLocalBounds().width/2,200));
		m_wnd->draw(text_title);

		sf::Text text_help;
		text_help.setFont(m_normal_font);
		text_help.setString("RocketRacoon wants to meet his daddy.\n Help him! start with the <SPACE> key.");
		text_help.setCharacterSize(20);
		text_help.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_help.getLocalBounds().width/2,500));
		m_wnd->draw(text_help);
	}
	else if (m_gst->getGameState() == STATE_SHOP)
	{
		//TODO
		m_wnd->clear();

		sf::Sprite sprite_shopbackground;
		sprite_shopbackground.setTexture(m_texture_shopbackground);
		sprite_shopbackground.setTextureRect(sf::IntRect(0,0,m_wnd->getSize().x,m_wnd->getSize().y));
		m_wnd->draw(sprite_shopbackground);

		//Upgrade 1
		sf::Sprite sprite_slot1;
		/*if upgradevector.bought == false;	// if nicht gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_slot1);
		else // if gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_upgrade_bought);*/
		sprite_slot1.setTexture(m_texture_slot1);
		sprite_slot1.setPosition(150, 200);
		sf::Text text_slot1;
		text_slot1.setFont(m_bold_font);
		text_slot1.setString("TEST");
		text_slot1.setColor(sf::Color::White);
		text_slot1.setPosition(150, 150);
		m_wnd->draw(text_slot1);
		m_wnd->draw(sprite_slot1);
		
		//Upgrade 2
		sf::Sprite sprite_slot2;
		/*if upgradevector.bought == false;	// if nicht gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_slot1);
		else // if gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_upgrade_bought);*/
		sprite_slot2.setTexture(m_texture_slot1);
		sprite_slot2.setPosition(300, 200);
		sf::Text text_slot2;
		text_slot2.setFont(m_bold_font);
		text_slot2.setString("TEST");
		text_slot2.setColor(sf::Color::White);
		text_slot2.setPosition(300, 150);
		m_wnd->draw(text_slot2);
		m_wnd->draw(sprite_slot2);
		
		//Upgrade 3
		sf::Sprite sprite_slot3;
		/*if upgradevector.bought == false;	// if nicht gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_slot1);
		else // if gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_upgrade_bought);*/
		sprite_slot3.setTexture(m_texture_slot1);
		sprite_slot3.setPosition(450, 200);
		sf::Text text_slot3;
		text_slot3.setFont(m_bold_font);
		text_slot3.setString("TEST");
		text_slot3.setColor(sf::Color::White);
		text_slot3.setPosition(450, 150);
		m_wnd->draw(text_slot3);
		m_wnd->draw(sprite_slot3);
		
		//Upgrade 4
		sf::Sprite sprite_slot4;
		/*if upgradevector.bought == false;	// if nicht gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_slot1);
		else // if gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_upgrade_bought);*/
		sprite_slot4.setTexture(m_texture_slot1);
		sprite_slot4.setPosition(600, 200);
		sf::Text text_slot4;
		text_slot4.setFont(m_bold_font);
		text_slot4.setString("TEST");
		text_slot4.setColor(sf::Color::White);
		text_slot4.setPosition(600, 150);
		m_wnd->draw(text_slot4);
		m_wnd->draw(sprite_slot4);
		
		//Upgrade 5
		sf::Sprite sprite_slot5;
		/*if upgradevector.bought == false;	// if nicht gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_slot1);
		else // if gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_upgrade_bought);*/
		sprite_slot5.setTexture(m_texture_slot1);
		sprite_slot5.setPosition(150, 400);
		sf::Text text_slot5;
		text_slot5.setFont(m_bold_font);
		text_slot5.setString("TEST");
		text_slot5.setColor(sf::Color::White);
		text_slot5.setPosition(150, 350);
		m_wnd->draw(text_slot5);
		m_wnd->draw(sprite_slot5);
		
		//Upgrade 8
		sf::Sprite sprite_slot8;
		/*if upgradevector.bought == false;	// if nicht gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_slot1);
		else // if gekauft / Seite
			sprite_upgrade1.setTexture(m_texture_upgrade_bought);*/
		sprite_slot8.setTexture(m_texture_slot1);
		sprite_slot8.setPosition(150, 600);
		sf::Text text_slot8;
		text_slot8.setFont(m_bold_font);
		text_slot8.setString("TEST");
		text_slot8.setColor(sf::Color::White);
		text_slot8.setPosition(150, 550);
		m_wnd->draw(text_slot8);
		m_wnd->draw(sprite_slot8);
		
		//Stats
		sf::Text text_stats;
		text_stats.setFont(m_bold_font);
		text_stats.setString("Stats:");
		text_stats.setColor(sf::Color::White);
		text_stats.setPosition(1000, 450);
		m_wnd->draw(text_stats);
		
		sf::Text text_stats_startspeed;
		text_stats_startspeed.setFont(m_bold_font);
		text_stats_startspeed.setString("Startspeed: ");
		text_stats_startspeed.setColor(sf::Color::White);
		text_stats_startspeed.setPosition(1000, 500);
		m_wnd->draw(text_stats_startspeed);
		
		sf::Text text_stats_startspeed_number;
		text_stats_startspeed_number.setFont(m_bold_font);
		text_stats_startspeed_number.setString("X");
		text_stats_startspeed_number.setColor(sf::Color::White);
		text_stats_startspeed_number.setPosition(1200, 500);
		m_wnd->draw(text_stats_startspeed_number);
		
		sf::Text text_stats_aerodynamic;
		text_stats_aerodynamic.setFont(m_bold_font);
		text_stats_aerodynamic.setString("Aerodynamic: ");
		text_stats_aerodynamic.setColor(sf::Color::White);
		text_stats_aerodynamic.setPosition(1000, 550);
		m_wnd->draw(text_stats_aerodynamic);
		
		sf::Text text_stats_aerodynamic_number;
		text_stats_aerodynamic_number.setFont(m_bold_font);
		text_stats_aerodynamic_number.setString("X");
		text_stats_aerodynamic_number.setColor(sf::Color::White);
		text_stats_aerodynamic_number.setPosition(1200, 550);
		m_wnd->draw(text_stats_aerodynamic_number);
		
		sf::Text text_stats_coolness;
		text_stats_coolness.setFont(m_bold_font);
		text_stats_coolness.setString("Coolness: ");
		text_stats_coolness.setColor(sf::Color::White);
		text_stats_coolness.setPosition(1000, 600);
		m_wnd->draw(text_stats_coolness);
		
		sf::Text text_stats_coolness_number;
		text_stats_coolness_number.setFont(m_bold_font);
		text_stats_coolness_number.setString("X");
		text_stats_coolness_number.setColor(sf::Color::White);
		text_stats_coolness_number.setPosition(1200, 600);
		m_wnd->draw(text_stats_coolness_number);
	}

	else if(m_gst->getGameState() == STATE_PLAYING)
	{
		std::stringstream str;
		//str << m_gst->getCollectedScrewsCount() << " collected\n" << m_gst->getVisibleScrewsCount() << " visible";


		// Game texts
		sf::Text text_screws;
		text_screws.setFont(m_bold_font);
		text_screws.setString(str.str());
		text_screws.setCharacterSize(30);
		text_screws.setPosition(sf::Vector2f(30,30));
		m_wnd->draw(text_screws);
	}
	
	
	m_wnd->display();

}
