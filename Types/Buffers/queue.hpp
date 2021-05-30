#ifndef QUEUE_HPP
#define QUEUE_HPP
#pragma once

#include "../../Structures/LinkedLists/_dNode.hpp"
#include <algorithm>
#include <iterator>
#include <limits>
#include <initializer_list>

/** @brief Queue-class implementation file, representing the FIFO abstract data type
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Types::Buffers {

	template<class T>
	class Queue {
		/** This class is the FIFo (Queue) implementation **/
		private:
			Salih::Structures::LinkedLists::DNode<T>* head ;
			
			Salih::Structures::LinkedLists::DNode<T>* tail ;
			
			std::size_t size ;
		public:
			/** Empty constructor, intialises empty queue 
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR Queue() ;

			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for queue)
			@return <initialised-object> **/			
			_GLIBCXX20_CONSTEXPR Queue(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, re-assigns values to queue (1st element provided becomes head, etc.)
			@param initialisation list (of values for queue)
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR Queue& operator=(const std::initializer_list<T>&) ;
		
			/** Copy constructor, creates copy of a given queue
			@param a (l-value) queue object
			@return <initialised-object> **/				
			_GLIBCXX20_CONSTEXPR Queue(const Queue<T>&) ;
			
			/** Copy assignment operator, creates copy of a given queue
			@param a (l-value) queue object
			@return reference to current object **/	
			_GLIBCXX20_CONSTEXPR Queue& operator=(const Queue<T>&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary queue object
			@param an r-value queue object
			@return <initialised-object> **/
			_GLIBCXX20_CONSTEXPR Queue(Queue<T>&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary queue object
			@param an (r-value) queue object
			@return reference to current object **/
			_GLIBCXX20_CONSTEXPR Queue& operator=(Queue<T>&&) ;
			
			/** Comparison operator, determines calling queue object content matches with a given queue object
			@param queue object
			@return a boolean representing whether equality is met **/ 	
			_GLIBCXX20_CONSTEXPR bool operator==(const Queue<T>&) const ;

			/** Inequality operator, determines calling queue object content does not match with a given queue object
			@param queue object
			@return a boolean representing whether equality is not met **/ 				
			_GLIBCXX20_CONSTEXPR bool operator!=(const Queue<T>&) const ;

			/** Comparison operator, determines calling queue object content matches with a given queue object
			@param queue object (which contains different type values)
			@return a boolean representing whether equality is met **/ 			
			template<typename OTHER>
			_GLIBCXX20_CONSTEXPR bool operator==(const Queue<OTHER>&) const ;

			/** Inequality operator, determines calling queue object content does not match with a given queue object
			@param queue object (which contains different type values)
			@return a boolean representing whether equality is not met **/ 				
			template<typename OTHER>
			_GLIBCXX20_CONSTEXPR bool operator!=(const Queue<OTHER>&) const ;
			
			/** Destructor, frees memory and deletes queue **/					
			_GLIBCXX20_CONSTEXPR ~Queue() ;
			
			/** pop method, removes oldest / earliest added value from the queue
			@return value (of removed data object) **/					
			_GLIBCXX20_CONSTEXPR T pop() ;

			/** peek method, shows oldest / earliest added value to the queue
			@return constant reference to value (of earliest added / oldest data object) **/				
			_GLIBCXX20_CONSTEXPR const T& peek() const ;

			/** push method, adds a value to the end of the queue type
			@param value (to add) **/							
			_GLIBCXX20_CONSTEXPR void push(T) ;

			/** push method, adds a value to the end of the queue type
			@param initialisation list (of values to add) **/			
			_GLIBCXX20_CONSTEXPR void push(const std::initializer_list<T>&) ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			_GLIBCXX20_CONSTEXPR std::size_t getSize() ;
			
			template<typename OTHER>
    			friend class Queue ;
    			
	} ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>::Queue()
{
	this->size = 0 ;
	this->head = nullptr ;
	this->tail = nullptr ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>::Queue(const std::initializer_list<T>& values)
{
	this->size = 0 ;
	this->head = new Salih::Structures::LinkedLists::DNode<T>(*std::begin(values)) ;
	Salih::Structures::LinkedLists::DNode<T>* p = head ;
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
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>& Salih::Types::Buffers::Queue<T>::operator=(const std::initializer_list<T>& values)
{
	if(head != nullptr)
	{
		for(Salih::Structures::LinkedLists::DNode<T>* node = head ; ;)
		{
			Salih::Structures::LinkedLists::DNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	}
	
	this->size = 0 ;
	this->head = new Salih::Structures::LinkedLists::DNode<T>(*std::begin(values)) ;
	Salih::Structures::LinkedLists::DNode<T>* p = head ;
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
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>::Queue(const Queue& q)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::DNode<T>* h = q.head ;
	Salih::Structures::LinkedLists::DNode<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			this->head = new Salih::Structures::LinkedLists::DNode<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			this->tail = new Salih::Structures::LinkedLists::DNode<T>(h->data, p, 0) ;
		}
		else {
			p = new Salih::Structures::LinkedLists::DNode<T>(h->data, p, 0) ;
		}
		h = h->getNext() ;
		this->size = this->size + 1 ;	
	}
}

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>& Salih::Types::Buffers::Queue<T>::operator=(const Queue& q)
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
	Salih::Structures::LinkedLists::DNode<T>* h = q.head ;
	Salih::Structures::LinkedLists::DNode<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			this->head = new Salih::Structures::LinkedLists::DNode<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			this->tail = new Salih::Structures::LinkedLists::DNode<T>(h->data, p) ;
		}
		else {
			p = new Salih::Structures::LinkedLists::DNode<T>(h->data, p) ;
		}
		h = h->getNext() ;
		this->size = this->size + 1 ;	
	}
	return *this ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>::Queue(Queue&& q)
{
	this->head = q.head ;
	this->tail = q.tail ;
	this->size = q.size ;
	q.head = nullptr ;
	q.tail = nullptr ;
	q.size = 0 ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>& Salih::Types::Buffers::Queue<T>::operator=( Queue&& q ) 
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
_GLIBCXX20_CONSTEXPR bool Salih::Types::Buffers::Queue<T>::operator==(const Salih::Types::Buffers::Queue<T>& qq) const
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
_GLIBCXX20_CONSTEXPR bool Salih::Types::Buffers::Queue<T>::operator!=(const Salih::Types::Buffers::Queue<T>& qq) const
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
_GLIBCXX20_CONSTEXPR bool Salih::Types::Buffers::Queue<T>::operator==(const Salih::Types::Buffers::Queue<OTHER>& qq) const
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
_GLIBCXX20_CONSTEXPR bool Salih::Types::Buffers::Queue<T>::operator!=(const Salih::Types::Buffers::Queue<OTHER>& qq) const
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
_GLIBCXX20_CONSTEXPR Salih::Types::Buffers::Queue<T>::~Queue()
{
	if(head == nullptr) return;
	
	for(Salih::Structures::LinkedLists::DNode<T>* node = head ; ;)
	{
		Salih::Structures::LinkedLists::DNode<T>* mem = node->getNext() ;
		delete node ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
}

template <typename T>
_GLIBCXX20_CONSTEXPR T Salih::Types::Buffers::Queue<T>::pop()
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
_GLIBCXX20_CONSTEXPR const T& Salih::Types::Buffers::Queue<T>::peek() const
{
	if(size != 0) return head->data ;
	else throw std::out_of_range("Queue is empty") ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void Salih::Types::Buffers::Queue<T>::push(T val)
{
	Salih::Structures::LinkedLists::DNode<T>* p ;
	if(size == 0)
	{
		p = new Salih::Structures::LinkedLists::DNode<T>(val) ;
		head = p ;
	}
	else {
		p = new Salih::Structures::LinkedLists::DNode<T>(val, tail, 0) ;	
	}
	tail = p ;
	size += 1 ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void Salih::Types::Buffers::Queue<T>::push(const std::initializer_list<T>& values)
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

template <typename T>
_GLIBCXX20_CONSTEXPR std::size_t Salih::Types::Buffers::Queue<T>::getSize()
{
	return this->size ;
}

#endif
