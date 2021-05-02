#ifndef _SWAP_HPP
#define _SWAP_HPP
#pragma once

/** @brief Swapping functionality for sorting algorithms
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Algorithms::Sorts {

	/** This function swaps the position of two elements (in a list structure)
         * @param x, y (references to elements (of a list) we wish to swap) **/
	template<typename U>
	inline void swap(U&, U&) ;

	template<typename U>
	inline void swap(U& x, U& y)
	{
		U buffer = y ; // store the value of the 'x' to be (aka the current 'y')
		y = x ; // we can just directly assign x to y
		x = buffer ;
	}
	
}

#endif
