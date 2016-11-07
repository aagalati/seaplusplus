/*!brief	This code was provided to create the test suite. I have decided to split the 
			original file to have a proper header file. I have also added to additional
			test cases to ensure that the hitPointGenerator() and the sorting mechanism
			of the abilityPointGenerator() work as intended.
*/
#ifndef C_TEST_H
#define C_TEST_H
	//! @file 
	//! @brief Implementation file for the Character Testing class  
	//!

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "Character.h"
#include "Subject.h"
#include "Observer.h"

	using namespace CppUnit;
	using namespace std;


	//! Test Class for the Character class
	class CharacterTest : public CppUnit::TestFixture
	{
		CPPUNIT_TEST_SUITE(CharacterTest);
		CPPUNIT_TEST(testValidNewCharacter);
		CPPUNIT_TEST(testInvalidNewCharacter);
		CPPUNIT_TEST(testHit);
		
		//!Added test cases (Assignment 1)
		CPPUNIT_TEST(testHighestStat);
		CPPUNIT_TEST(testHitPointGenerator);

		//!Added test case(Assignment 2)
		CPPUNIT_TEST(testUpdate);
		
		CPPUNIT_TEST_SUITE_END();
	protected:
		void testValidNewCharacter();
		void testInvalidNewCharacter();
		
		void testHit();
		//!Added test cases (Assignment 1)
		void testHighestStat();
		void testHitPointGenerator();

		//!Added test case(Assignment 2)
		
		void testUpdate();

	};

	//! test case registration
	CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

#endif

