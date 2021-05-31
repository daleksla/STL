#ifndef SHARED_POINTER_TPP
#define SHARED_POINTER_TPP

/** @brief File containing shared pointer class definitions
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer() : Salih::Types::SmartPointers::Pointer<T>(), count(nullptr) {} ;

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer(std::nullptr_t x) : Salih::Types::SmartPointers::Pointer<T>(x), count(nullptr) {} ;

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer(T* data) : Salih::Types::SmartPointers::Pointer<T>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer(void* data) : Salih::Types::SmartPointers::Pointer<T>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>& Salih::Types::SmartPointers::SharedPointer<T>::operator=(T* data)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<T>::operator=(data) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>& Salih::Types::SmartPointers::SharedPointer<T>::operator=(std::nullptr_t data) 
{
	this->reset() ;
	this->count = nullptr ;
	return *this ;	
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer(const Salih::Types::SmartPointers::SharedPointer<T>& ptr) : Salih::Types::SmartPointers::Pointer<T>(ptr), count(ptr.count)
{
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer(const Salih::Types::SmartPointers::SharedPointer<void>& ptr) : Salih::Types::SmartPointers::Pointer<T>(ptr)
{
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>& Salih::Types::SmartPointers::SharedPointer<T>::operator=(const Salih::Types::SmartPointers::SharedPointer<T>& ptr)
{
	Salih::Types::SmartPointers::Pointer<T>::operator=(ptr) ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
	return *this ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer(Salih::Types::SmartPointers::SharedPointer<T>&& ptr) : count(ptr.count), Salih::Types::SmartPointers::Pointer<T>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>::SharedPointer(Salih::Types::SmartPointers::SharedPointer<void>&& ptr) : count(ptr.count), Salih::Types::SmartPointers::Pointer<T>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<T>& Salih::Types::SmartPointers::SharedPointer<T>::operator=(Salih::Types::SmartPointers::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	Salih::Types::SmartPointers::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
void Salih::Types::SmartPointers::SharedPointer<T>::reset() 
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
Salih::Types::SmartPointers::SharedPointer<T>::~SharedPointer()
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

Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer() : Salih::Types::SmartPointers::Pointer<void>() 
{
	this->count = nullptr ;
}

Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer(std::nullptr_t x) : Salih::Types::SmartPointers::Pointer<void>(x) 
{
	this->count = nullptr ;
}

Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer(void* ptr, std::size_t ct) : Salih::Types::SmartPointers::Pointer<void>(ptr,ct) 
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer(T* ptr) : Salih::Types::SmartPointers::Pointer<void>(ptr) 
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

Salih::Types::SmartPointers::SharedPointer<void>& Salih::Types::SmartPointers::SharedPointer<void>::operator=(std::nullptr_t x)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<void>::operator=(x) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

Salih::Types::SmartPointers::SharedPointer<void>& Salih::Types::SmartPointers::SharedPointer<void>::operator()(void* ptr, std::size_t ct)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<void>::operator()(ptr,ct) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
Salih::Types::SmartPointers::SharedPointer<void>& Salih::Types::SmartPointers::SharedPointer<void>::operator=(T* ptr)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<void>::operator=(ptr) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer(const Salih::Types::SmartPointers::SharedPointer<void>& ptr) : Salih::Types::SmartPointers::Pointer<void>(ptr) 
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
template<typename T>
Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer(const Salih::Types::SmartPointers::SharedPointer<T>& ptr) : Salih::Types::SmartPointers::Pointer<void>(ptr)
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
Salih::Types::SmartPointers::SharedPointer<void>& Salih::Types::SmartPointers::SharedPointer<void>::operator=(const Salih::Types::SmartPointers::SharedPointer<void>& ptr)
{
	Salih::Types::SmartPointers::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}
			
template<typename T>
Salih::Types::SmartPointers::SharedPointer<void>& Salih::Types::SmartPointers::SharedPointer<void>::operator=(const Salih::Types::SmartPointers::SharedPointer<T>& ptr)
{
	Salih::Types::SmartPointers::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}

Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer(Salih::Types::SmartPointers::SharedPointer<void>&& ptr) : count(ptr.count), Salih::Types::SmartPointers::Pointer<void>( std::move(ptr) ) 
{
	ptr.count = nullptr ;
} 
			
template<typename T>
Salih::Types::SmartPointers::SharedPointer<void>::SharedPointer(Salih::Types::SmartPointers::SharedPointer<T>&& ptr) : count(ptr.count), Salih::Types::SmartPointers::Pointer<void>( std::move(ptr) )
{
	ptr.count = nullptr ;
}
			
Salih::Types::SmartPointers::SharedPointer<void>& Salih::Types::SmartPointers::SharedPointer<void>::operator=(Salih::Types::SmartPointers::SharedPointer<void>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	Salih::Types::SmartPointers::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
Salih::Types::SmartPointers::SharedPointer<void>& Salih::Types::SmartPointers::SharedPointer<void>::operator=(Salih::Types::SmartPointers::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	Salih::Types::SmartPointers::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

void Salih::Types::SmartPointers::SharedPointer<void>::reset()
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

Salih::Types::SmartPointers::SharedPointer<void>::~SharedPointer()
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
