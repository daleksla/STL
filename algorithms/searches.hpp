#ifndef SEARCHES_HPP
#define SEARCHES_HPP
#pragma once

#include "../types/macros.hpp"
#include "../types/iterators.hpp"
#include <type_traits>
		
/** @brief Searching algorihtms file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih::algorithms {

	/** This is a useful inline function to obtain the 'middle index' value, based on a given size
	 * @param const integer (size of list to determine middle of)
	 * @return integer ('middle' index) **/
	CONSTEXPRCXX14 inline std::size_t getMiddle(const std::size_t totalSize) ;
	
	/** This is a binary search algorithm, which splits a list into sub-segments to look upon and repeats until the element is found
	 * @param const reference to list (to be searched)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/	
	template<typename T, typename U, typename = typename std::enable_if<std::is_same<U, typename T::innerType>::value>::type>
	CONSTEXPRCXX14 bool binarySearch(const T&, const U&) ;
	
	CONSTEXPRCXX14 bool binarySearch(...) = delete ;
	
	/** This is the interpolation search algorithm, I don't exactly know how to explain this one but it works
	 * @param const reference to list (to be searched)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	template<typename T, typename U, typename = typename std::enable_if<std::is_same<U, typename T::innerType>::value>::type>
	CONSTEXPRCXX14 bool interpolationSearch(const T&, const U&) ;
	
	CONSTEXPRCXX14 bool interpolationSearch(...) = delete ;
	
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param const reference to iterator to beginning of search range
	 * @param const reference to iterator to end of search range
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	template<typename T, typename = typename std::enable_if< T::category::value >= salih::types::UniDirectionalIteratorTag::value>, typename U, typename = typename std::enable_if<std::is_same<U, typename T::innerType>::value>::type>
	CONSTEXPRCXX14 bool linearSearch(const T&, const T&, const U&) ;
	
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param const reference to list (to be searched through)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	template<typename T, typename = typename std::enable_if< T::iteratorType::value >= salih::types::UniDirectionalIteratorTag::value>, typename U, typename = typename std::enable_if<std::is_same<U, typename T::innerType>::value>::type>
	CONSTEXPRCXX14 inline bool linearSearch(const T&, const U&) ;

	CONSTEXPRCXX14 inline bool linearSearch(...) = delete ;

}

#include "searches.tpp"

#endif
