#include "stdafx.h"
#include "BuilderDisplay.h"


BuilderDisplay::BuilderDisplay() : Display()
{

	gridlist.push_back(new Grid(10, 10, false));
	gridlist.push_back(new Grid(10, 11, true));
	gridlist.push_back(new Grid(10, 12, true));
	gridlist.push_back(new Grid(10, 11, true));
	gridlist.push_back(new Grid(10, 12, true));
	gridlist.push_back(new Grid(10, 10, true));

	numofmapbuttons = gridlist.size();
	buttons.resize(numofmapbuttons);

	numofeditbuttons = 8;
	editButtons.resize(numofeditbuttons);

	buildMode = 0;
	brush = -1;

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

	this->gridlist = gridlist;

	numofmapbuttons = gridlist.size();
	buttons.resize(numofmapbuttons);

	numofeditbuttons = 8;
	editButtons.resize(numofeditbuttons);

	buildMode = 0;
	brush = -1;

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

void  BuilderDisplay::drawSprites() {

	for (int i = 0; i < _tilemaps.size(); i++) {

		createButton(i);
		seButton();

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

void BuilderDisplay::seButton() {

	sf::Vector2f s, p;
	sf::Text buttonname;
	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::Black);
	buttonname.setCharacterSize(20);
	string name = "Save and Exit";
	s.x = 300;
	s.y = 50;
	p.x = 350;
	p.y = 500;

	saveandexit = new GameButton(s, p, name, sf::Color::Green);
	buttonname.setString(name);
	buttonname.setPosition(435, 510);

	_window.draw(saveandexit->draw());
	_window.draw(buttonname);
}

void BuilderDisplay::drawSameSprites() {

	for (int i = 0; i < _tilemaps.size(); i++) {

		for (int j = 0; j < _tilemaps[i].size(); j++) {

			for (int k = 0; k < _tilemaps[i][j].size(); k++) {

				_window.draw(_tilemaps[i][j][k]);

			}

		}

	}

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
			if (buildMode == 0) {
				buttonAction(_event.mouseMove.x, _event.mouseMove.y, false);
			}
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

void BuilderDisplay::paint(int x, int  y) {

	int width = (x - PADDINGX - BORDER_SIZE*_tilesize2.x) / _tilesize2.x;
	int height = (y - PADDINGY - BORDER_SIZE*_tilesize2.y) / _tilesize2.y;
	
	//std::cout << "Grid X: " << width << std::endl;
	//std::cout << "Grid Y: " << height << std::endl;

	gridlist[workingGrid] = gridlist[workingGrid]->setCell(width, height, brush, gridlist[workingGrid]);
	buildDisplay(gridlist[workingGrid]);
	update();

}

void BuilderDisplay::saveGrids()
{
	for (vector< Grid*>::iterator iter = gridlist.begin(); iter != gridlist.end(); iter++)
	{
		Grid g(*iter);
		g.save();
	}
}

void BuilderDisplay::buttonAction(int x, int y, bool isclick) {

	if (buildMode == 0) {
	
		if (isclick && saveandexit->isClicked(x, y)) {

			std::cout << "SAVING AND EXITING" << std::endl;

			saveGrids();

		}

		for (int i = 0; i < numofmapbuttons; i++) {

			if (isclick) {

				if (buttons[i]->isClicked(x, y)) {
					_window.clear();
					buildMode = 1;
					workingGrid = i;
					buildDisplay(gridlist[workingGrid]);
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

	if (buildMode == 1) {

		_window.clear();

		for (int i = 0; i < numofeditbuttons; i++) {

			if (isclick) {

				if (editButtons[i]->isClicked(x, y)) {
					
					std::cout << "You clicked " << editButtons[i]->getText() << std::endl;

					if (i < 6)
						brush = i;
					else {
						switch (i) {
							case 6:  _window.clear();
									buildMode = 0;
									brush = -1;
									drawSprites();
									break;
							
							case 7: break;

						}
					}
				}

			}
		}

		if (isclick) {
			paint(_event.mouseButton.x, _event.mouseButton.y);
		}

		update();

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

														   //std::cout << "Creating border at " << i << ", " << j << std::endl;

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

	drawEditButtons(grid);
	_window.display();

}

void BuilderDisplay::drawEditButtons(Grid* grid) {

	sf::Vector2f size, position;
	sf::Text buttonname;
	string name;
	sf::Color color;
	buttonname.setFont(font);
	buttonname.setFillColor(sf::Color::White);
	buttonname.setCharacterSize(20);

	size.x = 150;
	size.y = 75;

	position.x = grid->getWidth() * _tilesize2.x + PADDINGX * 6;

	for (int i = 0; i < numofeditbuttons; i++) {

		if (i < 4) {
				position.y = PADDINGY * 2 + i * size.y;
			}
		else
			{
				position.y = PADDINGY * 2 + (i - 4) * size.y;
				position.x = grid->getWidth() * _tilesize2.x + PADDINGX * 6 + 200;
			}
		switch (i) {
			case 0: name = "Floor";
				color = sf::Color::Black;
				break;
			case 1: name = "Wall";
				color = sf::Color(40, 45, 125, 255);
				break;
			case 2: name = "Treasure";
				color = sf::Color(242, 226, 0, 255);
				break;
			case 3: name = "Entrance";
				color = sf::Color(111, 53, 15, 255);
				break;
			case 4: name = "Exit";
				color = sf::Color(111, 53, 15, 255);
				break;
			case 5: name = "Enemy";
				color = sf::Color(200, 0, 0, 255);
				break;
			case 6: name = "Save and Exit";
				color = sf::Color::Green;
				break;
			case 7: name = "Erase all";
				color = sf::Color::Black;
				break;

		}
		
		editButtons[i] = new GameButton(size, position, name, color);
		buttonname.setString(name);
		buttonname.setPosition(position.x + 10, position.y + 20);

		_window.draw(editButtons[i]->draw());
		_window.draw(buttonname);

	}

}

void BuilderDisplay::listDisplay()
{
}


void BuilderDisplay::update()
{


	if (buildMode == 0) {
		_window.clear();
		seButton();
		drawSameSprites();
		drawButtons();
	}

	_window.display();


}


BuilderDisplay::~BuilderDisplay()
{
}
