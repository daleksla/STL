/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include <testing/catch.hpp>

/* Include the code that we plan to test */
#include <lib/Types/queue.hpp>
#include <string>
#include <iostream>
#include <stdexcept>

typedef Salih::Types::Queue<int> intQueue ;

/* Create sub-categories to test with predicted outcomes */
TEST_CASE("Testing peek() method - correct value returned")
{
	intQueue queue1 = {1,2,3,4,5,6} ;
	REQUIRE(queue1.peek() == 1) ;
	REQUIRE(queue1.peek() == 1) ;
}

TEST_CASE("Testing peek() method - does 'out_of_range' error get thrown if queue is empty")
{
	intQueue queue1 ;
	bool isError = false ;
	try {
		queue1.pop() ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	} catch(...) {
		isError = false ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("Testing pop() method - do values get removed")
{
	intQueue queue1 = {1,2,3,4,5,6} ;
	queue1.pop() ;
	REQUIRE(queue1.pop() == 2) ;
}

TEST_CASE("Testing pop() method - do the correct values get removed")
{
	intQueue queue1 = {1,2,3,4,5,6} ;
	auto poppedVal = queue1.pop() ;
	REQUIRE(poppedVal != 6) ;
	REQUIRE(poppedVal == 1) ;
}

TEST_CASE("Testing pop() method - does 'out_of_range' error get thrown if queue is empty")
{
	intQueue queue1 = {1,2,3,4,5,6} ;
	queue1.pop() ;
	queue1.pop() ;
	queue1.pop() ;
	queue1.pop() ;
	queue1.pop() ;
	queue1.pop() ;
	bool isError = false ;
	try {
		queue1.pop() ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("Testing push() method - do values get added")
{
	intQueue queue1 ;
	queue1.push(1) ;
	REQUIRE(queue1.pop() == 1) ;
}

TEST_CASE("Testing push() method - do values get added correctly when queue is empty")
{
	intQueue queue1 ;
	queue1.push(1) ;
	REQUIRE(queue1.pop() == 1) ;
}

TEST_CASE("Testing push() method - do values get added correctly when queue has values")
{
	intQueue queue1{1,2} ;
	queue1.push(2) ;
	REQUIRE(queue1.peek() == 1) ;
}
