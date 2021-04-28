#ifndef _VOID_POINTERS_TPP
#define _VOID_POINTERS_TPP
#pragma once

#include <iostream>
#include <stdexcept>

Salih::Types::Pointer<void>::Pointer() 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
}

Salih::Types::Pointer<void>::Pointer(std::nullptr_t) 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
}

Salih::Types::Pointer<void>::Pointer(void* ptr, std::size_t ct) 
{
	if(! ::Salih::Types::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = ct ;	
}

template<typename T>
Salih::Types::Pointer<void>::Pointer(T* ptr) 
{
	if(! ::Salih::Types::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
}

Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(std::nullptr_t) 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
	return *this ;
}

Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator()(void* ptr, std::size_t sz) 
{
	if(! ::Salih::Types::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = sz ;
	return *this ;	
}

template<typename T>
Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(T* ptr) 
{
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
	return *this ;
}

Salih::Types::Pointer<void>::Pointer(const Salih::Types::Pointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;
}
			
template<typename T>
Salih::Types::Pointer<void>::Pointer(const Salih::Types::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
}
			
Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(const Salih::Types::Pointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	return *this ;
}
			
template<typename T>
Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(const Salih::Types::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	return *this ;
}

///ddd
Salih::Types::Pointer<void>::Pointer(Salih::Types::Pointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
}
			
template<typename T>
Salih::Types::Pointer<void>::Pointer(Salih::Types::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;	
}
			
Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(Salih::Types::Pointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
	return *this ;
}
			
template<typename T>
Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(Salih::Types::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
	return *this ;
}

bool Salih::Types::Pointer<void>::operator() const
{
	return (this->pointer != nullptr) ;
}

bool Salih::Types::Pointer<void>::operator!() const
{
	return (this->pointer == nullptr) ;
}

void* Salih::Types::Pointer<void>::get() const 
{
	return this->pointer ;
}

Salih::Types::Pointer<void>::~Pointer() {} ;

Salih::Types::SharedPointer<void>::SharedPointer() : Salih::Types::Pointer<void>() 
{
	this->count = nullptr ;
}

Salih::Types::SharedPointer<void>::SharedPointer(std::nullptr_t x) : Salih::Types::Pointer<void>(x) 
{
	this->count = nullptr ;
}

Salih::Types::SharedPointer<void>::SharedPointer(void* ptr, std::size_t ct) : Salih::Types::Pointer<void>(ptr,ct) 
{
	this->count = new int ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SharedPointer<void>::SharedPointer(T* ptr) : Salih::Types::Pointer<void>(ptr) 
{
	this->count = new int ;
	*(this->count) = 1 ;
}

Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(std::nullptr_t x)
{
	this->reset() ;
	Salih::Types::Pointer<void>::operator=(x) ;
	this->count = new int ; *(this->count) = 1 ;
	return *this ;	
}

Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator()(void* ptr, std::size_t ct)
{
	this->reset() ;
	Salih::Types::Pointer<void>::operator()(ptr,ct) ;
	this->count = new int ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(T* ptr)
{
	this->reset() ;
	Salih::Types::Pointer<void>::operator=(ptr) ;
	this->count = new int ; *(this->count) = 1 ;
	return *this ;	
}
//dddddddddddddddddddddddddddddddddddddddddddddddddddd
Salih::Types::SharedPointer<void>::SharedPointer(const Salih::Types::SharedPointer<void>& ptr) : Salih::Types::Pointer<void>(ptr) 
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
template<typename T>
Salih::Types::SharedPointer<void>::SharedPointer(const Salih::Types::SharedPointer<T>& ptr) : Salih::Types::Pointer<void>(ptr)
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(const Salih::Types::SharedPointer<void>& ptr)
{
	Salih::Types::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}
			
template<typename T>
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(const Salih::Types::SharedPointer<T>& ptr)
{
	Salih::Types::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}

//fffffffffffffffffffffff
Salih::Types::SharedPointer<void>::SharedPointer(Salih::Types::SharedPointer<void>&& ptr) : count(ptr.count), Salih::Types::Pointer<void>( std::move(ptr) ) 
{
	ptr.count = nullptr ;
} 
			
template<typename T>
Salih::Types::SharedPointer<void>::SharedPointer(Salih::Types::SharedPointer<T>&& ptr) : count(ptr.count), Salih::Types::Pointer<void>( std::move(ptr) )
{
	ptr.count = nullptr ;
}
			
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(Salih::Types::SharedPointer<void>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	Salih::Types::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(Salih::Types::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	Salih::Types::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

void Salih::Types::SharedPointer<void>::reset()
{
	if(this->pointer)
	{
		if(*(this->count) == 1)
		{
			operator delete(this->pointer, this->bytes) ; 
			delete this->count ;
		}
		else {
			*(this->count) = (*this->count) - 1 ;
		}
		this->count = nullptr ;
		this->pointer = nullptr ;	
	}
}

Salih::Types::SharedPointer<void>::~SharedPointer()
{
	if(this->pointer)
	{
		if(*(this->count) == 1)
		{
			operator delete(this->pointer, this->bytes) ; 
			delete this->count ;
		}
		else {
			*(this->count) = (*this->count) - 1 ;
		}
	}
}

Salih::Types::UniquePointer<void>::UniquePointer() : Salih::Types::Pointer<void>() {} ;

Salih::Types::UniquePointer<void>::UniquePointer(std::nullptr_t x) : Salih::Types::Pointer<void>(x) {} ;

Salih::Types::UniquePointer<void>::UniquePointer(void* ptr, std::size_t ct) : Salih::Types::Pointer<void>(ptr,ct) {} ;

template<typename T>
Salih::Types::UniquePointer<void>::UniquePointer(T* ptr) : Salih::Types::Pointer<void>(ptr) {} ;

Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator=(std::nullptr_t x)
{
	this->reset() ;
	Salih::Types::Pointer<void>::operator=(x) ;
	return *this ;	
}

Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator()(void* ptr, std::size_t ct)
{
	this->reset() ;
	Salih::Types::Pointer<void>::operator()(ptr, ct) ;
	return *this ;	
}

template<typename T>
Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator=(T* ptr)
{
	this->reset() ;
	Salih::Types::Pointer<void>::operator=(ptr) ;
	return *this ;	
}

//dddddddddddddddddddddddddddddddddddddddddddddddddddd
Salih::Types::UniquePointer<void>::UniquePointer(Salih::Types::UniquePointer<void>&& ptr) : Salih::Types::Pointer<void>( std::move(ptr) ) {} ; 
			
template<typename T>
Salih::Types::UniquePointer<void>::UniquePointer(Salih::Types::UniquePointer<T>&& ptr) : Salih::Types::Pointer<void>( std::move(ptr) ) {} ;
			
Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator=(Salih::Types::UniquePointer<void>&& ptr)
{
	Salih::Types::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator=(Salih::Types::UniquePointer<T>&& ptr)
{
	Salih::Types::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

void Salih::Types::UniquePointer<void>::reset()
{
	if(this->pointer)
	{
		operator delete(this->pointer, this->bytes) ; 
		this->pointer = nullptr ;	
	}
}

Salih::Types::UniquePointer<void>::~UniquePointer()
{
	if(this->pointer)
	{
		operator delete(this->pointer, this->bytes) ; 
	}
}

#endif
