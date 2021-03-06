#ifndef SORTS_TPP
#define SORTS_TPP
#pragma once

#include "data-ops.hpp"

/** @brief Implementations of sorting algorihtms. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

template<typename T>
CONSTEXPRCXX14 T salih::algorithms::bubbleSort(T list, bool(*const order)(typename T::innerType, typename T::innerType))
{
	unsigned long listLength = list.getSize() ;
	if(listLength <= 1) return list ;
	
	for(unsigned long main = 0 ; main < (listLength - 1) ; main++)
	{
		for(unsigned long inner = 0 ; inner < (listLength - main - 1) ; inner++)
		{
			if((*order)(list[inner+1], list[inner]))
			{
				salih::algorithms::swap(list[inner], list[inner+1]) ;
			}
		}
	}
	return list ;
}

template<typename U, unsigned long SIZE>
CONSTEXPRCXX14 salih::containers::Array<U, SIZE+SIZE> salih::algorithms::merge(const salih::containers::Array<U, SIZE>& x, const salih::containers::Array<U, SIZE>& y, bool(*const order)(typename U::innerType, typename U::innerType))
{	
	salih::containers::Array<U, SIZE+SIZE> out ;
	unsigned long i = 0, j = 0, k = 0 ;
	
	while(i < x.getSize() && j < y.getSize())
	{
		if((*order)(x[i],y[j]))
		{
			out[k] = (x[i]) ;
			i += 1 ;
		}
		else {
			out[k] = (y[j]) ;
			j += 1 ;
		}
		k += 1 ;
	}
	while(i < x.getSize())
	{
		out[k] = (x[i]) ;
		i += 1 ;
		k += 1 ;
	}
	while(j < y.getSize())
	{
		out[k] = (y[j]) ;
		j += 1 ;
		k += 1 ;
	}
	
	return out ;
}
	
template<typename U, unsigned long SIZE, unsigned long DIFF>
CONSTEXPRCXX14 salih::containers::Array<U, SIZE+DIFF> salih::algorithms::merge(const salih::containers::Array<U, SIZE>& x, const salih::containers::Array<U, DIFF>& y, bool(*const order)(typename U::innerType, typename U::innerType))
{	
	salih::containers::Array<U, SIZE+DIFF> out ;
	unsigned long i = 0, j = 0, k = 0 ;
	
	while(i < x.getSize() && j < y.getSize())
	{
		if((*order)(x[i],y[j]))
		{
			out[k] = (x[i]) ;
			i += 1 ;
		}
		else {
			out[k] = (y[j]) ;
			j += 1 ;
		}
		k += 1 ;
	}
	while(i < x.getSize())
	{
		out[k] = (x[i]) ;
		i += 1 ;
		k += 1 ;
	}
	while(j < y.getSize())
	{
		out[k] = (y[j]) ;
		j += 1 ;
		k += 1 ;
	}
	
	return out ;
}

template<typename T>
CONSTEXPRCXX14 T salih::algorithms::merge(const T& x, const T& y, bool(*const order)(typename T::innerType, typename T::innerType))
{	
	T out ;
	unsigned long i = 0, j = 0, k = 0 ;
	
	while(i < x.getSize() && j < y.getSize())
	{
		if((*order)(x[i],y[j]))
		{
			out.append(x[i]) ;
			i += 1 ;
		}
		else {
			out.append(y[j]) ;
			j += 1 ;
		}
		k += 1 ;
	}
	while(i < x.getSize())
	{
		out.append(x[i]) ;
		i += 1 ;
		k += 1 ;
	}
	while(j < y.getSize())
	{
		out.append(y[j]) ;
		j += 1 ;
		k += 1 ;
	}
	
	return out ;
}

template<typename T>
CONSTEXPRCXX14 T salih::algorithms::mergeSort(const T& data, bool(*const order)(typename T::innerType, typename T::innerType))
{			
	unsigned long listLength = data.getSize() ;
	
	if(listLength <= 1) return data ;
	
	T a, b ;
	
	for(unsigned long i = 0 ; i < static_cast<unsigned long>(listLength / 2) ; i++) 
	{
		a.append(data[i]) ;
	}
	for(unsigned long i = static_cast<unsigned long>(listLength / 2) ; i < listLength ; i++) 
	{
		b.append(data[i]) ;
	}
		
	a = salih::algorithms::mergeSort(a, order) ;
	b = salih::algorithms::mergeSort(b, order) ;
	
	return salih::algorithms::merge(a, b, order) ;
}
	
template<typename U, unsigned long SIZE>
CONSTEXPRCXX14 salih::containers::Array<U, SIZE> salih::algorithms::mergeSort(const salih::containers::Array<U, SIZE>& data, bool(*const order)(typename U::innerType, typename U::innerType))
{				
	if(SIZE <= 1) return data ;
	
	salih::containers::Array<U,SIZE/2> a, b ;
	
	for(unsigned long i = 0 ; i < static_cast<unsigned long>(SIZE / 2) ; i++) 
	{
		a[i] = data[i] ;
	}
	for(unsigned long i = static_cast<unsigned long>(SIZE / 2) ; i < SIZE ; i++)
	{
		b[i-static_cast<unsigned long>(SIZE/2)] = data[i] ;
	}
		
	a = salih::algorithms::mergeSort(a, order) ;
	b = salih::algorithms::mergeSort(b, order) ;
	
	return salih::algorithms::merge(a, b, order) ;
}

template<typename T>
CONSTEXPRCXX14 T salih::algorithms::quickSort(const T& list, bool(*const order)(typename T::innerType, typename T::innerType))
{			
	if(list.getSize() <= 1) return list ;
	
	T left, right, equal ;		
	auto pivot = list[0] ;
	
	for(unsigned long i = 0 ; i < list.getSize() ; i++)
	{
		auto iterR = list[i] ;
		if((*order)(iterR, pivot)) left.append(iterR) ;
		else if(iterR == pivot) equal.append(iterR) ;
		else right.append(iterR) ;
	}
	
	return salih::algorithms::quickSort(left, order) + equal + salih::algorithms::quickSort(right, order) ;
}

template<typename T>
CONSTEXPRCXX14 T salih::algorithms::selectionSort(T list, bool(*const order)(typename T::innerType, typename T::innerType))
{
	if(list.getSize() <= 1) return list ;
	unsigned long limit = list.getSize() - 1 ; //initialise 2nd section boundary value (for larger values) 
	for(unsigned long i = 0 ; i < limit ; i++) // only iterate until the 2nd section boundary (since values past this are sorted)  
	{               
		int min = i ; //set minimum index as current index 
		int max = i ; //set maximum index as current index 
		for(unsigned long j = i ; j < limit + 1 ; j++)
		{           
			if((*order)(list[j], list[min])) //set the index for minimum element in list
			{                  
				min = j ;
			}
			if((*order)(list[max], list[j])) //set the index for minimum element in list
			{
				max = j ;
			}
		}
		salih::algorithms::swap(list[i], list[min]) ;
		if((*order)(list[max],list[min])) //if the just-found smallest value is larger then the just-found 'largest' value
		{
			salih::algorithms::swap(list[limit], list[min]) ; //then put the larger value (at index min) in larger sorted section
		}
		else {
			salih::algorithms::swap(list[limit], list[max]) ; //then put the larger value (at index max) in larger sorted section
		}         
		limit -= 1 ; 
		//since we get the largest value and place it at the end of the sorted list, we shrink the limit
		//this way, on the next-iteration we get the second-largest, element and place it in the slot before, etc.
	}
	return list ;
}

#endif
