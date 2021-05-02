#ifndef _LINEARSEARCH_HPP
#define _LINEARSEARCH_HPP
#pragma once

#include "../../Types/traits.hpp"
#include "../../Structures/Contiguous/array.hpp"
#include "../../Structures/Contiguous/vector.hpp"
#include "../../Structures/LinkedLists/linkedlist.hpp"
#include "../../Types/string.hpp"

/** @brief Linear search algorithm file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Searches {

	template<typename T, typename = typename std::enable_if< Salih::Types::Traits::isList<T>::value, T >::type, typename U>
	bool linearSearch(T& list, U target)
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param reference to list (to be sorted)
	 * @return boolean (indicates if supplied value was found or not) **/
	{
		for(int i = 0 ; i < list.getSize() ; i++) if(list[i] == target) return true ;
		return false ;
	}

}

#endif
