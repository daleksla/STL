#ifndef SORTS_HPP
#define SORTS_HPP
#pragma once

#include "data-ops.hpp"
#include "flags.hpp"
#include "../containers/array.hpp"
#include "../types/macros.hpp"

/** @brief Sorting algorihtms file
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

namespace salih { 
namespace algorithms {

	/** This is the bubble-sort sort algorithm. It works by repeatedly swapping the adjacent elements if they are in wrong order
	 * @param copy of list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename T>
	CONSTEXPRCXX14 T bubbleSort(T, bool(*const order)(typename T::innerType, typename T::innerType) = salih::algorithms::ASCEND) ;

	template<typename T>
	CONSTEXPRCXX14 T bubbleSort(...) = delete ;

	/** This is the merging subroutine - it works by taking two lists and adding the smallest / the largest value from each, such that the resulting list is a combined list in order
	This subroutine is an overload specifically for two given Array class' whereby they are of the same size, which cannot use the generic list version due to the need of compile-time setup / preallocation, which other containers have no need or capability of
	 * @param const reference to list (one of the lists)
	 * @param const reference to list (another list)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename U, std::size_t SIZE>
	CONSTEXPRCXX14 salih::containers::Array<U, SIZE+SIZE> merge(const salih::containers::Array<U, SIZE>&, const salih::containers::Array<U, SIZE>&, bool(*const order)(typename U::innerType, typename U::innerType) = salih::algorithms::ASCEND) ;
	
	/** This is the merging subroutine - it works by taking two lists and adding the smallest / the largest value from each, such that the resulting list is a combined list in order
	This subroutine is an overload specifically for two given Array class' whereby they are of a different size, which cannot use the generic list version due to the need of compile-time setup / preallocation, which other containers have no need or capability of
	 * @param const reference to list (one of the lists)
	 * @param const reference to list (another list)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename U, std::size_t SIZE, std::size_t DIFF>
	CONSTEXPRCXX14 salih::containers::Array<U, SIZE+DIFF> merge(const salih::containers::Array<U, SIZE>&, const salih::containers::Array<U, DIFF>&, bool(*const order)(typename U::innerType, typename U::innerType) = salih::algorithms::ASCEND) ;
	
	/** This is the merging subroutine - it works by taking two lists and adding the smallest / the largest value from each, such that the resulting list is a combined list in order
	 * @param const reference to list (one of the lists)
	 * @param const reference to list (another list)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename T>
	CONSTEXPRCXX14 T merge(const T&, const T&, bool(*const order)(typename T::innerType, typename T::innerType) = salih::algorithms::ASCEND) ;

	template<typename T>
	CONSTEXPRCXX14 T merge(...) = delete ;

	/** This is the merge sort algorithm. It works splitting a list into minimal sublists and combining two, in order, into a bigger list. It keeps merging the lists together, then the merged lists together, until a fully sorted list is formed
	 * @param const refernece to list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename T>
	CONSTEXPRCXX14 T mergeSort(const T&, bool(*const order)(typename T::innerType, typename T::innerType) = salih::algorithms::ASCEND) ;

	/** This is the merge sort algorithm. It works splitting a list into minimal sublists and combining two, in order, into a bigger list. It keeps merging the lists together, then the merged lists together, until a fully sorted list is formed
	This algorithm is an overload specifically for a given Array class', which cannot use the generic list version due to the need of compile-time setup / preallocation, which other containers have no need or capability of
	 * @param const refernece to list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename U, std::size_t SIZE>
	CONSTEXPRCXX14 salih::containers::Array<U, SIZE> mergeSort(const salih::containers::Array<U, SIZE>&, bool(*const order)(typename U::innerType, typename U::innerType) = salih::algorithms::ASCEND) ;
	
	template<typename T>
	CONSTEXPRCXX14 T mergeSort(...) = delete ;
	
	/** This is the quick sort algorithm. It creates three empty arrays to hold elements less than the pivot value, the same as the pivot value and elements greater than the pivot value, and then recursively sort the sub arrays and adds them together
	 * @param copy of list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename T>
	CONSTEXPRCXX14 T quickSort(const T&, bool(*const order)(typename T::innerType, typename T::innerType) = salih::algorithms::ASCEND) ;

	template<typename T>
	CONSTEXPRCXX14 T quickSort(...) = delete ;

	/** This is the double-ended selection sort algorithm. It works by sorting a list of values by finding the smallest value from unsorted section and putting it at the end of the first sorted section & has an additional sorted subsection containing the largest values
	 * @param copy of list (to be sorted)
	 * @param const function pointer, will facilitate ordering of list. Set as either salih::algorithms::ASCEND (1,...,n) or salih::algorithms::DESCEND (n,...,1)
	 * @return list (sorted version) **/	
	template<typename T>
	CONSTEXPRCXX14 T selectionSort(T, bool(*const order)(typename T::innerType, typename T::innerType) = salih::algorithms::ASCEND) ;

	template<typename T>
	CONSTEXPRCXX14 T selectionSort(...) = delete ;

} 
}

#include "sorts.tpp"

#endif
