/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include <lib/Types/pointers.hpp>
using namespace Salih::Types ;

struct Test 
{
	int val = 2 ;
}

/* Note: since this is a virtual class, this file will only test full inherited methods aswell as 'principles'
 * These methods will be accessed via both child classes - unique and shared pointers */
 
TEST_CASE("Testing arrow (->) operator value - for shared pointers")
{
	SharedPointer<int> sp ;
	sp = new Test ;
	REQUIRE(sp->val = 2) ;
}

TEST_CASE("Testing arrow (->) operator value - for unique pointers")
{
	UniquePointer<int> up ;
	up = new Test ;
	REQUIRE(sp->val = 2) ;
}

TEST_CASE("Testing dereferncing (*) operator - for shared pointers")
{
	SharedPointer<int> sp ;
	sp = new Test ;
	*(sp).val = 2 ;
}

TEST_CASE("Testing dereferncing (*) operator - for unique pointers")
{
	UniquePointer<int> up ;
	up = new Test ;
	*(up).val = 2 ;
}

TEST_CASE("Testing get method - for shared pointers")
{
	int* p = new int ;
	SharedPointer<int> sp ;
	sp = p ;
	REQUIRE(sp.get() == p) ;
}

TEST_CASE("Testing get method - for unique pointers")
{
	int* p = new int ;
	UniquePointer<int> up ;
	sp = p ;
	REQUIRE(up.get() == p) ;
}

TEST_CASE("Testing index ([]) operator - for shared pointers")
{
	int* p = new int ;
	SharedPointer<int> sp ;
	sp = p ;
	REQUIRE(sp[0] != nullptr) ;
}

TEST_CASE("Testing index ([]) operator - for unique pointers")
{
	int* p = new int ;
	UniquePointer<int> up ;
	sp = p ;
	REQUIRE(up[0] != nullptr) ;
}
