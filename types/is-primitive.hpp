#ifndef IS_PRIMITIVE_HPP
#define IS_PRIMITIVE_HPP
#pragma once

#include "macros.hpp"
#include "bool-type.hpp"

/** @brief 'isPrimitive' type trait. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	template<typename T> struct isPrimitive : public falseType {} ;

	template<> struct isPrimitive<char> : public trueType {} ;
	
	template<> struct isPrimitive<const char> : public trueType {} ;

	template<> struct isPrimitive<unsigned char> : public trueType {} ;
	
	template<> struct isPrimitive<const unsigned char> : public trueType {} ;
	
	template<> struct isPrimitive<signed char> : public trueType {} ;
	
	template<> struct isPrimitive<const signed char> : public trueType {} ;
	
	template<> struct isPrimitive<unsigned short> : public trueType {} ;
	
	template<> struct isPrimitive<const unsigned short> : public trueType {} ;
	
	template<> struct isPrimitive<signed short> : public trueType {} ;
	
	template<> struct isPrimitive<const signed short> : public trueType {} ;
	
	template<> struct isPrimitive<unsigned int> : public trueType {} ;
	
	template<> struct isPrimitive<const unsigned int> : public trueType {} ;
	
	template<> struct isPrimitive<signed int> : public trueType {} ;
	
	template<> struct isPrimitive<const signed int> : public trueType {} ;
	
	template<> struct isPrimitive<unsigned long> : public trueType {} ;
	
	template<> struct isPrimitive<unsigned long long> : public trueType {} ;
	
	template<> struct isPrimitive<const unsigned long> : public trueType {} ;

	template<> struct isPrimitive<const unsigned long long> : public trueType {} ;
	
	template<> struct isPrimitive<signed long> : public trueType {} ;
	
	template<> struct isPrimitive<signed long long> : public trueType {} ;
	
	template<> struct isPrimitive<const signed long> : public trueType {} ;
	
	template<> struct isPrimitive<const signed long long> : public trueType {} ;
	
	template<> struct isPrimitive<float> : public trueType {} ;
	
	template<> struct isPrimitive<const float> : public trueType {} ;
	
	template<> struct isPrimitive<double> : public trueType {} ;
	
	template<> struct isPrimitive<const double> : public trueType {} ;
	
	template<> struct isPrimitive<bool> : public trueType {} ;
	
	template<> struct isPrimitive<const bool> : public trueType {} ;

}
}
	
#endif
