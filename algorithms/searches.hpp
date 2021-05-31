#ifndef SEARCHES_HPP
#define SEARCHES_HPP
#pragma once

/** @brief Searching algorihtms file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih::algorithms {

	/** This is a useful inline function to obtain the 'middle index' value, based on a given size
	 * @param const integer (size of list to determine middle of)
	 * @return integer ('middle' index) **/
	inline std::size_t getMiddle(const std::size_t size) ;
	
	/** This is a binary search algorithm, which splits a list into sub-segments to look upon and repeats until the element is found
	 * @param const reference to list (to be searched)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/	
	template<typename T, typename U>
	bool binarySearch(const T&, const U&) ;
	
	/** This is the interpolation search algorithm, I don't exactly know how to explain this one but it works
	 * @param const reference to list (to be searched)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	template<typename T, typename U>
	bool interpolationSearch(const T&, const U&) ;
	
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param const reference to iterator to beginning of search range
	 * @param const reference to iterator to end of search range
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	template<typename UniDirectionalIterator, typename U>
	_GLIBCXX14_CONSTEXPR bool linearSearch(const UniDirectionalIterator&, const UniDirectionalIterator&, const U&) ;
	
	/** This is a linear search algorithm, which iterates through a list until the end if need be
	 * @param const reference to list (to be searched through)
	 * @param const reference of target (to be identified in list)
	 * @return boolean (indicates if supplied target was found or not) **/
	template<typename T, typename U>
	_GLIBCXX14_CONSTEXPR bool linearSearch(const T&, const U&) ;

}

#include "searches.tpp"

#endif
