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
Salih::Structures::Contiguous::Array<T,SIZE>::Array() 
{
	//T tmp[SIZE] ;
	//this->pointer = tmp ;
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Array(const std::initializer_list<T>& values)
{
	if(values.size() > SIZE) throw std::overflow_error("Size of values is larger than destination array") ;
	//T tmp[SIZE] ;
	//this->pointer = tmp ;
	std::size_t i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(const std::initializer_list<T>& values)
{
	if(values.size() > SIZE) throw std::overflow_error("Size of values is larger than destination array") ;
	std::size_t i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
	return *this ;
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>::Array(const Array<T,SIZE>& list)
{
	//T tmp[SIZE] ;
	//this->pointer = tmp ;
	for(std::size_t i = 0 ; i < list.getSize() ; i++)
	{
		this->pointer[i] = list[i] ;
	}		
}

template<typename T, std::size_t SIZE> 
template<std::size_t DIFF> 
Salih::Structures::Contiguous::Array<T, SIZE>::Array(const Array<T,DIFF>& list)
{
	static_assert(SIZE > DIFF, "Origin array is larger than destination array") ;
	//T tmp[SIZE] ;
	//this->pointer = tmp ;
	for(std::size_t i = 0 ; i < list.getSize() ; i++)
	{
		this->pointer[i] = list[i] ;
	}		
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T, SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(const Array<T,SIZE>& list)
{
	//T tmp[SIZE] ;
	//this->pointer = tmp ;
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
	return *this ;	
}

template<typename T, std::size_t SIZE> 
template<std::size_t DIFF> 
Salih::Structures::Contiguous::Array<T, SIZE>& Salih::Structures::Contiguous::Array<T, SIZE>::operator=(const Array<T,DIFF>& list)
{
	static_assert(SIZE > DIFF, "Origin array is larger than destination array") ;
	//T tmp[SIZE] ;
	//this->pointer = tmp ;
	for(std::size_t i = 0 ; i < DIFF ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
	return *this ;		
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::~Array() 
{
	//this->pointer = nullptr ;
}

template<typename T, std::size_t SIZE> 
constexpr std::size_t Salih::Structures::Contiguous::Array<T, SIZE>::getSize() const
{
	return SIZE ;
}

template<typename T, std::size_t SIZE> 
T& Salih::Structures::Contiguous::Array<T, SIZE>::operator[](const std::size_t x)
{
	return this->pointer[x] ;
} 

template<typename T, std::size_t SIZE> 
const T& Salih::Structures::Contiguous::Array<T, SIZE>::operator[](const std::size_t x) const
{
	return this->pointer[x] ;	
}

template<typename T, std::size_t SIZE> 
T& Salih::Structures::Contiguous::Array<T, SIZE>::at(const std::size_t x, const bool check)
{
	if(check && x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T, std::size_t SIZE> 
const T& Salih::Structures::Contiguous::Array<T,SIZE>::at(const std::size_t x, const bool check) const
{
	if(check && x > this->size - 1) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;	
}	

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,(SIZE+SIZE)> Salih::Structures::Contiguous::Array<T,SIZE>::operator+(const Salih::Structures::Contiguous::Array<T,SIZE>& arr) const
{
	Array<T,(SIZE+SIZE)> tmp ;
	
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp->pointer[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp->pointer[i+SIZE] = arr.pointer[i] ;
	
	return tmp ;
}

template<typename T, std::size_t SIZE> 
template<std::size_t DIFF>
Salih::Structures::Contiguous::Array<T,(SIZE+DIFF)> Salih::Structures::Contiguous::Array<T,SIZE>::operator+(const Salih::Structures::Contiguous::Array<T,DIFF>& arr) const
{
	Array<T,(SIZE+DIFF)> tmp ;
	
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp->pointer[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < DIFF ; i++) tmp->pointer[i+SIZE] = arr.pointer[i] ;
	
	return tmp ;
}

template<typename T, std::size_t SIZE> 
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator==(const Salih::Structures::Contiguous::Array<T,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T, std::size_t SIZE> 
template<typename OTHER>
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator==(const Salih::Structures::Contiguous::Array<OTHER,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T, std::size_t SIZE> 
template<std::size_t  DIFF>
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator==(const Salih::Structures::Contiguous::Array<T,DIFF>& b) const
{
	return false ;
}

template<typename T, std::size_t SIZE> 
template<typename OTHER, std::size_t  DIFF>
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator==(const Salih::Structures::Contiguous::Array<OTHER,DIFF>& b) const
{
	return false ;
}

template<typename T, std::size_t SIZE> 
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator!=(const Salih::Structures::Contiguous::Array<T,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T, std::size_t SIZE> 
template<typename OTHER>
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator!=(const Salih::Structures::Contiguous::Array<OTHER,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T, std::size_t SIZE> 
template<std::size_t  DIFF>
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator!=(const Salih::Structures::Contiguous::Array<T,DIFF>& b) const
{
	return true ;
}

template<typename T, std::size_t SIZE> 
template<typename OTHER, std::size_t DIFF>
bool Salih::Structures::Contiguous::Array<T,SIZE>::operator!=(const Salih::Structures::Contiguous::Array<OTHER,DIFF>& b) const
{
	return true ;
}

#endif
