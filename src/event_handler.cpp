#include "event_handler.h"

EventHandler::EventHandler(sf::RenderWindow *window, GameState *state)
{
	m_wnd = window;
	m_gst = state;
	s = SoundHandler::getSoundHandler();
}

void EventHandler::handleEvents()
{
	sf::Event event;
    while (m_wnd->pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed)
        {
            m_wnd->close();
        }

        if (m_gst->getGameState() == STATE_MENU)
        {
        }
        //restart game when r pressed
        else if (m_gst->getGameState() == STATE_PLAYING)
        {
        	if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::R)
				{
					m_gst->startPlaying();
				}
			}
        }
        else if (m_gst->getGameState() == STATE_READY_TO_LAUNCH)
        {
        	// Start/continue playing when SPACE is pressed
        	if(event.type == sf::Event::KeyPressed)
        	{ 
				if(event.key.code == sf::Keyboard::Space)
				{
					m_gst->startPlaying();
					s->playSound(SOUND_START);
					//m_gst->setGameState(STATE_PLAYING);
					//std::cout<< "blaaaaabbbbbaaaa\n";
				}
			}
        }
        else if ( m_gst->getGameState() == STATE_PAUSE || m_gst->getGameState() == STATE_CONTROLS)
        {
        	//TODO Clean Up ? :D 
        }

//SUPER SPECIAL MINIGAME
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && m_gst->getGameState() == STATE_SHOP)
    {
		m_gst->setGameState(STATE_MINI);
		m_gst->startMini();
    }

//MOUSE HANDLING
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_gst->getGameState() == STATE_SHOP)
	{
		m_gst->shopMouseHandling(sf::Mouse::getPosition(*m_wnd));
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_gst->getGameState() == STATE_MENU)
	{
		m_gst->menuMouseHandling(sf::Mouse::getPosition(*m_wnd));
	}

	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_gst->getGameState() == STATE_CREDITS)
	{
		m_gst->creditsMouseHandling(sf::Mouse::getPosition(*m_wnd));
	}

	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_gst->getGameState() == STATE_CONTROLS)
	{
		m_gst->controlMouseHandling(sf::Mouse::getPosition(*m_wnd));
	}
	
	
	


	// Get robot direction
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_LEFT);
        	//std::cout << "left" <<std::endl;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_RIGHT);
        	//std::cout << "right" <<std::endl;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_UP);
        	//std::cout << "up" <<std::endl;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_DOWN);
        	//std::cout << "down" <<std::endl;
        }
        else
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_NONE);
        }
        
//GLOBAL HOTKEYS		
		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::M)
			{
				s->toggleMute();
			}
			else if(event.key.code == sf::Keyboard::C)
			{
				m_gst->setTotalDodgecoins(m_gst->getTotalDodgecoins()+10);
			}
		}
    }
}
