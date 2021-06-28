#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP
#pragma once

#include "macros.hpp"

/** @brief Collection of general-use Concepts (constraints of as given parameter type based on permissible operation / conditions) 
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

#ifdef CXX20

namespace salih {
namespace types {

	template<typename T>
	concept Number = requires(T a) {
		a = 0 ;
		a += 2 ;
		++a ;
		a++ ;
		a-- ;
		--a ;
		a / 1 ;
		a * 1 ;
		a - 1 ;
		a + 1 ;
	} ;

	template<typename T>
	concept Comparable = requires(T a) {
		a > a ;
		a >= a ;
		a < a ;
		a <= a ;
		a == a ;
		a != a ;
	} ;

	template<typename T>
	concept ForwardIterator = !(Number<T>) && requires(T a) {
		++a ;
		a++ ;
		a += 2 ;
		a + 1 ;	
		*a ;
	} ;

	template<typename T>
	concept BidirectionalIterator = ForwardIterator<T> && requires(T a) {
		--a ;
		a-- ;
		a -= 2 ;
		a - 1 ;	
	} ;

	template<typename T>
	concept RandomAccessIterator = BidirectionalIterator<T> && requires(T a) {
		a > a ;
		a >= a ;
		a < a ;
		a <= a ;	
	} ;
	
	template<typename T>
	concept Indexable = requires(T a) {
		a[0] ;
	} ;

}
}

#else
	#error Concepts are only availible on compilers compliant with C++ standard version 20 and later
#endif

#endif // CONCEPTS_HPP
