#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "_flags.hpp"
#include "_swap.hpp"

/** @brief Bubble sort algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Sorts {

	template<typename T>
	T bubbleSort(T list, bool(*const order)(int, int) = ASCEND)
	/** This is the bubble-sort sort algorithm. It works by repeatedly swapping the adjacent elements if they are in wrong order
	 * @param copy of list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{
		std::size_t listLength = list.getSize() ;
		if(listLength <= 1) return list ;
		
		for(std::size_t main = 0 ; main < (listLength - 1) ; main++)
		{
			for(std::size_t inner = 0 ; inner < (listLength - main - 1) ; inner++)
			{
				if((*order)(list[inner+1], list[inner]))
				{
					swap(list[inner], list[inner+1]) ;
				}
			}
		}
		return list ;
	}

}

#endif
