/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include "../../Structures/Contiguous/vector.hpp"

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

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.at(7) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
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

/* Append method */
TEST_CASE("'append()' method - correct value added")
{
	intList list1 ;
	list1.append(5) ;
	REQUIRE(list1.pointer[0] == 5) ;
	REQUIRE(list1.size == 1) ;
}

/* Insert method */
TEST_CASE("'insert()' method - correct value added at beginning of list")
{
	intList list1{54,2,3,4,5} ;
	auto size = list1.size ;
	list1.insert(1,1) ;
	REQUIRE(list1.pointer[0] == 1) ;
	REQUIRE(list1.size == (size+1)) ;
}

TEST_CASE("'insert()' method - correct value added in the middle of list")
{
	intList list1{1,2,4,5} ;
	auto size = list1.size ;
	list1.insert(3,3) ;
	REQUIRE(list1[2] == 3) ;
	REQUIRE(list1.size == (size+1)) ;
}

TEST_CASE("'insert()' method - correct value added at end of list")
{
	intList list1{1,2,3} ;
	auto size = list1.size ;
	list1.insert(4,4) ;
	REQUIRE(list1.pointer[3] == 4) ;
	REQUIRE(list1.size == (size+1)) ;
}

TEST_CASE("'insert()' method - does 'out_of_range' error get thrown if position is invalid / too large")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.insert(2,1) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("'insert()' method - does 'out_of_range' error not get thrown if position provided is only one larger than current size")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.insert(1,1) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == false) ;
}

/* Clear method */
TEST_CASE("'clear()' method - values deleted")
{
	intList list1{1,2,3} ;
	list1.clear() ;
	REQUIRE(list1.size == 0) ;
}

/* Delete method */
TEST_CASE("'del()' method - correct value deleted")
{
	intList list1{1,2,3} ;
	list1.del(1) ;
	REQUIRE(list1.pointer[0] == 2) ;
}

TEST_CASE("'del()' method - does 'out_of_range' error get thrown if list is empty")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.del(1) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("'del()' method - does 'out_of_range' error get thrown if list doesn't contain index")
{
	intList list1{1} ;
	bool isError = false ;
	try {
		list1.del(2) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}
