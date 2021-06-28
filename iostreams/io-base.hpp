#ifndef IO_BASE_HPP
#define IO_BASE_HPP
#pragma once

#include "../memory/unique-pointer.hpp"

/** @brief Base class for streaming classes / functionalities
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace iostreams {

	class IOBase {
		protected:
			salih::memory::UniquePointer<char[]> buffer ;
		
			unsigned long maxCapacity ;
		
			int fileDescriptor ;
		
		protected:	
			char* writePoint ; // keep track of position in buffer
		
			IOBase() ;
		
			IOBase(int) ;
			
			inline char* getBuffer() ;
			
			inline void setMaxCapacity(size_t) ;
			
		public:		
			inline size_t getMaxCapacity() ;
		
			inline void resizeBuffer(size_t) ;
			
			void flush() ;
			
			void close() ;
			
			virtual ~IOBase() = 0 ;
			
	} ;

}
}

#include "io-base.tpp"

#endif //IO_BASE_HPP
