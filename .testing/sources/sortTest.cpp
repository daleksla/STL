/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include "../../Structures/Contiguous/vector.hpp"
#include "../../Structures/Contiguous/array.hpp"
#include "../../Structures/LinkedLists/list.hpp"
#include "../../Algorithms/Sorts/mergeSort.hpp"
#include "../../Algorithms/Sorts/bubbleSort.hpp"
#include "../../Algorithms/Sorts/selectionSort.hpp"
#include "../../Algorithms/Sorts/quickSort.hpp"

typedef Salih::Structures::LinkedLists::List<int> intList ;
typedef Salih::Structures::LinkedLists::FwdList<double> doubleFwdList ;
typedef Salih::Structures::Contiguous::Array<float,4> floatArr ;
typedef Salih::Structures::Contiguous::Vector<float> floatVec ;

//** Sorts themselves **//

/* bubble sort */
TEST_CASE("bubble sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::bubbleSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::bubbleSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = Salih::Algorithms::Sorts::bubbleSort(list3) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::bubbleSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("bubble sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::bubbleSort(list1, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::bubbleSort(list2, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = Salih::Algorithms::Sorts::bubbleSort(list3, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::bubbleSort(list4, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("bubble sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::bubbleSort(list1, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::bubbleSort(list2, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	floatArr list3{3,6,4,5} ;
	list3 = Salih::Algorithms::Sorts::bubbleSort(list3, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list3 == floatArr{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::bubbleSort(list4, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

/* selection sort */
TEST_CASE("selection sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::selectionSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::selectionSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = Salih::Algorithms::Sorts::selectionSort(list3) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::selectionSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("selection sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::selectionSort(list1, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::selectionSort(list2, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	floatArr list3{3,6,4,5} ;
	list3 = Salih::Algorithms::Sorts::selectionSort(list3, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list3 == floatArr{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::selectionSort(list4, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("selection sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::selectionSort(list1, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::selectionSort(list2, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	floatArr list3{3,6,4,5} ;
	list3 = Salih::Algorithms::Sorts::selectionSort(list3, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list3 == floatArr{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::selectionSort(list4, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

/* merge sort */
TEST_CASE("merge sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::mergeSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::mergeSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::mergeSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("merge sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::mergeSort(list1, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::mergeSort(list2, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::mergeSort(list4, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("merge sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::mergeSort(list1, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::mergeSort(list2, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::mergeSort(list4, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

/* quick sort */

TEST_CASE("quick sort - does the accepted list get sorted with order not explicitly set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::quickSort(list1) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::quickSort(list2) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::quickSort(list4) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("quick sort - does the accepted list get sorted with ascending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::quickSort(list1, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list1 == intList{1,2,3}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::quickSort(list2, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list2 == floatVec{3,4,5,6}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::quickSort(list4, Salih::Algorithms::Sorts::ASCEND) ;
	REQUIRE(list4 == doubleFwdList{3,4,5,6}) ;
}

TEST_CASE("quick sort - does the accepted list get sorted with descending order set?")
{
	intList list1{1,3,2} ;
	list1 = Salih::Algorithms::Sorts::quickSort(list1, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list1 == intList{3,2,1}) ;
	floatVec list2{3,6,4,5} ;
	list2 = Salih::Algorithms::Sorts::quickSort(list2, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list2 == floatVec{6,5,4,3}) ;
	doubleFwdList list4{3,6,4,5} ;
	list4 = Salih::Algorithms::Sorts::quickSort(list4, Salih::Algorithms::Sorts::DESCEND) ;
	REQUIRE(list4 == doubleFwdList{6,5,4,3}) ;
}

//** helper functions **//

/* flags */
TEST_CASE("does ASCEND function pointer / flag return correct value based on values provided")
{
	REQUIRE(Salih::Algorithms::Sorts::ASCEND(2,1) == false) ;
	REQUIRE(Salih::Algorithms::Sorts::ASCEND(1,2) == true) ;
	REQUIRE(Salih::Algorithms::Sorts::ASCEND(2,2) == false) ;
}

TEST_CASE("does DESCEND function pointer / flag return correct values based on values provided")
{
	REQUIRE(Salih::Algorithms::Sorts::DESCEND(2,1) == true) ;
	REQUIRE(Salih::Algorithms::Sorts::DESCEND(1,2) == false) ;
	REQUIRE(Salih::Algorithms::Sorts::DESCEND(2,2) == false) ;
}
