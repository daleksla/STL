#ifndef FWD_LIST_TPP
#define FWD_LIST_TPP
#pragma once

#include <stdexcept>
#include "s-node.hpp"
#include "../types/macros.hpp"
#include <initializer_list>

/** @brief Implementations of singly Linkedlist container. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/
 
template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>::FwdList() : head(nullptr), size(0) {} ;

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>::FwdList(const unsigned long x)
{
	this->size = x ;
	if(x)
	{
		this->head = new SNode<T>(T()) ;
		salih::containers::SNode<T>* p = this->head ;
		for(unsigned long i = 1 ; i < x ; ++i)
		{
			p = new SNode<T>(T(), p) ;
		}
	}
	else {
		this->head = nullptr ;
	}	
}

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>::FwdList(const std::initializer_list<T>& values)
{
	this->size = values.size() ;
	this->head = new SNode<T>(*std::begin(values)) ;
	salih::containers::SNode<T>* p = this->head ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		p = new SNode<T>(*it, p) ;
	}
}

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>& salih::containers::FwdList<T>::operator=(const std::initializer_list<T>& values)
{
	this->clear() ;
	 
	this->size = values.size() ;
	this->head = new SNode<T>(*std::begin(values)) ;
	salih::containers::SNode<T>* p = this->head ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		p = new SNode<T>(*it, p) ;
	}
	return *this ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>::FwdList(const salih::containers::FwdList<T>& list)
{
	this->size = list.size ;

	if(this->size == 0) 
	{
		this->head = nullptr ; 
		return ;
	}

	SNode<T> const* listCounter = list.head ;
	SNode<T>* thisCounter = new SNode<T>(listCounter->data) ;
	this->head = thisCounter ;
	listCounter = listCounter->getNext() ;
	
	while(listCounter)
	{
		thisCounter = new SNode<T>(listCounter->data, thisCounter) ;
		listCounter = listCounter->getNext() ;
	}
}

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>& salih::containers::FwdList<T>::operator=(const salih::containers::FwdList<T>& list)
{
	this->clear() ;
	
	this->size = list.size ;

	if(this->size == 0) 
	{
		this->head = nullptr ; 
		return *this ;
	}

	SNode<T> const* listCounter = list.head ;
	SNode<T>* thisCounter = new SNode<T>(listCounter->data) ;
	this->head = thisCounter ;
	listCounter = listCounter->getNext() ;
	
	while(listCounter)
	{
		thisCounter = new SNode<T>(listCounter->data, thisCounter) ;
		listCounter = listCounter->getNext() ;
	}
	
	return *this ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>::FwdList(salih::containers::FwdList<T>&& list)
{
	this->head = list.head ;
	this->size = list.size ;
	list.head = nullptr ;
	list.size = 0 ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>& salih::containers::FwdList<T>::operator=(salih::containers::FwdList<T>&& list)
{
	this->clear() ;

	this->head = list.head ;
	this->size = list.size ;
	list.head = nullptr ;
	list.size = 0 ;
	return *this ;
}

template <typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>::~FwdList()
{
	this->clear() ;
}

template<typename T>		
CONSTEXPRCXX20 salih::containers::FwdList<T> salih::containers::FwdList<T>::operator()(const unsigned long a, const unsigned long b) const
{
	if(a > b || a < 0 || b > this->size) throw std::out_of_range("Element range requested does not exist") ;
	salih::containers::FwdList<T> tmp ;
	SNode<T>* node = head ; unsigned long count = 0 ;
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
CONSTEXPRCXX20 T& salih::containers::FwdList<T>::operator[](const unsigned long index)
{
	unsigned long count = 0 ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
CONSTEXPRCXX20 const T& salih::containers::FwdList<T>::operator[](const unsigned long index) const
{
	unsigned long count = 0 ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template <typename T>
CONSTEXPRCXX20 T& salih::containers::FwdList<T>::at(const unsigned long index)
{
	unsigned long count = 0 ;
	if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		++count ;
	}
	return node->data ;
}

template <typename T>
CONSTEXPRCXX20 const T& salih::containers::FwdList<T>::at(const unsigned long index) const
{
	unsigned long count = 0 ;
	if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	SNode<T>* node = head ;
	while(count != index)
	{
		node = node->getNext() ;
		count++ ;
	}
	return node->data ;
}

template<typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T> salih::containers::FwdList<T>::operator+(const salih::containers::FwdList<T>& list) const
{
	salih::containers::FwdList<T> tmp ;
	salih::containers::SNode<T>* node = this->head ;
	for(unsigned long i = 0 ; i < this->size ; i++)
	{
		tmp.append(node->data) ;
		node = node->getNext() ;
	}
	node = list.head ;	
	for(unsigned long i = 0 ; i < list.size ; i++)
	{
		tmp.append(node->data) ;
		node = node->getNext() ;
	}
	return tmp ;
}

template<typename T>
CONSTEXPRCXX20 salih::containers::FwdList<T>& salih::containers::FwdList<T>::operator+=(const salih::containers::FwdList<T>& list)
{
	salih::containers::SNode<T>* node = list.head ;
	for(unsigned long i = 0 ; i < list.size ; i++) 
	{
		this->append(node->data) ;
		node = node->getNext() ;
	}
	return *this ;
}

template <typename T>
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::operator==(const salih::containers::FwdList<T>& list) const
{
	if(list.size != this->size) return false ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(unsigned long i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return false ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return true ;
}

template <typename T>
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::operator!=(const salih::containers::FwdList<T>& list) const
{
	if(list.size != this->size) return true ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(unsigned long i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return true ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return false ;
}

template <typename T>
template <typename OTHER>
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::operator==(const salih::containers::FwdList<OTHER>& list) const
{
	if(list.size != this->size) return false ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(unsigned long i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return false ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return true ;
}

template <typename T>
template <typename OTHER>
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::operator!=(const salih::containers::FwdList<OTHER>& list) const
{
	if(list.getSize() != this->size) return true ;
	
	auto head1 = this->head ;
	auto head2 = list.head ;
	
	for(unsigned long i = 0 ; i < list.size ; i++)
	{
		if(head1->data != head2->data) return true ;
		head1 = head1->getNext() ;
		head2 = head2->getNext() ;
	}
	 
	return false ;
}

template <typename T>
CONSTEXPRCXX20 void salih::containers::FwdList<T>::insert(const unsigned long pos, T data) 
{
	if(pos == 0 || pos > this->size + 1) throw std::out_of_range("Invalid insert position") ;	
	else if(pos == this->size + 1) return this->append(data) ;
	else if(pos == 1) 
	{
		SNode<T>* exHead = this->head ;
		this->head = new SNode<T>(data) ;
		this->head->setNext(exHead) ;
	}
	else {
		//loop through LL, find correct 'node'
		SNode<T>* curNode = this->head ;
		for(unsigned long count = 1 ; count < pos - 1 ; count++) 
		{
			curNode = curNode->getNext() ;
		}

		auto nextNode = curNode->getNext() ;
		auto newNode = new SNode<T>(data, curNode) ;
		newNode->setNext(nextNode) ;
	}
	
	++this->size ;	
}

template <typename T>
CONSTEXPRCXX20 unsigned long salih::containers::FwdList<T>::getSize() const
{
	return this->size ;
}

template <typename T>
CONSTEXPRCXX20 void salih::containers::FwdList<T>::append(T data)
{
	if(this->size == 0) 
	{
		this->head = new SNode<T>(data) ;
	}	
	else {
		SNode<T>* node = nullptr ;
		for(node = this->head ; node->getNext() != nullptr ; node = node->getNext()) ;
		new SNode<T>(data, node) ;
	}
	
	++this->size ;
}

template <typename T>
CONSTEXPRCXX20 void salih::containers::FwdList<T>::append(const std::initializer_list<T>& data)
{
	SNode<T>* node = nullptr ;
	for(node = this->head ; node->getNext() != nullptr ; node = node->getNext()) ;
	for(auto it = std::begin(data) ; it != std::end(data) ; it = std::next(it))
	{ 
		if(this->size == 0) 
		{
			this->head = new SNode<T>(*it) ;
			node = node->getNext() ;
		}	
		else {
			new SNode<T>(*it, node) ;
			node = node->getNext() ;
		}
	
		++this->size ;
	}
}

template <typename T>
CONSTEXPRCXX20 void salih::containers::FwdList<T>::del(const unsigned long index)
{
	if(index == 0 || index > this->size) throw std::out_of_range("Index does not exist") ;	
	
	//loop through LL, find correct 'node'
	SNode<T>* prevNode = nullptr ;
	SNode<T>* curNode = this->head ;
	unsigned long count ;
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
		
	--this->size ;
}

template <typename T>
CONSTEXPRCXX20 void salih::containers::FwdList<T>::clear()
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
	this->size = 0 ;
}

template<typename T> 
CONSTEXPRCXX20 salih::containers::FwdList<T>::Iterator::Iterator() : pointer(nullptr) {} ;

template<typename T> 
CONSTEXPRCXX20 salih::containers::FwdList<T>::Iterator::Iterator(salih::containers::SNode<T>* input) : pointer(input) {} ;

template<typename T> 
CONSTEXPRCXX20 T& salih::containers::FwdList<T>::Iterator::operator*() const
{
	return this->pointer->data ; 
}

template<typename T> 
CONSTEXPRCXX20 T* salih::containers::FwdList<T>::Iterator::operator->() const
{
	return &(this->pointer->data) ; 
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::Iterator salih::containers::FwdList<T>::Iterator::operator+(const unsigned long x) const
{
	salih::containers::SNode<T>* tmp = this->pointer ;
	for(unsigned long i = 1 ; i <= x ; i++) tmp = tmp->getNext() ; 
	return salih::containers::FwdList<T>::Iterator(tmp) ; 
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::Iterator& salih::containers::FwdList<T>::Iterator::operator+=(const unsigned long x)
{
	for(unsigned long i = 1 ; i <= x ; i++) this->pointer = this->pointer->getNext() ; 
	return *this ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::Iterator& salih::containers::FwdList<T>::Iterator::operator++()
{
	this->pointer = this->pointer->getNext() ;
	return *this ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::Iterator salih::containers::FwdList<T>::Iterator::operator++(const int)
{
	salih::containers::FwdList<T>::Iterator tmp(this->pointer) ;
	this->pointer = this->pointer->getNext() ;
	return tmp ;
}

template<typename T> 
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::Iterator::operator==(const salih::containers::FwdList<T>::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T> 
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::Iterator::operator!=(const salih::containers::FwdList<T>::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T> 
CONSTEXPRCXX20 salih::containers::FwdList<T>::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

template<typename T> 
CONSTEXPRCXX20 salih::containers::FwdList<T>::ConstIterator::ConstIterator(salih::containers::SNode<T> const* input) : pointer(input) {} ;

template<typename T> 
CONSTEXPRCXX20 const T& salih::containers::FwdList<T>::ConstIterator::operator*() const
{
	return this->pointer->data ; 
}

template<typename T> 
CONSTEXPRCXX20 const T* salih::containers::FwdList<T>::ConstIterator::operator->() const
{
	return &(this->pointer->data) ; 
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator salih::containers::FwdList<T>::ConstIterator::operator+(const unsigned long x) const
{
	salih::containers::SNode<T> const* tmp = this->pointer ;
	for(unsigned long i = 1 ; i <= x ; i++) tmp = tmp->getNext() ; 
	return salih::containers::FwdList<T>::ConstIterator(tmp) ; 
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator& salih::containers::FwdList<T>::ConstIterator::operator+=(const unsigned long x)
{
	for(unsigned long i = 1 ; i <= x ; i++) this->pointer = this->pointer->getNext() ; 
	return *this ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator& salih::containers::FwdList<T>::ConstIterator::operator++()
{
	this->pointer = this->pointer->getNext() ;
	return *this ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator salih::containers::FwdList<T>::ConstIterator::operator++(const int)
{
	salih::containers::FwdList<T>::ConstIterator tmp(this->pointer) ;
	this->pointer = this->pointer->getNext() ;
	return tmp ;
}

template<typename T> 
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::ConstIterator::operator==(const salih::containers::FwdList<T>::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T> 
CONSTEXPRCXX20 bool salih::containers::FwdList<T>::ConstIterator::operator!=(const salih::containers::FwdList<T>::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::Iterator salih::containers::FwdList<T>::begin()
{
	return salih::containers::FwdList<T>::Iterator(this->head) ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::Iterator salih::containers::FwdList<T>::end()
{
	return salih::containers::FwdList<T>::Iterator(nullptr) ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator salih::containers::FwdList<T>::begin() const 
{
	return salih::containers::FwdList<T>::ConstIterator(this->head) ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator salih::containers::FwdList<T>::end() const
{
	return salih::containers::FwdList<T>::ConstIterator(nullptr) ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator salih::containers::FwdList<T>::cbegin() const 
{
	return salih::containers::FwdList<T>::ConstIterator(this->head) ;
}

template<typename T> 
CONSTEXPRCXX20 typename salih::containers::FwdList<T>::ConstIterator salih::containers::FwdList<T>::cend() const
{
	return salih::containers::FwdList<T>::ConstIterator(nullptr) ;
}

#endif
