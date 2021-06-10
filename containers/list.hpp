#ifndef LIST_HPP
#define LIST_HPP
#pragma once

#include "d-node.hpp"
#include <initializer_list>

/** @brief Double Linkedlist container-class declaration file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/
 
namespace salih {
namespace containers {

	template<class T>
	class List {
		/** @brief This class is a doubly-linkedlist class implementation, serving as a custom linked-node wrapper / manager **/
		private:
			DNode<T>* head ;
			
			DNode<T>* tail ;
			
			std::size_t size ;
			
			_GLIBCXX20_CONSTEXPR inline void setSize(std::size_t) ;
			
			_GLIBCXX20_CONSTEXPR inline void del(DNode<T>*) ;
			
			_GLIBCXX20_CONSTEXPR inline void insert(DNode<T>*, T) ;
			
		public:
			/** Empty constructor, intialises empty list 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR List() ; //empty linkedlist (ie no nodes)
			
			/** Copy constructor, creates copy of a given list
			@param a (l-value) list object
			@return <initialised-object> **/	
			_GLIBCXX20_CONSTEXPR List(const List&) ; //create new copy where each node is copied and mapped to new copies
			
			/** Copy assignment operator, creates copy of a given list
			@param a (l-value) list object
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR List& operator=(const List&) ;
					
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for list)
			@return <initialised-object> **/	
			_GLIBCXX20_CONSTEXPR List(const std::initializer_list<T>&) ; //initialise linked list by creating a node for every element in the vector - use new and delete to throw values onto stack - use destructor to loop through and delete
			
			/** Regular assignment operator, assigns values to list
			@param initialisation list (of values for list)
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR List& operator=(const std::initializer_list<T>&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary list object
			@param an (r-value) list object
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR List& operator=(List&&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary list object
			@param an r-value list object
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR List(List&&) ;
			
			/** Destructor, frees memory and deletes list **/					
			_GLIBCXX20_CONSTEXPR ~List() ; //destructor - will deallocate memory if necessary
			
			/** Slicing operator, extract part of structure directly
			@param integer to start slicing from	
			@param integer to slice until			
			@return sliced linked list (ie values from index a->b) **/ 
			_GLIBCXX20_CONSTEXPR List operator()(const std::size_t, const std::size_t) const ;			
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the list **/ 
			_GLIBCXX20_CONSTEXPR T& operator[](const std::size_t) ; //method to index linked list, returns data
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/
			_GLIBCXX20_CONSTEXPR const T& operator[](const std::size_t) const ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure, but with range checks
			@param integer to index structure with
			@return reference to a given element in the structure **/ 			
			_GLIBCXX20_CONSTEXPR T& at(const std::size_t) ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure, but with range checks
			@param integer to index structure with
			@return constant reference to a given element in the structure **/ 
			_GLIBCXX20_CONSTEXPR const T& at(const std::size_t) const ; //method to index linked list, returns data
			
			/** Concatenation operator, adds two lists together
			@param list structure to add
			@return list containing combined values **/ 	
			_GLIBCXX20_CONSTEXPR List operator+(const List&) const ;	
			
			/** Concatenation operator, modifies / appends calling list with additional values
			@param list structure to add
			@return a reference to the calling list **/ 			
			_GLIBCXX20_CONSTEXPR List& operator+=(const List&) ;				
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is met **/ 	
			_GLIBCXX20_CONSTEXPR bool operator==(const List<T>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is not met **/ 
			_GLIBCXX20_CONSTEXPR bool operator!=(const List<T>&) const ; //method to index linked list, returns data
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is met **/ 				
			template<typename OTHER>
			_GLIBCXX20_CONSTEXPR bool operator==(const List<OTHER>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is not met **/ 	
			template<typename OTHER>
			_GLIBCXX20_CONSTEXPR bool operator!=(const List<OTHER>&) const ; //method to index linked list, returns data
			
			/** insert method, inserts a value into a given position in a list sequence 
			@param integer (representing position to insert into), value (to insert into said position) **/ 
			_GLIBCXX20_CONSTEXPR void insert(const std::size_t, T) ;
				
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			_GLIBCXX20_CONSTEXPR std::size_t getSize() const ; //get size
			
			/** append method, adds a value to the end of the linkedlist
			@param value (to add) **/
			_GLIBCXX20_CONSTEXPR void append(T) ; //append value to list
			
			/** append method, adds values to the end of the linkedlist
			@param values (to add) **/
			_GLIBCXX20_CONSTEXPR void append(const std::initializer_list<T>&) ; //append values to list
			
			/** del method, deletes a value at a given position
			@param position (from list to remove) **/			
			_GLIBCXX20_CONSTEXPR void del(const std::size_t) ; //delete element in list based off rank (1st, 2nd, etc.)
			
			/** clear method, wipes and deletes all values **/			
			_GLIBCXX20_CONSTEXPR void clear() ;	
			
			class Iterator {
				/** This class represents an Iterator object, allowing for controlled, read-write access to the list's values **/ 
				private:
					DNode<T>* pointer ;

					/** Regular constructor, intialises iterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					_GLIBCXX20_CONSTEXPR Iterator(DNode<T>*) ;
				
				public:
					/** Empty constructor, intialises empty iterator 
					@return <initialised-object> **/
					_GLIBCXX20_CONSTEXPR Iterator() ;
					
					/** Copy constructor, copies address of element behind an iterator
					@param Iterator object
					@return <initialised-object> **/
					_GLIBCXX20_CONSTEXPR Iterator(const Iterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an iterator
					@param Iterator object
					@return reference to calling Iterator **/
					_GLIBCXX20_CONSTEXPR Iterator& operator=(const Iterator&) = default ;
					
					/** Move constructor, takes ownership of Iterator properties
					@param Iterator object
					@return <initialised-object> **/
					_GLIBCXX20_CONSTEXPR Iterator(Iterator&&) = default ;
					
					/** Move assignment operator, takes ownership of Iterator properties
					@param Iterator object
					@return reference to calling Iterator **/
					_GLIBCXX20_CONSTEXPR Iterator& operator=(Iterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					_GLIBCXX20_CONSTEXPR T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					_GLIBCXX20_CONSTEXPR T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return Iterator object (pointing to the further element in sequence) **/					
					_GLIBCXX20_CONSTEXPR Iterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to further element in sequence) **/					
					_GLIBCXX20_CONSTEXPR Iterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling Iterator (now pointing to the next element in sequence) **/										
					_GLIBCXX20_CONSTEXPR Iterator& operator++() ; 

					/** Postfix increment operator - modifies iterator to point to the next element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					_GLIBCXX20_CONSTEXPR Iterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return Iterator object (pointing to the earlier element in sequence) **/						
					_GLIBCXX20_CONSTEXPR Iterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to the earlier element in sequence) **/											
					_GLIBCXX20_CONSTEXPR Iterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies iterator to point to the previous element in sequence
					@return reference to calling Iterator (now pointing to the previous element in sequence) **/						
					_GLIBCXX20_CONSTEXPR Iterator& operator--() ; 

					/** Postfix decrement operator - modifies iterator to point to the previous element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					_GLIBCXX20_CONSTEXPR Iterator operator--(const int) ;

					/** Comparison operator, determines if two iterators point to the same location
					@param Iterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					_GLIBCXX20_CONSTEXPR bool operator==(const Iterator&) const ;

					/** Inequality operator, determines if two iterators don't point to the same location
					@param Iterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					_GLIBCXX20_CONSTEXPR bool operator!=(const Iterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					_GLIBCXX20_CONSTEXPR ~Iterator() = default ;
					
					friend class List ;
					
			} ; 
			
			class ConstIterator {
				/** This class represents a ConstIterator object, allowing for controlled, read-only access to the list's values **/ 
				private:
					DNode<T> const* pointer;

					/** Regular constructor, intialises ConstIterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					_GLIBCXX20_CONSTEXPR ConstIterator(DNode<T> const*) ;
				
				public:
					/** Empty constructor, intialises empty ConstIterator 
					@return <initialised-object> **/
					_GLIBCXX20_CONSTEXPR ConstIterator() ;
					
					/** Copy constructor, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return <initialised-object> **/
					_GLIBCXX20_CONSTEXPR ConstIterator(const ConstIterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					_GLIBCXX20_CONSTEXPR ConstIterator& operator=(const ConstIterator&) = default ;
					
					/** Move constructor, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return <initialised-object> **/
					_GLIBCXX20_CONSTEXPR ConstIterator(ConstIterator&&) = default ;
					
					/** Move assignment operator, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					_GLIBCXX20_CONSTEXPR ConstIterator& operator=(ConstIterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					_GLIBCXX20_CONSTEXPR const T& operator*() const ;

					/** Access / Arrow operator - gets data behind the iterator
					@return Pointer to data (behind the iterator) **/
					_GLIBCXX20_CONSTEXPR const T* operator->() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return ConstIterator object (pointing to the further element in sequence) **/					
					_GLIBCXX20_CONSTEXPR ConstIterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps later
					@param Number of positions further in sequence that the ConstIterator should point to
					@return reference to calling ConstIterator (now pointing to further element in sequence) **/					
					_GLIBCXX20_CONSTEXPR ConstIterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling ConstIterator (now pointing to the next element in sequence) **/										
					_GLIBCXX20_CONSTEXPR ConstIterator& operator++() ; 

					/** Postfix increment operator - modifies ConstIterator to point to the next element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					_GLIBCXX20_CONSTEXPR ConstIterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the ConstIterator should point to
					@return ConstIterator object (pointing to the earlier element in sequence) **/						
					_GLIBCXX20_CONSTEXPR ConstIterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling ConstIterator (now pointing to the earlier element in sequence) **/											
					_GLIBCXX20_CONSTEXPR ConstIterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return reference to calling ConstIterator (now pointing to the previous element in sequence) **/						
					_GLIBCXX20_CONSTEXPR ConstIterator& operator--() ; 

					/** Postfix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					_GLIBCXX20_CONSTEXPR ConstIterator operator--(const int) ;

					/** Comparison operator, determines if two ConstIterators point to the same location
					@param ConstIterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					_GLIBCXX20_CONSTEXPR bool operator==(const ConstIterator&) const ;

					/** Inequality operator, determines if two ConstIterators don't point to the same location
					@param ConstIterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					_GLIBCXX20_CONSTEXPR bool operator!=(const ConstIterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					_GLIBCXX20_CONSTEXPR ~ConstIterator() = default ;
					
					friend class List ;
					
			} ; 
			
			/** begin method, creates Iterator object to the first element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to first element in sequence **/ 
			_GLIBCXX20_CONSTEXPR Iterator begin() ;

			/** end method, creates Iterator object to beyond the final element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to beyond the final element in sequence **/ 			
			_GLIBCXX20_CONSTEXPR Iterator end() ;

			/** begin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to first element in sequence **/ 			
			_GLIBCXX20_CONSTEXPR ConstIterator begin() const ;

			/** end method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			_GLIBCXX20_CONSTEXPR ConstIterator end() const ;

			/** cbegin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to first element in sequence **/ 			
			_GLIBCXX20_CONSTEXPR ConstIterator cbegin() const ;

			/** cend method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			_GLIBCXX20_CONSTEXPR ConstIterator cend() const ;				
			
			template<typename OTHER>
			friend class List ;
	} ;	

}
}

#include "list.tpp"

#endif