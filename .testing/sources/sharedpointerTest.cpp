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

/* Constructors */

TEST_CASE("Empty Constructor")
{
	SharedPointer<int> sp ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
}

TEST_CASE("Regular Constructor")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Copy Constructor")
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

TEST_CASE("Move Constructor")
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

TEST_CASE("Value assignment operator (template value)")
{
	SharedPointer<int> sp ;
	sp = new int ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Value assignment operator (nullptr value)")
{
	SharedPointer<int> sp ;
	sp = nullptr ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
}

TEST_CASE("Copy assignment")
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

TEST_CASE("Move assignment")
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

TEST_CASE("Reset method for one-sharing pointer")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
	REQUIRE(sp.count != nullptr) ;
	REQUIRE(*(sp.count) == 1) ;
	sp.reset() ;
	REQUIRE(sp.pointer == nullptr) ;
	REQUIRE(sp.count == nullptr) ;
}

TEST_CASE("Reset method for two or more-sharing pointer")
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

TEST_CASE("Reference count - value at initialisation")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(*(sp.count) == 1) ;
}

TEST_CASE("Reference count - value when copying")
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

TEST_CASE("Reference count - value when moving")
{
	SharedPointer<int> sp(new int) ;
	SharedPointer<int> sp2(std::move(sp)) ;
	REQUIRE(*(sp2.count) == 1) ; 
	
	SharedPointer<int> sp3(SharedPointer<int>(new int)) ;
	REQUIRE(*(sp3.count) == 1) ; 
}

TEST_CASE("Reference count - address at initialisation")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.count != nullptr) ;
}

TEST_CASE("Reference count - address when copying")
{
	SharedPointer<int> sp(new int) ;
	SharedPointer<int> sp2(sp) ;
	REQUIRE(sp.count == sp2.count) ;
}

TEST_CASE("Reference count - address when moving")
{
	SharedPointer<int> sp(new int) ;
	auto countAddress = sp.count ;
	SharedPointer<int> sp2(std::move(sp)) ;
	REQUIRE(sp2.count == countAddress) ; 
}

TEST_CASE("Pointer address at initialisation")
{
	SharedPointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
}

TEST_CASE("Pointer address when copying")
{
	SharedPointer<int> sp(new int) ;
	SharedPointer<int> sp2(sp) ;
	REQUIRE(sp.pointer == sp2.pointer) ;
}

TEST_CASE("Pointer address when moving")
{
	SharedPointer<int> sp(new int) ;
	auto pointer1 = sp.pointer ;
	SharedPointer<int> sp2(std::move(sp)) ;
	REQUIRE(pointer1 == sp2.pointer) ;
}
