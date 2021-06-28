#ifndef IS_FLOATING_HPP
#define IS_FLOATING_HPP
#pragma once

#include "bool-type.hpp"
#include "macros.hpp"

/** @brief 'isFloating' type trait. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	template <class T> struct isFloating : public falseType {} ;
	
	template<> struct isFloating<float> : public trueType {} ;
	
	template<> struct isFloating<const float> : public trueType {} ;
	
	template<> struct isFloating<double> : public trueType {} ;
	
	template<> struct isFloating<const double> : public trueType {} ;

}
}
	
#endif
