#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#pragma once

#include <lib/Structures/LinkedLists/_node.hpp>
#include <algorithm>
#include <iostream>
#include <initializer_list>

/** @brief Linkedlist container-class declaration file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/
 
namespace Salih {
	
	namespace Structures::LinkedLists {
	
		template<typename T>
		class LinkedList ;

	}

	template<typename T>
	::std::ostream& operator<<(::std::ostream&, const Structures::LinkedLists::LinkedList<T>&) ;
	
}

namespace Salih::Structures::LinkedLists {

	template<class T>
	class LinkedList {
		/** This class is the Linkedlist-class implementation, serving as a custom linked-node wrapper / manager **/
		private:
			Node<T>* head ;
			
			Node<T>* tail ;
			
			int size ;
			
			inline void setSize(int) ;
			
			inline void del(Node<T>*) ;
			
			inline void insert(Node<T>*, T) ;
			
		public:
			/** Empty constructor, intialises empty list 
			@return <initialised-object> **/
			LinkedList() ; //empty linkedlist (ie no nodes)
			
			/** Copy constructor, creates copy of a given list
			@param a (l-value) list object
			@return <initialised-object> **/	
			LinkedList(const LinkedList&) ; //create new copy where each node is copied and mapped to new copies
			/** Copy assignment operator, creates copy of a given list
			@param a (l-value) list object
			@return reference to current object **/
			LinkedList& operator=(const LinkedList&) ;
					
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for list)
			@return <initialised-object> **/	
			LinkedList(const std::initializer_list<T>&) ; //initialise linked list by creating a node for every element in the vector - use new and delete to throw values onto stack - use destructor to loop through and delete
			
			/** Regular assignment operator, assigns values to list
			@param initialisation list (of values for list)
			@return reference to current object **/
			LinkedList& operator=(const std::initializer_list<T>&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary list object
			@param an (r-value) list object
			@return reference to current object **/
			LinkedList& operator=(LinkedList&&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary list object
			@param an r-value list object
			@return <initialised-object> **/
			LinkedList(LinkedList&&) ;
			
			/** Destructor, frees memory and deletes list **/					
			~LinkedList() ; //destructor - will deallocate memory if necessary
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the list **/ 
			T& operator[](const int) ; //method to index linked list, returns data
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/
			const T& operator[](const int) const ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure
			@param integer to index structure with, bool (assumingly true flag as to check whether an index is valid)
			@return reference to a given element in the structure **/ 			
			T& at(const int, const bool check = true) ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure
			@param integer to index structure with, bool (assumingly true flag as to check whether an index is valid)
			@return constant reference to a given element in the structure **/ 
			const T& at(const int, const bool check = true) const ; //method to index linked list, returns data
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is met **/ 	
			bool operator==(const LinkedList<T>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is not met **/ 
			bool operator!=(const LinkedList<T>&) const ; //method to index linked list, returns data
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is met **/ 				
			template<typename OTHER>
			bool operator==(const LinkedList<OTHER>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is not met **/ 	
			template<typename OTHER>
			bool operator!=(const LinkedList<OTHER>&) const ; //method to index linked list, returns data
			
			/** insert method, inserts a value into a given position in a list sequence 
			@param integer (representing position to insert into), value (to insert into said position) **/ 
			void insert(const int, T) ;
				
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			int getSize() const ; //get size
			
			/** append method, adds a value to the end of the linkedlist
			@param value (to add) **/
			void append(T) ; //append value to list
			
			/** del method, deletes a value at a given position
			@param position (from list to remove) **/			
			void del(const int) ; //delete element in list based off rank (1st, 2nd, etc.)
			
			template<typename OTHER>
			friend class LinkedList ;
			
			friend ::std::ostream& ::Salih::operator<<(::std::ostream&, const LinkedList&) ;

	} ;	
}

#include "linkedlist.tpp"

#endif
