#ifndef LINKED_LIST_TPP
#define LINKED_LIST_TPP
#pragma once

#include <lib/Structures/LinkedLists/node.hpp>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

/* This file contains the implementations of a linked list
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
			this->head = new Node<T>(*it) ;
			p = head ;	
		} else if(it == std::prev(std::end(values))) {
			tail = new Node<T>(*it, *p, 0) ;
		} else {
			p = new Node<T>(*it, *p, 0) ;
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
	while(count < index)
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

#endif
