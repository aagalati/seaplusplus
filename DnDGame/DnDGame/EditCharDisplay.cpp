#include "stdafx.h"
#include "EditCharDisplay.h"


EditCharDisplay::EditCharDisplay()
{

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeons and Dragons (Menu)");

	numoftypebuttons = 3;
	typeButtons.resize(numoftypebuttons);

	loadFonts();
	setFonts();
	placeText();
	typeDisplay();
	update();

}

void EditCharDisplay::setFonts() {

	titlename.setFont(font);
	titlename.setFillColor(sf::Color::White);
	titlename.setCharacterSize(20);

	inputname.setFont(font);
	inputname.setFillColor(sf::Color::White);
	inputname.setCharacterSize(20);

	titlelevel.setFont(font);
	titlelevel.setFillColor(sf::Color::White);
	titlelevel.setCharacterSize(20);

	inputlevel.setFont(font);
	inputlevel.setFillColor(sf::Color::White);
	inputlevel.setCharacterSize(20);

	stats.setFont(font);
	stats.setFillColor(sf::Color::White);
	stats.setCharacterSize(20);

}

void EditCharDisplay::placeText() {

	titlename.setPosition(50, 50);
	titlename.setString("Name:");
	inputname.setPosition(115, 50);

	titlelevel.setPosition(350, 50);
	titlelevel.setString("Enter Level:");
	inputlevel.setPosition(475, 50);

	stats.setPosition(50, 200);

}

void EditCharDisplay::drawText() {

	_window.draw(titlename);
	_window.draw(inputname);
	_window.draw(titlelevel);
	_window.draw(inputlevel);
	_window.draw(stats);

}

void EditCharDisplay::typeDisplay() {

	string bname;
	sf::Color color;

	//Making buttons

	for (int i = 0; i < numoftypebuttons; i++) {
		switch (i) {
		case 0: bname = "Bully";
			_buttonsize.x = 150;
			_buttonsize.y = 75;
			_buttonposition.x = 50;
			_buttonposition.y = 100;
			color = sf::Color(30, 155, 0, 255);
			break;
		case 1:	bname = "Nimble";
			_buttonsize.x = 150;
			_buttonsize.y = 75;
			_buttonposition.x = 250;
			_buttonposition.y = 100;
			color = sf::Color(0, 165, 180, 255);
			break;
		case 2: bname = "Tank";
			_buttonsize.x = 150;
			_buttonsize.y = 75;
			_buttonposition.x = 450;
			_buttonposition.y = 100;
			color = sf::Color(190, 30, 0, 255);
			break;
		default: bname = "Button!";

		}

		typeButtons[i] = new GameButton(_buttonsize, _buttonposition, bname, color);

	}

}

void EditCharDisplay::drawButtons() {

	sf::Text buttonname;
	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::Black);
	buttonname.setCharacterSize(20);

	for (int i = 0; i < numoftypebuttons; i++) {

		buttonname.setPosition(typeButtons[i]->getPosition().x + 25, typeButtons[i]->getPosition().y + 25);
		buttonname.setString(typeButtons[i]->getText());

		_window.draw(typeButtons[i]->draw());
		_window.draw(buttonname);

	}

}

void EditCharDisplay::run() {

	while (_window.pollEvent(_event)) {

		switch (_event.type) {

		case sf::Event::Closed:
			_window.clear();
			_window.close();
			break;

		case sf::Event::TextEntered:
			if (_event.text.unicode >= 65 && _event.text.unicode <= 122) {
				name += (char)_event.text.unicode;
			}
			else if (_event.text.unicode >= 48 && _event.text.unicode <= 57) {
				level += (char)_event.text.unicode;
			}
			else if (_event.text.unicode == 8 && name.size() > 0) {
				name.erase(name.size() - 1, name.size());
			}
			else if (_event.text.unicode == 129 && level.size() > 0) {
				level.erase(level.size() - 1, level.size());
			}
			inputname.setString(name);
			inputlevel.setString(level);
			update();
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


void EditCharDisplay::buttonAction(int x, int y, bool isclick) {

	for (int i = 0; i < numoftypebuttons; i++) {

		if (isclick) {

			if (typeButtons[i]->isClicked(x, y)) {
				int l;
				FighterDirector fd;
				switch (i) {
				case 0:
					fd.setCharacterBuilder(bs);
					l = std::stoi(level);
					fd.constructCharacter(l);
					ch = fd.getCharacter();
					getStats();
					break;
				case 1: 
					fd.setCharacterBuilder(ba);
					l = std::stoi(level);
					fd.constructCharacter(l);
					ch = fd.getCharacter();
					getStats();
					break;
				case 2: 
					fd.setCharacterBuilder(bb);
					std::string::size_type sz;
					l = std::stoi(level);
					fd.constructCharacter(l);
					ch = fd.getCharacter();
					getStats();
					break;
				}
				//std::cout << "You clicked button " << i << std::endl;
			}

		}
		else {

			if (typeButtons[i]->isClicked(x, y)) {
				typeButtons[i]->changeColor(sf::Color(150, 150, 150, 255));
				update();
			}
			else {
				typeButtons[i]->changeColorDefault();
				update();
			}

		}

	}

}

void EditCharDisplay::getStats() {

	stats.setString(ch->toString());

}

void EditCharDisplay::update() {

	_window.clear();
	drawButtons();
	drawText();
	_window.display();

}

EditCharDisplay::~EditCharDisplay()
{
}
