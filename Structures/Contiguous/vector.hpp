#ifndef VECTOR_HPP
#define VECTOR_HPP
#pragma once

#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

/** @brief Vector-class implementation file, a wrapper for a C-style dynamic-contiguous data structure
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Structures::Contiguous {

	template<class T>
	class Vector {
		/** This class is the vector-class implementation, serving as a dynamically resizing c-array wrapper **/
		private:			
			T* pointer ;
			
			std::size_t size ;
		
			Vector(T*, const std::size_t) ;
		public:
			/** Empty constructor, intialises empty vector 
			@return <initialised-object> **/
			Vector() ;
		
			/** Size-creating constructor, intialises a vector of a specified size
			@param size_t (size of vector to pre-initialise)
			@return <initialised-object> **/	
			Vector(const std::size_t) ;

			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for vector)
			@return <initialised-object> **/			
			Vector(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, assigns values to vector
			@param initialisation list (of values for vector)
			@return reference to current object **/
			Vector& operator=(const std::initializer_list<T>&) ;
			
			/** Copy constructor, creates copy of a given vector
			@param a (l-value) vector object
			@return <initialised-object> **/
			Vector(const Vector&) ;
			
			/** Copy assignment operator, creates copy of a given vector
			@param a (l-value) vector object
			@return reference to current object **/
			Vector& operator=(const Vector&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary vector object
			@param an r-value vector object
			@return <initialised-object> **/
			Vector(Vector&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary vector object
			@param an (r-value) vector object
			@return reference to current object **/
			Vector& operator=(Vector&&) ;			
			
			/** Destructor, frees memory and deletes vector **/					
			~Vector() ;			
			
			/** append method, adds a value to the end of the current vector
			@param value (to add) **/
			void append(T) ;
			
			/** clear method, deletes all elements of the vector **/
			void clear() ;
			
			/** insert method, adds an element into a specified position
			@param position in vector to insert to **/
			void insert(const std::size_t, T) ;
			
			/** del method, deletes a selected element by position
			@param value representing position to delete from vector **/
			void del(const std::size_t) ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/
			std::size_t getSize() const ;

			/** Slicing operator, extract part of structure directly
			@param integer to start slicing from	
			@param integer to slice until			
			@return sliced vector (ie values from index a->b) **/ 
			Vector operator()(const std::size_t, const std::size_t) const ;
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the structure **/ 
			T& operator[](const std::size_t) ; 
	
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/ 		
			const T& operator[](const std::size_t) const ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with
			@param bool (assumingly true flag as to check whether an index is valid)
			@return reference to a given element in the structure **/ 				
			T& at(const std::size_t, const bool check = true) ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with, 
			@param bool (assumingly true flag as to check whether an index is valid)
			@return constant reference to a given element in the structure **/ 	
			const T& at(const std::size_t, const bool check = true) const ; 
			
			/** Concatenation operator, adds two vectors together
			@param vector structure to add
			@return vector containing combined values **/ 	
			Vector operator+(const Vector&) const ;	
			
			/** Concatenation operator, modifies / appends calling vector with additional values
			@param vector structure to add
			@return a reference to the calling vector **/ 			
			Vector& operator+=(const Vector&) ;			
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param vector structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			bool operator==(const Vector<OTHER>&) const ;
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param vector structure to compare with
			@return a boolean representing whether equality is met **/ 	
			bool operator==(const Vector&) const ;
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param vector structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is not met **/ 	
			template<typename OTHER>
			bool operator!=(const Vector<OTHER>&) const ;
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param vector structure to compare with
			@return a boolean representing whether equality is not met **/ 
			bool operator!=(const Vector&) const ;
			
			class Iterator {
				/** This class represents an Iterator object, allowing for controlled, read-write access to the vector's values **/ 
				private:
					T* pointer;
				
				public:
					/** Empty constructor, intialises empty iterator 
					@return <initialised-object> **/
					Iterator() ;
					
					/** Copy constructor, copies address of element behind an iterator
					@param Iterator object
					@return <initialised-object> **/
					Iterator(const Iterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an iterator
					@param Iterator object
					@return reference to calling Iterator **/
					Iterator& operator=(const Iterator&) = default ;
					
					/** Move constructor, takes ownership of Iterator properties
					@param Iterator object
					@return <initialised-object> **/
					Iterator(Iterator&&) = default ;
					
					/** Move assignment operator, takes ownership of Iterator properties
					@param Iterator object
					@return reference to calling Iterator **/
					Iterator& operator=(Iterator&&) = default ;

					/** Regular constructor, intialises iterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					Iterator(T*) ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return Iterator object (pointing to the further element in sequence) **/					
					Iterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to further element in sequence) **/					
					Iterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling Iterator (now pointing to the next element in sequence) **/										
					Iterator& operator++() ; 

					/** Postfix increment operator - modifies iterator to point to the next element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					Iterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return Iterator object (pointing to the earlier element in sequence) **/						
					Iterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to the earlier element in sequence) **/											
					Iterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies iterator to point to the previous element in sequence
					@return reference to calling Iterator (now pointing to the previous element in sequence) **/						
					Iterator& operator--() ; 

					/** Postfix decrement operator - modifies iterator to point to the previous element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					Iterator operator--(const int) ;

					/** Comparison operator, determines if two iterators point to the same location
					@param Iterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					bool operator==(const Iterator&) const ;

					/** Inequality operator, determines if two iterators don't point to the same location
					@param Iterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					bool operator!=(const Iterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					~Iterator() = default ;
					
			} ; 
			
			class ConstIterator {
				/** This class represents a ConstIterator object, allowing for controlled, read-only access to the Vector's values **/ 
				private:
					T* pointer;
				
				public:
					/** Empty constructor, intialises empty ConstIterator 
					@return <initialised-object> **/
					ConstIterator() ;
					
					/** Copy constructor, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return <initialised-object> **/
					ConstIterator(const ConstIterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					ConstIterator& operator=(const ConstIterator&) = default ;
					
					/** Move constructor, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return <initialised-object> **/
					ConstIterator(ConstIterator&&) = default ;
					
					/** Move assignment operator, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					ConstIterator& operator=(ConstIterator&&) = default ;

					/** Regular constructor, intialises ConstIterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					ConstIterator(T const*) ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					const T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					const T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return ConstIterator object (pointing to the further element in sequence) **/					
					ConstIterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps later
					@param Number of positions further in sequence that the ConstIterator should point to
					@return reference to calling ConstIterator (now pointing to further element in sequence) **/					
					ConstIterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling ConstIterator (now pointing to the next element in sequence) **/										
					ConstIterator& operator++() ; 

					/** Postfix increment operator - modifies ConstIterator to point to the next element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					ConstIterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the ConstIterator should point to
					@return ConstIterator object (pointing to the earlier element in sequence) **/						
					ConstIterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling ConstIterator (now pointing to the earlier element in sequence) **/											
					ConstIterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return reference to calling ConstIterator (now pointing to the previous element in sequence) **/						
					ConstIterator& operator--() ; 

					/** Postfix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					ConstIterator operator--(const int) ;

					/** Comparison operator, determines if two ConstIterators point to the same location
					@param ConstIterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					bool operator==(const ConstIterator&) const ;

					/** Inequality operator, determines if two ConstIterators don't point to the same location
					@param ConstIterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					bool operator!=(const ConstIterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					~ConstIterator() = default ;
					
			} ; 
			
			/** begin method, creates Iterator object to the first element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to first element in sequence **/ 
			Iterator begin() ;

			/** end method, creates Iterator object to beyond the final element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to beyond the final element in sequence **/ 			
			Iterator end() ;

			/** begin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to first element in sequence **/ 			
			ConstIterator begin() const ;

			/** end method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			ConstIterator end() const ;

			/** cbegin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to first element in sequence **/ 			
			ConstIterator cbegin() const ;

			/** cend method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			ConstIterator cend() const ;		
			
			template<typename OTHER>
			friend class Vector ;
	} ;
	
}

#include "vector.tpp"

#endif
