#include "sound_handler.h"
//Singleton Class


//constructor
SoundHandler::SoundHandler()
{
	bgVolume = 100;
	muted = 0;
	soundVolume = 100;
	loadBuffers();
	
}



								
SoundHandler* SoundHandler::s = NULL;

SoundHandler* SoundHandler::getSoundHandler()
{
	// if there is no SoundHandler build new one
	if(s == NULL)
	{
		s = new SoundHandler;
		s->loadBuffers();
		
	}
	
	return s;
}



void SoundHandler::playSound(int soundNumber)
{
	if(!muted)
	{
		int pitch = 1;
		switch(soundNumber) {
			case SOUND_INTRO:
			sound.setBuffer(introSound);
			break;
			
			case SOUND_FFF:
			sound.setBuffer(FFF);
			break;
		}

		sound.setVolume(soundVolume);
		sound.play();
	}
}


void SoundHandler::playBg()
{
	bgMusic.setBuffer(bgMusicBuff);
	
	bgMusic.setLoop(true);
	bgMusic.setVolume(bgVolume);
	bgMusic.play();
	std::cout<<"playbg\n";
}



void SoundHandler::toggleMute()
{
	
	bgMusic.setVolume(muted * bgVolume); 
	muted ^= 1; //invertieren
}


void SoundHandler::setBgVolume(float volume)
{
	bgVolume = volume;
	bgMusic.setVolume(volume);
}


void SoundHandler::setSoundVolume(float volume)
{
	soundVolume = volume;
}

void SoundHandler::loadBuffers()
{
	bgMusicBuff.loadFromFile("sfx/bg/maintheme.ogg");
	introSound.loadFromFile("sfx/rocky_sadder.ogg");
	FFF.loadFromFile("sfx/FFFJingle.ogg");
	start.loadFromFile("sfx/start.ogg");
}

void SoundHandler::del()
{
	delete s;
}
