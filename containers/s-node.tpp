#ifndef S_NODE_TPP
#define S_NODE_TPP
#pragma once

/* This file contains the implementations of linked list nodes
 * It is located in the nested Salih, Structures, LinkedLists namespaces */

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::SNode<T>::SNode(const T i_data, salih::containers::SNode<T>* i_prev) : next(nullptr), data(i_data)
{
	i_prev->setNext(this) ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::SNode<T>::SNode(const T i_data) : next(nullptr), data(i_data) {} ;

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::SNode<T>* salih::containers::SNode<T>::getNext()
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const salih::containers::SNode<T>* salih::containers::SNode<T>::getNext() const
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void salih::containers::SNode<T>::setNext(SNode<T>* input) 
{
	this->next = input ;
}

#endif
