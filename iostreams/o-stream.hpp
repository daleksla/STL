#ifndef O_STREAM_HPP
#define O_STREAM_HPP
#pragma once

#include "io-base.hpp"
#include "../types/traits.hpp"
#include <type_traits>

/** @brief O(ut) Stream class / functionalities, which outputs to external files / sources
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

namespace salih {
namespace iostreams {

	class OStream : public IOBase {
		public:
			OStream() ;
		
			OStream(const char*) ;
			
			template<typename T, typename = typename std::enable_if<salih::types::isPrimitive<T>::value, T>::type>
			OStream& operator<<(const T) ;
			
			OStream& operator<<(const char*) ;	

	} ;

}
}

#include "o-stream.tpp"

#endif //O_STREAM_HPP
