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

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>::Contiguous() : size(SIZE)
{
	this->pointer = new T[this->size] ;
}

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>::Contiguous(T* ptr, const std::size_t sizeP) : pointer(ptr), size(sizeP) {} ;

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>::Contiguous(const std::initializer_list<T>& values) : size(SIZE)
{
	//std::cout << SIZE << std::endl ;
	if(values.size() > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = new T[this->size] ;
	int i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
}

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>& Salih::Structures::Contiguous::Contiguous<T,SIZE>::operator=(const std::initializer_list<T>& values)
{
	this->size = SIZE ;
	if(values.size() > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	int i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
	return *this ;
}

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>::Contiguous(const Contiguous& list) : size(SIZE)
{
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = new T[list.size] ;
	for(int i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
}

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>& Salih::Structures::Contiguous::Contiguous<T,SIZE>::operator=(const Contiguous& list)
{
	this->size = SIZE ;
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	//this->size = list.size ;
	for(int i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
	return *this ;
}

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>::Contiguous(Contiguous&& list) : size(SIZE) 
{
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = list.pointer ;
	this->size = list.size ;
	list.pointer = nullptr ;
	list.size = 0 ;
}

template<typename T, std::size_t SIZE>
Salih::Structures::Contiguous::Contiguous<T,SIZE>& Salih::Structures::Contiguous::Contiguous<T,SIZE>::operator=(Contiguous&& list)
{
	this->size = SIZE ;
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = list.pointer ;
	//this->size = list.size ;
	list.pointer = nullptr ;
	list.size = 0 ;	
	return *this ;
}

template<typename T, std::size_t SIZE>		
std::size_t Salih::Structures::Contiguous::Contiguous<T,SIZE>::getSize() const
{
	return this->size ;
}

template<typename T, std::size_t SIZE>		
T& Salih::Structures::Contiguous::Contiguous<T,SIZE>::operator[](const int x)
{
	if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T, std::size_t SIZE>		
const T& Salih::Structures::Contiguous::Contiguous<T,SIZE>::operator[](const int x) const
{
	if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;	
}

template<typename T, std::size_t SIZE>		
bool Salih::Structures::Contiguous::Contiguous<T,SIZE>::operator==(const Salih::Structures::Contiguous::Contiguous<T,SIZE>& b) const
{
	if(this->size != b.size) return false ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T, std::size_t SIZE>		
bool Salih::Structures::Contiguous::Contiguous<T,SIZE>::operator!=(const Salih::Structures::Contiguous::Contiguous<T,SIZE>& b) const
{
	if(this->size == b.size) return false ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T, std::size_t SIZE>		
void Salih::Structures::Contiguous::Contiguous<T,SIZE>::del(const int index)
{
	if(index == 0 || index > this->size) throw std::out_of_range("Index does not exist") ;
	for(int i = index - 1 ; i < this->size ; i++)
	{
		this->pointer[i] = this->pointer[i+1] ;
	}
	this->size -= 1 ;
}
			
template<typename T, std::size_t SIZE>		
Salih::Structures::Contiguous::Contiguous<T,SIZE>::~Contiguous() 
{
	if(this->pointer != nullptr) delete[] this->pointer ;
}

//helpful overloads

template<typename T, std::size_t SIZE>		
std::ostream& operator<<(std::ostream& os, const Salih::Structures::Contiguous::Contiguous<T,SIZE>& list)
{
	os << "[" ;
	for(int i = 0 ; i < SIZE ; i++)
	{
		os << list[i] ;
		if( (i + 1) < SIZE) os << "," ;
	}
	os << "]" ;
	return os ;
}	

#endif
