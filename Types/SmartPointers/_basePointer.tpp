#ifndef _BASE_POINTER_TPP
#define _BASE_POINTER_TPP

#include <stdexcept>
#include "utilities.hpp"

/** @brief File containing base class definitions for all smart pointers
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::Pointer() 
{
	this->pointer = nullptr ;	
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::Pointer(std::nullptr_t)
{
	this->pointer = nullptr ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::Pointer(T* data)
{
	if(! ::Salih::Types::SmartPointers::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = data ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::Pointer(void* data)
{
	if(! ::Salih::Types::SmartPointers::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = static_cast<T*>(data) ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>& Salih::Types::SmartPointers::Pointer<T>::operator=(std::nullptr_t)
{
	this->pointer = nullptr ;
	return *this ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>& Salih::Types::SmartPointers::Pointer<T>::operator=(T* data)
{
	if(! ::Salih::Types::SmartPointers::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = data ;
	return *this ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::Pointer(const Salih::Types::SmartPointers::Pointer<T>& ptr) : pointer(ptr.pointer) {} ;

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::Pointer(const Salih::Types::SmartPointers::Pointer<void>& ptr) 
{
	if(ptr.bytes != sizeof(T)) throw std::bad_cast() ;
	this->pointer = static_cast<T*>(ptr.pointer) ;
}

template<typename T>			
Salih::Types::SmartPointers::Pointer<T>& Salih::Types::SmartPointers::Pointer<T>::operator=(const Salih::Types::SmartPointers::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	return *this ;
}

template<typename T>			
Salih::Types::SmartPointers::Pointer<T>::Pointer(Salih::Types::SmartPointers::Pointer<T>&& ptr) : pointer(ptr.pointer) 
{
	ptr.pointer = nullptr ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::Pointer(Salih::Types::SmartPointers::Pointer<void>&& ptr) 
{
	if(ptr.bytes != sizeof(T)) throw std::bad_cast() ;
	this->pointer = static_cast<T*>(ptr.pointer) ;
	ptr.pointer = nullptr ;
}

template<typename T>			
Salih::Types::SmartPointers::Pointer<T>& Salih::Types::SmartPointers::Pointer<T>::operator=(Salih::Types::SmartPointers::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
	return *this ;
}

template<typename T>
T* Salih::Types::SmartPointers::Pointer<T>::operator->()
{
	return this->pointer ;
}

template<typename T>
T& Salih::Types::SmartPointers::Pointer<T>::operator*()
{
	return *(this->pointer) ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::operator bool() const
{
	return (this->pointer != nullptr) ;
}

template<typename T>
bool Salih::Types::SmartPointers::Pointer<T>::operator!() const
{
	return (this->pointer == nullptr) ;
}

template<typename T>
T* Salih::Types::SmartPointers::Pointer<T>::get() const
{
	return this->pointer ;
}

template<typename T>
Salih::Types::SmartPointers::Pointer<T>::~Pointer() {} ;

Salih::Types::SmartPointers::Pointer<void>::Pointer() 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
}

Salih::Types::SmartPointers::Pointer<void>::Pointer(std::nullptr_t) 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
}

Salih::Types::SmartPointers::Pointer<void>::Pointer(void* ptr, std::size_t ct) 
{
	if(! ::Salih::Types::SmartPointers::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = ct ;	
}

template<typename T>
Salih::Types::SmartPointers::Pointer<void>::Pointer(T* ptr) 
{
	if(! ::Salih::Types::SmartPointers::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
}

Salih::Types::SmartPointers::Pointer<void>& Salih::Types::SmartPointers::Pointer<void>::operator=(std::nullptr_t) 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
	return *this ;
}

Salih::Types::SmartPointers::Pointer<void>& Salih::Types::SmartPointers::Pointer<void>::operator()(void* ptr, std::size_t sz) 
{
	if(! ::Salih::Types::SmartPointers::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = sz ;
	return *this ;	
}

template<typename T>
Salih::Types::SmartPointers::Pointer<void>& Salih::Types::SmartPointers::Pointer<void>::operator=(T* ptr) 
{
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
	return *this ;
}

Salih::Types::SmartPointers::Pointer<void>::Pointer(const Salih::Types::SmartPointers::Pointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;
}
			
template<typename T>
Salih::Types::SmartPointers::Pointer<void>::Pointer(const Salih::Types::SmartPointers::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
}
			
Salih::Types::SmartPointers::Pointer<void>& Salih::Types::SmartPointers::Pointer<void>::operator=(const Salih::Types::SmartPointers::Pointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	return *this ;
}
			
template<typename T>
Salih::Types::SmartPointers::Pointer<void>& Salih::Types::SmartPointers::Pointer<void>::operator=(const Salih::Types::SmartPointers::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	return *this ;
}

Salih::Types::SmartPointers::Pointer<void>::Pointer(Salih::Types::SmartPointers::Pointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
}
			
template<typename T>
Salih::Types::SmartPointers::Pointer<void>::Pointer(Salih::Types::SmartPointers::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;	
}
			
Salih::Types::SmartPointers::Pointer<void>& Salih::Types::SmartPointers::Pointer<void>::operator=(Salih::Types::SmartPointers::Pointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
	return *this ;
}
			
template<typename T>
Salih::Types::SmartPointers::Pointer<void>& Salih::Types::SmartPointers::Pointer<void>::operator=(Salih::Types::SmartPointers::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
	return *this ;
}

Salih::Types::SmartPointers::Pointer<void>::operator bool() const
{
	return (this->pointer != nullptr) ;
}

bool Salih::Types::SmartPointers::Pointer<void>::operator!() const
{
	return (this->pointer == nullptr) ;
}

void* Salih::Types::SmartPointers::Pointer<void>::get() const 
{
	return this->pointer ;
}

Salih::Types::SmartPointers::Pointer<void>::~Pointer() {} ;

#endif
