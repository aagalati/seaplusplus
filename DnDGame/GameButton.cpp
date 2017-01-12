#include "stdafx.h"
#include "GameButton.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

GameButton::GameButton() {

}

GameButton::GameButton(sf::Vector2f size, sf::Vector2f position)
{

	shape.setSize(size);
	shape.setPosition(position);
	


}


GameButton::~GameButton()
{
}
