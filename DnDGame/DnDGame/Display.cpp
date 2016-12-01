#include "stdafx.h"
#include "Display.h"
#include "Grid.h"
#include "DNDObject.h"
#include <string>


int pppGridAutopathInfo[10][10][4] = { 0 };
int gnMoveCount = 0;

Display::Display() {

	_windowsize.x = 1000;
	_windowsize.y = 600;

}

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

	_enemyX = this->grid->getExitX();
	_enemyY = this->grid->getExitY();



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

	goCharacter = FALSE;
	isvisibleEnemy = FALSE;
	bRemoveEnemy = FALSE;
}

void Display::builderDisplay() {

	button1.setSize(_buttonsize); //setting buttons for the builder
	button2.setSize(_buttonsize);
	button3.setSize(_buttonsize);
	button4.setSize(_buttonsize);

	update();

	_window.display();

}

//DELETE AFTER NEW IMPLEMENTAION FROM MENUDISPLAY
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

	if (!tileTexture.loadFromFile("texture/tiletexture2.png"))   //load and verify textures
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
				else if (cellValue == Enemy)
					_tilesource.y = Enemy;

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
					else if (cellValue == Enemy)
						_tilesource.y = Enemy;

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
				button2.setFillColor(sf::Color(139, 69, 19));
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

			case sf::Event::MouseButtonPressed:
				if (_event.mouseButton.button == sf::Mouse::Left) {
					isvisibleEnemy = TRUE;
					MoveHero(_event.mouseButton.x, _event.mouseButton.y);
					if (IsCrash())
					{
						std::cout << "Player Crashed with Enemy !!!!!!!" << std::endl;
						goCharacter = FALSE;
						RemoveHero();
						update();
						isvisibleEnemy = FALSE;
					}
				}
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
	}

	if (goCharacter)
	{
		gnMoveCount++;
		int nResult = AutoSearch();
		if (nResult == 2)
		{
			std::cout << "Map Error!!" << std::endl;
			goCharacter = FALSE;
			isvisibleEnemy = FALSE;
			return;
		}
		else if (nResult == 1)
		{
			std::cout << "Complete!!" << std::endl;
			goCharacter = FALSE;
			isvisibleEnemy = FALSE;
			return;
		}
		else if (nResult == 3)
		{
			std::cout << "Player Crashed with Enemy !!!!!!!" << std::endl;
			goCharacter = FALSE;
			RemoveHero();
			update();
			isvisibleEnemy = FALSE;
			return;
		}
	}
	if (gnMoveCount >= 3)
		goCharacter = false;

	if (isvisibleEnemy)
	{
		ChangeEnemy();
		update();
	}
}

void Display::gridHover(int x, int y) { //this function needs the actual object to display the info

										//std::cout << "Hover X: " << (x - PADDINGX - BORDER_SIZE*_tilesize.x)/_tilesize.x << " Hover Y: " << (y - PADDINGY - BORDER_SIZE*_tilesize.y) / _tilesize.y << std::endl;

										//std::cout << grid->getCellValue((x - PADDINGX - BORDER_SIZE*_tilesize.x) / _tilesize.x, (y - PADDINGY - BORDER_SIZE*_tilesize.y) / _tilesize.y) << std::endl;

	if (_type == 2)
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

	int nResult;

	switch (event.key.code) {  //this code currently generates double events, not sure why, must fix (events trigger twice, ex. Left Left Right Right)

							   //Checking if moving will be valid, if so, it will trigger the move function which will trigger Subject::Notify
	case sf::Keyboard::S:
		goCharacter = TRUE;
		gnMoveCount = 0;
		if (!isvisibleEnemy)
			isvisibleEnemy = TRUE;
		// 		nResult = AutoSearch();
		break;

	case sf::Keyboard::P:
		goCharacter = FALSE;
		break;

	case sf::Keyboard::A:
		// 		if (goCharacter)
	{
		int nOffsetX, nOffsetY;
		nOffsetX = abs(_playerX - _enemyX);
		nOffsetY = abs(_playerY - _enemyY);
		//needs to change in terms of characters' weapon range
		if (nOffsetX <= 1 && nOffsetY <= 1)
		{
			std::cout << "Attack Enemy!!!" << std::endl;
			RemoveEnemy();
			update();
			isvisibleEnemy = FALSE;
			bRemoveEnemy = TRUE;
		}
	}
	break;

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

int Display::AutoSearch()
{
	int nDirect = -1;
	int nLess = 0;
	int nCase = 0;
	int nMoveFlag = 0;

	while (!nMoveFlag)
	{
		Sleep(100);
		while (nDirect == -1)
		{
			if (IsEqual(0) || IsEqual(1))
			{
				srand(time(NULL));
				nDirect = rand() % 4;
			}
			else if (IsEqual(2))
				return 2; // haven't any direction!!
			else
			{
				for (int i = 0; i < 4; i++)
				{
					if (pppGridAutopathInfo[_playerX][_playerY][nLess] > pppGridAutopathInfo[_playerX][_playerY][i])
						nLess = i;
				}
				nDirect = nLess;
			}
		}
		// move to direction
		if (pppGridAutopathInfo[_playerX][_playerY][nDirect] >= 2)
		{
			nDirect = -1;
			return 0;
		}
		pppGridAutopathInfo[_playerX][_playerY][nDirect] ++;

		switch (nDirect)
		{
		case 0: // top
			if (grid->getCellValue(_playerX, _playerY - 1)->type() == 0 || grid->getCellValue(_playerX, _playerY - 1)->type() == 2) {  //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX, _playerY - 1);
				_playerY--;
				update();
				std::cout << "Up" << std::endl;
				pppGridAutopathInfo[_playerX][_playerY][2] ++;
				nMoveFlag = 1;
			}
			else
				nDirect = -1;
			break;

		case 1: // right
			if (grid->getCellValue(_playerX + 1, _playerY)->type() == 0 || grid->getCellValue(_playerX + 1, _playerY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX + 1, _playerY);
				_playerX++;
				update();
				std::cout << "Right" << std::endl;
				pppGridAutopathInfo[_playerX][_playerY][3] ++;
				nMoveFlag = 1;
			}
			else
				nDirect = -1;
			break;

		case 2: // bottom
			if (grid->getCellValue(_playerX, _playerY + 1)->type() == 0 || grid->getCellValue(_playerX, _playerY + 1)->type() == 2) { //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX, _playerY + 1);
				_playerY++;
				update();
				std::cout << "Down" << std::endl;
				pppGridAutopathInfo[_playerX][_playerY][0] ++;
				nMoveFlag = 1;
			}
			else
				nDirect = -1;
			break;

		case 3: // left
			if (grid->getCellValue(_playerX - 1, _playerY)->type() == 0 || grid->getCellValue(_playerX - 1, _playerY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX - 1, _playerY);
				_playerX--;
				update();
				std::cout << "Left" << std::endl;
				pppGridAutopathInfo[_playerX][_playerY][1] ++;
				nMoveFlag = 1;
			}
			else
				nDirect = -1;
			break;
		}

		if (IsCrash())
			return 3;

		if (IsComplete())
			return 1;
	}
	return 0;
}


BOOL Display::IsEqual(int nValue)
{
	if (pppGridAutopathInfo[_playerX][_playerY][0] == nValue &&
		pppGridAutopathInfo[_playerX][_playerY][1] == nValue &&
		pppGridAutopathInfo[_playerX][_playerY][2] == nValue &&
		pppGridAutopathInfo[_playerX][_playerY][3] == nValue)
		return TRUE;

	return FALSE;
}
BOOL Display::IsCrash()
{
	if (!isvisibleEnemy)
		return FALSE;

	int nOffsetX, nOffsetY;

	nOffsetX = abs(_playerX - _enemyX);
	nOffsetY = abs(_playerY - _enemyY);

	if (nOffsetX <= 1 && nOffsetY <= 1)
		return TRUE;

	return FALSE;
}

int Display::IsComplete()
{
	if (grid->getCellValue(_playerX, _playerY - 1)->type() == 4 ||
		grid->getCellValue(_playerX, _playerY + 1)->type() == 4 ||
		grid->getCellValue(_playerX - 1, _playerY)->type() == 4 ||
		grid->getCellValue(_playerX + 1, _playerY)->type() == 4)
		return 1;
	return 0;
}



void Display::ChangeEnemy()
{
	if (bRemoveEnemy)
		return;

	Sleep(100);
	srand(time(NULL));
	int nDirect = rand() % 4;
	switch (nDirect)
	{
	case 0: // top
		if (grid->getCellValue(_enemyX, _enemyY - 1)->type() == 0 || grid->getCellValue(_enemyX, _enemyY - 1)->type() == 2) {  //checking if next cell is open space or object, if so, player can move
			grid->move(_enemyX, _enemyY, _enemyX, _enemyY - 1);
			_enemyY--;
			update();
		}
		break;

	case 1: // right
		if (grid->getCellValue(_enemyX + 1, _enemyY)->type() == 0 || grid->getCellValue(_enemyX + 1, _enemyY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_enemyX, _enemyY, _enemyX + 1, _enemyY);
			_enemyX++;
			update();
		}
		break;

	case 2: // bottom
		if (grid->getCellValue(_enemyX, _enemyY + 1)->type() == 0 || grid->getCellValue(_enemyX, _enemyY + 1)->type() == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_enemyX, _enemyY, _enemyX, _enemyY + 1);
			_enemyY++;
			update();
		}
		break;

	case 3: // left
		if (grid->getCellValue(_enemyX - 1, _enemyY)->type() == 0 || grid->getCellValue(_enemyX - 1, _enemyY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
			grid->move(_enemyX, _enemyY, _enemyX - 1, _enemyY);
			_enemyX--;
			update();
		}
		break;
	}

}
void Display::RemoveEnemy()
{
	grid->setCell(_enemyX, _enemyY, 0);
}

void Display::RemoveHero()
{
	grid->setCell(_playerX, _playerY, 0);
}


void Display::MoveHero(int nMoveX, int nMoveY)
{
	int nMovePosX = (nMoveX - PADDINGX - BORDER_SIZE*_tilesize.x) / _tilesize.x;
	int nMovePosY = (nMoveY - PADDINGY - BORDER_SIZE*_tilesize.y) / _tilesize.y;
	int nDirection, nStep;

	if (_playerX == nMovePosX) { // horizontal
		nStep = nMovePosY - _playerY;
		nDirection = nStep  > 0 ? 2 : 0;
	}
	else if (_playerY == nMovePosY) { // vertical
		nStep = nMovePosX - _playerX;
		nDirection = nStep > 0 ? 1 : 3;
	}
	else
		return;

	for (int idx = 0; idx < abs(nStep); idx++)
	{
		Sleep(100);
		switch (nDirection)
		{
		case 0: // top
			if (grid->getCellValue(_playerX, _playerY - 1)->type() == 0 || grid->getCellValue(_playerX, _playerY - 1)->type() == 2) {  //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX, _playerY - 1);
				_playerY--;
				update();
			}
			break;

		case 1: // right
			if (grid->getCellValue(_playerX + 1, _playerY)->type() == 0 || grid->getCellValue(_playerX + 1, _playerY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX + 1, _playerY);
				_playerX++;
				update();
			}
			break;

		case 2: // bottom
			if (grid->getCellValue(_playerX, _playerY + 1)->type() == 0 || grid->getCellValue(_playerX, _playerY + 1)->type() == 2) { //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX, _playerY + 1);
				_playerY++;
				update();
			}
			break;

		case 3: // left
			if (grid->getCellValue(_playerX - 1, _playerY)->type() == 0 || grid->getCellValue(_playerX - 1, _playerY)->type() == 2) { //checking if next cell is open space or object, if so, player can move
				grid->move(_playerX, _playerY, _playerX - 1, _playerY);
				_playerX--;
				update();
			}
			break;
		}
	}
}
