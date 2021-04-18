#ifndef STRING_HPP
#define STRING_HPP
#pragma once

#include <iostream>

namespace Salih::Types {

	class String ;
	
}

namespace std _GLIBCXX_VISIBILITY(default)
{
	std::ostream& operator<<(std::ostream&, const Salih::Types::String&) ;
	
	std::istream& operator>>(std::istream&, Salih::Types::String&) ;
}

namespace Salih::Types {

	class String {
		private:
			char* str ;
			
			int size ;
					
			String(char*, const int) ;	
		public:
		
			String() ;
			
			String(const char*) ;
			
			String(const String&) ;
			
			String(String&&) ;
					
			~String() ;
			
			String& operator=(const char*) ;
			
			String& operator=(const String&) ;
			
			String& operator=(String&&) ;
			
			String operator+(char) const ; //to append char
			
			String& operator+=(char) ; //to append char
			
			String operator+(const String&) const ; //to append another string
			
			String& operator+=(const String&) ; //to append another string
			
			String operator+(const char*) const ;
			
			String& operator+=(const char*) ;
			
			bool operator==(const char*) const ;
			
			bool operator!=(const char*) const ;
			
			bool operator==(const String&) const ;
			
			bool operator!=(const String&) const ;
			
			const char* get() const ;
			
			int getSize() const ;
			
			char& operator[](const int) ;
			
			const char& operator[](const int) const ;
			
			String capitalise() const ;
			
			String upper() const ;
			
			String lower() const ;
			
			bool isAlphaNum() const ;
			
			bool isAlpha() const ;
			
			bool isNum() const ;
			
			bool isUpper() const ;
			
			bool isLower() const ;
			
			bool isCapitalised() const ;
			
			friend ::std::istream& ::std::operator>>(::std::istream&, String&) ;
			
			friend ::std::ostream& ::std::operator<<(::std::ostream&, const String&) ;
			
	} ;
}

Salih::Types::String::String(char* temp, const int SIZE)
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

std::ostream& std::operator<<(std::ostream& os, const Salih::Types::String& str)
{
	os << str.str ;
	return os ;
}

std::istream& std::operator>>(std::istream& in, Salih::Types::String& str)
{
	std::size_t size = 1024 ;
	char* temp = new char[size+1] ;
	in >> temp ;
	temp[size] = '\0' ;
	delete[] str.str ;
	str.str = nullptr ;
	str.str = temp ;
	str.size = size ;
	
	return in ;
}

#endif
