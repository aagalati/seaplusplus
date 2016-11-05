#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Grid
{
public:

	Grid(int width, int height, bool blank);
	void fillMapRandom();
	bool checkValid();
	bool checkValid(int col, int row, int dir);
	void printMapValues();
	void printMapImage();
	void printMapImage(int col, int row);
	void sizeMap();
	void resizeMap(int width, int height);
	void setCell(int col, int row, int set);
	void setDoors();
	
	inline int getWidth();
	inline int getHeight();

	//void setRow(int row, int set);
	//void setCol(int col, int set);
	//void addExtraRow(int set);  //commmented code is code to be implemented later on
	//void addExtraCol(int set);
	//void getWidth();
	//void getHeight();
	//~Grid();
	//generate stack for the shortest distance
	//use objects/cell class for cells

private:

	int _width;
	int _height;
	int _entrance_row;
	int _entrance_col;
	int _exit_row;
	int _exit_col;
	int dir;
	bool isValid;

	vector< vector<int> > _gridData;
};

