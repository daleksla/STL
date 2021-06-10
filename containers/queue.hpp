#ifndef QUEUE_HPP
#define QUEUE_HPP
#pragma once

#include "d-node.hpp"
#include "../types/macros.hpp"
#include <initializer_list>

/** @brief Queue-class implementation file, representing the FIFO abstract data type
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date April 2021
**/

namespace salih {
namespace containers {

	template<class T>
	class Queue {
		/** This class is the FIFo (Queue) implementation **/
		private:
			salih::containers::DNode<T>* head ;
			
			salih::containers::DNode<T>* tail ;
			
			std::size_t size ;
		public:
			using inner = T ;
		
			/** Empty constructor, intialises empty queue 
			@return <initialised-object> **/
			CONSTEXPRCXX20 Queue() ;

			/** Regular constructor, intialises multiple values
			@param initialisation list (of values for queue)
			@return <initialised-object> **/			
			CONSTEXPRCXX20 Queue(const std::initializer_list<T>&) ;
			
			/** Regular assignment operator, re-assigns values to queue (1st element provided becomes head, etc.)
			@param initialisation list (of values for queue)
			@return reference to current object **/
			CONSTEXPRCXX20 Queue& operator=(const std::initializer_list<T>&) ;
		
			/** Copy constructor, creates copy of a given queue
			@param a (l-value) queue object
			@return <initialised-object> **/				
			CONSTEXPRCXX20 Queue(const Queue<T>&) ;
			
			/** Copy assignment operator, creates copy of a given queue
			@param a (l-value) queue object
			@return reference to current object **/	
			CONSTEXPRCXX20 Queue& operator=(const Queue<T>&) ;
			
			/** Move constructor, takes ownership of an otherwise temporary queue object
			@param an r-value queue object
			@return <initialised-object> **/
			CONSTEXPRCXX20 Queue(Queue<T>&&) ;
			
			/** Move assignment operator, takes ownership of an otherwise temporary queue object
			@param an (r-value) queue object
			@return reference to current object **/
			CONSTEXPRCXX20 Queue& operator=(Queue<T>&&) ;
			
			/** Comparison operator, determines calling queue object content matches with a given queue object
			@param queue object
			@return a boolean representing whether equality is met **/ 	
			CONSTEXPRCXX20 bool operator==(const Queue<T>&) const ;

			/** Inequality operator, determines calling queue object content does not match with a given queue object
			@param queue object
			@return a boolean representing whether equality is not met **/ 				
			CONSTEXPRCXX20 bool operator!=(const Queue<T>&) const ;

			/** Comparison operator, determines calling queue object content matches with a given queue object
			@param queue object (which contains different type values)
			@return a boolean representing whether equality is met **/ 			
			template<typename OTHER>
			CONSTEXPRCXX20 bool operator==(const Queue<OTHER>&) const ;

			/** Inequality operator, determines calling queue object content does not match with a given queue object
			@param queue object (which contains different type values)
			@return a boolean representing whether equality is not met **/ 				
			template<typename OTHER>
			CONSTEXPRCXX20 bool operator!=(const Queue<OTHER>&) const ;
			
			/** Destructor, frees memory and deletes queue **/					
			CONSTEXPRCXX20 ~Queue() ;
			
			/** pop method, removes oldest / earliest added value from the queue
			@return value (of removed data object) **/					
			CONSTEXPRCXX20 T pop() ;

			/** peek method, shows oldest / earliest added value to the queue
			@return constant reference to value (of earliest added / oldest data object) **/				
			CONSTEXPRCXX20 const T& peek() const ;

			/** push method, adds a value to the end of the queue type
			@param value (to add) **/							
			CONSTEXPRCXX20 void push(T) ;

			/** push method, adds a value to the end of the queue type
			@param initialisation list (of values to add) **/			
			CONSTEXPRCXX20 void push(const std::initializer_list<T>&) ;
			
			/** getSize method, returns size of a structure
			@return returns size (of data structure) **/	
			CONSTEXPRCXX20 std::size_t getSize() ;
			
			template<typename OTHER>
    			friend class Queue ;
    			
	} ;
}
}

#include "queue.tpp"

#endif
