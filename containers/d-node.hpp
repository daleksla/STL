#ifndef D_NODE_HPP
#define D_NODE_HPP
#pragma once

#include "../types/macros.hpp"

namespace salih {
namespace containers {

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

			CONSTEXPRCXX14 DNode() = default ;
		
			CONSTEXPRCXX14 DNode(const T) ; //constructor - takes data
			
			CONSTEXPRCXX14 DNode(const DNode&) = delete ;
			
			CONSTEXPRCXX14 DNode& operator=(const DNode&) = delete ;
			
			CONSTEXPRCXX14 DNode(DNode&&) = default ;
			
			CONSTEXPRCXX14 DNode& operator=(DNode&&) = default ;
			
			CONSTEXPRCXX14 DNode(const T, DNode*, const bool) ; //constructor - takes data, connects to specified node

			CONSTEXPRCXX14 DNode* getPrev() ; //gets prev node in LL

			CONSTEXPRCXX14 const DNode* getPrev() const ; //gets prev node in LL
		
			CONSTEXPRCXX14 void setPrev(DNode*) ; //sets prev node in LL

			CONSTEXPRCXX14 DNode* getNext() ; //returns next node in LL
			
			CONSTEXPRCXX14 const DNode* getNext() const ; //returns next node in LL

			CONSTEXPRCXX14 void setNext(DNode*) ; //sets next node in LL

	} ;	
	
}
}

#include "d-node.tpp"

#endif
