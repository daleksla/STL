/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include <lib/Structures/LinkedLists/linkedlist.hpp>

typedef Salih::Structures::LinkedLists::LinkedList<int> intList ;

//** Create sub-categories to test with predicted outcomes **//

/* Constructors */
TEST_CASE("empty constructor - attribute testing")
{
	intList list1 ;
	REQUIRE(list1.head == NULL) ;
	REQUIRE(list1.tail == NULL) ;
	REQUIRE(list1.size == 0) ;
}

TEST_CASE("regular constructor - attribute testing")
{
	intList list1{1,2,3,4} ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list1.head->getNext()->getNext()->getNext() == list1.tail) ;
	REQUIRE(list1.tail->getPrev()->getPrev()->getPrev() == list1.head) ;
}

TEST_CASE("regular constructor - value testing")
{
	intList list1{1,2,3,4} ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
}

TEST_CASE("copy constructor - attribute testing")
{
	intList list1{1,2,3,4} ;
	intList list3(list1) ;
	REQUIRE(list1.head != list3.head) ;
	REQUIRE(list1.tail != list3.tail) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("copy constructor - value testing")
{
	intList list1{1,2,3,4} ;
	intList list3(list1) ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list3.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
	REQUIRE(list3.tail->data == 4) ;
}

TEST_CASE("move constructor - attribute testing")
{
	intList list2(intList{1,2,3,4}) ;
	REQUIRE(list2.head != NULL) ;
	REQUIRE(list2.tail != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.head ;
	auto t = list2.tail ;
	intList list3 = std::move(list2) ;
	REQUIRE(list3.head == h) ;
	REQUIRE(list3.tail == t) ;	
}

TEST_CASE("move constructor - value testing")
{
	intList list2(intList{1,2,3,4}) ;
	REQUIRE(list2.head->data == 1) ;
	REQUIRE(list2.tail->data == 4) ;
}

/* Assignment Operators */
TEST_CASE("assigning values using operator to list - attribute testing")
{
	intList list1{1,2,3,4} ;
	list1 = {1,2,3,43} ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list1.head->getNext()->getNext()->getNext() == list1.tail) ;
	REQUIRE(list1.tail->getPrev()->getPrev()->getPrev() == list1.head) ;
}

TEST_CASE("assigning values using operator to list - value testing")
{
	intList list1 = {1,2,3,4} ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
}

TEST_CASE("assigning created list using operator to list - attribute testing")
{
	intList list1{1,2,3,4} ;
	intList list3 = list1 ;
	REQUIRE(list1.head != list3.head) ;
	REQUIRE(list1.tail != list3.tail) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("assigning created list using operator to list - value testing")
{
	intList list1{1,2,3,4} ;
	intList list3 = list1 ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list3.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
	REQUIRE(list3.tail->data == 4) ;
}

TEST_CASE("assigning r-value / temporary list using operator to list - attribute testing")
{
	intList list2 = intList{1,2,3,4} ;
	REQUIRE(list2.head != NULL) ;
	REQUIRE(list2.tail != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.head ;
	auto t = list2.tail ;
	intList list3 = std::move(list2) ;
	REQUIRE(list3.head == h) ;
	REQUIRE(list3.tail == t) ;	
}

TEST_CASE("assigning r-value / temporary list using operator to list - value testing")
{
	intList list2 = intList{1,2,3,4} ;
	REQUIRE(list2.head->data == 1) ;
	REQUIRE(list2.tail->data == 4) ;
}

/* Index / access operator */
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

TEST_CASE("[] operator - does 'out_of_range' error get thrown if list is empty")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1[0] ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

/* Boolean operators */
TEST_CASE("== operator - comparing values")
{
	intList list1 = {1,2,3,4,5,6} ;
	intList list2{1,2,3,4,5,6} ;
	REQUIRE(list1 == list2) ;
}

TEST_CASE("!= operator - comparing values")
{
	intList list1 = {1,2,3,4,5,6} ;
	intList list2{1,2,3,4,5} ;
	REQUIRE(list1 != list2) ;
}

/* Size method */
TEST_CASE("'getSize()' method - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.getSize() == 6) ;
}

/* Append method */
TEST_CASE("'append()' method - correct value added")
{
	intList list1 ;
	list1.append(5) ;
	REQUIRE(list1[0] == 5) ;
}

/* Insert method */
TEST_CASE("'insert()' method - correct value added at beginning of list")
{
	intList list1{54,2,3,4,5} ;
	list1.insert(1,1) ;
	REQUIRE(list1[0] == 1) ;
}

TEST_CASE("'insert()' method - correct value added in the middle of list")
{
	intList list1{1,2,4,5} ;
	list1.insert(3,3) ;
	REQUIRE(list1[2] == 3) ;
}

TEST_CASE("'insert()' method - correct value added at end of list")
{
	intList list1{1,2,3} ;
	list1.insert(4,4) ;
	REQUIRE(list1[3] == 4) ;
}

TEST_CASE("'insert()' method - does 'out_of_range' error get thrown if index is invalid")
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

/* Delete method */
TEST_CASE("'del()' method - correct value deleted")
{
	intList list1{1,2,3} ;
	list1.del(1) ;
	REQUIRE(list1[0] == 2) ;
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
