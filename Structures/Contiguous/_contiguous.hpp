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
			//Contiguous() = delete ;
			
			Contiguous(const std::size_t) ;
			
			Contiguous(const std::initializer_list<T>&, const std::size_t) ;
			
			//Contiguous& operator=(const std::initializer_list<T>&) ;
			
			Contiguous(const Contiguous&, const std::size_t) ;
			
			//Contiguous& operator=(const Contiguous&) ;
			
			Contiguous(Contiguous&&, const std::size_t) ;
			
			//Contiguous& operator=(Contiguous&&) ;
			
			std::size_t getSize() const ;
			
			T& operator[](const int) ; 
			
			const T& operator[](const int) const ; 
			
			T& at(const int, const bool) ; 
			
			const T& at(const int, const bool) const ; 
			
			template<typename OTHER>
			bool operator==(const Contiguous<OTHER>&) const ;
			
			bool operator==(const Contiguous&) const ;
			
			template<typename OTHER>
			bool operator!=(const Contiguous<OTHER>&) const ;
			
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
