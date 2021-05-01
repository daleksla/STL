#ifndef POINTERS_HPP
#define POINTERS_HPP
#pragma once

#include <iostream>
#include <stdexcept>

/** @brief Pointer-related files, including smart pointers and related functions
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace Salih::Types {

	template<typename T>
	class Pointer ;
	
	template<typename T>
	class SharedPointer ;
	
	template<typename T>
	class UniquePointer ;
	
	template<>
	class Pointer<void> ;
	
	template<>
	class SharedPointer<void> ;
	
	template<>
	class UniquePointer<void> ;
	
	/** isHeap function - determines if pointer is on heap
	@param void pointer (void*)
	@return boolean (indicating if pointer given is a heap pointer (outside stack range therefore allocated) or not) **/
	bool isHeap(void*) ;
}

#include "./pointers/_regular.hpp"

#include "./pointers/_void.hpp"

//other functions / overloads	
bool Salih::Types::isHeap(void* data)
{
	int x ;
        asm("movq %1, %%rax;"
            "cmpq %%rsp, %%rax;"
            "jbe Heap%=;"
            "movl $1,%0;"
            "jmp Done%=;"
            "Heap%=:"
            "movl $0,%0;"
            "Done%=:"
            : "=r" (x)
            : "r" (data)
            ) ;
       if(x) return false ;
       else return true ;
	//const char* errorMsg = "Cannot allocate pointer to stack value to smart pointer" ;
	//if(x) throw std::runtime_error(errorMsg) ;
}

//template<typename T>
//std::ostream& Salih::operator<<(std::ostream& os, const ::Salih::Types::Pointer<T>& ptr)
//{
//	os << ptr.pointer ;
//	return os ;
//}

#endif
