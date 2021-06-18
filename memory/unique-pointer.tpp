#ifndef UNIQUE_POINTER_TPP
#define UNIQUE_POINTER_TPP

#include "base-pointer.hpp"

/** @brief Implementations of Unique pointer class. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer() : salih::memory::Pointer<T>() {} ;

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(const decltype(nullptr) x) : salih::memory::Pointer<T>() {} ;

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(T* data) : salih::memory::Pointer<T>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(void* data) : salih::memory::Pointer<T>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(T* data)
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(const decltype(nullptr) data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;
}

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(salih::memory::UniquePointer<T>&& ptr) : salih::memory::Pointer<T>( std::move(ptr) ) {} ;

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(salih::memory::UniquePointer<void>&& ptr) : salih::memory::Pointer<T>( std::move(ptr) ) {} ;

template<typename T>
salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(salih::memory::UniquePointer<T>&& ptr)
{
	salih::memory::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;	
}

template<typename T>
void salih::memory::UniquePointer<T>::reset() 
{
	if(this->pointer) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
salih::memory::UniquePointer<T>::~UniquePointer()
{
	this->reset() ;
}

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer() : salih::memory::Pointer<T[]>() {} ;

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(const decltype(nullptr) x) : salih::memory::Pointer<T[]>() {} ;

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(T* data) : salih::memory::Pointer<T[]>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(void* data) : salih::memory::Pointer<T[]>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(T* data)
{
	static_cast<Pointer<T[]>*>(&*this)->operator=(data) ;
	return *this ;	
}

template<typename T>
salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(std::nullptr_t data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;
}

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(salih::memory::UniquePointer<T[]>&& ptr) : salih::memory::Pointer<T[]>( std::move(ptr) ) {} ;

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(salih::memory::UniquePointer<void>&& ptr) : salih::memory::Pointer<T[]>( std::move(ptr) ) {} ;

template<typename T>
salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(salih::memory::UniquePointer<T[]>&& ptr)
{
	salih::memory::Pointer<T[]>::operator=( std::move(ptr) ) ;
	return *this ;	
}

template<typename T>
void salih::memory::UniquePointer<T[]>::reset() 
{
	if(this->pointer) 
	{
		delete[] this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
salih::memory::UniquePointer<T[]>::~UniquePointer()
{
	this->reset() ;
}

salih::memory::UniquePointer<void>::UniquePointer() : salih::memory::Pointer<void>() {} ;

salih::memory::UniquePointer<void>::UniquePointer(std::nullptr_t x) : salih::memory::Pointer<void>(x) {} ;

template<typename T>
salih::memory::UniquePointer<void>::UniquePointer(T* ptr) : salih::memory::Pointer<void>(ptr) {} ;

salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(std::nullptr_t x)
{
	salih::memory::Pointer<void>::operator=(x) ;
	return *this ;	
}

template<typename T>
salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(T* ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	return *this ;	
}

salih::memory::UniquePointer<void>::UniquePointer(salih::memory::UniquePointer<void>&& ptr) : salih::memory::Pointer<void>( std::move(ptr) ) {} ; 
			
template<typename T>
salih::memory::UniquePointer<void>::UniquePointer(salih::memory::UniquePointer<T>&& ptr) : salih::memory::Pointer<void>( std::move(ptr) ) {} ;

template<typename T>
salih::memory::UniquePointer<void>::UniquePointer(salih::memory::UniquePointer<T[]>&& ptr) : salih::memory::Pointer<void>( std::move(ptr) ) {} ;
			
salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(salih::memory::UniquePointer<void>&& ptr)
{
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(salih::memory::UniquePointer<T>&& ptr)
{
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(salih::memory::UniquePointer<T[]>&& ptr)
{
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

void salih::memory::UniquePointer<void>::reset()
{
	if(this->pointer)
	{
		operator delete(this->pointer, this->bytes) ; 
		this->pointer = nullptr ;
		this->bytes = 0 ;	
	}
}

salih::memory::UniquePointer<void>::~UniquePointer()
{
	this->reset() ;
}

template<class T>
salih::memory::UniquePointer<T> salih::memory::makeUnique()
{
	return salih::memory::UniquePointer<T>(new T) ;
}
	
template<class T, class... Args>
salih::memory::UniquePointer<T> salih::memory::makeUnique(const Args&&... args)
{
	T* p = new T(args...) ;
	return salih::memory::UniquePointer<T>(new T(args...)) ;
}
	
template<class T>
salih::memory::UniquePointer<T[]> salih::memory::makeUnique(const unsigned long sz)
{
	return salih::memory::UniquePointer<T[]>(new T[sz]) ;
}

#endif
