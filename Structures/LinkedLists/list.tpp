#ifndef LIST_TPP
#define LIST_TPP
#pragma once

#include <stdexcept>
#include <limits>
#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

/* This file contains the implementations of a linked list
 * It is located in the nested Salih, Structures, LinkedLists namespaces */
 
template <typename T>
Salih::Structures::LinkedLists::List<T>::List() : head(nullptr), tail(nullptr), size(0) {} ;

template <typename T>
Salih::Structures::LinkedLists::List<T>::List(const std::initializer_list<T>& values)
{
	this->setSize(values.size()) ;
	Salih::Structures::LinkedLists::DNode<T>* p = nullptr ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::begin(values)) 
		{
			this->head = new DNode<T>(*it) ;
			p = head ;	
		} else if(it == std::prev(std::end(values))) {
			tail = new DNode<T>(*it, p, 0) ;
		} else {
			p = new DNode<T>(*it, p, 0) ;
		}
	}
}

template <typename T>
Salih::Structures::LinkedLists::List<T>& Salih::Structures::LinkedLists::List<T>::operator=(const std::initializer_list<T>& values)
{
	if(head != nullptr)
	{
		for(DNode<T>* node = head ; ;)
		{
			DNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	this->setSize(values.size()) ;
	Salih::Structures::LinkedLists::DNode<T>* p = nullptr ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::begin(values)) 
		{
			this->head = new DNode<T>(*it) ;
			p = head ;	
		} else if(it == std::prev(std::end(values))) {
			tail = new DNode<T>(*it, p, 0) ;
		} else {
			p = new DNode<T>(*it, p, 0) ;
		}
	}
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::List<T>::List(const Salih::Structures::LinkedLists::List<T>& list)
{
	this->setSize(0) ;
	Salih::Structures::LinkedLists::DNode<T>* h = list.head ;
	Salih::Structures::LinkedLists::DNode<T>* p = nullptr ;
	this->head = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			head = new DNode<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			tail = new DNode<T>(h->data, p, 0) ;
		}
		else {
			p = new DNode<T>(h->data, p, 0) ;
		}
		h = h->getNext() ;
		this->setSize(this->size + 1) ;	
	}
}

template <typename T>
Salih::Structures::LinkedLists::List<T>& Salih::Structures::LinkedLists::List<T>::operator=(const Salih::Structures::LinkedLists::List<T>& list)
{
	if(head != nullptr)
	{
		for(DNode<T>* node = head ; ;)
		{
			DNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	
	this->setSize(0) ;
	this->head = nullptr ;
	Salih::Structures::LinkedLists::DNode<T>* h = list.head ;
	Salih::Structures::LinkedLists::DNode<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			head = new DNode<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			tail = new DNode<T>(h->data, p, 0) ;
		}
		else {
			p = new DNode<T>(h->data, p, 0) ;
		}
		h = h->getNext() ;
		this->setSize(this->size + 1) ;	
	}
	
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::List<T>::List(Salih::Structures::LinkedLists::List<T>&& list)
{
	this->head = list.head ;
	this->tail = list.tail ;
	this->setSize(list.size) ;
	list.head = nullptr ;
	list.tail = nullptr ;
	list.size = 0 ;
}

template <typename T>
Salih::Structures::LinkedLists::List<T>& Salih::Structures::LinkedLists::List<T>::operator=(Salih::Structures::LinkedLists::List<T>&& list)
{
	if(head != nullptr)
	{
		for(DNode<T>* node = head ; ;)
		{
			DNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 	
	this->head = list.head ;
	this->tail = list.tail ;
	this->setSize(list.size) ;
	list.head = nullptr ;
	list.tail = nullptr ;
	list.size = 0 ;
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::List<T>::~List()
{
	if(head == nullptr) return;
	
	for(DNode<T>* node = head ; ;)
	{
		DNode<T>* mem = node->getNext() ;
		delete node ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
}

template<typename T>		
Salih::Structures::LinkedLists::List<T> Salih::Structures::LinkedLists::List<T>::operator()(const std::size_t a, const std::size_t b) const
{
	if(a > b || a < 0 || b > this->size) throw std::out_of_range("Element range requested does not exist") ;
	Salih::Structures::LinkedLists::List<T> tmp ;
	DNode<T>* node = head ; std::size_t count = 0 ;
	while(count != a)
	{
		node = node->getNext() ;
		count++ ;
	}
	for( ; count < b ; count++ ) 
	{
		tmp.append(node->data) ;
		node = node->getNext() ;
	}
	return tmp ;
}

template <typename T>
T& Salih::Structures::LinkedLists::List<T>::operator[](const std::size_t index)
{
	std::size_t count = 0 ;
	DNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
const T& Salih::Structures::LinkedLists::List<T>::operator[](const std::size_t index) const
{
	std::size_t count = 0 ;
	DNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
T& Salih::Structures::LinkedLists::List<T>::at(const std::size_t index, const bool check)
{
	std::size_t count = 0 ;
	if((check) && (index >= this->size)) throw std::out_of_range("Element does not exist") ;
	DNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
const T& Salih::Structures::LinkedLists::List<T>::at(const std::size_t index, const bool check) const
{
	std::size_t count = 0 ;
	if((check) && (index >= this->size)) throw std::out_of_range("Element does not exist") ;
	DNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template<typename T>
Salih::Structures::LinkedLists::List<T> Salih::Structures::LinkedLists::List<T>::operator+(const Salih::Structures::LinkedLists::List<T>& list) const
{
	Salih::Structures::LinkedLists::List<T> tmp ;
	Salih::Structures::LinkedLists::DNode<T>* node = this->head ;
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		tmp.append(node->data) ;
		node = node->getNext() ;
	}
	node = list.head ;	
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		tmp.append(node->data) ;
		node = node->getNext() ;
	}
	return tmp ;
}

template<typename T>
Salih::Structures::LinkedLists::List<T>& Salih::Structures::LinkedLists::List<T>::operator+=(const Salih::Structures::LinkedLists::List<T>& list)
{
	Salih::Structures::LinkedLists::DNode<T>* node = list.head ;
	for(std::size_t i = 0 ; i < list.size ; i++) this->append(node->data) ;
	return *this ;
}


template <typename T>
bool Salih::Structures::LinkedLists::List<T>::operator==(const Salih::Structures::LinkedLists::List<T>& list) const
{
	if(list.size != this->size) return false ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return false ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return true ;
}

template <typename T>
bool Salih::Structures::LinkedLists::List<T>::operator!=(const Salih::Structures::LinkedLists::List<T>& list) const
{
	if(list.size != this->size) return true ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return true ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return false ;
}

template <typename T>
template <typename OTHER>
bool Salih::Structures::LinkedLists::List<T>::operator==(const Salih::Structures::LinkedLists::List<OTHER>& list) const
{
	if(list.size != this->size) return false ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return false ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return true ;
}

template <typename T>
template <typename OTHER>
bool Salih::Structures::LinkedLists::List<T>::operator!=(const Salih::Structures::LinkedLists::List<OTHER>& list) const
{
	if(list.getSize() != this->size) return true ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return true ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return false ;
}

template <typename T>
void Salih::Structures::LinkedLists::List<T>::insert(const std::size_t pos, T data) 
{
	if(pos == 0 || pos > this->size + 1) throw std::out_of_range("Invalid insert position") ;	
	else if(pos == this->size + 1) return this->append(data) ;
	
	//loop through LL, find correct 'node'
	DNode<T>* curNode = head ;
	for(std::size_t count = 1 ; count < pos ; count++) 
	{
		curNode = curNode->getNext() ;
	}

	this->insert(curNode, data) ;
	this->setSize(this->size + 1) ;	
}

template <typename T>
inline void Salih::Structures::LinkedLists::List<T>::insert(Salih::Structures::LinkedLists::DNode<T>* node, T data)
{ //correct function
	auto newNode = new DNode<T>(data) ;
	DNode<T>* prev = node->getPrev() ;
	
	if(prev == nullptr)
	{
		this->head = newNode ;
		newNode->setNext(node) ;	
		node->setPrev(newNode) ;
	} 
	else {
		prev->setNext(newNode) ;
		newNode->setPrev(prev) ;
		newNode->setNext(node) ;	
		node->setPrev(newNode) ;
	}
}

template <typename T>
inline void Salih::Structures::LinkedLists::List<T>::setSize(std::size_t newSize)
{
	this->size = newSize ;
}

template <typename T>
std::size_t Salih::Structures::LinkedLists::List<T>::getSize() const
{
	return this->size ;
}

template <typename T>
void Salih::Structures::LinkedLists::List<T>::append(T data)
{
	DNode<T>* node = nullptr ;
	if(this->size == 0) 
	{
		node = new DNode<T>(data) ;
		this->tail = node ;
		this->head = node ;
	}
	else {
		node = new DNode<T>(data, tail, 0) ;
		this->tail = node ;
	}
	
	this->setSize(this->size + 1) ;
}

template <typename T>
void Salih::Structures::LinkedLists::List<T>::del(const std::size_t index)
{
	if(index == 0 || index > this->size) throw std::out_of_range("Index does not exist") ;	
	
	//loop through LL, find correct 'node'
	DNode<T>* curNode = head ;
	for(std::size_t count = 1 ; count < index ; count++) 
	{
		curNode = curNode->getNext() ;
	}
		
	this->del(curNode) ;
	this->setSize(this->size - 1) ;
}

template <typename T>
inline void Salih::Structures::LinkedLists::List<T>::del(Salih::Structures::LinkedLists::DNode<T>* node)
{ //correct function
	DNode<T>* prev = node->getPrev() ;
	DNode<T>* next = node->getNext() ;
	if(prev == nullptr) this->head = next ;
	else prev->setNext(next) ; 
	if(next == nullptr) this->tail = prev ;
	else next->setPrev(prev) ;
	delete node ;
	node = nullptr ;
}

template <typename T>
void Salih::Structures::LinkedLists::List<T>::clear()
{
	if(head != nullptr)
	{
		for(DNode<T>* node = head ; ;)
		{
			DNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	this->head = nullptr ;
}

#endif
