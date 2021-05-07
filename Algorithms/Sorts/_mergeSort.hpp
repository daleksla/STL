#ifndef _MERGESORT_HPP
#define _MERGESORT_HPP
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

}

#endif
