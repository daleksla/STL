#ifndef _SELECTIONSORT_HPP
#define _SELECTIONSORT_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "_flags.hpp"
#include "_swap.hpp"
#include "../../Structures/Contiguous/array.hpp"
#include "../../Structures/Contiguous/vector.hpp"
#include "../../Structures/LinkedLists/linkedlist.hpp"
#include "../../Types/string.hpp"

namespace Salih::Algorithms::Sorts {

	template<typename T, typename = typename std::enable_if< Salih::Types::Traits::isList<T>::value, T >::type>
	T& selectionSort(T& list, bool(*order)(int, int) = ASCEND)
	/* The selection sort algorithm sorts a list of values by finding the smallest value from unsorted section and putting it at the end of the first sorted section
	 	* This algorithm differs in that it also has an additional sorted subsection containing the largest values
	 * Input: list (reference to list to be sorted)
	 * Output: list (reference to the sorted list) */
	{
		int limit = list.getSize() - 1 ; //initialise 2nd section boundary value (for larger values) 
		for(int i = 0 ; i < limit ; i++) // only iterate until the 2nd section boundary (since values past this are sorted)  
		{               
			int min = i ; //set minimum index as current index 
			int max = i ; //set maximum index as current index 
			for(int j = i ; j < limit + 1 ; j++)
			{           
				if(list[j] < list[min]) //set the index for minimum element in list
				{                  
					min = j ;
				}
				if(list[j] > list[max]) //set the index for maximum element in list
				{
					max = j ;
				}
			}
			swap(list[i], list[min]) ;
			if(list[min] >= list[max]) //if the just-found smallest value is larger then the just-found 'largest' value
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
