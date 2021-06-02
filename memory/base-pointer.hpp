#ifndef BASE_POINTER_HPP
#define BASE_POINTER_HPP

/** @brief File containing base class declarations for all smart pointers
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih {
namespace memory {
	
	template<class T>
	class Pointer ;
	
	template<>
	class Pointer<void> ;	
	
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

			/** Regular constructor, intialises base-properties for smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/			
			Pointer(void*) ;

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

			/** Pseudo-copy constructor, creates copy (of base-properties) of a given specialised void smart pointer
			@param a (l-value) specialised void base class reference
			@return <initialised-object> **/			
			Pointer(const Pointer<void>&) ;
			
			/** Copy assignment operator, creates copy (of base-properties) of a given base-reference smart pointer
			@param a (l-value) base class reference 
			@return reference to modified smart pointer **/	
			Pointer& operator=(const Pointer&) ;
			
			/** Move constructor, takes ownership of a given base-reference smart pointer
			@param an r-value base class reference 
			@return <initialised-object> **/
			Pointer(Pointer&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given base-reference specialised void smart pointer
			@param an r-value specialised void base class reference 
			@return <initialised-object> **/
			Pointer(Pointer<void>&&) ;
			
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
			
			Pointer(void*) = delete ;
			
			/** Regular assignment operator, assigns null pointer to base-properties for smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/
			Pointer& operator=(std::nullptr_t) ;					
			
			/** Regular assignment operator, intialises base-properties for smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/
			template<typename T>
			Pointer& operator=(T*) ;
			
			Pointer& operator=(void*) = delete ;			
			
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
			
			/** Pseudo-move constructor, takes ownership of a given base-reference templated smart pointer
			@param an r-value templated base class reference 
			@return <initialised-object> **/
			template<typename T>
			Pointer(Pointer<T>&&) ;	
			
			/** Move assignment operator, takes ownership of a given base-reference smart pointer
			@param an r-value base class reference 
			@return reference to modified smart pointer **/
			Pointer& operator=(Pointer&&) ;
			
			/** Pseudo-move assignment operator, takes ownership of a given base-reference templated smart pointer
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
	
}
}

#include "base-pointer.tpp"

#endif
