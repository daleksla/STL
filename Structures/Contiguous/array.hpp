#ifndef ARRAY_HPP
#define ARRAY_HPP
#pragma once

#include "_contiguous.hpp"
#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

/** @brief Array-class implementation file, representing a fixed-contiguous data structure
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Structures::Contiguous {

	template<class T, std::size_t SIZE>
	class Array : public Contiguous<T> {
		/** This class is the Array-class implementation, serving as a c-array wrapper **/
		private:			
			Array(T*, const std::size_t) ;
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
			
			/** Copy assignment operator, creates copy of a given array
			@param a (l-value) array object
			@return reference to current object **/
			Array& operator=(const Array&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary array object
			@param an r-value array object
			@return <initialised-object> **/
			Array(Array&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary array object
			@param an (r-value) array object
			@return reference to current object **/
			Array& operator=(Array&&) ;			
			
			//template<std::size_t NEW_SIZE>
			//Array<T,NEW_SIZE> operator()(const int x, const int y) const ;
			
			/** Destructor, frees memory and deletes array **/					
			~Array() ;
			
			template<typename OTHER, std::size_t _SIZE>
			friend class Array ;
	} ;
	
}

#include "array.tpp"

#endif
