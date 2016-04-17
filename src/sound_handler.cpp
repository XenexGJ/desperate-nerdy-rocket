#include "sound_handler.h"
//Singleton Class


//constructor
SoundHandler::SoundHandler()
{
	bgVolume = 30;
	muted = 1;
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
			sound.play();
			break;
		}

		sound.setVolume(soundVolume);
		sound.play();
	}
}


void SoundHandler::playBg()
{
	bgMusic.setBuffer(bgMusicBuff);
	bgMusic.play();
	bgMusic.setLoop(true);
	bgMusic.setVolume(bgVolume);
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
	bgMusicBuff.loadFromFile("sfx/bg/sound2.ogg");
	introSound.loadFromFile("sfx/rocky_sadder.ogg");
}

void SoundHandler::del()
{
	delete s;
}
