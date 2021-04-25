#ifndef _VOID_POINTERS_HPP
#define _VOID_POINTERS_HPP
#pragma once

#include <iostream>
#include <stdexcept>

namespace Salih::Types {
	
	template<>
	class Pointer<void> {
		protected:
			void* pointer ;
			
		public:
			Pointer() ;	
			
			Pointer(std::nullptr_t) ;			
			
			Pointer(void*) ;
			
			void* get() const ;
			
			virtual void reset() = 0 ;
			
			virtual ~Pointer() = 0 ;
			
			template<typename T>
			friend ::std::ostream& ::Salih::operator<<(::std::ostream&, const Pointer<T>&) ;
	} ;
	
	template<>
	class SharedPointer<void> : public Pointer<void> {
		private:
			int* count ;
			
		public:
			SharedPointer() ;
			
			SharedPointer(std::nullptr_t) ;			
			
			SharedPointer(void*) ;
			
			SharedPointer& operator=(std::nullptr_t) ;
			
			SharedPointer& operator=(void*) ;
		
			SharedPointer(const SharedPointer&) ;
			
			SharedPointer& operator=(const SharedPointer&) ;
			
			SharedPointer(SharedPointer&&) ;
			
			SharedPointer& operator=(SharedPointer&&) ;
			
			void reset() ;
			
			~SharedPointer() ;
	} ;
	
	template<>
	class UniquePointer<void> : public Pointer<void> {
		public:
			UniquePointer() ;
			
			UniquePointer(std::nullptr_t) ;		
			
			UniquePointer(void*) ;
			
			UniquePointer& operator=(std::nullptr_t) ;
			
			UniquePointer& operator=(void*) ;
		
			UniquePointer(const UniquePointer&) = delete ;
			
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			UniquePointer(UniquePointer&&) ;
			
			UniquePointer& operator=(UniquePointer&&) ;
			
			void reset() ;
			
			~UniquePointer() ;
	} ;
	
}

#include "./_void.tpp"

#endif
