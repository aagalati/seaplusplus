#include "stdafx.h"
#include "Display.h"
#include "Grid.h"
#include "DNDObject.h"
#include <string>


Display::Display(Grid *grid, int type)   //!!GAME
{

	_type = game;

	BORDER_SIZE = 1;
	BORDER = BORDER_SIZE * 2;
	PADDINGX = 32;
	PADDINGY = 32;

	_type = type;

	this->grid = new Grid(grid);  //copy  constructor

	_width = this->grid->getWidth() + BORDER;  //setting up the game grid
	_height = this->grid->getHeight() + BORDER;

	_playerX = this->grid->getEntranceX();
	_playerY = this->grid->getEntranceY();

	_tilesource.x = 32;
	_tilesource.y = Wall;

	_tilesize.x = 32;
	_tilesize.y = 32;

	_windowsize.x = 1000;
	_windowsize.y = 600;

	loadFonts();
	loadTextures();
	loadSprites();

	
	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeouns and Dragons");
	//_window.setKeyRepeatEnabled(false);

	if (_type == 2) {

		_buttonsize.x = _windowsize.x*0.15;
		_buttonsize.y = _windowsize.y*0.15;

		_buttonposition.x = _buttonposition.x = _width*_tilesize.x + BORDER_SIZE + PADDINGX;
		_buttonposition.y = PADDINGY + _headerposition.y;

		builderDisplay();

	}


}

Display::Display()   //!!MENU
{

	_type = menu;

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
	_buttonposition.y = PADDINGY + _headerposition.y;

	loadFonts();	

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeons and Dragons (Menu)");
	//_window.setKeyRepeatEnabled(false);

	menuDisplay();

}

void Display::builderDisplay() {

	button1.setSize(_buttonsize); //setting buttons for the builder
	button2.setSize(_buttonsize); 
	button3.setSize(_buttonsize);
	button4.setSize(_buttonsize);

	update(); 

	_window.display();

}

void Display::menuDisplay() {
	
	//header
	//play game
	//item encyclopedia
	//map creator

	sf::RectangleShape header(_headersize);
	header.setPosition(_headerposition);


	button1.setSize(_buttonsize);
	button2.setSize(_buttonsize);   //putting the buttons and boxes in place for a nice GUI
	button3.setSize(_buttonsize);
	button4.setSize(_buttonsize);

	sf::Text buttonname;  //generate butttonname and set its attributes
	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::Black);
	buttonname.setCharacterSize(20);

	buttonname.setString("Dungeons and Dragons!");
	buttonname.setPosition(_headerposition.x + _headersize.x*0.25 + 10, _headerposition.y + 15);

	_window.draw(header);  
	_window.draw(buttonname);

	for (int i = 0; i < 4; i++) {

		std::cout << "drawing button: " << i << std::endl;

		_buttonposition.y = PADDINGY + _buttonsize.y*i * 2 + _headerposition.y + _headersize.y;

		if (i == 0) {
			button1.setPosition(_buttonposition);
			button1.setFillColor(sf::Color::Cyan);
			button1.setOutlineThickness(4);
			button1.setOutlineColor(sf::Color::Blue);

			buttonname.setString("Play Game");
			buttonname.setPosition(_buttonposition.x + 20, _buttonposition.y);

			_window.draw(button1);
			_window.draw(buttonname);
		}

		else if (i == 1) {
			button2.setPosition(_buttonposition);
			button2.setFillColor(sf::Color::Cyan);
			button2.setOutlineThickness(4);
			button2.setOutlineColor(sf::Color::Blue);

			buttonname.setString("Item Encyclopedia");
			buttonname.setPosition(_buttonposition.x + 20, _buttonposition.y);

			_window.draw(button2);
			_window.draw(buttonname);
		}

		else if (i == 2) {
			button3.setPosition(_buttonposition);
			button3.setFillColor(sf::Color::Cyan);
			button3.setOutlineThickness(4);
			button3.setOutlineColor(sf::Color::Blue);

			buttonname.setString("Map Maker");
			buttonname.setPosition(_buttonposition.x + 20, _buttonposition.y);

			_window.draw(button3);
			_window.draw(buttonname);
		}

		else if (i == 3) {
			button4.setPosition(_buttonposition);
			button4.setFillColor(sf::Color::Cyan);
			button4.setOutlineThickness(4);
			button4.setOutlineColor(sf::Color::Blue);

			buttonname.setString("Exit");
			buttonname.setPosition(_buttonposition.x + 20, _buttonposition.y);

			_window.draw(button4);
			_window.draw(buttonname);
		}

	}

	_window.display();

}

void Display::buttonAction(int x, int y, bool isClick) {

	//if (isClick)
		//std::cout << "clicked at x: " << x << " y: " << y << std::endl;
	//else
		//std::cout << "moved at x: " << x << " y: " << y << std::endl;


	//std::cout << "Position XLeft: " << button1.getPosition().x << " Position XRight: " << button1.getPosition().x + _buttonsize.x << " Position YUp: " << button1.getPosition().y << " Position YDown" << button1.getPosition().y + _buttonsize.y << std::endl;
	if (isClick) {
		if (x > button1.getPosition().x && x < button1.getPosition().x + _buttonsize.x && y > button1.getPosition().y && y < button1.getPosition().y + _buttonsize.y) {
			goplay = true;
			_window.close();
		}

		if (x > button2.getPosition().x && x < button2.getPosition().x + _buttonsize.x && y > button2.getPosition().y && y < button2.getPosition().y + _buttonsize.y) {
			goitem = true;
			_window.close();
		}

		if (x > button3.getPosition().x && x < button3.getPosition().x + _buttonsize.x && y > button3.getPosition().y && y < button3.getPosition().y + _buttonsize.y) {
			gobuilder = true;
			_window.close();
		}

		if (x > button4.getPosition().x && x < button4.getPosition().x + _buttonsize.x && y > button4.getPosition().y && y < button4.getPosition().y + _buttonsize.y) {
			goexit = true;
			_window.close();
		}
	}

}

void Display::loadTextures() {

	if (!tileTexture.loadFromFile("texture/tiletexture.png"))   //load and verify textures
		std::cout << "Error: Tile texture not loaded" << std::endl;
	else
		std::cout << "Tile texture loaded.." << std::endl;

	if (!borderTexture.loadFromFile("texture/bordertexture.png"))  //load and verify textures
		std::cout << "Error: Border texture not loaded" << std::endl;
	else
		std::cout << "Border texture loaded.." << std::endl;

}

void Display::loadFonts() {

	if (!font.loadFromFile("texture/framd.ttf"))
		std::cout << "Error: Font not loaded" << std::endl;
	else
		std::cout << "Font loaded.. " << std::endl;

}

void Display::loadSprites() {

	_tilemap.resize(_width);

	for (int i = 0; i < _width; i++) {     //for loop to instantiate all the sprites and apply textures to them

		_tilemap[i].resize(_height);
		//std::cout << i << std::endl;

		for (int j = 0; j < _height; j++) {

			if (i == 0 || j == 0 || i == _width - 1 || j == _height - 1) {

				_tilemap[i][j].setTexture(borderTexture);  //setting border texture

														  //This line is for single box texture
														  //tilemap[i][j].setTextureRect(sf::IntRect(0, 32, 32, 32));

														  //std::cout << "Creating border at " << i << ", " << j << std::endl;

														  //THIS CODE IS FOR FRAMED BORDER

				if (i == 0 && j == 0)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * tlcorner, _tilesize.x, _tilesize.y));

				else if (j == 0 && (i != _width - 1 && i != 0))
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * top, _tilesize.x, _tilesize.y));

				else if (i == _width - 1 && j == 0)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * trcorner, _tilesize.x, _tilesize.y));

				else if (i == _width - 1 && j != 0 && j != _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * right, _tilesize.x, _tilesize.y));

				else if (i == _width - 1 && j == _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * brcorner, _tilesize.x, _tilesize.y));

				else if (i != 0 && j == _height - 1 && i != _width - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * bottom, _tilesize.x, _tilesize.y));

				else if (i == 0 && j == _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * blcorner, _tilesize.x, _tilesize.y));

				else if (i == 0 && j != 0 && j != _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize.y * left, _tilesize.x, _tilesize.y));

			}
			else {


				_tilemap[i][j].setTexture(tileTexture);
				//std::cout << "Creating tile at " << i << ", " << j << std::endl;
				int cellValue;
				cellValue = grid->getCellValue(i - 1, j - 1)->type();   //using enum types, refer to grid to apply corresponding textures
				if (cellValue == Space)
					_tilesource.y = Space;
				else if (cellValue == Wall)
					_tilesource.y = Wall;
				else if (cellValue == Object)
					_tilesource.y = Object;
				else if (cellValue == Entrance)
					_tilesource.y = Entrance;
				else if (cellValue == Exit)
					_tilesource.y = Exit;
				else if (cellValue == Player)
					_tilesource.y = Player;

				//std::cout << "Texture will be " << tilesource.y << std::endl;

				_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesource.y * _tilesize.y, _tilesize.x, _tilesize.x));
			}

			_tilemap[i][j].setPosition(_tilesize.x * i + PADDINGX, _tilesize.y * j + PADDINGY);  //setting position

		}



	}

	update();

}

void Display::update() {

	if (_type == 1 || _type == 2) {



		std::cout << "Update called in display" << std::endl;
		std::cout << "PlayerX: " << _playerX << ", Player Y: " << _playerY << std::endl;
		//grid->printMapImage();

		for (int i = 0; i < _width; i++) {

			for (int j = 0; j < _height; j++) {

				if (!(i == 0 || j == 0 || i == _width - 1 || j == _height - 1)) {

					int cellValue;
					cellValue = grid->getCellValue(i - 1, j - 1)->type();  //refreshing map, rechecking all values
					if (cellValue == Space)
						_tilesource.y = Space;
					else if (cellValue == Wall)
						_tilesource.y = Wall;
					else if (cellValue == Object)
						_tilesource.y = Object;
					else if (cellValue == Entrance)
						_tilesource.y = Entrance;
					else if (cellValue == Exit)
						_tilesource.y = Exit;
					else if (cellValue == Player)
						_tilesource.y = Player;

					//std::cout << "Texture will be " << tilesource.y << std::endl;

					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesource.y * _tilesize.y, _tilesize.x, _tilesize.y));

				}

				_window.draw(_tilemap[i][j]);
			}

		}

	}
	
	if (_type == 2) {
		for (int i = 0; i < 4; i++) {

			//std::cout << "drawing button: " << i << std::endl;

			_buttonposition.y = PADDINGY + _buttonsize.y*i*1.1 + _headerposition.y + _headersize.y;

			if (i == 0) {
				button1.setPosition(_buttonposition);
				button1.setFillColor(sf::Color::Black);
				button1.setOutlineThickness(4);
				button1.setOutlineColor(sf::Color::White);

				_window.draw(button1);
			}

			else if (i == 1) {
				button2.setPosition(_buttonposition);
				button2.setFillColor(sf::Color(139,69,19));
				button2.setOutlineThickness(4);
				button2.setOutlineColor(sf::Color::White);

				_window.draw(button2);
			}

			else if (i == 2) {
				button3.setPosition(_buttonposition);
				button3.setFillColor(sf::Color::Green);
				button3.setOutlineThickness(4);
				button3.setOutlineColor(sf::Color::White);

				_window.draw(button3);
			}

			else if (i == 3) {
				button4.setPosition(_buttonposition);
				button4.setFillColor(sf::Color::Red);
				button4.setOutlineThickness(4);
				button4.setOutlineColor(sf::Color::White);

				_window.draw(button4);
			}

		}
	}

	_window.display();

}

bool Display::windowOpen() {

	return _window.isOpen();

}

void Display::run() {

	if (_type == 2) 
	update();

	while (_window.pollEvent(_event)) {

		if (_type == 1) {

			switch (_event.type) {

			case sf::Event::Closed:
				delete this;
				_window.close();
				break;

			case sf::Event::KeyPressed:
				std::cout << "Key Pressed" << std::endl;
				keyPressed(_event);
				break;

			case sf::Event::MouseMoved:
				//std::cout << "X: " << _event.mouseMove.x << " Y: " << _event.mouseMove.y << std::endl;
				gridHover(_event.mouseMove.x, _event.mouseMove.y);
				break;

			}
		}

		if (_type == 2) {

			switch (_event.type) {

			case sf::Event::Closed:
				delete this;
				_window.close();
				break;

			case sf::Event::MouseButtonPressed:
				//std::cout << "Clicked at X: " << _event.mouseButton.x << " Y: " << _event.mouseButton.y << std::endl;
				if (_event.mouseButton.button == sf::Mouse::Left) {
					gridHover(_event.mouseButton.x, _event.mouseButton.y);
				}
				break;

			}
		}

			if (_type == 0) {
				switch (_event.type) {

				case sf::Event::Closed:
					//delete this;
					_window.close();
					break;

				//case sf::Event::MouseMoved:
					//std::cout << "X: " << _event.mouseMove.x << " Y: " << _event.mouseMove.y << std::endl;
					//buttonAction(_event.mouseMove.x, _event.mouseMove.y, false);
					//break;

				case sf::Event::MouseButtonPressed:
					//std::cout << "Clicked at X: " << _event.mouseButton.x << " Y: " << _event.mouseButton.y << std::endl;
					if (_event.mouseButton.button == sf::Mouse::Left) {
						buttonAction(_event.mouseButton.x, _event.mouseButton.y, true);
					}
					break;
				}

			}

		}
		
	}

void Display::gridHover(int x, int y) { //this function needs the actual object to display the info

	//std::cout << "Hover X: " << (x - PADDINGX - BORDER_SIZE*_tilesize.x)/_tilesize.x << " Hover Y: " << (y - PADDINGY - BORDER_SIZE*_tilesize.y) / _tilesize.y << std::endl;

	//std::cout << grid->getCellValue((x - PADDINGX - BORDER_SIZE*_tilesize.x) / _tilesize.x, (y - PADDINGY - BORDER_SIZE*_tilesize.y) / _tilesize.y) << std::endl;

	if(_type == 2)
		grid->setCell((x - PADDINGX - BORDER_SIZE*_tilesize.x) / _tilesize.x, (y - PADDINGY - BORDER_SIZE*_tilesize.y) / _tilesize.y, 1);

	if (_type == 1)
	showInfo(grid->getCellValue((x - PADDINGX - BORDER_SIZE*_tilesize.x) / _tilesize.x, (y - PADDINGY - BORDER_SIZE*_tilesize.y) / _tilesize.y));

} 

void Display::showInfo(DNDObject* hover) {

	std::cout << "Showing Info" << std::endl;
	text.setFont(font);
	text.setString(hover->toString());
	_window.clear();

	/* switch () {

	case 5: 
		text.setString("Player: Arnold\nStats: 2good4u\nClass: classyaf");
		_window.clear();
		break;

	default:
		text.setString("Hover over objects to view stats");
		_window.clear();
		break;

	} */

	text.setCharacterSize(16);
	//text.setColor(sf::Color::White);
	text.setPosition(_width*_tilesize.x + BORDER_SIZE + PADDINGX, BORDER_SIZE + PADDINGY);

	_window.draw(text);
	update();

}

void Display::keyPressed(sf::Event event) {

	switch (event.key.code) {  //this code currently generates double events, not sure why, must fix (events trigger twice, ex. Left Left Right Right)

							   //Checking if moving will be valid, if so, it will trigger the move function which will trigger Subject::Notify

	case sf::Keyboard::Up:
		if (grid->getCellValue(_playerX, _playerY - 1)->type() == 0 || grid->getCellValue(_playerX, _playerY - 1)->type() == 2) {  //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX, _playerY - 1);
			_playerY--;
			update();
			std::cout << "Up" << std::endl;
		}
		if (grid->getCellValue(_playerX, _playerY - 1)->type() == 4)
			_window.close();
		break;

	case sf::Keyboard::Down:
		if (grid->getCellValue(_playerX, _playerY + 1)->type() == 0 || grid->getCellValue(_playerX, _playerY + 1)->type() == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX, _playerY + 1);
			_playerY++;
			update();
			std::cout << "Down" << std::endl;
		}
		if (grid->getCellValue(_playerX, _playerY + 1)->type() == 4)
			_window.close();
		break;

	case sf::Keyboard::Left:
		if (grid->getCellValue(_playerX - 1, _playerY)->type() == 0 || grid->getCellValue(_playerX - 1, _playerY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX - 1, _playerY);
			_playerX--;
			update();
			std::cout << "Left" << std::endl;
		}
		if (grid->getCellValue(_playerX - 1, _playerY)->type() == 4)
			_window.close();
		break;

	case sf::Keyboard::Right:
		if (grid->getCellValue(_playerX + 1, _playerY)->type() == 0 || grid->getCellValue(_playerX + 1, _playerY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX + 1, _playerY);
			_playerX++;
			update();
			std::cout << "Right" << std::endl;
		}
		if (grid->getCellValue(_playerX + 1, _playerY)->type() == 4)
			_window.close();
		break;

	}


}


Display::~Display()
{

}
