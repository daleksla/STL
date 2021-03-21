#ifndef QUEUE_HPP
#define QUEUE_HPP
#pragma once

#include "../Structures/LinkedLists/node.hpp"
#include <algorithm>
#include <iterator>
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
			Queue(const Queue&) ;
			Queue& operator=(const Queue&) ;
			Queue(Queue&&) ;
			Queue& operator=(Queue&&) ;
			~Queue() ;
			T pop() ;
			const T& peek() const ;
			void push(T) ;
			void push(const std::initializer_list<T>&) ;
	} ;
}

template <typename T>
Salih::Types::Queue<T>::Queue()
{
	this->size = 0 ;
	this->head = NULL ;
	this->tail = NULL ;
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
Salih::Types::Queue<T>::Queue(const Queue& q)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* h = q.head ;
	Salih::Structures::LinkedLists::Node<T>* p = NULL ;
	while(h != NULL)
	{
		if(h->getPrev() == NULL) 
		{	
			head = new Salih::Structures::LinkedLists::Node<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == NULL)
		{
			tail = new Salih::Structures::LinkedLists::Node<T>(h->data, *p, 0) ;
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
	if(head != NULL)
	{
		for(Salih::Structures::LinkedLists::Node<T>* node = head ; ;)
		{
			Salih::Structures::LinkedLists::Node<T>* mem = node->getNext() ;
			delete node ;
			if(mem == NULL) break ;
			node = mem ;
		}
	} 
	
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* h = q.head ;
	Salih::Structures::LinkedLists::Node<T>* p = NULL ;
	while(h != NULL)
	{
		if(h->getPrev() == NULL) 
		{	
			head = new Salih::Structures::LinkedLists::Node<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == NULL)
		{
			tail = new Salih::Structures::LinkedLists::Node<T>(h->data, *p, 0) ;
		}
		else {
			p = new Salih::Structures::LinkedLists::Node<T>(h->data, *p, 0) ;
		}
		h = h->getNext() ;
		this->size = this->size + 1 ;	
	}
}

template <typename T>
Salih::Types::Queue<T>::Queue(Queue&& q)
{
	this->head = q.head ;
	this->tail = q.tail ;
	this->size = q.size ;
	q.head = NULL ;
	q.tail = NULL ;
}

template <typename T>
Salih::Types::Queue<T>& Salih::Types::Queue<T>::operator=(Queue&& q)
{
	if(q.head != NULL)
	{
		for(Salih::Structures::LinkedLists::Node<T>* node = q.head ; ;)
		{
			Salih::Structures::LinkedLists::Node<T>* mem = node->getNext() ;
			delete node ;
			if(mem == NULL) break ;
			node = mem ;
		}
	} 	
	this->head = q.head ;
	this->tail = q.tail ;
	this->size = q.size ;
	q.head = NULL ;
	q.tail = NULL ;
}

template <typename T>
Salih::Types::Queue<T>::~Queue()
{
	if(size == 0) return;
	
	for(Salih::Structures::LinkedLists::Node<T>* node = head ; ;)
	{
		Salih::Structures::LinkedLists::Node<T>* mem = node->getNext() ;
		delete node ;
		if(mem == NULL) break ;
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
