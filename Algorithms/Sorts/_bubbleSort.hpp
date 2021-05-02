#ifndef _BUBBLESORT_HPP
#define _BUBBLESORT_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "_flags.hpp"
#include "_swap.hpp"
#include "../../Structures/Contiguous/array.hpp"
#include "../../Structures/Contiguous/vector.hpp"
#include "../../Structures/LinkedLists/linkedlist.hpp"
#include "../../Types/string.hpp"

/** @brief Bubble sort algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Sorts {

	template<typename T, typename = typename std::enable_if< Salih::Types::Traits::isList<T>::value, T >::type>
	T& bubbleSort(T& list, bool(*order)(int, int) = ASCEND)
	/** This is the bubble-sort sort algorithm. It works by repeatedly swapping the adjacent elements if they are in wrong order
	 * @param reference to list (to be sorted)
	 * @return reference to list (now sorted) **/
	{
		int listLength = list.getSize() ;
		
		for(int main = 0 ; main < (listLength - 1) ; main++)
		{
			for(int inner = 0 ; inner < (listLength - main - 1) ; inner++)
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
