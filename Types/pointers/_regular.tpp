#ifndef _REGULAR_POINTERS_TPP
#define _REGULAR_POINTERS_TPP
#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
Salih::Types::Pointer<T>::Pointer() 
{
	this->pointer = nullptr ;	
}

template<typename T>
Salih::Types::Pointer<T>::Pointer(std::nullptr_t)
{
	this->pointer = nullptr ;
}

template<typename T>
Salih::Types::Pointer<T>::Pointer(T* data)
{
	if(! ::Salih::Types::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = data ;
}

template<typename T>
Salih::Types::Pointer<T>& Salih::Types::Pointer<T>::operator=(std::nullptr_t)
{
	this->pointer = nullptr ;
	return *this ;
}

template<typename T>
Salih::Types::Pointer<T>& Salih::Types::Pointer<T>::operator=(T* data)
{
	if(! ::Salih::Types::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = data ;
	return *this ;
}

template<typename T>
Salih::Types::Pointer<T>::Pointer(const Salih::Types::Pointer<T>& ptr) : pointer(ptr.pointer) {} ;

template<typename T>			
Salih::Types::Pointer<T>& Salih::Types::Pointer<T>::operator=(const Salih::Types::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	return *this ;
}

template<typename T>			
Salih::Types::Pointer<T>::Pointer(Salih::Types::Pointer<T>&& ptr) : pointer(ptr.pointer) 
{
	ptr.pointer = nullptr ;
}

template<typename T>			
Salih::Types::Pointer<T>& Salih::Types::Pointer<T>::operator=(Salih::Types::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
	return *this ;
}

template<typename T>
T* Salih::Types::Pointer<T>::operator->()
{
	return this->pointer ;
}

template<typename T>
T& Salih::Types::Pointer<T>::operator*()
{
	return *(this->pointer) ;
}

template<typename T>
Salih::Types::Pointer<T>::operator bool() const
{
	return (this->pointer != nullptr) ;
}

template<typename T>
bool Salih::Types::Pointer<T>::operator!() const
{
	return (this->pointer == nullptr) ;
}

template<typename T>
T* Salih::Types::Pointer<T>::get() const
{
	return this->pointer ;
}

template<typename T>
Salih::Types::Pointer<T>::~Pointer() {} ;

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer() : Salih::Types::Pointer<T>(), count(nullptr) {} ;

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(std::nullptr_t x) : Salih::Types::Pointer<T>(x), count(nullptr) {} ;

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(T* data) : Salih::Types::Pointer<T>(data)
{
	this->count = new int ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SharedPointer<T>& Salih::Types::SharedPointer<T>::operator=(T* data)
{
	this->reset() ;
	Salih::Types::Pointer<T>::operator=(data) ;
	this->count = new int ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
Salih::Types::SharedPointer<T>& Salih::Types::SharedPointer<T>::operator=(std::nullptr_t data) 
{
	this->reset() ;
	this->count = nullptr ;
	return *this ;	
}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(const Salih::Types::SharedPointer<T>& ptr) : Salih::Types::Pointer<T>(ptr), count(ptr.count)
{
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
Salih::Types::SharedPointer<T>& Salih::Types::SharedPointer<T>::operator=(const Salih::Types::SharedPointer<T>& ptr)
{
	Salih::Types::Pointer<T>::operator=(ptr) ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
	return *this ;
}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(Salih::Types::SharedPointer<T>&& ptr) : count(ptr.count), Salih::Types::Pointer<T>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
Salih::Types::SharedPointer<T>& Salih::Types::SharedPointer<T>::operator=(Salih::Types::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	Salih::Types::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
void Salih::Types::SharedPointer<T>::reset() 
{
	if(this->pointer) 
	{
		*(this->count) = *(this->count) - 1 ; 
		if( *(this->count) == 0) 
		{
			delete this->pointer ; 
			delete this->count ;
		}
	}
	this->pointer = nullptr ;
	this->count = nullptr ;
}

template<typename T>
Salih::Types::SharedPointer<T>::~SharedPointer()
{
	if(this->pointer) 
	{
		*(this->count) = *(this->count) - 1 ; 
		if( *(this->count) == 0) 
		{
			delete this->pointer ; 
			delete this->count ;
		}
	}
	this->pointer = nullptr ;
	this->count = nullptr ;
}

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer() : Salih::Types::Pointer<T>() {} ;

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer(std::nullptr_t x) : Salih::Types::Pointer<T>() {} ;

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer(T* data) : Salih::Types::Pointer<T>(data) {} ;

template<typename T>
Salih::Types::UniquePointer<T>& Salih::Types::UniquePointer<T>::operator=(T* data)
{
	this->reset() ;
	Salih::Types::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
Salih::Types::UniquePointer<T>& Salih::Types::UniquePointer<T>::operator=(std::nullptr_t data) 
{
	return *this ;
}

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer(Salih::Types::UniquePointer<T>&& ptr) : Salih::Types::Pointer<T>( std::move(ptr) ) {} ;

template<typename T>
Salih::Types::UniquePointer<T>& Salih::Types::UniquePointer<T>::operator=(Salih::Types::UniquePointer<T>&& ptr)
{
	Salih::Types::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;	
}

template<typename T>
void Salih::Types::UniquePointer<T>::reset() 
{
	if(this->pointer) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
Salih::Types::UniquePointer<T>::~UniquePointer()
{
	if(this->pointer) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

#endif
