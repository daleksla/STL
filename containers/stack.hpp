#ifndef STACK_HPP
#define STACK_HPP
#pragma once

#include "d-node.hpp"
#include <initializer_list>

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
			/** Empty constructor, intialises empty stack 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR Stack() ;
			
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for stack)
			@return <initialised-object> **/		
			_GLIBCXX20_CONSTEXPR Stack(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, re-assigns values to stack (last element provided becomes tail, etc.)
			@param initialisation list (of values for stack)
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR Stack& operator=(const std::initializer_list<T>&) ;
			
			/** Copy assignment operator, creates copy of a given stack
			@param a (l-value) stack object
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR Stack(const Stack&) ;
			
			/** Copy assignment operator, creates copy of a given stack
			@param a (l-value) stack object
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR Stack& operator=(const Stack&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary stack object
			@param an r-value stack object
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR Stack(Stack&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary stack object
			@param an (r-value) stack object
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR Stack& operator=(Stack&&) ;
			
			/** Comparison operator, determines calling stack object content matches with a given stack object
			@param stack object
			@return a boolean representing whether equality is met **/ 	
			_GLIBCXX20_CONSTEXPR bool operator==(const Stack<T>&) const ;
			
			/** Inequality operator, determines calling stack object content does not match with a given stack object
			@param stack object
			@return a boolean representing whether equality is not met **/ 
			_GLIBCXX20_CONSTEXPR bool operator!=(const Stack<T>&) const ;
			
			/** Comparison operator, determines calling stack object content matches with a given stack object
			@param stack object (which contains different type values)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			_GLIBCXX20_CONSTEXPR bool operator==(const Stack<OTHER>&) const ;

			/** Inequality operator, determines calling stack object content does not match with a given stack object
			@param stack object (which contains different type values)
			@return a boolean representing whether equality is not met **/ 
			template<typename OTHER>
			_GLIBCXX20_CONSTEXPR bool operator!=(const Stack<OTHER>&) const ;
			
			_GLIBCXX20_CONSTEXPR ~Stack() ;
			
			/** pop method, removes newest / latest added value from the stack
			@return value (of removed data object) **/					
			_GLIBCXX20_CONSTEXPR T pop() ;
			
			/** peek method, shows newest / latest added value to the stack
			@return constant reference to value (of latest added / newest data object) **/
			_GLIBCXX20_CONSTEXPR const T& peek() const ;
			
			/** push method, adds a value to the end of the stack type
			@param value (to add) **/
			_GLIBCXX20_CONSTEXPR void push(T) ;
			
			/** push method, adds a value to the top of the queue type
			@param initialisation list (of values to add) **/	
			_GLIBCXX20_CONSTEXPR void push(const std::initializer_list<T>&) ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			_GLIBCXX20_CONSTEXPR std::size_t getSize() ;
			
			template<typename OTHER>
			friend class Stack ;
	} ;

}
}

#include "stack.tpp"

#endif
