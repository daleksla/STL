/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#define protected public
#include <lib/Types/pointers.hpp>
using namespace Salih::Types ;

struct Test 
{
	int val = 2 ;
} ;

/* Note: since this is a virtual class, this file will only test full inherited methods aswell as 'principles'
 * These methods will be accessed interchangeably between both child classes - the methods are identical */

TEST_CASE("Testing arrow (->) operator value")
{
	UniquePointer<Test> up ;
	up = new Test ;
	REQUIRE(up->val == 2) ;
}

TEST_CASE("Testing dereferncing (*) operator")
{
	SharedPointer<int> sp ;
	sp = new int ;
	*sp = 2 ;
	REQUIRE(*sp == 2) ;
}

TEST_CASE("Testing get method")
{
	int* p = new int ;
	UniquePointer<int> up ;
	up = p ;
	REQUIRE(up.get() == p) ;
}

TEST_CASE("Testing differentiation between stack and heap pointers")
{
	/* As part of an effort to prevent mistakes regarding allocation, freeing etc., the user is blocked from assigning a pointer to the stack, lest an error message be thrown - this code is embedded as inline assembly code within relevant constructors / assignment operators */
	bool status = false ;
	bool* data = &status ;
	//code 
	try {
		Pointer<bool>::checkValidity(data) ;
	} catch(std::runtime_error)
	{
		status = true ;
	}
	
	REQUIRE(status == true) ;
	
	status = true ;
	data = new bool ;
	//code 
	try {
		Pointer<bool>::checkValidity(data) ;
	} catch(std::runtime_error)
	{
		status = false ;
		delete data ;
	}
	
	REQUIRE(status == true) ;
	delete data ;
}
