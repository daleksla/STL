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

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T,size>::Array() : Salih::Structures::Contiguous::Contiguous<T>(size) {} ;

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T,size>::Array(T* dumbArray, std::size_t sizing) : Salih::Structures::Contiguous::Contiguous<T>(dumbArray, sizing) {} ;

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T,size>::Array(const std::initializer_list<T>& list) : Salih::Structures::Contiguous::Contiguous<T>(size, list) {} ;

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T,size>& Salih::Structures::Contiguous::Array<T, size>::operator=(const std::initializer_list<T>& values)
{
	Contiguous<T>::operator=(values) ;
	return *this ;
}

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T, size>::Array(const Array<T,size>& list) : Salih::Structures::Contiguous::Contiguous<T>(list) {} ;

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T, size>& Salih::Structures::Contiguous::Array<T, size>::operator=(const Array<T,size>& list)
{
	Contiguous<T>::operator=(list) ;
	return *this ;	
}

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T, size>::Array(Array<T,size>&& list) : Salih::Structures::Contiguous::Contiguous<T>(list) {} ;

template<typename T, std::size_t size> 
Salih::Structures::Contiguous::Array<T, size>& Salih::Structures::Contiguous::Array<T, size>::operator=(Array<T,size>&& list)
{
	Contiguous<T>::operator=(list) ;
	return *this ;	
}

template<typename T, std::size_t size>		
Salih::Structures::Contiguous::Array<T,size> Salih::Structures::Contiguous::Array<T,size>::operator()(const int x, const int y) const
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

template<typename T, std::size_t size> 			
Salih::Structures::Contiguous::Array<T,size>::~Array() {} ;	

#endif
