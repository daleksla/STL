#ifndef _REGULAR_POINTERS_HPP
#define _REGULAR_POINTERS_HPP
#pragma once

#include <iostream>
#include <stdexcept>

namespace Salih::Types {
	
	template<class T>
	class Pointer {
		protected:
			T* pointer ;
			
		public:
			Pointer() ;	
			
			Pointer(std::nullptr_t) ;
			
			Pointer(T*) ;
			
			explicit Pointer(void*) ;
			
			Pointer& operator=(std::nullptr_t) ;
			
			Pointer& operator=(T*) ;
			
			Pointer(const Pointer&) ;
			
			explicit Pointer(const Pointer<void>&) ;
			
			Pointer& operator=(const Pointer&) ;
			
			Pointer(Pointer&&) ;
			
			explicit Pointer(Pointer<void>&&) ;
			
			Pointer& operator=(Pointer&&) ;
			
			T* operator->() ;
			
			T& operator*() ;
			
			operator bool() const ;
			
			bool operator!() const ;
			
			T* get() const ;
			
			virtual void reset() = 0 ;
			
			virtual ~Pointer() = 0 ;
		
			friend class Pointer<void> ;
	} ;
	
	template<class T>
	class SharedPointer : public Pointer<T> {
		private:
			std::size_t* count ;
			
		public:
			SharedPointer() ;
			
			SharedPointer(std::nullptr_t) ;
			
			SharedPointer(T*) ;
			
			explicit SharedPointer(void*) ;
			
			SharedPointer& operator=(std::nullptr_t) ;
			
			SharedPointer& operator=(T*) ;
		
			SharedPointer(const SharedPointer&) ;
			
			explicit SharedPointer(const SharedPointer<void>&) ;
			
			SharedPointer& operator=(const SharedPointer&) ;
			
			SharedPointer(SharedPointer&&) ;
			
			explicit SharedPointer(SharedPointer<void>&&) ;
			
			SharedPointer& operator=(SharedPointer&&) ;
			
			void reset() ;
			
			~SharedPointer() ;
			
			friend class SharedPointer<void> ;
	} ;
	
	template<class T>
	class UniquePointer : public Pointer<T> {
		public:
			UniquePointer() ;
			
			UniquePointer(std::nullptr_t) ;
			
			UniquePointer(T*) ;
			
			explicit UniquePointer(void*) ;
			
			UniquePointer& operator=(std::nullptr_t) ;
			
			UniquePointer& operator=(T*) ;
		
			UniquePointer(const UniquePointer&) = delete ;
			
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			UniquePointer(UniquePointer&&) ;
			
			explicit UniquePointer(UniquePointer<void>&&) ;
			
			UniquePointer& operator=(UniquePointer&&) ;
			
			void reset() ;
			
			~UniquePointer() ;
			
			friend class UniquePointer<void> ;
	} ;
	
}

#include "./_regular.tpp"

#endif
