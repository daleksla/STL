#ifndef MACROS_HPP
#define MACROS_HPP
#pragma once

/** @brief Useful, library & compiler independant macros
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

/* C++ version */

#if __cplusplus > 199711L 
	#define CXX98 
#endif

#if __cplusplus > 201103L 
	#define CXX11 
#endif

#if __cplusplus > 201402L 
	#define CXX14 
#endif

#if __cplusplus > 201703L 
	#define CXX17 
#endif

#if __cplusplus > 202002L 
	#define CXX20 
#endif

/* Constexpr labels (depending on C++ version) */

#ifdef CXX11 
	#define CONSTEXPRCXX11 constexpr
#else
	#define CONSTEXPRCXX11
#endif

#ifdef CXX14
	#define CONSTEXPRCXX14 constexpr
#else
	#define CONSTEXPRCXX14
#endif

#ifdef CXX17
	#define CONSTEXPRCXX17 constexpr
#else
	#define CONSTEXPRCXX17
#endif

#ifdef CXX20
	#define CONSTEXPRCXX20 constexpr
#else
	#define CONSTEXPRCXX20
#endif


#endif // MACROS_HPP
