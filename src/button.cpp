#include "button.h"


Button::Button(){}

Button::Button(sf::Vector2f position,sf::Vector2f bounds,std::string text,std::string assetPath)
{
	this->position = position;
//	this->assetPath = assetPath;
	this->text = text;
	this->bounds = bounds;
   	if (!texture.loadFromFile(assetPath))
	{
    	//TODO
    }
}

void Button::draw(sf::RenderTarget& target,sf::RenderStates states)const
{	sf::Font font;
	 if (!font.loadFromFile("assets/Roboto-Bold.ttf"))
    {
    	//m_wnd->close();
    }
	sf::Sprite sprite_button;
	sprite_button.setTexture(texture);
	sprite_button.setPosition(position);
	target.draw(sprite_button,states);
	
	sf::Text text_button;
	text_button.setFont(font);
	text_button.setColor(sf::Color::Black);
	text_button.setString(text);
	text_button.setCharacterSize(30);
	text_button.setPosition(position+sf::Vector2f(20,5));
	target.draw(text_button,states);
		
}

bool Button::checkClick(sf::Vector2i click)
{
	sf::Vector2f click2f =(sf::Vector2f) click;
	std::cout << click.x << "  " << click.y << "\n";
	if(click2f.x >= position.x && click2f.y >= position.y && click2f.x < position.x + bounds.x && click2f.y < position.y + bounds.y)
	{
		std::cout<<"treffer\n";
		return true;
	}
	//std::cout<<"kein treffer\n";
	return false;
}
