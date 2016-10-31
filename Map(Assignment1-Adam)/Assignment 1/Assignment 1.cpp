// Assignment 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Grid.h"

using namespace std;

int main()
{

	int width, height, input, quit, x, y;
	bool isBlank = true;

	cout << "--------------Welcome to the Map Generator---------------" << endl;
	cout << "--To start making your map, enter the width and height!--" << endl;
	cout << "Width: ";
	cin >> width;
	cout << "Height: ";
	cin >> height;
	cout << endl;
	cout << "Great! The map will have a width of " << width << ", and a height of " << height << "." << endl;
	cout << endl;
	cout << "Would you like your map to be blank or randomly generate?" << endl;
	cout << "----------(1) Blank or (2) Randomly generated-----------" << endl;
	cout << "Enter a 1 or 2: ";
	cin >> input;
	cout << endl;
	cout << "Awesome, making your map..." << endl << endl;

	cout << "Legend" << endl << "------" << endl << "# = wall" << endl << "O = an Object" << endl << "D = door" << endl << endl;

	isBlank = (input == 1) ? true : false;

	Grid mygrid(width, height, isBlank);
	//mygrid.printMapValues();
	mygrid.printMapImage();

	if (isBlank) {

		mygrid.setDoors();

		mygrid.printMapImage();
	
	}

	mygrid.checkValid();



	//cout << endl;

	//cout << mygrid.checkValid() << endl;

	//mygrid.resizeMap(4, 4);
	//mygrid.setCell(1, 2, 7);

	//cout << endl;

	//mygrid.printMapValues();

	//cout << endl;

	//mygrid.printMapImage();

	//cout << mygrid.checkValid() << endl;

	//cout << mygrid.checkValid() << endl;


	cout << "Type 0 to quit ";
	cin >> quit;

    return 0;
}

