#ifndef SHARED_POINTER_TPP
#define SHARED_POINTER_TPP

#include "base-pointer.hpp"

/** @brief Implementations of Shared pointer class. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/
template<typename T>
salih::memory::SharedPointer<T>::SharedPointer() : salih::memory::Pointer<T>(), count(nullptr) {} ;

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(const decltype(nullptr) x) : salih::memory::Pointer<T>(x), count(nullptr) {} ;

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(T* data) : salih::memory::Pointer<T>(data)
{
	this->count = new unsigned long ;
	*(this->count) = 1 ;
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(void* data) : salih::memory::Pointer<T>(data)
{
	this->count = new unsigned long ;
	*(this->count) = 1 ;
}

template<typename T>
salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(T* data)
{
	salih::memory::Pointer<T>::operator=(data) ;
	this->count = new unsigned long ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(const decltype(nullptr) data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(const salih::memory::SharedPointer<T>& ptr) : salih::memory::Pointer<T>(ptr), count(ptr.count)
{
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(const salih::memory::SharedPointer<void>& ptr) : salih::memory::Pointer<T>(ptr), count(ptr.count)
{
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(const salih::memory::SharedPointer<T>& ptr)
{
	salih::memory::Pointer<T>::operator=(ptr) ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
	return *this ;
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(salih::memory::SharedPointer<T>&& ptr) : count(ptr.count), salih::memory::Pointer<T>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(salih::memory::SharedPointer<void>&& ptr) : count(ptr.count), salih::memory::Pointer<T>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(salih::memory::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
void salih::memory::SharedPointer<T>::reset() 
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
salih::memory::SharedPointer<T>::~SharedPointer()
{
	this->reset() ;
}

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer() : salih::memory::Pointer<T[]>(), count(nullptr) {} ;

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer(const decltype(nullptr) x) : salih::memory::Pointer<T>(x), count(nullptr) {} ;

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer(T* data) : salih::memory::Pointer<T[]>(data)
{
	this->count = new unsigned long ;
	*(this->count) = 1 ;
}

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer(void* data) : salih::memory::Pointer<T[]>(data)
{
	this->count = new unsigned long ;
	*(this->count) = 1 ;
}

template<typename T>
salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(T* data)
{
	salih::memory::Pointer<T[]>::operator=(data) ;
	this->count = new unsigned long ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(const decltype(nullptr) data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer(const salih::memory::SharedPointer<T[]>& ptr) : salih::memory::Pointer<T[]>(ptr), count(ptr.count)
{
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer(const salih::memory::SharedPointer<void>& ptr) : salih::memory::Pointer<T[]>(ptr)
{
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(const salih::memory::SharedPointer<T[]>& ptr)
{
	salih::memory::Pointer<T[]>::operator=(ptr) ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
	return *this ;
}

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer(salih::memory::SharedPointer<T[]>&& ptr) : count(ptr.count), salih::memory::Pointer<T[]>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
salih::memory::SharedPointer<T[]>::SharedPointer(salih::memory::SharedPointer<void>&& ptr) : count(ptr.count), salih::memory::Pointer<T[]>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(salih::memory::SharedPointer<T[]>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
void salih::memory::SharedPointer<T[]>::reset() 
{
	if(this->pointer) 
	{
		*(this->count) = *(this->count) - 1 ; 
		if( *(this->count) == 0) 
		{
			delete[] this->pointer ; 
			delete this->count ;
		}
	}
	this->pointer = nullptr ;
	this->count = nullptr ;
}

template<typename T>
salih::memory::SharedPointer<T[]>::~SharedPointer()
{
	this->reset() ;
}

salih::memory::SharedPointer<void>::SharedPointer() : salih::memory::Pointer<void>(), count(nullptr) {} ;

salih::memory::SharedPointer<void>::SharedPointer(const decltype(nullptr) x) : salih::memory::Pointer<void>(x), count(nullptr) {} ;

template<typename T>
salih::memory::SharedPointer<void>::SharedPointer(T* ptr) : salih::memory::Pointer<void>(ptr) 
{
	this->count = new unsigned long ;
	*(this->count) = 1 ;
}

salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(const decltype(nullptr) x)
{
	salih::memory::Pointer<void>::operator=(x) ;
	this->count = new unsigned long ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(T* ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = new unsigned long ; *(this->count) = 1 ;
	return *this ;	
}

salih::memory::SharedPointer<void>::SharedPointer(const salih::memory::SharedPointer<void>& ptr) : salih::memory::Pointer<void>(ptr) 
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
template<typename T>
salih::memory::SharedPointer<void>::SharedPointer(const salih::memory::SharedPointer<T>& ptr) : salih::memory::Pointer<void>(ptr)
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}

template<typename T>
salih::memory::SharedPointer<void>::SharedPointer(const salih::memory::SharedPointer<T[]>& ptr) : salih::memory::Pointer<void>(ptr)
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(const salih::memory::SharedPointer<void>& ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}
			
template<typename T>
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(const salih::memory::SharedPointer<T>& ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(const salih::memory::SharedPointer<T[]>& ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}

salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<void>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) ) 
{
	ptr.count = nullptr ;
} 
			
template<typename T>
salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<T>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) )
{
	ptr.count = nullptr ;
}

template<typename T>
salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<T[]>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) )
{
	ptr.count = nullptr ;
}
			
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(salih::memory::SharedPointer<void>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(salih::memory::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(salih::memory::SharedPointer<T[]>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

void salih::memory::SharedPointer<void>::reset()
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

salih::memory::SharedPointer<void>::~SharedPointer()
{
	this->reset() ;
}

template<class T>
salih::memory::SharedPointer<T> salih::memory::makeShared()
{
	return salih::memory::SharedPointer<T>(new T) ;
}
	
template<class T, class... Args>
salih::memory::SharedPointer<T> salih::memory::makeShared(Args&&... args)
{
	return salih::memory::SharedPointer<T>(new T(args...)) ;
}
	
template<class T>
salih::memory::SharedPointer<T[]> salih::memory::makeShared(const unsigned long sz)
{
	return salih::memory::SharedPointer<T[]>(new T[sz]) ;
}

#endif
