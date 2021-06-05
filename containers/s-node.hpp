#ifndef S_NODE_HPP
#define S_NODE_HPP
#pragma once

namespace salih {
namespace containers {

	template<typename T>
	class SNode ;
	
	template<class T>
	class SNode {
		/** This class is the Node (singly linkedlist)-class implementation **/
		private:
			SNode* next ; //pointer to prev element in LL
					
		public:
			T data ; //template variable for data		
			
			SNode() = default ;
		
			_GLIBCXX20_CONSTEXPR SNode(const T) ; //constructor - takes data
			
			_GLIBCXX20_CONSTEXPR SNode(const T, SNode*) ;
			
			_GLIBCXX20_CONSTEXPR SNode(const SNode&) = delete ;
			
			_GLIBCXX20_CONSTEXPR SNode& operator=(const SNode&) = delete ;
		
			_GLIBCXX20_CONSTEXPR SNode(SNode&&) = default ;
			
			_GLIBCXX20_CONSTEXPR SNode& operator=(SNode&&) = default ;
		
			_GLIBCXX20_CONSTEXPR SNode* getNext() ; //returns next node in LL
		
			_GLIBCXX20_CONSTEXPR const SNode* getNext() const ; //returns next node in LL

			_GLIBCXX20_CONSTEXPR void setNext(SNode*) ; //sets next node in LL

	} ;
		
}
}

#include "s-node.tpp"

#endif
