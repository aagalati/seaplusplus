#include "stdafx.h"
#include "MenuDisplay.h"


MenuDisplay::MenuDisplay()
{
	//_type = menu;

	BORDER_SIZE = 1;
	BORDER = BORDER_SIZE * 2;
	PADDINGX = 50;
	PADDINGY = 50;

	_tilesource.x = 32;
	_tilesource.y = Wall;

	_tilesize.x = 32;
	_tilesize.y = 32;

	_windowsize.x = 1000;
	_windowsize.y = 600;

	_headersize.x = _windowsize.x*0.5;
	_headersize.y = _windowsize.y*0.1;

	_buttonsize.x = _windowsize.x*0.30;
	_buttonsize.y = _windowsize.y*0.05;

	_headerposition.x = _windowsize.x*0.25;
	_headerposition.y = _windowsize.y*0.05;

	_buttonposition.x = _windowsize.x*0.5 - _buttonsize.x*0.5;
	_buttonposition.y = PADDINGY + _headerposition.y + _headersize.y;

	loadFonts();
	
	numofbuttons = 4;

	

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeons and Dragons (Menu)");
	//_window.setKeyRepeatEnabled(false);

	menuDisplay();

}


void MenuDisplay::menuDisplay() {

	//header
	//play game
	//item encyclopedia
	//map creator

	string bname;
	buttons.resize(numofbuttons);

	//MAKING HEADER
		sf::RectangleShape header(_headersize);
		header.setPosition(_headerposition);
		
		buttonname.setFont(font);
		buttonname.setFillColor(sf::Color::Black);
		buttonname.setCharacterSize(20);
		buttonname.setString("Dungeons and Dragons!");
		buttonname.setPosition(_headerposition.x + _headersize.x*0.25 + 10, _headerposition.y + 15);

		_window.draw(header);
		_window.draw(buttonname);
	//HEADER IS MADE



	//Making buttons

	for (int i = 0; i < numofbuttons; i++) {
		switch (i) {
		case 0: bname = "Play Game";
			break;
		case 1:	bname = "Item Encyclopedia";
			break;
		case 2: bname = "Map Maker";
			break;
		case 3: bname = "Exit";
			break;
		default: bname = "Button!";

		}
		
		buttons[i] = new GameButton(_buttonsize, _buttonposition, bname);
		_buttonposition.y += 60;

	}

	drawButtons();
	_window.display();

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

	drawButtons();

}

void MenuDisplay::run() {

	while (_window.pollEvent(_event)) {

		switch (_event.type) {

		case sf::Event::Closed:
			_window.close();
			break;

			case sf::Event::MouseMoved:
				//std::cout << "X: " << _event.mouseMove.x << " Y: " << _event.mouseMove.y << std::endl;
				//buttonAction(_event.mouseMove.x, _event.mouseMove.y, false);
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

		}

	}

}

int MenuDisplay::getExitType() {

	return exitType;

}

MenuDisplay::~MenuDisplay()
{
}
