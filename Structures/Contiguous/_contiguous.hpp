#ifndef CONTIGUOUS_HPP
#define CONTIGUOUS_HPP
#pragma once

#include <algorithm>
#include <iostream>
#include <utility>
#include <initializer_list>

/** @brief Base contiguous-class header file, storing base mechanics of a fixed-contiguous data structure
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/
 
namespace Salih {
	
	namespace Structures::Contiguous {
	
		template<typename T>
		class Contiguous ;
		
	}
	
	template<typename T>
	::std::ostream& operator<<(::std::ostream&, const Structures::Contiguous::Contiguous<T>&) ;	
	
}


namespace Salih::Structures::Contiguous {

	template<class T>
	class Contiguous {
		/** This class is the contiguous base-class declaration **/
		protected:
			std::size_t size ;
			
			T* pointer ;
			
			Contiguous(T*, const std::size_t) ;
	
		public:
			//Contiguous() = delete ;
			
			/** Initialising constructor, intialises size of structure
			@param size (of structure)
			@return <initialised-object> **/
			Contiguous(const std::size_t) ;
			
			/** Regular constructor, intialises multiple values and size of structure
			@param initialisation list (of values for structure), size of structure
			@return <initialised-object> **/	
			Contiguous(const std::initializer_list<T>&, const std::size_t) ;
			
			//Contiguous& operator=(const std::initializer_list<T>&) ;
			
			/** Mock copy constructor, copys base-class reference into specifically-sized structure
			@param l-value reference to base-class object, size (of structure)
			@return <initialised-object> **/				
			Contiguous(const Contiguous&, const std::size_t) ;
			
			//Contiguous& operator=(const Contiguous&) ;

			/** Mock copy constructor, copys base-class reference into specifically-sized structure
			@param r-value reference to base-class object, size (of structure)
			@return <initialised-object> **/						
			Contiguous(Contiguous&&, const std::size_t) ;
			
			//Contiguous& operator=(Contiguous&&) ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/
			std::size_t getSize() const ;
			
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return reference to a given element in the structure **/ 
			T& operator[](const int) ; 
	
			/** Index operator, modifying structure directly
			@param integer to index structure with		
			@return constant reference to a given element in the structure **/ 		
			const T& operator[](const int) const ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with, bool (assumingly true flag as to check whether an index is valid)
			@return reference to a given element in the structure **/ 				
			T& at(const int, const bool check = true) ; 
			
			/** at method, another method to modify the structure
			@param integer to index structure with, bool (assumingly true flag as to check whether an index is valid)
			@return constant reference to a given element in the structure **/ 	
			const T& at(const int, const bool check = true) const ; 
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param contiguous structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is met **/ 	
			template<typename OTHER>
			bool operator==(const Contiguous<OTHER>&) const ;
			
			/** Comparison operator, determines if a calling objects values matches another structure's values
			@param contiguous structure to compare with
			@return a boolean representing whether equality is met **/ 	
			bool operator==(const Contiguous&) const ;
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param contiguous structure to compare with (with different data-type values within)
			@return a boolean representing whether equality is not met **/ 	
			template<typename OTHER>
			bool operator!=(const Contiguous<OTHER>&) const ;
			
			/** Inequality operator, determines if a calling objects values do not match another structure's values
			@param contiguous structure to compare with
			@return a boolean representing whether equality is not met **/ 
			bool operator!=(const Contiguous&) const ;
			
			//void del(const int) ;

			//virtual Contiguous operator()(const int, const int) const ; //slicing
			
			//virtual Contiguous operator+(const Contiguous&) const = 0 ;
			
			//virtual void operator+=(const Contiguous&) const = 0 ;
			
			//virtual Contiguous operator()(const int, const int) = 0 ;
			
			//virtual void insert(const int, T) = 0 ;
			
			//virtual void append(T) = 0 ;

			/** Virtual base-class destructor **/					
			virtual ~Contiguous() = 0 ;
			
			template<typename OTHER>
			friend class Contiguous ;
			
			friend ::std::ostream& ::Salih::operator<<(::std::ostream&, const Contiguous&) ;
	} ;
}

#include "_contiguous.tpp"

#endif
