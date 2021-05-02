#ifndef _FLAGS_HPP
#define _FLAGS_HPP
#pragma once

namespace Salih::Algorithms::Sorts {

	template<typename U>
	inline bool ASCEND(U, U) ;

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

#endif
