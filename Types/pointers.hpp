#ifndef POINTERS_HPP
#define POINTERS_HPP
#pragma once

#include <iostream>
#include <cstdlib>

namespace Salih::Types {

	template<class T>
	class Pointer<T> ;
	
	template<class T>
	class SharedPointer<T> ;
	
	template<class T>
	class UniquePointer<T> ;
	
	template<class T>
	class Pointer<T> {
		private:
			T* pointer ;
			
			int count ; int& refCount ;
			
			float dataSize ;
		public:
			Pointer(T) ;
			
			Pointer(T*) ;
			
			T operator->(const int) const ;
			
			virtual ~Pointer() ;
	} ;
	
	template<class T>
	class SharedPointer : public Pointer<T> {
		public:
			SharedPointer(T) ;
			
			SharedPointer(T*) ;
		
			SharedPointer(const SharedPointer&) ;
			
			SharedPointer(SharedPointer&&) ;
			
			~SharedPointer() ;
	} ;
	
	template<class T>
	class UniquePointer : public Pointer<T> {
		public:
			UniquePointer(T) ;
			
			UniquePointer(T*) ;
		
			UniquePointer(const UniquePointer&) = delete ;
			
			UniquePointer(UniquePointer&&) ;
			
			~UniquePointer() ;
	} ;
}

//helpful overloads

template<typename T>
std::ostream& operator<<(std::ostream& os, Salih::Types::Pointer<T>& ptr)
{
	os << ptr.pointer ;
	return os ;
}

#endif
