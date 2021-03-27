#ifndef STACK_HPP
#define STACK_HPP
#pragma once

#include "../Structures/LinkedLists/node.hpp"
#include <algorithm>
#include <iterator>
#include <initializer_list>

/* This file contains the declarations and implementations of a Stack-based structure
 * The data is stored and maintained using a linked-list structure */

namespace Salih::Types {

	template<typename T>
	class Stack ;
	
	template<class T>
	class Stack {
		private:
			Salih::Structures::LinkedLists::Node<T>* tail ;
			
			int size ;
		public:
			Stack() ;
			
			Stack(const std::initializer_list<T>&) ;
			
			Stack& operator=(const std::initializer_list<T>&) ;
			
			Stack(const Stack&) ;
			
			Stack& operator=(const Stack&) ;
			
			Stack(Stack&&) ;
			
			Stack& operator=(Stack&&) ;
			
			bool operator==(const Stack<T>&) const ;
			
			bool operator!=(const Stack<T>&) const ;
			
			template<typename OTHER>
			bool operator==(const Stack<OTHER>&) const ;
			
			template<typename OTHER>
			bool operator!=(const Stack<OTHER>&) const ;
			
			~Stack() ;
			
			T pop() ;
			
			const T& peek() const ;
			
			void push(T) ;
			
			void push(const std::initializer_list<T>&) ;
			
			template<typename OTHER>
			friend class Stack ;
	} ;
}

template <typename T>
Salih::Types::Stack<T>::Stack()
{
	this->size = 0 ;
	this->tail = NULL ;
}

template <typename T>
Salih::Types::Stack<T>::Stack(const std::initializer_list<T>& values)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* p = new Salih::Structures::LinkedLists::Node<T>(*std::begin(values)) ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new Salih::Structures::LinkedLists::Node<T>(*it, *p, 0) ;
		} else {
			p = new Salih::Structures::LinkedLists::Node<T>(*it, *p, 0) ;
		}
		this->size = size + 1 ;	
	}
}

template <typename T>
Salih::Types::Stack<T>& Salih::Types::Stack<T>::operator=(const std::initializer_list<T>& values)
{
	if(this->size != 0)
	{
		for(Salih::Structures::LinkedLists::Node<T>* node = tail ; ;)
		{
			Salih::Structures::LinkedLists::Node<T>* mem = node->getPrev() ;
			delete node ;
			if(mem == NULL) break ;
			node = mem ;
		} 
	}
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* p = new Salih::Structures::LinkedLists::Node<T>(*std::begin(values)) ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new Salih::Structures::LinkedLists::Node<T>(*it, *p, 0) ;
		} else {
			p = new Salih::Structures::LinkedLists::Node<T>(*it, *p, 0) ;
		}
		this->size = size + 1 ;	
	}
	return *this ;
}

template <typename T>
Salih::Types::Stack<T>::Stack(const Salih::Types::Stack<T>& stck)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* node = stck.tail ;
	for(; ;)
	{
		Salih::Structures::LinkedLists::Node<T>* mem = node->getPrev() ;
		if(mem == NULL) break ;
		node = mem ;
	} 
	while(node != NULL) 
	{
		this->push(node->data) ;	
		node = node->getNext() ;
	}
}
			
template <typename T>
Salih::Types::Stack<T>& Salih::Types::Stack<T>::operator=(const Salih::Types::Stack<T>& stck) 
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* node = stck.tail ;
	for(; ;)
	{
		Salih::Structures::LinkedLists::Node<T>* mem = node->getPrev() ;
		if(mem == NULL) break ;
		node = mem ;
	} 
	while(node != NULL) 
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
	stck.tail = NULL ;
}
			
template <typename T>
Salih::Types::Stack<T>& Salih::Types::Stack<T>::operator=(Salih::Types::Stack<T>&& stck)
{
	this->size = stck.size ;
	this->tail = stck.tail ;
	stck.size = 0 ;
	stck.tail = NULL ;
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
	
	for(Salih::Structures::LinkedLists::Node<T>* node = tail ; ;)
	{
		Salih::Structures::LinkedLists::Node<T>* mem = node->getPrev() ;
		delete node ;
		if(mem == NULL) break ;
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
	Salih::Structures::LinkedLists::Node<T>* p ;
	if(size == 0) p = new Salih::Structures::LinkedLists::Node<T>(val) ;
	else p = new Salih::Structures::LinkedLists::Node<T>(val, *tail, 0) ;
	tail = p ;
	size += 1 ;
}

template <typename T>
void Salih::Types::Stack<T>::push(const std::initializer_list<T>& values)
{
	Salih::Structures::LinkedLists::Node<T>* p = tail ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new Salih::Structures::LinkedLists::Node<T>(*it, *p, 0) ;
		} else {
			p = new Salih::Structures::LinkedLists::Node<T>(*it, *p, 0) ;
		}
		size += 1 ;	
	}
	tail = p ;
}

#endif
