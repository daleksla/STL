#ifndef POINTERS_HPP
#define POINTERS_HPP
#pragma once

#include <iostream>
#include <cstdlib>

namespace Salih::Types {

	template<typename T>
	class Pointer ;
	
	template<typename T>
	class SharedPointer ;
	
	template<typename T>
	class UniquePointer ;
}

template<typename T>
std::ostream& operator<<(std::ostream&, const Salih::Types::Pointer<T>&) ;

namespace Salih::Types {
	
	template<class T>
	class Pointer {
		protected:
			T* pointer ;			
		public:
			Pointer() ;	
	
			Pointer(T) ;
			
			T* operator->() ;
			
			T& operator*() ;
			
			T* get() const ;
			
			virtual ~Pointer() = 0 ;
	} ;
	
	template<class T>
	class SharedPointer : public Pointer<T> {
		private:
			int* count ;
		public:
			SharedPointer() ;
		
			SharedPointer(T) ;
		
			SharedPointer(const SharedPointer&) ;
			
			SharedPointer(SharedPointer&&) ;
			
			~SharedPointer() ;
	} ;
	
	template<class T>
	class UniquePointer : public Pointer<T> {
		public:
			UniquePointer() ;
			
			UniquePointer(T) ;
		
			UniquePointer(const UniquePointer&) = delete ;
			
			UniquePointer(UniquePointer&&) ;
			
			~UniquePointer() ;
	} ;
}

template<typename T>
Salih::Types::Pointer<T>::Pointer() {}

template<typename T>
Salih::Types::Pointer<T>::Pointer(T data)
{
	this->pointer = new T ;
	*pointer = data ;	
}

template<typename T>
T* Salih::Types::Pointer<T>::operator->()
{
	return this->pointer ;
}

template<typename T>
T& Salih::Types::Pointer<T>::operator*()
{
	return this->*pointer ;
}

template<typename T>
T* Salih::Types::Pointer<T>::get() const
{
	return this->pointer ;
}

template<typename T>
Salih::Types::Pointer<T>::~Pointer() {} ;

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer() : Salih::Types::Pointer<T>()
{}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(T data) : Salih::Types::Pointer<T>(data)
{
	this->count = new int ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(const Salih::Types::SharedPointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	*count = *(this->count) + 1 ;
}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(Salih::Types::SharedPointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	ptr.pointer = NULL ;
	ptr.count = NULL ;
}

template<typename T>
Salih::Types::SharedPointer<T>::~SharedPointer()
{
	if(*(this->count) <= 1) 
	{
		delete this->pointer ; this->pointer = NULL ;
		delete this->count ; this->count = NULL ;
	}
	else {
		*count = *(this->count) - 1 ;
	}
}

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer() : Salih::Types::Pointer<T>() {} ;

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer(T data) : Salih::Types::Pointer<T>(data) {} ;

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer(Salih::Types::UniquePointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	ptr.pointer = NULL ;
}

template<typename T>
Salih::Types::UniquePointer<T>::~UniquePointer()
{
	if(this->pointer != NULL) 
	{
		delete this->pointer ; 
		this->pointer = NULL ;
	}
}

//helpful overloads

template<typename T>
std::ostream& operator<<(std::ostream& os, const Salih::Types::Pointer<T>& ptr)
{
	os << ptr.get() ;
	return os ;
}

#endif
