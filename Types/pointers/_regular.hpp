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
			
			Pointer& operator=(std::nullptr_t) ;
			
			Pointer& operator=(T*) ;
			
			Pointer(const Pointer&) ;
			
			Pointer& operator=(const Pointer&) ;
			
			Pointer(Pointer&&) ;
			
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
			
			SharedPointer& operator=(std::nullptr_t) ;
			
			SharedPointer& operator=(T*) ;
		
			SharedPointer(const SharedPointer&) ;
			
			SharedPointer& operator=(const SharedPointer&) ;
			
			SharedPointer(SharedPointer&&) ;
			
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
			
			UniquePointer& operator=(std::nullptr_t) ;
			
			UniquePointer& operator=(T*) ;
		
			UniquePointer(const UniquePointer&) = delete ;
			
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			UniquePointer(UniquePointer&&) ;
			
			UniquePointer& operator=(UniquePointer&&) ;
			
			void reset() ;
			
			~UniquePointer() ;
			
			friend class UniquePointer<void> ;
	} ;
	
}

#include "./_regular.tpp"

#endif
