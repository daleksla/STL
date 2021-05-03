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
Salih::Structures::Contiguous::Vector<T>::Vector() : size(0)
{
	this->pointer = new T[this->size] ;
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(const std::size_t SIZE) : size(SIZE)
{
	this->pointer = new T[this->size] ;
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(T* dumbArray, const std::size_t sizing) : pointer(dumbArray), size(sizing) {} ;

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(const std::initializer_list<T>& values) : size(values.size())
{
	this->pointer = new T[this->size] ;
	std::size_t i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(const std::initializer_list<T>& values)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = values.size() ;
	this->pointer = new T[this->size] ;
	std::size_t i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
	return *this ;
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(const Vector<T>& list) : size(list.size)
{
	this->pointer = new T[this->size] ;
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(const Vector<T>& list)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->size = list.size ;
	this->pointer = new T[this->size] ;
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
	return *this ;	
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::Vector(Vector<T>&& list) : size(list.size), pointer(list.pointer)
{
	list.pointer = nullptr ;
	list.size = 0 ;
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(Vector<T>&& list)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
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
	for(std::size_t i = 0 ; i < this->size ; i++)
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
	delete[] this->pointer ;
	this->pointer = new T[0] ;
	this->size = 0 ;
}

template<typename T> 
Salih::Structures::Contiguous::Vector<T>::~Vector()
{
	if(this->pointer != nullptr) delete[] this->pointer ;
}

template<typename T>		
std::size_t Salih::Structures::Contiguous::Vector<T>::getSize() const
{
	return this->size ;
}	

template<typename T>		
T& Salih::Structures::Contiguous::Vector<T>::operator[](const std::size_t x)
{
	return this->pointer[x] ;
} 

template<typename T>		
const T& Salih::Structures::Contiguous::Vector<T>::operator[](const std::size_t x) const
{
	return this->pointer[x] ;	
}

template<typename T>		
T& Salih::Structures::Contiguous::Vector<T>::at(const std::size_t x, const bool check)
{
	if(check && x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T>		
const T& Salih::Structures::Contiguous::Vector<T>::at(const std::size_t x, const bool check) const
{
	if(check && x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;	
}

template<typename T>		
bool Salih::Structures::Contiguous::Vector<T>::operator==(const Salih::Structures::Contiguous::Vector<T>& b) const
{
	if(this->size != b.size) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T>
template<typename OTHER>		
bool Salih::Structures::Contiguous::Vector<T>::operator==(const Salih::Structures::Contiguous::Vector<OTHER>& b) const
{
	if(this->size != b.size) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T>		
bool Salih::Structures::Contiguous::Vector<T>::operator!=(const Salih::Structures::Contiguous::Vector<T>& b) const
{
	if(this->size == b.size) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T>
template<typename OTHER>				
bool Salih::Structures::Contiguous::Vector<T>::operator!=(const Salih::Structures::Contiguous::Vector<OTHER>& b) const
{
	if(this->size == b.size) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

#endif
