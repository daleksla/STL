#ifndef QUEUE_TPP
#define QUEUE_TPP
#pragma once

#include "d-node.hpp"
#include "../types/macros.hpp"
#include <algorithm>
#include <initializer_list>

/** @brief Implementations of Queue FIFO structure. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

template <typename T>
CONSTEXPRCXX20 salih::containers::Queue<T>::Queue()
{
	this->size = 0 ;
	this->head = nullptr ;
	this->tail = nullptr ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::Queue<T>::Queue(const std::initializer_list<T>& values)
{
	this->size = 0 ;
	this->head = new salih::containers::DNode<T>(*std::begin(values)) ;
	salih::containers::DNode<T>* p = head ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new salih::containers::DNode<T>(*it, p, 0) ;
		} else {
			p = new salih::containers::DNode<T>(*it, p, 0) ;
		}
		this->size = size + 1 ;	
	}
}

template <typename T>
CONSTEXPRCXX20 salih::containers::Queue<T>& salih::containers::Queue<T>::operator=(const std::initializer_list<T>& values)
{
	if(head != nullptr)
	{
		for(salih::containers::DNode<T>* node = head ; ;)
		{
			salih::containers::DNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	}
	
	this->size = 0 ;
	this->head = new salih::containers::DNode<T>(*std::begin(values)) ;
	salih::containers::DNode<T>* p = head ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new salih::containers::DNode<T>(*it, p, 0) ;
		} else {
			p = new salih::containers::DNode<T>(*it, p, 0) ;
		}
		this->size = size + 1 ;	
	}
	return *this ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::Queue<T>::Queue(const Queue& q)
{
	this->size = 0 ;
	salih::containers::DNode<T>* h = q.head ;
	salih::containers::DNode<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			this->head = new salih::containers::DNode<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			this->tail = new salih::containers::DNode<T>(h->data, p, 0) ;
		}
		else {
			p = new salih::containers::DNode<T>(h->data, p, 0) ;
		}
		h = h->getNext() ;
		this->size = this->size + 1 ;	
	}
}

template <typename T>
CONSTEXPRCXX20 salih::containers::Queue<T>& salih::containers::Queue<T>::operator=(const Queue& q)
{
	//if(this->head != nullptr)
	//{
	//	for(salih::containers::Node<T>* node = this->head ; ;)
	//	{
	//		salih::containers::Node<T>* mem = node->getNext() ;
	//		delete node ;
	//		if(mem == nullptr) break ;
	//		node = mem ;
	//	}
	//}
	this->size = 0 ;
	salih::containers::DNode<T>* h = q.head ;
	salih::containers::DNode<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			this->head = new salih::containers::DNode<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			this->tail = new salih::containers::DNode<T>(h->data, p) ;
		}
		else {
			p = new salih::containers::DNode<T>(h->data, p) ;
		}
		h = h->getNext() ;
		this->size = this->size + 1 ;	
	}
	return *this ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::Queue<T>::Queue(Queue&& q)
{
	this->head = q.head ;
	this->tail = q.tail ;
	this->size = q.size ;
	q.head = nullptr ;
	q.tail = nullptr ;
	q.size = 0 ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::Queue<T>& salih::containers::Queue<T>::operator=( Queue&& q ) 
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
CONSTEXPRCXX20 bool salih::containers::Queue<T>::operator==(const salih::containers::Queue<T>& qq) const
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
CONSTEXPRCXX20 bool salih::containers::Queue<T>::operator!=(const salih::containers::Queue<T>& qq) const
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
CONSTEXPRCXX20 bool salih::containers::Queue<T>::operator==(const salih::containers::Queue<OTHER>& qq) const
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
CONSTEXPRCXX20 bool salih::containers::Queue<T>::operator!=(const salih::containers::Queue<OTHER>& qq) const
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
CONSTEXPRCXX20 salih::containers::Queue<T>::~Queue()
{
	if(head == nullptr) return;
	
	for(salih::containers::DNode<T>* node = head ; ;)
	{
		salih::containers::DNode<T>* mem = node->getNext() ;
		delete node ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
}

template <typename T>
CONSTEXPRCXX20 T salih::containers::Queue<T>::pop()
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
CONSTEXPRCXX20 const T& salih::containers::Queue<T>::peek() const
{
	if(size != 0) return head->data ;
	else throw std::out_of_range("Queue is empty") ;
}

template <typename T>
CONSTEXPRCXX20 void salih::containers::Queue<T>::push(T val)
{
	salih::containers::DNode<T>* p ;
	if(size == 0)
	{
		p = new salih::containers::DNode<T>(val) ;
		head = p ;
	}
	else {
		p = new salih::containers::DNode<T>(val, tail, 0) ;	
	}
	tail = p ;
	size += 1 ;
}

template <typename T>
CONSTEXPRCXX20 void salih::containers::Queue<T>::push(const std::initializer_list<T>& values)
{
	salih::containers::DNode<T>* p = tail ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new salih::containers::DNode<T>(*it, p, 0) ;
		} else {
			p = new salih::containers::DNode<T>(*it, p, 0) ;
		}
		size += 1 ;	
	}
	tail = p ;
}

template <typename T>
CONSTEXPRCXX20 std::size_t salih::containers::Queue<T>::getSize()
{
	return this->size ;
}

#endif
