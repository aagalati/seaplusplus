#include "stdafx.h"
#include "BuilderDisplay.h"


BuilderDisplay::BuilderDisplay() : Display()
{

	gridlist.push_back(new Grid(10, 10, false));
	gridlist.push_back(new Grid(10, 11, false));
	gridlist.push_back(new Grid(10, 12, false));
	gridlist.push_back(new Grid(10, 11, false));
	gridlist.push_back(new Grid(10, 12, false));
	gridlist.push_back(new Grid(10, 10, false));

	numofmapbuttons = gridlist.size();
	buttons.resize(numofmapbuttons);

	numofeditbuttons = 0;

	buildMode = 0;

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeouns and Dragons");
	_window.clear();

	_tilesource.x = 16;
	_tilesource.y = Wall;

	_tilesize.x = 16;
	_tilesize.y = 16;
	_tilesize2.x = _tilesize.x * 2;
	_tilesize2.y = _tilesize.y * 2;

	PADDINGX = 16;
	PADDINGY = 16;

	loadFonts();
	loadTextures();
	sizeTilemap();
	drawSprites();

}

BuilderDisplay::BuilderDisplay(std::vector<Grid*> gridlist) : Display()
{
	loadFonts();
	loadTextures();
	sizeTilemap();
	drawSprites();

	
	->gridlist = gridlist;

	numofmapbuttons = gridlist.size();
	buttons.resize(numofmapbuttons);

	numofeditbuttons = 0;
}

void  BuilderDisplay::drawSprites() {

	for (int i = 0; i < _tilemaps.size(); i++) {

		createButton(i);

		for (int j = 0; j < _tilemaps[i].size(); j++) {

			for (int k = 0; k < _tilemaps[i][j].size(); k++) {

				_tilemaps[i][j][k].setTexture(tileTexture);
				//std::cout << "Creating tile at for grid " << i << " at " << j << ", " << k << std::endl;
				int cellValue;
				cellValue = gridlist[i]->getCellValue(j, k)->type();   //using enum types, refer to grid to apply corresponding textures
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

				_tilemaps[i][j][k].setTextureRect(sf::IntRect(0, _tilesource.y * 32, 32, 32));
				_tilemaps[i][j][k].setScale(0.5f, 0.5f);
				if (i < 4)
					_tilemaps[i][j][k].setPosition(_tilesize.x * j + PADDINGX + i*_tilemaps[i].size()*20, _tilesize.y * k + PADDINGY);  //setting position
				else 
					_tilemaps[i][j][k].setPosition(_tilesize.x * j + PADDINGX + (i-4)*_tilemaps[i].size() * 20, _tilesize.y * k + PADDINGY + 275);  //setting position

				_window.draw(_tilemaps[i][j][k]);

			}


		}


	}

	drawButtons();
	_window.display();  //REMOVE IF MOVED TO UPDATE

}

void BuilderDisplay::createButton(int i) {

	sf::Vector2f size, position;

	size.x = gridlist[i]->getWidth() * _tilesize.x;
	size.y = gridlist[i]->getHeight() * _tilesize.y;

	if (i < 4) {
		position.x = PADDINGX + i* gridlist[i]->getWidth() * 20;
		position.y = PADDINGY;
	}
	else {
		position.x = PADDINGX + (i-4)* gridlist[i]->getWidth() * 20;
		position.y = PADDINGY + 275;
	}


	buttons[i] = new GameButton(size, position, sf::Color::Transparent);

		//_tilesize.x * j + PADDINGX + i*_tilemaps[i].size()*20, _tilesize.y * k + PADDINGY


}

void BuilderDisplay::drawButtons() {

	//sf::Text buttonname;
	//buttonname.setFont(font);
	//buttonname.setFillColor(sf::Color::Black);
	//buttonname.setCharacterSize(20);

	for (int i = 0; i < numofmapbuttons; i++) {

		//buttonname.setPosition(buttons[i]->getPosition());
		//buttonname.setString(buttons[i]->getText());

		_window.draw(buttons[i]->draw());
		//_window.draw(buttonname);

	}

}


void BuilderDisplay::run() {

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
			std::cout << "Clicked at X: " << _event.mouseButton.x << " Y: " << _event.mouseButton.y << std::endl;
			if (_event.mouseButton.button == sf::Mouse::Left) {
				buttonAction(_event.mouseButton.x, _event.mouseButton.y, true);
			}
			break;
		}
	}
}

void BuilderDisplay::buttonAction(int x, int y, bool isclick) {

	for (int i = 0; i < numofmapbuttons; i++) {

		if (isclick) {

			if (buttons[i]->isClicked(x, y)) {
				_window.clear();
				buildMode = 1;
				buildDisplay(gridlist[i]);
			}

		}
		else {

			if (buttons[i]->isClicked(x, y)) {
				buttons[i]->changeOutlineColor(sf::Color::Red);
				update();
			}
			else {
				buttons[i]->changeOutlineColor(sf::Color::White);
				update();
			}

		}

	}

}

void BuilderDisplay::sizeTilemap() {

	_tilemaps.resize(gridlist.size());

	for (int i = 0; i < gridlist.size(); i++) {

		_tilemaps[i].resize(gridlist[i]->getWidth());

			for (int j = 0; j < gridlist[i]->getWidth(); j++) {

				_tilemaps[i][j].resize(gridlist[i]->getHeight());

		}

	}

}

void BuilderDisplay::buildDisplay(Grid* grid)
{

	BORDER_SIZE = 1;
	BORDER = BORDER_SIZE * 2;

	int _width = grid->getWidth() + BORDER;
	int _height = grid->getHeight() + BORDER;

	_tilemap.resize(_width);

	for (int i = 0; i < _width; i++) {     //for loop to instantiate all the sprites and apply textures to them

		_tilemap[i].resize(_height);
		//std::cout << i << std::endl;

		for (int j = 0; j < _height; j++) {

			if (i == 0 || j == 0 || i == _width - 1 || j == _height - 1) {

				_tilemap[i][j].setTexture(borderTexture);  //setting border texture

														   //This line is for single box texture
														   //tilemap[i][j].setTextureRect(sf::IntRect(0, 32, 32, 32));

														   std::cout << "Creating border at " << i << ", " << j << std::endl;

														   //THIS CODE IS FOR FRAMED BORDER

				if (i == 0 && j == 0)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * tlcorner, _tilesize2.x, _tilesize2.y*2));

				else if (j == 0 && (i != _width - 1 && i != 0))
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * top, _tilesize2.x, _tilesize2.y));

				else if (i == _width - 1 && j == 0)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * trcorner, _tilesize2.x, _tilesize2.y));

				else if (i == _width - 1 && j != 0 && j != _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * right, _tilesize2.x, _tilesize2.y));

				else if (i == _width - 1 && j == _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * brcorner, _tilesize2.x, _tilesize2.y));

				else if (i != 0 && j == _height - 1 && i != _width - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * bottom, _tilesize2.x, _tilesize2.y));

				else if (i == 0 && j == _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * blcorner, _tilesize2.x, _tilesize2.y));

				else if (i == 0 && j != 0 && j != _height - 1)
					_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesize2.y * left, _tilesize2.x, _tilesize2.y));

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

				_tilemap[i][j].setTextureRect(sf::IntRect(0, _tilesource.y * _tilesize2.y, _tilesize2.x, _tilesize2.x));
				
			
			}

			_tilemap[i][j].setPosition(_tilesize2.x * i + PADDINGX, _tilesize2.y * j + PADDINGY);  //setting position
			_window.draw(_tilemap[i][j]);
			

		}

	}

	drawEditButtons();
	_window.display();

}

void BuilderDisplay::drawEditButtons() {



}

void BuilderDisplay::listDisplay()
{
}


void BuilderDisplay::update()
{
}


BuilderDisplay::~BuilderDisplay()
{
}
