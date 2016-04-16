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

    if (!m_texture_startBg.loadFromFile("assets/anfang.png"))
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
	if (!m_texture_shopbackground.loadFromFile("assets/brickwall.jpg"))
	{
    	m_wnd->close();
    }	
    if (!m_texture_graffitti.loadFromFile("assets/FF.png"))
	{
    	m_wnd->close();
    }	
    if (!m_texture_slot1.loadFromFile("assets/Kaufen.png"))
	{
    	m_wnd->close();
    }
	if (!m_texture_upgrade_bought.loadFromFile("assets/na.png"))
	{
		m_wnd->close();
	}
	
	if (!m_texture_fappsy.loadFromFile("assets/fappsi.png"))
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
	if (!m_texture_minibackground.loadFromFile("assets/anfang.png"))
	{
		m_wnd->close();
	}
	
	// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

	
	


    // Load all the fonts
    if (!m_normal_font.loadFromFile("assets/Roboto-Regular.ttf"))
    {
    	m_wnd->close();
    }

    if (!m_bold_font.loadFromFile("assets/Roboto-Bold.ttf"))
    {
    	m_wnd->close();
    }
	
	if (!m_funk.loadFromFile("assets/Cocksure.ttf"))
    {
    	m_wnd->close();
    }
}

void Renderer::drawGame()
{
	m_wnd->clear();

	sf::View view(sf::Vector2f(640,m_gst->getPlayerLocation().y), sf::Vector2f(1280,800));
    m_wnd->setView(view);

	//zeichne hintergrund
    sf::Sprite sprite_background;
	sprite_background.setTexture(m_texture_background);
	sf::Vector2f textureSize(80,80);
	float textureLocation_y = fmod(m_gst->getPlayerLocation().y,textureSize.y);
	sprite_background.setTextureRect(sf::IntRect(0,textureLocation_y,m_wnd->getSize().x ,m_wnd->getSize().y*2));
	sprite_background.setPosition(0,m_gst->getPlayerLocation().y - 400);
	m_wnd->draw(sprite_background);		
	
	//weltraum beginnt bei 1500
	float transparency = 255 - m_gst->getPlayerLocation().y/1500; 
	
	

	
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

	//Coin vector bauen
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

	if(m_gst->getGameState() == STATE_MENU)
	{
		// Menu texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("The desperate Rocket Rocky's Path To Infinity ");
		text_title.setCharacterSize(80);
		text_title.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_title.getLocalBounds().width/2,200));
		m_wnd->draw(text_title);

		sf::Text text_help;
		text_help.setFont(m_normal_font);
		text_help.setString("Rocky the Rocket wants to meet his daddy.\nBut he is high up in space. :-( Help him get there! \nStart with the <SPACE> key.");
		text_help.setCharacterSize(20);
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
		sprite_help.setPosition(100,400);
		m_wnd->draw(sprite_help);
		
		//Beenden Button
		sf::Sprite sprite_quit;
		sprite_quit.setTexture(m_texture_quit); 
		sprite_quit.setPosition(100,600);
		m_wnd->draw(sprite_quit);
		
	}
	if(m_gst->getGameState() == STATE_READY_TO_LAUNCH)
	{
		// Menu texts
		sf::Text text_title;
		text_title.setFont(m_bold_font);
		text_title.setString("PRESS <SPACE> TO LAUNCH");
		text_title.setCharacterSize(80);
		text_title.setColor(sf::Color::Red);
		text_title.setPosition(sf::Vector2f(m_wnd->getSize().x/2 - text_title.getLocalBounds().width/2,200));
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
		sprite_graffitti.setTextureRect(sf::IntRect(0,0,m_wnd->getSize().x,m_wnd->getSize().y));
		m_wnd->draw(sprite_graffitti);
		
		//Headline Shop
		sf::Text text_head;
		text_head.setFont(m_funk);
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
		
		/*sf::Sprite sprite_slot[12];  
		for(int i = 0; i < 12; i++)
		{
			//sprite_slot();
			if (upgrades->at(i)->price != 0)	// if nicht gekauft / Seite
			{
			//	sprite_slot[i].setTexture(m_texture_slot1);
			}
		}*/
		
		
		//Upgrade 1
		sf::Sprite sprite_slot1;
		if (upgrades->at(0)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot1.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot1.setTexture(m_texture_upgrade_bought);
		}
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
		if (upgrades->at(1)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot2.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot2.setTexture(m_texture_upgrade_bought);
		}
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
		if (upgrades->at(2)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot3.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot3.setTexture(m_texture_upgrade_bought);
		}
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
		if (upgrades->at(3)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot4.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot4.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot4.setPosition(600, 200);
		sf::Text text_slot4;
		text_slot4.setFont(m_bold_font);
		text_slot4.setString("TEST");
		text_slot4.setColor(sf::Color::White);
		text_slot4.setPosition(600, 150);
		m_wnd->draw(text_slot4);
		m_wnd->draw(sprite_slot4);
		/*
		//Upgrade 5
		sf::Sprite sprite_slot5;
		if (upgrades->at(4)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot5.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot5.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot5.setPosition(150, 400);
		sf::Text text_slot5;
		text_slot5.setFont(m_bold_font);
		text_slot5.setString("TEST");
		text_slot5.setColor(sf::Color::White);
		text_slot5.setPosition(150, 350);
		m_wnd->draw(text_slot5);
		m_wnd->draw(sprite_slot5);
		
		//Upgrade 6
		sf::Sprite sprite_slot6;
		if (upgrades->at(5)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot6.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot6.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot6.setPosition(300, 400);
		sf::Text text_slot6;
		text_slot6.setFont(m_bold_font);
		text_slot6.setString("TEST");
		text_slot6.setColor(sf::Color::White);
		text_slot6.setPosition(300, 350);
		m_wnd->draw(text_slot6);
		m_wnd->draw(sprite_slot6);
		
		//Upgrade 7
		sf::Sprite sprite_slot7;
		if (upgrades->at(6)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot7.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot7.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot7.setPosition(450, 400);
		sf::Text text_slot7;
		text_slot7.setFont(m_bold_font);
		text_slot7.setString("TEST");
		text_slot7.setColor(sf::Color::White);
		text_slot7.setPosition(450, 350);
		m_wnd->draw(text_slot7);
		m_wnd->draw(sprite_slot7);
		
		//Upgrade 8
		sf::Sprite sprite_slot8;
		if (upgrades->at(7)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot8.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot8.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot8.setTexture(m_texture_slot1);
		sprite_slot8.setPosition(600, 400);
		sf::Text text_slot8;
		text_slot8.setFont(m_bold_font);
		text_slot8.setString("TEST");
		text_slot8.setColor(sf::Color::White);
		text_slot8.setPosition(600, 350);
		m_wnd->draw(text_slot8);
		m_wnd->draw(sprite_slot8);
		
		//Upgrade 9
		sf::Sprite sprite_slot9;
		if (upgrades->at(8)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot9.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot9.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot9.setPosition(150, 600);
		sf::Text text_slot9;
		text_slot9.setFont(m_bold_font);
		text_slot9.setString("TEST");
		text_slot9.setColor(sf::Color::White);
		text_slot9.setPosition(150, 550);
		m_wnd->draw(text_slot9);
		m_wnd->draw(sprite_slot9);
		
		//Upgrade 10
		sf::Sprite sprite_slot10;
		if (upgrades->at(9)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot10.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot10.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot10.setPosition(300, 600);
		sf::Text text_slot10;
		text_slot10.setFont(m_bold_font);
		text_slot10.setString("TEST");
		text_slot10.setColor(sf::Color::White);
		text_slot10.setPosition(300, 550);
		m_wnd->draw(text_slot10);
		m_wnd->draw(sprite_slot10);
		
		//Upgrade 11
		sf::Sprite sprite_slot11;
		if (upgrades->at(10)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot11.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot11.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot11.setPosition(450, 600);
		sf::Text text_slot11;
		text_slot11.setFont(m_bold_font);
		text_slot11.setString("TEST");
		text_slot11.setColor(sf::Color::White);
		text_slot11.setPosition(450, 550);
		m_wnd->draw(text_slot11);
		m_wnd->draw(sprite_slot11);
		
		//Upgrade 12
		sf::Sprite sprite_slot12;
		if (upgrades->at(11)->price != 0)	// if nicht gekauft / Seite
		{
			sprite_slot12.setTexture(m_texture_slot1);
		}
		else // if gekauft / Seite
		{
			sprite_slot12.setTexture(m_texture_upgrade_bought);
		}
		sprite_slot12.setPosition(600, 600);
		sf::Text text_slot12;
		text_slot12.setFont(m_bold_font);
		text_slot12.setString("TEST");
		text_slot12.setColor(sf::Color::White);
		text_slot12.setPosition(600, 550);
		m_wnd->draw(text_slot12);
		m_wnd->draw(sprite_slot12);
		
		*/
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
		std::stringstream str;
		str << "Height: " << -m_gst->getPlayerLocation().y << "\nVelocity "<< m_gst->getVelocity() << "\nCoins: " << m_gst->getCollectedDodgecoinCount();		


// a -b 

		// Game texts
		sf::Text text_height;
		text_height.setFont(m_bold_font);
		text_height.setString(str.str());
		text_height.setCharacterSize(30);
		text_height.setPosition(sf::Vector2f(30,m_gst->getPlayerLocation().y));
		m_wnd->draw(text_height);
		
		m_wnd->draw(m_gst->rocket);	
	}
	else if (m_gst->getGameState() == STATE_MINI)
	{
		sf::View nils_view(sf::Vector2f(640,400), sf::Vector2f(1280,800));
   		m_wnd->setView(nils_view);
   		
		// Coins collected text		
		std::stringstream str;		
		str << "Coins: " << m_gst->getCollectedDodgecoinCount();	
		
		sf::Sprite sprite_minibackground;
		sprite_minibackground.setTexture(m_texture_minibackground);
		sprite_minibackground.setTextureRect(sf::IntRect(0,0,m_wnd->getSize().x,m_wnd->getSize().y));
		m_wnd->draw(sprite_minibackground);
		
		sf::Sprite sprite_achieve;
		sprite_achieve.setTexture(m_texture_jung_und_geld); 
		sprite_achieve.setPosition(294,50);
		m_wnd->draw(sprite_achieve);
		
		/*
sf::Text text_coins;
		text_coins.setFont(m_bold_font);
		text_coins.setString(str.str());
		text_coins.setCharacterSize(30);
		text_coins.setPosition(sf::Vector2f(30,m_gst->getPlayerLocation().y));
		m_wnd->draw(text_coins);
	*/
		m_gst->nils.setLocation(m_gst->getPlayerLocation());  //panda

		m_wnd->draw(m_gst->nils);

	}

	m_wnd->display();
}
