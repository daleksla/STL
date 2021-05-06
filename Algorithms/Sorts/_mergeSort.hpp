#ifndef _MERGESORT_HPP
#define _MERGESORT_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "_flags.hpp"
#include "_merge.hpp"
#include <iostream>

/** @brief Merge sort algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Sorts {

	template<typename T, typename = typename std::enable_if< (Salih::Types::Traits::isList<T>::value && Salih::Types::Traits::isDynamic<T>::value && Salih::Types::Traits::getDimensions<T>::value == 1), T >::type>
	T mergeSort(const T& data, bool(*const order)(int, int) = ASCEND)
	/** This is the merge sort algorithm. It works splitting a list into minimal sublists and combining two, in order, into a bigger list. It keeps merging the lists together, then the merged lists together, until a fully sorted list is formed
	 * @param const reference to list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{			
		std::size_t listLength = data.getSize() ;
		
		if(listLength <= 1) return data ;
		
		T a, b ;
		
		for(std::size_t i = 0 ; i < std::size_t(listLength / 2) ; i++) a.append(data[i]) ;
		for(std::size_t i = std::size_t(listLength / 2) ; i < listLength ; i++) b.append(data[i]) ;
			
		mergeSort(a, order) ;
		mergeSort(b, order) ;
		
		return merge(a, b, order) ;
	}

}

#endif
