/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define private public
#define protected public
/* Include the code that we plan to test */
#include <lib/Types/queue.hpp>
#include <string>
#include <iostream>
#include <stdexcept>

typedef Salih::Types::Queue<int> intQueue ;
typedef Salih::Types::Queue<float> floatQueue ;

/* Create sub-categories to test with predicted outcomes */
TEST_CASE("empty constructor - attribute testing")
{
	intQueue list1 ;
	REQUIRE(list1.head == NULL) ;
	REQUIRE(list1.tail == NULL) ;
	REQUIRE(list1.size == 0) ;
}

TEST_CASE("regular constructor - attribute testing")
{
	intQueue list1{1,2,3,4} ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list1.head->getNext()->getNext()->getNext() == list1.tail) ;
	REQUIRE(list1.tail->getPrev()->getPrev()->getPrev() == list1.head) ;
}

TEST_CASE("regular constructor - value testing")
{
	intQueue list1{1,2,3,4} ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
}

TEST_CASE("copy constructor - attribute testing")
{
	intQueue list1{1,2,3,4} ;
	intQueue list3(list1) ;
	REQUIRE(list1.head != list3.head) ;
	REQUIRE(list1.tail != list3.tail) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("copy constructor - value testing")
{
	intQueue list1{1,2,3,4} ;
	intQueue list3(list1) ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list3.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
	REQUIRE(list3.tail->data == 4) ;
}

TEST_CASE("move constructor - attribute testing")
{
	intQueue list2(intQueue{1,2,3,4}) ;
	REQUIRE(list2.head != NULL) ;
	REQUIRE(list2.tail != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.head ;
	auto t = list2.tail ;
	intQueue list3 = std::move(list2) ;
	REQUIRE(list3.head == h) ;
	REQUIRE(list3.tail == t) ;	
}

TEST_CASE("move constructor - value testing")
{
	intQueue list2(intQueue{1,2,3,4}) ;
	REQUIRE(list2.head->data == 1) ;
	REQUIRE(list2.tail->data == 4) ;
}

/* Assignment Operators */
TEST_CASE("assigning values using operator to list - attribute testing")
{
	intQueue list1{1,2,3,4} ;
	list1 = {1,2,3,43} ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list1.head->getNext()->getNext()->getNext() == list1.tail) ;
	REQUIRE(list1.tail->getPrev()->getPrev()->getPrev() == list1.head) ;
}

TEST_CASE("assigning values using operator to list - value testing")
{
	intQueue list1 = {1,2,3,4} ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
}

TEST_CASE("assigning created list using operator to list - attribute testing")
{
	intQueue list1{1,2,3,4} ;
	intQueue list3 = list1 ;
	REQUIRE(list1.head != list3.head) ;
	REQUIRE(list1.tail != list3.tail) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("assigning created list using operator to list - value testing")
{
	intQueue list1{1,2,3,4} ;
	intQueue list3 = list1 ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list3.head->data == 1) ;
	REQUIRE(list1.tail->data == 4) ;
	REQUIRE(list3.tail->data == 4) ;
}

TEST_CASE("assigning r-value / temporary list using operator to list - attribute testing")
{
	intQueue list2 = intQueue{1,2,3,4} ;
	REQUIRE(list2.head != NULL) ;
	REQUIRE(list2.tail != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.head ;
	auto t = list2.tail ;
	intQueue list3 = std::move(list2) ;
	REQUIRE(list3.head == h) ;
	REQUIRE(list3.tail == t) ;	
}

TEST_CASE("assigning r-value / temporary list using operator to list - value testing")
{
	intQueue list2 = intQueue{1,2,3,4} ;
	REQUIRE(list2.head->data == 1) ;
	REQUIRE(list2.tail->data == 4) ;
}

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

/* Comparison operators */
TEST_CASE("Comparing for equality between two stacks of the same type")
{
	intQueue queue1{1,2} ;
	intQueue queue2{1,2} ;
	REQUIRE((queue1 == queue2) == 1) ;
}

TEST_CASE("Comparing for equality between two stacks of different types")
{
	intQueue queue1{1,2} ;
	floatQueue queue2{1,2} ;
	REQUIRE((queue1 == queue2) == 1) ;
}

TEST_CASE("Comparing for inequality between two stacks of the same type")
{
	intQueue queue1{1,2} ;
	intQueue queue2{1,2,3} ;
	REQUIRE((queue1 != queue2) == 1) ;
}

TEST_CASE("Comparing for inequality between two stacks of different types")
{
	intQueue queue1{1,2} ;
	floatQueue queue2{1,2,3} ;
	REQUIRE((queue1 != queue2) == 1) ;
}
