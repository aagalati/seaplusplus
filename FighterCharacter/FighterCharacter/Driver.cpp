

#include "stdafx.h"
#include "Character.h"
#include "Subject.h"
#include "CharacterObserver.h"
#include "Observer.h"



using namespace std;

	/*int main()
	{
	//!This character will be named Johnny One Eye and will be level 1.
		Character johnny(1, "Johnny One Eye");
		if(johnny.validateNewCharacter())
			johnny.printCharacter();
	
	//!This character will be level 18, and will have greater statistics as such
		Character bigJohnny(18, "Johnny Eighteen Eyes");
		if (bigJohnny.validateNewCharacter())
			bigJohnny.printCharacter();
	
	//!This character will have the set Ability Points assigned to it
		Character billyGood(12, 12, 12, 12, 12, 12);
		if (billyGood.validateNewCharacter())
			billyGood.printCharacter();

	//!This character will not be printed.
		Character billyBad(21, 12, 12, 12, 12, 12);
		if (billyBad.validateNewCharacter())
			billyBad.printCharacter();
	
	//!This is the default character.
		Character defaultJoe;
		if (defaultJoe.validateNewCharacter())
			defaultJoe.printCharacter();

	


	}*/

void main()
{
	string name;
	cout << "Creating a new level 1 character, please choose a name" << endl;
	cin >> name;
	Character ex1(1,name);
	ex1.printCharacter();

	int str;
	cout << "Change the strength statistic:" << endl;
	cin >> str;
	ex1.setStrength(str);
	cout << "Do it again" << endl;
	cin >> str;
	ex1.setStrength(str);

	cout << "Creating a new level  character, choose name" << endl;
	cin >> name;
	Character ex2(1, name);
	ex2.printCharacter();
	cout << "Chantge the dex stat:" << endl;
	cin >> str;
	ex2.setDexterity(str);





}