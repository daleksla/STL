/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define private public
#define protected public
/* Include the code that we plan to test */
#include <lib/Types/stack.hpp>
#include <string>
#include <iostream>
#include <stdexcept>

typedef Salih::Types::Stack<int> intStack ;

/* Create sub-categories to test with predicted outcomes */
TEST_CASE("empty constructor - attribute testing")
{
	intStack list1 ;
	REQUIRE(list1.tail == NULL) ;
	REQUIRE(list1.size == 0) ;
}

TEST_CASE("regular constructor - attribute testing")
{
	intStack list1{1,2,3,4} ;
	REQUIRE(list1.size == 4) ;
}

TEST_CASE("regular constructor - value testing")
{
	intStack list1{1,2,3,4} ;
	REQUIRE(list1.tail->data == 4) ;
}

TEST_CASE("copy constructor - attribute testing")
{
	intStack list1{1,2,3,4} ;
	intStack list3(list1) ;
	REQUIRE(list1.tail != list3.tail) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("copy constructor - value testing")
{
	intStack list1{1,2,3,4} ;
	intStack list3(list1) ;
	REQUIRE(list1.tail->data == 4) ;
	REQUIRE(list3.tail->data == 4) ;
}

TEST_CASE("move constructor - attribute testing")
{
	intStack list2(intStack{1,2,3,4}) ;
	REQUIRE(list2.tail != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto t = list2.tail ;
	intStack list3 = std::move(list2) ;
	REQUIRE(list3.tail == t) ;	
}

TEST_CASE("move constructor - value testing")
{
	intStack list2(intStack{1,2,3,4}) ;
	REQUIRE(list2.tail->data == 4) ;
}

/* Assignment Operators */
TEST_CASE("assigning values using operator to list - attribute testing")
{
	intStack list1{1,2,3,4} ;
	list1 = {1,2,3,43} ;
	REQUIRE(list1.size == 4) ;
}

TEST_CASE("assigning values using operator to list - value testing")
{
	intStack list1 = {1,2,3,4} ;
	REQUIRE(list1.tail->data == 4) ;
}

TEST_CASE("assigning created list using operator to list - attribute testing")
{
	intStack list1{1,2,3,4} ;
	intStack list3 = list1 ;
	REQUIRE(list1.tail != list3.tail) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("assigning created list using operator to list - value testing")
{
	intStack list1{1,2,3,4} ;
	intStack list3 = list1 ;
	REQUIRE(list1.tail->data == 4) ;
	REQUIRE(list3.tail->data == 4) ;
}

TEST_CASE("assigning r-value / temporary list using operator to list - attribute testing")
{
	intStack list2 = intStack{1,2,3,4} ;
	REQUIRE(list2.tail != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto t = list2.tail ;
	intStack list3 = std::move(list2) ;
	REQUIRE(list3.tail == t) ;	
}

TEST_CASE("assigning r-value / temporary list using operator to list - value testing")
{
	intStack list2 = intStack{1,2,3,4} ;
	REQUIRE(list2.tail->data == 4) ;
}

TEST_CASE("Testing peek() method - correct value returned")
{
	intStack stack1 = {1,2,3,4,5,6} ;
	REQUIRE(stack1.peek() == 6) ;
	REQUIRE(stack1.peek() != 1) ;
}

TEST_CASE("Testing peek() method - does 'out_of_range' error get thrown if stack is empty")
{
	intStack stack1 ;
	bool isError = false ;
	try {
		stack1.pop() ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	} catch(...) {
		isError = false ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("Testing pop() method - do values get removed")
{
	intStack stack1 = {1,2,3,4,5,6} ;
	stack1.pop() ;
	REQUIRE(stack1.pop() == 5) ;
}

TEST_CASE("Testing pop() method - do the correct values get removed")
{
	intStack stack1 = {1,2,3,4,5,6} ;
	auto poppedVal = stack1.pop() ;
	REQUIRE(poppedVal == 6) ;
	REQUIRE(poppedVal != 1) ;
}

TEST_CASE("Testing pop() method - does 'out_of_range' error get thrown if stack is empty")
{
	intStack stack1 = {1,2,3,4,5,6} ;
	stack1.pop() ;
	stack1.pop() ;
	stack1.pop() ;
	stack1.pop() ;
	stack1.pop() ;
	stack1.pop() ;
	bool isError = false ;
	try {
		stack1.pop() ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("Testing push() method - do values get added")
{
	intStack stack1 ;
	stack1.push(1) ;
	REQUIRE(stack1.pop() == 1) ;
}

TEST_CASE("Testing push() method - do values get added correctly when stack is empty")
{
	intStack stack1 ;
	stack1.push(1) ;
	REQUIRE(stack1.pop() == 1) ;
}

TEST_CASE("Testing push() method - do values get added correctly when stack has values")
{
	intStack stack1{1,2} ;
	stack1.push(3) ;
	REQUIRE(stack1.peek() == 3) ;
}
