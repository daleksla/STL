/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include "../../containers/vector.hpp"
#include "../../containers/array.hpp"
#include "../../containers/list.hpp"
#include "../../containers/fwd-list.hpp"
#include "../../algorithms/sorts.hpp"

typedef salih::containers::List<int> intList ;
typedef salih::containers::FwdList<double> doubleFwdList ;
typedef salih::containers::Array<float,4> floatArr ;
typedef salih::containers::Vector<float> floatVec ;

//** Sorts themselves **//

/* bubble sort */
TEST_CASE("bubble sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::bubbleSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::bubbleSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = salih::algorithms::bubbleSort(list3) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::bubbleSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("bubble sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::bubbleSort(list1, salih::algorithms::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::bubbleSort(list2, salih::algorithms::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = salih::algorithms::bubbleSort(list3, salih::algorithms::ASCEND) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::bubbleSort(list4, salih::algorithms::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("bubble sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::bubbleSort(list1, salih::algorithms::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::bubbleSort(list2, salih::algorithms::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	floatArr list3{3,6,4,5} ;
	list3 = salih::algorithms::bubbleSort(list3, salih::algorithms::DESCEND) ;
	REQUIRE(list3 == floatArr{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::bubbleSort(list4, salih::algorithms::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

/* selection sort */
TEST_CASE("selection sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::selectionSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::selectionSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = salih::algorithms::selectionSort(list3) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::selectionSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("selection sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::selectionSort(list1, salih::algorithms::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::selectionSort(list2, salih::algorithms::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = salih::algorithms::selectionSort(list3, salih::algorithms::ASCEND) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::selectionSort(list4, salih::algorithms::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("selection sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::selectionSort(list1, salih::algorithms::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::selectionSort(list2, salih::algorithms::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	floatArr list3{3,6,4,5} ;
	list3 = salih::algorithms::selectionSort(list3, salih::algorithms::DESCEND) ;
	REQUIRE(list3 == floatArr{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::selectionSort(list4, salih::algorithms::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

/* merge sort */
TEST_CASE("merge sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::mergeSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::mergeSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::mergeSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("merge sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::mergeSort(list1, salih::algorithms::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::mergeSort(list2, salih::algorithms::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::mergeSort(list4, salih::algorithms::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("merge sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::mergeSort(list1, salih::algorithms::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::mergeSort(list2, salih::algorithms::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::mergeSort(list4, salih::algorithms::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

/* quick sort */

TEST_CASE("quick sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::quickSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::quickSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::quickSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("quick sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::quickSort(list1, salih::algorithms::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::quickSort(list2, salih::algorithms::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::quickSort(list4, salih::algorithms::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("quick sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = salih::algorithms::quickSort(list1, salih::algorithms::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = salih::algorithms::quickSort(list2, salih::algorithms::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = salih::algorithms::quickSort(list4, salih::algorithms::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

//** helper functions **//

/* flags */
TEST_CASE("does ASCEND function pointer / flag return correct value based on values provided")
{
	REQUIRE(salih::algorithms::ASCEND(2,1) == false) ;
	REQUIRE(salih::algorithms::ASCEND(1,2) == true) ;
	REQUIRE(salih::algorithms::ASCEND(2,2) == false) ;
}

TEST_CASE("does DESCEND function pointer / flag return correct values based on values provided")
{
	REQUIRE(salih::algorithms::DESCEND(2,1) == true) ;
	REQUIRE(salih::algorithms::DESCEND(1,2) == false) ;
	REQUIRE(salih::algorithms::DESCEND(2,2) == false) ;
}
