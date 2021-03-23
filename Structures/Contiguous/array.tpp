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
Salih::Structures::Contiguous::Array<T,size>::Array(const std::initializer_list<T>& list) : Salih::Structures::Contiguous::Contiguous<T>(size, list) {} ;

template<typename T, std::size_t size>		
constexpr std::size_t Salih::Structures::Contiguous::Array<T,size>::deduct(const int y, const int x)
{
	return y-x ;	
}

template<typename T, std::size_t size>		
Salih::Structures::Contiguous::Array<T,size> Salih::Structures::Contiguous::Array<T,size>::operator()(const int x, const int y) const
{
	if(x < 0 || x > this->size - 1 || y < x || y > this->size - 1) throw std::out_of_range("Element range does not exist") ;
	//constexpr std::size_t calculatedSize = deduct(y,x) ;
	Array<T, deduct(y,x)> tmp ;
	for(int i = x ; i < y ; i++)
	{
		tmp.pointer[i-x] = this->pointer[i] ;
	}
	return tmp ;
}

template<typename T, std::size_t size> 			
Salih::Structures::Contiguous::Array<T,size>::~Array() {} ;	

#endif
