#ifndef S_NODE_HPP
#define S_NODE_HPP
#pragma once

#include "../types/macros.hpp"

/** @brief Singly Linkedlist nodes
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

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
		
			CONSTEXPRCXX14 SNode(const T) ; //constructor - takes data
			
			CONSTEXPRCXX14 SNode(const T, SNode*) ;
			
			CONSTEXPRCXX14 SNode(const SNode&) = delete ;
			
			CONSTEXPRCXX14 SNode& operator=(const SNode&) = delete ;
		
			CONSTEXPRCXX14 SNode(SNode&&) = default ;
			
			CONSTEXPRCXX14 SNode& operator=(SNode&&) = default ;
		
			CONSTEXPRCXX14 SNode* getNext() ; //returns next node in LL
		
			CONSTEXPRCXX14 const SNode* getNext() const ; //returns next node in LL

			CONSTEXPRCXX14 void setNext(SNode*) ; //sets next node in LL

	} ;
		
}
}

#include "s-node.tpp"

#endif
