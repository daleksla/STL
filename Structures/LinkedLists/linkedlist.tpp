#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP
#pragma once

#include <lib/Structures/LinkedLists/node.hpp>
#include <stdexcept>
#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

/* This file contains the implementations of a linked list
 * It is located in the nested Salih, Structures, LinkedLists namespaces */
 
template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList() : head(NULL), tail(NULL), size(0) {} ;

template <typename T>
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(const std::initializer_list<T>& values)
{
	this->setSize(0) ;
	Salih::Structures::LinkedLists::Node<T>* p = NULL ;
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
Salih::Structures::LinkedLists::LinkedList<T>::LinkedList(const Salih::Structures::LinkedLists::LinkedList<T>& list)
{
	this->setSize(0) ;
	Salih::Structures::LinkedLists::Node<T>* h = list.head ;
	Salih::Structures::LinkedLists::Node<T>* p = NULL ;
	while(h != NULL)
	{
		if(h->getPrev() == NULL) 
		{	
			head = new Node<T>(h->data) ;
			p = head ;
		}
		else if(h->getNext() == NULL)
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
Salih::Structures::LinkedLists::LinkedList<T>::~LinkedList()
{
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
T& Salih::Structures::LinkedLists::LinkedList<T>::operator[](const int index)
{
	int count = 0 ;
	if(index >= this->size) throw std::out_of_range("Element does not exist") ;
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
	Node<T>* node = NULL ;
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
	if(prev == NULL) this->head = next ;
	else prev->setNext(next) ; 
	if(next == NULL) this->tail = prev ;
	else next->setPrev(prev) ;
	delete node ;
	node = NULL ;
}


template<typename T>
std::ostream& operator<<(std::ostream& os, Salih::Structures::LinkedLists::LinkedList<T>& dt)
{
    //os << dt.mo << '/' << dt.da << '/' << dt.yr;
    if(dt.getSize() == 0) 
    {
    	os << "[]" ;
    	return os ;
    }
    
    os << "[" ;
    for(int i = 0 ; i < dt.getSize() ; i++)
    {
    	if(i != dt.getSize() - 1) os << dt[i] << "," ;
    	else os << dt[i] ;
    }
    os << "]" ;
    
    return os;
}

#endif
