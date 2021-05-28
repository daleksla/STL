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
	if((check) && (x >= SIZE)) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T, std::size_t SIZE> 
const T& Salih::Structures::Contiguous::Array<T,SIZE>::at(const std::size_t x, const bool check) const
{
	if((check) && (x >= SIZE)) throw std::out_of_range("Element does not exist") ;
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

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::Iterator() : pointer(nullptr) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::Iterator(T* input) : pointer(input) {} ;

template<typename T, std::size_t SIZE> 
T& Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T, std::size_t SIZE> 
T* Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator->() const
{
	return this->pointer ; 
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator+(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::Iterator(this->pointer + x) ; 
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator& Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator& Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator++(const int)
{
	Salih::Structures::Contiguous::Array<T,SIZE>::Iterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator-(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::Iterator(this->pointer - x) ; 
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator& Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator& Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator--(const int)
{
	Salih::Structures::Contiguous::Array<T,SIZE>::Iterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
bool Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator==(const Salih::Structures::Contiguous::Array<T,SIZE>::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
bool Salih::Structures::Contiguous::Array<T,SIZE>::Iterator::operator!=(const Salih::Structures::Contiguous::Array<T,SIZE>::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

template<typename T, std::size_t SIZE> 
Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::ConstIterator(T const* input) : pointer(input) {} ;

template<typename T, std::size_t SIZE> 
const T& Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T, std::size_t SIZE> 
const T* Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator->() const
{
	return this->pointer ; 
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator+(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator(this->pointer + x) ; 
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator& Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator& Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator++(const int)
{
	Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator-(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator(this->pointer - x) ; 
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator& Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator& Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator--(const int)
{
	Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
bool Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator==(const Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
bool Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator::operator!=(const Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator Salih::Structures::Contiguous::Array<T,SIZE>::begin()
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::Iterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::Iterator Salih::Structures::Contiguous::Array<T,SIZE>::end()
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::Iterator(this->pointer + SIZE) ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::begin() const 
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::end() const
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator(this->pointer + SIZE) ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::cbegin() const 
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
typename Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator Salih::Structures::Contiguous::Array<T,SIZE>::cend() const
{
	return Salih::Structures::Contiguous::Array<T,SIZE>::ConstIterator(this->pointer + SIZE) ;
}

#endif
