/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include "../../containers/vector.hpp"
#include "../../containers/array.hpp"
#include "../../containers/fwd-list.hpp"
#include "../../containers/list.hpp"
#include "../../algorithms/searches.hpp"

typedef salih::containers::List<int> intList ;
typedef salih::containers::Array<float,4> floatArr ;
typedef salih::containers::Vector<float> floatVec ;
typedef salih::containers::FwdList<double> doubleFwdList ;

/* linear search */
TEST_CASE("linear search - does it find valid value at start of list?")
{
	intList list1{1,3,2} ;
	REQUIRE(salih::algorithms::linearSearch(list1,1) == true) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list2,3) == true) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list3,3) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list4,3) == true) ;
}

TEST_CASE("linear search - does it find valid value in middle of list?")
{
	intList list1{1,3,2} ;
	REQUIRE(salih::algorithms::linearSearch(list1,3) == true) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list2,6) == true) ;
	REQUIRE(salih::algorithms::linearSearch(list2,4) == true) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list3,6) == true) ;
	REQUIRE(salih::algorithms::linearSearch(list3,4) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list4,6) == true) ;
	REQUIRE(salih::algorithms::linearSearch(list4,4) == true) ;
}

TEST_CASE("linear search - does it find valid value at end of list?")
{
	intList list1{1,3,2} ;
	REQUIRE(salih::algorithms::linearSearch(list1,2) == true) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list2,5) == true) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list3,5) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list4,5) == true) ;
}

TEST_CASE("linear search - does it find invalid value in list?")
{
	intList list1{1,3,2} ;
	REQUIRE(salih::algorithms::linearSearch(list1,10) == false) ;
	floatVec list2{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list2,20) == false) ;
	floatArr list3{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list3,30) == false) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(salih::algorithms::linearSearch(list4,30) == false) ;
}

TEST_CASE("linear search - does it find value in empty list?")
{
	intList list1{} ;
	REQUIRE(salih::algorithms::linearSearch(list1,2) == false) ;
	floatVec list2{} ;
	REQUIRE(salih::algorithms::linearSearch(list2,5) == false) ;
	floatArr list3{} ;
	REQUIRE(salih::algorithms::linearSearch(list3,5) == false) ;
	doubleFwdList list4{} ;
	REQUIRE(salih::algorithms::linearSearch(list4,5) == false) ;
}

/* binary search */
TEST_CASE("binary search - does it find valid value at start of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::binarySearch(list1,1) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::binarySearch(list2,3) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(salih::algorithms::binarySearch(list4,3) == true) ;
}

TEST_CASE("binary search - does it find valid value(s) in middle of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::binarySearch(list1,2) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::binarySearch(list2,4) == true) ;
	REQUIRE(salih::algorithms::binarySearch(list2,5) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(salih::algorithms::binarySearch(list4,4) == true) ;
	REQUIRE(salih::algorithms::binarySearch(list4,5) == true) ;
}

TEST_CASE("binary search - does it find valid value at end of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::binarySearch(list1,3) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::binarySearch(list2,6) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(salih::algorithms::binarySearch(list4,6) == true) ;	
}

TEST_CASE("binary search - does it find invalid value in list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::binarySearch(list1,10) == false) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::binarySearch(list2,20) == false) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(salih::algorithms::binarySearch(list4,30) == false) ;
}

TEST_CASE("binary search - does it find value in empty list?")
{
	intList list1{} ;
	REQUIRE(salih::algorithms::binarySearch(list1,2) == false) ;
	floatVec list2{} ;
	REQUIRE(salih::algorithms::binarySearch(list2,5) == false) ;
	doubleFwdList list4{} ;
	REQUIRE(salih::algorithms::binarySearch(list4,30) == false) ;
}

/* interpolation search */
TEST_CASE("interpolation search - does it find valid value at start of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::interpolationSearch(list1,1) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::interpolationSearch(list2,3) == true) ;
	doubleFwdList list4{3,6,4,5} ;
	REQUIRE(salih::algorithms::interpolationSearch(list4,3) == true) ;
}

TEST_CASE("interpolation search - does it find valid value in middle of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::interpolationSearch(list1,2) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::interpolationSearch(list2,4) == true) ;
	REQUIRE(salih::algorithms::interpolationSearch(list2,5) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(salih::algorithms::interpolationSearch(list4,4) == true) ;
	REQUIRE(salih::algorithms::interpolationSearch(list4,5) == true) ;
}

TEST_CASE("interpolation search - does it find valid value at end of list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::interpolationSearch(list1,3) == true) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::interpolationSearch(list2,6) == true) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(salih::algorithms::interpolationSearch(list4,6) == true) ;
}

TEST_CASE("interpolation search - does it find invalid value in list?")
{
	intList list1{1,2,3} ;
	REQUIRE(salih::algorithms::interpolationSearch(list1,10) == false) ;
	floatVec list2{3,4,5,6} ;
	REQUIRE(salih::algorithms::interpolationSearch(list2,20) == false) ;
	doubleFwdList list4{3,4,5,6} ;
	REQUIRE(salih::algorithms::interpolationSearch(list4,30) == false) ;
}

TEST_CASE("interpolation search - does it find value in empty list?")
{
	intList list1{} ;
	REQUIRE(salih::algorithms::interpolationSearch(list1,2) == false) ;
	floatVec list2{} ;
	REQUIRE(salih::algorithms::interpolationSearch(list2,5) == false) ;
	doubleFwdList list4{} ;
	REQUIRE(salih::algorithms::interpolationSearch(list4,30) == false) ;
}

TEST_CASE("interpolation search - does it find in unevenly (yet ordered) list?")
{
	intList list1{1,2,4,5,8,11,12} ;
	REQUIRE(salih::algorithms::interpolationSearch(list1,8) == true) ;
	floatVec list2{1,2,4,5,8,11,12} ;
	REQUIRE(salih::algorithms::interpolationSearch(list2,8) == true) ;
	doubleFwdList list4{1,2,4,5,8,11,12} ;
	REQUIRE(salih::algorithms::interpolationSearch(list4,8) == true) ;
}
