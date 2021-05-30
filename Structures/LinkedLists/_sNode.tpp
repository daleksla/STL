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
_GLIBCXX20_CONSTEXPR Salih::Structures::LinkedLists::SNode<T>::SNode(const T i_data, Salih::Structures::LinkedLists::SNode<T>* i_prev) : data(i_data), next(nullptr)
{
	i_prev->setNext(this) ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Structures::LinkedLists::SNode<T>::SNode(const T i_data) : data(i_data), next(nullptr) {} ;

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Structures::LinkedLists::SNode<T>* Salih::Structures::LinkedLists::SNode<T>::getNext()
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const Salih::Structures::LinkedLists::SNode<T>* Salih::Structures::LinkedLists::SNode<T>::getNext() const
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void Salih::Structures::LinkedLists::SNode<T>::setNext(SNode<T>* input) 
{
	this->next = input ;
}

#endif
