#ifndef SHARED_POINTER_TPP
#define SHARED_POINTER_TPP

/** @brief File containing shared pointer class definitions
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer() : salih::memory::Pointer<T>(), count(nullptr) {} ;

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(std::nullptr_t x) : salih::memory::Pointer<T>(x), count(nullptr) {} ;

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(T* data) : salih::memory::Pointer<T>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(void* data) : salih::memory::Pointer<T>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(T* data)
{
	this->reset() ;
	salih::memory::Pointer<T>::operator=(data) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(std::nullptr_t data) 
{
	this->reset() ;
	this->count = nullptr ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(const salih::memory::SharedPointer<T>& ptr) : salih::memory::Pointer<T>(ptr), count(ptr.count)
{
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
salih::memory::SharedPointer<T>::SharedPointer(const salih::memory::SharedPointer<void>& ptr) : salih::memory::Pointer<T>(ptr)
{
	this->count = ptr.count ;
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

salih::memory::SharedPointer<void>::SharedPointer() : salih::memory::Pointer<void>() 
{
	this->count = nullptr ;
}

salih::memory::SharedPointer<void>::SharedPointer(std::nullptr_t x) : salih::memory::Pointer<void>(x) 
{
	this->count = nullptr ;
}

salih::memory::SharedPointer<void>::SharedPointer(void* ptr, std::size_t ct) : salih::memory::Pointer<void>(ptr,ct) 
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
salih::memory::SharedPointer<void>::SharedPointer(T* ptr) : salih::memory::Pointer<void>(ptr) 
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(std::nullptr_t x)
{
	this->reset() ;
	salih::memory::Pointer<void>::operator=(x) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(T* ptr)
{
	this->reset() ;
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
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

salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<void>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) ) 
{
	ptr.count = nullptr ;
} 
			
template<typename T>
salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<T>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) )
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

#endif
