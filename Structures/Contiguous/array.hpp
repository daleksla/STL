#ifndef ARRAY_HPP
#define ARRAY_HPP
#pragma once

#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

/** @brief Array-class implementation file, representing a C-style array wrapper
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Structures::Contiguous {

	template<class T, std::size_t SIZE>
	class Array {
		/** This class is the Array-class implementation, serving as a c-array wrapper **/
		private:			
			T pointer[SIZE] ;
			
		public:
			/** Empty constructor, intialises empty array 
			@return <initialised-object> **/
			Array() ;
		
			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for array)
			@return <initialised-object> **/	
			Array(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, assigns values to array
			@param initialisation list (of values for array)
			@return reference to current object **/
			Array& operator=(const std::initializer_list<T>&) ;
			
			/** Copy constructor, creates copy of a given array
			@param a (l-value) array object
			@return <initialised-object> **/	
			Array(const Array&) ;
			
			/** Copy constructor, creates copy of a given array
			@param a (l-value) array object (of different size)
			@return <initialised-object> **/	
			template<std::size_t DIFF>
			Array(const Array<T, DIFF>&) ;
			
			/** Copy assignment operator, creates copy of a given array
			@param a (l-value) array object
			@return reference to current object **/
			Array& operator=(const Array&) ;
			
			/** Copy assignment operator, creates copy of a given array
			@param a (l-value) array object (of different size)
			@return reference to current object **/
			template<std::size_t DIFF>
			Array& operator=(const Array<T, DIFF>&) ;		
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/
			constexpr std::size_t getSize() const ;
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the structure **/ 
			T& operator[](const std::size_t) ; 
	
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/ 		
			const T& operator[](const std::size_t) const ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with, bool (assumingly true flag as to check whether an index is valid)
			@return reference to a given element in the structure **/ 				
			T& at(const std::size_t, const bool check = true) ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with, bool (assumingly true flag as to check whether an index is valid)
			@return constant reference to a given element in the structure **/ 	
			const T& at(const std::size_t, const bool check = true) const ; 
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of same type and size)
			@return a boolean representing whether equality is met **/ 	
			bool operator==(const Array&) const ;			
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of different type, same size)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			bool operator==(const Array<OTHER, SIZE>&) const ;
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of same type, different size)
			@return a boolean (will always return false, since the arrays can't have the same values) **/ 	
			template<std::size_t DIFF>
			bool operator==(const Array<T, DIFF>&) const ;
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param array structure to compare with (of different type and size)
			@return a boolean (will always return false, since the arrays can't have the same values) **/ 	
			template<typename OTHER, std::size_t DIFF>
			bool operator==(const Array<OTHER, DIFF>&) const ;
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's values
			@param contiguous structure to compare with (of same type and size)
			@return a boolean representing whether inequality is met **/ 	
			bool operator!=(const Array&) const ;			
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's values
			@param array structure to compare with (of different type, same size)
			@return a boolean representing whether inequality is met **/ 	
			template<typename OTHER>
			bool operator!=(const Array<OTHER, SIZE>&) const ;
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's
			@param array structure to compare with (of same type, different size)
			@return a boolean representing whether inequality is met (will always return true) **/ 	
			template<std::size_t DIFF>
			bool operator!=(const Array<T, DIFF>&) const ;
			
			/** Inequality operator, determines if a calling objects values doesn't match another structure's
			@param array structure to compare with (of different type and size)
			@return a boolean representing whether inequality is met (will always return true) **/ 	
			template<typename OTHER, std::size_t DIFF>
			bool operator!=(const Array<OTHER, DIFF>&) const ;
			
			/** Destructor **/					
			~Array() ;
			
			template<class, std::size_t>
			friend class Array ;
	} ;
	
}

#include "array.tpp"

#endif
