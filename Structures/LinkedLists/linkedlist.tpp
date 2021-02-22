#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP
#pragma once

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

/* This file contains the implementations of a linked list
 * This includes the core linked nodes & a convenient wrapper 
 * It is located in the nested Salih, Structures, LinkedLists namespaces */
 
template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList() : head(NULL), tail(NULL) {} ;

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(Salih::Structures::LinkedLists::Node<T>& i_head, Salih::Structures::LinkedLists::Node<T>& i_tail)
{
	this->head = &i_head ;
	this->tail = &i_tail ;
	this->alloc = false ;
	getSize() ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(Salih::Structures::LinkedLists::Node<T>& i_node)
{
	Node<T>* node = &i_node ;
	this->head = node ;
	this->tail = Node<T>::getTail(node) ;
	this->alloc = false ;
	getSize() ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(Salih::Structures::LinkedLists::Node<T>& i_node, bool mode)
{
	Node<T>* node = &i_node ;
	if(mode == 0) 
	{
		this->head = node ;
		this->tail = Node<T>::getTail(node) ;
	} else {
		this->tail = node ;
		this->head = Node<T>::getHead(node) ;
	}
	this->alloc = false ;
	getSize() ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(const std::initializer_list<T>& values)
{
	this->size = 0 ;
	Salih::Structures::LinkedLists::Node<T>* p = NULL ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::begin(values)) 
		{
			this->head = new Node(*it) ;
			p = head ;	
		} else if(it == std::prev(std::end(values))) {
			tail = new Node(*it, *p, 0) ;
		} else {
			p = new Node(*it, *p, 0) ;
		}
		this->size = size + 1 ;	
	}
	this->alloc = true ;
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::~LinkedList()
{
	if(alloc != true) return;
	
	if(head == NULL) return;
	
	for(Node<T>* node = head ; ;)
	{
		Node<T>* mem = node->getNext() ;
		delete node ;
		if(mem == NULL) break ;
		node = mem ;
	} 
}

template <typename T>
T& Salih::Structures::LinkedLists::LinkedList<T>::operator[](const int& index)
{
	int count = 0 ;
	Node<T>* node = head ;
	while(count != index)
	{
		if(node->getNext() != NULL)
		{
			node = node->getNext() ;
		}
		else {
			throw std::out_of_range("Element does not exist") ;
		}
		count++ ;
	}
	return node->getData() ;
}

template <typename T>
inline void Salih::Structures::LinkedLists::LinkedList<T>::setSize(int newSize)
{
	this->size = newSize ;
}

template <typename T>
int Salih::Structures::LinkedLists::LinkedList<T>::getSize()
{
	if(size == -1) //ie we need to calculate size first
	{
		if(this->head == NULL) setSize(0) ;
		else {
			Node<T>* node = head ;
			while(node->getNext() != NULL)
			{
				setSize(size + 1) ;
				node = node->getNext() ;
			}
		}
	}
	return size ;
}

template <typename T>
void Salih::Structures::LinkedLists::LinkedList<T>::append(T data)
{
	Node<T>* node = new Node<T>(data) ;
	tail->setNext(node) ;
	this->tail = node ;
	setSize(size + 1) ;
}

template <typename T>
void Salih::Structures::LinkedLists::LinkedList<T>::del(int index)
{
	int count = 0 ;
	auto node = head ;
	while(count != index)
	{
		if(this->getNext() != NULL)
		{
			node = node->getNext() ;
		}
		else {
			throw std::out_of_range("Element does not exist") ;
		}
		count++ ;
	}
	del(node) ;
	setSize(size - 1) ;
}

template <typename T>
void Salih::Structures::LinkedLists::LinkedList<T>::del(Salih::Structures::LinkedLists::Node<T>*& node)
{
	Node<T>*& prev = node->getPrev() ;
	Node<T>*& next = node->getNext() ;
	prev->setNext(next) ; 
	next->setPrev(prev) ; 
	delete node ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>::Node(T i_data, Salih::Structures::LinkedLists::Node<T>& i_prev, Salih::Structures::LinkedLists::Node<T>& i_next) : data(i_data), prev(&i_prev), next(&i_next) 
{
	auto temp = this ;
	prev->setNext(temp) ;
	next->setPrev(temp) ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>::Node(T i_data, Salih::Structures::LinkedLists::Node<T>& node, bool type) : data(i_data)
{
	auto temp = this ;
	if(type == 0)
	{
		this->prev = &node ;
		prev->setNext(temp) ;
		this->next = NULL ;
	} else {
		this->next = &node ;
		next->setPrev(temp) ;
		this->prev = NULL ;
	}
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>::Node(T i_data) : data(i_data), prev(NULL), next(NULL) {} ;

template <typename T>
Salih::Structures::LinkedLists::Node<T>::Node(const Node<T>& node) : data(node.getData()), prev(NULL), next(NULL) {} ;

template <typename T>
const Salih::Structures::LinkedLists::Node<T>*& Salih::Structures::LinkedLists::Node<T>::getPrev() const
{
	return prev ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>*& Salih::Structures::LinkedLists::Node<T>::getPrev()
{
	return prev ;
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::setPrev(Node<T>*& input) 
{
	this->prev = input ;
}

template <typename T>
const Salih::Structures::LinkedLists::Node<T>*& Salih::Structures::LinkedLists::Node<T>::getNext() const
{
	return next ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>*& Salih::Structures::LinkedLists::Node<T>::getNext()
{
	return next ;
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::setNext(Node<T>*& input) 
{
	this->next = input ;
}

template <typename T>
T& Salih::Structures::LinkedLists::Node<T>::getData() 
{
	return data ;
}

template <typename T>
const T& Salih::Structures::LinkedLists::Node<T>::getData() const
{
	return data ;
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::setData(T input) 
{
	this->data = input ;
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::deleteNode() 
{	
	prev->setNext(this->getNext()) ; 
	next->setPrev(this->getPrev()) ; 
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::appendNode(Salih::Structures::LinkedLists::Node<T>*& base, Salih::Structures::LinkedLists::Node<T>*& itemToAdd) 
{	
	if(base->getNext() != NULL)
	{
		Node::appendNode(base->getNext(), itemToAdd) ;
	}
	else {
		base->setNext(itemToAdd) ;
		itemToAdd->setPrev(base) ;
	}
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::appendNode(Salih::Structures::LinkedLists::Node<T>& base, Salih::Structures::LinkedLists::Node<T>& itemToAdd) 
{	
	auto tbase = &base ;
	auto titemToAdd = &itemToAdd ;
	Node::appendNode(tbase, titemToAdd) ;
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::appendNode(Salih::Structures::LinkedLists::Node<T>& itemToAdd) 
{	
	auto tbase = this ;
	auto titemToAdd = &itemToAdd ;
	Node::appendNode(tbase, titemToAdd) ;
}

template <typename T>
int Salih::Structures::LinkedLists::Node<T>::size(Salih::Structures::LinkedLists::Node<T>& node)
{
	int count = 0 ;
	Node* x = &node ;
	while(x->getPrev() != NULL) x = x->getPrev() ;
	while(x->getNext() != NULL)
	{
		count++ ;
	}	
	count++ ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>* Salih::Structures::LinkedLists::Node<T>::getHead(Salih::Structures::LinkedLists::Node<T>* a)
{
	Node* x = a ;
	while(x->getPrev() != NULL)
	{
		x = x->getPrev() ;
	}
	return x ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>* Salih::Structures::LinkedLists::Node<T>::getTail(Salih::Structures::LinkedLists::Node<T>* a)
{
	Node* x = a ;
	while(x->getNext() != NULL)
	{
		x = x->getNext() ;
	}
	return x ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>* Salih::Structures::LinkedLists::Node<T>::getHead(Salih::Structures::LinkedLists::Node<T>& a)
{
	return Node<T>::getHead(&a) ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>* Salih::Structures::LinkedLists::Node<T>::getTail(Salih::Structures::LinkedLists::Node<T>& a)
{
	return Node<T>::getTail(&a) ;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Salih::Structures::LinkedLists::Node<T> data)
{
	os << "Data: " << data.data << "; Prev. location: " << data.prev << "; Next location: " << data.next ;
	return os ;
}

#endif
