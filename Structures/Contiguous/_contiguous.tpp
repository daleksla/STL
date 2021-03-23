#ifndef CONTIGUOUS_TPP
#define CONTIGUOUS_TPP
#pragma once

#include "_contiguous.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <stdexcept>
#include <initializer_list>

/* This file contains the implementation of the base class for contiguous memory structures 
 * It is located in the nested Salih, Structures, Contiguous namespace */

template<typename T>
Salih::Structures::Contiguous::Contiguous<T>::Contiguous(std::size_t size) : size(size)
{
	this->pointer = new T[this->size] ;
}


template<typename T>
Salih::Structures::Contiguous::Contiguous<T>::Contiguous(std::size_t size, const std::initializer_list<T>& values) : size(size)
{
	if(values.size() > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = new T[this->size] ;
	int i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
}

template<typename T>			
std::size_t Salih::Structures::Contiguous::Contiguous<T>::getSize() const
{
	return this->size ;
}

template<typename T>			
T& Salih::Structures::Contiguous::Contiguous<T>::operator[](const int x)
{
	if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T>		
const T& Salih::Structures::Contiguous::Contiguous<T>::operator[](const int x) const
{
	if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;	
}

template<typename T>		
bool Salih::Structures::Contiguous::Contiguous<T>::operator==(const Salih::Structures::Contiguous::Contiguous<T>& b) const
{
	if(this->size != b.size) return false ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T>		
bool Salih::Structures::Contiguous::Contiguous<T>::operator!=(const Salih::Structures::Contiguous::Contiguous<T>& b) const
{
	if(this->size == b.size) return false ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T>
void Salih::Structures::Contiguous::Contiguous<T>::del(const int index)
{
	if(index == 0 || index > this->size) throw std::out_of_range("Index does not exist") ;
	for(int i = index - 1 ; i < this->size ; i++)
	{
		this->pointer[i] = this->pointer[i+1] ;
	}
	this->size -= 1 ;
}
			
template<typename T>
Salih::Structures::Contiguous::Contiguous<T>::~Contiguous() 
{
	delete[] pointer ;
}

//helpful overloads

template<typename T>
std::ostream& operator<<(std::ostream& os, const Salih::Structures::Contiguous::Contiguous<T>& list)
{
	int size = list.getSize() ;
	for(int i = 0 ; i < size ; i++)
	{
		os << list[i] ;
		if(i + 1 >= size) os << "," ;
	}
}	

#endif
