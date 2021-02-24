#ifndef GRAPH_HPP
#define GRAPH_HPP
#pragma once

#include <iostream>
#include <tuple>
#include <type_traits>
#include <lib/Structures/LinkedLists/linkedlist.hpp>
#include <iterator>
#include <algorithm>
#include <initializer_list>

/* This file contains the declarations of a Graph data-structure
 * It is flexible and allows for custom-vertex labelling (name, number, etc.) as-well as choosing whether a path is directed or weighted, assuming values if not provided 
 * It also features an adjacency matrix, allowing one to see the structure of their Graph */

namespace Salih::Structures::Graphs {
	template<typename T>
	class Graph {
		private:
			bool directed ;
			
			bool weighted ;
			
			Salih::Structures::LinkedLists::LinkedList<T> vertices ;
			
			template<typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, U>::type>>
			std::tuple<T, T, U> edges ;
			
			bool isEdge(const T&, const T&) ;
		public:
			//constructor(s) need to be implemented
	
			bool addVertex(T) ;
			
			template<typename U, typename = typename std::enable_if<std::is_arithmetic<U>::value, U>::type>>
			bool addEdge(T, T, U, bool) ; //assume U (weight) to be 0, assume bool to be false (directed or not)
			
			bool removeEdge(T, T) ;
			
			void displayGraph() ;
	} ;
}

#include "graph.tpp"

#endif
