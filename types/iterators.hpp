#ifndef ITERATORS_HPP
#define ITERATORS_HPP
#pragma once

#include "macros.hpp"

/** @brief Collection of concepts, traits & tags for iterator types
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	struct UniDirectionalIteratorTag {
		static constexpr int value = 1 ;
	} ;

	struct BiDirectionalIteratorTag {
		static constexpr int value = 2 ;
	} ;

	struct RandomAccessIteratorTag {
		static constexpr int value = 3 ;
	} ;

	#ifdef CXX20
	template<typename T>
	concept ForwardIterator = requires(T a) {
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
	concept RandomAccessIterator = BidirectionalIterator<T> && requires(T a) {
		a > a ;
		a >= a ;
		a < a ;
		a <= a ;	
	} ;
	#endif
	
}
}

#endif
