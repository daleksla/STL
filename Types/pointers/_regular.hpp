#ifndef _REGULAR_POINTERS_HPP
#define _REGULAR_POINTERS_HPP
#pragma once

#include <iostream>
#include <stdexcept>

/** @brief General smart pointer file, for every implementation of T (ie. all types except void)
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Types {
	
	template<class T>
	class Pointer {
		/** This class is the base-class general smart pointer implementation, serving as a raw, heap pointer wrapper **/
		protected:
			T* pointer ;
			
		public:
			/** Empty constructor, intialises base-properties for smart pointer container 
			@return <initialised-object> **/
			Pointer() ;	
			
			/** Regular constructor, intialises base-properties for smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			Pointer(std::nullptr_t) ;

			/** Regular constructor, intialises base-properties for smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/			
			Pointer(T*) ;

			/** Explicit constructor, intialises base-properties for smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/			
			explicit Pointer(void*) ;

			/** Regular assignment operator, assigns null pointer to base-properties for smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/	
			Pointer& operator=(std::nullptr_t) ;

			/** Regular assignment operator, assigns type-T pointer to base-properties for smart pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/	
			Pointer& operator=(T*) ;
			
			/** Copy constructor, creates copy (of base-properties) of a given base-reference smart pointer
			@param a (l-value) base class reference 
			@return <initialised-object> **/
			Pointer(const Pointer&) ;

			/** Explicit pseudo-copy constructor, creates copy (of base-properties) of a given specialised void smart pointer
			@param a (l-value) specialised void base class reference
			@return <initialised-object> **/			
			explicit Pointer(const Pointer<void>&) ;
			
			/** Copy assignment operator, creates copy (of base-properties) of a given base-reference smart pointer
			@param a (l-value) base class reference 
			@return reference to modified smart pointer **/	
			Pointer& operator=(const Pointer&) ;
			
			/** Move constructor, takes ownership of a given base-reference smart pointer
			@param an r-value base class reference 
			@return <initialised-object> **/
			Pointer(Pointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given base-reference specialised void smart pointer
			@param an r-value specialised void base class reference 
			@return <initialised-object> **/
			explicit Pointer(Pointer<void>&&) ;
			
			/** Move assignment operator, takes ownership of a given base-reference smart pointer
			@param an r-value base class reference 
			@return reference to modified smart pointer **/	
			Pointer& operator=(Pointer&&) ;
			
			/** Arrow operator, allows for object / sub-object access directly / without full dereferencing
			@return raw-pointer to access **/
			T* operator->() ;

			/** Dereferencing operator
			@return reference to object behind pointer **/			
			T& operator*() ;
			
			/** bool operator (tests 'truth' of object)
			@return boolean (True if pointer actually points to something valid (ie not NULL address), False otherwise) **/
			operator bool() const ;
			
			/** bool operator (tests 'falsehood' of object)
			@return boolean (True if pointer does not point to something valid (ie NULL address), False otherwise) **/
			bool operator!() const ;
			
			/** get method to return raw pointer (of data) behind wrapped
			@return raw pointer (of data) **/
			T* get() const ;
			
			/** (virtual) reset method, placeholder to appropriately disengage from pointing at data **/
			virtual void reset() = 0 ;
			
			/** Virtual destructor, needed but doesn't do anything per se **/					
			virtual ~Pointer() = 0 ;
		
			friend class Pointer<void> ;
	} ;
	
	template<class T>
	class SharedPointer : public Pointer<T> {
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
			
			/** Regular constructor, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/	
			SharedPointer(T*) ;
			
			/** Explicit constructor, intialises shared smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/	
			explicit SharedPointer(void*) ;
			
			/** Regular assignment operator, assigns null pointer to shared smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/	
			SharedPointer& operator=(std::nullptr_t) ;
			
			/** Regular assignment operator, assigns null pointer to shared smart pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/	
			SharedPointer& operator=(T*) ;
		
			/** Copy constructor, creates copy of a given shared smart pointer
			@param a (l-value) base class reference 
			@return <initialised-object> **/
			SharedPointer(const SharedPointer&) ;
			
			/** Explicit pseudo-copy constructor, creates copy of a given specialised void smart pointer
			@param a (l-value) base class reference 
			@return <initialised-object> **/	
			explicit SharedPointer(const SharedPointer<void>&) ;
			
			/** Copy assignment operator, creates copy of a given shared smart pointer
			@param a (l-value) base class reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(const SharedPointer&) ;
			
			/** Move constructor, takes ownership of a given shared smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			SharedPointer(SharedPointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given specialised void shared smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			explicit SharedPointer(SharedPointer<void>&&) ;
			
			/** Move assignment operator, takes ownership of a given shared smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(SharedPointer&&) ;
			
			/** reset method, to appropriately disengage from pointing at data **/
			void reset() ;
			
			/** Destructor, frees memory if appropriate and deletes objects **/					
			~SharedPointer() ;
			
			friend class SharedPointer<void> ;
	} ;
	
	template<class T>
	class UniquePointer : public Pointer<T> {
		/** This class is the derived-class unique smart pointer implementation, whereby access to a resource is restricted to only one variable / existing object and upon it's deletion, the memory resource expires **/
		public:
			/** Empty constructor, intialises unique smart pointer container 
			@return <initialised-object> **/
			UniquePointer() ;
			
			/** Regular constructor, intialises unique smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			UniquePointer(std::nullptr_t) ;
			
			/** Regular constructor, intialises unique smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/	
			UniquePointer(T*) ;
			
			/** Explicit constructor, intialises unique smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/
			explicit UniquePointer(void*) ;
			
			/** Regular assignment operator, assigns null pointer to unique smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/
			UniquePointer& operator=(std::nullptr_t) ;
			
			/** Regular assignment operator, assigns null pointer to unique smart pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/	
			UniquePointer& operator=(T*) ;
		
			/** Removed copy constructor **/
			UniquePointer(const UniquePointer&) = delete ;
			
			/** Removed copy assignment operator **/
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			/** Move constructor, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			UniquePointer(UniquePointer&&) ;
			
			/** Explicit pseudo-move constructor, takes ownership of a given specialised void unique smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			explicit UniquePointer(UniquePointer<void>&&) ;
			
			/** Move assignment operator, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			UniquePointer& operator=(UniquePointer&&) ;
			
			/** reset method, to appropriately disengage from pointing at data **/
			void reset() ;
			
			/** Destructor, frees memory and deletes objects **/					
			~UniquePointer() ;
			
			friend class UniquePointer<void> ;
	} ;
	
}

#include "./_regular.tpp"

#endif
