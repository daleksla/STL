#ifndef TRAITS_HPP
#define TRAITS_HPP
#pragma once

#include "string.hpp"
#include "Buffers/queue.hpp"
#include "Buffers/stack.hpp"
#include "../Structures/Contiguous/vector.hpp"
#include "../Structures/Contiguous/array.hpp"
#include "../Structures/LinkedLists/list.hpp"
#include "../Structures/LinkedLists/fwdList.hpp"

namespace Salih::Types::Traits {

	// base types - true or false
	struct falseType {
		static constexpr bool value = false ;
	} ;
	
	struct trueType {
		static constexpr bool value = true ;
	} ;

	//isSame
	template<typename T, typename U> //generic, false same
	struct isSame : falseType {} ; 

	template<typename T> //specialised where both inputs are of type-T, true same
	struct isSame<T,T> : trueType {} ;

	//isList
	template<typename T> // generic, false list
	struct isList : falseType {} ;

	template<> // specialised for string, true list
	struct isList< Salih::Types::String > : trueType {} ;

	template<typename T> // specialised for vectors, true list 
	struct isList< Salih::Structures::Contiguous::Vector<T> > : trueType {} ;

	template<typename T, std::size_t SIZE> // specialised for arrays, true list
	struct isList< Salih::Structures::Contiguous::Array<T, SIZE> > : trueType {} ;

	template<typename T> // specialised for linked lists, true list
	struct isList< Salih::Structures::LinkedLists::List<T> > : trueType {} ;
	
	template<typename T> // specialised for linked lists, true list
	struct isList< Salih::Structures::LinkedLists::FwdList<T> > : trueType {} ;

	//isContiguous (list)
	template<typename T> // generic, false contiguous (list)
	struct isContiguous : falseType {} ;
	
	template<> // specialised for string, true contiguous (list)
	struct isContiguous< Salih::Types::String > : trueType {} ;

	template<typename T> // specialised for vectors, true contiguous (list)
	struct isContiguous< Salih::Structures::Contiguous::Vector<T> > : trueType {} ;

	template<typename T, std::size_t SIZE> // specialised for arrays, true contiguous (list)
	struct isContiguous< Salih::Structures::Contiguous::Array<T,SIZE> > : trueType {} ;
	
	//isDynamic (list)
	template<typename T> // generic, false dynamic (list)
	struct isDynamic : falseType {} ;
	
	template<> // specialised for string, true dynamic (list)
	struct isDynamic< Salih::Types::String > : trueType {} ;

	template<typename T> // specialised for vectors, true dynamic (list)
	struct isDynamic< Salih::Structures::Contiguous::Vector<T> > : trueType {} ;
	
	template<typename T> // specialised for linked lists, true dynamic (list)
	struct isDynamic< Salih::Structures::LinkedLists::List<T> > : trueType {} ;
	
	template<typename T> // specialised for linked lists, true dynamic (list)
	struct isDynamic< Salih::Structures::LinkedLists::FwdList<T> > : trueType {} ;

	template<typename T> // specialised for queues, true dynamic (list)
	struct isDynamic< Salih::Types::Queue<T> > : trueType {} ;
	
	template<typename T> // specialised for stacks, true dynamic (list)
	struct isDynamic< Salih::Types::Stack<T> > : trueType {} ;
	
	//getDimensions
	template<typename T>
	struct getDimensions {
  		static constexpr size_t value = 0 ;
	} ;	

	template<typename T>
	struct getDimensions< Salih::Types::Queue<T> > {
		static constexpr size_t value = 1 + getDimensions<T>::value ;
	} ;
	
	template<typename T>
	struct getDimensions< Salih::Types::Stack<T> > {
		static constexpr size_t value = 1 + getDimensions<T>::value ;
	} ;
	
	template<>
	struct getDimensions< Salih::Types::String > {
		static constexpr size_t value = 1 ;
	} ;
			
	template<typename T>
	struct getDimensions< Salih::Structures::LinkedLists::List<T> > {
		static constexpr size_t value = 1 + getDimensions<T>::value ;
	} ;
	
	template<typename T>
	struct getDimensions< Salih::Structures::Contiguous::Vector<T> > {
		static constexpr size_t value = 1 + getDimensions<T>::value ;
	} ;
	
	template<typename T, std::size_t SIZE>
	struct getDimensions< Salih::Structures::Contiguous::Array<T, SIZE> > {
		static constexpr size_t value = 1 + getDimensions<T>::value ;
	} ;
	
	template<typename T>
	struct getDimensions< Salih::Structures::LinkedLists::FwdList<T> > {
		static constexpr size_t value = 1 + getDimensions<T>::value ;
	} ;
}

#endif
