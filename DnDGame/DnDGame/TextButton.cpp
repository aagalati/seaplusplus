#include "stdafx.h"
#include "TextButton.h"
#include <SFML\Graphics.hpp>
#include "GameButton.h"

TextButton::TextButton(){



}

TextButton::TextButton(sf::Vector2f size, sf::Vector2f position, std::string buttonname, sf::Font font) 
: GameButton(size, position, sf::Color::White)
{
	
	name.setFont(font);
	name.setFillColor(sf::Color::Black);
	name.setCharacterSize(20);
	name.setString("Hello");
	name.setPosition(position.x + 20, position.y);

}

sf::Text TextButton::drawText() {

	return name;

}

TextButton::~TextButton()
{



}
