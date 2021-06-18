#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include "base-pointer.hpp"

/** @brief Shared pointer class, which persists a dynamic resource until the last Shared pointer object is destroyed or reset
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih {
namespace memory {

	template<class T>
	class SharedPointer : public Pointer<T> {
		/** This class is the derived-class shared smart pointer implementation, which allows for the sharing and existence of a piece of memory till no shared pointer at all is making use of the pointed-to resource **/
		private:
			unsigned long* count ;
			
		public:
			/** Empty constructor, intialises shared smart pointer container 
			@return <initialised-object> **/
			SharedPointer() ;
			
			/** Regular constructor, intialises shared smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			SharedPointer(const decltype(nullptr)) ;
			
			/** Regular constructor, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/	
			SharedPointer(T*) ;
			
			/** Regular constructor, intialises shared smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/	
			explicit SharedPointer(void*) ;
			
			/** Regular assignment operator, assigns null pointer to shared smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/	
			SharedPointer& operator=(const decltype(nullptr)) ;
			
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
			explicit SharedPointer(const SharedPointer<void>&) ;
			
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
	class SharedPointer<T[]> : public Pointer<T[]> {
		/** This class is the derived-class shared smart pointer implementation, specialised for dynamically allocated arrays, which allows for the sharing and existence of a piece of memory till no shared pointer at all is making use of the pointed-to resource **/
		private:
			unsigned long* count ;
			
		public:
			/** Empty constructor, intialises shared smart pointer container 
			@return <initialised-object> **/
			SharedPointer() ;
			
			/** Regular constructor, intialises shared smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			SharedPointer(const decltype(nullptr)) ;
			
			/** Regular constructor, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/	
			SharedPointer(T*) ;
			
			/** Regular constructor, intialises shared smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/	
			explicit SharedPointer(void*) ;
			
			/** Regular assignment operator, assigns null pointer to shared smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/	
			SharedPointer& operator=(const decltype(nullptr)) ;
			
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
			explicit SharedPointer(const SharedPointer<void>&) ;
			
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
	
	template<>
	class SharedPointer<void> : public Pointer<void> {
		/** This class is the derived-class shared smart pointer implementation, specialised for void pointer usage, which allows for the sharing and existence of a piece of memory till no shared pointer at all is making use of the pointed-to resource **/
		private:
			unsigned long* count ;
			
		public:
			/** Empty constructor, intialises shared smart pointer container 
			@return <initialised-object> **/
			SharedPointer() ;
			
			/** Regular constructor, intialises shared smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			SharedPointer(const decltype(nullptr)) ;

			/** Regular constructor, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(T*) ;	
			
			SharedPointer(void*) = delete ;			
			
			/** Regular assignment operator, assigns null pointer to shared smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/	
			SharedPointer& operator=(const decltype(nullptr)) ;
			
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
			
			/** Pseudo-copy constructor, creates copy of a templated shared smart pointer
			@param a (l-value) templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(const SharedPointer<T[]>&) ;
			
			/** Copy constructor, creates copy (of base-properties) of a given shared smart pointer
			@param a (l-value) object reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(const SharedPointer&) ;
			
			/** Pseudo-copy constructor, creates copy of a given templated shared smart pointer
			@param a (l-value) templated object reference 
			@return reference to modified smart pointer **/
			template<typename T>
			SharedPointer& operator=(const SharedPointer<T>&) ;	
			
			/** Pseudo-copy constructor, creates copy of a given templated shared smart pointer
			@param a (l-value) templated object reference 
			@return reference to modified smart pointer **/
			template<typename T>
			SharedPointer& operator=(const SharedPointer<T[]>&) ;	
			
			/** Pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated base class reference 
			@return <initialised-object> **/
			SharedPointer(SharedPointer&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(SharedPointer<T>&&) ;	
			
			/** Pseudo-move constructor, takes ownership of a given templated shared smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer(SharedPointer<T[]>&&) ;
			
			/** Move assignment operator, takes ownership of a given shared smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			SharedPointer& operator=(SharedPointer&&) ;
			
			/** Pseudo-move assignment operator, takes ownership of a given templated shared smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer& operator=(SharedPointer<T>&&) ;	
			
			/** Pseudo-move assignment operator, takes ownership of a given templated shared smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			SharedPointer& operator=(SharedPointer<T[]>&&) ;
			
			/** reset method, to appropriately disengage from pointing at data **/
			void reset() ;
			
			/** Destructor, frees memory if appropriate and deletes objects **/					
			~SharedPointer() ;		
			
			template<typename T>
			friend class SharedPointer ;

	} ;
	
	/** This is the makeShared function, which creates a SharedPointer object of type T on the heap (using said object's empty / default initialisation)
	 * @return SharedPointer of type T **/
	template<class T>
	SharedPointer<T> makeShared() ;
	
	/** This is the makeShared function, which creates a SharedPointer object of type T on the heap, initialising the object using constructor determined by the parameters given
	 * @param Variadic template (arguments to pass in order to initialise object of type T)
	 * @return SharedPointer of type T **/
	template<class T, class... Args>
	SharedPointer<T> makeShared(Args&&...) ;
	
	/** This is the makeShared function, which creates a SharedPointer object of an array of T's (T[]) on the heap, 
	 * @param number of T's to allocate in contiguous block
	 * @return SharedPointer of type T[] **/
	template<class T>
	SharedPointer<T[]> makeShared(const unsigned long) ;
	
}
}

#include "shared-pointer.tpp"

#endif
