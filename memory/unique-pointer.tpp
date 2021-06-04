#ifndef UNIQUE_POINTER_TPP
#define UNIQUE_POINTER_TPP

/** @brief File containing unique pointer class definitions
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>::UniquePointer() : salih::memory::Pointer<T>() {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>::UniquePointer(std::nullptr_t x) : salih::memory::Pointer<T>() {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>::UniquePointer(T* data) : salih::memory::Pointer<T>(data) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>::UniquePointer(void* data) : salih::memory::Pointer<T>(data) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(T* data)
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(std::nullptr_t data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>::UniquePointer(salih::memory::UniquePointer<T>&& ptr) : salih::memory::Pointer<T>( std::move(ptr) ) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>::UniquePointer(salih::memory::UniquePointer<void>&& ptr) : salih::memory::Pointer<T>( std::move(ptr) ) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>& salih::memory::UniquePointer<T>::operator=(salih::memory::UniquePointer<T>&& ptr)
{
	salih::memory::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR void salih::memory::UniquePointer<T>::reset() 
{
	if(this->pointer) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T>::~UniquePointer()
{
	this->reset() ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>::UniquePointer() : salih::memory::Pointer<T[]>() {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>::UniquePointer(std::nullptr_t x) : salih::memory::Pointer<T[]>() {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>::UniquePointer(T* data) : salih::memory::Pointer<T[]>(data) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>::UniquePointer(void* data) : salih::memory::Pointer<T[]>(data) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(T* data)
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(std::nullptr_t data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>::UniquePointer(salih::memory::UniquePointer<T[]>&& ptr) : salih::memory::Pointer<T[]>( std::move(ptr) ) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>::UniquePointer(salih::memory::UniquePointer<void>&& ptr) : salih::memory::Pointer<T[]>( std::move(ptr) ) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>& salih::memory::UniquePointer<T[]>::operator=(salih::memory::UniquePointer<T[]>&& ptr)
{
	salih::memory::Pointer<T[]>::operator=( std::move(ptr) ) ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR void salih::memory::UniquePointer<T[]>::reset() 
{
	if(this->pointer) 
	{
		delete[] this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<T[]>::~UniquePointer()
{
	this->reset() ;
}

_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>::UniquePointer() : salih::memory::Pointer<void>() {} ;

_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>::UniquePointer(std::nullptr_t x) : salih::memory::Pointer<void>(x) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>::UniquePointer(T* ptr) : salih::memory::Pointer<void>(ptr) {} ;

_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(std::nullptr_t x)
{
	salih::memory::Pointer<void>::operator=(x) ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(T* ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	return *this ;	
}

_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>::UniquePointer(salih::memory::UniquePointer<void>&& ptr) : salih::memory::Pointer<void>( std::move(ptr) ) {} ; 
			
template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>::UniquePointer(salih::memory::UniquePointer<T>&& ptr) : salih::memory::Pointer<void>( std::move(ptr) ) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>::UniquePointer(salih::memory::UniquePointer<T[]>&& ptr) : salih::memory::Pointer<void>( std::move(ptr) ) {} ;
			
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(salih::memory::UniquePointer<void>&& ptr)
{
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(salih::memory::UniquePointer<T>&& ptr)
{
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>& salih::memory::UniquePointer<void>::operator=(salih::memory::UniquePointer<T[]>&& ptr)
{
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR void salih::memory::UniquePointer<void>::reset()
{
	if(this->pointer)
	{
		operator delete(this->pointer, this->bytes) ; 
		this->pointer = nullptr ;
		this->bytes = 0 ;	
	}
}

_GLIBCXX20_CONSTEXPR salih::memory::UniquePointer<void>::~UniquePointer()
{
	this->reset() ;
}

template<class T>
salih::memory::UniquePointer<T> salih::memory::makeUnique()
{
	return salih::memory::UniquePointer<T>(new T) ;
}
	
template<class T, class... Args>
salih::memory::UniquePointer<T> salih::memory::makeUnique(Args&&... args)
{
	return salih::memory::UniquePointer<T>(new T(args...)) ;
}
	
template<class T>
salih::memory::UniquePointer<T[]> salih::memory::makeUnique(const std::size_t sz)
{
	return salih::memory::UniquePointer<T[]>(new T[sz]) ;
}

#endif
