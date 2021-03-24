#ifndef CONTIGUOUS_HPP
#define CONTIGUOUS_HPP
#pragma once

#include <algorithm>
#include <iostream>
#include <utility>
#include <initializer_list>

/* This file contains the declarations of the base class for contiguous memory structures 
 * It is located in the nested Salih, Structures, Contiguous namespace */
 
namespace Salih::Structures::Contiguous {
	
	template<typename T>
	class Contiguous ;
	
}

template<typename T>
std::ostream& operator<<(std::ostream&, const Salih::Structures::Contiguous::Contiguous<T>&) ;

namespace Salih::Structures::Contiguous {

	template<class T>
	class Contiguous {
		protected:
			std::size_t size ;
			
			T* pointer ;
			
			Contiguous(T*, const std::size_t) ;
	
		public:	
			Contiguous() = delete ;
			
			Contiguous(const std::size_t) ;
			
			Contiguous(const std::size_t, const std::initializer_list<T>&) ;
			
			Contiguous& operator=(const std::initializer_list<T>&) ;
			
			Contiguous(const Contiguous&) ;
			
			Contiguous& operator=(const Contiguous&) ;
			
			Contiguous(Contiguous&&) ;
			
			Contiguous& operator=(Contiguous&&) ;
			
			std::size_t getSize() const ;
			
			T& operator[](const int) ; 
			
			const T& operator[](const int) const ; 
			
			bool operator==(const Contiguous&) const ;
			
			bool operator!=(const Contiguous&) const ;
			
			void del(const int) ;

			//virtual Contiguous operator()(const int, const int) const ; //slicing
			
			//virtual Contiguous operator+(const Contiguous&) const = 0 ;
			
			//virtual void operator+=(const Contiguous&) const = 0 ;
			
			//virtual Contiguous operator()(const int, const int) = 0 ;
			
			//virtual void insert(const int, T) = 0 ;
			
			//virtual void append(T) = 0 ;
			
			virtual ~Contiguous() = 0 ;
	} ;
}

#include "_contiguous.tpp"

#endif
