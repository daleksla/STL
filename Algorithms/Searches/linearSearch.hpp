#ifndef LINEARSEARCH_HPP
#define LINEARSEARCH_HPP
#pragma once

#include "../../Types/traits.hpp"

/** @brief Linear search algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Searches {

	template<typename UniDirectionalIterator, typename U>
	_GLIBCXX14_CONSTEXPR bool linearSearch(const UniDirectionalIterator& begin, const UniDirectionalIterator& end, const U& target)
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param const reference to iterator to beginning of search range
	 * @param const reference to iterator to end of search range
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	{
		for(auto it = begin ; it != end ; ++it) if(*it == target) return true ;
		return false ;
	}

	template<typename T, typename U>
	_GLIBCXX14_CONSTEXPR bool linearSearch(const T& list, const U& target)
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param const reference to list (to be searched through)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	{
		if(list.getSize() == 0) return false ;
		for(auto it = list.cbegin() ; it != list.cend() ; ++it) if(*it == target) return true ;
		return false ;
	}

}

#endif
