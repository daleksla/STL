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

	template<class T, std::size_t size>
	class Array : public Contiguous<T> {
		private:			
			Array(T*, std::size_t) ;
		public:
			Array() ;
		
			Array(const std::initializer_list<T>&) ;
			
			Array& operator=(const std::initializer_list<T>&) ;
			
			Array(const Array&) ;
			
			Array& operator=(const Array&) ;
			
			Array(Array&&) ;
			
			Array& operator=(Array&&) ;			
			
			Array operator()(const int x, const int y) const ;
			
			~Array() ;
	} ;
	
}

#include "array.tpp"

#endif
