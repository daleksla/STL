#ifndef FLAGS_HPP
#define FLAGS_HPP
#pragma once

/** @brief Flags for sorting algorithms. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih {
namespace algorithms {

	/** This flag indicates 'smaller' value based on desire (for an ascending or descending list)
	  * @param a, b (values to compare)
	  * @return boolean if a is smaller, else false **/
	template<typename U>
	inline bool ASCEND(U, U) ;

	/** This flag indicates 'smaller' value based on desire (for an ascending or descending list)
	  * @param a, b (values to compare)
	  * @return boolean if a is larger, else false **/
	template<typename U>
	inline bool DESCEND(U, U) ;

	template<typename U>
	inline bool ASCEND(U a, U b)
	{
		return a < b ;
	}

	template<typename U>
	inline bool DESCEND(U a, U b)
	{
		return a > b ;
	}

} 
}

#endif
