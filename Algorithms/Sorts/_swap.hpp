#ifndef _SWAP_HPP
#define _SWAP_HPP
#pragma once

namespace Salih::Algorithms::Sorts {

	template<typename U>
	void swap(U&, U&) ;

	template<typename U>
	void swap(U& x, U& y)
	{
		/* This function swaps the position of two elements (in a list structure)
		 * Input: x, y (references to elements (of a list) we wish to swap)
		 * Output: None (elements are modified by reference) */
		U buffer = y ; // store the value of the 'x' to be (aka the current 'y')
		y = x ; // we can just directly assign x to y
		x = buffer ;
	}
	
}

#endif
