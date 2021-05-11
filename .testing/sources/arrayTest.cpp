/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include <lib/Structures/Contiguous/array.hpp>

typedef Salih::Structures::Contiguous::Array<int,6> bigList ;
typedef Salih::Structures::Contiguous::Array<int,6> floatList ;
typedef Salih::Structures::Contiguous::Array<int,3> smallList ;

template<std::size_t SIZE>
constexpr std::size_t getSize(Salih::Structures::Contiguous::Array<int, SIZE> a)
{
	return SIZE ;
}

//** Create sub-categories to test with predicted outcomes **//

/* Constructors */
TEST_CASE("Empty constructor - attribute testing")
{
	bigList list ;
	REQUIRE(getSize(list) == 6) ;
}

TEST_CASE("Regular constructor - attribute testing")
{
	bigList list{1,2,3,4,5,6} ;
	REQUIRE(getSize(list) == 6) ;
}

TEST_CASE("Regular constructor - value testing")
{
	bigList list{1,2,3,4,5,6} ;
	REQUIRE((list.pointer[0] == 1 && list.pointer[1] == 2 && list.pointer[2] == 3 && list.pointer[3] == 4 && list.pointer[4] == 5 && list.pointer[5] == 6)) ;
}

TEST_CASE("Copy constructor (same size arrays) - attribute testing")
{
	bigList list{1,2,3,4,5,6} ;
	bigList list2(list) ; //copy constructor
	REQUIRE(list.pointer != list2.pointer) ;
	REQUIRE(getSize(list) == getSize(list2)) ;
}

TEST_CASE("Copy constructor (same size arrays) - value testing")
{
	bigList list{1,2,3,4,5,6} ;
	bigList list2(list) ; //copy constructor
	REQUIRE((list.pointer[0] == list2.pointer[0] && list.pointer[1] == list2.pointer[1] && list.pointer[2] == list2.pointer[2] && list.pointer[3] == list2.pointer[3] && list.pointer[4] == list2.pointer[4] && list.pointer[5] == list2.pointer[5])) ;
}

TEST_CASE("Copy constructor (copying smaller sized arrays) - attribute testing")
{
	smallList list{1,2,3} ;
	bigList list2(list) ; //copy constructor
	REQUIRE(list.pointer != list2.pointer) ;
	REQUIRE(getSize(list) != getSize(list2)) ;
}

TEST_CASE("Copy constructor (copying smaller sized arrays) - value testing")
{
	smallList list{1,2,3} ;
	bigList list2(list) ; //copy constructor
	REQUIRE((list.pointer[0] == list2.pointer[0] && list.pointer[1] == list2.pointer[1] && list.pointer[2] == list2.pointer[2])) ;
}

//no move constructor tests, since array class has a compiler generated version

/* Assignment operators */
TEST_CASE("Initialisation list assignment - attribute testing")
{
	bigList list = {1,2,3,4,5,6} ;
	REQUIRE(getSize(list) == 6) ;
}

TEST_CASE("Initialisation list assignment - value testing")
{
	bigList list = {1,2,3,4,5,6} ;
	REQUIRE((list.pointer[0] == 1 && list.pointer[1] == 2 && list.pointer[2] == 3 && list.pointer[3] == 4 && list.pointer[4] == 5 && list.pointer[5] == 6)) ;
}

TEST_CASE("Copy assignment operator (same size arrays) - attribute testing")
{
	bigList list{1,2,3,4,5,6} ;
	bigList list2 = list ; //copy constructor
	REQUIRE(list.pointer != list2.pointer) ;
	REQUIRE(getSize(list) == getSize(list2)) ;
}

TEST_CASE("Copy assignment operator (same size arrays) - value testing")
{
	bigList list{1,2,3,4,5,6} ;
	bigList list2 = list ; //copy constructor
	REQUIRE((list.pointer[0] == list2.pointer[0] && list.pointer[1] == list2.pointer[1] && list.pointer[2] == list2.pointer[2] && list.pointer[3] == list2.pointer[3] && list.pointer[4] == list2.pointer[4] && list.pointer[5] == list2.pointer[5])) ;
}

TEST_CASE("Copy assignment operator (copying smaller sized arrays) - attribute testing")
{
	smallList list{1,2,3} ;
	bigList list2 = list ; //copy constructor
	REQUIRE(list.pointer != list2.pointer) ;
	REQUIRE(getSize(list) != getSize(list2)) ;
}

//no move assignment tests, since array class has a compiler generated version

/* Index / access operators */
TEST_CASE("[] operator - correct value returned")
{
	bigList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1[0] == 1) ;
	REQUIRE(list1[3] != 2) ;
}

TEST_CASE("[] operator - modifying values")
{
	bigList list1 = {1,2,3,4,5,6} ;
	list1[3] = 1 ;
	REQUIRE(list1[3] == 1) ;
	REQUIRE(list1[3] != 4) ;
}

TEST_CASE("'at()' method - correct value returned")
{
	bigList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.at(0) == 1) ;
	REQUIRE(list1.at(3) != 2) ;
}

TEST_CASE("'at()' method  - modifying values")
{
	bigList list1 = {1,2,3,4,5,6} ;
	list1.at(3) = 1 ;
	REQUIRE(list1.at(3) == 1) ;
	REQUIRE(list1.at(3) != 4) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index and flag is not specified")
{
	bigList list1 ;
	bool isError = false ;
	try {
		list1.at(7) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index and flag is set to true")
{
	bigList list1 ;
	bool isError = false ;
	try {
		list1.at(7, true) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index but flag is set to false")
{
	bigList list1 ;
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
	bigList list1 = {1,2,3,4,5,6} ;
	bigList list2{1,2,3,4,5,6} ;
	floatList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 == list2) ;
	REQUIRE(!(list1 == list3)) ;
}

TEST_CASE("== operator - comparing values of different type") 
{
	bigList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5,6} ;
	floatList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 == list2) ;
	REQUIRE(!(list1 == list3)) ;
}

TEST_CASE("== operator - comparing values of different size") // will always be false
{
	floatList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(!(list1 == list2)) ;
}

TEST_CASE("== operator - comparing values of different type and different size") // will always be false
{
	bigList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(!(list1 == list2)) ;
}

TEST_CASE("!= operator - comparing values of same type")
{
	bigList list1 = {1,2,3,4,5,6} ;
	bigList list2{1,2,3,4,5,6} ;
	bigList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 != list3) ;
	REQUIRE(!(list1 != list2)) ;
}

TEST_CASE("!= operator - comparing values of different types")
{
	bigList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5,5} ;
	floatList list3{1,2,3,4,5,6} ;
	REQUIRE(list1 != list2) ;
	REQUIRE(!(list3 != list1)) ;
}

TEST_CASE("!= operator - comparing values of different size") // will always be true
{
	floatList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(list1 != list2) ;
}

TEST_CASE("!= operator - comparing values of different type and different size") // will always be false
{
	bigList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(list1 != list2) ;
}

/* Size method */
TEST_CASE("'getSize()' method - correct value returned")
{
	bigList list2 ;
	REQUIRE(list2.getSize() == 6) ;
	bigList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.getSize() == 6) ;
}
