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
			
			T* operator->() ;
			
			T& operator*() ;
			
			T* get() const ;
			
			virtual void reset() = 0 ;
			
			virtual ~Pointer() = 0 ;
			
			friend ::std::ostream& ::Salih::operator<<(::std::ostream&, const Pointer&) ;
	} ;
	
	template<class T>
	class SharedPointer : public Pointer<T> {
		private:
			int* count ;
			
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
	} ;
	
}

#include "./_regular.tpp"

#endif
