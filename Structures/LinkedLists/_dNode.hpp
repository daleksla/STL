#ifndef _DNODE_HPP
#define _DNODE_HPP
#pragma once

#include <algorithm>
#include <iostream>
#include <initializer_list>

namespace Salih::Structures::LinkedLists {

	template<typename T>
	class DNode ;
	
	template<class T>
	class DNode {
		/** This class is the Node (doubly linkedlist)-class implementation **/
		private:
			DNode* prev ; //pointer to prev element in LL

			DNode* next ; //pointer to next element in LL
					
		public:
			T data ; //template variable for data		
		
			DNode(T) ; //constructor - takes data
			
			DNode(const DNode&) ; //copy constructor - copies data and removes head and tail
			
			DNode& operator=(const DNode&) ; //copy constructor - copies data and removes head and tail
			
			DNode(T, DNode*, bool) ; //constructor - takes data, connects to specified node

			DNode* getPrev() ; //gets prev node in LL

			const DNode* getPrev() const ; //gets prev node in LL
		
			void setPrev(DNode*) ; //sets prev node in LL

			DNode* getNext() ; //returns next node in LL
			
			const DNode* getNext() const ; //returns next node in LL

			void setNext(DNode*) ; //sets next node in LL

	} ;	
}

#include "_dNode.tpp"

#endif
