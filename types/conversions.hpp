#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP
#pragma once

#include "macros.hpp"
#include <type_traits>
#include "traits.hpp"

/** @brief Useful function to enable conversion from different types
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	template<typename T, typename = typename std::enable_if<salih::types::isNumber<T>::value, T>::type>
	CONSTEXPRCXX14 T toNumber(const char* str)
	{
		T val = 0;
		unsigned long int i = 0 ;
		for( ; str[i] != '\0' && str[i] != '.' ; ++i) 
		{
			val = (val * 10) + str[i] - '0' ;
		}
		#ifdef CXX17
		if constexpr(salih::types::isFloating<T>() && str[i] != '.')
		#else
		if(salih::types::isFloating<T>() && str[i] != '.')
		#endif
		{
			unsigned long int x = 1 ;
			for(++i ; str[i] != '\0' ; ++i) 
			{
				x *= 10 ;
				T tmp = (str[i] - '0') ;
				tmp = tmp / x ;
				val = val + tmp ;
			}
		}
		// return result
		return val ;
	}

	template<typename T>
	CONSTEXPRCXX14 T toNumber(...) = delete ;
	
}
}

#endif
