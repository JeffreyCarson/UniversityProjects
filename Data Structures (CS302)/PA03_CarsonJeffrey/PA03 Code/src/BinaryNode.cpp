/*
	Jeffrey Carson
	CS302
	10/26/20
	Binary Node Implementation FIle
*/
#include <iostream>
#include "BinaryNode.h"
//Default Ctor
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(){
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}
//Param Ctor (Leaf)
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & anItem){
	item = anItem;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}
//Param Ctor 
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr){
	item = anItem;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}
//Set Item
template<typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem){
	item = anItem;
}
//Get item
template<typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const{
	return item;
}
//Is the node a leaf?
template<typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const{
	if (rightChildPtr == nullptr || leftChildPtr == nullptr){
		return false;
	}
	return true;
}
//Returns leftptr
template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr() const{
	return leftChildPtr;
}
//returns rightptr
template<typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightChildPtr() const{
	return rightChildPtr;
}
//Sets left ptr
template<typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr){
	leftChildPtr = leftPtr;
}
//sets right ptr;
template<typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr){
	rightChildPtr = rightPtr;
}
