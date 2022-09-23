/*
	Jeffrey Carson
	Stack array implementation
	CS302
	Sept. 7, 2020
*/

#include <iostream>
#include <stdexcept>
#include "StackArray.h"

using namespace std;

template <typename DataType>
//CONSTRUCTOR
StackArray<DataType>::StackArray()
//	: maxSize(maxNumber), top(0)
{
	int maxNumber = Stack<DataType>::MAX_STACK_SIZE;
	maxSize = maxNumber;
	top = 0;
	dataItems = new DataType[maxSize];
}
//COPY CONSTRUCTOR
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray<DataType>& other)
	: maxSize(other.maxSize), top(other.top)
{
	for (int i = 0; i < other.maxSize; ++i){
		dataItems[i] = other.dataItems[i];
	}
}
//OPERATOR '=' OVERLOAD
template <typename DataType>
StackArray<DataType> & StackArray<DataType>::operator=(const StackArray<DataType>& other)
{
	if (*this != &other){
		maxSize = other.maxSize;
		top = other.top;
		for (int i = 0; i < other.maxSize; ++i){
			dataItems[i] = other.dataItems[i];
		}
	}
	return *this;
}
//DTOR
template <typename DataType>
StackArray<DataType>::~StackArray(){
	delete [] dataItems;
}
//PUSH ONTO STACK
template <typename DataType>
void StackArray<DataType>::push(const DataType & newDataItem) throw (logic_error){
	if (!isFull()){
		dataItems[top] = newDataItem;
		++top;
	}
	else {
		throw logic_error("Error:: Stack Full - Cannot Push");
	}
}
//POP FROM STACK
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error){
	if (!isEmpty()){
		top -= 1;
		return dataItems[top];
	}
	else{
		throw logic_error("Error:: Stack Empty - Cannot Pop");
	}
}
//CLEAR
template <typename DataType>
void StackArray<DataType>::clear(){
	top = 0;
}
//IS EMPTY
template <typename DataType>
bool StackArray<DataType>::isEmpty() const{
	if (top == 0){
		return true;
	}
	else{
		return false;
	}
}
//IS FULL
template <typename DataType>
bool StackArray<DataType>::isFull() const{
	if (top == maxSize){
		return true;
	}
	else {
		return false;
	}
}

// NOT MY CODE, GIVEN BY INSTRUCTOR.....................................
template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 1 ; j < maxSize+1 ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}



