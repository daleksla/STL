#ifndef ARRAY_TPP
#define ARRAY_TPP
#pragma once

#include "array.hpp"
#include <algorithm>
#include <type_traits>
#include <iostream>
#include <iterator>
#include <utility>
#include <stdexcept>
#include <initializer_list>

/* This file contains the declarations and implementations of a array-based (child) contiguous structure 
 * It is located in the Salih, Structures, Contiguous namespaces */

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Array() : Salih::Structures::Contiguous::Contiguous<T>(SIZE) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Array(T* dumbArray, const std::size_t sizing) : Salih::Structures::Contiguous::Contiguous<T>(dumbArray, sizing) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Array(const std::initializer_list<T>& values) : Salih::Structures::Contiguous::Contiguous<T>(values, SIZE) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(const std::initializer_list<T>& values)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = SIZE ;
	if(values.size() > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = new T[this->size] ;
	int i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
	return *this ;
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>::Array(const Array<T,SIZE>& list) : Salih::Structures::Contiguous::Contiguous<T>(list, SIZE) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(const Array<T,SIZE>& list)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = SIZE ;
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = new T[list.size] ;
	for(int i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
	return *this ;	
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>::Array(Array<T,SIZE>&& list) : Salih::Structures::Contiguous::Contiguous<T>(std::move(list), SIZE) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(Array<T,SIZE>&& list)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = SIZE ;
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = list.pointer ;
	this->size = list.size ;
	list.pointer = nullptr ;
	list.size = 0 ;
	return *this ;	
}

//template<typename T, std::size_t SIZE> 
//template<std::size_t NEW_SIZE>
//Salih::Structures::Contiguous::Array<T,NEW_SIZE> Salih::Structures::Contiguous::Array<T,SIZE>::operator()(const int x, const int y) const
//{
//	if(x < 0 || x > this->size - 1 || y < x || y > this->size - 1) throw std::out_of_range("Element range does not exist") ;
//	const int SIZE_TMP = y - x ;
//	std::cout << SIZE_TMP << std::endl ;
//	T* ARRAY = new T[SIZE_TMP] ;
//	for(int i = x ; i < y ; i++)
//	{
//		ARRAY[i-x] = this->pointer[i] ;
//	}
//	return Array<T, NEW_SIZE>(ARRAY, SIZE_TMP) ;
//}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::~Array() {} ;	

#endif
