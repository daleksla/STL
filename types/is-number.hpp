#ifndef IS_NUMBER_HPP
#define IS_NUMBER_HPP
#pragma once

#include "macros.hpp"

/** @brief 'isNumber' type trait. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {


	template <class T> struct isNumber : public falseType {} ;

	template<> struct isNumber<unsigned char> : public trueType {} ;
	
	template<> struct isNumber<const unsigned char> : public trueType {} ;
	
	template<> struct isNumber<signed char> : public trueType {} ;
	
	template<> struct isNumber<const signed char> : public trueType {} ;
	
	template<> struct isNumber<unsigned short> : public trueType {} ;
	
	template<> struct isNumber<const unsigned short> : public trueType {} ;
	
	template<> struct isNumber<signed short> : public trueType {} ;
	
	template<> struct isNumber<const signed short> : public trueType {} ;
	
	template<> struct isNumber<unsigned int> : public trueType {} ;
	
	template<> struct isNumber<const unsigned int> : public trueType {} ;
	
	template<> struct isNumber<signed int> : public trueType {} ;
	
	template<> struct isNumber<const signed int> : public trueType {} ;
	
	template<> struct isNumber<unsigned long> : public trueType {} ;
	
	template<> struct isNumber<const unsigned long> : public trueType {} ;
	
	template<> struct isNumber<signed long> : public trueType {} ;
	
	template<> struct isNumber<const signed long> : public trueType {} ;
	
	template<> struct isNumber<bool> : public trueType {} ;
	
	template<> struct isNumber<const bool> : public trueType {} ;

}
}
	
#endif
