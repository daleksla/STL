#ifndef UNIQUE_POINTER_TPP
#define UNIQUE_POINTER_TPP

/** @brief File containing unique pointer class definitions
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer() : salih::memory::Pointer<T>() {} ;

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(std::nullptr_t x) : salih::memory::Pointer<T>() {} ;

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(T* data) : salih::memory::Pointer<T>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T>::UniquePointer(void* data) : salih::memory::Pointer<T>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(T* data)
{
	this->reset() ;
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(std::nullptr_t data) 
{
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
	if(this->pointer) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer() : salih::memory::Pointer<T[]>() {} ;

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(std::nullptr_t x) : salih::memory::Pointer<T[]>() {} ;

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(T* data) : salih::memory::Pointer<T[]>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T[]>::UniquePointer(void* data) : salih::memory::Pointer<T[]>(data) {} ;

template<typename T>
salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(T* data)
{
	this->reset() ;
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(std::nullptr_t data) 
{
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
	if(this->pointer) 
	{
		delete[] this->pointer ; 
		this->pointer = nullptr ;
	}
}

salih::memory::UniquePointer<void>::UniquePointer() : salih::memory::Pointer<void>() {} ;

salih::memory::UniquePointer<void>::UniquePointer(std::nullptr_t x) : salih::memory::Pointer<void>(x) {} ;

template<typename T>
salih::memory::UniquePointer<void>::UniquePointer(T* ptr) : salih::memory::Pointer<void>(ptr) {} ;

salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(std::nullptr_t x)
{
	this->reset() ;
	salih::memory::Pointer<void>::operator=(x) ;
	return *this ;	
}

template<typename T>
salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(T* ptr)
{
	this->reset() ;
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
	}
}

salih::memory::UniquePointer<void>::~UniquePointer()
{
	if(this->pointer)
	{
		operator delete(this->pointer, this->bytes) ; 
	}
}

#endif
