#ifndef LIST_HPP
#define LIST_HPP
#pragma once

#include "d-node.hpp"
#include "../types/macros.hpp"
#include "../types/iterators.hpp"
#include <initializer_list>

/** @brief Doubly Linkedlist container
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/
 
namespace salih {
namespace containers {

	template<class T>
	class List {
		/** @brief This class is a doubly-linkedlist class implementation, serving as a custom linked-node wrapper / manager **/
		public:
			using innerType = T ;                            
			using pointerType = T* ;                               
			using constPointerType = const T* ;                         
			using referenceType = T& ;                             
			using constReferenceType = const T& ;  
			using iteratorType = salih::types::BiDirectionalIteratorTag ;
			
		private:
			DNode<T>* head ;
			
			DNode<T>* tail ;
			
			unsigned long size ;
			
			CONSTEXPRCXX20 inline void setSize(unsigned long) ;
			
			CONSTEXPRCXX20 inline void del(DNode<T>*) ;
			
			CONSTEXPRCXX20 inline void insert(DNode<T>*, T) ;
			
		public:
			/** Empty constructor, intialises empty list 
			@return <initialised-object> **/
			CONSTEXPRCXX20 List() ; //empty linkedlist (ie no nodes)
			
			/** Copy constructor, creates copy of a given list
			@param a (l-value) list object
			@return <initialised-object> **/	
			CONSTEXPRCXX20 List(const List&) ; //create new copy where each node is copied and mapped to new copies
			
			/** Copy assignment operator, creates copy of a given list
			@param a (l-value) list object
			@return reference to current object **/
			CONSTEXPRCXX20 List& operator=(const List&) ;
					
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for list)
			@return <initialised-object> **/	
			CONSTEXPRCXX20 List(const std::initializer_list<T>&) ; //initialise linked list by creating a node for every element in the vector - use new and delete to throw values onto stack - use destructor to loop through and delete
			
			/** Regular assignment operator, assigns values to list
			@param initialisation list (of values for list)
			@return reference to current object **/
			CONSTEXPRCXX20 List& operator=(const std::initializer_list<T>&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary list object
			@param an (r-value) list object
			@return reference to current object **/
			CONSTEXPRCXX20 List& operator=(List&&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary list object
			@param an r-value list object
			@return <initialised-object> **/
			CONSTEXPRCXX20 List(List&&) ;
			
			/** Destructor, frees memory and deletes list **/					
			CONSTEXPRCXX20 ~List() ; //destructor - will deallocate memory if necessary
			
			/** Slicing operator, extract part of structure directly
			@param integer to start slicing from	
			@param integer to slice until			
			@return sliced linked list (ie values from index a->b) **/ 
			CONSTEXPRCXX20 List operator()(const unsigned long, const unsigned long) const ;			
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the list **/ 
			CONSTEXPRCXX20 T& operator[](const unsigned long) ; //method to index linked list, returns data
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/
			CONSTEXPRCXX20 const T& operator[](const unsigned long) const ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure, but with range checks
			@param integer to index structure with
			@return reference to a given element in the structure **/ 			
			CONSTEXPRCXX20 T& at(const unsigned long) ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure, but with range checks
			@param integer to index structure with
			@return constant reference to a given element in the structure **/ 
			CONSTEXPRCXX20 const T& at(const unsigned long) const ; //method to index linked list, returns data
			
			/** Concatenation operator, adds two lists together
			@param list structure to add
			@return list containing combined values **/ 	
			CONSTEXPRCXX20 List operator+(const List&) const ;	
			
			/** Concatenation operator, modifies / appends calling list with additional values
			@param list structure to add
			@return a reference to the calling list **/ 			
			CONSTEXPRCXX20 List& operator+=(const List&) ;				
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is met **/ 	
			CONSTEXPRCXX20 bool operator==(const List<T>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is not met **/ 
			CONSTEXPRCXX20 bool operator!=(const List<T>&) const ; //method to index linked list, returns data
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is met **/ 				
			template<typename OTHER>
			CONSTEXPRCXX20 bool operator==(const List<OTHER>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is not met **/ 	
			template<typename OTHER>
			CONSTEXPRCXX20 bool operator!=(const List<OTHER>&) const ; //method to index linked list, returns data
			
			/** insert method, inserts a value into a given position in a list sequence 
			@param integer (representing position to insert into), value (to insert into said position) **/ 
			CONSTEXPRCXX20 void insert(const unsigned long, T) ;
				
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			CONSTEXPRCXX20 unsigned long getSize() const ; //get size
			
			/** append method, adds a value to the end of the linkedlist
			@param value (to add) **/
			CONSTEXPRCXX20 void append(T) ; //append value to list
			
			/** append method, adds values to the end of the linkedlist
			@param values (to add) **/
			CONSTEXPRCXX20 void append(const std::initializer_list<T>&) ; //append values to list
			
			/** del method, deletes a value at a given position
			@param position (from list to remove) **/			
			CONSTEXPRCXX20 void del(const unsigned long) ; //delete element in list based off rank (1st, 2nd, etc.)
			
			/** clear method, wipes and deletes all values **/			
			CONSTEXPRCXX20 void clear() ;	
			
			class Iterator {
				/** This class represents an Iterator object, allowing for controlled, read-write access to the list's values **/ 
				public:
					using innerType = T ;                            
					using pointerType = T* ;                               
					using constPointerType = const T* ;                         
					using referenceType = T& ;                             
					using constReferenceType = const T& ;  
					using category = salih::types::BiDirectionalIteratorTag ;
					
				private:
					DNode<T>* pointer ;

					/** Regular constructor, intialises iterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					CONSTEXPRCXX20 Iterator(DNode<T>*) ;
				
				public:
					/** Empty constructor, intialises empty iterator 
					@return <initialised-object> **/
					CONSTEXPRCXX20 Iterator() ;
					
					/** Copy constructor, copies address of element behind an iterator
					@param Iterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 Iterator(const Iterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an iterator
					@param Iterator object
					@return reference to calling Iterator **/
					CONSTEXPRCXX20 Iterator& operator=(const Iterator&) = default ;
					
					/** Move constructor, takes ownership of Iterator properties
					@param Iterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 Iterator(Iterator&&) = default ;
					
					/** Move assignment operator, takes ownership of Iterator properties
					@param Iterator object
					@return reference to calling Iterator **/
					CONSTEXPRCXX20 Iterator& operator=(Iterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					CONSTEXPRCXX20 T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					CONSTEXPRCXX20 T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return Iterator object (pointing to the further element in sequence) **/					
					CONSTEXPRCXX20 Iterator operator+(const unsigned long) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to further element in sequence) **/					
					CONSTEXPRCXX20 Iterator& operator+=(const unsigned long) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling Iterator (now pointing to the next element in sequence) **/										
					CONSTEXPRCXX20 Iterator& operator++() ; 

					/** Postfix increment operator - modifies iterator to point to the next element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 Iterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return Iterator object (pointing to the earlier element in sequence) **/						
					CONSTEXPRCXX20 Iterator operator-(const unsigned long) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to the earlier element in sequence) **/											
					CONSTEXPRCXX20 Iterator& operator-=(const unsigned long) ;

					/** Prefix decrement operator - modifies iterator to point to the previous element in sequence
					@return reference to calling Iterator (now pointing to the previous element in sequence) **/						
					CONSTEXPRCXX20 Iterator& operator--() ; 

					/** Postfix decrement operator - modifies iterator to point to the previous element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 Iterator operator--(const int) ;

					/** Comparison operator, determines if two iterators point to the same location
					@param Iterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					CONSTEXPRCXX20 bool operator==(const Iterator&) const ;

					/** Inequality operator, determines if two iterators don't point to the same location
					@param Iterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					CONSTEXPRCXX20 bool operator!=(const Iterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					CONSTEXPRCXX20 ~Iterator() = default ;
					
					friend class List ;
					
			} ; 
			
			class ConstIterator {
				/** This class represents a ConstIterator object, allowing for controlled, read-only access to the list's values **/ 
				public:
					using innerType = T ;                            
					using pointerType = T* ;                               
					using constPointerType = const T* ;                         
					using referenceType = T& ;                             
					using constReferenceType = const T& ;  
					using category = salih::types::BiDirectionalIteratorTag ;
					
				private:
					DNode<T> const* pointer;

					/** Regular constructor, intialises ConstIterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					CONSTEXPRCXX20 ConstIterator(DNode<T> const*) ;
				
				public:
					/** Empty constructor, intialises empty ConstIterator 
					@return <initialised-object> **/
					CONSTEXPRCXX20 ConstIterator() ;
					
					/** Copy constructor, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 ConstIterator(const ConstIterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					CONSTEXPRCXX20 ConstIterator& operator=(const ConstIterator&) = default ;
					
					/** Move constructor, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 ConstIterator(ConstIterator&&) = default ;
					
					/** Move assignment operator, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					CONSTEXPRCXX20 ConstIterator& operator=(ConstIterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					CONSTEXPRCXX20 const T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					CONSTEXPRCXX20 const T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return ConstIterator object (pointing to the further element in sequence) **/					
					CONSTEXPRCXX20 ConstIterator operator+(const unsigned long) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps later
					@param Number of positions further in sequence that the ConstIterator should point to
					@return reference to calling ConstIterator (now pointing to further element in sequence) **/					
					CONSTEXPRCXX20 ConstIterator& operator+=(const unsigned long) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling ConstIterator (now pointing to the next element in sequence) **/										
					CONSTEXPRCXX20 ConstIterator& operator++() ; 

					/** Postfix increment operator - modifies ConstIterator to point to the next element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 ConstIterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the ConstIterator should point to
					@return ConstIterator object (pointing to the earlier element in sequence) **/						
					CONSTEXPRCXX20 ConstIterator operator-(const unsigned long) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling ConstIterator (now pointing to the earlier element in sequence) **/											
					CONSTEXPRCXX20 ConstIterator& operator-=(const unsigned long) ;

					/** Prefix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return reference to calling ConstIterator (now pointing to the previous element in sequence) **/						
					CONSTEXPRCXX20 ConstIterator& operator--() ; 

					/** Postfix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 ConstIterator operator--(const int) ;

					/** Comparison operator, determines if two ConstIterators point to the same location
					@param ConstIterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					CONSTEXPRCXX20 bool operator==(const ConstIterator&) const ;

					/** Inequality operator, determines if two ConstIterators don't point to the same location
					@param ConstIterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					CONSTEXPRCXX20 bool operator!=(const ConstIterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					CONSTEXPRCXX20 ~ConstIterator() = default ;
					
					friend class List ;
					
			} ; 
			
			/** begin method, creates Iterator object to the first element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to first element in sequence **/ 
			CONSTEXPRCXX20 Iterator begin() ;

			/** end method, creates Iterator object to beyond the final element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX20 Iterator end() ;

			/** begin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to first element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator begin() const ;

			/** end method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator end() const ;

			/** cbegin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to first element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator cbegin() const ;

			/** cend method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator cend() const ;				
			
			template<typename OTHER>
			friend class List ;
	} ;	

}
}

#include "list.tpp"

#endif
