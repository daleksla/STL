#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "_flags.hpp"
#include "_swap.hpp"

/** @brief Selection sort algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Sorts {

	template<typename T>
	T selectionSort(T list, bool(*const order)(int, int) = ASCEND)
	/** This is the double-ended selection sort algorithm. It works by sorting a list of values by finding the smallest value from unsorted section and putting it at the end of the first sorted section & has an additional sorted subsection containing the largest values
	 * @param copy of list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either ASCEND (1,...,n) or DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	{
		if(list.getSize() <= 1) return list ;
		std::size_t limit = list.getSize() - 1 ; //initialise 2nd section boundary value (for larger values) 
		for(std::size_t i = 0 ; i < limit ; i++) // only iterate until the 2nd section boundary (since values past this are sorted)  
		{               
			int min = i ; //set minimum index as current index 
			int max = i ; //set maximum index as current index 
			for(std::size_t j = i ; j < limit + 1 ; j++)
			{           
				if((*order)(list[j], list[min])) //set the index for minimum element in list
				{                  
					min = j ;
				}
				if((*order)(list[max], list[j])) //set the index for minimum element in list
				{
					max = j ;
				}
			}
			swap(list[i], list[min]) ;
			if((*order)(list[max],list[min])) //if the just-found smallest value is larger then the just-found 'largest' value
			{
				swap(list[limit], list[min]) ; //then put the larger value (at index min) in larger sorted section
			}
			else {
				swap(list[limit], list[max]) ; //then put the larger value (at index max) in larger sorted section
			}         
			limit -= 1 ; 
			//since we get the largest value and place it at the end of the sorted list, we shrink the limit
			//this way, on the next-iteration we get the second-largest, element and place it in the slot before, etc.
		}
		return list ;
	}

}

#endif
