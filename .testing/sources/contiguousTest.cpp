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

TEST_CASE("Indexing structures (using 'at' method) - exception thrown only if index too large")
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
		Array<int,3> arr{1,2,3} ;
		arr.at(4) ;
	} catch(std::out_of_range)
	{
		exceptionCount += 1 ;
	}
	
	try {
		Array<int,3> arr{1,2,3} ;
		arr.at(2) ;
	} catch(std::out_of_range)
	{
		exceptionCount += 1 ;
	}
	
	REQUIRE(exceptionCount == 2) ;
}

TEST_CASE("Indexing structures (using 'at' method) - exception not thrown if bool checking flag set to false")
{
	int exceptionCount = 0 ;
	try {
		Vector<int> vec2{1,2,3} ;
		vec2.at(4, false) ;
	} catch(std::out_of_range)
	{
		exceptionCount += 1 ;
	}
	
	try {
		Array<int,3> arr{1,2,3} ;
		arr.at(4, false) ;
	} catch(std::out_of_range)
	{
		exceptionCount += 1 ;
	}
	REQUIRE(exceptionCount == 0) ;
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

TEST_CASE("Inequality comparison operators between two containers with different types within")
{
	REQUIRE((Vector<float>{1} != Vector<int>{1}) == 0) ;
	REQUIRE((Array<float,1>{1} != Array<int,1>{1}) == 0) ;
	REQUIRE((Vector<float>{1} != Array<int,1>{1}) == 0) ;
}

///* Array class methods *///
TEST_CASE("Empty constructor - array")
{
	Array<int,3> ss ;
	REQUIRE(ss.size == 3) ;
	REQUIRE(ss.pointer != nullptr) ;
}

TEST_CASE("Regular constructor - array")
{
	Array<int,3> ss{1,2,3} ;
	REQUIRE(ss.size == 3) ;
	REQUIRE(ss[0] == 1) ;
	REQUIRE(ss[1] == 2) ;
	REQUIRE(ss[2] == 3) ;
	REQUIRE(ss.pointer != nullptr) ;
}

TEST_CASE("Copy constructor - array")
{
	Array<int,3> ss{1,2,3} ;
	Array<int,3> ff(ss) ;
	REQUIRE(ss.size == ff.size) ;
	REQUIRE(ff.pointer != nullptr) ;
	REQUIRE(ff.pointer != ss.pointer) ;
}

TEST_CASE("Move constructor - array")
{
	Array<int,3> ss{1,2,3} ;
	auto ptr = ss.pointer ;
	auto sz = ss.size ;
	Array<int,3> ff(std::move(ss)) ;
	REQUIRE(ff.size == sz) ;
	REQUIRE(ff.pointer == ptr) ;
	REQUIRE(ss.size == 0) ;
	REQUIRE(ss.pointer == nullptr) ;
}

TEST_CASE("value assignment - array")
{
	Array<int,3> ss ;
	ss = {1,2,3} ;
	REQUIRE(ss.size == 3) ;
	REQUIRE(ss[0] == 1) ;
	REQUIRE(ss[1] == 2) ;
	REQUIRE(ss[2] == 3) ;
}

TEST_CASE("l-value array assignment - array")
{
	Array<int,3> ss{1,2,3} ;
	Array<int,3> ff = ss ;
	REQUIRE(ss.size == 3) ;
	REQUIRE(ff.size == 3) ;
	REQUIRE(ff.pointer != ss.pointer) ;
}

TEST_CASE("r-value array assignment - array")
{
	Array<int,3> ss{1,2,3} ;
	auto ptr = ss.pointer ;
	auto sz = ss.size ;
	Array<int,3> f = std::move(ss) ;
	REQUIRE(f.size == sz) ;
	REQUIRE(f.pointer == ptr) ;
	REQUIRE(ss.size == 0) ;
	REQUIRE(ss.pointer == nullptr) ;
}

///* Vector class methods *///
TEST_CASE("Empty constructor - vector")
{
	Vector<int> ss ;
	REQUIRE(ss.size == 0) ;
	REQUIRE(ss.pointer != nullptr) ;
}

TEST_CASE("size-providing constructor - vector")
{
	Vector<int> ss(3) ;
	REQUIRE(ss.size == 3) ;
	REQUIRE(ss.pointer != nullptr) ;
}

TEST_CASE("value-providing constructor - vector")
{
	Vector<int> ss{1,2,3} ;
	REQUIRE(ss.size == 3) ;
	REQUIRE(ss.pointer != nullptr) ;
}

TEST_CASE("Copy constructor - vector")
{
	Vector<int> ss{1,2,3} ;
	Vector<int> ff(ss) ;
	REQUIRE(ss.size == ff.size) ;
	REQUIRE(ff.pointer != ss.pointer) ;
}

TEST_CASE("Move constructor - vector")
{
	Vector<int> ss{1,2,3} ;
	auto ptr = ss.pointer ;
	auto sz = ss.size ;
	Vector<int> ff(std::move(ss)) ;
	REQUIRE(ff.size == sz) ;
	REQUIRE(ff.pointer == ptr) ;
	REQUIRE(ss.size == 0) ;
	REQUIRE(ss.pointer == nullptr) ;
}

TEST_CASE("value assignment - vector")
{
	Vector<int> ss ;
	ss = {1,2,3} ;
	REQUIRE(ss.size == 3) ;
	REQUIRE(ss[0] == 1) ;
	REQUIRE(ss[1] == 2) ;
	REQUIRE(ss[2] == 3) ;
}

TEST_CASE("l-value vector assignment - vector")
{
	Vector<int> ss{1,2,3} ;
	Vector<int> ff = ss ;
	REQUIRE(ss.size == ff.size) ;
	REQUIRE(ff.pointer != ss.pointer) ;
}

TEST_CASE("r-value vector assignment - vector")
{
	Vector<int> ss{1,2,3} ;
	auto ptr = ss.pointer ;
	auto sz = ss.size ;
	Vector<int> f = std::move(ss) ;
	REQUIRE(f.size == sz) ;
	REQUIRE(f.pointer == ptr) ;
	REQUIRE(ss.size == 0) ;
	REQUIRE(ss.pointer == nullptr) ;
}

TEST_CASE("append method - vector")
{
	Vector<int> ss{1,2,3} ;
	REQUIRE(ss.size == 3) ;
	ss.append(4) ;
	REQUIRE(ss.size == 4) ;
	REQUIRE(ss[3] == 4) ;
}

TEST_CASE("clear method - vector")
{
	Vector<int> ss{1,2,3} ;
	REQUIRE(ss.size == 3) ;
	ss.clear() ;
	REQUIRE(ss.size == 0) ;
	REQUIRE(ss.pointer != nullptr) ;
}
