#ifndef STRING_HPP
#define STRING_HPP
#pragma once

#include <iostream>

/** @brief String-class implementation file, serving as a wrapper for a c-string (character array)
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Types {
	
		class String ;
	
}

namespace Salih::Types {
	
	class String {
		/** This class is the String-class implementation, serving as a c-string (character array) wrapper **/
	
		private:
			char* str ;
			
			std::size_t size ;
					
			String(char*, const std::size_t) ;	
		public:
			/** Empty constructor, intialises empty string 
			@return <initialised-object> **/
			String() ;
			
			/** Regular constructor, intialises string 
			@param a c-string to wrap
			@return <initialised-object> **/			
			String(const char*) ;

			/** Copy constructor, creates copy of a given string
			@param a (l-value) string object
			@return <initialised-object> **/				
			String(const String&) ;
		
			/** Move constructor, takes ownership of an otherwise temporary string object
			@param an r-value string object
			@return <initialised-object> **/				
			String(String&&) ;
				
			/** Destructor, frees memory and deletes string **/					
			~String() ;
			
			/** Regular assignment operator, wraps around a new c-string
			@param a c-string to wrap
			@return reference to current object **/			
			String& operator=(const char*) ;
			
			/** Copy assignment operator, creates copy of a given string
			@param a (l-value) string object
			@return reference to current object **/			
			String& operator=(const String&) ;
	
			/** Move assignment operator, takes ownership of an otherwise temporary string object
			@param an (r-value) string object
			@return reference to current object **/			
			String& operator=(String&&) ;

			/** Concatenation operator, creates a copy of a calling string with an additional character
			@param a character to append
			@return a copy of the string with the appended value **/ 			
			String operator+(char) const ; //to append char

			/** Concatenation operator, modifies / appends calling string with an additional character
			@param a character to append
			@return a reference to the calling string **/ 			
			String& operator+=(char) ; //to append char

			/** Concatenation operator, creates a copy of a calling string with an additional sequence of characters
			@param wrapped / object string 
			@return a copy of the string with the appended value **/ 			
			String operator+(const String&) const ; //to append another string
			
			/** Concatenation operator, modifies / appends calling string with data of a provided string object
			@param wrapped / object string 
			@return a reference to the calling string **/ 			
			String& operator+=(const String&) ; //to append another string

			/** Concatenation operator, creates a copy of a calling string with an additional sequence of characters
			@param c-string / null-terminated sequence of characters 
			@return a copy of the string with the appended value **/ 				
			String operator+(const char*) const ;
			
			/** Concatenation operator, modifies / appends calling string with an additional sequence of characters
			@param c-string / null-terminated sequence of characters  
			@return a reference to the calling string **/ 			
			String& operator+=(const char*) ;

			/** Comparison operator, determines if string object content matches with a given (c-)string
			@param c-string / null-terminated sequence of characters  
			@return a boolean representing whether equality is met **/ 			
			bool operator==(const char*) const ;

			/** Inequality operator, determines if string object content does not match with a given (c-)string
			@param c-string / null-terminated sequence of characters  
			@return a boolean representing whether equality is not met **/ 			
			bool operator!=(const char*) const ;

			/** Comparison operator, determines if string object content matches with a given string object
			@param wrapped / object string   
			@return a boolean representing whether equality is met **/ 				
			bool operator==(const String&) const ;

			/** Inequality operator, determines if string object content does not match with a given string object
			@param wrapped / object string   
			@return a boolean representing whether equality is not met **/ 				
			bool operator!=(const String&) const ;
			
			/** Multiplication operator, creates a duplicated string x amount of times
			@param number to multiply string by
			@return a duplicated string object **/ 				
			String operator*(std::size_t) const ;
			
			/** Multiplication operator, overwrites a string with said duplicated string x amount of times
			@param number to multiply string by
			@return a reference to the calling string **/ 			
			String& operator*=(std::size_t) ;			

			/** get method, returns the c-string representation of a string
			@return constant c-string **/ 				
			const char* get() const ;

			/** getSize method, returns size of a string object
			@return integer representing size **/ 				
			std::size_t getSize() const ;
			
			/** Slicing operator, extract part of structure directly
			@param integer to start slicing from	
			@param integer to slice until			
			@return sliced string (ie values from index a->b) **/			
			String operator()(const std::size_t, const std::size_t) const ;

			/** Index operator, modifying string directly
			@param integer to index string with		
			@return reference to a given character in the string **/ 			
			char& operator[](const std::size_t) ;

			/** Index operator, modifying string directly
			@param integer to index string with		
			@return constant reference to a given character in the string **/ 			
			const char& operator[](const std::size_t) const ;

			/** capitalise method, capitalises a copy of calling object's string value
			@return calling object copy with capitalised values (where possible) **/ 			
			String capitalise() const ;

			/** upper method, upper cases entire copy of calling object's string value
			@return calling object copy with upper-cased values (where possible) **/ 			
			String upper() const ;

			/** lower method, lower cases entire copy of calling object's string value
			@return calling object copy with lower-cased values (where possible) **/ 			
			String lower() const ;

			/** isAlphaNum method, determines if all values within string object are alphanumeric
			@return boolean indicatting if all values are alphanumeric **/ 				
			bool isAlphaNum() const ;

			/** isAlpha method, determines if all values within string object are alphabetical
			@return boolean indicatting if all values are alphabetical **/ 				
			bool isAlpha() const ;

			/** isNum method, determines if all values within string object are numerical
			@return boolean indicatting if all values are numerical **/ 				
			bool isNum() const ;

			/** isUpper method, determines if all values within string object are in upper-case
			@return boolean indicatting if all values are in upper-case **/ 				
			bool isUpper() const ;

			/** isLower method, determines if all values within string object are in lower-case
			@return boolean indicatting if all values are in lower-case **/ 				
			bool isLower() const ;

			/** isCapitalised method, determines if all values within string object are in a capitalised format
			@return boolean indicatting if all values are in a capitalised format **/ 				
			bool isCapitalised() const ;	
			
			class Iterator {
				/** This class represents an Iterator object, allowing for controlled, read-write access to the string's values **/ 
				private:
					char* pointer;
				
				public:
					/** Empty constructor, intialises empty iterator 
					@return <initialised-object> **/
					Iterator() ;
					
					/** Copy constructor, copies address of element behind an iterator
					@param Iterator object
					@return <initialised-object> **/
					Iterator(const Iterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an iterator
					@param Iterator object
					@return reference to calling Iterator **/
					Iterator& operator=(const Iterator&) = default ;
					
					/** Move constructor, takes ownership of Iterator properties
					@param Iterator object
					@return <initialised-object> **/
					Iterator(Iterator&&) = default ;
					
					/** Move assignment operator, takes ownership of Iterator properties
					@param Iterator object
					@return reference to calling Iterator **/
					Iterator& operator=(Iterator&&) = default ;

					/** Regular constructor, intialises iterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					Iterator(char*) ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					char& operator*() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return Iterator object (pointing to the further element in sequence) **/					
					Iterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to further element in sequence) **/					
					Iterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling Iterator (now pointing to the next element in sequence) **/										
					Iterator& operator++() ; 

					/** Postfix increment operator - modifies iterator to point to the next element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					Iterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return Iterator object (pointing to the earlier element in sequence) **/						
					Iterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling Iterator (now pointing to the earlier element in sequence) **/											
					Iterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies iterator to point to the previous element in sequence
					@return reference to calling Iterator (now pointing to the previous element in sequence) **/						
					Iterator& operator--() ; 

					/** Postfix decrement operator - modifies iterator to point to the previous element in sequence
					@return Iterator object (pointing to the element prior to modification) **/					
					Iterator operator--(const int) ;

					/** Comparison operator, determines if two iterators point to the same location
					@param Iterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					bool operator==(const Iterator&) const ;

					/** Inequality operator, determines if two iterators don't point to the same location
					@param Iterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					bool operator!=(const Iterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					~Iterator() = default ;
					
			} ; 
			
			class ConstIterator {
				/** This class represents a ConstIterator object, allowing for controlled, read-only access to the string's values **/ 
				private:
					char const* pointer;
				
				public:
					/** Empty constructor, intialises empty ConstIterator 
					@return <initialised-object> **/
					ConstIterator() ;
					
					/** Copy constructor, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return <initialised-object> **/
					ConstIterator(const ConstIterator&) = default ;
					
					/** Copy assignment operator, copies address of element behind an ConstIterator
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					ConstIterator& operator=(const ConstIterator&) = default ;
					
					/** Move constructor, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return <initialised-object> **/
					ConstIterator(ConstIterator&&) = default ;
					
					/** Move assignment operator, takes ownership of ConstIterator properties
					@param ConstIterator object
					@return reference to calling ConstIterator **/
					ConstIterator& operator=(ConstIterator&&) = default ;

					/** Regular constructor, intialises ConstIterator to a given location
					@param Pointer (to an element of type T)
					@return <initialised-object> **/				
					ConstIterator(char const*) ;

					/** Dereferncing operator - gets data behind the iterator
					@return referemce to data **/					
					const char& operator*() const ;

					/** Subtraction operator - gets iterator to an element in sequence x steps later
					@param Number of positions further in sequence that the iterator should point to
					@return ConstIterator object (pointing to the further element in sequence) **/					
					ConstIterator operator+(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps later
					@param Number of positions further in sequence that the ConstIterator should point to
					@return reference to calling ConstIterator (now pointing to further element in sequence) **/					
					ConstIterator& operator+=(const std::size_t) ;

					/** Prefix increment operator - modifies iterator to point to the next element in sequence
					@return reference to calling ConstIterator (now pointing to the next element in sequence) **/										
					ConstIterator& operator++() ; 

					/** Postfix increment operator - modifies ConstIterator to point to the next element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					ConstIterator operator++(const int) ;

					/** Subtraction operator - gets iterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the ConstIterator should point to
					@return ConstIterator object (pointing to the earlier element in sequence) **/						
					ConstIterator operator-(const std::size_t) const ;

					/** Subtraction operator - modifies ConstIterator to an element in sequence x steps prior
					@param Number of positions previous in sequence that the iterator should point to
					@return reference to calling ConstIterator (now pointing to the earlier element in sequence) **/											
					ConstIterator& operator-=(const std::size_t) ;

					/** Prefix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return reference to calling ConstIterator (now pointing to the previous element in sequence) **/						
					ConstIterator& operator--() ; 

					/** Postfix decrement operator - modifies ConstIterator to point to the previous element in sequence
					@return ConstIterator object (pointing to the element prior to modification) **/					
					ConstIterator operator--(const int) ;

					/** Comparison operator, determines if two ConstIterators point to the same location
					@param ConstIterator object
					@return a boolean (True if iterators point to same location, false if otherwise) **/
					bool operator==(const ConstIterator&) const ;

					/** Inequality operator, determines if two ConstIterators don't point to the same location
					@param ConstIterator object
					@return a boolean (False if iterators point to same location, true if otherwise) **/					
					bool operator!=(const ConstIterator&) const ;
					
					/** (Trivial) Destructor (Default) **/
					~ConstIterator() = default ;
					
			} ; 
			
			/** begin method, creates Iterator object to the first element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to first element in sequence **/ 
			Iterator begin() ;

			/** end method, creates Iterator object to beyond the final element of the structure. Allows for read-write access of structure. Note: is called if calling object is mutable
			@return Iterator pointing to beyond the final element in sequence **/ 			
			Iterator end() ;

			/** begin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to first element in sequence **/ 			
			ConstIterator begin() const ;

			/** end method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure. Note: is called if calling object is a constant
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			ConstIterator end() const ;

			/** cbegin method, creates ConstIterator object to the first element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to first element in sequence **/ 			
			ConstIterator cbegin() const ;

			/** cend method, creates ConstIterator object to beyond the final element of the structure. Allows for read-only access of structure
			@return ConstIterator pointing to beyond the final element in sequence **/ 			
			ConstIterator cend() const ;	
		
	} ;
}

Salih::Types::String::String(char* temp, const std::size_t SIZE)
{
	this->str = temp ;
	this->size = SIZE ;
}

Salih::Types::String::String()
{
	this->str = new char[1] ;
	this->str[0] = '\0' ;
	this->size = 0 ;
}

Salih::Types::String::String(const char* input)
{
	for(this->size = 0 ; input[this->size] != '\0'; this->size++) ;
	this->str = new char[size + 1] ;
	for(std::size_t i = 0 ; i < size ; i++) str[i] = input[i] ;
	str[this->size] = '\0' ;
}

Salih::Types::String::String(const Salih::Types::String& tbc)
{
	this->str = new char[tbc.size+1] ;
	this->size = tbc.size ;
	for(std::size_t i = 0 ; i < this->size ; i++) this->str[i] = tbc.str[i] ;
	this->str[this->size] = '\0' ;
}

Salih::Types::String::String(Salih::Types::String&& tbo)
{
	delete[] this->str ;
	this->size = tbo.size ;
	this->str = tbo.str ;
	tbo.size = 0 ;
	tbo.str = nullptr ;
}

Salih::Types::String::~String()
{
	if(str == nullptr) return;
	delete[] str ; //else
	str = nullptr ;
}

Salih::Types::String& Salih::Types::String::operator=(const char* tbc)
{
	delete[] this->str ;
	for(this->size = 0 ; tbc[this->size] != '\0'; this->size++) ;
	this->str = new char[this->size + 1] ;
	for(std::size_t i = 0 ; i < this->size ; i++) this->str[i] = tbc[i] ;
	this->str[this->size] = '\0' ;
	return *this ;
}

Salih::Types::String& Salih::Types::String::operator=(const Salih::Types::String& tbc)
{
	delete[] this->str ;
	this->size = tbc.size ;
	this->str = new char[this->size+1] ;
	for(std::size_t i = 0 ; i < this->size ; i++) this->str[i] = tbc.str[i] ;
	this->str[this->size] = '\0' ;
	return *this ;
}

Salih::Types::String& Salih::Types::String::operator=(Salih::Types::String&& tbo)
{
	delete[] this->str ;
	this->size = tbo.size ;
	this->str = tbo.str ;
	tbo.size = 0 ;
	tbo.str = nullptr ;
	return *this ;
}

Salih::Types::String Salih::Types::String::operator+(char c) const
{
	Salih::Types::String tmp ;
	delete[] tmp.str ;
	tmp.size = this->size + 1 ;
	tmp.str = new char[tmp.size+1] ;
	for(std::size_t i = 0 ; i < tmp.size - 1 ; i++) tmp.str[i] = this->str[i] ;
	tmp.str[tmp.size-1] = c ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

Salih::Types::String& Salih::Types::String::operator+=(char c) 
{
	this->size = this->size + 1 ;
	char* tmp = new char[this->size+1] ;
	for(std::size_t i = 0 ; i < this->size - 1 ; i++) tmp[i] = this->str[i] ;
	tmp[this->size-1] = c ;
	tmp[this->size] = '\0' ;
	delete[] this->str ;
	this->str = tmp ;
	
	return *this ;
}

Salih::Types::String Salih::Types::String::operator+(const Salih::Types::String& tbm) const
{
	Salih::Types::String tmp ; delete[] tmp.str ;
	tmp.size = this->size + tbm.size ;
	tmp.str = new char[tmp.size+1] ;
	
	for(std::size_t i = 0 ; i < this->size ; i++) tmp.str[i] = this->str[i] ;
	for(std::size_t i = this->size ; i < tmp.size ; i++) tmp.str[i] = tbm.str[i-this->size] ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

Salih::Types::String& Salih::Types::String::operator+=(const Salih::Types::String& tbm)
{
	char* tmp = new char[this->size + tbm.size + 1] ;
	for(std::size_t i = 0 ; i < this->size ; i++) tmp[i] = this->str[i] ;
	for(std::size_t i = this->size ; i < tbm.size + this->size ; i++) tmp[i] = tbm.str[i-this->size] ;
	this->size = this->size + tbm.size ;
	tmp[this->size] = '\0' ;
	delete[] this->str ;
	this->str = tmp ;
	
	return *this ;
}

Salih::Types::String Salih::Types::String::operator+(const char* tbm) const
{
	Salih::Types::String tmp ; delete[] tmp.str ;
	
	tmp.size = 0 ;
	for(tmp.size = 0 ; tbm[tmp.size] != '\0' ; tmp.size++) ;
	tmp.size += this->size ;
	
	tmp.str = new char[tmp.size+1] ;
	
	for(std::size_t i = 0 ; i < this->size ; i++) tmp.str[i] = this->str[i] ;
	for(std::size_t i = this->size ; i < tmp.size ; i++) tmp.str[i] = tbm[i-this->size] ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

Salih::Types::String& Salih::Types::String::operator+=(const char* tbm)
{
	std::size_t tmpSize ;
	for(tmpSize = 0 ; tbm[tmpSize] != '\0' ; tmpSize++) ;
	char* tmp = new char[this->size + tmpSize + 1] ;
	
	for(std::size_t i = 0 ; i < this->size ; i++) tmp[i] = this->str[i] ;
	for(std::size_t i = this->size ; i < tmpSize + this->size ; i++) tmp[i] = tbm[i-this->size] ;
	this->size = this->size + tmpSize ;
	tmp[this->size] = '\0' ;
	delete[] this->str ;
	this->str = tmp ;
	
	return *this ;
}

Salih::Types::String Salih::Types::String::operator*(std::size_t x) const
{
	Salih::Types::String tmp ;
	char* tmpStr = new char[(this->size * x) + 1] ;
	for(int i = 0 ; i < x ; i++)
	{
		for(int j = 0 ; j < this->size ; j++)
		{
			tmpStr[j+(i*this->size)] = this->str[j] ;
		}
	}
	tmpStr[this->size * x] = '\0' ;
	tmp.str = tmpStr ;
	tmp.size = this->size * x ;
	return tmp ;
}

Salih::Types::String& Salih::Types::String::operator*=(std::size_t x)
{
	char* tmpStr = new char[(this->size * x) + 1] ;
	for(int i = 0 ; i < x ; i++)
	{
		for(int j = 0 ; j < this->size ; j++)
		{
			tmpStr[j+(i*this->size)] = this->str[j] ;
		}
	}
	tmpStr[this->size * x] = '\0' ;
	delete[] this->str ;
	this->str = tmpStr ;
	this->size = this->size * x ;	
	return *this ;
}

bool Salih::Types::String::operator==(const char* str) const
{
	std::size_t i ;
	for(i = 0 ; str[i] != '\0' ; i++) ;
	
	if(this->size != i) return false ;
	
	for(i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str[i]) return false ;
	}
	
	return true ;
}
			
bool Salih::Types::String::operator!=(const char* str) const
{
	std::size_t i ;
	for(i = 0 ; str[i] != '\0' ; i++) ;
	
	if(this->size != i) return true ;
	
	for(i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str[i]) return true ;
	}
	
	return false ;
}
			
bool Salih::Types::String::operator==(const Salih::Types::String& str) const
{
	if(this->size != str.size) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str.str[i]) return false ;
	}
	
	return true ;
}
			
bool Salih::Types::String::operator!=(const Salih::Types::String& str) const
{
	if(this->size != str.size) return true ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str.str[i]) return true ;
	}
	
	return false ;
}

const char* Salih::Types::String::get() const
{
	return this->str ;
}

std::size_t Salih::Types::String::getSize() const
{
	return this->size ;
}

Salih::Types::String Salih::Types::String::operator()(const std::size_t a, const std::size_t b) const 
{
	if(a > b || a < 0 || b > this->size) throw std::out_of_range("Element range requested does not exist") ;
	Salih::Types::String tmp ;
	for(std::size_t idx = a ; idx < b ; idx++) tmp[idx-a] += this->str[idx] ;
	return tmp ;
}

char& Salih::Types::String::operator[](const std::size_t index)
{
	return this->str[index] ;
}

const char& Salih::Types::String::operator[](const std::size_t index) const
{
	return this->str[index] ;
}
			
Salih::Types::String Salih::Types::String::capitalise() const
{
	Salih::Types::String tmp(*this) ;
	
	if(tmp[0] >= 97 && tmp[0] <= 122)
	{
		tmp[0] = tmp[0] - 32 ;
	}
	
	for(std::size_t i = 1 ; i < tmp.size ; i++)
	{
		if(tmp[i] >= 65 && tmp[i] <= 90)
		{
			tmp[i] = tmp[i] + 32 ;
		}
	}
	return tmp ;
}
			
Salih::Types::String Salih::Types::String::upper() const
{
	Salih::Types::String tmp(*this) ;
		
	for(std::size_t i = 0 ; i < tmp.size ; i++)
	{
		if(tmp[i] >= 97 && tmp[i] <= 122)
		{
			tmp[i] = tmp[i] - 32 ;
		}
	}
	
	return tmp ;
}
			
Salih::Types::String Salih::Types::String::lower() const
{
	Salih::Types::String tmp(*this) ;
		
	for(int i = 0 ; i < tmp.size ; i++)
	{
		if(tmp[i] >= 65 && tmp[i] <= 90)
		{
			tmp[i] = tmp[i] + 32 ;
		}
	}
	
	return tmp ;
}

bool Salih::Types::String::isAlphaNum() const
{
	if(this->size == 0) return false ;
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(	((this->str[i] >= 48 && this->str[i] <= 57) || 
			(this->str[i] >= 65 && this->str[i] <= 90) || 
			(this->str[i] >= 97 && this->str[i] <= 122)) == 0
		)
		return false ;	
	}
	return true ;
}
			
bool Salih::Types::String::isAlpha() const
{
	if(this->size == 0) return false ;
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(	((this->str[i] >= 65 && this->str[i] <= 90) || 
			(this->str[i] >= 97 && this->str[i] <= 122)) == 0
		)
		return false ;	
	}
	return true ;
}
			
bool Salih::Types::String::isNum() const
{
	if(this->size == 0) return false ;
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if( (this->str[i] >= 48 && this->str[i] <= 57) == 0) return false ;	
	}
	return true ;
}

bool Salih::Types::String::isUpper() const
{
	if(this->size == 0) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 60 && this->str[i] <= 90)) return false ;
	}
	return true ;
}
			
bool Salih::Types::String::isLower() const
{
	if(this->size == 0) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 97 && this->str[i] <= 122)) return false ;
	}
	return true ;
}
			
bool Salih::Types::String::isCapitalised() const
{
	if(this->size == 0) return false ;
	
	if(!(this->str[0] >= 60 && this->str[0] <= 90)) return false ;
	
	for(std::size_t i = 1 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 97 && this->str[i] <= 122)) return false ;
	}
	
	return true ;
}

Salih::Types::String::Iterator::Iterator() : pointer(nullptr) {} ;

Salih::Types::String::Iterator::Iterator(char* input) : pointer(input) {} ;

char& Salih::Types::String::Iterator::operator*() const
{
	return *this->pointer ; 
}

typename Salih::Types::String::Iterator Salih::Types::String::Iterator::operator+(const std::size_t x) const
{
	return Salih::Types::String::Iterator(this->pointer + x) ; 
}

typename Salih::Types::String::Iterator& Salih::Types::String::Iterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

typename Salih::Types::String::Iterator& Salih::Types::String::Iterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

typename Salih::Types::String::Iterator Salih::Types::String::Iterator::operator++(const int)
{
	Salih::Types::String::Iterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

typename Salih::Types::String::Iterator Salih::Types::String::Iterator::operator-(const std::size_t x) const
{
	return Salih::Types::String::Iterator(this->pointer - x) ; 
}

typename Salih::Types::String::Iterator& Salih::Types::String::Iterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

typename Salih::Types::String::Iterator& Salih::Types::String::Iterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

typename Salih::Types::String::Iterator Salih::Types::String::Iterator::operator--(const int)
{
	Salih::Types::String::Iterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

bool Salih::Types::String::Iterator::operator==(const Salih::Types::String::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

bool Salih::Types::String::Iterator::operator!=(const Salih::Types::String::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

Salih::Types::String::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

Salih::Types::String::ConstIterator::ConstIterator(char const* input) : pointer(input) {} ;

const char& Salih::Types::String::ConstIterator::operator*() const
{
	return *this->pointer ; 
}

typename Salih::Types::String::ConstIterator Salih::Types::String::ConstIterator::operator+(const std::size_t x) const
{
	return Salih::Types::String::ConstIterator(this->pointer + x) ; 
}

typename Salih::Types::String::ConstIterator& Salih::Types::String::ConstIterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

typename Salih::Types::String::ConstIterator& Salih::Types::String::ConstIterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

typename Salih::Types::String::ConstIterator Salih::Types::String::ConstIterator::operator++(const int)
{
	Salih::Types::String::ConstIterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

typename Salih::Types::String::ConstIterator Salih::Types::String::ConstIterator::operator-(const std::size_t x) const
{
	return Salih::Types::String::ConstIterator(this->pointer - x) ; 
}

typename Salih::Types::String::ConstIterator& Salih::Types::String::ConstIterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

typename Salih::Types::String::ConstIterator& Salih::Types::String::ConstIterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

typename Salih::Types::String::ConstIterator Salih::Types::String::ConstIterator::operator--(const int)
{
	Salih::Types::String::ConstIterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

bool Salih::Types::String::ConstIterator::operator==(const Salih::Types::String::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

bool Salih::Types::String::ConstIterator::operator!=(const Salih::Types::String::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

typename Salih::Types::String::Iterator Salih::Types::String::begin()
{
	return Salih::Types::String::Iterator(this->str) ;
}

typename Salih::Types::String::Iterator Salih::Types::String::end()
{
	return Salih::Types::String::Iterator(this->str + this->size) ;
}

typename Salih::Types::String::ConstIterator Salih::Types::String::begin() const 
{
	return Salih::Types::String::ConstIterator(this->str) ;
}

typename Salih::Types::String::ConstIterator Salih::Types::String::end() const
{
	return Salih::Types::String::ConstIterator (this->str + this->size) ;
}

typename Salih::Types::String::ConstIterator Salih::Types::String::cbegin() const 
{
	return Salih::Types::String::ConstIterator(this->str) ;
}

typename Salih::Types::String::ConstIterator Salih::Types::String::cend() const
{
	return Salih::Types::String::ConstIterator(this->str + this->size) ;
}

#endif
