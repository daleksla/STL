#ifndef SHARED_POINTER_TPP
#define SHARED_POINTER_TPP

/** @brief File containing shared pointer class definitions
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer() : salih::memory::Pointer<T>(), count(nullptr) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer(std::nullptr_t x) : salih::memory::Pointer<T>(x), count(nullptr) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer(T* data) : salih::memory::Pointer<T>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer(void* data) : salih::memory::Pointer<T>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(T* data)
{
	salih::memory::Pointer<T>::operator=(data) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(std::nullptr_t data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer(const salih::memory::SharedPointer<T>& ptr) : salih::memory::Pointer<T>(ptr), count(ptr.count)
{
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer(const salih::memory::SharedPointer<void>& ptr) : salih::memory::Pointer<T>(ptr), count(ptr.count)
{
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(const salih::memory::SharedPointer<T>& ptr)
{
	salih::memory::Pointer<T>::operator=(ptr) ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer(salih::memory::SharedPointer<T>&& ptr) : count(ptr.count), salih::memory::Pointer<T>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::SharedPointer(salih::memory::SharedPointer<void>&& ptr) : count(ptr.count), salih::memory::Pointer<T>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>& salih::memory::SharedPointer<T>::operator=(salih::memory::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR void salih::memory::SharedPointer<T>::reset() 
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
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T>::~SharedPointer()
{
	this->reset() ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer() : salih::memory::Pointer<T[]>(), count(nullptr) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer(std::nullptr_t x) : salih::memory::Pointer<T>(x), count(nullptr) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer(T* data) : salih::memory::Pointer<T[]>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer(void* data) : salih::memory::Pointer<T[]>(data)
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(T* data)
{
	salih::memory::Pointer<T[]>::operator=(data) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(std::nullptr_t data) 
{
	salih::memory::Pointer<T>::operator=(data) ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer(const salih::memory::SharedPointer<T[]>& ptr) : salih::memory::Pointer<T[]>(ptr), count(ptr.count)
{
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer(const salih::memory::SharedPointer<void>& ptr) : salih::memory::Pointer<T[]>(ptr)
{
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(const salih::memory::SharedPointer<T[]>& ptr)
{
	salih::memory::Pointer<T[]>::operator=(ptr) ;
	this->count = ptr.count ;
	if(this->count != nullptr) *count = *(this->count) + 1 ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer(salih::memory::SharedPointer<T[]>&& ptr) : count(ptr.count), salih::memory::Pointer<T[]>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::SharedPointer(salih::memory::SharedPointer<void>&& ptr) : count(ptr.count), salih::memory::Pointer<T[]>( std::move(ptr) )
{
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>& salih::memory::SharedPointer<T[]>::operator=(salih::memory::SharedPointer<T[]>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<T>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR void salih::memory::SharedPointer<T[]>::reset() 
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
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<T[]>::~SharedPointer()
{
	this->reset() ;
}

_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer() : salih::memory::Pointer<void>(), count(nullptr) {} ;

_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(std::nullptr_t x) : salih::memory::Pointer<void>(x), count(nullptr) {} ;

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(T* ptr) : salih::memory::Pointer<void>(ptr) 
{
	this->count = new std::size_t ;
	*(this->count) = 1 ;
}

_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(std::nullptr_t x)
{
	salih::memory::Pointer<void>::operator=(x) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(T* ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = new std::size_t ; *(this->count) = 1 ;
	return *this ;	
}

_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(const salih::memory::SharedPointer<void>& ptr) : salih::memory::Pointer<void>(ptr) 
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(const salih::memory::SharedPointer<T>& ptr) : salih::memory::Pointer<void>(ptr)
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(const salih::memory::SharedPointer<T[]>& ptr) : salih::memory::Pointer<void>(ptr)
{
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;	
}
			
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(const salih::memory::SharedPointer<void>& ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}
			
template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(const salih::memory::SharedPointer<T>& ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(const salih::memory::SharedPointer<T[]>& ptr)
{
	salih::memory::Pointer<void>::operator=(ptr) ;
	this->count = ptr.count ;
	*(this->count) = *(ptr.count) + 1 ;
	return *this ;	
}

_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<void>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) ) 
{
	ptr.count = nullptr ;
} 
			
template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<T>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) )
{
	ptr.count = nullptr ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::SharedPointer(salih::memory::SharedPointer<T[]>&& ptr) : count(ptr.count), salih::memory::Pointer<void>( std::move(ptr) )
{
	ptr.count = nullptr ;
}
			
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(salih::memory::SharedPointer<void>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}
			
template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(salih::memory::SharedPointer<T>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>& salih::memory::SharedPointer<void>::operator=(salih::memory::SharedPointer<T[]>&& ptr)
{
	this->count = ptr.count ;
	ptr.count = nullptr ;
	salih::memory::Pointer<void>::operator=( std::move(ptr) ) ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR void salih::memory::SharedPointer<void>::reset()
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

_GLIBCXX20_CONSTEXPR salih::memory::SharedPointer<void>::~SharedPointer()
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
salih::memory::SharedPointer<T[]> salih::memory::makeShared(const std::size_t sz)
{
	return salih::memory::SharedPointer<T[]>(new T[sz]) ;
}

#endif
