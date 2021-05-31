#ifndef D_NODE_TPP
#define D_NODE_TPP
#pragma once

/* This file contains the implementations of linked list nodes
 * It is located in the nested Salih, Structures, LinkedLists namespaces */

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::DNode<T>::DNode(const T i_data, salih::containers::DNode<T>* node, const bool flag)
{
       auto temp = this ;
       if(flag == 0)
       {
               this->prev = node ;
               prev->setNext(temp) ;
               this->next = nullptr ;
       } else {
               this->prev = nullptr ;
               this->next = node ;
               next->setPrev(temp) ;
       }
       this->data = i_data ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::DNode<T>::DNode(const T i_data) : prev(nullptr), next(nullptr), data(i_data) {} ;

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::DNode<T>* salih::containers::DNode<T>::getPrev()
{
	return prev ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const salih::containers::DNode<T>* salih::containers::DNode<T>::getPrev() const
{
	return prev ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void salih::containers::DNode<T>::setPrev(DNode<T>* input) 
{
	this->prev = input ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR salih::containers::DNode<T>* salih::containers::DNode<T>::getNext() 
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const salih::containers::DNode<T>* salih::containers::DNode<T>::getNext() const 
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void salih::containers::DNode<T>::setNext(DNode<T>* input) 
{
	this->next = input ;
}

#endif
