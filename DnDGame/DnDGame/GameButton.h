#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


class GameButton
{
public:

	GameButton();
	GameButton(sf::Vector2f size, sf::Vector2f position);
	GameButton(sf::Vector2f size, sf::Vector2f position, std::string name);
	~GameButton();
	
	void changeColor(sf::Color color);

	sf::RectangleShape draw();
	
	std::string getText();
	sf::Vector2f getPosition();

	bool isClicked(int x, int y);


private:

	sf::RectangleShape shape;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	std::string buttonname;

};

