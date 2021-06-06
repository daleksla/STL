/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include "../../containers/array.hpp"

struct weird {
	int a = 5 ;
} ;

typedef salih::containers::Array<int,6> bigList ;
typedef salih::containers::Array<int,6> floatList ;
typedef salih::containers::Array<int,3> smallList ;

template<std::size_t SIZE>
constexpr std::size_t getSize(salih::containers::Array<int, SIZE> a)
{
	return SIZE ;
}

//** Create sub-categories to test with predicted outcomes **//

/* Aggregate class - testing assignment only */
TEST_CASE("Empty assignment - attribute testing")
{
	bigList list ;
	REQUIRE(getSize(list) == 6) ;
	bigList list2{} ;
	REQUIRE(getSize(list2) == 6) ;
	bigList list3 = {} ;
	REQUIRE(getSize(list3) == 6) ;
}

TEST_CASE("Regular assignment - attribute testing")
{
	bigList list{1,2,3,4,5,6} ;
	REQUIRE(getSize(list) == 6) ;
	list = {1,2,3,4,5,6} ;
	REQUIRE(getSize(list) == 6) ;
	bigList list2 = {1,2,3,4,5,6} ;
	REQUIRE(getSize(list2) == 6) ;
}

TEST_CASE("Regular assignment - value testing")
{
	bigList list{1,2,3,4,5,6} ;
	REQUIRE((list.pointer[0] == 1 && list.pointer[1] == 2 && list.pointer[2] == 3 && list.pointer[3] == 4 && list.pointer[4] == 5 && list.pointer[5] == 6)) ;
	list = {1,2,3,4,5,7} ;
	REQUIRE((list.pointer[0] == 1 && list.pointer[1] == 2 && list.pointer[2] == 3 && list.pointer[3] == 4 && list.pointer[4] == 5 && list.pointer[5] == 7)) ;
}

/* Index / access operators */
TEST_CASE("[] operator - correct value returned")
{
	bigList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1[0] == 1) ;
	REQUIRE(list1[3] != 2) ;
}

TEST_CASE("[] operator - modifying values")
{
	bigList list1 = {1,2,3,4,5,6} ;
	list1[3] = 1 ;
	REQUIRE(list1[3] == 1) ;
	REQUIRE(list1[3] != 4) ;
}

TEST_CASE("'at()' method - correct value returned")
{
	bigList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.at(0) == 1) ;
	REQUIRE(list1.at(3) != 2) ;
}

TEST_CASE("'at()' method  - modifying values")
{
	bigList list1 = {1,2,3,4,5,6} ;
	list1.at(3) = 1 ;
	REQUIRE(list1.at(3) == 1) ;
	REQUIRE(list1.at(3) != 4) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index")
{
	bigList list1 ;
	bool isError = false ;
	try {
		list1.at(7) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

/* Boolean operators */
TEST_CASE("== operator - comparing values of same type")
{
	bigList list1 = {1,2,3,4,5,6} ;
	bigList list2{1,2,3,4,5,6} ;
	floatList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 == list2) ;
	REQUIRE(!(list1 == list3)) ;
}

TEST_CASE("== operator - comparing values of different type") 
{
	bigList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5,6} ;
	floatList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 == list2) ;
	REQUIRE(!(list1 == list3)) ;
}

TEST_CASE("== operator - comparing values of different size") // will always be false
{
	floatList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(!(list1 == list2)) ;
}

TEST_CASE("== operator - comparing values of different type and different size") // will always be false
{
	bigList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(!(list1 == list2)) ;
}

TEST_CASE("!= operator - comparing values of same type")
{
	bigList list1 = {1,2,3,4,5,6} ;
	bigList list2{1,2,3,4,5,6} ;
	bigList list3{1,2,3,4,5,5} ;
	REQUIRE(list1 != list3) ;
	REQUIRE(!(list1 != list2)) ;
}

TEST_CASE("!= operator - comparing values of different types")
{
	bigList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5,5} ;
	floatList list3{1,2,3,4,5,6} ;
	REQUIRE(list1 != list2) ;
	REQUIRE(!(list3 != list1)) ;
}

TEST_CASE("!= operator - comparing values of different size") // will always be true
{
	floatList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(list1 != list2) ;
}

TEST_CASE("!= operator - comparing values of different type and different size") // will always be false
{
	bigList list1 = {1,2,3,4,5,6} ;
	smallList list2{1,2,3} ;
	REQUIRE(list1 != list2) ;
}

/* Size method */
TEST_CASE("'getSize()' method - correct value returned")
{
	bigList list2 ;
	REQUIRE(list2.getSize() == 6) ;
	bigList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.getSize() == 6) ;
}

/* iterator utilisation */
TEST_CASE("'begin()' method - correct value returned")
{
	bigList list2 ;
	REQUIRE(list2.begin().pointer == &(list2.pointer[0])) ;
}

TEST_CASE("'end()' method - correct value returned")
{
	bigList list2 ;
	REQUIRE(list2.end().pointer == &(list2.pointer[6])) ;
}

TEST_CASE("'cbegin()' method - correct value returned")
{
	bigList list2 ;
	REQUIRE(list2.cbegin().pointer == &(list2.pointer[0])) ;
}

TEST_CASE("'cend()' method - correct value returned")
{
	bigList list2 ;
	REQUIRE(list2.cend().pointer == &(list2.pointer[6])) ;
}

/* iterators */
TEST_CASE("Iterator object - empty initialisation")
{
	bigList list2 ;
	REQUIRE(bigList::Iterator().pointer == nullptr) ;
}

TEST_CASE("Iterator object - prefix incrementation")
{
	bigList list2 ;
	auto it = list2.begin() ;
	REQUIRE(++it == bigList::Iterator(&(list2[1]))) ;
	REQUIRE(it == bigList::Iterator(&(list2[1]))) ;
}

TEST_CASE("Iterator object - postfix incrementation")
{
	bigList list2 ;
	auto it = list2.begin() ;
	REQUIRE(it++ == bigList::Iterator(&(list2[0]))) ;
	REQUIRE(it++ == bigList::Iterator(&(list2[1]))) ;
}

TEST_CASE("Iterator object - moving position using + operator (addition)")
{
	bigList list2 ;
	auto it = list2.begin() ;
	REQUIRE((it+1) == bigList::Iterator(&(list2[1]))) ;
	REQUIRE((it) == bigList::Iterator(&(list2[0]))) ;
}

TEST_CASE("Iterator object - moving position using += operator (compound addition)")
{
	bigList list2 ;
	auto it = list2.begin() ;
	REQUIRE((it+=1) == bigList::Iterator(&(list2[1]))) ;
	REQUIRE(it == bigList::Iterator(&(list2[1]))) ;
}

TEST_CASE("Iterator object - prefix decrement")
{
	bigList list2 ;
	auto it = list2.end() ;
	REQUIRE(--it == bigList::Iterator(&(list2[5]))) ;
}

TEST_CASE("Iterator object - postfix decrement")
{
	bigList list2 ;
	auto it = list2.end() ;
	REQUIRE(it-- == bigList::Iterator(&(list2[6]))) ;
}

TEST_CASE("Iterator object - moving position using - operator (subtracting)")
{
	bigList list2 ;
	auto it = list2.end() ;
	REQUIRE(it-1 == bigList::Iterator(&(list2[5]))) ;
	REQUIRE(it == bigList::Iterator(&(list2[6]))) ;
}

TEST_CASE("Iterator object - moving position using -= operator (compound subtracting)")
{
	bigList list2 ;
	auto it = list2.end() ;
	REQUIRE((it-=1) == bigList::Iterator(&(list2[5]))) ;
	REQUIRE(it == bigList::Iterator(&(list2[5]))) ;
}

TEST_CASE("Iterator object - equality comparison")
{
	bigList list2 ;
	auto it = list2.end() ;
	REQUIRE(it == list2.end()) ;
	it = list2.begin() ;
	REQUIRE(it == list2.begin()) ;
}

TEST_CASE("Iterator object - inequality comparison")
{
	bigList list2 ;
	auto it = list2.begin() ;
	REQUIRE(it != list2.end()) ;
	it = list2.end() ;
	REQUIRE(it != list2.begin()) ;
}

TEST_CASE("Iterator object - dereferencing operator")
{
	bigList list2{1,2,3,4,5,6} ;
	auto it = list2.begin() ;
	REQUIRE(*it == 1) ;
}

TEST_CASE("Iterator object - access operator")
{
	salih::containers::Array<weird,1> list2 ;
	auto it = list2.begin() ;
	REQUIRE(it->a == 5) ;
}

/* const iterators */
TEST_CASE("ConstIterator object - empty initialisation")
{
	bigList list2 ;
	REQUIRE(bigList::ConstIterator().pointer == nullptr) ;
}

TEST_CASE("ConstIterator object - prefix incrementation")
{
	bigList list2 ;
	auto it = list2.cbegin() ;
	REQUIRE(++it == bigList::ConstIterator(&(list2[1]))) ;
	REQUIRE(it == bigList::ConstIterator(&(list2[1]))) ;
}

TEST_CASE("ConstIterator object - postfix incrementation")
{
	bigList list2 ;
	auto it = list2.cbegin() ;
	REQUIRE(it++ == bigList::ConstIterator(&(list2[0]))) ;
	REQUIRE(it++ == bigList::ConstIterator(&(list2[1]))) ;
}

TEST_CASE("ConstIterator object - moving position using + operator (addition)")
{
	bigList list2 ;
	auto it = list2.cbegin() ;
	REQUIRE(it+1 == bigList::ConstIterator(&(list2[1]))) ;
	REQUIRE(it == bigList::ConstIterator(&(list2[0]))) ;
}

TEST_CASE("ConstIterator object - moving position using += operator (compound addition)")
{
	bigList list2 ;
	auto it = list2.cbegin() ;
	REQUIRE((it+=1) == bigList::ConstIterator(&(list2[1]))) ;
	REQUIRE(it == bigList::ConstIterator(&(list2[1]))) ;
}

TEST_CASE("ConstIterator object - prefix decrement")
{
	bigList list2 ;
	auto it = list2.cend() ;
	REQUIRE(--it == bigList::ConstIterator(&(list2[5]))) ;
}

TEST_CASE("ConstIterator object - postfix decrement")
{
	bigList list2 ;
	auto it = list2.cend() ;
	REQUIRE(it-- == bigList::ConstIterator(&(list2[6]))) ;
}

TEST_CASE("ConstIterator object - moving position using - operator (subtracting)")
{
	bigList list2 ;
	auto it = list2.cend() ;
	REQUIRE((it-1) == bigList::ConstIterator(&(list2[5]))) ;
	REQUIRE(it == bigList::ConstIterator(&(list2[6]))) ;
}

TEST_CASE("ConstIterator object - moving position using -= operator (compound subtracting)")
{
	bigList list2 ;
	auto it = list2.cend() ;
	REQUIRE((it-=1) == bigList::ConstIterator(&(list2[5]))) ;
	REQUIRE(it == bigList::ConstIterator(&(list2[5]))) ;
}

TEST_CASE("ConstIterator object - equality comparison")
{
	bigList list2 ;
	auto it = list2.cend() ;
	REQUIRE(it == list2.cend()) ;
	it = list2.cbegin() ;
	REQUIRE(it == list2.cbegin()) ;
}

TEST_CASE("ConstIterator object - inequality comparison")
{
	bigList list2 ;
	auto it = list2.cbegin() ;
	REQUIRE(it != list2.cend()) ;
	it = list2.cend() ;
	REQUIRE(it != list2.cbegin()) ;
}

TEST_CASE("ConstIterator object - dereferencing operator")
{
	bigList list2{1,2,3,4,5,6} ;
	auto it = list2.cbegin() ;
	REQUIRE(*it == 1) ;
}

TEST_CASE("ConstIterator object - access operator")
{
	salih::containers::Array<weird,1> list2 ;
	auto it = list2.cbegin() ;
	REQUIRE(it->a == 5) ;
}
