#include "stdafx.h"
#include "Display.h"
#include "Grid.h"


Display::Display(Grid *grid)
{


	BORDER_SIZE = 1;
	BORDER = BORDER_SIZE * 2;
	PADDING = 32; //need paddingx and paddingy in future

	this->grid = new Grid(*grid);

	_width = this->grid->getWidth() + BORDER;
	_height = this->grid->getHeight() + BORDER;

	_playerX = this->grid->getEntranceX();
	_playerY = this->grid->getEntranceY();

	_tilesource.x = 32;
	_tilesource.y = Wall;

	_tilesize.x = 32;
	_tilesize.y = 32;

	_windowsize.x = 1000;
	_windowsize.y = 600;

	key = true;

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeouns and Dragons");
	_window.setKeyRepeatEnabled(false);

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
				cellValue = grid->getCellValue(i - 1, j - 1);   //using enum types, refer to grid to apply corresponding textures
				if (cellValue == Space)
					_tilesource.y = Space;
				else if (cellValue == Wall)
					_tilesource.y = Wall;
				else if (cellValue == Object)
					_tilesource.y = Space;
				else if (cellValue == Entrance)
					_tilesource.y = Entrance;
				else if (cellValue == Exit)
					_tilesource.y = Exit;
				else if (cellValue == Player)
					_tilesource.y = Player;

				//std::cout << "Texture will be " << tilesource.y << std::endl;

				_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesource.y * _tilesize.y, _tilesize.x, _tilesize.x));
			}

			_tilemap[i][j].setPosition(_tilesize.x * i + PADDING, _tilesize.y * j + PADDING);  //setting position

		}



	}

	update();

}



void Display::update() {

	int cellValue;

	std::cout << "Update called in display" << std::endl;
	std::cout << "PlayerX: " << _playerX << ", Player Y: " << _playerY << std::endl;

	for (int i = 0; i < _width; i++) {

		for (int j = 0; j < _height; j++) {

			if (!(i == 0 || j == 0 || i == _width - 1 || j == _height - 1)) {

				cellValue = grid->getCellValue(i - 1, j - 1);  //refreshing map, rechecking all values
				if (cellValue == Space)
					_tilesource.y = Space;
				else if (cellValue == Wall)
					_tilesource.y = Wall;
				else if (cellValue == Object)
					_tilesource.y = Space;
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

	_window.display();

}

bool Display::windowOpen() {

	return _window.isOpen();

}

void Display::run() {

	while (_window.pollEvent(_event)) {

		if (_event.type == sf::Event::Closed)
			_window.close();

		if (sf::Event::KeyPressed) {
			if (key)
				keyPressed(_event);
			else
				key = true;
		}

	}

}

void Display::keyPressed(sf::Event event) {

	switch (event.key.code) {  //this code currently generates double events, not sure why, must fix (events trigger twice, ex. Left Left Right Right)

							   //Checking if moving will be valid, if so, it will trigger the move function which will trigger Subject::Notify

	case sf::Keyboard::Up:
		if (grid->getCellValue(_playerX, _playerY - 1) == 0 || grid->getCellValue(_playerX, _playerY - 1) == 2) {  //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX, _playerY - 1);
			_playerY--;
			update();
			key = false;
			std::cout << "Up" << std::endl;
		}
		break;

	case sf::Keyboard::Down:
		if (grid->getCellValue(_playerX, _playerY + 1) == 0 || grid->getCellValue(_playerX, _playerY + 1) == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX, _playerY + 1);
			_playerY++;
			update();
			key = false;
			std::cout << "Down" << std::endl;
		}
		break;

	case sf::Keyboard::Left:
		if (grid->getCellValue(_playerX - 1, _playerY) == 0 || grid->getCellValue(_playerX - 1, _playerY) == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX - 1, _playerY);
			_playerX--;
			update();
			key = false;
			std::cout << "Left" << std::endl;
		}
		break;

	case sf::Keyboard::Right:
		if (grid->getCellValue(_playerX + 1, _playerY) == 0 || grid->getCellValue(_playerX + 1, _playerY) == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_playerX, _playerY, _playerX + 1, _playerY);
			_playerX++;
			update();
			key = false;
			std::cout << "Right" << std::endl;
		}
		break;

	}


}


Display::~Display()
{

}
