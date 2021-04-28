#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP
#pragma once

#include <lib/Structures/LinkedLists/_node.hpp>
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
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {} ;

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(const std::initializer_list<T>& values)
{
	this->setSize(0) ;
	Salih::Structures::LinkedLists::Node<T>* p = nullptr ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::begin(values)) 
		{
			this->head = new Node<T>(*it) ;
			p = head ;	
		} else if(it == std::prev(std::end(values))) {
			tail = new Node<T>(*it, *p, 0) ;
		} else {
			p = new Node<T>(*it, *p, 0) ;
		}
		this->setSize(this->size + 1) ;	
	}
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>& Salih::Structures::LinkedLists::LinkedList<T>::operator=(const std::initializer_list<T>& values)
{
	if(head != nullptr)
	{
		for(Node<T>* node = head ; ;)
		{
			Node<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	this->setSize(0) ;
	Salih::Structures::LinkedLists::Node<T>* p = nullptr ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::begin(values)) 
		{
			this->head = new Node<T>(*it) ;
			p = head ;	
		} else if(it == std::prev(std::end(values))) {
			tail = new Node<T>(*it, *p, 0) ;
		} else {
			p = new Node<T>(*it, *p, 0) ;
		}
		this->setSize(this->size + 1) ;	
	}
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(const Salih::Structures::LinkedLists::LinkedList<T>& list)
{
	this->setSize(0) ;
	Salih::Structures::LinkedLists::Node<T>* h = list.head ;
	Salih::Structures::LinkedLists::Node<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			head = new Node<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			tail = new Node<T>(h->data, *p, 0) ;
		}
		else {
			p = new Node<T>(h->data, *p, 0) ;
		}
		h = h->getNext() ;
		this->setSize(this->size + 1) ;	
	}
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>& Salih::Structures::LinkedLists::LinkedList<T>::operator=(const Salih::Structures::LinkedLists::LinkedList<T>& list)
{
	if(head != nullptr)
	{
		for(Node<T>* node = head ; ;)
		{
			Node<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	
	this->setSize(0) ;
	Salih::Structures::LinkedLists::Node<T>* h = list.head ;
	Salih::Structures::LinkedLists::Node<T>* p = nullptr ;
	while(h != nullptr)
	{
		if(h->getPrev() == nullptr) 
		{	
			head = new Node<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == nullptr)
		{
			tail = new Node<T>(h->data, *p, 0) ;
		}
		else {
			p = new Node<T>(h->data, *p, 0) ;
		}
		h = h->getNext() ;
		this->setSize(this->size + 1) ;	
	}
	
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(Salih::Structures::LinkedLists::LinkedList<T>&& list)
{
	this->head = list.head ;
	this->tail = list.tail ;
	this->setSize(list.size) ;
	list.head = nullptr ;
	list.tail = nullptr ;
	list.size = std::numeric_limits<int>::max() ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>& Salih::Structures::LinkedLists::LinkedList<T>::operator=(Salih::Structures::LinkedLists::LinkedList<T>&& list)
{
	if(head != nullptr)
	{
		for(Node<T>* node = head ; ;)
		{
			Node<T>* mem = node->getNext() ;
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
	list.size = std::numeric_limits<int>::max() ;
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::~LinkedList()
{
	if(head == nullptr) return;
	
	for(Node<T>* node = head ; ;)
	{
		Node<T>* mem = node->getNext() ;
		delete node ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
}

template <typename T>
T& Salih::Structures::LinkedLists::LinkedList<T>::operator[](const int index)
{
	int count = 0 ;
	Node<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
const T& Salih::Structures::LinkedLists::LinkedList<T>::operator[](const int index) const
{
	int count = 0 ;
	Node<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
T& Salih::Structures::LinkedLists::LinkedList<T>::at(const int index, const bool check)
{
	int count = 0 ;
	if(check) if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	Node<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
const T& Salih::Structures::LinkedLists::LinkedList<T>::at(const int index, const bool check) const
{
	int count = 0 ;
	if(check) if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	Node<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
bool Salih::Structures::LinkedLists::LinkedList<T>::operator==(const Salih::Structures::LinkedLists::LinkedList<T>& list) const
{
	if(list.getSize() != this->getSize()) return false ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(int i = 0 ; i < list.getSize() ; i++)
	{
		if(head1->data != head2->data) return false ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return true ;
}

template <typename T>
bool Salih::Structures::LinkedLists::LinkedList<T>::operator!=(const Salih::Structures::LinkedLists::LinkedList<T>& list) const
{
	if(list.getSize() != this->getSize()) return true ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(int i = 0 ; i < list.getSize() ; i++)
	{
		if(head1->data != head2->data) return true ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return false ;
}

template <typename T>
template <typename OTHER>
bool Salih::Structures::LinkedLists::LinkedList<T>::operator==(const Salih::Structures::LinkedLists::LinkedList<OTHER>& list) const
{
	if(list.getSize() != this->getSize()) return false ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(int i = 0 ; i < list.getSize() ; i++)
	{
		if(head1->data != head2->data) return false ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return true ;
}

template <typename T>
template <typename OTHER>
bool Salih::Structures::LinkedLists::LinkedList<T>::operator!=(const Salih::Structures::LinkedLists::LinkedList<OTHER>& list) const
{
	if(list.getSize() != this->getSize()) return true ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(int i = 0 ; i < list.getSize() ; i++)
	{
		if(head1->data != head2->data) return true ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return false ;
}

template <typename T>
void Salih::Structures::LinkedLists::LinkedList<T>::insert(const int pos, T data) 
{
	if(pos == 0 || pos > this->size + 1) throw std::out_of_range("Invalid insert position") ;	
	else if(pos == this->size + 1) return this->append(data) ;
	
	//loop through LL, find correct 'node'
	Node<T>* curNode = head ;
	for(int count = 1 ; count < pos ; count++) 
	{
		curNode = curNode->getNext() ;
	}

	this->insert(curNode, data) ;
	this->setSize(this->size + 1) ;	
}

template <typename T>
inline void Salih::Structures::LinkedLists::LinkedList<T>::insert(Salih::Structures::LinkedLists::Node<T>* node, T data)
{ //correct function
	auto newNode = new Node<T>(data) ;
	Node<T>* prev = node->getPrev() ;
	
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
inline void Salih::Structures::LinkedLists::LinkedList<T>::setSize(int newSize)
{
	this->size = newSize ;
}

template <typename T>
int Salih::Structures::LinkedLists::LinkedList<T>::getSize() const
{
	return this->size ;
}

template <typename T>
void Salih::Structures::LinkedLists::LinkedList<T>::append(T data)
{
	Node<T>* node = nullptr ;
	if(this->size == 0) 
	{
		node = new Node<T>(data) ;
		this->tail = node ;
		this->head = node ;
	}
	else {
		node = new Node<T>(data, *tail, 0) ;
		this->tail = node ;
	}
	
	this->setSize(this->size + 1) ;
}

template <typename T>
void Salih::Structures::LinkedLists::LinkedList<T>::del(const int index)
{
	if(index == 0 || index > this->size) throw std::out_of_range("Index does not exist") ;	
	
	//loop through LL, find correct 'node'
	Node<T>* curNode = head ;
	for(int count = 1 ; count < index ; count++) 
	{
		curNode = curNode->getNext() ;
	}
		
	this->del(curNode) ;
	this->setSize(this->size - 1) ;
}

template <typename T>
inline void Salih::Structures::LinkedLists::LinkedList<T>::del(Salih::Structures::LinkedLists::Node<T>* node)
{ //correct function
	Node<T>* prev = node->getPrev() ;
	Node<T>* next = node->getNext() ;
	if(prev == nullptr) this->head = next ;
	else prev->setNext(next) ; 
	if(next == nullptr) this->tail = prev ;
	else next->setPrev(prev) ;
	delete node ;
	node = nullptr ;
}


template<typename T>
std::ostream& std::operator<<(std::ostream& os, const Salih::Structures::LinkedLists::LinkedList<T>& dt)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    if(dt.size == 0) 
    {
    	os << "[]" ;
    	return os ;
    }
    
    os << "[" ;
    for(int i = 0 ; i < dt.size ; i++)
    {
    	if(i != dt.size - 1) os << dt[i] << "," ;
    	else os << dt[i] ;
    }
    os << "]" ;
    
    return os;
}

#endif
