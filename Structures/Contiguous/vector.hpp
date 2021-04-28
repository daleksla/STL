#ifndef VECTOR_HPP
#define VECTOR_HPP
#pragma once

#include "_contiguous.hpp"
#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

/** @brief Vector-class implementation file, representing a dynamic-contiguous data structure
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Structures::Contiguous {

	template<class T>
	class Vector : public Contiguous<T> {
		/** This class is the vector-class implementation, serving as a dynamically resizing c-array wrapper **/
		private:			
			Vector(T*, const std::size_t) ;
		public:
			/** Empty constructor, intialises empty vector 
			@return <initialised-object> **/
			Vector() ;
		
			/** Size-creating constructor, intialises a vector of a specified size
			@param size_t (size of vector to pre-initialise)
			@return <initialised-object> **/	
			Vector(const std::size_t) ;

			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for vector)
			@return <initialised-object> **/			
			Vector(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, assigns values to vector
			@param initialisation list (of values for vector)
			@return reference to current object **/
			Vector& operator=(const std::initializer_list<T>&) ;
			
			/** Copy constructor, creates copy of a given vector
			@param a (l-value) vector object
			@return <initialised-object> **/
			Vector(const Vector&) ;
			
			/** Copy assignment operator, creates copy of a given vector
			@param a (l-value) vector object
			@return reference to current object **/
			Vector& operator=(const Vector&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary vector object
			@param an r-value vector object
			@return <initialised-object> **/
			Vector(Vector&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary vector object
			@param an (r-value) vector object
			@return reference to current object **/
			Vector& operator=(Vector&&) ;			
			
			//template<std::size_t NEW_SIZE>
			//Array<T,NEW_SIZE> operator()(const int x, const int y) const ;
			
			/** append method, adds a value to the end of the current vector
			@param value (to add) **/
			void append(T) ;
			
			/** clear method, deletes all elements of the vector **/
			void clear() ;
			
			/** Destructor, frees memory and deletes vector **/					
			~Vector() ;
			
			template<typename OTHER>
			friend class Vector ;
	} ;
	
}

#include "vector.tpp"

#endif
