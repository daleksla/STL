#ifndef _VOID_POINTERS_HPP
#define _VOID_POINTERS_HPP
#pragma once

#include <iostream>
#include <stdexcept>

/** @brief Specialised smart pointer file, for void-type smart pointers
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Types {
	
	template<>
	class Pointer<void> {
		/** This class is the base-class void-specialised smart pointer implementation, serving as a raw, heap pointer wrapper **/
		protected:
			void* pointer ;
			
			std::size_t bytes ;
			
		public:
			/** Empty constructor, intialises base-properties for smart pointer container 
			@return <initialised-object> **/
			Pointer() ;	
			
			/** Regular constructor, intialises base-properties for smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			Pointer(std::nullptr_t) ;			
			
			/** Regular constructor, intialises base-properties for smart pointer container to point at void-type pointer
			@param void* (raw void pointer), size_t (size of data-type which pointer is pointing to)
			@return <initialised-object> **/
			Pointer(void*, std::size_t) ;	
			
			/** Regular constructor, intialises base-properties for smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/
			template<typename T>
			Pointer(T*) ;
			
			/** Regular assignment operator, assigns null pointer to base-properties for smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/
			Pointer& operator=(std::nullptr_t) ;		
			
			/** Regular pseudo-assignment operator, intialises base-properties for smart pointer container to void pointer
			@param void* (raw void pointer), size_t (size of data-type which pointer is pointing to)
			@return reference to modified smart pointer **/
			Pointer& operator()(void*, std::size_t) ;				
			
			/** Regular assignment operator, intialises base-properties for smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/
			template<typename T>
			Pointer& operator=(T*) ;
			
			/** Copy constructor, creates copy (of base-properties) of a given base-reference smart pointer
			@param a (l-value) base class reference 
			@return <initialised-object> **/
			Pointer(const Pointer&) ;
			
			/** Pseudo-copy constructor, creates copy (of base-properties) of a templated smart pointer
			@param a (l-value) templated base class version reference 
			@return <initialised-object> **/
			template<typename T>
			Pointer(const Pointer<T>&) ;	
			
			/** Copy constructor, creates copy (of base-properties) of a given base-reference smart pointer
			@param a (l-value) base class reference 
			@return reference to modified smart pointer **/
			Pointer& operator=(const Pointer&) ;

			/** Pseudo-copy constructor, creates copy (of base-properties) of a given base-reference templated smart pointer
			@param a (l-value) templated base class version reference 
			@return reference to modified smart pointer **/	
			template<typename T>
			Pointer& operator=(const Pointer<T>&) ;	
			
			/** Move constructor, takes ownership of a given base-reference smart pointer
			@param an r-value base class reference 
			@return <initialised-object> **/
			Pointer(Pointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given base-reference templated smart pointer
			@param an r-value templated base class reference 
			@return <initialised-object> **/
			template<typename T>
			Pointer(Pointer<T>&&) ;	
			
			/** Move assignment operator, takes ownership of a given base-reference smart pointer
			@param an r-value base class reference 
			@return reference to modified smart pointer **/
			Pointer& operator=(Pointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given base-reference templated smart pointer
			@param an r-value templated base class reference 
			@return <initialised-object> **/
			template<typename T>
			Pointer& operator=(Pointer<T>&&) ;	
			
			/** bool operator (tests 'truth' of object)
			@return boolean (True if pointer actually points to something valid (ie not NULL address), False otherwise) **/			
			operator bool() const ;
			
			/** bool operator (tests 'falsehood' of object)
			@return boolean (True if pointer does not point to something valid (ie NULL address), False otherwise) **/
			bool operator!() const ;	
			
			/** get method to return raw pointer (of data) behind wrapped
			@return raw pointer (of data) **/
			void* get() const ;
			
			/** (virtual) reset method, placeholder to appropriately disengage from pointing at data **/
			virtual void reset() = 0 ;
			
			/** Virtual destructor, needed but doesn't do anything per se **/					
			virtual ~Pointer() = 0 ;
			
			template<typename T>
			friend class Pointer ;
	} ;
	
	template<>
	class SharedPointer<void> : public Pointer<void> {
		/** This class is the derived-class shared smart pointer implementation, which allows for the sharing and existence of a piece of memory till no shared pointer at all is making use of the pointed-to resource **/
		private:
			std::size_t* count ;
			
		public:
			/** Empty constructor, intialises shared smart pointer container 
			@return <initialised-object> **/
			SharedPointer() ;
			
			/** Regular constructor, intialises shared smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			SharedPointer(std::nullptr_t) ;

			/** Regular constructor, intialises shared smart pointer container to point at void-type pointer
			@param void* (raw void pointer), size_t (size of data-type which pointer is pointing to)
			@return <initialised-object> **/
			SharedPointer(void*, std::size_t) ;
			
			/** Regular constructor, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(T*) ;	
			
			/** Regular assignment operator, assigns null pointer to shared smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/	
			SharedPointer& operator=(std::nullptr_t) ;

			/** Regular pseudo-assignment operator, intialises shared smart pointer container to void pointer
			@param void* (raw void pointer), size_t (size of data-type which pointer is pointing to)
			@return reference to modified smart pointer **/
			SharedPointer& operator()(void*, std::size_t) ;
			
			/** Regular assignment operator, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/
			template<typename T>
			SharedPointer& operator=(T*) ;
			
			/** Copy constructor, creates copy of a given shared smart pointer
			@param a (l-value) object reference 
			@return <initialised-object> **/
			SharedPointer(const SharedPointer&) ;
			
			/** Pseudo-copy constructor, creates copy of a templated shared smart pointer
			@param a (l-value) templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(const SharedPointer<T>&) ;	
			
			/** Copy constructor, creates copy (of base-properties) of a given shared smart pointer
			@param a (l-value) object reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(const SharedPointer&) ;
			
			/** Pseudo-copy constructor, creates copy of a given templated shared smart pointer
			@param a (l-value) templated object reference 
			@return reference to modified smart pointer **/
			template<typename T>
			SharedPointer& operator=(const SharedPointer<T>&) ;	
			
			/** Explicit pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated base class reference 
			@return <initialised-object> **/
			SharedPointer(SharedPointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(SharedPointer<T>&&) ;	
			
			/** Move assignment operator, takes ownership of a given shared smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(SharedPointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer& operator=(SharedPointer<T>&&) ;	
			
			/** reset method, to appropriately disengage from pointing at data **/
			void reset() ;
			
			/** Destructor, frees memory if appropriate and deletes objects **/					
			~SharedPointer() ;		
			
			template<typename T>
			friend class SharedPointer ;
	
	} ;
	
	template<>
	class UniquePointer<void> : Pointer<void> {
		/** This class is the derived-class unique smart pointer implementation, whereby access to a resource is restricted to only one variable / existing object and upon it's deletion, the memory resource expires **/
		public:
			/** Empty constructor, intialises unique smart pointer container 
			@return <initialised-object> **/
			UniquePointer() ;
			
			/** Regular constructor, intialises unique smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			UniquePointer(std::nullptr_t) ;

			/** Regular constructor, intialises unique smart pointer container to point at void-type pointer
			@param void* (raw void pointer), size_t (size of data-type which pointer is pointing to)
			@return <initialised-object> **/
			UniquePointer(void*, std::size_t) ;
			
			/** Regular constructor, intialises unique smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/
			template<typename T>
			UniquePointer(T*) ;	
			
			/** Regular assignment operator, assigns null pointer to unique smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/
			UniquePointer& operator=(std::nullptr_t) ;

			/** Regular pseudo-assignment operator, intialises unique smart pointer container to void pointer
			@param void* (raw void pointer), size_t (size of data-type which pointer is pointing to)
			@return reference to modified smart pointer **/
			UniquePointer& operator()(void*, std::size_t) ;
			
			/** Regular assignment operator, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/
			template<typename T>
			UniquePointer& operator=(T*) ;
			
			/** Removed copy constructor **/
			UniquePointer(const UniquePointer&) = delete ;
			
			/** Removed copy assignment operator **/
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given templated unique smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			UniquePointer(UniquePointer&&) ;
			
			/** Move assignment operator, takes ownership of a given shared unique pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			template<typename T>
			UniquePointer(UniquePointer<T>&&) ;	
			
			/** Move assignment operator, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			UniquePointer& operator=(UniquePointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given templated unique smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			UniquePointer& operator=(UniquePointer<T>&&) ;	
			
			/** reset method, to appropriately disengage from pointing at data **/
			void reset() ;
			
			/** Destructor, frees memory if appropriate and deletes objects **/					
			~UniquePointer() ;		
			
			template<typename T>
			friend class UniquePointer ;			
	} ;
}

#include "./_void.tpp"

#endif
