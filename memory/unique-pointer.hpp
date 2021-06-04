#ifndef UNIQUE_POINTER_HPP
#define UNIQUE_POINTER_HPP

#include "base-pointer.hpp"

/** @brief File containing unique pointer class declarations
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih {
namespace memory {

	template<class T>
	class UniquePointer ;
	
	template<class T>
	class UniquePointer<T[]> ;
	
	template<>
	class UniquePointer<void> ;	

	/** This is the makeUnique function, which creates a UniquePointer object of type T on the heap (using said object's empty / default initialisation)
	 * @return UniquePointer of type T **/
	template<class T>
	UniquePointer<T> makeUnique() ;
	
	/** This is the makeUnique function, which creates a UniquePointer object of type T on the heap, initialising the object using constructor determined by the parameters given
	 * @param Variadic template (arguments to pass in order to initialise object of type T)
	 * @return UniquePointer of type T **/
	template<class T, class... Args>
	UniquePointer<T> makeUnique(Args&&...) ;
	
	/** This is the makeUnique function, which creates a UniquePointer object of an array of T's (T[]) on the heap, 
	 * @param number of T's to allocate in contiguous block
	 * @return UniquePointer of type T[] **/
	template<class T>
	UniquePointer<T[]> makeUnique(const std::size_t) ;

	template<class T>
	class UniquePointer : public Pointer<T> {
		/** This class is the derived-class unique smart pointer implementation, whereby access to a resource is restricted to only one variable / existing object and upon it's deletion, the memory resource expires **/
		public:
			/** Empty constructor, intialises unique smart pointer container 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer() ;
			
			/** Regular constructor, intialises unique smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer(std::nullptr_t) ;
			
			/** Regular assignment operator, assigns null pointer to unique smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(std::nullptr_t) ;
			
			/** Regular constructor, intialises unique smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/	
			_GLIBCXX20_CONSTEXPR UniquePointer(T*) ;
	
			/** Regular assignment operator, assigns null pointer to unique smart pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/	
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(T*) ;
			
			/** Regular constructor, intialises unique smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/
			explicit _GLIBCXX20_CONSTEXPR UniquePointer(void*) ;
	
			/** Removed copy constructor **/
			UniquePointer(const UniquePointer&) = delete ;
			
			/** Removed copy assignment operator **/
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			/** Move constructor, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer(UniquePointer&&) ;
			
			/** Move assignment operator, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(UniquePointer&&) ;
	
			/** Pseudo-move constructor, takes ownership of a given specialised void unique smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			explicit _GLIBCXX20_CONSTEXPR UniquePointer(UniquePointer<void>&&) ;
			
			/** reset method, to appropriately disengage from pointing at data **/
			_GLIBCXX20_CONSTEXPR void reset() ;
			
			/** Destructor, frees memory and deletes objects **/					
			_GLIBCXX20_CONSTEXPR ~UniquePointer() ;
			
			friend class UniquePointer<void> ;
			
	} ;
	
	template<class T>
	class UniquePointer<T[]> : public Pointer<T[]> {
		/** This class is the derived-class unique smart pointer implementation, specialised for dynamically sized arrays, whereby access to a resource is restricted to only one variable / existing object and upon it's deletion, the memory resource expires **/
		public:
			/** Empty constructor, intialises unique smart pointer container 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer() ;
			
			/** Regular constructor, intialises unique smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer(std::nullptr_t) ;
			
			/** Regular assignment operator, assigns null pointer to unique smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(std::nullptr_t) ;	
		
			/** Regular constructor, intialises unique smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/	
			_GLIBCXX20_CONSTEXPR UniquePointer(T*) ;
			
			/** Regular assignment operator, assigns T pointer to unique smart pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/	
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(T*) ;
			
			/** Regular constructor, intialises unique smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/
			explicit _GLIBCXX20_CONSTEXPR UniquePointer(void*) ;
		
			/** Removed copy constructor **/
			UniquePointer(const UniquePointer&) = delete ;
			
			/** Removed copy assignment operator **/
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			/** Move constructor, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer(UniquePointer&&) ;
			
			/** Move assignment operator, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(UniquePointer&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given specialised void unique smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			explicit _GLIBCXX20_CONSTEXPR UniquePointer(UniquePointer<void>&&) ;
			
			/** reset method, to appropriately disengage from pointing at data **/
			_GLIBCXX20_CONSTEXPR void reset() ;
			
			/** Destructor, frees memory and deletes objects **/					
			_GLIBCXX20_CONSTEXPR ~UniquePointer() ;
			
			friend class UniquePointer<void> ;
			
	} ;
	
	template<>
	class UniquePointer<void> : public Pointer<void> {
		/** This class is the derived-class unique smart pointer implementation, specialised for void pointer usage, whereby access to a resource is restricted to only one variable / existing object and upon it's deletion, the memory resource expires **/
		public:
			/** Empty constructor, intialises unique smart pointer container 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer() ;
			
			/** Regular constructor, intialises unique smart pointer container
			@param nullptr_t (special type indicating NULL)
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer(std::nullptr_t) ;

			/** Regular assignment operator, assigns null pointer to unique smart pointer
			@param nullptr_t (special type indicating NULL)
			@return reference to modified smart pointer **/
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(std::nullptr_t) ;
			
			/** Regular constructor, intialises unique smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return <initialised-object> **/
			template<typename T>
			_GLIBCXX20_CONSTEXPR UniquePointer(T*) ;	
			
			/** Regular assignment operator, intialises shared smart pointer container to point at T-type pointer
			@param T* (raw pointer to object of type T)
			@return reference to modified smart pointer **/
			template<typename T>
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(T*) ;
			
			UniquePointer(void*) = delete ;			
			
			UniquePointer& operator=(void*) = delete ;			
			
			/** Removed copy constructor **/
			UniquePointer(const UniquePointer&) = delete ;
			
			/** Removed copy assignment operator **/
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			/** Pseudo-move constructor, takes ownership of a given templated unique smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR UniquePointer(UniquePointer&&) ;
	
			/** Move assignment operator, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(UniquePointer&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given shared unique pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			template<typename T>
			_GLIBCXX20_CONSTEXPR UniquePointer(UniquePointer<T>&&) ;	

			/** Pseudo-move assignment operator, takes ownership of a given templated unique smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(UniquePointer<T>&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given shared unique pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			template<typename T>
			_GLIBCXX20_CONSTEXPR UniquePointer(UniquePointer<T[]>&&) ;	
			
			/** Pseudo-move assignment operator, takes ownership of a given templated unique smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			template<typename T>
			_GLIBCXX20_CONSTEXPR UniquePointer& operator=(UniquePointer<T[]>&&) ;	
			
			/** reset method, to appropriately disengage from pointing at data **/
			_GLIBCXX20_CONSTEXPR void reset() ;
			
			/** Destructor, frees memory if appropriate and deletes objects **/					
			_GLIBCXX20_CONSTEXPR ~UniquePointer() ;		
			
			template<typename T>
			friend class UniquePointer ;		
					
	} ;

}
}

#include "unique-pointer.tpp"

#endif
