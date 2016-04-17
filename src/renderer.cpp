#include "renderer.h"

Renderer::Renderer(sf::RenderWindow *window, GameState *state)
{
	m_wnd = window;
	m_gst = state;

	// Load all the textures
	if (!m_texture_background.loadFromFile("assets/sternenhimmel.png"))
	{
    	m_wnd->close();
    }
    m_texture_background.setRepeated(true);
    if (!m_texture_background2.loadFromFile("assets/tageshimmel.png"))
	{
    	m_wnd->close();
    }
    m_texture_background2.setRepeated(true);

    if (!m_texture_startBg.loadFromFile("assets/rocky_mountains_screen.png"))
	{
    	m_wnd->close();
    }

	if (!m_texture_player.loadFromFile("assets/rocket_basic.png"))
	{
		m_wnd->close();
	}
    if (!m_texture_dodgecoin.loadFromFile("assets/Qoin_klein.png"))
	{
    	m_wnd->close();
    }
    if (!m_texture_meteor.loadFromFile("assets/meteor.png"))
	{
    	m_wnd->close();
    }	
	if (!m_texture_shopbackground.loadFromFile("assets/licht.png"))
	{
    	m_wnd->close();
    }	
    if (!m_texture_graffitti.loadFromFile("assets/FF.png"))
	{
    	m_wnd->close();
    }	
    if (!m_texture_buy.loadFromFile("assets/Kaufen.png"))
	{
    	m_wnd->close();
    }
    if (!m_texture_item_bg.loadFromFile("assets/shop_item_bg.png"))
	{
    	m_wnd->close();
    }
	if (!m_texture_upgrade_bought.loadFromFile("assets/NV.png"))
	{
		m_wnd->close();
	}
	
	if (!m_texture_fappsy.loadFromFile("assets/morefappfapp.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_mower.loadFromFile("assets/mower.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_jung_und_geld.loadFromFile("assets/achieve_jungundgeld.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_takeoff.loadFromFile("assets/takeoff.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_menu.loadFromFile("assets/menu.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_minibackground.loadFromFile("assets/rocky_mountains_screen.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_play.loadFromFile("assets/play.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_help.loadFromFile("assets/help.png"))
	{
		m_wnd->close();
	}
	if (!m_texture_quit.loadFromFile("assets/quit.png"))
	{
		m_wnd->close();
	}

	if (!m_texture_credits.loadFromFile("assets/credits.png"))
	{
		m_wnd->close();
	}
	
	if (!m_texture_papa.loadFromFile("assets/cola_anne.png"))
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
	
	if (!m_funk.loadFromFile("assets/Funk.ttf"))
    {
    	m_wnd->close();
    }
}

void Renderer::drawGame()
{
	m_wnd->clear();

	sf::View view(sf::Vector2f(640, m_gst->getPlayerLocation().y), sf::Vector2f(1280,800));
	m_wnd->setView(view);

	if(m_gst->getGameState() == STATE_MENU)
	{
		sf::Sprite sprite_startBg;
		sprite_startBg.setTexture(m_texture_startBg);
		//sprite_startBg.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
		sprite_startBg.setPosition(0,0);
		m_wnd->draw(sprite_startBg);
	
		// Menu texts
		sf::Text text_title;
		text_title.setFont(m_funk);
		text_title.setColor(sf::Color::Magenta);
		text_title.setString("The desperate Rocket Rocky's Path To Infinity ");
		text_title.setCharacterSize(50);
		text_title.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_title.getLocalBounds().width/2,50));
		m_wnd->draw(text_title);
	

		sf::Text text_help;
		text_help.setFont(m_bold_font);
		text_help.setColor(sf::Color::White);
		text_help.setString("Rocky the Rocket wants to meet his daddy.\nBut he is high up in the sky. :-( Help him get there!");
		text_help.setCharacterSize(30);
		text_help.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_help.getLocalBounds().width/2,500));
		m_wnd->draw(text_help);
		
		//Start Button
		sf::Sprite sprite_play;
		sprite_play.setTexture(m_texture_play); 
		sprite_play.setPosition(100,200);
		m_wnd->draw(sprite_play);
		
		//Hilfe Button
		sf::Sprite sprite_help;
		sprite_help.setTexture(m_texture_help); 
		sprite_help.setPosition(100,350);
		m_wnd->draw(sprite_help);
		
		//Beenden Button
		sf::Sprite sprite_quit;
		sprite_quit.setTexture(m_texture_quit); 
		sprite_quit.setPosition(100,500);
		m_wnd->draw(sprite_quit);
		
		//Credits Button
		sf::Sprite sprite_credits;
		sprite_credits.setTexture(m_texture_credits); 
		sprite_credits.setPosition(100,650); 
		m_wnd->draw(sprite_credits);
		
		
		
	}
	else if(m_gst->getGameState() == STATE_READY_TO_LAUNCH)
	{
		sf::View launch_view(sf::Vector2f(640,400), sf::Vector2f(1280,800));
   		m_wnd->setView(launch_view);
		
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("PRESS <SPACE> TO LAUNCH");
		text_title.setCharacterSize(70);
		text_title.setColor(sf::Color::Red);
		
		text_title.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_title.getLocalBounds().width/2,100));
		
		//weltraum beginnt bei 1500
		float transparency = 255 - m_gst->getPlayerLocation().y/(1500*100); 
		
		sf::Sprite sprite_background2;
		sf::Vector2f textureSize(80,80);
		float textureLocation_y = fmod(m_gst->getPlayerLocation().y,textureSize.y);
		sprite_background2.setTexture(m_texture_background2);
		sprite_background2.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
		sprite_background2.setPosition(0,m_gst->getPlayerLocation().y - 400);
		sprite_background2.setColor(sf::Color(255, 255, 255, transparency));
		m_wnd->draw(sprite_background2);	
	
		sf::Sprite sprite_startBg;
		sprite_startBg.setTexture(m_texture_startBg);
		//sprite_startBg.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
		sprite_startBg.setPosition(0,0);
		m_wnd->draw(sprite_startBg);
		
		

		
		

		
		m_wnd->draw(text_title);
		m_wnd->draw(m_gst->rocket);	

	}
	else if (m_gst->getGameState() == STATE_SHOP)
	{
	
		sf::View shop_view(sf::Vector2f(640,400), sf::Vector2f(1280,800));
   		m_wnd->setView(shop_view);

		sf::Sprite sprite_shopbackground;
		sprite_shopbackground.setTexture(m_texture_shopbackground);
		sprite_shopbackground.setTextureRect(sf::IntRect(0,0,m_wnd->getSize().x,m_wnd->getSize().y));
		m_wnd->draw(sprite_shopbackground);
		
		sf::Sprite sprite_graffitti;
		sprite_graffitti.setTexture(m_texture_graffitti);
		sprite_graffitti.setTextureRect(sf::IntRect(0,250,m_wnd->getSize().x,m_wnd->getSize().y));
		m_wnd->draw(sprite_graffitti);
		
		//Headline Shop
		sf::Text text_head;
		text_head.setFont(m_funk);
		text_head.setColor(sf::Color::Cyan);
		text_head.setCharacterSize(80);
		text_head.setPosition(75, 10);
		text_head.setString("Fappsy's Fappulous Fanshop");
		m_wnd->draw(text_head);
		
		//Fappsy
		sf::Sprite sprite_fappsy;
		sprite_fappsy.setTexture(m_texture_fappsy);
		sprite_fappsy.setPosition(700,400);
		sprite_fappsy.scale(sf::Vector2f(5, 5)); // factor relative to the current scale
		m_wnd->draw(sprite_fappsy);
		
		//Start Button
		sf::Sprite sprite_takeoff;
		sprite_takeoff.setTexture(m_texture_takeoff); 
		sprite_takeoff.setPosition(1000,700);
		m_wnd->draw(sprite_takeoff);
		
		//Menue Button
		sf::Sprite sprite_menue;
		sprite_menue.setTexture(m_texture_menu);
		sprite_menue.setPosition(100,700);
		m_wnd->draw(sprite_menue);


		std::vector<Upgrade*> *upgrades = m_gst->getUpgradeList();
		
		//Upgrades
		int numberOfUpgrades = upgrades->size();
		sf::Sprite sprite_slot[12];
		sf::Sprite sprite_button_slot[12];
		sf::Sprite sprite_item_bg[12];
		sf::Text text_slot[12];  
		for(int i = 0; i < numberOfUpgrades; i++)
		{
			float x = 150 * (i %4 +1);
			float y = 200 * (i/4 +1);
			
			sprite_item_bg[i].setPosition(x,y-100);
			sprite_item_bg[i].setTexture(m_texture_item_bg);
			sprite_item_bg[i].setColor(sf::Color(255,255,255,128));
			m_wnd->draw(sprite_item_bg[i]);
			
			sprite_slot[i].setPosition(x, y-80);
			sprite_slot[i].setTexture(upgrades->at(i)->texture);
			text_slot[i].setFont(m_bold_font);
			std::stringstream upgradeString;
			upgradeString << upgrades->at(i)->name;
			if(upgrades->at(i)->price > 0)
			{
				upgradeString << "\n \n\n\n\n\n Preis: ";
				upgradeString << upgrades->at(i)->price;
			}
			
			text_slot[i].setString(upgradeString.str());
			text_slot[i].setColor(sf::Color::Black);
			text_slot[i].setPosition(x+10, y-100);
			text_slot[i].setCharacterSize(20);
			m_wnd->draw(sprite_slot[i]);
			m_wnd->draw(text_slot[i]);
			//sprite_slot();
			if (upgrades->at(i)->price != 0)	// if nicht gekauft / Seite
			{
				sprite_button_slot[i].setTexture(m_texture_buy);
			}
			else // if gekauft / Seite
			{
				sprite_button_slot[i].setTexture(m_texture_upgrade_bought);
			}
			sprite_button_slot[i].setPosition(x, y);
			m_wnd->draw(sprite_button_slot[i]);
		}
		
		
		
		Rocket r = m_gst->rocket;
		r.updateStats();
		std::stringstream statsString;
		statsString << "Stats: \n";
		statsString << "Startspeed: " << r.boost << "\n";
		statsString << "Aerodynamic: " << r.aerodynamic << "\n";
		statsString << "Coolness: " << r.coolness << "\n";
		//Stats
		sf::Text text_stats;
		text_stats.setFont(m_bold_font);
		text_stats.setString(statsString.str());
		text_stats.setColor(sf::Color::White);
		text_stats.setPosition(1000, 450);
		m_wnd->draw(text_stats);
		
		//coins
		std::stringstream str;
		str << "Coins: " << m_gst->getTotalDodgecoins();	
		
		sf::Text text_coins;
		text_coins.setFont(m_bold_font);
		text_coins.setString(str.str());
		text_coins.setCharacterSize(30);
		text_coins.setPosition(sf::Vector2f(1000,100));
		m_wnd->draw(text_coins);
	}
	else if(m_gst->getGameState() == STATE_CONTROLS)
	{
		// Controls texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("Controls");
		text_title.setCharacterSize(80);
		text_title.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y -160));
		m_wnd->draw(text_title);

		sf::Text text_controls;
		text_controls.setFont(m_normal_font);
		text_controls.setString(" Pause \t\t\t\t\t\t\t\t\t\t <P>\n Mute \t\t\t\t\t\t\t\t\t\t  <M>\n Beenden\t\t\t\t\t\t\t\t\t <Escape>\n Spiel starten/fortsetzen \t\t <Space>\n Spiel neustarten\t\t\t\t\t\t<R>\n");
		text_controls.setCharacterSize(20);
		text_controls.setPosition(sf::Vector2f(m_gst->getPlayerLocation().x  -120 ,m_gst->getPlayerLocation().y +100));
		m_wnd->draw(text_controls);
	}
	else if(m_gst->getGameState() == STATE_PLAYING)
	{			
		//zeichne hintergrund
		sf::Sprite sprite_background;
		sprite_background.setTexture(m_texture_background);
		sf::Vector2f textureSize(320,200);
		float textureLocation_y = fmod(m_gst->getPlayerLocation().y,textureSize.y);
		sprite_background.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
		sprite_background.setPosition(0,m_gst->getPlayerLocation().y - 400);
		m_wnd->draw(sprite_background);		
	
		//weltraum beginnt bei 1500
		float transparency = 255 - m_gst->getPlayerLocation().y/(1500*100); 
	
		sf::Sprite sprite_background2;
		sprite_background2.setTexture(m_texture_background2);
		sprite_background2.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
		sprite_background2.setPosition(0,m_gst->getPlayerLocation().y - 400);
		sprite_background2.setColor(sf::Color(255, 255, 255, transparency));
		m_wnd->draw(sprite_background2);	
	
		sf::Sprite sprite_startBg;
		sprite_startBg.setTexture(m_texture_startBg);
		sprite_startBg.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
		sprite_startBg.setPosition(0,0);
		m_wnd->draw(sprite_startBg);

		std::vector<sf::Vector2f> dodgecoin = m_gst->getDodgecoinLocations();
		std::vector<sf::Vector2f>::iterator s_it;

		for(s_it = dodgecoin.begin();s_it != dodgecoin.end();s_it++)
		{
			// Coins einfügen
			sf::Sprite sprite_dodgecoin;
			sprite_dodgecoin.setTexture(m_texture_dodgecoin);
			sprite_dodgecoin.setPosition(*s_it);
			m_wnd->draw(sprite_dodgecoin);
		}	
		
		std::vector<sf::Vector2f> meteor = m_gst->getMeteorLocations();
		//std::vector<sf::Vector2f>::iterator s_it;

		for(s_it = meteor.begin();s_it != meteor.end();s_it++)
		{
			// Coins einfügen
			sf::Sprite sprite_meteor;
			sprite_meteor.setTexture(m_texture_meteor);
			sprite_meteor.setPosition(*s_it);
			m_wnd->draw(sprite_meteor);
		}	
		
		
		//stats
		std::stringstream str;
		str << "Height: " << -m_gst->getPlayerLocation().y/100 << "\nVelocity "<< m_gst->getVelocity() << "\nCoins: " << m_gst->getCollectedDodgecoinCount();		
		
		// Game texts
		sf::Text text_height;
		text_height.setFont(m_bold_font);
		text_height.setString(str.str());
		text_height.setCharacterSize(30);
		text_height.setPosition(sf::Vector2f(30,m_gst->getPlayerLocation().y));
		m_wnd->draw(text_height);
		
		m_wnd->draw(m_gst->rocket);	
	}
	else if(m_gst->getGameState() == STATE_MINI)
	{
		sf::View nils_view(sf::Vector2f(640,400), sf::Vector2f(1280,800));
   		m_wnd->setView(nils_view);
   		
		
		
		sf::Sprite sprite_minibackground;
		sprite_minibackground.setTexture(m_texture_minibackground);
		sprite_minibackground.setTextureRect(sf::IntRect(0,0,m_wnd->getSize().x,m_wnd->getSize().y));
		m_wnd->draw(sprite_minibackground);
		
		std::vector<sf::Vector2f> dodgecoin = m_gst->getDodgecoinLocations();
		std::vector<sf::Vector2f>::iterator s_it;

		for(s_it = dodgecoin.begin();s_it != dodgecoin.end();s_it++)
		{
			// Coins einfügen
			sf::Sprite sprite_dodgecoin;
			sprite_dodgecoin.setTexture(m_texture_dodgecoin);
			sprite_dodgecoin.setPosition(*s_it);
			m_wnd->draw(sprite_dodgecoin);
		}
		
		sf::Sprite sprite_achieve;
		sprite_achieve.setTexture(m_texture_jung_und_geld); 
		sprite_achieve.setPosition(294,50);
		m_wnd->draw(sprite_achieve);
		
		//stats
		// Coins collected text		
		std::stringstream str;		
		str << "Coins: " << m_gst->getCollectedDodgecoinCount();		
		
		
		sf::Text text_coins;
		text_coins.setFont(m_bold_font);
		text_coins.setString(str.str());
		text_coins.setCharacterSize(30);
		text_coins.setPosition(sf::Vector2f(30,m_gst->getPlayerLocation().y));
		m_wnd->draw(text_coins);
	
		m_gst->nils.setLocation(m_gst->getPlayerLocation());  //panda

		m_wnd->draw(m_gst->nils);
	}
	else if (m_gst->getGameState() == STATE_END)
	{
		//Zeichne Hintergrund
		sf::Sprite sprite_background;
		sprite_background.setTexture(m_texture_background);
		sf::Vector2f textureSize(80,80);
		float textureLocation_y = fmod(m_gst->getPlayerLocation().y,textureSize.y);
		sprite_background.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
		sprite_background.setPosition(0,m_gst->getPlayerLocation().y - 400);
		m_wnd->draw(sprite_background);		
		
		//Zeichne Raketen
		sf::Sprite sprite_papa;
		sf::Vector2f location;
		location.x = 680;
		location.y = 400;
		m_gst->rocket.setLocation(location);
		m_wnd->draw(m_gst->rocket);
		
		sprite_papa.setPosition(600,400);
		sprite_papa.setTexture(m_texture_papa);
		m_wnd->draw(sprite_papa);
		
	}
	m_wnd->display();
}
