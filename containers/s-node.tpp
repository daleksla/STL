#ifndef S_NODE_TPP
#define S_NODE_TPP
#pragma once

#include "../types/macros.hpp"

/** @brief Implementations of Singly Linkedlist nodes. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

template <typename T>
CONSTEXPRCXX14 salih::containers::SNode<T>::SNode(const T i_data, salih::containers::SNode<T>* i_prev) : next(nullptr), data(i_data)
{
	i_prev->setNext(this) ;
}

template <typename T>
CONSTEXPRCXX14 salih::containers::SNode<T>::SNode(const T i_data) : next(nullptr), data(i_data) {} ;

template <typename T>
CONSTEXPRCXX14 salih::containers::SNode<T>* salih::containers::SNode<T>::getNext()
{
	return next ;
}

template <typename T>
CONSTEXPRCXX14 const salih::containers::SNode<T>* salih::containers::SNode<T>::getNext() const
{
	return next ;
}

template <typename T>
CONSTEXPRCXX14 void salih::containers::SNode<T>::setNext(SNode<T>* input) 
{
	this->next = input ;
}

#endif
