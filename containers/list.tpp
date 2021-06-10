#ifndef LIST_TPP
#define LIST_TPP
#pragma once

#include "d-node.hpp"
#include <stdexcept>
#include <initializer_list>
 
template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::List() : head(nullptr), tail(nullptr), size(0) {} ;

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::List(const std::initializer_list<T>& values)
{
	this->setSize(values.size()) ;
	salih::containers::DNode<T>* p = nullptr ;
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
_GLIBCXX20_CONSTEXPR salih::containers::List<T>& salih::containers::List<T>::operator=(const std::initializer_list<T>& values)
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
	salih::containers::DNode<T>* p = nullptr ;
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
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::List(const salih::containers::List<T>& list)
{
	this->setSize(0) ;
	salih::containers::DNode<T>* h = list.head ;
	salih::containers::DNode<T>* p = nullptr ;
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
_GLIBCXX20_CONSTEXPR salih::containers::List<T>& salih::containers::List<T>::operator=(const salih::containers::List<T>& list)
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
	salih::containers::DNode<T>* h = list.head ;
	salih::containers::DNode<T>* p = nullptr ;
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
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::List(salih::containers::List<T>&& list)
{
	this->head = list.head ;
	this->tail = list.tail ;
	this->setSize(list.size) ;
	list.head = nullptr ;
	list.tail = nullptr ;
	list.size = 0 ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::List<T>& salih::containers::List<T>::operator=(salih::containers::List<T>&& list)
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
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::~List()
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
_GLIBCXX20_CONSTEXPR salih::containers::List<T> salih::containers::List<T>::operator()(const std::size_t a, const std::size_t b) const
{
	if(a > b || a < 0 || b > this->size) throw std::out_of_range("Element range requested does not exist") ;
	salih::containers::List<T> tmp ;
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
_GLIBCXX20_CONSTEXPR T& salih::containers::List<T>::operator[](const std::size_t index)
{
	std::size_t count = 0 ;
	DNode<T>* node = nullptr ;
	if(this->size - index > (this->size / 2))
	{
		node = this->head ;
		while(count != index)
		{
			node = node->getNext() ;
			count++ ;
		}
	} 
	else {
		node = this->tail ;
		while((this->size - count) - 1 != index)
		{
			node = node->getPrev() ;
			count++ ;
		}		
	}
	return node->data ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const T& salih::containers::List<T>::operator[](const std::size_t index) const
{
	std::size_t count = 0 ;
	DNode<T>* node = nullptr ;
	if(this->size - index > (this->size / 2))
	{
		node = this->head ;
		while(count != index)
		{
			node = node->getNext() ;
			count++ ;
		}
	} 
	else {
		node = this->tail ;
		while((this->size - count) - 1 != index)
		{
			node = node->getPrev() ;
			count++ ;
		}		
	}
	return node->data ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR T& salih::containers::List<T>::at(const std::size_t index)
{
	if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	std::size_t count = 0 ;
	DNode<T>* node = nullptr ;
	if(this->size - index > (this->size / 2))
	{
		node = this->head ;
		while(count != index)
		{
			node = node->getNext() ;
			count++ ;
		}
	} 
	else {
		node = this->tail ;
		while((this->size - count) - 1 != index)
		{
			node = node->getPrev() ;
			count++ ;
		}		
	}
	return node->data ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const T& salih::containers::List<T>::at(const std::size_t index) const
{
	if(index >= this->size) throw std::out_of_range("Element does not exist") ;
	std::size_t count = 0 ;
	DNode<T>* node = nullptr ;
	if(this->size - index > (this->size / 2))
	{
		node = this->head ;
		while(count != index)
		{
			node = node->getNext() ;
			count++ ;
		}
	} 
	else {
		node = this->tail ;
		while((this->size - count) - 1 != index)
		{
			node = node->getPrev() ;
			count++ ;
		}		
	}
	return node->data ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR salih::containers::List<T> salih::containers::List<T>::operator+(const salih::containers::List<T>& list) const
{
	salih::containers::List<T> tmp ;
	salih::containers::DNode<T>* node = this->head ;
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
_GLIBCXX20_CONSTEXPR salih::containers::List<T>& salih::containers::List<T>::operator+=(const salih::containers::List<T>& list)
{
	salih::containers::DNode<T>* node = list.head ;
	for(std::size_t i = 0 ; i < list.size ; i++) this->append(node->data) ;
	return *this ;
}


template <typename T>
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::operator==(const salih::containers::List<T>& list) const
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
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::operator!=(const salih::containers::List<T>& list) const
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
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::operator==(const salih::containers::List<OTHER>& list) const
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
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::operator!=(const salih::containers::List<OTHER>& list) const
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
_GLIBCXX20_CONSTEXPR void salih::containers::List<T>::insert(const std::size_t pos, T data) 
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
_GLIBCXX20_CONSTEXPR inline void salih::containers::List<T>::insert(salih::containers::DNode<T>* node, T data)
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
_GLIBCXX20_CONSTEXPR inline void salih::containers::List<T>::setSize(std::size_t newSize)
{
	this->size = newSize ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR std::size_t salih::containers::List<T>::getSize() const
{
	return this->size ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void salih::containers::List<T>::append(T data)
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
_GLIBCXX20_CONSTEXPR void salih::containers::List<T>::append(const std::initializer_list<T>& data)
{
	DNode<T>* node = nullptr ;
	for(auto it = std::begin(data) ; it != std::end(data) ; ++it)
	{
		if(this->size == 0) 
		{
			node = new DNode<T>(*it) ;
			this->tail = node ;
			this->head = node ;
		}
		else {
			node = new DNode<T>(*it, tail, 0) ;
			this->tail = node ;
		}
	
		this->setSize(this->size + 1) ;
	}
}

template <typename T>
_GLIBCXX20_CONSTEXPR void salih::containers::List<T>::del(const std::size_t index)
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
_GLIBCXX20_CONSTEXPR inline void salih::containers::List<T>::del(salih::containers::DNode<T>* node)
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
_GLIBCXX20_CONSTEXPR void salih::containers::List<T>::clear()
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
	this->tail = nullptr ;
	this->size = 0 ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::Iterator::Iterator() : pointer(nullptr) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::Iterator::Iterator(salih::containers::DNode<T>* input) : pointer(input) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR T& salih::containers::List<T>::Iterator::operator*() const
{
	return this->pointer->data ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR T* salih::containers::List<T>::Iterator::operator->() const
{
	return &(this->pointer->data) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator salih::containers::List<T>::Iterator::operator+(const std::size_t x) const
{
	salih::containers::DNode<T>* tmp = this->pointer ;
	for(std::size_t i = 1 ; i <= x ; i++) tmp = tmp->getNext() ; 
	return salih::containers::List<T>::Iterator(tmp) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator& salih::containers::List<T>::Iterator::operator+=(const std::size_t x)
{
	for(std::size_t i = 1 ; i <= x ; i++) this->pointer = this->pointer->getNext() ; 
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator& salih::containers::List<T>::Iterator::operator++()
{
	this->pointer = this->pointer->getNext() ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator salih::containers::List<T>::Iterator::operator++(const int)
{
	salih::containers::List<T>::Iterator tmp(this->pointer) ;
	this->pointer = this->pointer->getNext() ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator salih::containers::List<T>::Iterator::operator-(const std::size_t x) const
{
	salih::containers::DNode<T>* tmp = this->pointer ;
	for(std::size_t i = 1 ; i <= x ; i++) tmp = tmp->getPrev() ; 
	return salih::containers::List<T>::Iterator(tmp) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator& salih::containers::List<T>::Iterator::operator-=(const std::size_t x)
{
	for(std::size_t i = 1 ; i <= x ; i++) this->pointer = this->pointer->getPrev() ; 
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator& salih::containers::List<T>::Iterator::operator--()
{
	this->pointer = this->pointer->getPrev() ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator salih::containers::List<T>::Iterator::operator--(const int)
{
	salih::containers::List<T>::Iterator tmp(this->pointer) ;
	this->pointer = this->pointer->getPrev() ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::Iterator::operator==(const salih::containers::List<T>::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::Iterator::operator!=(const salih::containers::List<T>::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR salih::containers::List<T>::ConstIterator::ConstIterator(salih::containers::DNode<T> const* input) : pointer(input) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR const T& salih::containers::List<T>::ConstIterator::operator*() const
{
	return this->pointer->data ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR const T* salih::containers::List<T>::ConstIterator::operator->() const
{
	return &(this->pointer->data) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::ConstIterator::operator+(const std::size_t x) const
{
	salih::containers::DNode<T>* tmp = this->pointer ;
	for(std::size_t i = 1 ; i <= x ; i++) tmp = tmp->getNext() ; 
	return salih::containers::List<T>::ConstIterator(tmp) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator& salih::containers::List<T>::ConstIterator::operator+=(const std::size_t x)
{
	for(std::size_t i = 1 ; i <= x ; i++) this->pointer = this->pointer->getNext() ; 
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator& salih::containers::List<T>::ConstIterator::operator++()
{
	this->pointer = this->pointer->getNext() ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::ConstIterator::operator++(const int)
{
	salih::containers::List<T>::ConstIterator tmp(this->pointer) ;
	this->pointer = this->pointer->getNext() ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::ConstIterator::operator-(const std::size_t x) const
{
	salih::containers::DNode<T>* tmp = this->pointer ;
	for(std::size_t i = 1 ; i <= x ; i++) tmp = tmp->getPrev() ; 
	return salih::containers::List<T>::ConstIterator(tmp) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator& salih::containers::List<T>::ConstIterator::operator-=(const std::size_t x)
{
	for(std::size_t i = 1 ; i <= x ; i++) this->pointer = this->pointer->getPrev() ; 
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator& salih::containers::List<T>::ConstIterator::operator--()
{
	this->pointer = this->pointer->getPrev() ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::ConstIterator::operator--(const int)
{
	salih::containers::List<T>::ConstIterator tmp(this->pointer) ;
	this->pointer = this->pointer->getPrev() ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::ConstIterator::operator==(const salih::containers::List<T>::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool salih::containers::List<T>::ConstIterator::operator!=(const salih::containers::List<T>::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator salih::containers::List<T>::begin()
{
	return salih::containers::List<T>::Iterator(this->head) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::Iterator salih::containers::List<T>::end()
{
	return salih::containers::List<T>::Iterator(nullptr) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::begin() const 
{
	return salih::containers::List<T>::ConstIterator(this->head) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::end() const
{
	return salih::containers::List<T>::ConstIterator(nullptr) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::cbegin() const 
{
	return salih::containers::List<T>::ConstIterator(this->head) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename salih::containers::List<T>::ConstIterator salih::containers::List<T>::cend() const
{
	return salih::containers::List<T>::ConstIterator(nullptr) ;
}

#endif
