/*  
	Jeffrey Carson
    CS302
    Project 2
	10/6/20
	InseritonSort Implementation
*/
#include <iostream>
#include "InsertionSort.h"

void InsertionSort::sort(int arr[], int size){
	m_numComps = 0;
	m_numSwaps = 0;
	int temp, j;
	for(int i = 0; i < size; ++i){
		//std::cout << i << std::endl;
		temp = arr[i];
		
		j = i -1;
		while(j >= 0 && temp < arr[j]){
				arr[j+1] = arr[j];
				++m_numSwaps;
				++m_numComps;
				
				--j;
		}
		arr[j+1] = temp;
		++m_numComps;
	}
	
}
const std::size_t InsertionSort::getSwaps(){
	return m_numSwaps;
}
const std::size_t InsertionSort::getComps(){
	return m_numComps;
}
