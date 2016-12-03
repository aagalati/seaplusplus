#include "stdafx.h"
#include "AllItemDisplay.h"


AllItemDisplay::AllItemDisplay()
{

	_tilesize.x = 32;
	_tilesize.y = 32;

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeons and Dragons");

	loadFonts();
	loadTextures();
	loadItems();

	numofmovebuttons = 3;
	moveButtons.resize(numofmovebuttons);

	currentShow = 0;

	itemDisplay();

}


AllItemDisplay::~AllItemDisplay()
{
}

void AllItemDisplay::loadItems()
{

	Item* item = new Item();

	ItemContainer* temp = new ItemContainer();

	container = temp->load(0);


}

void AllItemDisplay::displayfour(int a) {

	int count = 0;
	int typevalue;
	for (int i = a; i < container->contained.size() && count < 4; i++) {
		count++;
		itemname[i].setString(container->contained[i]->toString());
		typevalue = container->contained[i]->getIntItemType();
		source = typevalue - 1;
		itempack[i].setTextureRect(sf::IntRect(0, _tilesize.y*source, _tilesize.x, _tilesize.y));
		
		itemname[i].setFont(font);
		itemname[i].setFillColor(sf::Color::White);
		itemname[i].setCharacterSize(20);

		itempack[i].setPosition(_windowsize.x / 2 - _tilesize.x / 2, 100*i);
		itemname[i].setPosition(_windowsize.x / 2 - _tilesize.x / 2, 100 * i + _tilesize.y * 2);

		_window.draw(itempack[i]);
		_window.draw(itemname[i]);

	}

}

void AllItemDisplay::drawMoveButtons() {

	sf::Text buttonname;
	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::Black);
	buttonname.setCharacterSize(20);

	for (int i = 0; i < numofmovebuttons; i++) {

		buttonname.setPosition(moveButtons[i]->getPosition());
		buttonname.setString(moveButtons[i]->getText());

		_window.draw(moveButtons[i]->draw());
		_window.draw(buttonname);

	}

}


void AllItemDisplay::itemDisplay()
{

	string bname;
	sf::Color color;

	//Making buttons

	for (int i = 0; i < numofmovebuttons; i++) {
		switch (i) {
		case 0: bname = "Previous";
			_buttonsize.x = 100;
			_buttonsize.y = 50;
			_buttonposition.x = 200;
			_buttonposition.y = 500;
			color = sf::Color(30, 155, 0, 255);
			break;
		case 1:	bname = "Next";
			_buttonsize.x = 100;
			_buttonsize.y = 50;
			_buttonposition.x = 700;
			_buttonposition.y = 500;
			color = sf::Color(0, 165, 180, 255);
			break;
		case 2: bname = "Exit";
			_buttonsize.x = 100;
			_buttonsize.y = 50;
			_buttonposition.x = 450;
			_buttonposition.y = 500;
			color = sf::Color(190, 30, 0, 255);
			break;
		default: bname = "Button!";

		}

		moveButtons[i] = new GameButton(_buttonsize, _buttonposition, bname, color);

	}

	update();

}


void AllItemDisplay::run() {

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

void AllItemDisplay::buttonAction(int x, int y, bool isclick) {

	for (int i = 0; i < numofmovebuttons; i++) {

		if (isclick) {

			if (moveButtons[i]->isClicked(x, y)) {
				switch (i) {
				case 0: if (currentShow != 0)
							currentShow -= 4;
					break;
				case 1: if (currentShow + 4 < container->contained.size())
							currentShow += 4;
					break;
				case 2: _window.close();
					break;
				}
				//std::cout << "You clicked button " << i << std::endl;
			}

		}
		else {

			if (moveButtons[i]->isClicked(x, y)) {
				moveButtons[i]->changeColor(sf::Color(150, 150, 150, 255));
				update();
			}
			else {
				moveButtons[i]->changeColorDefault();
				update();
			}

		}

	}

}


void AllItemDisplay::update() {

	_window.clear();
	drawMoveButtons();
	displayfour(currentShow);
	_window.display();

}


