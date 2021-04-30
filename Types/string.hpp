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

			/** get method, returns the c-string representation of a string
			@return constant c-string **/ 				
			const char* get() const ;

			/** getSize method, returns size of a string object
			@return integer representing size **/ 				
			std::size_t getSize() const ;

			/** Index operator, modifying string directly
			@param integer to index string with		
			@return reference to a given character in the string **/ 			
			char& operator[](const int) ;

			/** Index operator, modifying string directly
			@param integer to index string with		
			@return constant reference to a given character in the string **/ 			
			const char& operator[](const int) const ;

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
	for(int i = 0 ; i < size ; i++) str[i] = input[i] ;
	str[this->size] = '\0' ;
}

Salih::Types::String::String(const Salih::Types::String& tbc)
{
	this->str = new char[tbc.size+1] ;
	this->size = tbc.size ;
	for(int i = 0 ; i < this->size ; i++) this->str[i] = tbc.str[i] ;
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
	for(int i = 0 ; i < this->size ; i++) this->str[i] = tbc[i] ;
	this->str[this->size] = '\0' ;
}

Salih::Types::String& Salih::Types::String::operator=(const Salih::Types::String& tbc)
{
	delete[] this->str ;
	this->size = tbc.size ;
	this->str = new char[this->size+1] ;
	for(int i = 0 ; i < this->size ; i++) this->str[i] = tbc.str[i] ;
	this->str[this->size] = '\0' ;
}

Salih::Types::String& Salih::Types::String::operator=(Salih::Types::String&& tbo)
{
	delete[] this->str ;
	this->size = tbo.size ;
	this->str = tbo.str ;
	tbo.size = 0 ;
	tbo.str = nullptr ;
}

Salih::Types::String Salih::Types::String::operator+(char c) const
{
	Salih::Types::String tmp ;
	delete[] tmp.str ;
	tmp.size = this->size + 1 ;
	tmp.str = new char[tmp.size+1] ;
	for(int i = 0 ; i < tmp.size - 1 ; i++) tmp.str[i] = this->str[i] ;
	tmp.str[tmp.size-1] = c ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

Salih::Types::String& Salih::Types::String::operator+=(char c) 
{
	this->size = this->size + 1 ;
	char* tmp = new char[this->size+1] ;
	for(int i = 0 ; i < this->size - 1 ; i++) tmp[i] = this->str[i] ;
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
	
	for(int i = 0 ; i < this->size ; i++) tmp.str[i] = this->str[i] ;
	for(int i = this->size ; i < tmp.size ; i++) tmp.str[i] = tbm.str[i-this->size] ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

Salih::Types::String& Salih::Types::String::operator+=(const Salih::Types::String& tbm)
{
	char* tmp = new char[this->size + tbm.size + 1] ;
	for(int i = 0 ; i < this->size ; i++) tmp[i] = this->str[i] ;
	for(int i = this->size ; i < tbm.size + this->size ; i++) tmp[i] = tbm.str[i-this->size] ;
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
	
	for(int i = 0 ; i < this->size ; i++) tmp.str[i] = this->str[i] ;
	for(int i = this->size ; i < tmp.size ; i++) tmp.str[i] = tbm[i-this->size] ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

Salih::Types::String& Salih::Types::String::operator+=(const char* tbm)
{
	int tmpSize ;
	for(tmpSize = 0 ; tbm[tmpSize] != '\0' ; tmpSize++) ;
	char* tmp = new char[this->size + tmpSize + 1] ;
	
	for(int i = 0 ; i < this->size ; i++) tmp[i] = this->str[i] ;
	for(int i = this->size ; i < tmpSize + this->size ; i++) tmp[i] = tbm[i-this->size] ;
	this->size = this->size + tmpSize ;
	tmp[this->size] = '\0' ;
	delete[] this->str ;
	this->str = tmp ;
	
	return *this ;
}

bool Salih::Types::String::operator==(const char* str) const
{
	int i ;
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
	int i ;
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
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str.str[i]) return false ;
	}
	
	return true ;
}
			
bool Salih::Types::String::operator!=(const Salih::Types::String& str) const
{
	if(this->size != str.size) return true ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str.str[i]) return true ;
	}
	
	return false ;
}

const char* Salih::Types::String::get() const
{
	return this->str ;
}

int Salih::Types::String::getSize() const
{
	return this->size ;
}

char& Salih::Types::String::operator[](const int index)
{
	return this->str[index] ;
}

const char& Salih::Types::String::operator[](const int index) const
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
	
	for(int i = 1 ; i < tmp.size ; i++)
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
		
	for(int i = 0 ; i < tmp.size ; i++)
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
	for(int i = 0 ; i < this->size ; i++)
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
	for(int i = 0 ; i < this->size ; i++)
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
	for(int i = 0 ; i < this->size ; i++)
	{
		if( (this->str[i] >= 48 && this->str[i] <= 57) == 0) return false ;	
	}
	return true ;
}

bool Salih::Types::String::isUpper() const
{
	if(this->size == 0) return false ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 60 && this->str[i] <= 90)) return false ;
	}
	return true ;
}
			
bool Salih::Types::String::isLower() const
{
	if(this->size == 0) return false ;
	
	for(int i = 0 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 97 && this->str[i] <= 122)) return false ;
	}
	return true ;
}
			
bool Salih::Types::String::isCapitalised() const
{
	if(this->size == 0) return false ;
	
	if(!(this->str[0] >= 60 && this->str[0] <= 90)) return false ;
	
	for(int i = 1 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 97 && this->str[i] <= 122)) return false ;
	}
	
	return true ;
}

// helpful overloads


#endif
