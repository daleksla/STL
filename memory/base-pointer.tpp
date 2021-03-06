#ifndef BASE_POINTER_TPP
#define BASE_POINTER_TPP

/** @brief Implementations of the Base class for all smart pointers. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

#include <stdexcept>

template<typename T>
salih::memory::Pointer<T>::Pointer() : pointer(nullptr) {} ;

template<typename T>
salih::memory::Pointer<T>::Pointer(const decltype(nullptr)) : pointer(nullptr) {} ;

template<typename T>
salih::memory::Pointer<T>::Pointer(T* data)
{
	this->pointer = data ;
}

template<typename T>
salih::memory::Pointer<T>::Pointer(void* data)
{
	this->pointer = static_cast<T*>(data) ;
}

template<typename T>
salih::memory::Pointer<T>& salih::memory::Pointer<T>::operator=(const decltype(nullptr))
{
	this->reset() ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<T>& salih::memory::Pointer<T>::operator=(T* data)
{
	this->reset() ;
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
	this->reset() ;
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
	this->reset() ;
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

template<typename T>
salih::memory::Pointer<T[]>::Pointer() 
{
	this->pointer = nullptr ;	
}

template<typename T>
salih::memory::Pointer<T[]>::Pointer(const decltype(nullptr))
{
	this->pointer = nullptr ;
}

template<typename T>
salih::memory::Pointer<T[]>::Pointer(T* data)
{
	this->pointer = data ;
}

template<typename T>
salih::memory::Pointer<T[]>::Pointer(void* data)
{
	this->pointer = static_cast<T*>(data) ;
}

template<typename T>
salih::memory::Pointer<T[]>& salih::memory::Pointer<T[]>::operator=(const decltype(nullptr))
{
	this->reset() ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<T[]>& salih::memory::Pointer<T[]>::operator=(T* data)
{
	this->reset() ;
	this->pointer = data ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<T[]>& salih::memory::Pointer<T[]>::operator=(void* data)
{
	this->reset() ;
	this->pointer = static_cast<T*>(data) ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<T[]>::Pointer(const salih::memory::Pointer<T[]>& ptr) : pointer(ptr.pointer) {} ;

template<typename T>
salih::memory::Pointer<T[]>::Pointer(const salih::memory::Pointer<void>& ptr) 
{
	if(ptr.bytes / sizeof(T)) throw std::bad_cast() ; // it's a pointer to an array, since the array can be any size we just see if it at least can store x amount of T's
	this->pointer = static_cast<T*>(ptr.pointer) ;
}

template<typename T>			
salih::memory::Pointer<T[]>& salih::memory::Pointer<T[]>::operator=(const salih::memory::Pointer<T[]>& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	return *this ;
}

template<typename T>			
salih::memory::Pointer<T[]>::Pointer(salih::memory::Pointer<T[]>&& ptr) : pointer(ptr.pointer) 
{
	ptr.pointer = nullptr ;
}

template<typename T>
salih::memory::Pointer<T[]>::Pointer(salih::memory::Pointer<void>&& ptr) 
{
	if(ptr.bytes / sizeof(T)) throw std::bad_cast() ;
	this->pointer = static_cast<T*>(ptr.pointer) ;
	ptr.pointer = nullptr ;
}

template<typename T>			
salih::memory::Pointer<T[]>& salih::memory::Pointer<T[]>::operator=(salih::memory::Pointer<T[]>&& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
	return *this ;
}

template<typename T>
T& salih::memory::Pointer<T[]>::operator[](const unsigned long x)
{
	return this->pointer[x] ;
}

template<typename T>
const T& salih::memory::Pointer<T[]>::operator[](const unsigned long x) const
{
	return this->pointer[x] ;
}

template<typename T>
salih::memory::Pointer<T[]>::operator bool() const
{
	return (this->pointer != nullptr) ;
}

template<typename T>
bool salih::memory::Pointer<T[]>::operator!() const
{
	return (this->pointer == nullptr) ;
}

template<typename T>
T* salih::memory::Pointer<T[]>::get() const
{
	return this->pointer ;
}

template<typename T>
salih::memory::Pointer<T[]>::~Pointer() {} ;

salih::memory::Pointer<void>::Pointer() : pointer(nullptr), bytes(0) {} ;

salih::memory::Pointer<void>::Pointer(const decltype(nullptr)) : pointer(nullptr), bytes(0) {} ;

template<typename T>
salih::memory::Pointer<void>::Pointer(T* ptr) 
{
	this->pointer = ptr ;	
	this->bytes = sizeof(T) ;	
}

salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(const decltype(nullptr)) 
{
	this->reset() ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(T* ptr) 
{
	this->reset() ;
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

template<typename T>
salih::memory::Pointer<void>::Pointer(const salih::memory::Pointer<T[]>& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
}
			
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(const salih::memory::Pointer<void>& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	return *this ;
}
			
template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(const salih::memory::Pointer<T>& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(const salih::memory::Pointer<T[]>& ptr)
{
	this->reset() ;
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
}

template<typename T>
salih::memory::Pointer<void>::Pointer(salih::memory::Pointer<T[]>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
}
			
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(salih::memory::Pointer<void>&& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	this->bytes = ptr.bytes ;	
	ptr.pointer = nullptr ;
	ptr.bytes = 0 ;
	return *this ;
}
			
template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(salih::memory::Pointer<T>&& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
	return *this ;
}

template<typename T>
salih::memory::Pointer<void>& salih::memory::Pointer<void>::operator=(salih::memory::Pointer<T[]>&& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	this->bytes = sizeof(T) ;
	ptr.pointer = nullptr ;
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
