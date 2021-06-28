#ifndef TRAITS_HPP
#define TRAITS_HPP
#pragma once

/** @brief 'isSame' type trait. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	template<typename T, typename U>
	struct isSame : public falseType {} ;
	
	template<typename T>
	struct isSame : public trueType {} ;

}
}
	
#endif
