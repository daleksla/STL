#ifndef STRING_TPP
#define STRING_TPP
#pragma once

inline _GLIBCXX20_CONSTEXPR salih::containers::String::String(char* temp, const std::size_t SIZE) : str(temp), size(SIZE) {} ;

_GLIBCXX20_CONSTEXPR salih::containers::String::String() : size(0)
{
	this->str = new char[1] ;
	this->str[0] = '\0' ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String::String(const char* input)
{
	for(this->size = 0 ; input[this->size] != '\0'; this->size++) ;
	this->str = new char[size + 1] ;
	for(std::size_t i = 0 ; i < size ; i++) str[i] = input[i] ;
	str[this->size] = '\0' ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String::String(const salih::containers::String& tbc) : str(new char[tbc.size+1]), size(tbc.size)
{
	for(std::size_t i = 0 ; i < this->size ; i++) this->str[i] = tbc.str[i] ;
	this->str[this->size] = '\0' ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String& salih::containers::String::operator=(const salih::containers::String& tbc)
{
	delete[] this->str ;
	this->size = tbc.size ;
	this->str = new char[this->size+1] ;
	for(std::size_t i = 0 ; i < this->size ; i++) this->str[i] = tbc.str[i] ;
	this->str[this->size] = '\0' ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String::String(salih::containers::String&& tbo) : str(tbo.str), size(tbo.size)
{
	tbo.size = 0 ;
	tbo.str = nullptr ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String& salih::containers::String::operator=(salih::containers::String&& tbo)
{
	delete[] this->str ;
	this->size = tbo.size ;
	this->str = tbo.str ;
	tbo.size = 0 ;
	tbo.str = nullptr ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String::~String()
{
	if(str == nullptr) return;
	delete[] str ; //else
	str = nullptr ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String& salih::containers::String::operator=(const char* tbc)
{
	delete[] this->str ;
	for(this->size = 0 ; tbc[this->size] != '\0'; this->size++) ;
	this->str = new char[this->size + 1] ;
	for(std::size_t i = 0 ; i < this->size ; i++) this->str[i] = tbc[i] ;
	this->str[this->size] = '\0' ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::operator+(char c) const
{
	salih::containers::String tmp ;
	delete[] tmp.str ;
	tmp.size = this->size + 1 ;
	tmp.str = new char[tmp.size+1] ;
	for(std::size_t i = 0 ; i < tmp.size - 1 ; i++) tmp.str[i] = this->str[i] ;
	tmp.str[tmp.size-1] = c ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String& salih::containers::String::operator+=(char c) 
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

_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::operator+(const salih::containers::String& tbm) const
{
	salih::containers::String tmp ; delete[] tmp.str ;
	tmp.size = this->size + tbm.size ;
	tmp.str = new char[tmp.size+1] ;
	
	for(std::size_t i = 0 ; i < this->size ; i++) tmp.str[i] = this->str[i] ;
	for(std::size_t i = this->size ; i < tmp.size ; i++) tmp.str[i] = tbm.str[i-this->size] ;
	tmp.str[tmp.size] = '\0' ;
	return tmp ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String& salih::containers::String::operator+=(const salih::containers::String& tbm)
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

_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::operator+(const char* tbm) const
{
	std::size_t tmpSize = 0 ;
	for(tmpSize = 0 ; tbm[tmpSize] != '\0' ; tmpSize++) ;
	tmpSize += this->size ;
	
	char* tmpStr = new char[tmpSize+1] ;
	
	for(std::size_t i = 0 ; i < this->size ; i++) tmpStr[i] = this->str[i] ;
	for(std::size_t i = this->size ; i < tmpSize ; i++) tmpStr[i] = tbm[i-this->size] ;
	tmpStr[tmpSize] = '\0' ;
	return salih::containers::String(tmpStr, tmpSize) ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String& salih::containers::String::operator+=(const char* tbm)
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

_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::operator*(std::size_t x) const
{
	char* tmpStr = new char[(this->size * x) + 1] ;
	for(std::size_t i = 0 ; i < x ; i++)
	{
		for(std::size_t j = 0 ; j < this->size ; j++)
		{
			tmpStr[j+(i*this->size)] = this->str[j] ;
		}
	}
	tmpStr[this->size * x] = '\0' ;
	return salih::containers::String(tmpStr, this->size * x) ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String& salih::containers::String::operator*=(std::size_t x)
{
	char* tmpStr = new char[(this->size * x) + 1] ;
	for(std::size_t i = 0 ; i < x ; i++)
	{
		for(std::size_t j = 0 ; j < this->size ; j++)
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

_GLIBCXX20_CONSTEXPR bool salih::containers::String::operator==(const char* str) const
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
			
_GLIBCXX20_CONSTEXPR bool salih::containers::String::operator!=(const char* str) const
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
			
_GLIBCXX20_CONSTEXPR bool salih::containers::String::operator==(const salih::containers::String& str) const
{
	if(this->size != str.size) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str.str[i]) return false ;
	}
	
	return true ;
}
			
_GLIBCXX20_CONSTEXPR bool salih::containers::String::operator!=(const salih::containers::String& str) const
{
	if(this->size != str.size) return true ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(this->str[i] != str.str[i]) return true ;
	}
	
	return false ;
}

_GLIBCXX20_CONSTEXPR const char* salih::containers::String::get() const
{
	return this->str ;
}

_GLIBCXX20_CONSTEXPR std::size_t salih::containers::String::getSize() const
{
	return this->size ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::operator()(const std::size_t a, const std::size_t b) const 
{
	if(a > b || a < 0 || b > this->size) throw std::out_of_range("Element range requested does not exist") ;
	salih::containers::String tmp ;
	for(std::size_t idx = a ; idx < b ; idx++) tmp[idx-a] += this->str[idx] ;
	return tmp ;
}

_GLIBCXX20_CONSTEXPR char& salih::containers::String::operator[](const std::size_t index)
{
	return this->str[index] ;
}

_GLIBCXX20_CONSTEXPR const char& salih::containers::String::operator[](const std::size_t index) const
{
	return this->str[index] ;
}
			
_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::capitalise() const
{
	salih::containers::String tmp(*this) ;
	
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
			
_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::upper() const
{
	salih::containers::String tmp(*this) ;
		
	for(std::size_t i = 0 ; i < tmp.size ; i++)
	{
		if(tmp[i] >= 97 && tmp[i] <= 122)
		{
			tmp[i] = tmp[i] - 32 ;
		}
	}
	
	return tmp ;
}
			
_GLIBCXX20_CONSTEXPR salih::containers::String salih::containers::String::lower() const
{
	salih::containers::String tmp(*this) ;
		
	for(std::size_t i = 0 ; i < tmp.size ; i++)
	{
		if(tmp[i] >= 65 && tmp[i] <= 90)
		{
			tmp[i] = tmp[i] + 32 ;
		}
	}
	
	return tmp ;
}

_GLIBCXX20_CONSTEXPR bool salih::containers::String::isAlphaNum() const
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
			
_GLIBCXX20_CONSTEXPR bool salih::containers::String::isAlpha() const
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
			
_GLIBCXX20_CONSTEXPR bool salih::containers::String::isNum() const
{
	if(this->size == 0) return false ;
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if( (this->str[i] >= 48 && this->str[i] <= 57) == 0) return false ;	
	}
	return true ;
}

_GLIBCXX20_CONSTEXPR bool salih::containers::String::isUpper() const
{
	if(this->size == 0) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 60 && this->str[i] <= 90)) return false ;
	}
	return true ;
}
			
_GLIBCXX20_CONSTEXPR bool salih::containers::String::isLower() const
{
	if(this->size == 0) return false ;
	
	for(std::size_t i = 0 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 97 && this->str[i] <= 122)) return false ;
	}
	return true ;
}
			
_GLIBCXX20_CONSTEXPR bool salih::containers::String::isCapitalised() const
{
	if(this->size == 0) return false ;
	
	if(!(this->str[0] >= 60 && this->str[0] <= 90)) return false ;
	
	for(std::size_t i = 1 ; i < this->size ; i++)
	{
		if(!(this->str[i] >= 97 && this->str[i] <= 122)) return false ;
	}
	
	return true ;
}

_GLIBCXX20_CONSTEXPR salih::containers::String::Iterator::Iterator() : pointer(nullptr) {} ;

_GLIBCXX20_CONSTEXPR salih::containers::String::Iterator::Iterator(char* input) : pointer(input) {} ;

_GLIBCXX20_CONSTEXPR char& salih::containers::String::Iterator::operator*() const
{
	return *this->pointer ; 
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator salih::containers::String::Iterator::operator+(const std::size_t x) const
{
	return salih::containers::String::Iterator(this->pointer + x) ; 
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator& salih::containers::String::Iterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator& salih::containers::String::Iterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator salih::containers::String::Iterator::operator++(const int)
{
	salih::containers::String::Iterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator salih::containers::String::Iterator::operator-(const std::size_t x) const
{
	return salih::containers::String::Iterator(this->pointer - x) ; 
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator& salih::containers::String::Iterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator& salih::containers::String::Iterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator salih::containers::String::Iterator::operator--(const int)
{
	salih::containers::String::Iterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

_GLIBCXX20_CONSTEXPR bool salih::containers::String::Iterator::operator==(const salih::containers::String::Iterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

_GLIBCXX20_CONSTEXPR bool salih::containers::String::Iterator::operator!=(const salih::containers::String::Iterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

_GLIBCXX20_CONSTEXPR salih::containers::String::ConstIterator::ConstIterator() : pointer(nullptr) {} ;

_GLIBCXX20_CONSTEXPR salih::containers::String::ConstIterator::ConstIterator(char const* input) : pointer(input) {} ;

_GLIBCXX20_CONSTEXPR const char& salih::containers::String::ConstIterator::operator*() const
{
	return *this->pointer ; 
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::ConstIterator::operator+(const std::size_t x) const
{
	return salih::containers::String::ConstIterator(this->pointer + x) ; 
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator& salih::containers::String::ConstIterator::operator+=(const std::size_t x)
{
	this->pointer += x ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator& salih::containers::String::ConstIterator::operator++()
{
	this->pointer += 1 ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::ConstIterator::operator++(const int)
{
	salih::containers::String::ConstIterator tmp(this->pointer) ;
	this->pointer += 1 ;
	return tmp ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::ConstIterator::operator-(const std::size_t x) const
{
	return salih::containers::String::ConstIterator(this->pointer - x) ; 
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator& salih::containers::String::ConstIterator::operator-=(const std::size_t x)
{
	this->pointer -= x ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator& salih::containers::String::ConstIterator::operator--()
{
	this->pointer -= 1 ;
	return *this ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::ConstIterator::operator--(const int)
{
	salih::containers::String::ConstIterator tmp(this->pointer) ;
	this->pointer -= 1 ;
	return tmp ;
}

_GLIBCXX20_CONSTEXPR bool salih::containers::String::ConstIterator::operator==(const salih::containers::String::ConstIterator& other) const
{
	return (this->pointer == other.pointer) ; 
}

_GLIBCXX20_CONSTEXPR bool salih::containers::String::ConstIterator::operator!=(const salih::containers::String::ConstIterator& other) const
{
	return (this->pointer != other.pointer) ; 
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator salih::containers::String::begin()
{
	return salih::containers::String::Iterator(this->str) ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::Iterator salih::containers::String::end()
{
	return salih::containers::String::Iterator(this->str + this->size) ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::begin() const 
{
	return salih::containers::String::ConstIterator(this->str) ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::end() const
{
	return salih::containers::String::ConstIterator (this->str + this->size) ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::cbegin() const 
{
	return salih::containers::String::ConstIterator(this->str) ;
}

_GLIBCXX20_CONSTEXPR typename salih::containers::String::ConstIterator salih::containers::String::cend() const
{
	return salih::containers::String::ConstIterator(this->str + this->size) ;
}

#endif
