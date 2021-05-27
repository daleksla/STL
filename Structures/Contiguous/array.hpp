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
		/** This aggregate class is the Array-class implementation, serving as a c-style array wrapper **/
		public:			
			T pointer[SIZE] ;
			
		public:
			/** Empty constructor, intialises empty array 
			@return <initialised-object> **/
			//Array() = default ;

			/** Regular constructor, assigns values to an array
			@param an initialiser list of values
			@return <initialised-object> **/	
			//Array(const std::intializer_list<T>&) ;
			
			/** Regular assignment operator, assigns values to an array
			@param an initialiser list of values
			@return reference to current object **/
			//Array& operator=(const std::intializer_list<T>&) ;
		
			/** Copy constructor, creates copy of a given array
			@param a (l-value) array object
			@return <initialised-object> **/	
			//Array(const Array&) = default ;
			
			/** Copy assignment operator, creates copy of a given array
			@param a (l-value) array object
			@return reference to current object **/
			//Array& operator=(const Array&) = default ;
			
			/** Move constructor, takes ownership of array contents
			@param an r-value array object
			@return <initialised-object> **/	
			//Array(const Array&) = default ;
			
			/** Move assignment operator, takes ownership of array contents
			@param an r-value array object
			@return reference to current object **/
			//Array& operator=(const Array&) = default ;			
			
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
			@param integer to index structure with
			@param bool (assumingly true flag as to check whether an index is valid)
			@return reference to a given element in the structure **/ 				
			T& at(const std::size_t, const bool check = true) ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with
			@param bool (assumingly true flag as to check whether an index is valid)
			@return constant reference to a given element in the structure **/ 	
			const T& at(const std::size_t, const bool check = true) const ; 
			
			/** Concatenation operator, adds two arrays together
			@param array structure to add 
			@return array containing combined values **/ 	
			Array<T,(SIZE+SIZE)> operator+(const Array&) const ;			
			
			/** Concatenation operator, adds two arrays together
			@param array structure (of a different size) to add
			@return array containing combined values **/ 	
			template<std::size_t DIFF>
			Array<T,(SIZE+DIFF)> operator+(const Array<T, DIFF>&) const ;	
			
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
			
			/** (Trivial) Destructor **/					
			~Array() = default ;
			
			class Iterator {
				private:
					T* pointer ;
				
				public:
					Iterator(T*) ;
					
					T& operator*() const ;
					
					T* operator->() const ;
					
					Iterator operator+(const std::size_t) const ;
					
					Iterator& operator+=(const std::size_t) ;
					
					Iterator& operator++() ; 

					Iterator operator++(const int) ;
					
					Iterator operator-(const std::size_t) const ;
					
					Iterator& operator-=(const std::size_t) ;
					
					Iterator& operator--() ; 

					Iterator operator--(const int) ;

					bool operator==(const Iterator&) const ;
					
					bool operator!=(const Iterator&) const ;
					
			} ; 
			
			class ConstIterator {
				private:
					T const* pointer ;
					
				public:
					ConstIterator(T const*) ;
					
					const T& operator*() const ;
					
					const T* operator->() const ;
					
					ConstIterator operator+(const std::size_t) const ;
					
					ConstIterator& operator+=(const std::size_t) ;
					
					ConstIterator& operator++() ; 

					ConstIterator operator++(const int) ;
					
					ConstIterator operator-(const std::size_t) const ;
					
					ConstIterator& operator-=(const std::size_t) ;
					
					ConstIterator& operator--() ; 

					ConstIterator operator--(const int) ;

					bool operator==(const ConstIterator&) const ;
					
					bool operator!=(const ConstIterator&) const ;
			} ; 
			
			Iterator begin() ;
			
			Iterator end() ;
			
			ConstIterator begin() const ;
			
			ConstIterator end() const ;
			
			ConstIterator cbegin() const ;
			
			ConstIterator cend() const ;
			
			template<class, std::size_t>
			friend class Array ;
	} ;
	
}

#include "array.tpp"

#endif
