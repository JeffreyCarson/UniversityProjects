/*
	Jeffrey Carson
	CS.302
	Linked Implementation of a stack
	9/3/20
*/
#include <iostream>
#include "Stack.h"
#include "StackLinked.h"
//Constructor
template <typename DataType>
StackLinked<DataType>::StackLinked(/*int maxNumber = Stack<DataType>::MAX_STACK_SIZE*/){
	int maxNumber = Stack<DataType>::MAX_STACK_SIZE;
	top = nullptr;
}
//COPY CTOR
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked<DataType>& other){
	if (other.top){
		for (StackNode * oCurr = other.top; oCurr != nullptr; oCurr = oCurr->next){
			push(oCurr->dataItem);
		}
		size = other.size;
	}
}
//"=" OVERLOAD
template <typename DataType>
StackLinked<DataType> & StackLinked<DataType>::operator=(const StackLinked<DataType>& other){
	if (*this != &other){
		if (other.top){
			for (StackNode * oCurr = other.top; oCurr != nullptr; oCurr = oCurr->next){
				push(oCurr->dataItem);
			}
		}
		size = other.size;
	}
	return *this;
}
//DTOR
template <typename DataType>
StackLinked<DataType>::~StackLinked(){
	clear();
}
//PUSH
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error){
	StackNode * newN = new StackNode(newDataItem, top);
        if (top == nullptr){
                top = newN;
        }
        else{
                newN->next = top;
                top = newN;
                newN = nullptr;
        }
	
}
//POP
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error){
	if (!isEmpty()){
		if (top->next == nullptr){
			DataType t = top->dataItem;
		        delete top;
		        top = nullptr;
			return t;
		}
		else{
			DataType t = top->dataItem;
		        StackNode * temp = top;
		        top = top->next;
		        if (isEmpty()){
		                top = nullptr;
		        }
		        delete temp;
			return t;
		}
	}	
	else {
		throw logic_error("Error:: Stack Empty - Cannot Pop");
	}
}
//CLEAR
template <typename DataType>
void StackLinked<DataType>::clear(){
	while(!isEmpty()){
		pop();
	}
}
//IS EMPTY?
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const{
	if (top == nullptr){
		return true;
	}
	return false;
}
//IS FULL?
template <typename DataType>
bool StackLinked<DataType>::isFull() const{
	return false;
}
//PRAM CTOR for StackNode (class nested within StackLinked)
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType & nodeData, StackNode* nextPtr){
	dataItem = nodeData;
	next = nextPtr;
}

//NOT MY CODE -- GIVEN BY INSTRUCTOR ...........................
template <typename DataType>
void StackLinked<DataType>::showStructure() const 

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}

