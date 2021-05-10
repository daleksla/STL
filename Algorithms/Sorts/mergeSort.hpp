#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "_flags.hpp"
#include <iostream>

/** @brief Merge sort algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Sorts {

	template<typename U, typename = typename std::enable_if<Salih::Types::Traits::getDimensions<U>::value==0,U>::type, std::size_t SIZE>
	inline Salih::Structures::Contiguous::Array<U, SIZE+SIZE> merge(const Salih::Structures::Contiguous::Array<U, SIZE>& x, const Salih::Structures::Contiguous::Array<U, SIZE>& y, bool(*const order)(int, int) = ASCEND)
	/** This is the merging subroutine - it works by taking two lists and adding the smallest / the largest value from each, such that the resulting list is a combined list in order
	This subroutine is an overload specifically for two given Array class' whereby they are of the same size, which cannot use the generic list version due to the need of compile-time setup / preallocation, which other containers have no need or capability of
	 * @param const reference to list (one of the lists)
	 * @param const reference to list (another list)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{	
		Salih::Structures::Contiguous::Array<U, SIZE+SIZE> out ;
		std::size_t i = 0, j = 0, k = 0 ;
		
		while(i < x.getSize() && j < y.getSize())
		{
			if((*order)(x[i],y[j]))
			{
				out[k] = (x[i]) ;
				i += 1 ;
			}
			else {
				out[k] = (y[j]) ;
				j += 1 ;
			}
			k += 1 ;
		}
		while(i < x.getSize())
		{
			out[k] = (x[i]) ;
			i += 1 ;
			k += 1 ;
		}
		while(j < y.getSize())
		{
			out[k] = (y[j]) ;
			j += 1 ;
			k += 1 ;
		}
		
		return out ;
	}
	
	template<typename U, typename = typename std::enable_if<Salih::Types::Traits::getDimensions<U>::value==0,U>::type, std::size_t SIZE, std::size_t DIFF>
	inline Salih::Structures::Contiguous::Array<U, SIZE+DIFF> merge(const Salih::Structures::Contiguous::Array<U, SIZE>& x, const Salih::Structures::Contiguous::Array<U, DIFF>& y, bool(*const order)(int, int) = ASCEND)
	/** This is the merging subroutine - it works by taking two lists and adding the smallest / the largest value from each, such that the resulting list is a combined list in order
	This subroutine is an overload specifically for two given Array class' whereby they are of a different size, which cannot use the generic list version due to the need of compile-time setup / preallocation, which other containers have no need or capability of
	 * @param const reference to list (one of the lists)
	 * @param const reference to list (another list)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{	
		Salih::Structures::Contiguous::Array<U, SIZE+DIFF> out ;
		std::size_t i = 0, j = 0, k = 0 ;
		
		while(i < x.getSize() && j < y.getSize())
		{
			if((*order)(x[i],y[j]))
			{
				out[k] = (x[i]) ;
				i += 1 ;
			}
			else {
				out[k] = (y[j]) ;
				j += 1 ;
			}
			k += 1 ;
		}
		while(i < x.getSize())
		{
			out[k] = (x[i]) ;
			i += 1 ;
			k += 1 ;
		}
		while(j < y.getSize())
		{
			out[k] = (y[j]) ;
			j += 1 ;
			k += 1 ;
		}
		
		return out ;
	}

	template<typename T, typename = typename std::enable_if< (Salih::Types::Traits::isList<T>::value && Salih::Types::Traits::isDynamic<T>::value && Salih::Types::Traits::getDimensions<T>::value == 1), T >::type>
	inline T merge(const T& x, const T& y, bool(*const order)(int, int) = ASCEND)
	/** This is the merging subroutine - it works by taking two lists and adding the smallest / the largest value from each, such that the resulting list is a combined list in order
	 * @param const reference to list (one of the lists)
	 * @param const reference to list (another list)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{	
		T out ;
		std::size_t i = 0, j = 0, k = 0 ;
		
		while(i < x.getSize() && j < y.getSize())
		{
			if((*order)(x[i],y[j]))
			{
				out.append(x[i]) ;
				i += 1 ;
			}
			else {
				out.append(y[j]) ;
				j += 1 ;
			}
			k += 1 ;
		}
		while(i < x.getSize())
		{
			out.append(x[i]) ;
			i += 1 ;
			k += 1 ;
		}
		while(j < y.getSize())
		{
			out.append(y[j]) ;
			j += 1 ;
			k += 1 ;
		}
		
		return out ;
	}

	template<typename T, typename = typename std::enable_if< (Salih::Types::Traits::isList<T>::value && Salih::Types::Traits::isDynamic<T>::value && Salih::Types::Traits::getDimensions<T>::value == 1), T >::type>
	T mergeSort(const T& data, bool(*const order)(int, int) = ASCEND)
	/** This is the merge sort algorithm. It works splitting a list into minimal sublists and combining two, in order, into a bigger list. It keeps merging the lists together, then the merged lists together, until a fully sorted list is formed
	 * @param const refernece to list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{			
		std::size_t listLength = data.getSize() ;
		
		if(listLength <= 1) return data ;
		
		T a, b ;
		
		for(std::size_t i = 0 ; i < std::size_t(listLength / 2) ; i++) a.append(data[i]) ;
		for(std::size_t i = std::size_t(listLength / 2) ; i < listLength ; i++) b.append(data[i]) ;
			
		a = mergeSort(a, order) ;
		b = mergeSort(b, order) ;
		
		return merge(a, b, order) ;
	}
	
	template<typename U, typename = typename std::enable_if<Salih::Types::Traits::getDimensions<U>::value==0,U>::type, std::size_t SIZE>
	Salih::Structures::Contiguous::Array<U, SIZE> mergeSort(const Salih::Structures::Contiguous::Array<U, SIZE>& data, bool(*const order)(int, int) = ASCEND)
	/** This is the merge sort algorithm. It works splitting a list into minimal sublists and combining two, in order, into a bigger list. It keeps merging the lists together, then the merged lists together, until a fully sorted list is formed
	This algorithm is an overload specifically for a given Array class', which cannot use the generic list version due to the need of compile-time setup / preallocation, which other containers have no need or capability of
	 * @param const refernece to list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{				
		if(SIZE <= 1) return data ;
		
		Salih::Structures::Contiguous::Array<U,SIZE/2> a, b ;
		
		for(std::size_t i = 0 ; i < std::size_t(SIZE / 2) ; i++) a[i] = data[i] ;
		for(std::size_t i = std::size_t(SIZE / 2) ; i < SIZE ; i++) b[i-std::size_t(SIZE/2)] = data[i] ;
			
		a = mergeSort(a, order) ;
		b = mergeSort(b, order) ;
		
		return merge(a, b, order) ;
	}

}

#endif
