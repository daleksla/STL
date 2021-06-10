/* Include the unit testing library */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* Include the code that we plan to test */
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

#define private public
#include "../../containers/fwd-list.hpp"

typedef salih::containers::FwdList<int> intList ;
typedef salih::containers::FwdList<float> floatList ;

struct weird {
	int a = 5 ;
} ;

//** Create sub-categories to test with predicted outcomes **//

/* Constructors */
TEST_CASE("empty constructor - attribute testing")
{
	intList list1 ;
	REQUIRE(list1.head == NULL) ;
	REQUIRE(list1.size == 0) ;
}

TEST_CASE("regular constructor - attribute testing")
{
	intList list1{1,2,3,4} ;
	REQUIRE(list1.size == 4) ;
}

TEST_CASE("regular constructor - value testing")
{
	intList list1{1,2,3,4} ;
	REQUIRE(list1.head->data == 1) ;
}

TEST_CASE("size initialisation constructor - attribute testing")
{
	intList list1(4) ;
	REQUIRE(list1.head != nullptr) ;
	REQUIRE(list1.size == 4) ;
}

TEST_CASE("copy constructor - attribute testing")
{
	intList list1{1,2,3,4} ;
	intList list3(list1) ;
	REQUIRE(list1.head != list3.head) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("copy constructor - value testing")
{
	intList list1{1,2,3,4} ;
	intList list3(list1) ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list3.head->data == 1) ;
}

TEST_CASE("move constructor - attribute testing")
{
	intList list2(intList{1,2,3,4}) ;
	REQUIRE(list2.head != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.head ;
	intList list3 = std::move(list2) ;
	REQUIRE(list3.head == h) ;
}

TEST_CASE("move constructor - value testing")
{
	intList list2(intList{1,2,3,4}) ;
	REQUIRE(list2.head->data == 1) ;
}

/* Assignment Operators */
TEST_CASE("assigning values using operator to list - attribute testing")
{
	intList list1{1,2,3,4} ;
	list1 = {1,2,3,43} ;
	REQUIRE(list1.size == 4) ;
}

TEST_CASE("assigning values using operator to list - value testing")
{
	intList list1 = {1,2,3,4} ;
	REQUIRE(list1.head->data == 1) ;
}

TEST_CASE("assigning created list using operator to list - attribute testing")
{
	intList list1{1,2,3,4} ;
	intList list3 = list1 ;
	REQUIRE(list1.head != list3.head) ;
	REQUIRE(list1.size == 4) ;
	REQUIRE(list3.size == 4) ;
}

TEST_CASE("assigning created list using operator to list - value testing")
{
	intList list1{1,2,3,4} ;
	intList list3 = list1 ;
	REQUIRE(list1.head->data == 1) ;
	REQUIRE(list3.head->data == 1) ;
}

TEST_CASE("assigning r-value / temporary list using operator to list - attribute testing")
{
	intList list2 = intList{1,2,3,4} ;
	REQUIRE(list2.head != NULL) ;
	REQUIRE(list2.size == 4) ;
	
	auto h = list2.head ;
	intList list3 = std::move(list2) ;
	REQUIRE(list3.head == h) ;
}

TEST_CASE("assigning r-value / temporary list using operator to list - value testing")
{
	intList list2 = intList{1,2,3,4} ;
	REQUIRE(list2.head->data == 1) ;
}

/* Slicing operator */
TEST_CASE("() operator - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1(0,6) == intList{1,2,3,4,5,6}) ;
}

TEST_CASE("() operator - returns seperate list")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1(0,6).head != list1.head) ;
}

/* Index / access operator */
TEST_CASE("[] operator - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1[0] == 1) ;
	REQUIRE(list1[3] != 2) ;
}

TEST_CASE("[] operator - modifying values")
{
	intList list1 = {1,2,3,4,5,6} ;
	list1[3] = 1 ;
	REQUIRE(list1[3] == 1) ;
	REQUIRE(list1[3] != 4) ;
}

TEST_CASE("'at()' method - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.at(0) == 1) ;
	REQUIRE(list1.at(3) != 2) ;
}

TEST_CASE("'at()' method  - modifying values")
{
	intList list1 = {1,2,3,4,5,6} ;
	list1.at(3) = 1 ;
	REQUIRE(list1.at(3) == 1) ;
	REQUIRE(list1.at(3) != 4) ;
}

TEST_CASE("'at()' method - does 'out_of_range' error get thrown if list is smaller than requested index")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.at(0) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

/* Boolean operators */
TEST_CASE("== operator - comparing values of same type")
{
	intList list1 = {1,2,3,4,5,6} ;
	intList list2{1,2,3,4,5,6} ;
	REQUIRE(list1 == list2) ;
}

TEST_CASE("== operator - comparing values of different type")
{
	intList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5,6} ;
	REQUIRE(list1 == list2) ;
}

TEST_CASE("!= operator - comparing values of same type")
{
	intList list1 = {1,2,3,4,5,6} ;
	intList list2{1,2,3,4,5} ;
	REQUIRE(list1 != list2) ;
}

TEST_CASE("!= operator - comparing values of different type")
{
	intList list1 = {1,2,3,4,5,6} ;
	floatList list2{1,2,3,4,5} ;
	REQUIRE(list1 != list2) ;
}

/* Size method */
TEST_CASE("'getSize()' method - correct value returned")
{
	intList list1 = {1,2,3,4,5,6} ;
	REQUIRE(list1.getSize() == 6) ;
}

/* Append method */
TEST_CASE("'append()' method - correct value added")
{
	intList list1 ;
	list1.append(5) ;
	REQUIRE(list1[0] == 5) ;
}

/* Insert method */
TEST_CASE("'insert()' method - correct value added at beginning of list")
{
	intList list1{54,2,3,4,5} ;
	list1.insert(1,1) ;
	REQUIRE(list1[0] == 1) ;
}

TEST_CASE("'insert()' method - correct value added in the middle of list")
{
	intList list1{1,2,4,5} ;
	list1.insert(3,3) ;
	REQUIRE(list1[2] == 3) ;
}

TEST_CASE("'insert()' method - correct value added at end of list")
{
	intList list1{1,2,3} ;
	list1.insert(4,4) ;
	REQUIRE(list1[3] == 4) ;
}

TEST_CASE("'insert()' method - does 'out_of_range' error get thrown if index is invalid")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.insert(2,1) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

/* Delete method */
TEST_CASE("'del()' method - correct value deleted")
{
	intList list1{1,2,3} ;
	list1.del(1) ;
	REQUIRE(list1[0] == 2) ;
}

TEST_CASE("'del()' method - does 'out_of_range' error get thrown if list is empty")
{
	intList list1 ;
	bool isError = false ;
	try {
		list1.del(1) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

TEST_CASE("'del()' method - does 'out_of_range' error get thrown if list doesn't contain index")
{
	intList list1{1} ;
	bool isError = false ;
	try {
		list1.del(2) ;
	} catch(const std::out_of_range& error) {
		isError = true ;
	}
	
	REQUIRE(isError == true) ;
}

/* clear method */
TEST_CASE("'clear()' method - attribute test")
{
	intList list1{1,2,3} ;
	list1.clear() ;
	REQUIRE(list1.size == 0) ;
	REQUIRE(list1.head == nullptr) ;
}

/* iterator utilisation */
TEST_CASE("'begin()' method - correct value returned")
{
	intList list2(6) ;
	REQUIRE(list2.begin().pointer == list2.head) ;
}

TEST_CASE("'end()' method - correct value returned")
{
	intList list2(6) ;
	REQUIRE(list2.end().pointer == nullptr) ;
}

TEST_CASE("'cbegin()' method - correct value returned")
{
	intList list2(6) ;
	REQUIRE(list2.cbegin().pointer == list2.head) ;
}

TEST_CASE("'cend()' method - correct value returned")
{
	intList list2(6) ;
	REQUIRE(list2.cend().pointer == nullptr) ;
}

/* iterators */
TEST_CASE("Iterator object - empty initialisation")
{
	intList list2(6) ;
	REQUIRE(intList::Iterator().pointer == nullptr) ;
}

TEST_CASE("Iterator object - prefix incrementation")
{
	intList list2(6) ;
	auto it = list2.begin() ;
	REQUIRE(++it == intList::Iterator(list2.head->getNext())) ;
	REQUIRE(it == intList::Iterator(list2.head->getNext())) ;
}

TEST_CASE("Iterator object - postfix incrementation")
{
	intList list2(6) ;
	auto it = list2.begin() ;
	REQUIRE(it++ == intList::Iterator(list2.head)) ;
	REQUIRE(it == intList::Iterator(list2.head->getNext())) ;
}

TEST_CASE("Iterator object - moving position using + operator (addition)")
{
	intList list2(6) ;
	auto it = list2.begin() ;
	REQUIRE((it+1) == intList::Iterator(list2.head->getNext())) ;
	REQUIRE((it) == intList::Iterator(list2.head)) ;
}

TEST_CASE("Iterator object - moving position using += operator (compound addition)")
{
	intList list2(6) ;
	auto it = list2.begin() ;
	REQUIRE((it+=1) == intList::Iterator(list2.head->getNext())) ;
	REQUIRE((it) == intList::Iterator(list2.head->getNext())) ;
}

TEST_CASE("Iterator object - equality comparison")
{
	intList list2(6) ;
	auto it = list2.end() ;
	REQUIRE(it == list2.end()) ;
	it = list2.begin() ;
	REQUIRE(it == list2.begin()) ;
}

TEST_CASE("Iterator object - inequality comparison")
{
	intList list2(6) ;
	auto it = list2.begin() ;
	REQUIRE(it != list2.end()) ;
	it = list2.end() ;
	REQUIRE(it != list2.begin()) ;
}

TEST_CASE("Iterator object - dereferencing operator")
{
	intList list2{1,2,3,4,5,6} ;
	auto it = list2.begin() ;
	REQUIRE(*it == 1) ;
}

TEST_CASE("Iterator object - access operator")
{
	salih::containers::FwdList<weird> list2(1) ;
	auto it = list2.begin() ;
	REQUIRE(it->a == 5) ;
}

/* const iterators */
TEST_CASE("ConstIterator object - empty initialisation")
{
	intList list2(6) ;
	REQUIRE(intList::ConstIterator().pointer == nullptr) ;
}

TEST_CASE("ConstIterator object - prefix incrementation")
{
	intList list2(6) ;
	auto it = list2.cbegin() ;
	REQUIRE(++it == intList::ConstIterator(list2.head->getNext())) ;
	REQUIRE(it == intList::ConstIterator(list2.head->getNext())) ;
}

TEST_CASE("ConstIterator object - postfix incrementation")
{
	intList list2(6) ;
	auto it = list2.cbegin() ;
	REQUIRE(it++ == intList::ConstIterator(list2.head)) ;
	REQUIRE(it == intList::ConstIterator(list2.head->getNext())) ;
}

TEST_CASE("ConstIterator object - moving position using + operator (addition)")
{
	intList list2(6) ;
	auto it = list2.cbegin() ;
	REQUIRE((it+1) == intList::ConstIterator(list2.head->getNext())) ;
	REQUIRE((it) == intList::ConstIterator(list2.head)) ;
}

TEST_CASE("ConstIterator object - moving position using += operator (compound addition)")
{
	intList list2(6) ;
	auto it = list2.cbegin() ;
	REQUIRE((it+=1) == intList::ConstIterator(list2.head->getNext())) ;
	REQUIRE((it) == intList::ConstIterator(list2.head->getNext())) ;
}

TEST_CASE("ConstIterator object - equality comparison")
{
	intList list2(6) ;
	auto it = list2.cend() ;
	REQUIRE(it == list2.cend()) ;
	it = list2.cbegin() ;
	REQUIRE(it == list2.cbegin()) ;
}

TEST_CASE("ConstIterator object - inequality comparison")
{
	intList list2(6) ;
	auto it = list2.cbegin() ;
	REQUIRE(it != list2.cend()) ;
	it = list2.cend() ;
	REQUIRE(it != list2.cbegin()) ;
}

TEST_CASE("ConstIterator object - dereferencing operator")
{
	intList list2{1,2,3,4,5,6} ;
	auto it = list2.cbegin() ;
	REQUIRE(*it == 1) ;
}

TEST_CASE("ConstIterator object - access operator")
{
	salih::containers::FwdList<weird> list2(1) ;
	auto it = list2.cbegin() ;
	REQUIRE(it->a == 5) ;
}
