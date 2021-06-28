#ifndef I_STREAM_TPP
#define I_STREAM_TPP
#pragma once

/** @brief Implementations of I(n) Stream class / functionalities. FOR INTERNAL USAGE ONLY.
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

salih::iostreams::IStream::IStream() : salih::iostreams::IOBase(), readPoint(buffer.get()) {} ;
			
salih::iostreams::IStream::IStream(const char* fileName) : salih::iostreams::IOBase(::open(fileName, O_RDONLY)), readPoint(buffer.get()) {} ;

salih::iostreams::IStream& salih::iostreams::IStream::operator>>(char& data)
{
	if(this->readPoint == this->writePoint) // if we've read all buffer data
	{ // try getting more
		this->readPoint = this->getBuffer() ;
		this->writePoint = this->getBuffer() ;
		this->writePoint += ::read(this->fileDescriptor, this->writePoint, this->getMaxCapacity()) ;
	}
	data = *readPoint ; // get data at current read point
	this->readPoint += 1 ; //sizeof(char), move read pointer ahead
	return *this ;
}

template<typename T, typename>
salih::iostreams::IStream& salih::iostreams::IStream::operator>>(T& data)
{
	//implemenet
	return *this ;
}
		
#endif
