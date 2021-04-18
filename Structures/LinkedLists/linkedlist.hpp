#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#pragma once

#include <lib/Structures/LinkedLists/node.hpp>
#include <algorithm>
#include <iostream>
#include <initializer_list>

/* This file contains the declarations of a linked list 
 * It is located in the nested Salih, Structures, LinkedLists namespaces */
 
namespace Salih::Structures::LinkedLists {
	
	template<typename T>
	class LinkedList ;
	
}

namespace std _GLIBCXX_VISIBILITY(default)
{
	template<typename T>
	ostream& operator<<(ostream&, const ::Salih::Structures::LinkedLists::LinkedList<T>&) ;
}

namespace Salih::Structures::LinkedLists {

	template<class T>
	class LinkedList {
		private:
			Node<T>* head ;
			
			Node<T>* tail ;
			
			int size ;
			
			inline void setSize(int) ;
			
			inline void del(Node<T>*) ;
			
			inline void insert(Node<T>*, T) ;
			
		public:
			LinkedList() ; //empty linkedlist (ie no nodes)
			
			LinkedList(const LinkedList&) ; //create new copy where each node is copied and mapped to new copies
			
			LinkedList& operator=(const LinkedList&) ;
					
			LinkedList(const std::initializer_list<T>&) ; //initialise linked list by creating a node for every element in the vector - use new and delete to throw values onto stack - use destructor to loop through and delete
			
			LinkedList& operator=(const std::initializer_list<T>&) ;
			
			LinkedList& operator=(LinkedList&&) ;
			
			LinkedList(LinkedList&&) ;
			
			~LinkedList() ; //destructor - will deallocate memory if necessary
			
			T& operator[](const int) ; //method to index linked list, returns data
			
			const T& operator[](const int) const ; //method to index linked list, returns data
			
			bool operator==(const LinkedList<T>&) const ; //method to index linked list, returns data
			
			bool operator!=(const LinkedList<T>&) const ; //method to index linked list, returns data
			
			template<typename OTHER>
			bool operator==(const LinkedList<OTHER>&) const ; //method to index linked list, returns data
			
			template<typename OTHER>
			bool operator!=(const LinkedList<OTHER>&) const ; //method to index linked list, returns data
			
			void insert(const int, T) ;
						
			int getSize() const ; //get size
			
			void append(T) ; //append value to list
			
			void del(const int) ; //delete element in list based off rank (1st, 2nd, etc.)
			
			template<typename OTHER>
			friend class LinkedList ;
			
			friend ::std::ostream& ::std::operator<<(::std::ostream&, const LinkedList&) ;

	} ;	
}

#include "linkedlist.tpp"

#endif
