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
		public:
			static CONSTEXPRCXX11 int value = 1 ;
		
		public:
			CONSTEXPRCXX11 int operator()()
			{
				return value ;
			}

	} ;

	struct BiDirectionalIteratorTag {
		public:
			static CONSTEXPRCXX11 int value = 2 ;
		
		public:
			CONSTEXPRCXX11 int operator()()
			{
				return value ;
			}
			
	} ;

	struct RandomAccessIteratorTag {
		public:
			static CONSTEXPRCXX11 int value = 3 ;
		
		public:
			CONSTEXPRCXX11 int operator()()
			{
				return value ;
			}
			
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
