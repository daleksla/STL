#ifndef TRAITS_HPP
#define TRAITS_HPP
#pragma once

#include "macros.hpp"

/** @brief Type traits allowing for compile-time type checkings, which can be used in conditional building, assertions, etc.
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace types {

	template<typename T, typename U>
	struct trueType {		
		private:
			static CONSTEXPRCXX11 bool value = true ;
			
		public:
			inline CONSTEXPRCXX11 bool operator()
			{
				return value ;
			}
			
	} ;
	
	template<typename T, typename U>
	struct falseType {		
		private:
			static CONSTEXPRCXX11 bool value = false ;
			
		public:
			inline CONSTEXPRCXX11 bool operator()
			{
				return value ;
			}
			
	} ;
	
	template<typename T, typename U>
	struct isSame : public falseType ;
	
	template<typename T>
	struct isSame : public trueType ;

}
}
	
#endif
