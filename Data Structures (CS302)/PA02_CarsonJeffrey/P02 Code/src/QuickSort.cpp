/*  
	Jeffrey Carson
    CS302
    Project 2
	10/6/20
	QuickSort Implementation
*/
#include <iostream>
#include "QuickSort.h"

void QuickSort::sort(int arr[], int size){
	m_numComps = 0;
	m_numSwaps = 0;
	quickSort(arr, 0, size);
}
void QuickSort::quickSort(int arr[], int left, int right){
	int middle;
	if (left < right){
		middle = partition(arr, left, right);
		quickSort(arr, left, middle -1);
		quickSort(arr, middle +1, right);
	}
}
int QuickSort::partition(int arr[], int left, int right){
	int pivot = arr[right];
	int j = (left-1);
	for (int i = left; i <=right; ++i){
		if(arr[i] < pivot){
			++j;
			std::swap(arr[j], arr[i]);
			++m_numSwaps;
			++m_numComps;
		}
		
	}
	std::swap(arr[j+1], arr[right]);
	++m_numSwaps;
	return(j+1);
}
const size_t QuickSort::getSwaps(){
	return m_numSwaps;
}
const size_t QuickSort::getComps(){
	return m_numComps;
}
