/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include <lib/Structures/Contiguous/vector.hpp>

typedef Salih::Structures::Contiguous::Vector<int> intList ;
typedef Salih::Structures::Contiguous::Vector<float> floatList ;

//** Create sub-categories to test with predicted outcomes **//

/* Constructors */
TEST_CASE("Empty constructor - attribute testing")
{
	intList list ;
	REQUIRE(list.size == 0) ;
}

TEST_CASE("Regular constructor - attribute testing")
{
	intList list{1,2,3,4,5,6} ;
	REQUIRE(list.size == 6) ;
}

TEST_CASE("Regular constructor - value testing")
{
	intList list{1,2,3,4,5,6} ;
	REQUIRE((list.pointer[0] == 1 && list.pointer[1] == 2 && list.pointer[2] == 3 && list.pointer[3] == 4 && list.pointer[4] == 5 && list.pointer[5] == 6)) ;
}

TEST_CASE("Copy constructor - attribute testing")
{
	intList list{1,2,3,4,5,6} ;
	intList list2(list) ; //copy constructor
	REQUIRE(list.pointer != list2.pointer) ;
	REQUIRE(list.size == list2.size) ;
}

TEST_CASE("Copy constructor - value testing")
{
	intList list{1,2,3,4,5,6} ;
	intList list2(list) ; //copy constructor
	REQUIRE((list.pointer[0] == list2.pointer[0] && list.pointer[1] == list2.pointer[1] && list.pointer[2] == list2.pointer[2] && list.pointer[3] == list2.pointer[3] && list.pointer[4] == list2.pointer[4] && list.pointer[5] == list2.pointer[5])) ;
}

TEST_CASE("move constructor - attribute testing")
{
	intList list2(intList{1,2,3,4}) ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.pointer ;
	intList list3(std::move(list2)) ;
	REQUIRE(list3.pointer == h) ;
}

TEST_CASE("move constructor - value testing")
{
	intList list2(intList{1,2,3,4}) ;
	REQUIRE((1 == list2.pointer[0] && 2 == list2.pointer[1] && 3 == list2.pointer[2] && 4 == list2.pointer[3])) ;
}

/* Assignment operators */
TEST_CASE("Initialisation list assignment - attribute testing")
{
	intList list = {1,2,3,4,5,6} ;
	REQUIRE(list.size == 6) ;
	list = {} ;
	REQUIRE(list.size == 0) ;
}

TEST_CASE("Initialisation list assignment - value testing")
{
	intList list = {1,2,3,4,5,6} ;
	REQUIRE((list.pointer[0] == 1 && list.pointer[1] == 2 && list.pointer[2] == 3 && list.pointer[3] == 4 && list.pointer[4] == 5 && list.pointer[5] == 6)) ;
}

TEST_CASE("Copy assignment operator - attribute testing")
{
	intList list{1,2,3,4,5,6} ;
	intList list2 = list ; //copy constructor
	REQUIRE(list.pointer != list2.pointer) ;
	REQUIRE(list.size == list2.size) ;
}

TEST_CASE("Copy assignment operator - value testing")
{
	intList list{1,2,3,4,5,6} ;
	intList list2 = list ; //copy constructor
	REQUIRE((list.pointer[0] == list2.pointer[0] && list.pointer[1] == list2.pointer[1] && list.pointer[2] == list2.pointer[2] && list.pointer[3] == list2.pointer[3] && list.pointer[4] == list2.pointer[4] && list.pointer[5] == list2.pointer[5])) ;
}

TEST_CASE("move assignment operator - attribute testing")
{
	intList list2 = intList{1,2,3,4} ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.pointer ;
	intList list3(std::move(list2)) ;
	REQUIRE(list3.pointer == h) ;
}

TEST_CASE("move assignment operator - value testing")
{
	intList list2(intList{1,2,3,4}) ;
	REQUIRE((1 == list2.pointer[0] && 2 == list2.pointer[1] && 3 == list2.pointer[2] && 4 == list2.pointer[3])) ;
}

/* Index / access operators */
TEST_CASE("[] operator - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1[0] == 1) ;
	REQUIRE(list1[3] != 2) ;
}

TEST_CASE("[] operator - modifying values")
{
	intList list1 = {1,2,3,4,5,6} ;
	list1[3] = 1 ;
	REQUIRE(list1[3] == 1) ;
	REQUIRE(list1[3] != 4) ;
}

TEST_CASE("'at()' method - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.at(0) == 1) ;
	REQUIRE(list1.at(3) != 2) ;
}

TEST_CASE("'at()' method  - modifying values")
{
	intList list1 = {1,2,3,4,5,6} ;
	list1.at(3) = 1 ;
	REQUIRE(list1.at(3) == 1) ;
	REQUIRE(list1.at(3) != 4) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index and flag is not specified")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.at(7) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
		std::cout << 1 << std::endl ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index and flag is set to true")
{
	intList list1 ;
	bool isError ;
	try {
		list1.at(7, true) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index but flag is set to false")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.at(7, false) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == false) ;
}

/* Boolean operators */
TEST_CASE("== operator - comparing values of same type")
{
	intList list1 = {1,2,3,4,5,6} ;
	intList list2{1,2,3,4,5,6} ;
	floatList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 == list2) ;
	REQUIRE(!(list1 == list3)) ;
}

TEST_CASE("== operator - comparing values of different type") 
{
	intList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5,6} ;
	floatList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 == list2) ;
	REQUIRE(!(list1 == list3)) ;
}

TEST_CASE("!= operator - comparing values of same type")
{
	intList list1 = {1,2,3,4,5,6} ;
	intList list2{1,2,3,4,5,6} ;
	intList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 != list3) ;
	REQUIRE(!(list1 != list2)) ;
}

TEST_CASE("!= operator - comparing values of different types")
{
	intList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5,5} ;
	floatList list3{1,2,3,4,5,6} ;
	REQUIRE(list1 != list2) ;
	REQUIRE((list3 != list1) == 1) ;
}

/* Size method */
TEST_CASE("'getSize()' method - correct value returned")
{
	intList list2 ;
	REQUIRE(list2.getSize() == 0) ;
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.getSize() == 6) ;
}
