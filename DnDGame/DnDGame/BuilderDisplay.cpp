#include "stdafx.h"
#include "BuilderDisplay.h"


BuilderDisplay::BuilderDisplay() : Display()
{

	gridlist.push_back(new Grid(10, 10, false));
	gridlist.push_back(new Grid(10, 10, false));
	gridlist.push_back(new Grid(10, 10, false));

	_window.create(sf::VideoMode(_windowsize.x, _windowsize.y), "Dungeouns and Dragons");

	_tilesource.x = 16;
	_tilesource.y = Wall;

	_tilesize.x = 16;
	_tilesize.y = 16;

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
}

void  BuilderDisplay::drawSprites() {

	for (int i = 0; i < _tilemaps.size(); i++) {

		for (int j = 0; j < _tilemaps[i].size(); j++) {

			for (int k = 0; k < _tilemaps[i][j].size(); k++) {

				_tilemaps[i][j][k].setTexture(tileTexture);
				std::cout << "Creating tile at for grid " << i << " at " << j << ", " << k << std::endl;
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
				_tilemaps[i][j][k].setPosition(_tilesize.x * j + PADDINGX + i*_tilemaps[i].size()*20, _tilesize.y * k + PADDINGY);  //setting position

				_window.draw(_tilemaps[i][j][k]);

			}


		}


	}


	_window.display();  //REMOVE IF MOVED TO UPDATE

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

void BuilderDisplay::buildDisplay()
{

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

void BuilderDisplay::listDisplay()
{
}

void BuilderDisplay::drawButtons()
{
}

void BuilderDisplay::run()
{
}

void BuilderDisplay::update()
{
}

void BuilderDisplay::buttonAction(int x, int y, bool isclick)
{
}


BuilderDisplay::~BuilderDisplay()
{
}
