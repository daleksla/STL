#ifndef VECTOR_HPP
#define VECTOR_HPP
#pragma once

#include "_contiguous.hpp"
#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

/* This file contains the declarations and implementations of a array-based (child) contiguous structure
 * It is located in the Salih, Structures, Contiguous namespaces */

namespace Salih::Structures::Contiguous {

	template<class T>
	class Vector : public Contiguous<T> {
		private:			
			Vector(T*, const std::size_t) ;
		public:
			Vector() ;
		
			Vector(const std::size_t) ;
		
			Vector(const std::initializer_list<T>&) ;
			
			Vector& operator=(const std::initializer_list<T>&) ;
			
			Vector(const Vector&) ;
			
			Vector& operator=(const Vector&) ;
			
			Vector(Vector&&) ;
			
			Vector& operator=(Vector&&) ;			
			
			//template<std::size_t NEW_SIZE>
			//Array<T,NEW_SIZE> operator()(const int x, const int y) const ;
			
			void append(T) ;
			
			void clear() ;
			
			~Vector() ;
			
			template<typename OTHER>
			friend class Vector ;
	} ;
	
}

#include "vector.tpp"

#endif
