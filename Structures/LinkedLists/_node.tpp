#ifndef _NODE_TPP
#define _NODE_TPP
#pragma once

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

/* This file contains the implementations of linked list nodes
 * It is located in the nested Salih, Structures, LinkedLists namespaces */

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
		this->next = nullptr ;
	} else {
		this->next = &node ;
		next->setPrev(temp) ;
		this->prev = nullptr ;
	}
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>::Node(T i_data) : data(i_data), prev(nullptr), next(nullptr) {} ;

template <typename T>
Salih::Structures::LinkedLists::Node<T>::Node(const Node<T>& node) : data(node.data), prev(nullptr), next(nullptr) {} ;

template <typename T>
Salih::Structures::LinkedLists::Node<T>& Salih::Structures::LinkedLists::Node<T>::operator=(const Node<T>& node)
{
	this->data(node.data) ; 
	this->prev = nullptr ;
	this->next = nullptr ;
} 

//template <typename T>
//const Salih::Structures::LinkedLists::Node<T>*& Salih::Structures::LinkedLists::Node<T>::getPrev() const
//{
//	return prev ;
//}

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

//template <typename T>
//const Salih::Structures::LinkedLists::Node<T>*& Salih::Structures::LinkedLists::Node<T>::getNext() const
//{
//	return next ;
//}

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
void Salih::Structures::LinkedLists::Node<T>::deleteNode() 
{	
	prev->setNext(this->getNext()) ; 
	next->setPrev(this->getPrev()) ; 
}

template <typename T>
void Salih::Structures::LinkedLists::Node<T>::appendNode(Salih::Structures::LinkedLists::Node<T>*& base, Salih::Structures::LinkedLists::Node<T>*& itemToAdd) 
{	
	if(base->getNext() != nullptr)
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
	while(x->getPrev() != nullptr) x = x->getPrev() ;
	while(x->getNext() != nullptr)
	{
		count++ ;
	}	
	count++ ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>* Salih::Structures::LinkedLists::Node<T>::getHead(Salih::Structures::LinkedLists::Node<T>* a)
{
	Node* x = a ;
	while(x->getPrev() != nullptr)
	{
		x = x->getPrev() ;
	}
	return x ;
}

template <typename T>
Salih::Structures::LinkedLists::Node<T>* Salih::Structures::LinkedLists::Node<T>::getTail(Salih::Structures::LinkedLists::Node<T>* a)
{
	Node* x = a ;
	while(x->getNext() != nullptr)
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

//template <typename T>
//std::ostream& operator<<(std::ostream& os, Salih::Structures::LinkedLists::Node<T> data)
//{
//	os << "Data: " << data.data << "; Prev. location: " << data.prev << "; Next location: " << data.next ;
//	return os ;
//}

#endif
