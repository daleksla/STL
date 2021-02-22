#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#pragma once

#include <algorithm>
#include <initializer_list>

/* This file contains the declarations of a linked list 
 * It is located in the nested Salih, Structures, LinkedLists namespaces */

namespace Salih::Structures::LinkedLists {

	template<typename T>
	class Node ;
	
	template<typename T>
	class LinkedList ;

	template<class T>
	class LinkedList {
		private:
			Node<T>* head ;
			
			Node<T>* tail ;
			
			bool alloc ;
		public:
			LinkedList() ; //empty linkedlist (ie no nodes)
			
			// LinkedList(const LinkedList&) ; //create new copy where each node is copied and mapped to new copies
			
			LinkedList(const std::initializer_list<T>&) ; //initialise linked list by creating a node for every element in the vector - use new and delete to throw values onto stack - use destructor to loop through and delete
					
			LinkedList(Node<T>&) ; //provide node and assumes head is supplied	
			
			LinkedList(Node<T>&, bool) ; //provide node and note whether tail or head is supplied
			
			LinkedList(Node<T>&, Node<T>&) ; //provide head and tail node
			
			~LinkedList() ; //destructor - will deallocate memory if necessary
			
			T& operator[](const int&) ; //method to index linked list, returns data

	} ;
	
	template<class T>
	class Node {
		private:
			Node* prev ; //pointer to prev element in LL

			Node* next ; //pointer to next element in LL

			T data ; //template variable for data
					
			static void appendNode(Node*&, Node*&) ; //static method actually finds slot and appends b to a's LL
			
		        static Node* getHead(Node*) ; // returns pointer of the head of the linked list current node is pointed to
		        
		        static Node* getTail(Node*) ; // returns pointer of the tail of the linked list current node is pointed to
					
		public:
			Node(T) ; //constructor - takes data
			
			Node(const Node&) ; //copy constructor - copies data and removes head and tail
			
			Node(T, Node&, bool) ; //constructor - takes data, node to connect to, specify direction (prev or next)
		
			Node(T, Node&, Node&) ; //constructor - takes data, prev node to connect to, next node to connect to
	
			const Node*& getPrev() const ; //gets prev node in LL

			Node*& getPrev() ; //gets prev node in LL
		
			void setPrev(Node*&) ; //sets prev node in LL
			
			const Node*& getNext() const ; //returns next node in LL

			Node*& getNext() ; //returns next node in LL

			void setNext(Node*&) ; //sets next node in LL
			
			T& getData() ; //returns data of object
			
			const T& getData() const ; //returns data of object

			void setData(T) ; //sets data of object

			void deleteNode() ; //connects previous and next node to each other, deletes data
			
			void appendNode(Node&) ; //method to append a to the object node

			static void appendNode(Node&, Node&) ; //static method to append b to the tree of a
		        
		        static int size(Node&) ; //calculate size of the LL a given node is connected to
		        
		        static Node* getHead(Node&) ; // returns pointer of the head of the linked list current node is pointed to
		        
		        static Node* getTail(Node&) ; // returns pointer of the tail of the linked list current node is pointed to
		        
		        friend class LinkedList<T> ;
			
		        friend std::ostream& operator<<(std::ostream&, Node) ; //custom printing off a node
	} ;	
	
}

#include "linkedlist.tpp"

#endif
