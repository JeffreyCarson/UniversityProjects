/*  
	Jeffrey Carson
    CS302
    Project 2
	10/6/20
	QuickSort Header
*/

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class QuickSort {
	public:
		void quickSort(int arr[], int left, int right);
		void sort(int arr[], int size);
		int partition(int arr[], int left, int right);
		const size_t getSwaps();
		const size_t getComps();
	private:
		std::size_t m_numSwaps;
		std::size_t m_numComps;
};

#endif