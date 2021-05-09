#ifndef INTERPOLATIONSEARCH_HPP
#define INTERPOLATIONSEARCH_HPP
#pragma once

#include "../../Types/traits.hpp"

/** @brief Interpolation search algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Searches {

	template<typename T, typename = typename std::enable_if< (Salih::Types::Traits::isList<T>::value && Salih::Types::Traits::isDynamic<T>::value && Salih::Types::Traits::getDimensions<T>::value == 1), T >::type, typename U>
	bool interpolationSearch(const T& list, const U& target)
	/** This is the interpolation search algorithm, I don't exactly know how to explain this one but it works
	 * @param const reference to list (to be sorted)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	{
		if(!list.getSize()) return false ;
	
		std::size_t start = 0 ; // lists always start at 0
		std::size_t end = list.getSize() - 1 ; // we want end index value
	
		if(start == end || target < list[start] || target > list[end]) return false ;
	
		std::size_t position = std::size_t(start + ( ( (target-list[start]) * (end-start)) / (list[end] - list[start]) )) ;
	
		if(list[position] == target) return true ;
		else if(list[position] < target) return interpolationSearch(list(position+1,list.getSize()), target) ;
		else if(list[position] > target) return interpolationSearch(list(0,position), target) ;
	}

}

#endif
