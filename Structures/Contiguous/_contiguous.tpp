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
Salih::Structures::Contiguous::Contiguous<T>::Contiguous(const std::size_t SIZE) : size(SIZE)
{
	this->pointer = new T[this->size] ;
}

template<typename T>
Salih::Structures::Contiguous::Contiguous<T>::Contiguous(T* ptr, const std::size_t SIZE) : pointer(ptr), size(SIZE) {} ;

template<typename T>
Salih::Structures::Contiguous::Contiguous<T>::Contiguous(const std::initializer_list<T>& values, const std::size_t SIZE) : size(SIZE)
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

//template<typename T>
//Salih::Structures::Contiguous::Contiguous<T>& Salih::Structures::Contiguous::Contiguous<T>::operator=(const std::initializer_list<T>& values)
//{
//	//std::cout << SIZE << std::endl ;
//	//this->size = SIZE ;
//	if(values.size() > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
//	int i = 0 ;
//	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
//	{
//		this->pointer[i] = *it ;
//		i++ ;
//	}
//	return *this ;
//}

template<typename T>
Salih::Structures::Contiguous::Contiguous<T>::Contiguous(const Contiguous<T>& list, const std::size_t SIZE) : size(SIZE)
{
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = new T[list.size] ;
	for(int i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
}

//template<typename T>
//Salih::Structures::Contiguous::Contiguous<T>& Salih::Structures::Contiguous::Contiguous<T>::operator=(const Contiguous<T>& list)
//{
//	//this->size = SIZE ;
//	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
//	//this->size = list.size ;
//	for(int i = 0 ; i < list.size ; i++)
//	{
//		this->pointer[i] = list.pointer[i] ;
//	}
//	return *this ;
//}

template<typename T>
Salih::Structures::Contiguous::Contiguous<T>::Contiguous(Contiguous<T>&& list, const std::size_t SIZE) : size(SIZE)
{
	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
	this->pointer = list.pointer ;
	this->size = list.size ;
	list.pointer = nullptr ;
	list.size = 0 ;
}

//template<typename T>
//Salih::Structures::Contiguous::Contiguous<T>& Salih::Structures::Contiguous::Contiguous<T>::operator=(Contiguous<T>&& list)
//{
//	//this->size = SIZE ;
//	if(list.size > this->size) throw std::overflow_error("Size of array is smaller then amount of values provided") ;
//	this->pointer = list.pointer ;
//	//this->size = list.size ;
//	list.pointer = nullptr ;
//	list.size = 0 ;	
//	return *this ;
//}

template<typename T>		
std::size_t Salih::Structures::Contiguous::Contiguous<T>::getSize() const
{
	return this->size ;
}

template<typename T>		
T& Salih::Structures::Contiguous::Contiguous<T>::operator[](const std::size_t x)
{
	//if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T>		
const T& Salih::Structures::Contiguous::Contiguous<T>::operator[](const std::size_t x) const
{
	//if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;	
}

template<typename T>		
T& Salih::Structures::Contiguous::Contiguous<T>::at(const std::size_t x, const bool check)
{
	if(check) if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T>		
const T& Salih::Structures::Contiguous::Contiguous<T>::at(const std::size_t x, const bool check) const
{
	if(check) if(x > this->size - 1) throw std::out_of_range("Element does not exist") ;
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
template<typename OTHER>		
bool Salih::Structures::Contiguous::Contiguous<T>::operator==(const Salih::Structures::Contiguous::Contiguous<OTHER>& b) const
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
template<typename OTHER>				
bool Salih::Structures::Contiguous::Contiguous<T>::operator!=(const Salih::Structures::Contiguous::Contiguous<OTHER>& b) const
{
	if(this->size == b.size) return false ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}
			
template<typename T>		
Salih::Structures::Contiguous::Contiguous<T>::~Contiguous() 
{
	if(this->pointer != nullptr) delete[] this->pointer ;
}

//helpful overloads

#endif
