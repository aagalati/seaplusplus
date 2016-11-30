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

	//coordinates are in clockwise order

	//XPOSITION
	x1 = position.x;  //top left
	x2 = position.x + size.x; //top right
	x3 = x2; //bottom right
	x4 = x1; //bottom left
	//YPOSITION
	y1 = position.y; //top left
	y2 = y1; //top right
	y3 = position.y + size.y; //bottom right
	y4 = y3; //bottom left


}

bool GameButton::isClicked(int x, int y) {

	if (x > x1 && x < x2 && y > y1 && y < y3) {
		return true;
	}

	return false;
}

sf::RectangleShape GameButton::draw() {

	return shape;

}

GameButton::~GameButton()
{

}
