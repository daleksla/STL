/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include <lib/Structures/Contiguous/vector.hpp>
#include <lib/Structures/Contiguous/array.hpp>
using namespace Salih::Structures::Contiguous ;

//** Create sub-categories to test with predicted outcomes **//

///* Base class methods *///
TEST_CASE("Getting size of structures")
{
	Vector<int> vec(3) ;
	REQUIRE(vec.getSize() == 3) ;
	Vector<int> vec2{1,2,3} ;
	REQUIRE(vec2.getSize() == 3) ;
	Array<int,3> arr ;
	REQUIRE(arr.getSize() == 3) ;	
}

TEST_CASE("Indexing structures (using [] operator)")
{
	Vector<int> vec2{1,2,3} ;
	REQUIRE(vec2[2] == 3) ;
	Array<int,3> arr{1,2,3} ;
	REQUIRE(arr[2] == 3) ;
}

TEST_CASE("Indexing structures (using 'at' method) - correct value returned")
{
	Vector<int> vec2{1,2,3} ;
	REQUIRE(vec2.at(2) == 3) ;
	Array<int,3> arr{1,2,3} ;
	REQUIRE(arr.at(2) == 3) ;
}

TEST_CASE("Indexing structures (using 'at' method) - exception thrown")
{
	int exceptionCount = 0 ;
	try {
		Vector<int> vec2{1,2,3} ;
		vec2.at(4) ;
	} catch(std::out_of_range)
	{
		exceptionCount += 1 ;
	}
	
	try {
		ARRAY<int,3> arr{1,2,3} ;
		arr.at(4) ;
	} catch(std::out_of_range)
	{
		exceptionCount += 1 ;
	}
	REQUIRE(exceptionCount == 2) ;
}

TEST_CASE("Equality comparison operators between two containers with same types within")
{
	REQUIRE(Vector<int>{1} == Vector<int>{1}) ;
	REQUIRE(Array<int,1>{1} == Array<int,1>{1}) ;
	REQUIRE(Vector<int>{1} == Array<int,1>{1}) ;
}

TEST_CASE("Inequality comparison operators between two containers with same types within")
{
	REQUIRE((Vector<int>{1} != Vector<int>{1}) == 0) ;
	REQUIRE((Array<int,1>{1} != Array<int,1>{1}) == 0) ;
	REQUIRE((Vector<int>{1} != Array<int,1>{1}) == 0) ;
}

TEST_CASE("Equality comparison operators between two containers with different types within")
{
	REQUIRE(Vector<float>{1} == Vector<int>{1}) ;
	REQUIRE(Array<float,1>{1} == Array<int,1>{1}) ;
	REQUIRE(Vector<float>{1} == Array<int,1>{1}) ;
}

TEST_CASE("Inequality comparison operators between two containers with same types within")
{
	REQUIRE((Vector<float>{1} != Vector<int>{1}) == 0) ;
	REQUIRE((Array<float,1>{1} != Array<int,1>{1}) == 0) ;
	REQUIRE((Vector<float>{1} != Array<int,1>{1}) == 0) ;
}

///* Array class methods *///

///* Vector class methods *///
