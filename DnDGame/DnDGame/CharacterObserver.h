/*!-brief Design For Assignment 2
	The implementation of the Character Observer class is done through the "Abstract" classes Observer and Subject and their concrete counterparts.
	Character is a subclass of Observer, while CharacterObserver is a subclass of Subject.

	The ObserverPattern begins with the creation of a list of Observers(Characters) which can be attached. In the scope of this assignment, every Character is
	attached to a single list(it was my understanding that the implementation of the Observer Pattern should be list based as demonstrated in Dr Taleb's slides).
	When a change is done to a statistic of a character, the Observer Pattern is triggered, such that the Notify method is invoked, which then updates the
	particular Character. This update prints the character, and as such the demands of this assignment are fulfilled. 
*/


#pragma once
#include "Observer.h"
#include "Subject.h"
#include <list>

//Take not that the program could more efficiently make a reference directly to the
//subject, but the assignment instructions refer to the necessity of making a concrete
//subject class.



	class CharacterObserver : public Subject

	{
	public:
		CharacterObserver();
		void changeToCharacter();
	};


