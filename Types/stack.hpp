#ifndef STACK_HPP
#define STACK_HPP
#pragma once

#include "../Structures/LinkedLists/_dNode.hpp"
#include <algorithm>
#include <iterator>
#include <initializer_list>

/** @brief Stack-class implementation file, representing the LIFO abstract data type
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Types {
	
	template<class T>
	class Stack {
		/** This class is the LIFO (Stack) implementation **/
		private:
			Salih::Structures::LinkedLists::DNode<T>* tail ;
			
			std::size_t size ;
		public:
			/** Empty constructor, intialises empty stack 
			@return <initialised-object> **/
			Stack() ;
			
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for stack)
			@return <initialised-object> **/		
			Stack(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, re-assigns values to stack (last element provided becomes tail, etc.)
			@param initialisation list (of values for stack)
			@return reference to current object **/
			Stack& operator=(const std::initializer_list<T>&) ;
			
			/** Copy assignment operator, creates copy of a given stack
			@param a (l-value) stack object
			@return <initialised-object> **/
			Stack(const Stack&) ;
			
			/** Copy assignment operator, creates copy of a given stack
			@param a (l-value) stack object
			@return reference to current object **/
			Stack& operator=(const Stack&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary stack object
			@param an r-value stack object
			@return <initialised-object> **/
			Stack(Stack&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary stack object
			@param an (r-value) stack object
			@return reference to current object **/
			Stack& operator=(Stack&&) ;
			
			/** Comparison operator, determines calling stack object content matches with a given stack object
			@param stack object
			@return a boolean representing whether equality is met **/ 	
			bool operator==(const Stack<T>&) const ;
			
			/** Inequality operator, determines calling stack object content does not match with a given stack object
			@param stack object
			@return a boolean representing whether equality is not met **/ 
			bool operator!=(const Stack<T>&) const ;
			
			/** Comparison operator, determines calling stack object content matches with a given stack object
			@param stack object (which contains different type values)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			bool operator==(const Stack<OTHER>&) const ;

			/** Inequality operator, determines calling stack object content does not match with a given stack object
			@param stack object (which contains different type values)
			@return a boolean representing whether equality is not met **/ 
			template<typename OTHER>
			bool operator!=(const Stack<OTHER>&) const ;
			
			~Stack() ;
			
			/** pop method, removes newest / latest added value from the stack
			@return value (of removed data object) **/					
			T pop() ;
			
			/** peek method, shows newest / latest added value to the stack
			@return constant reference to value (of latest added / newest data object) **/
			const T& peek() const ;
			
			/** push method, adds a value to the end of the stack type
			@param value (to add) **/
			void push(T) ;
			
			/** push method, adds a value to the top of the queue type
			@param initialisation list (of values to add) **/	
			void push(const std::initializer_list<T>&) ;
			
			template<typename OTHER>
			friend class Stack ;
	} ;
}

template <typename T>
Salih::Types::Stack<T>::Stack()
{
	this->size = 0 ;
	this->tail = nullptr ;
}

template <typename T>
Salih::Types::Stack<T>::Stack(const std::initializer_list<T>& values)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::DNode<T>* p = new Salih::Structures::LinkedLists::DNode<T>(*std::begin(values)) ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new Salih::Structures::LinkedLists::DNode<T>(*it, p, 0) ;
		} else {
			p = new Salih::Structures::LinkedLists::DNode<T>(*it, p, 0) ;
		}
		this->size = size + 1 ;	
	}
}

template <typename T>
Salih::Types::Stack<T>& Salih::Types::Stack<T>::operator=(const std::initializer_list<T>& values)
{
	if(this->size != 0)
	{
		for(Salih::Structures::LinkedLists::DNode<T>* node = tail ; ;)
		{
			Salih::Structures::LinkedLists::DNode<T>* mem = node->getPrev() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		} 
	}
	this->size = 0 ;
	Salih::Structures::LinkedLists::DNode<T>* p = new Salih::Structures::LinkedLists::DNode<T>(*std::begin(values)) ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new Salih::Structures::LinkedLists::DNode<T>(*it, p, 0) ;
		} else {
			p = new Salih::Structures::LinkedLists::DNode<T>(*it, p, 0) ;
		}
		this->size = size + 1 ;	
	}
	return *this ;
}

template <typename T>
Salih::Types::Stack<T>::Stack(const Salih::Types::Stack<T>& stck)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::DNode<T>* node = stck.tail ;
	for(; ;)
	{
		Salih::Structures::LinkedLists::DNode<T>* mem = node->getPrev() ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
	while(node != nullptr) 
	{
		this->push(node->data) ;	
		node = node->getNext() ;
	}
}
			
template <typename T>
Salih::Types::Stack<T>& Salih::Types::Stack<T>::operator=(const Salih::Types::Stack<T>& stck) 
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::DNode<T>* node = stck.tail ;
	for(; ;)
	{
		Salih::Structures::LinkedLists::DNode<T>* mem = node->getPrev() ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
	while(node != nullptr) 
	{
		this->push(node->data) ;	
		node = node->getNext() ;
	}
	return *this ;
}
			
template <typename T>
Salih::Types::Stack<T>::Stack(Salih::Types::Stack<T>&& stck)
{
	this->size = stck.size ;
	this->tail = stck.tail ;
	stck.size = 0 ;
	stck.tail = nullptr ;
}
			
template <typename T>
Salih::Types::Stack<T>& Salih::Types::Stack<T>::operator=(Salih::Types::Stack<T>&& stck)
{
	this->size = stck.size ;
	this->tail = stck.tail ;
	stck.size = 0 ;
	stck.tail = nullptr ;
	return *this ;
}

template <typename T>
bool Salih::Types::Stack<T>::operator==(const Salih::Types::Stack<T>& qq) const
{
	if(this->size != qq.size) return false ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return false ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return true ;
}

template <typename T>			
bool Salih::Types::Stack<T>::operator!=(const Salih::Types::Stack<T>& qq) const
{
	if(this->size != qq.size) return true ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return true ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return false ;
}

template <typename T>	
template<typename OTHER>
bool Salih::Types::Stack<T>::operator==(const Salih::Types::Stack<OTHER>& qq) const
{
	if(this->size != qq.size) return false ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return false ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return true ;
}
		
template <typename T>	
template <typename OTHER>
bool Salih::Types::Stack<T>::operator!=(const Salih::Types::Stack<OTHER>& qq) const
{
	if(this->size != qq.size) return true ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return true ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return false ;
}

template <typename T>
Salih::Types::Stack<T>::~Stack()
{
	if(size == 0) return;
	
	for(Salih::Structures::LinkedLists::DNode<T>* node = tail ; ;)
	{
		Salih::Structures::LinkedLists::DNode<T>* mem = node->getPrev() ;
		delete node ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
}

template <typename T>
T Salih::Types::Stack<T>::pop()
{
	if(size == 0) throw std::out_of_range("Stack is empty") ;
	auto newTail = tail->getPrev() ;
	auto data = tail->data ;
	delete tail ;
	tail = newTail ;
	size -= 1 ;
	return data ;
}

template <typename T>
const T& Salih::Types::Stack<T>::peek() const
{
	if(size != 0) return tail->data ;
	else throw std::out_of_range("Stack is empty") ;
}

template <typename T>
void Salih::Types::Stack<T>::push(T val)
{
	Salih::Structures::LinkedLists::DNode<T>* p ;
	if(size == 0) p = new Salih::Structures::LinkedLists::DNode<T>(val) ;
	else p = new Salih::Structures::LinkedLists::DNode<T>(val, tail, 0) ;
	tail = p ;
	size += 1 ;
}

template <typename T>
void Salih::Types::Stack<T>::push(const std::initializer_list<T>& values)
{
	Salih::Structures::LinkedLists::DNode<T>* p = tail ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new Salih::Structures::LinkedLists::DNode<T>(*it, p, 0) ;
		} else {
			p = new Salih::Structures::LinkedLists::DNode<T>(*it, p, 0) ;
		}
		size += 1 ;	
	}
	tail = p ;
}

#endif
