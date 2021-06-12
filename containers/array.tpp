#ifndef ARRAY_TPP
#define ARRAY_TPP
#pragma once

#include "../types/macros.hpp"
#include <stdexcept>

/** @brief Implementations of Array (C-style) wrapper. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 T* salih::containers::Array<T, SIZE>::get() const
{
	return this->pointer ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 std::size_t salih::containers::Array<T, SIZE>::getSize() const
{
	return SIZE ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 T& salih::containers::Array<T, SIZE>::operator[](const std::size_t x)
{
	return this->pointer[x] ;
} 

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 const T& salih::containers::Array<T, SIZE>::operator[](const std::size_t x) const
{
	return this->pointer[x] ;	
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 T& salih::containers::Array<T, SIZE>::at(const std::size_t x)
{
	// boolean ? lvalue : (throw-expr, lvalue)
	return x < SIZE ? this->pointer[x]
	  : (throw std::out_of_range("Element does not exist"), this->pointer[0]) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 const T& salih::containers::Array<T,SIZE>::at(const std::size_t x) const
{
	// boolean ? lvalue : (throw-expr, lvalue)
	return x < SIZE ? this->pointer[x]
	  : (throw std::out_of_range("Element does not exist"), this->pointer[0]) ;
}	

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 salih::containers::Array<T,(SIZE+SIZE)> salih::containers::Array<T,SIZE>::operator+(const salih::containers::Array<T,SIZE>& arr) const
{
	Array<T,(SIZE+SIZE)> tmp ;
	
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp.pointer[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp.pointer[i+SIZE] = arr.pointer[i] ;
	
	return tmp ;
}

template<typename T, std::size_t SIZE> 
template<std::size_t DIFF>
CONSTEXPRCXX14 salih::containers::Array<T,(SIZE+DIFF)> salih::containers::Array<T,SIZE>::operator+(const salih::containers::Array<T,DIFF>& arr) const
{
	Array<T,(SIZE+DIFF)> tmp ;
	
	for(std::size_t i = 0 ; i < SIZE ; i++) tmp.pointer[i] = this->pointer[i] ;
	for(std::size_t i = 0 ; i < DIFF ; i++) tmp.pointer[i+SIZE] = arr.pointer[i] ;
	
	return tmp ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<T,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T, std::size_t SIZE> 
template<typename OTHER>
CONSTEXPRCXX14 bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<OTHER,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return false ;
	}
	
	return true ;	
}

template<typename T, std::size_t SIZE> 
template<std::size_t  DIFF>
CONSTEXPRCXX11 bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<T,DIFF>& b) const
{
	return false ;
}

template<typename T, std::size_t SIZE> 
template<typename OTHER, std::size_t  DIFF>
CONSTEXPRCXX11 bool salih::containers::Array<T,SIZE>::operator==(const salih::containers::Array<OTHER,DIFF>& b) const
{
	return false ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<T,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T, std::size_t SIZE> 
template<typename OTHER>
CONSTEXPRCXX14 bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<OTHER,SIZE>& b) const
{
	for(std::size_t i = 0 ; i < SIZE ; i++)
	{
		if(this->pointer[i] != b.pointer[i]) return true ;
	}
	
	return false ;	
}

template<typename T, std::size_t SIZE> 
template<std::size_t  DIFF>
CONSTEXPRCXX11 bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<T,DIFF>& b) const
{
	return true ;
}

template<typename T, std::size_t SIZE> 
template<typename OTHER, std::size_t DIFF>
CONSTEXPRCXX11 bool salih::containers::Array<T,SIZE>::operator!=(const salih::containers::Array<OTHER,DIFF>& b) const
{
	return true ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 salih::containers::Array<T,SIZE>::Iterator::Iterator() : pointer(nullptr) {} ;

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 salih::containers::Array<T,SIZE>::Iterator::Iterator(T* input) : pointer(input) {} ;

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 T& salih::containers::Array<T,SIZE>::Iterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 T* salih::containers::Array<T,SIZE>::Iterator::operator->() const
{
	return this->pointer ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator+(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer + x) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator++(const int)
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer++) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator-(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer - x) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator& salih::containers::Array<T,SIZE>::Iterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::Iterator::operator--(const int)
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer--) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 bool salih::containers::Array<T,SIZE>::Iterator::operator==(const salih::containers::Array<T,SIZE>::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 bool salih::containers::Array<T,SIZE>::Iterator::operator!=(const salih::containers::Array<T,SIZE>::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 salih::containers::Array<T,SIZE>::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 salih::containers::Array<T,SIZE>::ConstIterator::ConstIterator(T const* input) : pointer(input) {} ;

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 const T& salih::containers::Array<T,SIZE>::ConstIterator::operator*() const
{
	return *this->pointer ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 const T* salih::containers::Array<T,SIZE>::ConstIterator::operator->() const
{
	return this->pointer ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator+(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer + x) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator++(const int)
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer++) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator-(const std::size_t x) const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer - x) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::ConstIterator& salih::containers::Array<T,SIZE>::ConstIterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::ConstIterator::operator--(const int)
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer--) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 bool salih::containers::Array<T,SIZE>::ConstIterator::operator==(const salih::containers::Array<T,SIZE>::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 bool salih::containers::Array<T,SIZE>::ConstIterator::operator!=(const salih::containers::Array<T,SIZE>::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::begin()
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX14 typename salih::containers::Array<T,SIZE>::Iterator salih::containers::Array<T,SIZE>::end()
{
	return salih::containers::Array<T,SIZE>::Iterator(this->pointer + SIZE) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::begin() const 
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::end() const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer + SIZE) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::cbegin() const 
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer) ;
}

template<typename T, std::size_t SIZE> 
CONSTEXPRCXX11 typename salih::containers::Array<T,SIZE>::ConstIterator salih::containers::Array<T,SIZE>::cend() const
{
	return salih::containers::Array<T,SIZE>::ConstIterator(this->pointer + SIZE) ;
}

#endif
