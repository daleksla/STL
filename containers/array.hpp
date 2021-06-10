#ifndef ARRAY_HPP
#define ARRAY_HPP
#pragma once

#include "../types/macros.hpp"

/** @brief Array-class implementation file, representing a C-style array wrapper
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace salih {
namespace containers {

	template<class T, std::size_t SIZE>
	class Array {
		/** This aggregate class is the Array-class implementation, serving as a c-style array wrapper **/
		public:			
			T pointer[SIZE] ;
			
		public:
			/** Empty constructor, intialises empty array 
			@return <initialised-object> **/
			//Array() = default ;

			/** Regular constructor, assigns values to an array
			@param an initialiser list of values
			@return <initialised-object> **/	
			//Array(const std::intializer_list<T>&) ;
			
			/** Regular assignment operator, assigns values to an array
			@param an initialiser list of values
			@return reference to current object **/
			//Array& operator=(const std::intializer_list<T>&) ;
		
			/** Copy constructor, creates copy of a given array
			@param a (l-value) array object
			@return <initialised-object> **/	
			//Array(const Array&) = default ;
			
			/** Copy assignment operator, creates copy of a given array
			@param a (l-value) array object
			@return reference to current object **/
			//Array& operator=(const Array&) = default ;
			
			/** Move constructor, takes ownership of array contents
			@param an r-value array object
			@return <initialised-object> **/	
			//Array(const Array&) = default ;
			
			/** Move assignment operator, takes ownership of array contents
			@param an r-value array object
			@return reference to current object **/
			//Array& operator=(const Array&) = default ;			
	
			/** get method, returns underlying array structure
			@return returns pointer to array **/
			CONSTEXPRCXX11 T* get() const ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/
			CONSTEXPRCXX11 std::size_t getSize() const ;
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the structure **/ 
			CONSTEXPRCXX14 T& operator[](const std::size_t) ; 
	
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/ 		
			CONSTEXPRCXX11 const T& operator[](const std::size_t) const ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with
			@param bool (assumingly true flag as to check whether an index is valid)
			@return reference to a given element in the structure **/ 				
			CONSTEXPRCXX14 T& at(const std::size_t) ; 
			
			/** at method, another method to modify the structure but with range checks
			@param integer to index structure with
			@return constant reference to a given element in the structure **/ 	
			CONSTEXPRCXX11 const T& at(const std::size_t) const ; 
			
			/** Concatenation operator, adds two arrays together
			@param array structure to add 
			@return array containing combined values **/ 	
			CONSTEXPRCXX14 Array<T,(SIZE+SIZE)> operator+(const Array&) const ;			
			
			/** Concatenation operator, adds two arrays together
			@param array structure (of a different size) to add
			@return array containing combined values **/ 	
			template<std::size_t DIFF>
			CONSTEXPRCXX14 Array<T,(SIZE+DIFF)> operator+(const Array<T, DIFF>&) const ;	
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of same type and size)
			@return a boolean representing whether equality is met **/ 	
			CONSTEXPRCXX14 bool operator==(const Array&) const ;			
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of different type, same size)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			CONSTEXPRCXX14 bool operator==(const Array<OTHER, SIZE>&) const ;
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of same type, different size)
			@return a boolean (will always return false, since the arrays can't have the same values) **/ 	
			template<std::size_t DIFF>
			CONSTEXPRCXX11 bool operator==(const Array<T, DIFF>&) const ;
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of different type and size)
			@return a boolean (will always return false, since the arrays can't have the same values) **/ 	
			template<typename OTHER, std::size_t DIFF>
			CONSTEXPRCXX11 bool operator==(const Array<OTHER, DIFF>&) const ;
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's values
			@param contiguous structure to compare with (of same type and size)
			@return a boolean representing whether inequality is met **/ 	
			CONSTEXPRCXX14 bool operator!=(const Array&) const ;			
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's values
			@param array structure to compare with (of different type, same size)
			@return a boolean representing whether inequality is met **/ 	
			template<typename OTHER>
			CONSTEXPRCXX14 bool operator!=(const Array<OTHER, SIZE>&) const ;
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's
			@param array structure to compare with (of same type, different size)
			@return a boolean representing whether inequality is met (will always return true) **/ 	
			template<std::size_t DIFF>
			CONSTEXPRCXX11 bool operator!=(const Array<T, DIFF>&) const ;
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's
			@param array structure to compare with (of different type and size)
			@return a boolean representing whether inequality is met (will always return true) **/ 	
			template<typename OTHER, std::size_t DIFF>
			CONSTEXPRCXX11 bool operator!=(const Array<OTHER, DIFF>&) const ;
			
			/** (Trivial) Destructor **/					
			//~Array() = default ;
			
			class Iterator {
				/** This class represents an Iterator object, allowing for controlled, read-write access to the Array's values **/ 
				private:
					T* pointer ;
					
					/** Regular constructor, intialises iterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					CONSTEXPRCXX14 Iterator(T*) ;
				
				public:
					/** Empty constructor, intialises empty iterator 
					@return <initialised-object> **/
					CONSTEXPRCXX14 Iterator() ;
					
					/** Copy constructor, copies address of element behind an iterator
					@param Iterator object
					@return <initialised-object> **/
					CONSTEXPRCXX14 Iterator(const Iterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an iterator
					@param Iterator object
					@return reference to calling Iterator **/
					CONSTEXPRCXX14 Iterator& operator=(const Iterator&) = default ;
					
					/** Move constructor, takes ownership of Iterator properties
					@param Iterator object
					@return <initialised-object> **/
					CONSTEXPRCXX14 Iterator(Iterator&&) = default ;
					
					/** Move assignment operator, takes ownership of Iterator properties
					@param Iterator object
					@return reference to calling Iterator **/
					CONSTEXPRCXX14 Iterator& operator=(Iterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					CONSTEXPRCXX14 T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					CONSTEXPRCXX14 T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return Iterator object (pointing to the further element in sequence) **/					
					CONSTEXPRCXX14 Iterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to further element in sequence) **/					
					CONSTEXPRCXX14 Iterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling Iterator (now pointing to the next element in sequence) **/										
					CONSTEXPRCXX14 Iterator& operator++() ; 

					/** Postfix increment operator - modifies iterator to point to the next element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX14 Iterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return Iterator object (pointing to the earlier element in sequence) **/						
					CONSTEXPRCXX14 Iterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to the earlier element in sequence) **/											
					CONSTEXPRCXX14 Iterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies iterator to point to the previous element in sequence
					@return reference to calling Iterator (now pointing to the previous element in sequence) **/						
					CONSTEXPRCXX14 Iterator& operator--() ; 

					/** Postfix decrement operator - modifies iterator to point to the previous element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX14 Iterator operator--(const int) ;

					/** Comparison operator, determines if two iterators point to the same location
					@param Iterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					CONSTEXPRCXX14 bool operator==(const Iterator&) const ;

					/** Inequality operator, determines if two iterators don't point to the same location
					@param Iterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					CONSTEXPRCXX14 bool operator!=(const Iterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					~Iterator() = default ;
					
					friend class Array ;
					
			} ; 
			
			class ConstIterator {
				/** This class represents a ConstIterator object, allowing for controlled, read-only access to the Array's values **/ 
				private:
					T const* pointer ;
					
					/** Regular constructor, intialises ConstIterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					CONSTEXPRCXX11 ConstIterator(T const*) ;
				
				public:
					/** Empty constructor, intialises empty ConstIterator 
					@return <initialised-object> **/
					CONSTEXPRCXX11 ConstIterator() ;
					
					/** Copy constructor, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return <initialised-object> **/
					CONSTEXPRCXX11 ConstIterator(const ConstIterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					CONSTEXPRCXX14 ConstIterator& operator=(const ConstIterator&) = default ;
					
					/** Move constructor, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return <initialised-object> **/
					CONSTEXPRCXX11 ConstIterator(ConstIterator&&) = default ;
					
					/** Move assignment operator, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					CONSTEXPRCXX14 ConstIterator& operator=(ConstIterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					CONSTEXPRCXX11 const T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					CONSTEXPRCXX11 const T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return ConstIterator object (pointing to the further element in sequence) **/					
					CONSTEXPRCXX11 ConstIterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps later
					@param Number of positions further in sequence that the ConstIterator should point to
					@return reference to calling ConstIterator (now pointing to further element in sequence) **/					
					CONSTEXPRCXX14 ConstIterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling ConstIterator (now pointing to the next element in sequence) **/										
					CONSTEXPRCXX14 ConstIterator& operator++() ; 

					/** Postfix increment operator - modifies ConstIterator to point to the next element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX14 ConstIterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the ConstIterator should point to
					@return ConstIterator object (pointing to the earlier element in sequence) **/						
					CONSTEXPRCXX11 ConstIterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling ConstIterator (now pointing to the earlier element in sequence) **/											
					CONSTEXPRCXX14 ConstIterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return reference to calling ConstIterator (now pointing to the previous element in sequence) **/						
					CONSTEXPRCXX14 ConstIterator& operator--() ; 

					/** Postfix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX14 ConstIterator operator--(const int) ;

					/** Comparison operator, determines if two ConstIterators point to the same location
					@param ConstIterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					CONSTEXPRCXX11 bool operator==(const ConstIterator&) const ;

					/** Inequality operator, determines if two ConstIterators don't point to the same location
					@param ConstIterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					CONSTEXPRCXX11 bool operator!=(const ConstIterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					~ConstIterator() = default ;
					
					friend class Array ;
					
			} ; 
			
			/** begin method, creates Iterator object to the first element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to first element in sequence **/ 
			CONSTEXPRCXX14 Iterator begin() ;

			/** end method, creates Iterator object to beyond the final element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX14 Iterator end() ;

			/** begin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to first element in sequence **/ 			
			CONSTEXPRCXX11 ConstIterator begin() const ;

			/** end method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX11 ConstIterator end() const ;

			/** cbegin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to first element in sequence **/ 			
			CONSTEXPRCXX11 ConstIterator cbegin() const ;

			/** cend method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX11 ConstIterator cend() const ;
			
			template<class, std::size_t>
			friend class Array ;
	} ;
	
}
}

#include "array.tpp"

#endif
