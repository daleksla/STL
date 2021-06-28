#ifndef I_STREAM_HPP
#define I_STREAM_HPP
#pragma once

#include "io-base.hpp"
#include "../types/traits.hpp"
#include <type_traits>

/** @brief I(n) Stream class / functionalities, which takes input from external files
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace iostreams {

	class IStream : public IOBase {
		private:
			char* readPoint ; 
			
		public:
			IStream() ;
		
			IStream(const char*) ;
			
			IStream& operator>>(char&) ;
			
			template<typename T, typename = typename std::enable_if<salih::types::isPrimitive<T>::value, T>::type>
			IStream& operator>>(T&) ;

	} ;

}
}

#include "i-stream.tpp"

#endif //I_STREAM_HPP
