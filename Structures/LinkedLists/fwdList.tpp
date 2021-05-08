#ifndef FWDLIST_TPP
#define FWDLIST_TPP
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
Salih::Structures::LinkedLists::FwdList<T>::FwdList() : head(nullptr), size(0) {} ;

template <typename T>
Salih::Structures::LinkedLists::FwdList<T>::FwdList(const std::initializer_list<T>& values)
{
	this->setSize(values.size()) ;
	if(this->size == 0) 
	{
		this->head = nullptr ; 
		return ;
	}
	SNode<T>* tmp = nullptr ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::begin(values))
		{
			this->head = new SNode<T>(*it) ;
			tmp = this->head ;
		}
		else {
			tmp = new SNode<T>(*it, tmp) ;
		}
	} 
}

template <typename T>
Salih::Structures::LinkedLists::FwdList<T>& Salih::Structures::LinkedLists::FwdList<T>::operator=(const std::initializer_list<T>& values)
{
	if(this->head != nullptr)
	{
		for(SNode<T>* node = head ; ;)
		{
			SNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	}
	 
	this->setSize(values.size()) ;	
	if(this->size == 0) 
	{
		this->head = nullptr ; 
		return *this ;
	}
	
	SNode<T>* tmp = nullptr ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::begin(values))
		{
			this->head = new SNode<T>(*it) ;
			tmp = this->head ;
		}
		else {
			tmp = new SNode<T>(*it, tmp) ;
		}
	} 
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::FwdList<T>::FwdList(const Salih::Structures::LinkedLists::FwdList<T>& list)
{
	this->setSize(list.size) ;

	if(this->size == 0) 
	{
		this->head = nullptr ; 
		return ;
	}

	SNode<T>* listCounter = list.head ;
	SNode<T>* thisCounter = nullptr ;
	
	while(listCounter)
	{
		if(listCounter == list.head) 
		{
			this->head = new SNode<T>(listCounter->data) ;
			thisCounter = this->head ;
		}
		else {
			thisCounter = new SNode<T>(listCounter->data, thisCounter) ;
		}
		listCounter = listCounter->getNext() ;
	}
}

template <typename T>
Salih::Structures::LinkedLists::FwdList<T>& Salih::Structures::LinkedLists::FwdList<T>::operator=(const Salih::Structures::LinkedLists::FwdList<T>& list)
{
	if(this->head != nullptr)
	{
		for(SNode<T>* node = head ; ;)
		{
			SNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	
	this->setSize(list.size) ;

	if(this->size == 0) 
	{
		this->head = nullptr ; 
		return *this ;
	}

	SNode<T>* listCounter = list.head ;
	SNode<T>* thisCounter = nullptr ;
	
	while(listCounter)
	{
		if(listCounter == list.head) 
		{
			this->head = new SNode<T>(listCounter->data) ;
			thisCounter = this->head ;
		}
		else {
			thisCounter = new SNode<T>(listCounter->data, thisCounter) ;
		}
		listCounter = listCounter->getNext() ;
	}
	
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::FwdList<T>::FwdList(Salih::Structures::LinkedLists::FwdList<T>&& list)
{
	this->head = list.head ;
	this->setSize(list.size) ;
	list.head = nullptr ;
	list.size = 0 ;
}

template <typename T>
Salih::Structures::LinkedLists::FwdList<T>& Salih::Structures::LinkedLists::FwdList<T>::operator=(Salih::Structures::LinkedLists::FwdList<T>&& list)
{
	if(head != nullptr)
	{
		for(SNode<T>* node = head ; ;)
		{
			SNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 	
	this->head = list.head ;
	this->setSize(list.size) ;
	list.head = nullptr ;
	list.size = 0 ;
	return *this ;
}

template <typename T>
Salih::Structures::LinkedLists::FwdList<T>::~FwdList()
{
	if(head != nullptr)
	{
		for(SNode<T>* node = head ; ;)
		{
			SNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	this->head = nullptr ;
}

template<typename T>		
Salih::Structures::LinkedLists::FwdList<T> Salih::Structures::LinkedLists::FwdList<T>::operator()(const std::size_t a, const std::size_t b) const
{
	if(a > b || a < 0 || b > this->size) throw std::out_of_range("Element range requested does not exist") ;
	Salih::Structures::LinkedLists::FwdList<T> tmp ;
	SNode<T>* node = head ; std::size_t count = 0 ;
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
T& Salih::Structures::LinkedLists::FwdList<T>::operator[](const std::size_t index)
{
	std::size_t count = 0 ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
const T& Salih::Structures::LinkedLists::FwdList<T>::operator[](const std::size_t index) const
{
	std::size_t count = 0 ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
T& Salih::Structures::LinkedLists::FwdList<T>::at(const std::size_t index, const bool check)
{
	std::size_t count = 0 ;
	if(check) if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
const T& Salih::Structures::LinkedLists::FwdList<T>::at(const std::size_t index, const bool check) const
{
	std::size_t count = 0 ;
	if(check) if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
bool Salih::Structures::LinkedLists::FwdList<T>::operator==(const Salih::Structures::LinkedLists::FwdList<T>& list) const
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
bool Salih::Structures::LinkedLists::FwdList<T>::operator!=(const Salih::Structures::LinkedLists::FwdList<T>& list) const
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
bool Salih::Structures::LinkedLists::FwdList<T>::operator==(const Salih::Structures::LinkedLists::FwdList<OTHER>& list) const
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
bool Salih::Structures::LinkedLists::FwdList<T>::operator!=(const Salih::Structures::LinkedLists::FwdList<OTHER>& list) const
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
void Salih::Structures::LinkedLists::FwdList<T>::insert(const std::size_t pos, T data) 
{
	if(pos == 0 || pos > this->size + 1) throw std::out_of_range("Invalid insert position") ;	
	else if(pos == this->size + 1) return this->append(data) ;
	
	//loop through LL, find correct 'node'
	SNode<T>* curNode = head ;
	for(std::size_t count = 1 ; count < pos ; count++) 
	{
		if(count >= pos - 2) break ;
		curNode = curNode->getNext() ;
	}

	this->insert(curNode, data) ;
	this->setSize(this->size + 1) ;	
}

template <typename T>
inline void Salih::Structures::LinkedLists::FwdList<T>::insert(Salih::Structures::LinkedLists::SNode<T>* node, T data)
{ //correct function
	auto newNode = new SNode<T>(data) ;
	SNode<T>* nextAfterNew = node->getNext() ;
	
	this->head = newNode ;
	this->head->setNext(nextAfterNew) ;
}

template <typename T>
inline void Salih::Structures::LinkedLists::FwdList<T>::setSize(int newSize)
{
	this->size = newSize ;
}

template <typename T>
std::size_t Salih::Structures::LinkedLists::FwdList<T>::getSize() const
{
	return this->size ;
}

template <typename T>
void Salih::Structures::LinkedLists::FwdList<T>::append(T data)
{
	if(this->size == 0) 
	{
		this->head = new SNode<T>(data) ;
	}	
	else {
		SNode<T>* node = nullptr ;
		for(node = this->head ; node->getNext() != nullptr ; node = node->getNext()) ;
		node->setNext(new SNode<T>(data, node)) ;
	}
	
	this->setSize(this->size + 1) ;
}

template <typename T>
void Salih::Structures::LinkedLists::FwdList<T>::del(const std::size_t index)
{
	if(index == 0 || index > this->size) throw std::out_of_range("Index does not exist") ;	
	
	//loop through LL, find correct 'node'
	SNode<T>* prevNode = nullptr ;
	SNode<T>* curNode = this->head ;
	std::size_t count ;
	for(count = 1 ; count < index ; count++)
	{
		prevNode = curNode ;
		curNode = curNode->getNext() ;
	}
	
	if(curNode == this->head) 
	{
		this->head = curNode->getNext() ;
	}
	else {	
		SNode<T>* next = curNode->getNext() ;
		prevNode->setNext(next) ;	
	}	
	delete curNode ;
		
	this->setSize(this->size - 1) ;
}

template <typename T>
void Salih::Structures::LinkedLists::FwdList<T>::clear()
{
	if(head != nullptr)
	{
		for(SNode<T>* node = head ; ;)
		{
			SNode<T>* mem = node->getNext() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		}
	} 
	this->head = nullptr ;
}

#endif
