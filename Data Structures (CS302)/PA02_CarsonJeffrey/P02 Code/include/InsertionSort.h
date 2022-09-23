/*  
	Jeffrey Carson
    CS302
    Project 2
	10/6/20
	InsertionSort Header
*/

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_


class InsertionSort {
	public:
		void sort(int arr[], int size);
		const std::size_t getSwaps();
		const std::size_t getComps();

	private:
		std::size_t m_numSwaps;
		std::size_t m_numComps;
};




#endif