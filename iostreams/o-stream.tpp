#ifndef O_STREAM_TPP
#define O_STREAM_TPP
#pragma once

/** @brief Implementations of O(ut) Stream class / functionalitiess. FOR INTERNAL USAGE ONLY.
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

salih::iostreams::OStream::OStream() : salih::iostreams::IOBase() {} ;
			
salih::iostreams::OStream::OStream(const char* fileName) : salih::iostreams::IOBase(::open(fileName, O_WRONLY)) {} ;

template<typename T, typename>
salih::iostreams::OStream& salih::iostreams::OStream::operator<<(const T data)
{
	T* ptr = reinterpret_cast<T*>(this->writePoint) ;
	*ptr = data ;
	this->writePoint = reinterpret_cast<char*>(ptr) + sizeof(T) ; 
	return *this ;
}

salih::iostreams::OStream& salih::iostreams::OStream::operator<<(const char* data)
{
	for(size_t sz = 0 ; data[sz] != '\0' ; ++sz) 
	{
		*this->writePoint = data[sz] ;
		++this->writePoint ; 
	}
	return *this ;
}
		
#endif
