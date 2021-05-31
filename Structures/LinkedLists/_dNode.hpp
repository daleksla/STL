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
			
			_GLIBCXX20_CONSTEXPR DNode() = default ;
		
			_GLIBCXX20_CONSTEXPR DNode(const T) ; //constructor - takes data
			
			_GLIBCXX20_CONSTEXPR DNode(const DNode&) = delete ;
			
			_GLIBCXX20_CONSTEXPR DNode& operator=(const DNode&) = delete ;
			
			_GLIBCXX20_CONSTEXPR DNode(DNode&&) = default ;
			
			_GLIBCXX20_CONSTEXPR DNode& operator=(DNode&&) = default ;
			
			_GLIBCXX20_CONSTEXPR DNode(const T, DNode*, const bool) ; //constructor - takes data, connects to specified node

			_GLIBCXX20_CONSTEXPR DNode* getPrev() ; //gets prev node in LL

			_GLIBCXX20_CONSTEXPR const DNode* getPrev() const ; //gets prev node in LL
		
			_GLIBCXX20_CONSTEXPR void setPrev(DNode*) ; //sets prev node in LL

			_GLIBCXX20_CONSTEXPR DNode* getNext() ; //returns next node in LL
			
			_GLIBCXX20_CONSTEXPR const DNode* getNext() const ; //returns next node in LL

			_GLIBCXX20_CONSTEXPR void setNext(DNode*) ; //sets next node in LL

	} ;	
}

#include "_dNode.tpp"

#endif
