#ifndef STRING_HPP
#define STRING_HPP
#pragma once

#include <string>
#include <cstring>
#include <iostream>

namespace Salih::Types {

	class String {
		private:
			char* str ;
			
			int size ;
			
		public:
		
			String() ;
			
			String(char*) ;
			
			String(const String&) ;
			
			String operator=(const String&) ;
			
			String(String&&) ;
			
			String operator=(String&&) ;
			
			~String() ;
			
			String operator+(char) ; //to append char
			
			void operator+=(char) ; //to append char
			
			String operator+(const String&) ; //to append another string
			
			void operator+=(const String&) ; //to append another string
			
			char* getStr() const ;
			
			int getSize() const ;
	} ;
}

Salih::Types::String::String()
{
	this->str = new char[1] ;
	this->str[0] = '\0' ;
	this->size = 0 ;
}

Salih::Types::String::String(char* input)
{
	this->size = 0 ;
	if(input == nullptr)  
	{
		str = new char[1] ;
		str[0] = '\0' ;
	}
	else {
		//implement
	}
}

Salih::Types::String::String(const Salih::Types::String& tbc)
{
	this->str = new char[tbc.size+1] ;
	//implement
}

Salih::Types::String Salih::Types::String::operator=(const Salih::Types::String& tbc)
{
	//implement
}

Salih::Types::String::String(Salih::Types::String&& tbo)
{
	this->size = tbo.size ;
	this->str = tbo.str ;
	tbo.size = 0 ;
	tbo.str = nullptr ;
}

Salih::Types::String Salih::Types::String::operator=(Salih::Types::String&& tbo)
{
	this->size = tbo.size ;
	this->str = tbo.str ;
	tbo.size = 0 ;
	tbo.str = nullptr ;
}


Salih::Types::String::~String()
{
	delete str ;
	str = nullptr ;
}

Salih::Types::String Salih::Types::String::operator+(char c) 
{
	//implement this
}

void Salih::Types::String::operator+=(char c) 
{
	//implement this
}

Salih::Types::String Salih::Types::String::operator+(const Salih::Types::String&) 
{
	//implement this
}

void Salih::Types::String::operator+=(const Salih::Types::String&) 
{
	//implement this
}

char* Salih::Types::String::getStr() const
{
	return this->str ;
}

int Salih::Types::String::getSize() const
{
	return this->size ;
}

// helpful overloads

std::ostream& operator<<(std::ostream& os, const Salih::Types::String& str)
{
	os << str.getStr() ;
	return os ;
}

#endif
