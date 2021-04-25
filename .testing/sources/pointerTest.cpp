/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#define protected public
#include <lib/Types/pointers.hpp>
using namespace Salih::Types ;

struct Test 
{
	int val = 2 ;
} ;

/* Note: since this is a virtual class, this section will only test full inherited methods aswell as 'principles'
 * These methods will be accessed interchangeably between both child classes - the methods are identical */

TEST_CASE("Testing arrow (->) operator value")
{
	UniquePointer<Test> up  = new Test ;
	REQUIRE(up->val == 2) ;
}

TEST_CASE("Testing dereferncing (*) operator")
{
	SharedPointer<int> sp ;
	sp = new int ;
	*sp = 2 ;
	REQUIRE(*sp == 2) ;
}

TEST_CASE("Testing 'get()' method")
{
	int* p = new int ;
	UniquePointer<int> up ;
	up = p ;
	REQUIRE(up.get() == p) ;
}

TEST_CASE("Testing differentiation between stack and heap pointers")
{
	/* As part of an effort to prevent mistakes regarding allocation, freeing etc., the pointer is checked regarding where it points */
	bool status = false ;
	bool* data = &status ;
	
	REQUIRE(isHeap(data) == false) ;
	
	status = true ;
	data = new bool ;
	//code 
	REQUIRE(isHeap(data) == true) ;

	delete data ;
}

/* Shared Pointers */

TEST_CASE("Empty Constructor - shared pointer ")
{
	SharedPointer<int> sp ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
}

TEST_CASE("Regular Constructor - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Copy Constructor - shared pointer ")
{
	SharedPointer<int> sp ;
	SharedPointer<int> sp2(sp) ;
	REQUIRE(sp.pointer == sp2.pointer) ;
	REQUIRE(sp.count == sp2.count) ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
	sp = new int ;
	*(sp) = 1 ;
	SharedPointer<int> sp3(sp) ;
	REQUIRE(sp.pointer == sp3.pointer) ;
	REQUIRE(sp.count == sp3.count) ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Move Constructor - shared pointer ")
{
	SharedPointer<int> sp ;
	sp = new int ;
	*sp = 1 ;
	auto h = sp.pointer ;
	auto c = sp.count ;
	SharedPointer<int> sp2(std::move(sp)) ;
	REQUIRE(sp2.pointer != nullptr) ;
	REQUIRE(sp2.count != nullptr) ;
	REQUIRE(sp2.pointer == h) ;
	REQUIRE(sp2.count == c) ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
}

/* Assignment operators */

TEST_CASE("Value assignment operator (template value) - shared pointer ")
{
	SharedPointer<int> sp ;
	sp = new int ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Value assignment operator (nullptr value) - shared pointer ")
{
	SharedPointer<int> sp ;
	sp = nullptr ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
}

TEST_CASE("Copy assignment - shared pointer ")
{
	SharedPointer<int> sp ;
	SharedPointer<int> sp2 ;
	sp2 = sp ;
	REQUIRE(sp.pointer == sp2.pointer) ;
	REQUIRE(sp.count == sp2.count) ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
	sp = new int ;
	*sp = 1 ;
	SharedPointer<int> sp3 ;
	sp3 = sp ;
	REQUIRE(sp.pointer == sp3.pointer) ;
	REQUIRE(sp.count == sp3.count) ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Move assignment - shared pointer ")
{
	SharedPointer<int> sp ;
	sp = new int ;
	*sp = 1 ;
	auto h = sp.pointer ;
	auto c = sp.count ;
	SharedPointer<int> sp2 = std::move(sp) ;
	REQUIRE(sp2.pointer != nullptr) ;
	REQUIRE(sp2.count != nullptr) ;
	REQUIRE(sp2.pointer == h) ;
	REQUIRE(sp2.count == c) ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
	SharedPointer<int> sp3 ;
	sp3 = std::move(sp) ;
}

/* Methods */

TEST_CASE("Reset method for one-sharing pointer - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
	REQUIRE(*(sp.count) == 1) ;
	sp.reset() ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
}

TEST_CASE("Reset method for two or more-sharing pointer - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
	SharedPointer<int> sp2(sp) ;
	REQUIRE(*(sp.count) == 2) ;
	sp.reset() ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
	REQUIRE(sp2.pointer != nullptr) ;
	REQUIRE(sp2.count != nullptr) ;
	REQUIRE(*(sp2.count) == 1) ;
	
}

/* Further testing (testing reference count value, memory pointing, whether values are shared) */

TEST_CASE("Reference count - value at initialisation - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(*(sp.count) == 1) ;
}

TEST_CASE("Reference count - value when copying - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	SharedPointer<int> sp2(sp) ;
	REQUIRE(*(sp.count) == 2) ;
	REQUIRE(*(sp2.count) == 2) ;
	SharedPointer<int> sp3(sp2) ;
	REQUIRE(*(sp.count) == 3) ;
	REQUIRE(*(sp2.count) == 3) ;
	REQUIRE(*(sp3.count) == 3) ;
}

TEST_CASE("Reference count - value when moving - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	SharedPointer<int> sp2(std::move(sp)) ;
	REQUIRE(*(sp2.count) == 1) ; 
	
	SharedPointer<int> sp3(SharedPointer<int>(new int)) ;
	REQUIRE(*(sp3.count) == 1) ; 
}

TEST_CASE("Reference count - address at initialisation - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Reference count - address when copying - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	SharedPointer<int> sp2(sp) ;
	REQUIRE(sp.count == sp2.count) ;
}

TEST_CASE("Reference count - address when moving - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	auto countAddress = sp.count ;
	SharedPointer<int> sp2(std::move(sp)) ;
	REQUIRE(sp2.count == countAddress) ; 
}

TEST_CASE("Pointer address at initialisation - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
}

TEST_CASE("Pointer address when copying - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	SharedPointer<int> sp2(sp) ;
	REQUIRE(sp.pointer == sp2.pointer) ;
}

TEST_CASE("Pointer address when moving - shared pointer ")
{
	SharedPointer<int> sp(new int) ;
	auto pointer1 = sp.pointer ;
	SharedPointer<int> sp2(std::move(sp)) ;
	REQUIRE(pointer1 == sp2.pointer) ;
}

/* Unique Pointers */

TEST_CASE("Empty Constructor - unique pointer ")
{
	UniquePointer<int> sp ;
	REQUIRE(sp.pointer == nullptr) ;
}

TEST_CASE("Regular Constructor - unique pointer ")
{
	UniquePointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
}

TEST_CASE("Move Constructor - unique pointer ")
{
	UniquePointer<int> sp ;
	sp = new int ;
	*sp = 1 ;
	auto h = sp.pointer ;
	UniquePointer<int> sp2(std::move(sp)) ;
	REQUIRE(sp2.pointer != nullptr) ;
	REQUIRE(sp2.pointer == h) ;
	REQUIRE(sp.pointer == nullptr) ;
}

/* Assignment operators */

TEST_CASE("Value assignment operator (template value) - unique pointer ")
{
	UniquePointer<int> sp ;
	sp = new int ;
	REQUIRE(sp.pointer != nullptr) ;
}

TEST_CASE("Value assignment operator (nullptr value) - unique pointer ")
{
	UniquePointer<int> sp ;
	sp = nullptr ;
	REQUIRE(sp.pointer == nullptr) ;
}

TEST_CASE("Move assignment - unique pointer ")
{
	UniquePointer<int> sp ;
	sp = new int ;
	*sp = 1 ;
	auto h = sp.pointer ;
	UniquePointer<int> sp2 = std::move(sp) ;
	REQUIRE(sp2.pointer != nullptr) ;
	REQUIRE(sp2.pointer == h) ;
	REQUIRE(sp.pointer == nullptr) ;
	UniquePointer<int> sp3 ;
	sp3 = std::move(sp) ;
}

/* Methods */

TEST_CASE("Reset method - unique pointer ")
{
	UniquePointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
	sp.reset() ;
	REQUIRE(sp.pointer == nullptr) ;
}
