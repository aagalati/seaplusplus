#pragma once
#define _AFXDLL
#include <afx.h>

#include <vector>
#include <iostream>
#include "Observer.h"
#include "GridObserver.h"
#include "DNDObject.h"

using namespace std;

class Grid : public Observer, public CObject
{
public:
	DECLARE_SERIAL(Grid)

	//Constructors
	Grid();
	Grid(int width, int height, bool blank);
	Grid(Grid* grid);
	~Grid();

	//Randomization
	void fillMapRandom();
	void fillMapBlank();
	void validRandom();

	//Map Validation
	bool checkValid();
	bool checkValid(int col, int row, int dir);

	//Console map print
	void printMapValues();
	void printMapImage();
	void printMapImage(int col, int row);

	//Map modification
	void sizeMap();
	void resizeMap(int width, int height);


	void setCell(int col, int row, int set);
	void setDoors();

	void move(int currentX, int  currentY, int nextX, int nextY);

	void update();
	bool needRefresh();


	//Map control
	std::vector<DNDObject*>* treasureList();
	std::vector<DNDObject*>* characterList();


	//Grid Accessor
	DNDObject* getCellValue(int width, int height);

	int getWidth();
	int getHeight();
	int getEntranceX();
	int getEntranceY();
	int getExitX();
	int getExitY();
	vector< vector<DNDObject*> >& getGridData();
	string getGridName();


	//void setRow(int row, int set);
	//void setCol(int col, int set);
	//void addExtraRow(int set);  //commmented code is code to be implemented later on
	//void addExtraCol(int set);
	//void getWidth();
	//void getHeight();
	//generate stack for the shortest distance
	//use objects/cell class for cells

	//Serial stuff
	virtual void Serialize(CArchive&);
	void save();
	Grid* load();

	int*** ppGridAutopathInfo;

private:

	int _width;
	int _height;
	int _entrance_row;
	int _entrance_col;
	int _exit_row;
	int _exit_col;
	int dir; //

	bool isValid; //
	bool refresh; //

	string gridName;

	GridObserver *_grid;

	DNDObject *_currentcell;

	//Actual grid component
	vector< vector<DNDObject*> > _gridData;

};

