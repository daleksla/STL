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
Salih::Structures::LinkedLists::DNode<T>::DNode(T i_data, Salih::Structures::LinkedLists::DNode<T>* node, bool flag) : data(i_data)
{
       auto temp = this ;
       if(flag == 0)
       {
               this->prev = node ;
               prev->setNext(temp) ;
               this->next = nullptr ;
       } else {
               this->next = node ;
               next->setPrev(temp) ;
               this->prev = nullptr ;
       }
}

template <typename T>
Salih::Structures::LinkedLists::DNode<T>::DNode(T i_data) : data(i_data), prev(nullptr), next(nullptr) {} ;

template <typename T>
Salih::Structures::LinkedLists::DNode<T>::DNode(const DNode<T>& node) : data(node.data), prev(nullptr), next(nullptr) {} ;

template <typename T>
Salih::Structures::LinkedLists::DNode<T>& Salih::Structures::LinkedLists::DNode<T>::operator=(const DNode<T>& node)
{
	this->data(node.data) ; 
	this->prev = nullptr ;
	this->next = nullptr ;
} 

template <typename T>
Salih::Structures::LinkedLists::DNode<T>* Salih::Structures::LinkedLists::DNode<T>::getPrev()
{
	return prev ;
}

template <typename T>
void Salih::Structures::LinkedLists::DNode<T>::setPrev(DNode<T>* input) 
{
	this->prev = input ;
}

template <typename T>
Salih::Structures::LinkedLists::DNode<T>* Salih::Structures::LinkedLists::DNode<T>::getNext()
{
	return next ;
}

template <typename T>
void Salih::Structures::LinkedLists::DNode<T>::setNext(DNode<T>* input) 
{
	this->next = input ;
}

template <typename T>
void Salih::Structures::LinkedLists::DNode<T>::deleteNode() 
{	
	prev->setNext(this->getNext()) ; 
	next->setPrev(this->getPrev()) ; 
}

#endif
