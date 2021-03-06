#ifndef SEARCHES_TPP
#define SEARCHES_TPP
#pragma once

#include "../types/macros.hpp"
#include "../types/iterators.hpp"

/** @brief Implementations of searching algorihtms. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

CONSTEXPRCXX14 inline unsigned long salih::algorithms::getMiddle(const unsigned long size)
{
	unsigned long middleN = 0;
	if(size == 1) middleN = 0 ;
	else {
		if(size % 2 == 0) middleN = static_cast<unsigned long>(size / 2) ; 
		// if the list size is even, we just get the size / 2, rounded down
		else middleN = static_cast<unsigned long>(size / 2) + 1 ;  // if list is odd, we get the size / 2, rounded up (by rounding down to a full int then adding 1 (e.g 3 / 2 == 1.5, 1.5->1->2 (since 2 is inbetween both values, giving us a true middle value))
	}
	return middleN ;
}
	
template<typename T, typename U>
CONSTEXPRCXX14 bool salih::algorithms::binarySearch(const T& list, const U& target)
{
	const unsigned long size = list.getSize() ; 
	if(size == 0) return false ;
	const unsigned long middleN = salih::algorithms::getMiddle(size) ;
	const auto middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return true ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return salih::algorithms::binarySearch(list(0,middleN), target) ;
		else if(target > middleVal) return salih::algorithms::binarySearch(list(middleN,size), target) ;
	}
	return false ; // if there aren't more elements we can look at
}

template<typename T, typename U>
CONSTEXPRCXX14 bool salih::algorithms::interpolationSearch(const T& list, const U& target)
{
	if(!list.getSize()) return false ;

	unsigned long start = 0 ; // lists always start at 0
	unsigned long end = list.getSize() - 1 ; // we want end index value

	if(start == end || target < list[start] || target > list[end]) return false ;

	unsigned long position = static_cast<unsigned long>(start + ( ( (target-list[start]) * (end-start)) / (list[end] - list[start]) )) ;

	bool result = false ;
	if(list[position] == target) result = true ;
	else if(list[position] < target) result = interpolationSearch(list(position+1,list.getSize()), target) ;
	else if(list[position] > target) result = interpolationSearch(list(0,position), target) ;
	return result ;
}

template<typename T, typename U>
CONSTEXPRCXX14 bool salih::algorithms::linearSearch(const T& begin, const T& end, const U& target)
{
	for(auto it = begin ; it != end ; ++it) if(*it == target) return true ;
	return false ;
}

template<typename T, typename U>
CONSTEXPRCXX14 inline bool salih::algorithms::linearSearch(const T& list, const U& target)
{
	if(list.getSize() == 0) return false ;
	return salih::algorithms::linearSearch(list.cbegin(), list.cend(), target) ;
}

#endif
