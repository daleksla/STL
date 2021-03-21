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
	UniquePointer<int> sp ;
	REQUIRE(sp.pointer == nullptr) ;
}

TEST_CASE("Regular Constructor")
{
	UniquePointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
}

TEST_CASE("Move Constructor")
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

TEST_CASE("Value assignment operator (template value)")
{
	UniquePointer<int> sp ;
	sp = new int ;
	REQUIRE(sp.pointer != nullptr) ;
}

TEST_CASE("Value assignment operator (nullptr value)")
{
	UniquePointer<int> sp ;
	sp = nullptr ;
	REQUIRE(sp.pointer == nullptr) ;
}

TEST_CASE("Move assignment")
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

TEST_CASE("Reset method")
{
	UniquePointer<int> sp(new int) ;
	REQUIRE(sp.pointer != nullptr) ;
	sp.reset() ;
	REQUIRE(sp.pointer == nullptr) ;
}
