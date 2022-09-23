/*
	Jeffrey Carson
	CS302
	10/26/20
	Binary Search Tree Implementation File
*/
#include <iostream>
#include "BinaryNodeTree.h"
#include "BinaryNode.cpp"
#include <algorithm>
//CTOR
template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(){
	rootPtr = nullptr;
}
//PARAM CTOR 
template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) : 
	rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
{
}
//PARAM CTOR (with child nodes)
template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr) :
	rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr)))
{
} 
//Copy Ctor
template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree){
	rootPtr = copyTree(tree.rootPtr);
}
//DTOR
template<typename ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree(){
	this->destroyTree(rootPtr);
}
//Is BNT empty?
template<typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const{
	if (rootPtr == nullptr){
		return true;
	}
	return false;
}
//calls getHeightHelper function
template<typename ItemType>
int BinaryNodeTree<ItemType>::getHeight() const{
	return getHeightHelper(rootPtr);
}
template<typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const{

}
template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcept){

}
//Adds a new value to the tree. Makes use of balanced add.
template<typename ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData){
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}
template<typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& data){

}
template<typename ItemType>
void BinaryNodeTree<ItemType>::clear(){

}
template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException){

}
template<typename ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const{

}
//Returns the maximum height of tree, recursive. (uses std::max function)
template<typename ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const{
	if (subTreePtr == nullptr){
		return 0;
	}
	else{
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
	}
}
template<typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const{

}
//Balanced add function, will add node greater than root to the right and less than root to the left.
template<typename ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr){
	if(subTreePtr == nullptr){
		return newNodePtr;
	}
	else
	{
		std::shared_ptr<BinaryNode<ItemType>> leftPtr = subTreePtr->getLeftChildPtr(); 
		std::shared_ptr<BinaryNode<ItemType>> rightPtr = subTreePtr->getRightChildPtr();
		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr); 
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        }
		return subTreePtr; 
	}
}
template<typename ItemType>
auto BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful){

}
template<typename ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr){

}
template<typename ItemType>
auto BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& isSuccessful) const{

}
//recursively copies the data from one tree to another.
template<typename ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const{
	std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
	if (oldTreeRootPtr != nullptr){
		newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr); 
		newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr())); 
		newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
	}
	return newTreePtr;
}
//recursively clears tree. 
template<typename ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr){
	if (subTreePtr != nullptr){
		destroyTree(subTreePtr->getLeftChildPtr()); 
		destroyTree(subTreePtr->getRightChildPtr()); 
		subTreePtr.reset();
	}
}
//Prints value from root, then left, then right.
template<typename ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const{
	if(treePtr != nullptr){
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}
}
//Prints value from left, root, then right
template<typename ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const{
	if (treePtr != nullptr){
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}
}
//Prints left, right, then root.
template<typename ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const{
	if (treePtr!=nullptr){
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType item = treePtr->getItem();
		visit(item);
	}
}

