#ifndef STACK_HPP
#define STACK_HPP
#pragma once

#include "d-node.hpp"
#include <initializer_list>
#include "../types/macros.hpp"

/** @brief Stack-class implementation file, representing the LIFO abstract data type
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace salih {
namespace containers {
	
	template<class T>
	class Stack {
		/** This class is the LIFO (Stack) implementation **/
		private:
			salih::containers::DNode<T>* tail ;
			
			std::size_t size ;
		public:
			using inner = T ;
		
			/** Empty constructor, intialises empty stack 
			@return <initialised-object> **/
			CONSTEXPRCXX20 Stack() ;
			
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for stack)
			@return <initialised-object> **/		
			CONSTEXPRCXX20 Stack(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, re-assigns values to stack (last element provided becomes tail, etc.)
			@param initialisation list (of values for stack)
			@return reference to current object **/
			CONSTEXPRCXX20 Stack& operator=(const std::initializer_list<T>&) ;
			
			/** Copy assignment operator, creates copy of a given stack
			@param a (l-value) stack object
			@return <initialised-object> **/
			CONSTEXPRCXX20 Stack(const Stack&) ;
			
			/** Copy assignment operator, creates copy of a given stack
			@param a (l-value) stack object
			@return reference to current object **/
			CONSTEXPRCXX20 Stack& operator=(const Stack&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary stack object
			@param an r-value stack object
			@return <initialised-object> **/
			CONSTEXPRCXX20 Stack(Stack&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary stack object
			@param an (r-value) stack object
			@return reference to current object **/
			CONSTEXPRCXX20 Stack& operator=(Stack&&) ;
			
			/** Comparison operator, determines calling stack object content matches with a given stack object
			@param stack object
			@return a boolean representing whether equality is met **/ 	
			CONSTEXPRCXX20 bool operator==(const Stack<T>&) const ;
			
			/** Inequality operator, determines calling stack object content does not match with a given stack object
			@param stack object
			@return a boolean representing whether equality is not met **/ 
			CONSTEXPRCXX20 bool operator!=(const Stack<T>&) const ;
			
			/** Comparison operator, determines calling stack object content matches with a given stack object
			@param stack object (which contains different type values)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			CONSTEXPRCXX20 bool operator==(const Stack<OTHER>&) const ;

			/** Inequality operator, determines calling stack object content does not match with a given stack object
			@param stack object (which contains different type values)
			@return a boolean representing whether equality is not met **/ 
			template<typename OTHER>
			CONSTEXPRCXX20 bool operator!=(const Stack<OTHER>&) const ;
			
			CONSTEXPRCXX20 ~Stack() ;
			
			/** pop method, removes newest / latest added value from the stack
			@return value (of removed data object) **/					
			CONSTEXPRCXX20 T pop() ;
			
			/** peek method, shows newest / latest added value to the stack
			@return constant reference to value (of latest added / newest data object) **/
			CONSTEXPRCXX20 const T& peek() const ;
			
			/** push method, adds a value to the end of the stack type
			@param value (to add) **/
			CONSTEXPRCXX20 void push(T) ;
			
			/** push method, adds a value to the top of the queue type
			@param initialisation list (of values to add) **/	
			CONSTEXPRCXX20 void push(const std::initializer_list<T>&) ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			CONSTEXPRCXX20 std::size_t getSize() ;
			
			template<typename OTHER>
			friend class Stack ;
	} ;

}
}

#include "stack.tpp"

#endif
