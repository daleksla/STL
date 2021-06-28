#ifndef MEMORY_UTILITIES_HPP
#define MEMORY_UTILITIES_HPP

/** @brief Functionality relating to memory management
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih {
namespace memory {

	/** isHeap function, detects whether function is dynamically allocated 
	@param void pointer
	@return Boolean (True if pointer is on free-store, else false) **/
	bool isHeap(void*) ;
	
	/** isAligned function, detects whether function is aligned on a specific boundary
	@param void pointer
	@param unsigned integer, which should be a whole divisible of the address of the given pointer
	@return Boolean (True if pointer is on a given boundary) **/
	bool isAligned(void*, unsigned int) ;

}
}

bool salih::memory::isHeap(void* data)
{
	int x ;
        asm("movq %1, %%rax;" //move a value into register rax
            "cmpq %%rsp, %%rax;" //compare value in register rsp to value in rax
            "jbe Heap%=;" //if the above comparison is met, jump to the heap section 
            "movl $1,%0;" //else (stack) give it true
            "jmp Done%=;" //jump to done section
            "Heap%=:" //heap section 
            "movl $0,%0;" //if it's on the heap, give it false 
            "Done%=:" //done section
            : "=r" (x) //load result into x
            : "r" (data) //data to be tested
            ) ;
       if(x) return false ;
       else return true ;
}

bool salih::memory::isAligned(void* data, unsigned int boundary)
{
	if(data % boundary) return false ;
	return true ;
}

#endif
