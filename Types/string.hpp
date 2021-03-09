#ifndef STRING_HPP
#define STRING_HPP
#pragma once

#include <iostream>

namespace Salih::Types {

	class String {
		private:
			char* str ;
			
			int size ;
			
		public:
		
			String() ;
			
			String(const char*) ;
			
			String(const String&) ;
			
			String(String&&) ;
					
			~String() ;
			
			void operator=(const char*) ;
			
			void operator=(const String&) ;
			
			void operator=(String&&) ;
			
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

void Salih::Types::String::operator=(const char* tbc)
{
	delete[] this->str ;
	for(this->size = 0 ; tbc[this->size] != '\0'; this->size++) ;
	this->str = new char[this->size + 1] ;
	for(int i = 0 ; i < this->size ; i++) this->str[i] = tbc[i] ;
	this->str[this->size] = '\0' ;
}

void Salih::Types::String::operator=(const Salih::Types::String& tbc)
{
	delete[] this->str ;
	this->size = tbc.size ;
	this->str = new char[this->size+1] ;
	for(int i = 0 ; i < this->size ; i++) this->str[i] = tbc.str[i] ;
	this->str[this->size] = '\0' ;
}

void Salih::Types::String::operator=(Salih::Types::String&& tbo)
{
	delete[] this->str ;
	this->size = tbo.size ;
	this->str = tbo.str ;
	tbo.size = 0 ;
	tbo.str = nullptr ;
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
