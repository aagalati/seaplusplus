#pragma once
#include "GameButton.h"


class TextButton : public GameButton
{
public:
	TextButton();
	TextButton(sf::Vector2f size, sf::Vector2f position, std::string buttonname, sf::Font font);
	~TextButton();

	sf::Text drawText();

private:
	sf::Text name;
};

