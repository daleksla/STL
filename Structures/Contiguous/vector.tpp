#ifndef VECTOR_TPP
#define VECTOR_TPP
#pragma once

#include "vector.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <stdexcept>
#include <initializer_list>

/* This file contains the declarations and implementations of a array-based (child) contiguous structure 
 * It is located in the Salih, Structures, Contiguous namespaces */

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector() : Salih::Structures::Contiguous::Contiguous<T>(0) {} ;


template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(const std::size_t SIZE) : Salih::Structures::Contiguous::Contiguous<T>(SIZE) {} ;

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(T* dumbArray, const std::size_t sizing) : Salih::Structures::Contiguous::Contiguous<T>(dumbArray, sizing) {} ;

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(const std::initializer_list<T>& values) : Salih::Structures::Contiguous::Contiguous<T>(values, values.size()) {} ;

template<typename T> 
Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(const std::initializer_list<T>& values)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = values.size() ;
	this->pointer = new T[this->size] ;
	int i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
	return *this ;
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(const Vector<T>& list) : Salih::Structures::Contiguous::Contiguous<T>(list, list.size) {} ;

template<typename T> 
Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(const Vector<T>& list)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = list.size ;
	//if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = new T[list.size] ;
	for(int i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
	return *this ;	
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(Vector<T>&& list) : Salih::Structures::Contiguous::Contiguous<T>(list, list.size) {} ;

template<typename T> 
Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(Vector<T>&& list)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = list.size ;
	//if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = list.pointer ;
	this->size = list.size ;
	list.pointer = nullptr ;
	list.size = 0 ;
	return *this ;	
}

template<typename T>
void Salih::Structures::Contiguous::Vector<T>::append(T data)
{
	T* newPointer = new T[this->size+1] ;
	for(int i = 0 ; i < this->size ; i++)
	{
		newPointer[i] = this->pointer[i] ;
	}
	newPointer[this->size] = data ;
	delete[] this->pointer ;
	this->pointer = newPointer ;
	this->size = this->size + 1 ;
}

template<typename T>
void Salih::Structures::Contiguous::Vector<T>::clear()
{
	T* newPointer = new T[0] ;
	delete[] this->pointer ;
	this->pointer = newPointer ;
	this->size = 0 ;
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::~Vector() {} ;	

#endif
