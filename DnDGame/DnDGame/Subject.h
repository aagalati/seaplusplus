#pragma once
#include "Observer.h"
#include <list>



class Subject
	{
	public:
		virtual void Attach(Observer* o);
		virtual void Detach(Observer* o);
		virtual void Notify();
		Subject();
		virtual ~Subject();
	private:
		std::list<Observer*> *_observers;
};

