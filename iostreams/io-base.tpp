#ifndef IO_BASE_TPP
#define IO_BASE_TPP
#pragma once

#include "../memory/unique-pointer.hpp"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/** @brief Implementations of base class for streaming classes / functionalities. FOR INTERNAL USAGE ONLY.
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

salih::iostreams::IOBase::IOBase() : buffer(new char[1024]), writePoint(buffer.get()), maxCapacity(1024), fileDescriptor(-1) {} ;
		
salih::iostreams::IOBase::IOBase(int fd) : buffer(new char[1024]), writePoint(buffer.get()), maxCapacity(1024), fileDescriptor(fd) {} ;
		
inline unsigned long salih::iostreams::IOBase::getMaxCapacity()
{
	return maxCapacity ;
}

inline char* salih::iostreams::IOBase::getBuffer()
{
	return this->buffer.get() ;
}
		
void salih::iostreams::IOBase::resizeBuffer(size_t x)
{
	this->buffer = new char[x] ;
	this->maxCapacity = x ;
	this->writePoint = this->buffer.get() ;
}

void salih::iostreams::IOBase::flush()
{
	if(this->fileDescriptor != -1) ::write(this->fileDescriptor, this->buffer.get(), this->writePoint - this->buffer.get()) ;
	this->writePoint = this->buffer.get() ;
}

void salih::iostreams::IOBase::close()
{
	if(this->fileDescriptor != -1) ::close(this->fileDescriptor) ;
}

salih::iostreams::IOBase::~IOBase()
{
	this->flush() ;
	this->close() ;
}

#endif //IO_BASE_HPP
