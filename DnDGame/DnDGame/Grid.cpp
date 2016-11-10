
#include "stdafx.h"
#include "Grid.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "Builder.h"

using namespace std;

Grid::Grid(int width, int height, bool blank) //constructor
{
	_width = width;  //set values 
	_height = height;
	sizeMap();
	if (!blank) fillMapRandom(); //if the user wants the map to be blank then the map is not filled randomly
	GridObserver *_gridObserver = new GridObserver();
	_grid = _gridObserver;
	_grid->Attach(this);
	refresh = false;

}

Grid::Grid(Grid *grid) {

	this->_width = _width;
	this->_height = _height;
	this->_gridData = _gridData;
	this->_entrance_col = _entrance_col;
	this->_entrance_row = _entrance_row;
	this->_exit_col = _exit_col;
	this->_exit_row = _exit_row;

	GridObserver *_gridObserver = new GridObserver();
	_grid = _gridObserver;
	_grid->Attach(this);
	refresh = false;

}

int Grid::getWidth() {
	return _width;
}

int Grid::getHeight() {
	return _height;
}

void Grid::validRandom() {
	while (!checkValid())
		fillMapRandom();
}

void Grid::fillMapRandom()  //this method fills the map randomly with walls, objects and open spaces
{

	int t;
	Builder *build = new Builder();
	DNDObject *make;

	srand( time(NULL) );  //using srand for random numbers everytime

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			t = rand() % 3;
			 make = build->build(t);
			_gridData[i][j] = make;

		}
	}
	
	_entrance_col = rand() % _width;  //randomizing entrances and exits
	_entrance_row = rand() % _height;

	do {  //exit cannot = entrance
		_exit_col = rand() % _width;
		_exit_row = rand() % _height;
	} while (_entrance_col == _exit_col && _entrance_row == _exit_row);

	make = build->build(3);
	_gridData[_entrance_col][_entrance_row] = make;

	make = build->build(4);
	_gridData[_exit_col][_exit_row] = make;

	_currentcell = _gridData[_entrance_col][_entrance_row]; //current cell is the door when you come into the map
	make = build->build(5);
	_gridData[_entrance_col][_entrance_row] = make;

}

bool Grid::checkValid() {

	return checkValid(_entrance_col, _entrance_row, 0);

}

bool Grid::checkValid(int row, int col, int dir) {

	//cout << "Checking at (" << row << "," << col << ") = " << _gridData[row][col] << endl;
	
	srand(time(NULL));

	//int t; //testing purposes
	//cin >> t;

	if (_gridData[row][col]->type() == 4) { //base case, if exit is found, return true
		//cout << "Found the exit, returning true" << endl;
		return true;
	}
	else if (_gridData[row][col]->type() == 1) { //case that there is a wall we return false
		//cout << "Wall in the way, returning false" << endl;
		return false;
	}
	else {
			//cout << "Checking empty space at (" << row << "," << col << ")" << endl;  //this code is for testing purposes
			//printMapImage(row, col);

			//cout << "Direction = " << dir << endl;

			if (col != 0 && dir != 2) {  //Checking left
				//cout << "Going left" << endl; //debugging purposes
				if (checkValid(row, col - 1, 1))
					return true;
			}

			if (col != _width - 1 && dir != 1) { //checking right
				//cout << "Going right" << endl;  //debugging purposes
				if (checkValid(row, col + 1, 2))
					return true;
			}

			int random2 = rand() % 2;

			//cout << "Random is: " << random2 << endl;

			if (row != 0 && dir != 4 && random2 == 0) { //checking up
				//cout << "Going up" << endl; //debugging purposes
				if (checkValid(row - 1, col, 3))
					return true;
			}

			if (row != _height - 1 && dir != 3 && random2 == 1) { //checking down
				//cout << "Going down" << endl; //debugging purposes
				if (checkValid(row + 1, col, 4))
					return true;
			}

	}

	return false;
}


void Grid::printMapValues() {


	for (int i = 0; i < _height - 2; i++) { //loop to create a header for the grid
		if (i == (_height / 2) - 1 && _height%2 == 0) //different formatting for odd and even
			cout << "Current Map----";
		else if (i == (_height / 2) - 1 && _height % 2 == 1)
			cout << "--Current Map--";
		else
			cout << "-----";
	}

	cout << endl;

	for (int i = 0; i < _width; i++) { //iterating through the whole 2d matrix and inserting random numbers
		for (int j = 0; j < _height; j++) {
			cout << "| " << _gridData[i][j] << " |";
		}
		cout << endl;
		for (int i = 0; i < _height; i++) {
			cout << "-----";
		}
		cout << endl;
	}


}


void Grid::printMapImage() {  //prints the map as an image, Wall = $ = 1, Open space = " " = 0, Object = O = 2, Door = D = -1 or -2

	for (int i = 0; i < _width + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < _height; i++) { //iterating through the whole 2d matrix and inserting random numbers

		cout << "#";

		for (int j = 0; j < _width; j++) {
			switch (_gridData[j][i]->type()) {

				case 0: cout << " "; //open space
						break;
				case 1: cout << "#"; //wall
						break;
				case 2: cout << "O"; //object
						break;
				default: cout << "D"; //door
						 break;

			}

		}

		cout << "#" << endl;

	}

	for (int i = 0; i < _width + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

}

void Grid::printMapImage(int row, int col) {  //this overloaded version of print map image is for debugging checkValid() it allows me to see where it is checking with the $ symbol

	for (int i = 0; i < _width + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < _height; i++) { //iterating through the whole 2d matrix and inserting random numbers

		cout << "#";

		for (int j = 0; j < _width; j++) {
			if (i == row && j == col)
				cout << "$";
			else {
				switch (_gridData[j][i]->type()) {

				case 0: cout << " ";
					break;
				case 1: cout << "#";
					break;
				case 2: cout << "O";
					break;
				default: cout << "D";
					break;
				}
			}

		}

		cout << "#" << endl;

	}

	for (int i = 0; i < _width + 2; i++) { //loop to create a header for the grid
		cout << "#";
	}

	cout << endl;

}

void Grid::setDoors() {

	int x, y;

	cout << "To begin, you must set an entrance and an exit!" << endl;
	cout << "Let's start with the entrance." << endl;
	cout << "You will need to enter the number of the column" << endl << "and row you want your entrance to be at" << endl;
	
	cout << "Column from 1 to " << _width << ": ";
	cin >> x;
	cout << "Row from 1 to " << _height << ": ";
	cin >> y;
	
	setCell(x - 1, y - 1, -1);
	
	cout << "Now you will need to set the exit" << endl;
	cout << "Column from 1 to " << _width << ": ";
	
	do {
		cin >> x;
		cout << "Row from 1 to " << _height << ": ";
		cin >> y;
	}  while (x == _entrance_col - 1 && y == _entrance_row - 1);

	setCell(x - 1, y - 1, -2);

}

void Grid::setCell(int col, int row, int set) {  //set a cell as a desired col and  row

	Builder *build = new Builder();
	DNDObject *make;

	if (col <= _width && row <= _height) {
		make = build->build(set);
		_gridData[col][row] = make;
	}
	else {
		cout << "Error: Cell doesn't exist in the map (out of bounds)" << endl;
		cout << "       Cell (" << col << "," << row << ") is not in the map" << endl;
	}

	//checkValid(); //after we make a switch we must check if this switch was valid

}

void Grid::sizeMap() {  //changing the size of the map

	_gridData.resize(_width); //sizing 2D vector to correct size
	for (int i = 0; i < _width; i++)
		_gridData[i].resize(_height);

	//checkValid(); //we must check if this change is valid

}

bool Grid::needRefresh() {  //needs GUI to refresh

	if (refresh) {
		refresh = false;
		return true;
	}

	else {
		return false;
	}

}

void Grid::resizeMap(int width, int height) {

	_width = width;
	_height = height;
	sizeMap();

}

DNDObject* Grid::getCellValue(int width, int height) {

		Builder *build = new Builder();
		return (width < 0 || height < 0 || width > _width - 1 || height > _height -1) ? build->build(-1) : _gridData[width][height];  //check for bounds

}

int Grid::getEntranceX() {

	return _entrance_col;

}

int Grid::getEntranceY() {

	return _entrance_row;

}

void Grid::move(int currentX, int  currentY, int nextX, int nextY) {

	DNDObject *temp;
	temp = _currentcell;

	_currentcell = _gridData[nextX][nextY];
	_gridData[nextX][nextY] = _gridData[currentX][currentY];
	_gridData[currentX][currentY] = temp;

	//std::cout << "Calling change to grid" << std::endl;

	_grid->changeToGrid();

}

void Grid::update() {

	//printMapImage();
	std::cout << "Updating Grid in Grid" << std::endl;
	refresh == true;

}


Grid::~Grid()
	{

		_grid = NULL; //destroy observer

	}