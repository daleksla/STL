#ifndef STACK_TPP
#define STACK_TPP
#pragma once

#include "d-node.hpp"
#include <algorithm>
#include <initializer_list>

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>::Stack()
{
	this->size = 0 ;
	this->tail = nullptr ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>::Stack(const std::initializer_list<T>& values)
{
	this->size = 0 ;
	salih::containers::DNode<T>* p = new salih::containers::DNode<T>(*std::begin(values)) ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new salih::containers::DNode<T>(*it, p, 0) ;
		} else {
			p = new salih::containers::DNode<T>(*it, p, 0) ;
		}
		this->size = size + 1 ;	
	}
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>& salih::containers::Stack<T>::operator=(const std::initializer_list<T>& values)
{
	if(this->size != 0)
	{
		for(salih::containers::DNode<T>* node = tail ; ;)
		{
			salih::containers::DNode<T>* mem = node->getPrev() ;
			delete node ;
			if(mem == nullptr) break ;
			node = mem ;
		} 
	}
	this->size = 0 ;
	salih::containers::DNode<T>* p = new salih::containers::DNode<T>(*std::begin(values)) ;
	size += 1 ;
	for(auto it = std::next(std::begin(values)) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new salih::containers::DNode<T>(*it, p, 0) ;
		} else {
			p = new salih::containers::DNode<T>(*it, p, 0) ;
		}
		this->size = size + 1 ;	
	}
	return *this ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>::Stack(const salih::containers::Stack<T>& stck)
{
	this->size = 0 ;
	salih::containers::DNode<T>* node = stck.tail ;
	for(; ;)
	{
		salih::containers::DNode<T>* mem = node->getPrev() ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
	while(node != nullptr) 
	{
		this->push(node->data) ;	
		node = node->getNext() ;
	}
}
			
template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>& salih::containers::Stack<T>::operator=(const salih::containers::Stack<T>& stck) 
{
	this->size = 0 ;
	salih::containers::DNode<T>* node = stck.tail ;
	for(; ;)
	{
		salih::containers::DNode<T>* mem = node->getPrev() ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
	while(node != nullptr) 
	{
		this->push(node->data) ;	
		node = node->getNext() ;
	}
	return *this ;
}
			
template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>::Stack(salih::containers::Stack<T>&& stck)
{
	this->size = stck.size ;
	this->tail = stck.tail ;
	stck.size = 0 ;
	stck.tail = nullptr ;
}
			
template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>& salih::containers::Stack<T>::operator=(salih::containers::Stack<T>&& stck)
{
	this->size = stck.size ;
	this->tail = stck.tail ;
	stck.size = 0 ;
	stck.tail = nullptr ;
	return *this ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR bool salih::containers::Stack<T>::operator==(const salih::containers::Stack<T>& qq) const
{
	if(this->size != qq.size) return false ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return false ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return true ;
}

template <typename T>			
_GLIBCXX20_CONSTEXPR bool salih::containers::Stack<T>::operator!=(const salih::containers::Stack<T>& qq) const
{
	if(this->size != qq.size) return true ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return true ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return false ;
}

template <typename T>	
template<typename OTHER>
_GLIBCXX20_CONSTEXPR bool salih::containers::Stack<T>::operator==(const salih::containers::Stack<OTHER>& qq) const
{
	if(this->size != qq.size) return false ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return false ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return true ;
}
		
template <typename T>	
template <typename OTHER>
_GLIBCXX20_CONSTEXPR bool salih::containers::Stack<T>::operator!=(const salih::containers::Stack<OTHER>& qq) const
{
	if(this->size != qq.size) return true ;
	
	auto node1 = this->tail ;
	auto node2 = qq.tail ;
	while(node1 && node2)
	{
		if(node1->data != node2->data) return true ;
		node1 = node1->getPrev() ;
		node2 = node2->getPrev() ;
	}
	
	return false ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::Stack<T>::~Stack()
{
	if(size == 0) return;
	
	for(salih::containers::DNode<T>* node = tail ; ;)
	{
		salih::containers::DNode<T>* mem = node->getPrev() ;
		delete node ;
		if(mem == nullptr) break ;
		node = mem ;
	} 
}

template <typename T>
_GLIBCXX20_CONSTEXPR T salih::containers::Stack<T>::pop()
{
	if(size == 0) throw std::out_of_range("Stack is empty") ;
	auto newTail = tail->getPrev() ;
	auto data = tail->data ;
	delete tail ;
	tail = newTail ;
	size -= 1 ;
	return data ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const T& salih::containers::Stack<T>::peek() const
{
	if(size != 0) return tail->data ;
	else throw std::out_of_range("Stack is empty") ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void salih::containers::Stack<T>::push(T val)
{
	salih::containers::DNode<T>* p ;
	if(size == 0) p = new salih::containers::DNode<T>(val) ;
	else p = new salih::containers::DNode<T>(val, tail, 0) ;
	tail = p ;
	size += 1 ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void salih::containers::Stack<T>::push(const std::initializer_list<T>& values)
{
	salih::containers::DNode<T>* p = tail ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		if(it == std::prev(std::end(values))) {
			tail = new salih::containers::DNode<T>(*it, p, 0) ;
		} else {
			p = new salih::containers::DNode<T>(*it, p, 0) ;
		}
		size += 1 ;	
	}
	tail = p ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR std::size_t salih::containers::Stack<T>::getSize()
{
	return this->size ;
}

#endif
