#ifndef BASE_POINTER_TPP
#define BASE_POINTER_TPP

#include <stdexcept>
#include "utilities.hpp"

/** @brief File containing base class definitions for all smart pointers
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
salih::memory::Pointer<T>::Pointer() 
{
	this->pointer = nullptr ;	
}

template<typename T>
salih::memory::Pointer<T>::Pointer(std::nullptr_t)
{
	this->pointer = nullptr ;
}

template<typename T>
salih::memory::Pointer<T>::Pointer(T* data)
{
	if(! ::salih::memory::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = data ;
}

template<typename T>
salih::memory::Pointer<T>::Pointer(void* data)
{
	if(! ::salih::memory::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = static_cast<T*>(data) ;
}

template<typename T>
salih::memory::Pointer<T>& salih::memory::Pointer<T>::operator=(std::nullptr_t)
{
	this->pointer = nullptr ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<T>& salih::memory::Pointer<T>::operator=(T* data)
{
	if(! ::salih::memory::isHeap(data) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = data ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<T>::Pointer(const salih::memory::Pointer<T>& ptr) : pointer(ptr.pointer) {} ;

template<typename T>
salih::memory::Pointer<T>::Pointer(const salih::memory::Pointer<void>& ptr) 
{
	if(ptr.bytes != sizeof(T)) throw std::bad_cast() ;
	this->pointer = static_cast<T*>(ptr.pointer) ;
}

template<typename T>			
salih::memory::Pointer<T>& salih::memory::Pointer<T>::operator=(const salih::memory::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	return *this ;
}

template<typename T>			
salih::memory::Pointer<T>::Pointer(salih::memory::Pointer<T>&& ptr) : pointer(ptr.pointer) 
{
	ptr.pointer = nullptr ;
}

template<typename T>
salih::memory::Pointer<T>::Pointer(salih::memory::Pointer<void>&& ptr) 
{
	if(ptr.bytes != sizeof(T)) throw std::bad_cast() ;
	this->pointer = static_cast<T*>(ptr.pointer) ;
	ptr.pointer = nullptr ;
}

template<typename T>			
salih::memory::Pointer<T>& salih::memory::Pointer<T>::operator=(salih::memory::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
	return *this ;
}

template<typename T>
T* salih::memory::Pointer<T>::operator->()
{
	return this->pointer ;
}

template<typename T>
T& salih::memory::Pointer<T>::operator*()
{
	return *(this->pointer) ;
}

template<typename T>
salih::memory::Pointer<T>::operator bool() const
{
	return (this->pointer != nullptr) ;
}

template<typename T>
bool salih::memory::Pointer<T>::operator!() const
{
	return (this->pointer == nullptr) ;
}

template<typename T>
T* salih::memory::Pointer<T>::get() const
{
	return this->pointer ;
}

template<typename T>
salih::memory::Pointer<T>::~Pointer() {} ;

salih::memory::Pointer<void>::Pointer() 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
}

salih::memory::Pointer<void>::Pointer(std::nullptr_t) 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
}

salih::memory::Pointer<void>::Pointer(void* ptr, std::size_t ct) 
{
	if(! ::salih::memory::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = ct ;	
}

template<typename T>
salih::memory::Pointer<void>::Pointer(T* ptr) 
{
	if(! ::salih::memory::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
}

salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(std::nullptr_t) 
{
	this->pointer = nullptr ;	
	this->bytes = 0 ;	
	return *this ;
}

salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator()(void* ptr, std::size_t sz) 
{
	if(! ::salih::memory::isHeap(ptr) ) throw std::runtime_error("Cannot allocate stack pointer to smart pointer")  ;
	this->pointer = ptr ;	
	this->bytes = sz ;
	return *this ;	
}

template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(T* ptr) 
{
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
	return *this ;
}

salih::memory::Pointer<void>::Pointer(const salih::memory::Pointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;
}
			
template<typename T>
salih::memory::Pointer<void>::Pointer(const salih::memory::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
}
			
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(const salih::memory::Pointer<void>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	return *this ;
}
			
template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(const salih::memory::Pointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	return *this ;
}

salih::memory::Pointer<void>::Pointer(salih::memory::Pointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
}
			
template<typename T>
salih::memory::Pointer<void>::Pointer(salih::memory::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;	
}
			
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(salih::memory::Pointer<void>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
	return *this ;
}
			
template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(salih::memory::Pointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
	return *this ;
}

salih::memory::Pointer<void>::operator bool() const
{
	return (this->pointer != nullptr) ;
}

bool salih::memory::Pointer<void>::operator!() const
{
	return (this->pointer == nullptr) ;
}

void* salih::memory::Pointer<void>::get() const 
{
	return this->pointer ;
}

salih::memory::Pointer<void>::~Pointer() {} ;

#endif
