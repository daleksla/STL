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
			
			String operator+(char) const ; //to append char
			
			void operator+=(char) ; //to append char
			
			String operator+(const String&) const ; //to append another string
			
			void operator+=(const String&) ; //to append another string
			
			String operator+(const char*) const ;
			
			void operator+=(const char*) ;
			
			char* getStr() const ;
			
			int getSize() const ;
			
			char& operator[](const int) ;
			
			String capitalise() const ;
			
			String upper() const ;
			
			String lower() const ;
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

void Salih::Types::String::operator+=(char c) 
{
	this->size = this->size + 1 ;
	char* tmp = new char[this->size+1] ;
	for(int i = 0 ; i < this->size - 1 ; i++) tmp[i] = this->str[i] ;
	tmp[this->size-1] = c ;
	tmp[this->size] = '\0' ;
	delete[] this->str ;
	this->str = tmp ;
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

void Salih::Types::String::operator+=(const Salih::Types::String& tbm)
{
	char* tmp = new char[this->size + tbm.size + 1] ;
	for(int i = 0 ; i < this->size ; i++) tmp[i] = this->str[i] ;
	for(int i = this->size ; i < tbm.size + this->size ; i++) tmp[i] = tbm.str[i-this->size] ;
	this->size = this->size + tbm.size ;
	tmp[this->size] = '\0' ;
	delete[] this->str ;
	this->str = tmp ;
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

void Salih::Types::String::operator+=(const char* tbm)
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
}

char* Salih::Types::String::getStr() const
{
	return this->str ;
}

int Salih::Types::String::getSize() const
{
	return this->size ;
}

char& Salih::Types::String::operator[](const int index)
{
	char* cur = this->str ;
	for(int i = 0 ; i < index ; i++)
	{
		cur = ++cur ;
	}
	return *cur ;
}
			
Salih::Types::String Salih::Types::String::capitalise() const
{
	Salih::Types::String tmp(*this) ;
	
	if(tmp[0] >= 65 && tmp[0] < 97)
	{
		tmp[0] = tmp[0] + 32 ;
	}
	
	for(int i = 1 ; i < tmp.size ; i++)
	{
		if(tmp[i] >= 97 && tmp[i] < 123)
		{
			tmp[i] = tmp[i] - 32 ;
		}
	}
	return tmp ;
}
			
Salih::Types::String Salih::Types::String::upper() const
{
	Salih::Types::String tmp(*this) ;
		
	for(int i = 1 ; i < tmp.size ; i++)
	{
		if(tmp[0] >= 65 && tmp[0] < 97)
		{
			tmp[0] = tmp[0] + 32 ;
		}
	}
	
	return tmp ;
}
			
Salih::Types::String Salih::Types::String::lower() const
{
	Salih::Types::String tmp(*this) ;
		
	for(int i = 1 ; i < tmp.size ; i++)
	{
		if(tmp[i] >= 97 && tmp[i] < 123)
		{
			tmp[0] = tmp[0] - 32 ;
		}
	}
	
	return tmp ;
}

// helpful overloads

std::ostream& operator<<(std::ostream& os, const Salih::Types::String& str)
{
	os << str.getStr() ;
	return os ;
}

#endif
