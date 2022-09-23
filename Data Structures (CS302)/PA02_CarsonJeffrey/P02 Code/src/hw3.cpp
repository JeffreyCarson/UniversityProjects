#include <iostream>
#include <ctime>
#include <cstddef>
#include <fstream>
#include <chrono>
#include <cstring>
#include "QuickSort.h"
#include "InsertionSort.h"

using namespace std;
using namespace std::chrono;

void printArray(int arr[], int length);
double findAveragesInsertion(int arr[], int length, string str, InsertionSort *iSort, bool isSorted);
double findAveragesQuick(int arr[], int length, string str, QuickSort *qSort, bool isSorted);

int main() {
	//srand(time(NULL));
	ifstream myfile;
	InsertionSort iSort, iSort2;
	QuickSort qSort, qSort2;
	string str1 = ("1000.txt");
	string str2 = ("10000.txt");
	string str3 = ("100000.txt");
	int arr1[1000], arr2[10000], arr3[100000];
	double qAvg1, qAvg2 = 0, qAvg3 = 0, iAvg1 = 0, iAvg2 = 0, iAvg3 = 0;
	double qSAvg1 = 0, qSAvg2 = 0, qSAvg3 = 0, iSAvg1 = 0, iSAvg2 = 0, iSAvg3 = 0;

	//TESTING INSERTION SORT 1000
	iAvg1 = findAveragesInsertion(arr1, 1000, str1, &iSort, 0);
	
	//Outputting results to terminal
	cout << "---Testing Insertion Sort 1000 Elements--- \n";
	cout << "Average time to sort in Microseconds: " << iAvg1 << endl;
	cout << "Number of Swaps: " << iSort.getSwaps() << endl;
	cout << "Number of Comparisons: " << iSort.getComps() << endl;
	iSAvg1 = findAveragesInsertion(arr1, 1000, str1, &iSort2, 1);
	cout << "Average time to sort Presorted Array in Microseconds: " << iSAvg1 << endl;
	cout << "Number of Swaps: " << iSort2.getSwaps() << endl;
	cout << "Number of Comparisons: " << iSort2.getComps() << endl << endl;
	

	//TESTING INSERTION SORT 10000
	
	iAvg2 = findAveragesInsertion(arr2, 10000, str2, &iSort, 0);
	
	//Outputting results to terminal
	cout << "---Testing Insertion Sort 10000 Elements--- \n";
	cout << "Average time to sort in Microseconds: " << iAvg2 << endl;
	cout << "Number of Swaps: " << iSort.getSwaps() << endl;
	cout << "Number of Comparisons: " << iSort.getComps() << endl;
	iSAvg2 = findAveragesInsertion(arr2, 10000, str2, &iSort2, 1);
	cout << "Average time to sort Presorted Array in Microseconds: " << iSAvg2 << endl;
	cout << "Number of Swaps: " << iSort2.getSwaps() << endl;
	cout << "Number of Comparisons: " << iSort2.getComps() << endl << endl;
	

	//TESTING INSERTION SORT 100000
	
	iAvg3 = findAveragesInsertion(arr3, 100000, str3, &iSort, 0);
	
	
	//Outputting results to terminal
	cout << "---Testing Insertion Sort 100000 Elements--- \n";
	cout << "Average time to sort in Microseconds: " << iAvg3 << endl;
	cout << "Number of Swaps: " << iSort.getSwaps() << endl;
	cout << "Number of Comparisons: " << iSort.getComps() << endl;
	iSAvg3 = findAveragesInsertion(arr3, 100000, str3, &iSort2, 1);
	cout << "Average time to sort Presorted Array in Microseconds: " << iSAvg3 << endl;
	cout << "Number of Swaps: " << iSort2.getSwaps() << endl;
	cout << "Number of Comparisons: " << iSort2.getComps() << endl << endl;
	
	




	//TESTING QUICKSORT 1000

	qAvg1 = findAveragesQuick(arr1, 1000, str1, &qSort, 0);
	

	cout << "\n---Testing Quick Sort 1000 Elements--- \n";
	cout << "Average time to sort in Microseconds: " << qAvg1 << endl;
	cout << "Number of Swaps: " << qSort.getSwaps() << endl;
	cout << "Number of Comparisons: " << qSort.getComps() << endl;
	qSAvg1 = findAveragesQuick(arr1, 1000, str1, &qSort2, 1);
	cout << "Average time to sort Presorted Array in Microseconds: " << qSAvg1 << endl;
	cout << "Number of Swaps: " << qSort2.getSwaps() << endl;
	cout << "Number of Comparisons: " << qSort2.getComps() << endl << endl;
	


	//TESTING QUICKSORT 10000

	qAvg2 = findAveragesQuick(arr2, 10000, str2, &qSort, 0);
	

	cout << "---Testing Quick Sort 10000 Elements--- \n";
	cout << "Average time to sort in Microseconds: " << qAvg2 << endl;
	cout << "Number of Swaps: " << qSort.getSwaps() << endl;
	cout << "Number of Comparisons: " << qSort.getComps() << endl;
	qSAvg2 = findAveragesQuick(arr2, 10000, str2, &qSort2, 1);
	cout << "Average time to sort Presorted Array in Microseconds: " << qSAvg2 << endl;
	cout << "Number of Swaps: " << qSort2.getSwaps() << endl;
	cout << "Number of Comparisons: " << qSort2.getComps() << endl << endl;
	

	//Testing QuickSort 100,000
	
	qAvg3 = findAveragesQuick(arr3, 100000, str3, &qSort, 0);
	
	//Outputting results to terminal
	cout << "---Testing Quick Sort 100000 Elements--- \n";
	cout << "Average time to sort in Microseconds: " << qAvg3 << endl;
	cout << "Number of Swaps: " << qSort.getSwaps() << endl;
	cout << "Number of Comparisons: " << qSort.getComps() << endl;
	qSAvg3 = findAveragesQuick(arr3, 100000, str3, &qSort2, 1);
	cout << "Average time to sort Presorted Array in Microseconds: " << qSAvg3 << endl;
	cout << "Number of Swaps: " << qSort2.getSwaps() << endl;
	cout << "Number of Comparisons: " << qSort2.getComps() << endl << endl;

	return 0;
}

double findAveragesInsertion(int arr[], int length, string str, InsertionSort *iSort, bool isSorted){
	double avg = 0;
	ifstream myfile;
	//InsertionSort iSort;
	for (int i = 0; i < 10 ; ++i){
		//Opening file and reading in to array
		if (!isSorted){
			myfile.open(str);
			for (int i = 0; i < length; ++i){
				myfile >> arr[i];
			}
			myfile.close();
		}
		//Calculating time taken to sort entire array
		auto start = high_resolution_clock::now();
		iSort->sort(arr, length);
		auto stop = high_resolution_clock::now();
		duration<double> elapsed = stop - start;

		avg = avg + elapsed.count();
	
	}
	//Calculating Averages of Runs
	avg = avg / 10;
	return avg;
}
double findAveragesQuick(int arr[], int length, string str, QuickSort *qSort, bool isSorted){
	double avg = 0;
	ifstream myfile;
	//InsertionSort iSort;
	for (int i = 0; i < 10 ; ++i){
		//Opening file and reading in to array
		if (!isSorted){
			myfile.open(str);
			for (int i = 0; i < length; ++i){
				myfile >> arr[i];
			}
			myfile.close();
		}
		//Calculating time taken to sort entire array
		auto start = high_resolution_clock::now();
		qSort->sort(arr, length);
		auto stop = high_resolution_clock::now();
		duration<double> elapsed = stop - start;

		avg = avg + elapsed.count();
	}
	//Calculating Averages of Runs
	avg = avg / 10;
	return avg;

}
void printArray(int arr[], int length){
	for (int i = 0; i < length; ++i){
		cout << i << ") " << arr[i] << endl;
	}
}
