#ifndef _VOID_POINTERS_TPP
#define _VOID_POINTERS_TPP
#pragma once

#include <iostream>
#include <stdexcept>

Salih::Types::Pointer<void>::Pointer() 
{
	this->pointer = nullptr ;	
}

Salih::Types::Pointer<void>::Pointer(std::nullptr_t)
{
	this->pointer = nullptr ;
}

Salih::Types::Pointer<void>::Pointer(void* data)
{
	if(! ::Salih::Types::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = data ;
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

Salih::Types::SharedPointer<void>::SharedPointer(std::nullptr_t x) : Salih::Types::Pointer<void>(x) {} ;

Salih::Types::SharedPointer<void>::SharedPointer(void* data) : Salih::Types::Pointer<void>(data)
{
	this->count = new int ;
	*(this->count) = 1 ;
}

Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(void* data)
{
	//this->reset() ;

	if(! ::Salih::Types::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	
	this->pointer = data ;
	this->count = new int ;
	*(this->count) = 1 ;
	return *this ;
}

Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(std::nullptr_t data) 
{
	return *this ;
}

Salih::Types::SharedPointer<void>::SharedPointer(const Salih::Types::SharedPointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(const Salih::Types::SharedPointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
	return *this ;
}

Salih::Types::SharedPointer<void>::SharedPointer(Salih::Types::SharedPointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

Salih::Types::SharedPointer<void>& Salih::Types::SharedPointer<void>::operator=(Salih::Types::SharedPointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
	return *this ;
}

void Salih::Types::SharedPointer<void>::reset() 
{	
	if(this->count != nullptr) 
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

Salih::Types::SharedPointer<void>::~SharedPointer()
{
	if(this->count != nullptr) 
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

Salih::Types::UniquePointer<void>::UniquePointer() : Salih::Types::Pointer<void>() {} ;

Salih::Types::UniquePointer<void>::UniquePointer(std::nullptr_t x) : Salih::Types::Pointer<void>(x) {} ;

Salih::Types::UniquePointer<void>::UniquePointer(void* data) : Salih::Types::Pointer<void>(data) {} ;

Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator=(void* data)
{
	//this->reset() ;
	if(! ::Salih::Types::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
            
        this->reset() ;    

	this->pointer = data ;
}

Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator=(std::nullptr_t data) {} ;

Salih::Types::UniquePointer<void>::UniquePointer(Salih::Types::UniquePointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
}

Salih::Types::UniquePointer<void>& Salih::Types::UniquePointer<void>::operator=(Salih::Types::UniquePointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
}

void Salih::Types::UniquePointer<void>::reset() 
{
	if(this->pointer != nullptr) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

Salih::Types::UniquePointer<void>::~UniquePointer()
{
	if(this->pointer != nullptr) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

#endif
