#ifndef NODE_HPP
#define NODE_HPP
#pragma once

#if defined LINKED_LIST_HPP
	#include <lib/Structures/LinkedLists/linkedlist.hpp>
#endif

#include <algorithm>
#include <iostream>
#include <initializer_list>

/* This file contains the declarations of a linked list node
 * It is located in the nested Salih, Structures, LinkedLists namespaces */

namespace Salih::Structures::LinkedLists {

	#if defined LINKED_LIST_HPP
		template<typename T>
		class LinkedList ;
	#endif

	template<typename T>
	class Node ;
	
	template<class T>
	class Node {
		private:
			Node* prev ; //pointer to prev element in LL

			Node* next ; //pointer to next element in LL
					
			static void appendNode(Node*&, Node*&) ; //static method actually finds slot and appends b to a's LL
			
		        static Node* getHead(Node*) ; // returns pointer of the head of the linked list current node is pointed to
		        
		        static Node* getTail(Node*) ; // returns pointer of the tail of the linked list current node is pointed to
					
		public:
			T data ; //template variable for data		
		
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

			void deleteNode() ; //connects previous and next node to each other, deletes data
			
			void appendNode(Node&) ; //method to append a to the object node

			static void appendNode(Node&, Node&) ; //static method to append b to the tree of a
		        
		        static int size(Node&) ; //calculate size of the LL a given node is connected to
		        
		        static Node* getHead(Node&) ; // returns pointer of the head of the linked list current node is pointed to
		        
		        static Node* getTail(Node&) ; // returns pointer of the tail of the linked list current node is pointed to
		        
		        #if defined LINKED_LIST_HPP
		        	friend class LinkedList<T> ;
		        #endif
			
		        //friend std::ostream& operator<<(std::ostream&, Node) ; //custom printing off a node
	} ;	
}

#include "node.tpp"

#endif
