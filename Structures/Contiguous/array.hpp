#ifndef ARRAY_HPP
#define ARRAY_HPP
#pragma once

#include "_contiguous.hpp"
#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

/* This file contains the declarations and implementations of a array-based (child) contiguous structure
 * It is located in the Salih, Structures, Contiguous namespaces */

namespace Salih::Structures::Contiguous {

	template<class T, std::size_t SIZE>
	class Array : public Contiguous<T> {
		private:			
			Array(T*, const std::size_t) ;
		public:
			Array() ;
		
			Array(const std::initializer_list<T>&) ;
			
			Array& operator=(const std::initializer_list<T>&) ;
			
			Array(const Array&) ;
			
			Array& operator=(const Array&) ;
			
			Array(Array&&) ;
			
			Array& operator=(Array&&) ;			
			
			//template<std::size_t NEW_SIZE>
			//Array<T,NEW_SIZE> operator()(const int x, const int y) const ;
			
			~Array() ;
			
			template<typename OTHER, std::size_t _SIZE>
			friend class Array ;
	} ;
	
}

#include "array.tpp"

#endif
