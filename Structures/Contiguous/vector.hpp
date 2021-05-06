#ifndef VECTOR_HPP
#define VECTOR_HPP
#pragma once

#include <algorithm>
#include <iterator>
#include <utility>
#include <initializer_list>

/** @brief Vector-class implementation file, a wrapper for a C-style dynamic-contiguous data structure
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Structures::Contiguous {

	template<class T>
	class Vector {
		/** This class is the vector-class implementation, serving as a dynamically resizing c-array wrapper **/
		private:			
			T* pointer ;
			
			std::size_t size ;
		
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
			
			/** Destructor, frees memory and deletes vector **/					
			~Vector() ;			
			
			/** append method, adds a value to the end of the current vector
			@param value (to add) **/
			void append(T) ;
			
			/** clear method, deletes all elements of the vector **/
			void clear() ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/
			std::size_t getSize() const ;

			/** Slicing operator, extract part of structure directly
			@param integer to start slicing from	
			@param integer to slice until			
			@return sliced vector (ie values from index a->b) **/ 
			Vector operator()(const std::size_t, const std::size_t) const ;
			
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
			@param vector structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			bool operator==(const Vector<OTHER>&) const ;
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param vector structure to compare with
			@return a boolean representing whether equality is met **/ 	
			bool operator==(const Vector&) const ;
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param vector structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is not met **/ 	
			template<typename OTHER>
			bool operator!=(const Vector<OTHER>&) const ;
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param vector structure to compare with
			@return a boolean representing whether equality is not met **/ 
			bool operator!=(const Vector&) const ;
			
			template<typename OTHER>
			friend class Vector ;
	} ;
	
}

#include "vector.tpp"

#endif
