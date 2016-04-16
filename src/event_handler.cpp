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
        	// Start/continue playing when SPACE is pressed
        	if(event.key.code == sf::Keyboard::Space)
        	{
        		m_gst->setGameState(STATE_READY_TO_LAUNCH);
        		m_gst->startPlaying();
        		//std::cout<< "blaaaaa\n";
        	}
        	//show control when C is pressed
        	else if(event.key.code == sf::Keyboard::C)
        	{
        		m_gst->setGameState(STATE_CONTROLS);
        	}
        }
        else if (event.type == sf::Event::KeyPressed && m_gst->getGameState() == STATE_READY_TO_LAUNCH)
        {
        	// Start/continue playing when SPACE is pressed
        	if(event.key.code == sf::Keyboard::Space)
        	{
        		
        		m_gst->setGameState(STATE_PLAYING);
        		//std::cout<< "blaaaaabbbbbaaaa\n";
        	}
        }
        else if ( m_gst->getGameState() == STATE_PAUSE || m_gst->getGameState() == STATE_CONTROLS)
        {
        	// Start/continue playing when SPACE is pressed
        	if(event.key.code == sf::Keyboard::Space)
        	{
        		m_gst->setGameState(STATE_PLAYING);
        	}
        	//show control when C is pressed
        	else if(event.key.code == sf::Keyboard::C)
        	{
        		m_gst->setGameState(STATE_CONTROLS);
        	}
        }
        // TEST: Open shop when B is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && m_gst->getGameState() == STATE_PLAYING)
        {
        	//m_gst->startShop();
			m_gst->setGameState(STATE_SHOP);
        }

//SUPER SPECIAL MINIGAME
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && m_gst->getGameState() == STATE_PLAYING)
        {
        	//m_gst->startShop();
		m_gst->setGameState(STATE_MINI);
		std::cout << "event start mini" <<std::endl;
		m_gst->startMini();
        }


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_gst->getGameState() == STATE_SHOP)
		{
			m_gst->buyUpgrade(sf::Mouse::getPosition(*m_wnd));
		}

        // Get robot direction
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_LEFT);
        	std::cout << "left" <<std::endl;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_RIGHT);
        	std::cout << "right" <<std::endl;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_UP);
        	std::cout << "up" <<std::endl;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_DOWN);
        	std::cout << "down" <<std::endl;
        }
        else
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_NONE);
        }
		
		if(event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::M)
			{
				s->toggleMute();
			}
		}
    }
}
