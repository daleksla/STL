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

	template<typename T, typename = typename std::enable_if< Salih::Types::Traits::isList<T>::value, T >::type, typename U>
	bool linearSearch(const T& list, const U& target)
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param const reference to list (to be sorted)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	{
		if(list.getSize() == 0) return false ;
		for(int i = 0 ; i < list.getSize() ; i++) if(list[i] == target) return true ;
		return false ;
	}

}

#endif
