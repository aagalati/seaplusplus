#include "stdafx.h"
#include "TextButton.h"


TextButton::TextButton(sf::Vector2f size, sf::Vector2f position, std::string buttonname, sf::Font font)
{
	GameButton(size, position);
	name.setFont(font);
	name.setFillColor(sf::Color::Black);
	name.setCharacterSize(20);
	name.setString(buttonname);

}


TextButton::~TextButton()
{
}
