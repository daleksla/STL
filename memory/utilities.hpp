#ifndef MEMORY_UTILITIES_HPP
#define MEMORY_UTILITIES_HPP

/** @brief File containing base class declarations for all smart pointers
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih {
namespace memory {

	/** isHeap function, detects whether function is dynamically allocated 
	@param void pointer
	@return Boolean (True if pointer is on free-store, else false) **/
	_GLIBCXX20_CONSTEXPR bool isHeap(const void*) ;

}
}

_GLIBCXX20_CONSTEXPR bool salih::memory::isHeap(const void* data)
{
	void* x = nullptr ;
	asm("movq %%rsp, %%rax;" //compare value in register rsp to value in rax
		: "=r" (x) //load result into x
		: "r" (data) //data to be tested
	) ;
	return (x > data) ;
}

#endif
