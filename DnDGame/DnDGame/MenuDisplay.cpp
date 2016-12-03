#include "stdafx.h"
#include "MenuDisplay.h"


MenuDisplay::MenuDisplay() : Display()
{
	
	PADDINGX = 50; 
	PADDINGY = 50;

	_headersize.x = _windowsize.x*0.5;
	_headersize.y = _windowsize.y*0.1;

	_buttonsize.x = _windowsize.x*0.30;
	_buttonsize.y = _windowsize.y*0.05;

	_headerposition.x = _windowsize.x*0.25;
	_headerposition.y = _windowsize.y*0.05;

	_buttonposition.x = _windowsize.x*0.5 - _buttonsize.x*0.5;
	_buttonposition.y = PADDINGY + _headerposition.y + _headersize.y;

	loadFonts();
	
	numofbuttons = 5;
	buttons.resize(numofbuttons);

	exitType = 3;

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeons and Dragons (Menu)");


	menuDisplay();

}


void MenuDisplay::menuDisplay() {

	//header
	//play game
	//item encyclopedia
	//map creator

	string bname;

	//Making buttons

	for (int i = 0; i < numofbuttons; i++) {
		switch (i) {
		case 0: bname = "Play Game";
			break;
		case 1:	bname = "Item Encyclopedia";
			break;
		case 2: bname = "Map Maker";
			break;
		case 3: bname = "Character Maker";
			break;
		case 4: bname = "Exit";
			break;
		default: bname = "Button!";

		}
		
		buttons[i] = new GameButton(_buttonsize, _buttonposition, bname, sf::Color::White);
		_buttonposition.y += 60;

	}

	update();

}

void MenuDisplay::drawHeader() {

	sf::RectangleShape header(_headersize);
	header.setPosition(_headerposition);

	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::Black);
	buttonname.setCharacterSize(20);
	buttonname.setString("Dungeons and Dragons!");
	buttonname.setPosition(_headerposition.x + _headersize.x*0.25 + 10, _headerposition.y + 15);

	_window.draw(header);
	_window.draw(buttonname);

}

void MenuDisplay::drawButtons() {

	sf::Text buttonname;
	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::Black);
	buttonname.setCharacterSize(20);

	for (int i = 0; i < numofbuttons; i++) {

		buttonname.setPosition(buttons[i]->getPosition());
		buttonname.setString(buttons[i]->getText());

		_window.draw(buttons[i]->draw());
		_window.draw(buttonname);

	}

}

void MenuDisplay::update() {

	_window.clear();
	drawHeader();
	drawButtons();
	_window.display();

}

void MenuDisplay::run() {

	while (_window.pollEvent(_event)) {

		switch (_event.type) {

		case sf::Event::Closed:
			_window.clear();
			exitType = 4;
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

void MenuDisplay::buttonAction(int x, int y, bool isclick) {

	for (int i = 0; i < numofbuttons; i++) {

		if (isclick) {

			if (buttons[i]->isClicked(x, y)) {
				exitType = i;
				_window.close();
				//std::cout << "You clicked button " << i << std::endl;
			}

		} else {

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

int MenuDisplay::getExitType() {

	return exitType;

}

MenuDisplay::~MenuDisplay()
{
}
