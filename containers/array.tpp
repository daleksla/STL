#ifndef ARRAY_TPP
#define ARRAY_TPP
#pragma once

#include <stdexcept>

/* This file contains the declarations and implementations of a array-based (child) contiguous structure 
 * It is located in the Salih, Structures, Contiguous namespaces */

template<typename T, std::size_t SIZE> 
constexpr std::size_t salih::containers::Array<T, SIZE>::getSize() const
{
	return SIZE ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR T& salih::containers::Array<T, SIZE>::operator[](const std::size_t x)
{
	return this->pointer[x] ;
} 

template<typename T, std::size_t SIZE> 
constexpr const T& salih::containers::Array<T, SIZE>::operator[](const std::size_t x) const
{
	return this->pointer[x] ;	
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR T& salih::containers::Array<T, SIZE>::at(const std::size_t x)
{
	// boolean ? lvalue : (throw-expr, lvalue)
	return x < SIZE ? this->pointer[x]
	  : (throw std::out_of_range("Element does not exist"), this->pointer[0]) ;
}

template<typename T, std::size_t SIZE> 
constexpr const T& salih::containers::Array<T,SIZE>::at(const std::size_t x) const
{
	// boolean ? lvalue : (throw-expr, lvalue)
	return x < SIZE ? this->pointer[x]
	  : (throw std::out_of_range("Element does not exist"), this->pointer[0]) ;
}	

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR salih::containers::Array<T,(SIZE+SIZE)> salih::containers::Array<T,SIZE>::operator+(const salih::containers::Array<T,SIZE>& arr) const
{
	Array<T,(SIZE+SIZE)> tmp ;
	
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp.pointer[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp.pointer[i+SIZE] = arr.pointer[i] ;
	
	return tmp ;
}

template<typename T, std::size_t SIZE> 
template<std::size_t DIFF>
_GLIBCXX14_CONSTEXPR salih::containers::Array<T,(SIZE+DIFF)> salih::containers::Array<T,SIZE>::operator+(const salih::containers::Array<T,DIFF>& arr) const
{
	Array<T,(SIZE+DIFF)> tmp ;
	
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp.pointer[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < DIFF ; i++) tmp.pointer[i+SIZE] = arr.pointer[i] ;
	
	return tmp ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<T,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T, std::size_t SIZE> 
template<typename OTHER>
_GLIBCXX14_CONSTEXPR bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<OTHER,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T, std::size_t SIZE> 
template<std::size_t  DIFF>
constexpr bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<T,DIFF>& b) const
{
	return false ;
}

template<typename T, std::size_t SIZE> 
template<typename OTHER, std::size_t  DIFF>
constexpr bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<OTHER,DIFF>& b) const
{
	return false ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<T,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T, std::size_t SIZE> 
template<typename OTHER>
_GLIBCXX14_CONSTEXPR bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<OTHER,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T, std::size_t SIZE> 
template<std::size_t  DIFF>
constexpr bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<T,DIFF>& b) const
{
	return true ;
}

template<typename T, std::size_t SIZE> 
template<typename OTHER, std::size_t DIFF>
constexpr bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<OTHER,DIFF>& b) const
{
	return true ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR salih::containers::Array<T,SIZE>::Iterator::Iterator() : pointer(nullptr) {} ;

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR salih::containers::Array<T,SIZE>::Iterator::Iterator(T* input) : pointer(input) {} ;

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR T& salih::containers::Array<T,SIZE>::Iterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR T* salih::containers::Array<T,SIZE>::Iterator::operator->() const
{
	return this->pointer ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator+(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer + x) ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator++(const int)
{
	salih::containers::Array<T,SIZE>::Iterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator-(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer - x) ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator--(const int)
{
	salih::containers::Array<T,SIZE>::Iterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR bool salih::containers::Array<T,SIZE>::Iterator::operator==(const salih::containers::Array<T,SIZE>::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR bool salih::containers::Array<T,SIZE>::Iterator::operator!=(const salih::containers::Array<T,SIZE>::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
constexpr salih::containers::Array<T,SIZE>::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

template<typename T, std::size_t SIZE> 
constexpr salih::containers::Array<T,SIZE>::ConstIterator::ConstIterator(T const* input) : pointer(input) {} ;

template<typename T, std::size_t SIZE> 
constexpr const T& salih::containers::Array<T,SIZE>::ConstIterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T, std::size_t SIZE> 
constexpr const T* salih::containers::Array<T,SIZE>::ConstIterator::operator->() const
{
	return this->pointer ; 
}

template<typename T, std::size_t SIZE> 
constexpr typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator+(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer + x) ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator++(const int)
{
	salih::containers::Array<T,SIZE>::ConstIterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
constexpr typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator-(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer - x) ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator--(const int)
{
	salih::containers::Array<T,SIZE>::ConstIterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

template<typename T, std::size_t SIZE> 
constexpr bool salih::containers::Array<T,SIZE>::ConstIterator::operator==(const salih::containers::Array<T,SIZE>::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
constexpr bool salih::containers::Array<T,SIZE>::ConstIterator::operator!=(const salih::containers::Array<T,SIZE>::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::begin()
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
_GLIBCXX14_CONSTEXPR typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::end()
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer + SIZE) ;
}

template<typename T, std::size_t SIZE> 
constexpr typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::begin() const 
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
constexpr typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::end() const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer + SIZE) ;
}

template<typename T, std::size_t SIZE> 
constexpr typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::cbegin() const 
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
constexpr typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::cend() const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer + SIZE) ;
}

#endif
