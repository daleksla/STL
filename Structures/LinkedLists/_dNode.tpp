#ifndef _DNODE_TPP
#define _DNODE_TPP
#pragma once

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

/* This file contains the implementations of linked list nodes
 * It is located in the nested Salih, Structures, LinkedLists namespaces */

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Structures::LinkedLists::DNode<T>::DNode(const T i_data, Salih::Structures::LinkedLists::DNode<T>* node, const bool flag)
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
_GLIBCXX20_CONSTEXPR Salih::Structures::LinkedLists::DNode<T>::DNode(const T i_data) : prev(nullptr), next(nullptr), data(i_data) {} ;

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Structures::LinkedLists::DNode<T>* Salih::Structures::LinkedLists::DNode<T>::getPrev()
{
	return prev ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const Salih::Structures::LinkedLists::DNode<T>* Salih::Structures::LinkedLists::DNode<T>::getPrev() const
{
	return prev ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void Salih::Structures::LinkedLists::DNode<T>::setPrev(DNode<T>* input) 
{
	this->prev = input ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR Salih::Structures::LinkedLists::DNode<T>* Salih::Structures::LinkedLists::DNode<T>::getNext() 
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR const Salih::Structures::LinkedLists::DNode<T>* Salih::Structures::LinkedLists::DNode<T>::getNext() const 
{
	return next ;
}

template <typename T>
_GLIBCXX20_CONSTEXPR void Salih::Structures::LinkedLists::DNode<T>::setNext(DNode<T>* input) 
{
	this->next = input ;
}

#endif
