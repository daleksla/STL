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
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::Vector() : size(0), pointer(new T[0]) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::Vector(const std::size_t SIZE) : size(SIZE), pointer(new T[SIZE]) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::Vector(const std::initializer_list<T>& values) : pointer(new T[values.size()]), size(values.size())
{
	std::size_t i = 0 ;
	for(auto it = std::begin(values) ; it != std::end(values) ; it = std::next(it))
	{
		this->pointer[i] = *it ;
		i++ ;
	}
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(const std::initializer_list<T>& values)
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
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::Vector(const Vector<T>& list) : size(list.size), pointer(new T[list.size])
{
	for(std::size_t i = 0 ; i < list.size ; i++)
	{
		this->pointer[i] = list.pointer[i] ;
	}
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(const Vector<T>& list)
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
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::Vector(Vector<T>&& list) : size(list.size), pointer(list.pointer)
{
	list.pointer = nullptr ;
	list.size = 0 ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator=(Vector<T>&& list)
{
	if(this->pointer != nullptr) delete[] this->pointer ;
	this->pointer = list.pointer ;
	this->size = list.size ;
	list.pointer = nullptr ;
	list.size = 0 ;
	return *this ;	
}

template<typename T>
_GLIBCXX20_CONSTEXPR void Salih::Structures::Contiguous::Vector<T>::append(T data)
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
_GLIBCXX20_CONSTEXPR void Salih::Structures::Contiguous::Vector<T>::clear()
{
	delete[] this->pointer ;
	this->pointer = new T[0] ;
	this->size = 0 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR void Salih::Structures::Contiguous::Vector<T>::insert(const std::size_t pos, T data)
{
	if(pos == 0 || pos > this->size + 1) throw std::out_of_range("Invalid insert position") ;	
	else if(pos == this->size + 1) return this->append(data) ;
	T* ptr = new T[this->size+1] ;
	bool check = false ;
	for(std::size_t i = 0 ; i < this->size ; i++) 
	{
		if(i == (pos - 1))
		{
			ptr[i] = data ;
			check = true ;
			continue ;
		}
		
		if(check) ptr[i+1] = this->pointer[i] ;
		else ptr[i] = this->pointer[i] ;	
	}
	delete[] this->pointer ;
	this->pointer = ptr ;
	this->size += 1 ;
}

template<typename T>
_GLIBCXX20_CONSTEXPR void Salih::Structures::Contiguous::Vector<T>::del(const std::size_t pos)
{
	if(pos == 0 || pos > this->size) throw std::out_of_range("Index does not exist") ;	
	T* ptr = new T[this->size-1] ;
	bool check = false ;
	for(std::size_t i = 0 ; i < this->size ; i++) 
	{
		if(i == (pos - 1))
		{
			check = true ;
			continue ;
		}
		
		if(check) ptr[i-1] = this->pointer[i] ;
		else ptr[i] = this->pointer[i] ;	
	}
	delete[] this->pointer ;
	this->pointer = ptr ;
	this->size -= 1 ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::~Vector()
{
	if(this->pointer != nullptr) delete[] this->pointer ;
}

template<typename T>		
_GLIBCXX20_CONSTEXPR std::size_t Salih::Structures::Contiguous::Vector<T>::getSize() const
{
	return this->size ;
}	

template<typename T>		
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T> Salih::Structures::Contiguous::Vector<T>::operator()(const std::size_t a, const std::size_t b) const
{
	if(a > b || a < 0 || b > this->size) throw std::out_of_range("Element range requested does not exist") ;
	Salih::Structures::Contiguous::Vector<T> tmp(b-a) ;
	for(std::size_t idx = a ; idx < b ; idx++) tmp[idx-a] = this->pointer[idx] ;
	return tmp ;
}

template<typename T>		
_GLIBCXX20_CONSTEXPR T& Salih::Structures::Contiguous::Vector<T>::operator[](const std::size_t x)
{
	return this->pointer[x] ;
} 

template<typename T>		
_GLIBCXX20_CONSTEXPR const T& Salih::Structures::Contiguous::Vector<T>::operator[](const std::size_t x) const
{
	return this->pointer[x] ;	
}

template<typename T>		
_GLIBCXX20_CONSTEXPR T& Salih::Structures::Contiguous::Vector<T>::at(const std::size_t x)
{
	if(x >= this->size) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;
} 

template<typename T>		
_GLIBCXX20_CONSTEXPR const T& Salih::Structures::Contiguous::Vector<T>::at(const std::size_t x) const
{
	if(x >= this->size) throw std::out_of_range("Element does not exist") ;
	return this->pointer[x] ;	
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T> Salih::Structures::Contiguous::Vector<T>::operator+(const Salih::Structures::Contiguous::Vector<T>& vec) const
{
	Vector<T> tmp(this->size + vec.size) ;
	
	for(std::size_t i = 0 ; i < this->size ; i++) tmp.pointer[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < vec.size ; i++) tmp.pointer[i+this->size] = vec.pointer[i] ;
	
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>& Salih::Structures::Contiguous::Vector<T>::operator+=(const Salih::Structures::Contiguous::Vector<T>& vec)
{
	T* tmp = new T[this->size + vec.size] ;
	
	for(std::size_t i = 0 ; i < this->size ; i++) tmp[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < vec.size ; i++) tmp[i+this->size] = vec.pointer[i] ;
	
	this->size = this->size + vec.size ;
	delete[] this->pointer ;
	this->pointer = tmp ;
	
	return *this ;
}

template<typename T>		
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::operator==(const Salih::Structures::Contiguous::Vector<T>& b) const
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
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::operator==(const Salih::Structures::Contiguous::Vector<OTHER>& b) const
{
	if(this->size != b.size) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T>		
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::operator!=(const Salih::Structures::Contiguous::Vector<T>& b) const
{
	if(this->size != b.size) return true ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T>
template<typename OTHER>				
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::operator!=(const Salih::Structures::Contiguous::Vector<OTHER>& b) const
{
	if(this->size == b.size) return true ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::Iterator::Iterator() : pointer(nullptr) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::Iterator::Iterator(T* input) : pointer(input) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR T& Salih::Structures::Contiguous::Vector<T>::Iterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR T* Salih::Structures::Contiguous::Vector<T>::Iterator::operator->() const
{
	return this->pointer ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator Salih::Structures::Contiguous::Vector<T>::Iterator::operator+(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Vector<T>::Iterator(this->pointer + x) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator& Salih::Structures::Contiguous::Vector<T>::Iterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator& Salih::Structures::Contiguous::Vector<T>::Iterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator Salih::Structures::Contiguous::Vector<T>::Iterator::operator++(const int)
{
	Salih::Structures::Contiguous::Vector<T>::Iterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator Salih::Structures::Contiguous::Vector<T>::Iterator::operator-(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Vector<T>::Iterator(this->pointer - x) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator& Salih::Structures::Contiguous::Vector<T>::Iterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator& Salih::Structures::Contiguous::Vector<T>::Iterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator Salih::Structures::Contiguous::Vector<T>::Iterator::operator--(const int)
{
	Salih::Structures::Contiguous::Vector<T>::Iterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::Iterator::operator==(const Salih::Structures::Contiguous::Vector<T>::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::Iterator::operator!=(const Salih::Structures::Contiguous::Vector<T>::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR Salih::Structures::Contiguous::Vector<T>::ConstIterator::ConstIterator(T const* input) : pointer(input) {} ;

template<typename T> 
_GLIBCXX20_CONSTEXPR const T& Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR const T* Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator->() const
{
	return this->pointer ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator+(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Vector<T>::ConstIterator(this->pointer + x) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator& Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator& Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator++(const int)
{
	Salih::Structures::Contiguous::Vector<T>::ConstIterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator-(const std::size_t x) const
{
	return Salih::Structures::Contiguous::Vector<T>::ConstIterator(this->pointer - x) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator& Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator& Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator--(const int)
{
	Salih::Structures::Contiguous::Vector<T>::ConstIterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator==(const Salih::Structures::Contiguous::Vector<T>::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR bool Salih::Structures::Contiguous::Vector<T>::ConstIterator::operator!=(const Salih::Structures::Contiguous::Vector<T>::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator Salih::Structures::Contiguous::Vector<T>::begin()
{
	return Salih::Structures::Contiguous::Vector<T>::Iterator(this->pointer) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::Iterator Salih::Structures::Contiguous::Vector<T>::end()
{
	return Salih::Structures::Contiguous::Vector<T>::Iterator(this->pointer + this->size) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::begin() const 
{
	return Salih::Structures::Contiguous::Vector<T>::ConstIterator(this->pointer) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::end() const
{
	return Salih::Structures::Contiguous::Vector<T>::ConstIterator (this->pointer + this->size) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::cbegin() const 
{
	return Salih::Structures::Contiguous::Vector<T>::ConstIterator(this->pointer) ;
}

template<typename T> 
_GLIBCXX20_CONSTEXPR typename Salih::Structures::Contiguous::Vector<T>::ConstIterator Salih::Structures::Contiguous::Vector<T>::cend() const
{
	return Salih::Structures::Contiguous::Vector<T>::ConstIterator(this->pointer + this->size) ;
}

#endif
