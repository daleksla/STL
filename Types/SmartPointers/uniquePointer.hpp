#ifndef UNIQUE_POINTER_HPP
#define UNIQUE_POINTER_HPP

#include "_basePointer.hpp"

/** @brief File containing unique pointer class declarations
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Types::SmartPointers {

	template<class T>
	class UniquePointer ;
	
	template<>
	class UniquePointer<void> ;

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
			
			/** Regular constructor, intialises unique smart pointer container to void pointer
			@param void* (raw void pointer)
			@return <initialised-object> **/
			UniquePointer(void*) ;
			
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
			
			/** Pseudo-move constructor, takes ownership of a given specialised void unique smart pointer
			@param an r-value object reference 
			@return <initialised-object> **/
			UniquePointer(UniquePointer<void>&&) ;
			
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
	
	template<>
	class UniquePointer<void> : public Pointer<void> {
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
			
			UniquePointer(void*) = delete ;			
			
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
			
			UniquePointer& operator=(void*) = delete ;			
			
			/** Removed copy constructor **/
			UniquePointer(const UniquePointer&) = delete ;
			
			/** Removed copy assignment operator **/
			UniquePointer& operator=(const UniquePointer&) = delete ;
			
			/** Pseudo-move constructor, takes ownership of a given templated unique smart pointer
			@param an r-value templated-object reference 
			@return <initialised-object> **/
			UniquePointer(UniquePointer&&) ;
			
			/** Pseudo-move constructor, takes ownership of a given shared unique pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			template<typename T>
			UniquePointer(UniquePointer<T>&&) ;	
			
			/** Move assignment operator, takes ownership of a given unique smart pointer
			@param an r-value object reference 
			@return reference to modified smart pointer **/
			UniquePointer& operator=(UniquePointer&&) ;
			
			/** Pseudo-move assignment operator, takes ownership of a given templated unique smart pointer
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

#include "uniquePointer.tpp"

#endif
