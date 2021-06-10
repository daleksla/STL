#ifndef DATA_OPS_HPP
#define DATA_OPS_HPP
#pragma once

#include "../types/macros.hpp"
#include "../types/iterators.hpp"

/** @brief Functionality relating to data manipulation of some sort
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih {
namespace algorithms {

	/** This function swaps the position of two elements (in a list structure)
         * @param x (reference to element we wish to swap with y
         * @param y (references to elements we wish to swap with x) **/
	template<typename U>
	CONSTEXPRCXX14 inline void swap(U&, U&) ;

	/** This function tallies the prescence of a value in a given container 
         * @param Iterator to start of sequence
         * @param Iterator to end of sequence
         * @param value to compare against
         * @return value relating to prescence of said value **/
	template<typename T, typename = std::enable_if< T::category::value >= salih::types::UniDirectionalIterator::value>, typename U>
	CONSTEXPRCXX14 std::size_t tally(const T&, const T&, const U&) ;
	
	/** This function tallies the prescence of a value in a given container 
	 * @param const reference to list (to be searched through)
         * @param value to compare against
         * @return value relating to prescence of said value **/
	template<typename T, typename U>
	CONSTEXPRCXX14 inline std::size_t tally(const T&, const U&) ;

}
}

#include "data-ops.tpp"

#endif
