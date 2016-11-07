#pragma once
class Observer  //abstract class
{
public:
	~Observer();
	virtual void update() = 0; 

protected:
	Observer();

};