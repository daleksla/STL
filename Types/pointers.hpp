#ifndef POINTERS_HPP
#define POINTERS_HPP
#pragma once

#include <iostream>
#include <stdexcept>

namespace Salih::Types {

	template<typename T>
	class Pointer ;
	
	template<typename T>
	class SharedPointer ;
	
	template<typename T>
	class UniquePointer ;
}

template<typename T>
std::ostream& operator<<(std::ostream&, const Salih::Types::Pointer<T>&) ;

namespace Salih::Types {
	
	template<class T>
	class Pointer {
		protected:
			T* pointer ;			
		public:
			Pointer() ;	
			
			Pointer(T) ;
			
			Pointer(T*) ;
			
			T* operator->() ;
			
			T& operator*() ;
			
			T* get() const ;
			
			virtual ~Pointer() = 0 ;
	} ;
	
	template<class T>
	class SharedPointer : public Pointer<T> {
		private:
			int* count ;
		public:
			SharedPointer() ;
		
			explicit SharedPointer(T) ;
			
			void operator=(T*) ;
		
			SharedPointer(const SharedPointer&) ;
			
			void operator=(const SharedPointer&) ;
			
			SharedPointer(SharedPointer&&) ;
			
			void operator=(SharedPointer&&) ;
			
			void reset() ;
			
			~SharedPointer() ;
	} ;
	
	template<class T>
	class UniquePointer : public Pointer<T> {
		public:
			UniquePointer() ;
		
			explicit UniquePointer(T) ;
			
			void operator=(T*) ;
		
			UniquePointer(const UniquePointer&) = delete ;
			
			void operator=(const UniquePointer&) = delete ;
			
			UniquePointer(UniquePointer&&) ;
			
			void operator=(UniquePointer&&) ;
			
			void reset() ;
			
			~UniquePointer() ;
	} ;
}

template<typename T>
Salih::Types::Pointer<T>::Pointer() 
{
	this->pointer = new T ;
}

template<typename T>
Salih::Types::Pointer<T>::Pointer(T data) 
{
	this->pointer = new T ;
	*(this->pointer) = data ;
}

template<typename T>
Salih::Types::Pointer<T>::Pointer(T* data)
{
	int x ;
        asm("movq %1, %%rax;"
            "cmpq %%rsp, %%rax;"
            "jbe Heap;"
            "movl $1,%0;"
            "jmp Done;"
            "Heap:"
            "movl $0,%0;"
            "Done:"
            : "=r" (x)
            : "r" (data)
            ) ;
	const char* errorMsg = "Cannot allocate stack pointer to heap" ;
	if(x) throw std::runtime_error(errorMsg) ;
	this->pointer = data ;
}

template<typename T>
T* Salih::Types::Pointer<T>::operator->()
{
	return this->pointer ;
}

template<typename T>
T& Salih::Types::Pointer<T>::operator*()
{
	return *(this->pointer) ;
}

template<typename T>
T* Salih::Types::Pointer<T>::get() const
{
	return this->pointer ;
}

template<typename T>
Salih::Types::Pointer<T>::~Pointer() {} ;

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer() : Salih::Types::Pointer<T>()
{
	this->count = new int ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(T data) : Salih::Types::Pointer<T>(data) 
{
	this->count = new int ;
	*(this->count) = 1 ;
}

template<typename T>
void Salih::Types::SharedPointer<T>::operator=(T* data)
{
	if(this->pointer != nullptr) delete this->pointer ;
	if(this->count != nullptr) delete this->count ;
	int x ;
        asm("movq %1, %%rax;"
            "cmpq %%rsp, %%rax;"
            "jbe Heap;"
            "movl $1,%0;"
            "jmp Done;"
            "Heap:"
            "movl $0,%0;"
            "Done:"
            : "=r" (x)
            : "r" (data)
            ) ;
	const char* errorMsg = "Cannot allocate stack pointer to heap" ;
	if(x) throw std::runtime_error(errorMsg) ;
	this->pointer = data ;
	this->count = new int ;
	*(this->count) = 1 ;
}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(const Salih::Types::SharedPointer<T>& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	*count = *(this->count) + 1 ;
}

template<typename T>
void Salih::Types::SharedPointer<T>::operator=(const Salih::Types::SharedPointer<T>& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	*count = *(this->count) + 1 ;
}

template<typename T>
Salih::Types::SharedPointer<T>::SharedPointer(Salih::Types::SharedPointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
void Salih::Types::SharedPointer<T>::operator=(Salih::Types::SharedPointer<T>&& ptr)
{
	this->reset() ;
	this->pointer = ptr.pointer ;
	this->count = ptr.count ;
	ptr.pointer = nullptr ;
	ptr.count = nullptr ;
}

template<typename T>
void Salih::Types::SharedPointer<T>::reset() 
{	
	if(*(this->count) <= 1)
	{
		delete (this->pointer) ;
		*count = *(this->count) - 1 ;
	}
	else {
		this->count = nullptr ;
	}
	this->pointer = nullptr ;
}

template<typename T>
Salih::Types::SharedPointer<T>::~SharedPointer()
{
	if(*(this->count) <= 1) 
	{
		delete this->pointer ; this->pointer = nullptr ;
		delete this->count ; this->count = nullptr ;
	}
	else {
		*count = *(this->count) - 1 ;
	}
}

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer() : Salih::Types::Pointer<T>() {} ;

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer(T data) : Salih::Types::Pointer<T>(data) {} ;

template<typename T>
void Salih::Types::UniquePointer<T>::operator=(T* data)
{
	this->reset() ;
	int x ;
        asm("movq %1, %%rax;"
            "cmpq %%rsp, %%rax;"
            "jbe Heap;"
            "movl $1,%0;"
            "jmp Done;"
            "Heap:"
            "movl $0,%0;"
            "Done:"
            : "=r" (x)
            : "r" (data)
            ) ;
	const char* errorMsg = "Cannot allocate stack pointer to heap" ;
	if(x) throw std::runtime_error(errorMsg) ;
	this->pointer = data ;
}

template<typename T>
Salih::Types::UniquePointer<T>::UniquePointer(Salih::Types::UniquePointer<T>&& ptr)
{
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
}

template<typename T>
void Salih::Types::UniquePointer<T>::operator=(Salih::Types::UniquePointer<T>&& ptr)
{
	if(this->pointer != nullptr) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
	this->pointer = ptr.pointer ;
	ptr.pointer = nullptr ;
}

template<typename T>
void Salih::Types::UniquePointer<T>::reset() 
{
	if(this->pointer != nullptr) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

template<typename T>
Salih::Types::UniquePointer<T>::~UniquePointer()
{
	if(this->pointer != nullptr) 
	{
		delete this->pointer ; 
		this->pointer = nullptr ;
	}
}

//helpful overloads

template<typename T>
std::ostream& operator<<(std::ostream& os, const Salih::Types::Pointer<T>& ptr)
{
	os << ptr.get() ;
	return os ;
}

#endif
