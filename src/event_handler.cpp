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
        		m_gst->startPlaying();
        	}
        	//show control when C is pressed
        	else if(event.key.code == sf::Keyboard::C)
        	{
        		m_gst->setGameState(STATE_CONTROLS);
        	}
        }
        if ( m_gst->getGameState() == STATE_PAUSE || m_gst->getGameState() == STATE_CONTROLS)
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
        	m_gst->startShop();
        }
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_gst->getGameState() == STATE_SHOP)
		{
			m_gst->buyUpgrade(sf::Mouse::getPosition(*m_wnd));
		}

        // Get robot direction
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_LEFT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_RIGHT);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_UP);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
        	m_gst->setPlayerMovementDirection(DIRECTION_DOWN);
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
