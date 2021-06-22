#ifndef DATA_OPS_HPP
#define DATA_OPS_HPP
#pragma once

#include "../types/macros.hpp"
#include "../types/iterators.hpp"

/** @brief Data manipulation functionalities
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
	template<typename T, typename = std::enable_if< T::category::value >= salih::types::UniDirectionalIteratorTag::value>, typename U>
	CONSTEXPRCXX14 unsigned long tally(const T&, const T&, const U&) ;
	
	/** This function tallies the prescence of a value in a given container 
	 * @param const reference to list (to be searched through)
         * @param value to compare against
         * @return value relating to prescence of said value **/
	template<typename T, typename = std::enable_if< T::iteratorType::value >= salih::types::UniDirectionalIteratorTag::value>, typename U>
	CONSTEXPRCXX14 inline unsigned long tally(const T&, const U&) ;

	/** This function applies a provided functionality to each element between two iterators
         * @param Iterator to start of sequence
         * @param Iterator to end of sequence
         * @param Function pointer to be executed on each element **/
	template<typename T, typename = std::enable_if< T::category::value >= salih::types::UniDirectionalIteratorTag::value>, typename F>
	CONSTEXPRCXX14 void forEach(const T&, const T&, const F) ;
	
	/** This function applies a provided functionality to each element in a given container
	 * @param const reference to list (to be searched through)
         * @param value to compare against
         * @param Function pointer to be executed on each element **/
	template<typename T, typename = std::enable_if< T::iteratorType::value >= salih::types::UniDirectionalIteratorTag::value>, typename F>
	CONSTEXPRCXX14 inline void forEach(T&, const F) ;

}
}

#include "data-ops.tpp"

#endif
