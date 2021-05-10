/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <lib/Structures/Contiguous/vector.hpp>
#include <lib/Structures/Contiguous/array.hpp>
#include <lib/Structures/LinkedLists/list.hpp>
#include <lib/Algorithms/Searches/binarySearch.hpp>
#include <lib/Algorithms/Searches/interpolationSearch.hpp>
#include <lib/Algorithms/Searches/linearSearch.hpp>

typedef Salih::Structures::LinkedLists::List<int> intList ;
typedef Salih::Structures::Contiguous::Array<float,4> floatArr ;
typedef Salih::Structures::Contiguous::Vector<float> floatVec ;
typedef Salih::Structures::LinkedLists::FwdList<double> doubleFwdList ;

/* linear search */
TEST_CASE("linear search - does it find valid value at start of list?")
{
	intList list1{1,3,2} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list1,1) == true) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list2,3) == true) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list3,3) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list4,3) == true) ;
}

TEST_CASE("linear search - does it find valid value in middle of list?")
{
	intList list1{1,3,2} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list1,3) == true) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list2,6) == true) ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list2,4) == true) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list3,6) == true) ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list3,4) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list4,6) == true) ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list4,4) == true) ;
}

TEST_CASE("linear search - does it find valid value at end of list?")
{
	intList list1{1,3,2} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list1,2) == true) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list2,5) == true) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list3,5) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list4,5) == true) ;
}

TEST_CASE("linear search - does it find invalid value in list?")
{
	intList list1{1,3,2} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list1,10) == false) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list2,20) == false) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list3,30) == false) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list4,30) == false) ;
}

TEST_CASE("linear search - does it find value in empty list?")
{
	intList list1{} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list1,2) == false) ;
	floatVec list2{} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list2,5) == false) ;
	floatArr list3{} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list3,5) == false) ;
	doubleFwdList list4{} ;
	REQUIRE(Salih::Algorithms::Searches::linearSearch(list4,5) == false) ;
}

/* binary search */
TEST_CASE("binary search - does it find valid value at start of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list1,1) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list2,3) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list4,3) == true) ;
}

TEST_CASE("binary search - does it find valid value(s) in middle of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list1,2) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list2,4) == true) ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list2,5) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list4,4) == true) ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list4,5) == true) ;
}

TEST_CASE("binary search - does it find valid value at end of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list1,3) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list2,6) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list4,6) == true) ;	
}

TEST_CASE("binary search - does it find invalid value in list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list1,10) == false) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list2,20) == false) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list4,30) == true) ;
}

TEST_CASE("binary search - does it find value in empty list?")
{
	intList list1{} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list1,2) == false) ;
	floatVec list2{} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list2,5) == false) ;
	doubleFwdList list4{} ;
	REQUIRE(Salih::Algorithms::Searches::binarySearch(list4,30) == true) ;
}

/* interpolation search */
TEST_CASE("interpolation search - does it find valid value at start of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list1,1) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list2,3) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list4,3) == true) ;
}

TEST_CASE("interpolation search - does it find valid value in middle of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list1,2) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list2,4) == true) ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list2,5) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list4,4) == true) ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list4,5) == true) ;
}

TEST_CASE("interpolation search - does it find valid value at end of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list1,3) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list2,6) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list4,6) == true) ;
}

TEST_CASE("interpolation search - does it find invalid value in list?")
{
	intList list1{1,2,3} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list1,10) == false) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list2,20) == false) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list4,30) == true) ;
}

TEST_CASE("interpolation search - does it find value in empty list?")
{
	intList list1{} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list1,2) == false) ;
	floatVec list2{} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list2,5) == false) ;
	doubleFwdList list4{} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list4,30) == true) ;
}

TEST_CASE("interpolation search - does it find in unevenly (yet ordered) list?")
{
	intList list1{1,2,4,5,8,11,12} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list1,8) == true) ;
	floatVec list2{1,2,4,5,8,11,12} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list2,8) == false) ;
	doubleFwdList list4{1,2,4,5,8,11,12} ;
	REQUIRE(Salih::Algorithms::Searches::interpolationSearch(list4,8) == true) ;
}
