#ifndef DATA_OPS_HPP
#define DATA_OPS_HPP
#pragma once

#include "../types/macros.hpp"

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

}
}

#include "data-ops.tpp"

#endif
