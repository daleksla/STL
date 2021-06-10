#ifndef DATA_OPS_TPP
#define DATA_OPS_TPP
#pragma once

#include "../types/macros.hpp"

template<typename U>
CONSTEXPRCXX14 inline void salih::algorithms::swap(U& x, U& y)
{
	U buffer = y ; // store the value of the 'x' to be (aka the current 'y')
	y = x ; // we can just directly assign x to y
	x = buffer ;
}

#endif
