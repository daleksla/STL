#ifndef TRAITS_HPP
#define TRAITS_HPP
#pragma once

#include "macros.hpp"

/** @brief Collection of general type traits (pseudo-functionalities conveying information of given data-types)
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	struct falseType {		
		private:
			static CONSTEXPRCXX11 bool value = false ;
			
		public:
			inline CONSTEXPRCXX11 operator bool()
			{
				return value ;
			}
			
			inline CONSTEXPRCXX11 bool operator!()
			{
				return !value ;
			}
			
	} ;
	
	struct trueType {		
		private:
			static CONSTEXPRCXX11 bool value = true ;
			
		public:
			inline CONSTEXPRCXX11 operator bool()
			{
				return value ;
			}
			
			inline CONSTEXPRCXX11 bool operator!()
			{
				return !value ;
			}
			
	} ;

}
}

#include "is-same.hpp"
#include "is-number.hpp"
	
#endif
