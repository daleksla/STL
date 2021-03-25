#ifndef ARRAY_TPP
#define ARRAY_TPP
#pragma once

#include "array.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <stdexcept>
#include <initializer_list>

/* This file contains the declarations and implementations of a array-based (child) contiguous structure 
 * It is located in the Salih, Structures, Contiguous namespaces */

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Array() : Salih::Structures::Contiguous::Contiguous<T,SIZE>() {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Array(T* dumbArray, const std::size_t sizing) : Salih::Structures::Contiguous::Contiguous<T,SIZE>(dumbArray, sizing) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Array(const std::initializer_list<T>& list) : Salih::Structures::Contiguous::Contiguous<T,SIZE>(list) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(const std::initializer_list<T>& values)
{
	this->size = SIZE ;
	Contiguous<T,SIZE>::operator=(values) ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>::Array(const Array<T,SIZE>& list) : Salih::Structures::Contiguous::Contiguous<T,SIZE>(list) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(const Array<T,SIZE>& list)
{
	this->size = SIZE ;
	Contiguous<T,SIZE>::operator=(list) ;
	return *this ;	
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>::Array(Array<T,SIZE>&& list) : Salih::Structures::Contiguous::Contiguous<T,SIZE>(list) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(Array<T,SIZE>&& list)
{
	this->size = SIZE ;
	Contiguous<T,SIZE>::operator=(list) ;
	return *this ;	
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE> Salih::Structures::Contiguous::Array<T,SIZE>::operator()(const int x, const int y) const
{
	if(x < 0 || x > this->size - 1 || y < x || y > this->size - 1) throw std::out_of_range("Element range does not exist") ;
	const int SIZE_TMP = y - x ;
	// std::cout << SIZE_TMP << std::endl ;
	T* ARRAY = new T[SIZE_TMP] ;
	for(int i = x ; i < y ; i++)
	{
		ARRAY[i-x] = this->pointer[i] ;
	}
	return Array(ARRAY, SIZE_TMP) ;
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::~Array() {} ;	

#endif
