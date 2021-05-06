#ifndef _SNODE_HPP
#define _SNODE_HPP
#pragma once

#include <algorithm>
#include <iostream>
#include <initializer_list>

namespace Salih::Structures::LinkedLists {

	template<typename T>
	class SNode ;
	
	template<class T>
	class SNode {
		/** This class is the Node (singly linkedlist)-class implementation **/
		private:
			SNode* next ; //pointer to prev element in LL
					
		public:
			T data ; //template variable for data		
		
			SNode(T) ; //constructor - takes data
			
			SNode(const SNode&) ; //copy constructor - copies data and removes links
			
			SNode& operator=(const SNode&) ; //copy constructor - copies data and removes links
			
			SNode(T, SNode&) ; //constructor - takes data, (prev) node to connect to
		
			SNode*& getNext() ; //returns next node in LL

			void setNext(SNode*&) ; //sets next node in LL

	} ;	
}

#include "_sNode.tpp"

#endif
