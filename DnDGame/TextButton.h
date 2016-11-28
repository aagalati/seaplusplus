#pragma once
#include "GameButton.h"
class TextButton : public GameButton
{
public:
	TextButton(sf::Vector2f size, sf::Vector2f position, std::string buttonname, sf::Font font);
	~TextButton();
private:
	sf::Text name;
};

