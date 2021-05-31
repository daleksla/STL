#ifndef SEARCHES_TPP
#define SEARCHES_TPP
#pragma once

inline std::size_t salih::algorithms::getMiddle(const std::size_t size)
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
bool salih::algorithms::binarySearch(const T& list, const U& target)
{
	const std::size_t size = list.getSize() ; 
	if(size == 0) return false ;
	const std::size_t middleN = salih::algorithms::getMiddle(size) ;
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
bool salih::algorithms::interpolationSearch(const T& list, const U& target)
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

template<typename UniDirectionalIterator, typename U>
_GLIBCXX14_CONSTEXPR bool salih::algorithms::linearSearch(const UniDirectionalIterator& begin, const UniDirectionalIterator& end, const U& target)
{
	for(auto it = begin ; it != end ; ++it) if(*it == target) return true ;
	return false ;
}

template<typename T, typename U>
_GLIBCXX14_CONSTEXPR bool salih::algorithms::linearSearch(const T& list, const U& target)
{
	if(list.getSize() == 0) return false ;
	for(auto it = list.cbegin() ; it != list.cend() ; ++it) if(*it == target) return true ;
	return false ;
}

#endif
