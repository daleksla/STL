#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP
#pragma once

#include "../../Types/traits.hpp"

/** @brief Binary search algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Searches {

	inline std::size_t getMiddle(const std::size_t size)
	/** This is a useful inline function to obtain the 'middle index' value, based on a given size
	 * @param const integer (size of list to determine middle of)
	 * @return integer ('middle' index) **/
	{
		std::size_t middleN ;
		if(size == 1) middleN = 0 ;
		else {
			if(size % 2 == 0) middleN = std::size_t(size / 2) ; 
			// if the list size is even, we just get the size / 2, rounded down
			else middleN = std::size_t(size / 2) + 1 ;  // if list is odd, we get the size / 2, rounded up (by rounding down to a full int then adding 1 (e.g 3 / 2 == 1.5, 1.5->1->2 (since 2 is inbetween both values, giving us a true middle value))
		}
		return middleN ;
	}
	
	template<typename T, typename U>
	bool binarySearch(const T& list, const U& target)
	/** This is a binary search algorithm, which splits a list into sub-segments to look upon and repeats until the element is found
	 * @param const reference to list (to be sorted)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	{
		const std::size_t size = list.getSize() ; 
		if(size == 0) return false ;
		const std::size_t middleN = getMiddle(size) ;
		const auto middleVal = list[middleN] ; // get middle element of list

		if(target == middleVal) return true ;
		else if(size != 1) // if there's more elements in the list we can actually look at
		{
			if(target < middleVal) return binarySearch(list(0,middleN), target) ;
			else if(target > middleVal) return binarySearch(list(middleN,size), target) ;
		}
		else return false ; // if there aren't more elements we can look at
	}
	
}

#endif
