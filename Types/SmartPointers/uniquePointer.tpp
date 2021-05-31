#ifndef UNIQUE_POINTER_TPP
#define UNIQUE_POINTER_TPP

/** @brief File containing unique pointer class definitions
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>::UniquePointer() : Salih::Types::SmartPointers::Pointer<T>() {} ;

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>::UniquePointer(std::nullptr_t x) : Salih::Types::SmartPointers::Pointer<T>() {} ;

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>::UniquePointer(T* data) : Salih::Types::SmartPointers::Pointer<T>(data) {} ;

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>::UniquePointer(void* data) : Salih::Types::SmartPointers::Pointer<T>(data) {} ;

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>& Salih::Types::SmartPointers::UniquePointer<T>::operator=(T* data)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>& Salih::Types::SmartPointers::UniquePointer<T>::operator=(std::nullptr_t data) 
{
	return *this ;
}

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>::UniquePointer(Salih::Types::SmartPointers::UniquePointer<T>&& ptr) : Salih::Types::SmartPointers::Pointer<T>( std::move(ptr) ) {} ;

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>::UniquePointer(Salih::Types::SmartPointers::UniquePointer<void>&& ptr) : Salih::Types::SmartPointers::Pointer<T>( std::move(ptr) ) {} ;

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>& Salih::Types::SmartPointers::UniquePointer<T>::operator=(Salih::Types::SmartPointers::UniquePointer<T>&& ptr)
{
	Salih::Types::SmartPointers::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;	
}

template<typename T>
void Salih::Types::SmartPointers::UniquePointer<T>::reset() 
{
	if(this->pointer) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
Salih::Types::SmartPointers::UniquePointer<T>::~UniquePointer()
{
	if(this->pointer) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

Salih::Types::SmartPointers::UniquePointer<void>::UniquePointer() : Salih::Types::SmartPointers::Pointer<void>() {} ;

Salih::Types::SmartPointers::UniquePointer<void>::UniquePointer(std::nullptr_t x) : Salih::Types::SmartPointers::Pointer<void>(x) {} ;

Salih::Types::SmartPointers::UniquePointer<void>::UniquePointer(void* ptr, std::size_t ct) : Salih::Types::SmartPointers::Pointer<void>(ptr,ct) {} ;

template<typename T>
Salih::Types::SmartPointers::UniquePointer<void>::UniquePointer(T* ptr) : Salih::Types::SmartPointers::Pointer<void>(ptr) {} ;

Salih::Types::SmartPointers::UniquePointer<void>& Salih::Types::SmartPointers::UniquePointer<void>::operator=(std::nullptr_t x)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<void>::operator=(x) ;
	return *this ;	
}

Salih::Types::SmartPointers::UniquePointer<void>& Salih::Types::SmartPointers::UniquePointer<void>::operator()(void* ptr, std::size_t ct)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<void>::operator()(ptr, ct) ;
	return *this ;	
}

template<typename T>
Salih::Types::SmartPointers::UniquePointer<void>& Salih::Types::SmartPointers::UniquePointer<void>::operator=(T* ptr)
{
	this->reset() ;
	Salih::Types::SmartPointers::Pointer<void>::operator=(ptr) ;
	return *this ;	
}

Salih::Types::SmartPointers::UniquePointer<void>::UniquePointer(Salih::Types::SmartPointers::UniquePointer<void>&& ptr) : Salih::Types::SmartPointers::Pointer<void>( std::move(ptr) ) {} ; 
			
template<typename T>
Salih::Types::SmartPointers::UniquePointer<void>::UniquePointer(Salih::Types::SmartPointers::UniquePointer<T>&& ptr) : Salih::Types::SmartPointers::Pointer<void>( std::move(ptr) ) {} ;
			
Salih::Types::SmartPointers::UniquePointer<void>& Salih::Types::SmartPointers::UniquePointer<void>::operator=(Salih::Types::SmartPointers::UniquePointer<void>&& ptr)
{
	Salih::Types::SmartPointers::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
Salih::Types::SmartPointers::UniquePointer<void>& Salih::Types::SmartPointers::UniquePointer<void>::operator=(Salih::Types::SmartPointers::UniquePointer<T>&& ptr)
{
	Salih::Types::SmartPointers::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

void Salih::Types::SmartPointers::UniquePointer<void>::reset()
{
	if(this->pointer)
	{
		operator delete(this->pointer, this->bytes) ; 
		this->pointer = nullptr ;	
	}
}

Salih::Types::SmartPointers::UniquePointer<void>::~UniquePointer()
{
	if(this->pointer)
	{
		operator delete(this->pointer, this->bytes) ; 
	}
}

#endif
