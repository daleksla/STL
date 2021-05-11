#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "_flags.hpp"
#include <iostream>

/** @brief Quick sort algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Sorts {

	template<typename T, typename = typename std::enable_if< (Salih::Types::Traits::isList<T>::value && Salih::Types::Traits::isDynamic<T>::value && Salih::Types::Traits::getDimensions<T>::value == 1), T >::type>
	T quickSort(const T& list, bool(*const order)(int, int) = ASCEND)
	/** This is the quick sort algorithm. It creates three empty arrays to hold elements less than the pivot value, the same as the pivot value and elements greater than the pivot value, and then recursively sort the sub arrays and adds them together
	 * @param copy of list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{			
		if(list.getSize() <= 1) return list ;
		
		T left, right, equal ;		
		auto pivot = list[0] ;
		
		for(int i = 0 ; i < list.getSize() ; i++)
		{
			auto iterR = list[i] ;
			if((*order)(iterR, pivot)) left.append(iterR) ;
			else if(iterR == pivot) equal.append(iterR) ;
			else right.append(iterR) ;
		}
		
		return quickSort(left, order) + equal + quickSort(right, order) ;
	}
	
}

#endif
