/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include <testing/catch.hpp>

/* Include the code that we plan to test */
#include <lib/Types/stack.hpp>
#include <string>
#include <iostream>
#include <stdexcept>

typedef Salih::Types::Stack<int> intStack ;

/* Create sub-categories to test with predicted outcomes */
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
