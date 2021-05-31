#ifndef POINTER_UTILITIES_HPP
#define POINTER_UTILITIES_HPP

/** @brief File containing base class declarations for all smart pointers
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace Salih::Types::SmartPointers {

	/** isHeap function, detects whether function is dynamically allocated 
	@param void pointer
	@return Boolean (True if pointer is on free-store, else false) **/
	bool isHeap(void*) ;

}

bool Salih::Types::SmartPointers::isHeap(void* data)
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
}

#endif
