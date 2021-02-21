#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP
#pragma once

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

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
}

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(Salih::Structures::LinkedLists::Node<T>& i_node)
{
	Node<T>* node = &i_node ;
	this->head = node ;
	this->tail = Node<T>::getTail(node) ;
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
}

//template <typename T>
//Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(std::vector<T> values)
//{
//	Salih::Structures::LinkedLists::Node<T>* p = NULL ;
//	for(auto it = begin(values) ; it != end(values) ; it = next(it))
//	{
//		if(it == begin(values)) 
//		{
//			this->head = &Node(*it) ;
//			p = head ;	
//		} else if(it == prev(end(values))) {
//			tail = &(Node(*it, *p, 0)) ;
//		} else {
//			p = &(Node(*it, *p, 0)) ;
//		}	
//	}
//}

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
