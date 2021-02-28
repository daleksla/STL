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

	template<class T>
	class LinkedList {
		private:
			Node<T>* head ;
			
			Node<T>* tail ;
			
			int size = -1 ;
			
			bool alloc ;
			
			inline void setSize(int) ;
			
			inline void del(Node<T>*&) ;
		public:
			LinkedList() ; //empty linkedlist (ie no nodes)
			
			// LinkedList(const LinkedList&) ; //create new copy where each node is copied and mapped to new copies
			
			LinkedList(const std::initializer_list<T>&) ; //initialise linked list by creating a node for every element in the vector - use new and delete to throw values onto stack - use destructor to loop through and delete
					
			LinkedList(Node<T>&) ; //provide node and assumes head is supplied	
			
			LinkedList(Node<T>&, bool) ; //provide node and note whether tail or head is supplied
			
			LinkedList(Node<T>&, Node<T>&) ; //provide head and tail node
			
			~LinkedList() ; //destructor - will deallocate memory if necessary
			
			T& operator[](const int&) ; //method to index linked list, returns data
			
			bool operator==(LinkedList<T>&) ; //method to index linked list, returns data
						
			const int getSize() ; //get size
			
			void append(T) ; //append value to list
			
			void del(int) ; //delete element in list based off rank (1st, 2nd, etc.)

	} ;	
}

#include "linkedlist.tpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, Salih::Structures::LinkedLists::LinkedList<T>& dt)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    if(dt.getSize() == 0) 
    {
    	os << "[]" ;
    	return os ;
    }
    
    os << "[" ;
    for(int i = 0 ; i < dt.getSize() ; i++)
    {
    	if(i != dt.getSize() - 1) os << dt[i] << "," ;
    	else os << dt[i] ;
    }
    os << "]" ;
    
    return os;
}

#endif
