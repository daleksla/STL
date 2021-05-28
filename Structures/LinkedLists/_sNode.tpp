#ifndef _SNODE_TPP
#define _SNODE_TPP
#pragma once

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

/* This file contains the implementations of linked list nodes
 * It is located in the nested Salih, Structures, LinkedLists namespaces */

template <typename T>
Salih::Structures::LinkedLists::SNode<T>::SNode(T i_data, Salih::Structures::LinkedLists::SNode<T>* i_prev) : data(i_data), next(nullptr)
{
	i_prev->setNext(this) ;
}

template <typename T>
Salih::Structures::LinkedLists::SNode<T>::SNode(T i_data) : data(i_data), next(nullptr) {} ;

template <typename T>
Salih::Structures::LinkedLists::SNode<T>::SNode(const SNode<T>& node) : data(node.data), next(nullptr) {} ;

template <typename T>
Salih::Structures::LinkedLists::SNode<T>& Salih::Structures::LinkedLists::SNode<T>::operator=(const SNode<T>& node)
{
	this->data(node.data) ; 
	this->next = nullptr ;
} 

template <typename T>
Salih::Structures::LinkedLists::SNode<T>* Salih::Structures::LinkedLists::SNode<T>::getNext()
{
	return next ;
}

template <typename T>
const Salih::Structures::LinkedLists::SNode<T>* Salih::Structures::LinkedLists::SNode<T>::getNext() const
{
	return next ;
}

template <typename T>
void Salih::Structures::LinkedLists::SNode<T>::setNext(SNode<T>* input) 
{
	this->next = input ;
}

#endif
