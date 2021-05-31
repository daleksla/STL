#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include "_basePointer.hpp"

/** @brief File containing shared pointer class declarations
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Types::SmartPointers {

	template<class T>
	class SharedPointer ;
	
	template<>
	class SharedPointer<void> ;

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
			
			/** Regular constructor, intialises shared smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/	
			SharedPointer(void*) ;
			
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
			
			/** Pseudo-copy constructor, creates copy of a given specialised void smart pointer
			@param a (l-value) base class reference 
			@return <initialised-object> **/	
			SharedPointer(const SharedPointer<void>&) ;
			
			/** Copy assignment operator, creates copy of a given shared smart pointer
			@param a (l-value) base class reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(const SharedPointer&) ;
			
			/** Move constructor, takes ownership of a given shared smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			SharedPointer(SharedPointer&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given specialised void shared smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			SharedPointer(SharedPointer<void>&&) ;
			
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
			
			SharedPointer(void*) = delete ;			
			
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
			
			SharedPointer& operator=(void*) = delete ;			
			
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
			
			/** Pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated base class reference 
			@return <initialised-object> **/
			SharedPointer(SharedPointer&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(SharedPointer<T>&&) ;	
			
			/** Move assignment operator, takes ownership of a given shared smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(SharedPointer&&) ;
			
			/** Pseudo-move assignment operator, takes ownership of a given templated shared smart pointer
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
	
}

#include "sharedPointer.tpp"

#endif
