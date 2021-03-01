/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include <testing/catch.hpp>

/* Include the code that we plan to test */
#include <lib/Structures/LinkedLists/linkedlist.hpp>
#include <string>
#include <iostream>
#include <stdexcept>

typedef Salih::Structures::LinkedLists::LinkedList<int> intList ;

/* Create sub-categories to test with predicted outcomes */
TEST_CASE("Testing [] operator - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1[0] == 1) ;
	REQUIRE(list1[3] == 4) ;
}

TEST_CASE("Testing [] operator - modifying values")
{
	intList list1 = {1,2,3,4,5,6} ;
	list1[3] = 1 ;
	REQUIRE(list1[3] == 1) ;
	REQUIRE(list1[3] != 4) ;
}

TEST_CASE("Testing [] operator - does 'out_of_range' error get thrown if list is empty")
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

TEST_CASE("Testing == operator - comparing values")
{
	intList list1 = {1,2,3,4,5,6} ;
	intList list2{1,2,3,4,5} ;
	REQUIRE(list1 != list2) ;
	list2.append(6) ;
	REQUIRE(list1 == list2) ;
}

TEST_CASE("'getSize()' method - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.getSize() == 6) ;
}

TEST_CASE("'append()' method - correct value added")
{
	intList list1 ;
	REQUIRE(!(list1.getSize() > 0)) ;
	list1.append(5) ;
	REQUIRE(list1.getSize() == 1) ;
	REQUIRE(list1[0] == 5) ;
}

TEST_CASE("'del()' method - correct value deleted")
{
	intList list1{1,2,3} ;
	list1.del(1) ;
	REQUIRE(list1[0] == 2) ;
	REQUIRE(list1.getSize() == 2) ;
}

TEST_CASE("'del()' method - does 'out_of_range' error get thrown if list is empty")
{
	intList list1 ;
	list1.del(1) ;
}

TEST_CASE("'del()' method - does 'out_of_range' error get thrown if list doesn't contain index")
{
	intList list1{1} ;
	list1.del(2) ;
}
