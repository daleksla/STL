#ifndef FWDLIST_HPP
#define FWDLIST_HPP
#pragma once

#include <lib/Structures/LinkedLists/_sNode.hpp>
#include <algorithm>
#include <iostream>
#include <initializer_list>

/** @brief Singly Linkedlist container-class declaration file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/
 
namespace Salih::Structures::LinkedLists {
	
	template<typename T>
	class FwdList ;

}

namespace Salih::Structures::LinkedLists {

	template<class T>
	class FwdList {
		/** @brief This class is a singly-linkedlist class implementation, serving as a custom linked-node wrapper / manager **/
		private:
			SNode<T>* head ;
			
			std::size_t size ;
			
			inline void setSize(int) ;
			
		public:
			/** Empty constructor, intialises empty list 
			@return <initialised-object> **/
			FwdList() ; //empty linkedlist (ie no nodes)
			
			/** Copy constructor, creates copy of a given list
			@param a (l-value) list object
			@return <initialised-object> **/	
			FwdList(const FwdList&) ; //create new copy where each node is copied and mapped to new copies
			
			/** Copy assignment operator, creates copy of a given list
			@param a (l-value) list object
			@return reference to current object **/
			FwdList& operator=(const FwdList&) ;
					
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for list)
			@return <initialised-object> **/	
			FwdList(const std::initializer_list<T>&) ; //initialise linked list by creating a node for every element in the vector - use new and delete to throw values onto stack - use destructor to loop through and delete
			
			/** Regular assignment operator, assigns values to list
			@param initialisation list (of values for list)
			@return reference to current object **/
			FwdList& operator=(const std::initializer_list<T>&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary list object
			@param an (r-value) list object
			@return reference to current object **/
			FwdList& operator=(FwdList&&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary list object
			@param an r-value list object
			@return <initialised-object> **/
			FwdList(FwdList&&) ;
			
			/** Destructor, frees memory and deletes list **/					
			~FwdList() ; //destructor - will deallocate memory if necessary
			
			/** Slicing operator, extract part of structure directly
			@param integer to start slicing from	
			@param integer to slice until			
			@return sliced linked list (ie values from index a->b) **/ 
			FwdList operator()(const std::size_t, const std::size_t) const ;			
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the list **/ 
			T& operator[](const std::size_t) ; //method to index linked list, returns data
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/
			const T& operator[](const std::size_t) const ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure
			@param integer to index structure with
			@param bool (assumingly true flag as to check whether an index is valid)
			@return reference to a given element in the structure **/ 			
			T& at(const std::size_t, const bool check = true) ; //method to index linked list, returns data
			
			/** at method, another method to modify the structure
			@param integer to index structure with
			@param bool (assumingly true flag as to check whether an index is valid)
			@return constant reference to a given element in the structure **/ 
			const T& at(const std::size_t, const bool check = true) const ; //method to index linked list, returns data
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is met **/ 	
			bool operator==(const FwdList<T>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with
			@return a boolean representing whether equality is not met **/ 
			bool operator!=(const FwdList<T>&) const ; //method to index linked list, returns data
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is met **/ 				
			template<typename OTHER>
			bool operator==(const FwdList<OTHER>&) const ; //method to index linked list, returns data
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param list structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is not met **/ 	
			template<typename OTHER>
			bool operator!=(const FwdList<OTHER>&) const ; //method to index linked list, returns data
			
			/** insert method, inserts a value into a given position in a list sequence 
			@param integer (representing position to insert into), value (to insert into said position) **/ 
			void insert(const std::size_t, T) ;
				
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			std::size_t getSize() const ; //get size
			
			/** append method, adds a value to the end of the linkedlist
			@param value (to add) **/
			void append(T) ; //append value to list
			
			/** del method, deletes a value at a given position
			@param position (from list to remove) **/			
			void del(const std::size_t) ; //delete element in list based off rank (1st, 2nd, etc.)

			/** clear method, wipes and deletes all values **/			
			void clear() ;
			
			template<typename OTHER>
			friend class FwdList ;
	} ;	
}

#include "fwdList.tpp"

#endif
