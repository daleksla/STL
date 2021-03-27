#ifndef QUEUE_HPP
#define QUEUE_HPP
#pragma once

#include "../Structures/LinkedLists/node.hpp"
#include <algorithm>
#include <iterator>
#include <limits>
#include <initializer_list>

/* This file contains the declarations and implementations of a Queue-based structure
 * The data is stored and maintained using a linked-list structure */

namespace Salih::Types {
	template<class T>
	class Queue {
		private:
			Salih::Structures::LinkedLists::Node<T>* head ;
			
			Salih::Structures::LinkedLists::Node<T>* tail ;
			
			int size ;
		public:
			Queue() ;
			
			Queue(const std::initializer_list<T>&) ;
			
			Queue& operator=(const std::initializer_list<T>&) ;
			
			Queue(const Queue<T>&) ;
			
			Queue& operator=(const Queue<T>&) ;
			
			Queue(Queue<T>&&) ;
			
			Queue& operator=(Queue<T>&&) ;
			
			bool operator==(const Queue<T>&) const ;
			
			bool operator!=(const Queue<T>&) const ;
			
			template<typename OTHER>
			bool operator==(const Queue<OTHER>&) const ;
			
			template<typename OTHER>
			bool operator!=(const Queue<OTHER>&) const ;
			
			~Queue() ;
			
			T pop() ;
			
			const T& peek() const ;
			
			void push(T) ;
			
			void push(const std::initializer_list<T>&) ;
			
			template<typename OTHER>
    			friend class Queue ;
	} ;
}

template <typename T>
Salih::Types::Queue<T>::Queue()
{
	this->size = 0 ;
	this->head = nullptr ;
	this->tail = nullptr ;
}

template <typename T>
Salih::Types::Queue<T>::Queue(const std::initializer_list<T>& values)
{
	this->size = 0 ;
	this->head = new Salih::Structures::LinkedLists::Node<T>(*std::begin(values)) ;
	Salih::Structures::LinkedLists::Node<T>* p = head ;
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
Salih::Types::Queue<T>& Salih::Types::Queue<T>::operator=(const std::initializer_list<T>& values)
{
	if(head != nullptr)
	{
		for(Salih::Structures::LinkedLists::Node<T>* node = head ; ;)
		{
			Salih::Structures::LinkedLists::Node<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	}
	
	this->size = 0 ;
	this->head = new Salih::Structures::LinkedLists::Node<T>(*std::begin(values)) ;
	Salih::Structures::LinkedLists::Node<T>* p = head ;
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
Salih::Types::Queue<T>::Queue(const Queue& q)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* h = q.head ;
	Salih::Structures::LinkedLists::Node<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			this->head = new Salih::Structures::LinkedLists::Node<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			this->tail = new Salih::Structures::LinkedLists::Node<T>(h->data, *p, 0) ;
		}
		else {
			p = new Salih::Structures::LinkedLists::Node<T>(h->data, *p, 0) ;
		}
		h = h->getNext() ;
		this->size = this->size + 1 ;	
	}
}

template <typename T>
Salih::Types::Queue<T>& Salih::Types::Queue<T>::operator=(const Queue& q)
{
	//if(this->head != nullptr)
	//{
	//	for(Salih::Structures::LinkedLists::Node<T>* node = this->head ; ;)
	//	{
	//		Salih::Structures::LinkedLists::Node<T>* mem = node->getNext() ;
	//		delete node ;
	//		if(mem == nullptr) break ;
	//		node = mem ;
	//	}
	//}
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* h = q.head ;
	Salih::Structures::LinkedLists::Node<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			this->head = new Salih::Structures::LinkedLists::Node<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			this->tail = new Salih::Structures::LinkedLists::Node<T>(h->data, *p, 0) ;
		}
		else {
			p = new Salih::Structures::LinkedLists::Node<T>(h->data, *p, 0) ;
		}
		h = h->getNext() ;
		this->size = this->size + 1 ;	
	}
	return *this ;
}

template <typename T>
Salih::Types::Queue<T>::Queue(Queue&& q)
{
	this->head = q.head ;
	this->tail = q.tail ;
	this->size = q.size ;
	q.head = nullptr ;
	q.tail = nullptr ;
	q.size = 0 ;
}

template <typename T>
Salih::Types::Queue<T>& Salih::Types::Queue<T>::operator=( Queue&& q ) 
{
	this->head = q.head ;
	this->tail = q.tail ;
	this->size = q.size ;
	q.head = nullptr ;
	q.tail = nullptr ;
	q.size = 0 ;
	return *this ;
}

template <typename T>
bool Salih::Types::Queue<T>::operator==(const Salih::Types::Queue<T>& qq) const
{
	if(this->size != qq.size) return false ;
	
	auto node1 = this->head ;
	auto node2 = qq.head ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return false ;
		node1 = node1->getNext() ;
		node2 = node2->getNext() ;
	}
	
	return true ;
}

template <typename T>			
bool Salih::Types::Queue<T>::operator!=(const Salih::Types::Queue<T>& qq) const
{
	if(this->size != qq.size) return true ;
	
	auto node1 = this->head ;
	auto node2 = qq.head ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return true ;
		node1 = node1->getNext() ;
		node2 = node2->getNext() ;
	}
	
	return false ;
}

template <typename T>			
template<typename OTHER>
bool Salih::Types::Queue<T>::operator==(const Salih::Types::Queue<OTHER>& qq) const
{
	if(this->size != qq.size) return false ;
	
	auto node1 = this->head ;
	auto node2 = qq.head ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return false ;
		node1 = node1->getNext() ;
		node2 = node2->getNext() ;
	}
	
	return true ;
}
		
template <typename T>	
template<typename OTHER>
bool Salih::Types::Queue<T>::operator!=(const Salih::Types::Queue<OTHER>& qq) const
{
	if(this->size != qq.size) return true ;
	
	auto node1 = this->head ;
	auto node2 = qq.head ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return true ;
		node1 = node1->getNext() ;
		node2 = node2->getNext() ;
	}
	
	return false ;
}

template <typename T>
Salih::Types::Queue<T>::~Queue()
{
	if(head == nullptr) return;
	
	for(Salih::Structures::LinkedLists::Node<T>* node = head ; ;)
	{
		Salih::Structures::LinkedLists::Node<T>* mem = node->getNext() ;
		delete node ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
}

template <typename T>
T Salih::Types::Queue<T>::pop()
{
	if(size == 0) throw std::out_of_range("Queue is empty") ;
	auto newHead = head->getNext() ;
	auto data = head->data ;
	delete head ;
	head = newHead ;
	size -= 1 ;
	return data ;
}

template <typename T>
const T& Salih::Types::Queue<T>::peek() const
{
	if(size != 0) return head->data ;
	else throw std::out_of_range("Queue is empty") ;
}

template <typename T>
void Salih::Types::Queue<T>::push(T val)
{
	Salih::Structures::LinkedLists::Node<T>* p ;
	if(size == 0)
	{
		p = new Salih::Structures::LinkedLists::Node<T>(val) ;
		head = p ;
	}
	else {
		p = new Salih::Structures::LinkedLists::Node<T>(val, *tail, 0) ;	
	}
	tail = p ;
	size += 1 ;
}

template <typename T>
void Salih::Types::Queue<T>::push(const std::initializer_list<T>& values)
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
