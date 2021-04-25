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
	this->pointer = ptr ;	
	this->bytes = ct ;	
}

template<typename T>
Salih::Types::Pointer<void>::Pointer(T* ptr) 
{
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
}

Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(std::nullptr_t) 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
}

Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator()(void* ptr, std::size_t sz) 
{
	this->pointer = ptr ;	
	this->bytes = sz ;	
}

template<typename T>
Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(T* ptr) 
{
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
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
}
			
template<typename T>
Salih::Types::Pointer<void>& Salih::Types::Pointer<void>::operator=(const Salih::Types::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
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
	Salih::Types::Pointer<void>::operator=(x) ;
	this->count = nullptr ;
}

Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator()(void* ptr, std::size_t ct)
{
	Salih::Types::Pointer<void>::operator()(ptr,ct) ;
	this->count = new int ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(T* ptr)
{
	Salih::Types::Pointer<void>::operator=(ptr) ;
	this->count = new int ;
	*(this->count) = 1 ;
}
//dddddddddddddddddddddddddddddddddddddddddddddddddddd
Salih::Types::SharedPointer<void>::SharedPointer(const Salih::Types::SharedPointer<void>& ptr) : Salih::Types::Pointer<void>(ptr) 
{
	*(this->count) = *(this->count) + 1 ;
}
			
template<typename T>
Salih::Types::SharedPointer<void>::SharedPointer(const Salih::Types::SharedPointer<T>& ptr) : Salih::Types::Pointer<void>(ptr)
{
	*(this->count) = *(this->count) + 1 ;	
}
			
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(const Salih::Types::SharedPointer<void>& ptr)
{
	Salih::Types::Pointer<void>::operator=(ptr) ;
	*(this->count) = *(this->count) + 1 ;
}
			
template<typename T>
Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(const Salih::Types::SharedPointer<T>& ptr)
{
	Salih::Types::Pointer<void>::operator=(ptr) ;
	*(this->count) = *(this->count) + 1 ;
}

void Salih::Types::SharedPointer<void>::reset()
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

Salih::Types::SharedPointer<void>::~SharedPointer()
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

#endif
