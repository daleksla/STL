#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP
#pragma once

#include "macros.hpp"

/** @brief Useful concepts for general and library-specific data-types
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
	concept ForwardIterator = !(Number<T>) && requires(T a) {
		++a ;
		a++ ;
		a += 2 ;
		a + 1 ;	
	} ;

	template<typename T>
	concept BidirectionalIterator = ForwardIterator<T> && requires(T a) {
		--a ;
		a-- ;
		a -= 2 ;
		a - 1 ;	
	} ;

	template<typename T>
	concept ContiguousIterator = BidirectionalIterator<T> && requires(T a) {
		a > a ;
		a >= a ;
		a < a ;
		a <= a ;	
	} ;

}
}

#else
	#error Concepts are only availible on compilers compliant with C++ standard version 20 and later
#endif

#endif // CONCEPTS_HPP
