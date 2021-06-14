#ifndef BOOL_TYPE_HPP
#define BOOL_TYPE_HPP
#pragma once

#include "macros.hpp"

/** @brief Base traits, inherited by other traits. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	struct falseType {		
		public:
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
		public:
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

#endif
