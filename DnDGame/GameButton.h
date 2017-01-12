#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


class GameButton
{
public:

	GameButton();
	GameButton(sf::Vector2f size, sf::Vector2f position);
	~GameButton();


private:

	sf::RectangleShape shape;
	int x1, x2, x3, x4, y1, y2, y3, y4;

};

