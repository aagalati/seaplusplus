#include "stdafx.h"
#include "ItemChoiceDisplay.h"


ItemChoiceDisplay::ItemChoiceDisplay() : Display()
{

	_buttonsize.x = _windowsize.x*0.30;
	_buttonsize.y = _windowsize.y*0.05;


	loadFonts();

	numofbuttons = 3;
	buttons.resize(numofbuttons);

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeons and Dragons");

	choiceDisplay();

}

void ItemChoiceDisplay::choiceDisplay() {

	string bname;
	sf::Color color;

	//Making buttons

	for (int i = 0; i < numofbuttons; i++) {
		switch (i) {
		case 0: bname = "View All";
			_buttonsize.x = 400;
			_buttonsize.y = 300;
			_buttonposition.x = 75;
			_buttonposition.y = 50;
			color = sf::Color(30, 155, 0, 255);
			break;
		case 1:	bname = "Create custom item";
			_buttonsize.x = 400;
			_buttonsize.y = 300;
			_buttonposition.x = 525;
			_buttonposition.y = 50;
			color = sf::Color(0, 165, 180, 255);
			break;
		case 2: bname = "Exit"; 
			_buttonsize.x = 400;
			_buttonsize.y = 150;
			_buttonposition.x = 325;
			_buttonposition.y = 425;
			color = sf::Color(190, 30, 0, 255);
			break;
		default: bname = "Button!";

		}

		buttons[i] = new GameButton(_buttonsize, _buttonposition, bname, color);

	}

}

void ItemChoiceDisplay::drawButtons() {

	sf::Text buttonname;
	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::Black);
	buttonname.setCharacterSize(20);

	for (int i = 0; i < numofbuttons; i++) {

		buttonname.setPosition(buttons[i]->getPosition().x + 25, buttons[i]->getPosition().y + 25);
		buttonname.setString(buttons[i]->getText());

		_window.draw(buttons[i]->draw());
		_window.draw(buttonname);

	}

}

void ItemChoiceDisplay::run() {

	while (_window.pollEvent(_event)) {

		switch (_event.type) {

		case sf::Event::Closed:
			_window.clear();
			_window.close();
			break;

		case sf::Event::MouseMoved:
			//std::cout << "X: " << _event.mouseMove.x << " Y: " << _event.mouseMove.y << std::endl;
			buttonAction(_event.mouseMove.x, _event.mouseMove.y, false);
			break;

		case sf::Event::MouseButtonPressed:
			//std::cout << "Clicked at X: " << _event.mouseButton.x << " Y: " << _event.mouseButton.y << std::endl;
			if (_event.mouseButton.button == sf::Mouse::Left) {
				buttonAction(_event.mouseButton.x, _event.mouseButton.y, true);
			}
			break;
		}
	}
}

void ItemChoiceDisplay::update() {

	_window.clear();
	drawButtons();
	_window.display();

}

void ItemChoiceDisplay::openAll() {

	AllItemDisplay *all = new AllItemDisplay();

	while (all->windowOpen()) {
		all->run();
	}

}

void ItemChoiceDisplay::openEdit() {



}

void ItemChoiceDisplay::buttonAction(int x, int y, bool isclick) {

	for (int i = 0; i < numofbuttons; i++) {

		if (isclick) {

			if (buttons[i]->isClicked(x, y)) {
				switch (i) {
				case 0: openAll();
						break;
				case 1: openEdit();
						break;
				case 2: _window.close();
					break;
				}
				//std::cout << "You clicked button " << i << std::endl;
			}

		}
		else {

			if (buttons[i]->isClicked(x, y)) {
				buttons[i]->changeColor(sf::Color(150, 150, 150, 255));
				update();
			}
			else {
				buttons[i]->changeColorDefault();
				update();
			}

		}

	}

}

int ItemChoiceDisplay::getExitType() {

	return -1;

}

ItemChoiceDisplay::~ItemChoiceDisplay()
{
}
