#ifndef STRING_HPP
#define STRING_HPP
#pragma once

#include "../types/macros.hpp"
#include "../types/iterators.hpp"

/** @brief String-class implementation file, serving as a wrapper for a c-string (character array)
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace salih {
namespace containers {
	
	class String {
		/** This class is the String-class implementation, serving as a c-string (character array) wrapper **/
		public:
			using inner = char ;                            
			using pointer = char* ;                               
			using constPointer = const char* ;                         
			using reference = char& ;                             
			using constReference = const char& ;  
			using iteratorType = salih::types::RandomAccessIterator ;
				
		private:
			char* str ;
			
			std::size_t size ;
					
			inline CONSTEXPRCXX20 String(char*, const std::size_t) ;
				
		public:
			/** Empty constructor, intialises empty string 
			@return <initialised-object> **/
			CONSTEXPRCXX20 String() ;
	
			/** Regular constructor, intialises string to a specific length
			@param length of string to initialise
			@return <initialised-object> **/			
			CONSTEXPRCXX20 String(const std::size_t) ;
			
			/** Regular constructor, intialises string 
			@param a c-string to wrap
			@return <initialised-object> **/			
			CONSTEXPRCXX20 String(const char*) ;

			/** Copy constructor, creates copy of a given string
			@param a (l-value) string object
			@return <initialised-object> **/				
			CONSTEXPRCXX20 String(const String&) ;
		
			/** Move constructor, takes ownership of an otherwise temporary string object
			@param an r-value string object
			@return <initialised-object> **/				
			CONSTEXPRCXX20 String(String&&) ;
				
			/** Destructor, frees memory and deletes string **/					
			CONSTEXPRCXX20 ~String() ;
			
			/** Regular assignment operator, wraps around a new c-string
			@param a c-string to wrap
			@return reference to current object **/			
			CONSTEXPRCXX20 String& operator=(const char*) ;
			
			/** Copy assignment operator, creates copy of a given string
			@param a (l-value) string object
			@return reference to current object **/			
			CONSTEXPRCXX20 String& operator=(const String&) ;
	
			/** Move assignment operator, takes ownership of an otherwise temporary string object
			@param an (r-value) string object
			@return reference to current object **/			
			CONSTEXPRCXX20 String& operator=(String&&) ;

			/** Concatenation operator, creates a copy of a calling string with an additional character
			@param a character to append
			@return a copy of the string with the appended value **/ 			
			CONSTEXPRCXX20 String operator+(char) const ; //to append char

			/** Concatenation operator, modifies / appends calling string with an additional character
			@param a character to append
			@return a reference to the calling string **/ 			
			CONSTEXPRCXX20 String& operator+=(char) ; //to append char

			/** Concatenation operator, creates a copy of a calling string with an additional sequence of characters
			@param wrapped / object string 
			@return a copy of the string with the appended value **/ 			
			CONSTEXPRCXX20 String operator+(const String&) const ; //to append another string
			
			/** Concatenation operator, modifies / appends calling string with data of a provided string object
			@param wrapped / object string 
			@return a reference to the calling string **/ 			
			CONSTEXPRCXX20 String& operator+=(const String&) ; //to append another string

			/** Concatenation operator, creates a copy of a calling string with an additional sequence of characters
			@param c-string / null-terminated sequence of characters 
			@return a copy of the string with the appended value **/ 				
			CONSTEXPRCXX20 String operator+(const char*) const ;
			
			/** Concatenation operator, modifies / appends calling string with an additional sequence of characters
			@param c-string / null-terminated sequence of characters  
			@return a reference to the calling string **/ 			
			CONSTEXPRCXX20 String& operator+=(const char*) ;

			/** Comparison operator, determines if string object content matches with a given (c-)string
			@param c-string / null-terminated sequence of characters  
			@return a boolean representing whether equality is met **/ 			
			CONSTEXPRCXX20 bool operator==(const char*) const ;

			/** Inequality operator, determines if string object content does not match with a given (c-)string
			@param c-string / null-terminated sequence of characters  
			@return a boolean representing whether equality is not met **/ 			
			CONSTEXPRCXX20 bool operator!=(const char*) const ;

			/** Comparison operator, determines if string object content matches with a given string object
			@param wrapped / object string   
			@return a boolean representing whether equality is met **/ 				
			CONSTEXPRCXX20 bool operator==(const String&) const ;

			/** Inequality operator, determines if string object content does not match with a given string object
			@param wrapped / object string   
			@return a boolean representing whether equality is not met **/ 				
			CONSTEXPRCXX20 bool operator!=(const String&) const ;
			
			/** Multiplication operator, creates a duplicated string x amount of times
			@param number to multiply string by
			@return a duplicated string object **/ 				
			CONSTEXPRCXX20 String operator*(std::size_t) const ;
			
			/** Multiplication operator, overwrites a string with said duplicated string x amount of times
			@param number to multiply string by
			@return a reference to the calling string **/ 			
			CONSTEXPRCXX20 String& operator*=(std::size_t) ;			

			/** get method, returns the c-string representation of a string
			@return constant c-string **/ 				
			CONSTEXPRCXX20 const char* get() const ;

			/** getSize method, returns size of a string object
			@return integer representing size **/ 				
			CONSTEXPRCXX20 std::size_t getSize() const ;
			
			/** Slicing operator, extract part of structure directly
			@param integer to start slicing from	
			@param integer to slice until			
			@return sliced string (ie values from index a->b) **/			
			CONSTEXPRCXX20 String operator()(const std::size_t, const std::size_t) const ;

			/** Index operator, modifying string directly
			@param integer to index string with		
			@return reference to a given character in the string **/ 			
			CONSTEXPRCXX20 char& operator[](const std::size_t) ;

			/** Index operator, modifying string directly
			@param integer to index string with		
			@return constant reference to a given character in the string **/ 			
			CONSTEXPRCXX20 const char& operator[](const std::size_t) const ;

			/** capitalise method, capitalises a copy of calling object's string value
			@return calling object copy with capitalised values (where possible) **/ 			
			CONSTEXPRCXX20 String capitalise() const ;

			/** upper method, upper cases entire copy of calling object's string value
			@return calling object copy with upper-cased values (where possible) **/ 			
			CONSTEXPRCXX20 String upper() const ;

			/** lower method, lower cases entire copy of calling object's string value
			@return calling object copy with lower-cased values (where possible) **/ 			
			CONSTEXPRCXX20 String lower() const ;

			/** isAlphaNum method, determines if all values within string object are alphanumeric
			@return boolean indicatting if all values are alphanumeric **/ 				
			CONSTEXPRCXX20 bool isAlphaNum() const ;

			/** isAlpha method, determines if all values within string object are alphabetical
			@return boolean indicatting if all values are alphabetical **/ 				
			CONSTEXPRCXX20 bool isAlpha() const ;

			/** isNum method, determines if all values within string object are numerical
			@return boolean indicatting if all values are numerical **/ 				
			CONSTEXPRCXX20 bool isNum() const ;

			/** isUpper method, determines if all values within string object are in upper-case
			@return boolean indicatting if all values are in upper-case **/ 				
			CONSTEXPRCXX20 bool isUpper() const ;

			/** isLower method, determines if all values within string object are in lower-case
			@return boolean indicatting if all values are in lower-case **/ 				
			CONSTEXPRCXX20 bool isLower() const ;

			/** isCapitalised method, determines if all values within string object are in a capitalised format
			@return boolean indicatting if all values are in a capitalised format **/ 				
			CONSTEXPRCXX20 bool isCapitalised() const ;	
			
			class Iterator {
				/** This class represents an Iterator object, allowing for controlled, read-write access to the string's values **/ 
				public:
					using inner = char ;                            
					using pointer = char* ;                               
					using constPointer = const char* ;                         
					using reference = char& ;                             
					using constReference = const char& ;  
					using category = salih::types::RandomAccessIterator ;
					
				private:
					char* pointer;
					
					/** Regular constructor, intialises iterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					CONSTEXPRCXX20 Iterator(char*) ;
				
				public:
					/** Empty constructor, intialises empty iterator 
					@return <initialised-object> **/
					CONSTEXPRCXX20 Iterator() ;
					
					/** Copy constructor, copies address of element behind an iterator
					@param Iterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 Iterator(const Iterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an iterator
					@param Iterator object
					@return reference to calling Iterator **/
					CONSTEXPRCXX20 Iterator& operator=(const Iterator&) = default ;
					
					/** Move constructor, takes ownership of Iterator properties
					@param Iterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 Iterator(Iterator&&) = default ;
					
					/** Move assignment operator, takes ownership of Iterator properties
					@param Iterator object
					@return reference to calling Iterator **/
					CONSTEXPRCXX20 Iterator& operator=(Iterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					CONSTEXPRCXX20 char& operator*() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return Iterator object (pointing to the further element in sequence) **/					
					CONSTEXPRCXX20 Iterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to further element in sequence) **/					
					CONSTEXPRCXX20 Iterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling Iterator (now pointing to the next element in sequence) **/										
					CONSTEXPRCXX20 Iterator& operator++() ; 

					/** Postfix increment operator - modifies iterator to point to the next element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 Iterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return Iterator object (pointing to the earlier element in sequence) **/						
					CONSTEXPRCXX20 Iterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to the earlier element in sequence) **/											
					CONSTEXPRCXX20 Iterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies iterator to point to the previous element in sequence
					@return reference to calling Iterator (now pointing to the previous element in sequence) **/						
					CONSTEXPRCXX20 Iterator& operator--() ; 

					/** Postfix decrement operator - modifies iterator to point to the previous element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 Iterator operator--(const int) ;

					/** Comparison operator, determines if two iterators point to the same location
					@param Iterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					CONSTEXPRCXX20 bool operator==(const Iterator&) const ;

					/** Inequality operator, determines if two iterators don't point to the same location
					@param Iterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					CONSTEXPRCXX20 bool operator!=(const Iterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					CONSTEXPRCXX20 ~Iterator() = default ;
					
					friend class String ;
					
			} ; 
			
			class ConstIterator {
				/** This class represents a ConstIterator object, allowing for controlled, read-only access to the string's values **/ 
				public:
					using inner = char ;                            
					using pointer = char* ;                               
					using constPointer = const char* ;                         
					using reference = char& ;                             
					using constReference = const char& ;  
					using category = salih::types::RandomAccessIterator ;
					
				private:
					char const* pointer;
				
					/** Regular constructor, intialises ConstIterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					CONSTEXPRCXX20 ConstIterator(char const*) ;
				
				public:
					/** Empty constructor, intialises empty ConstIterator 
					@return <initialised-object> **/
					CONSTEXPRCXX20 ConstIterator() ;
					
					/** Copy constructor, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 ConstIterator(const ConstIterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					CONSTEXPRCXX20 ConstIterator& operator=(const ConstIterator&) = default ;
					
					/** Move constructor, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return <initialised-object> **/
					CONSTEXPRCXX20 ConstIterator(ConstIterator&&) = default ;
					
					/** Move assignment operator, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					CONSTEXPRCXX20 ConstIterator& operator=(ConstIterator&&) = default ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					CONSTEXPRCXX20 const char& operator*() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return ConstIterator object (pointing to the further element in sequence) **/					
					CONSTEXPRCXX20 ConstIterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps later
					@param Number of positions further in sequence that the ConstIterator should point to
					@return reference to calling ConstIterator (now pointing to further element in sequence) **/					
					CONSTEXPRCXX20 ConstIterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling ConstIterator (now pointing to the next element in sequence) **/										
					CONSTEXPRCXX20 ConstIterator& operator++() ; 

					/** Postfix increment operator - modifies ConstIterator to point to the next element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 ConstIterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the ConstIterator should point to
					@return ConstIterator object (pointing to the earlier element in sequence) **/						
					CONSTEXPRCXX20 ConstIterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling ConstIterator (now pointing to the earlier element in sequence) **/											
					CONSTEXPRCXX20 ConstIterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return reference to calling ConstIterator (now pointing to the previous element in sequence) **/						
					CONSTEXPRCXX20 ConstIterator& operator--() ; 

					/** Postfix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					CONSTEXPRCXX20 ConstIterator operator--(const int) ;

					/** Comparison operator, determines if two ConstIterators point to the same location
					@param ConstIterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					CONSTEXPRCXX20 bool operator==(const ConstIterator&) const ;

					/** Inequality operator, determines if two ConstIterators don't point to the same location
					@param ConstIterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					CONSTEXPRCXX20 bool operator!=(const ConstIterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					CONSTEXPRCXX20 ~ConstIterator() = default ;
					
					friend class String ;
					
			} ; 
			
			/** begin method, creates Iterator object to the first element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to first element in sequence **/ 
			CONSTEXPRCXX20 Iterator begin() ;

			/** end method, creates Iterator object to beyond the final element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX20 Iterator end() ;

			/** begin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to first element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator begin() const ;

			/** end method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator end() const ;

			/** cbegin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to first element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator cbegin() const ;

			/** cend method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			CONSTEXPRCXX20 ConstIterator cend() const ;	
		
	} ;
}
}

#include "string.tpp"

#endif
