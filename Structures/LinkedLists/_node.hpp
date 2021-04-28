#ifndef _NODE_HPP
#define _NODE_HPP
#pragma once

#include <algorithm>
#include <iostream>
#include <initializer_list>

/** @brief Linkedlist node-class declaration file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Structures::LinkedLists {

	template<typename T>
	class Node ;
	
	template<class T>
	class Node {
		/** This class is the Linkedlist-node implementation **/
		private:
			Node* prev ; //pointer to prev element in LL

			Node* next ; //pointer to next element in LL
					
			static void appendNode(Node*&, Node*&) ; //static method actually finds slot and appends b to a's LL
			
		        static Node* getHead(Node*) ; // returns pointer of the head of the linked list current node is pointed to
		        
		        static Node* getTail(Node*) ; // returns pointer of the tail of the linked list current node is pointed to
					
		public:
			T data ; //template variable for data		
		
			/** Regular constructor, intialises node with a given value
			@param value (to set for node) 
			@return <initialised-object> **/
			Node(T) ; //constructor - takes data
			
			/** Copy constructor, creates independant copy of a given node
			@param a (l-value) node object
			@return <initialised-object> **/	
			Node(const Node&) ; //copy constructor - copies data and removes head and tail
			
			/** Copy assignment operator, creates independant copy of a given node
			@param a (l-value) node object
			@return reference to current node object **/	
			Node& operator=(const Node&) ; //copy constructor - copies data and removes head and tail
			
			Node(T, Node&, bool) ; //constructor - takes data, node to connect to, specify direction (prev or next)
		
			Node(T, Node&, Node&) ; //constructor - takes data, prev node to connect to, next node to connect to
	
			//const Node*& getPrev() const ; //gets prev node in LL

			Node*& getPrev() ; //gets prev node in LL
		
			void setPrev(Node*&) ; //sets prev node in LL
			
			//const Node*& getNext() const ; //returns next node in LL

			Node*& getNext() ; //returns next node in LL

			void setNext(Node*&) ; //sets next node in LL

			void deleteNode() ; //connects previous and next node to each other, deletes data
			
			void appendNode(Node&) ; //method to append a to the object node

			static void appendNode(Node&, Node&) ; //static method to append b to the tree of a
		        
		        static int size(Node&) ; //calculate size of the LL a given node is connected to
		        
		        static Node* getHead(Node&) ; // returns pointer of the head of the linked list current node is pointed to
		        
		        static Node* getTail(Node&) ; // returns pointer of the tail of the linked list current node is pointed to

	} ;	
}

#include "_node.tpp"

#endif
