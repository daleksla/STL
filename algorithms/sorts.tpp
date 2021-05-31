#ifndef SORTS_TPP
#define SORTS_TPP
#pragma once

#include "data-ops.hpp"

template<typename T>
T salih::algorithms::bubbleSort(T list, bool(*const order)(int, int))
{
	std::size_t listLength = list.getSize() ;
	if(listLength <= 1) return list ;
	
	for(std::size_t main = 0 ; main < (listLength - 1) ; main++)
	{
		for(std::size_t inner = 0 ; inner < (listLength - main - 1) ; inner++)
		{
			if((*order)(list[inner+1], list[inner]))
			{
				salih::algorithms::swap(list[inner], list[inner+1]) ;
			}
		}
	}
	return list ;
}

template<typename U, std::size_t SIZE>
salih::containers::Array<U, SIZE+SIZE> salih::algorithms::merge(const salih::containers::Array<U, SIZE>& x, const salih::containers::Array<U, SIZE>& y, bool(*const order)(int, int))
{	
	salih::containers::Array<U, SIZE+SIZE> out ;
	std::size_t i = 0, j = 0, k = 0 ;
	
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
	
template<typename U, std::size_t SIZE, std::size_t DIFF>
salih::containers::Array<U, SIZE+DIFF> salih::algorithms::merge(const salih::containers::Array<U, SIZE>& x, const salih::containers::Array<U, DIFF>& y, bool(*const order)(int, int))
{	
	salih::containers::Array<U, SIZE+DIFF> out ;
	std::size_t i = 0, j = 0, k = 0 ;
	
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
T salih::algorithms::merge(const T& x, const T& y, bool(*const order)(int, int))
{	
	T out ;
	std::size_t i = 0, j = 0, k = 0 ;
	
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
T salih::algorithms::mergeSort(const T& data, bool(*const order)(int, int))
{			
	std::size_t listLength = data.getSize() ;
	
	if(listLength <= 1) return data ;
	
	T a, b ;
	
	for(std::size_t i = 0 ; i < std::size_t(listLength / 2) ; i++) a.append(data[i]) ;
	for(std::size_t i = std::size_t(listLength / 2) ; i < listLength ; i++) b.append(data[i]) ;
		
	a = salih::algorithms::mergeSort(a, order) ;
	b = salih::algorithms::mergeSort(b, order) ;
	
	return salih::algorithms::merge(a, b, order) ;
}
	
template<typename U, std::size_t SIZE>
salih::containers::Array<U, SIZE> salih::algorithms::mergeSort(const salih::containers::Array<U, SIZE>& data, bool(*const order)(int, int))
{				
	if(SIZE <= 1) return data ;
	
	salih::containers::Array<U,SIZE/2> a, b ;
	
	for(std::size_t i = 0 ; i < std::size_t(SIZE / 2) ; i++) a[i] = data[i] ;
	for(std::size_t i = std::size_t(SIZE / 2) ; i < SIZE ; i++) b[i-std::size_t(SIZE/2)] = data[i] ;
		
	a = salih::algorithms::mergeSort(a, order) ;
	b = salih::algorithms::mergeSort(b, order) ;
	
	return salih::algorithms::merge(a, b, order) ;
}

template<typename T>
T salih::algorithms::quickSort(const T& list, bool(*const order)(int, int))
{			
	if(list.getSize() <= 1) return list ;
	
	T left, right, equal ;		
	auto pivot = list[0] ;
	
	for(std::size_t i = 0 ; i < list.getSize() ; i++)
	{
		auto iterR = list[i] ;
		if((*order)(iterR, pivot)) left.append(iterR) ;
		else if(iterR == pivot) equal.append(iterR) ;
		else right.append(iterR) ;
	}
	
	return salih::algorithms::quickSort(left, order) + equal + salih::algorithms::quickSort(right, order) ;
}

template<typename T>
T salih::algorithms::selectionSort(T list, bool(*const order)(int, int))
{
	if(list.getSize() <= 1) return list ;
	std::size_t limit = list.getSize() - 1 ; //initialise 2nd section boundary value (for larger values) 
	for(std::size_t i = 0 ; i < limit ; i++) // only iterate until the 2nd section boundary (since values past this are sorted)  
	{               
		int min = i ; //set minimum index as current index 
		int max = i ; //set maximum index as current index 
		for(std::size_t j = i ; j < limit + 1 ; j++)
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
