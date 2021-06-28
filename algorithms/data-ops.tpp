#ifndef DATA_OPS_TPP
#define DATA_OPS_TPP
#pragma once

#include "../types/macros.hpp"
#include "../types/iterators.hpp"

/** @brief Implementations of data manipulation functionalities. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename U>
CONSTEXPRCXX14 inline void salih::algorithms::swap(U& x, U& y)
{
	U buffer = y ; // store the value of the 'x' to be (aka the current 'y')
	y = x ; // we can just directly assign x to y
	x = buffer ;
}

template<typename U>
CONSTEXPRCXX11 inline U&& salih::algorithms::move(U& x)
{
	return static_cast<U&&>(x) ; // store the value of x in r-value object
}

template<typename T, typename F, typename U>
CONSTEXPRCXX14 unsigned long salih::algorithms::tally(const T& begin, const T& end, const U& target)
{
	unsigned long tally = 0 ;
	for(auto it = begin ; it != end ; ++it) if(*it == target) ++tally ;
	return tally ;
}

template<typename T, typename F, typename U>
CONSTEXPRCXX14 inline unsigned long salih::algorithms::tally(const T& list, const U& target)
{
	if(list.getSize() == 0) return 0 ;
	return salih::algorithms::tally(list.cbegin(), list.cend(), target) ;
}

template<typename T, typename U, typename F>
CONSTEXPRCXX14 void salih::algorithms::forEach(const T& begin, const T& end, const F function)
{
	for(auto it = begin ; it != end ; ++it)
	{
		(*function)(*it) ;
	}
}

template<typename T, typename U, typename F>
CONSTEXPRCXX14 inline void salih::algorithms::forEach(T& list, const F function)
{
	salih::algorithms::forEach(list.begin(), list.end(), function) ;
}

#endif
