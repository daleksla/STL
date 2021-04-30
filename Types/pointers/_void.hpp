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
			
			std::size_t bytes ;
			
		public:
			Pointer() ;	
			
			Pointer(std::nullptr_t) ;			
			
			Pointer(void*, std::size_t) ;	
			
			template<typename T>
			Pointer(T*) ;
			
			Pointer& operator=(std::nullptr_t) ;		
			
			Pointer& operator()(void*, std::size_t) ;				
			
			template<typename T>
			Pointer& operator=(T*) ;
			
			Pointer(const Pointer&) ;
			
			template<typename T>
			Pointer(const Pointer<T>&) ;	
			
			Pointer& operator=(const Pointer&) ;
			
			template<typename T>
			Pointer& operator=(const Pointer<T>&) ;	
			
			Pointer(Pointer&&) ;
			
			template<typename T>
			Pointer(Pointer<T>&&) ;	
			
			Pointer& operator=(Pointer&&) ;
			
			template<typename T>
			Pointer& operator=(Pointer<T>&&) ;	
			
			operator bool() const ;
			
			bool operator!() const ;	
			
			void* get() const ;
			
			virtual void reset() = 0 ;
			
			virtual ~Pointer() = 0 ;
			
			template<typename T>
			friend class Pointer ;
	} ;
	
	template<>
	class SharedPointer<void> : public Pointer<void> {
		private:
			int* count ;
			
		public:
			SharedPointer() ;
			
			SharedPointer(std::nullptr_t) ;

			SharedPointer(void*, std::size_t) ;
			
			template<typename T>
			SharedPointer(T*) ;	
			
			SharedPointer& operator=(std::nullptr_t) ;

			SharedPointer& operator()(void*, std::size_t) ;
			
			template<typename T>
			SharedPointer& operator=(T*) ;
			
			SharedPointer(const SharedPointer&) ;
			
			template<typename T>
			SharedPointer(const SharedPointer<T>&) ;	
			
			SharedPointer& operator=(const SharedPointer&) ;
			
			template<typename T>
			SharedPointer& operator=(const SharedPointer<T>&) ;	
			
			SharedPointer(SharedPointer&&) ;
			
			template<typename T>
			SharedPointer(SharedPointer<T>&&) ;	
			
			SharedPointer& operator=(SharedPointer&&) ;
			
			template<typename T>
			SharedPointer& operator=(SharedPointer<T>&&) ;	
			
			void reset() ;
			
			~SharedPointer() ;		
			
			template<typename T>
			friend class SharedPointer ;
	
	} ;
	
	template<>
	class UniquePointer<void> : Pointer<void> {
		public:
			UniquePointer() ;
			
			UniquePointer(std::nullptr_t) ;

			UniquePointer(void*, std::size_t) ;
			
			template<typename T>
			UniquePointer(T*) ;	
			
			UniquePointer& operator=(std::nullptr_t) ;

			UniquePointer& operator()(void*, std::size_t) ;
			
			template<typename T>
			UniquePointer& operator=(T*) ;
			
			UniquePointer(const UniquePointer&) = delete ;
			
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			UniquePointer(UniquePointer&&) ;
			
			template<typename T>
			UniquePointer(UniquePointer<T>&&) ;	
			
			UniquePointer& operator=(UniquePointer&&) ;
			
			template<typename T>
			UniquePointer& operator=(UniquePointer<T>&&) ;	
			
			void reset() ;
			
			~UniquePointer() ;		
			
			template<typename T>
			friend class UniquePointer ;			
	} ;
}

#include "./_void.tpp"

#endif
