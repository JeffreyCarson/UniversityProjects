/*
	Jeffrey Carson
	CS302
	10/26/20
	Binary Search Tree Implementation FIle
*/
#include "BinarySearchTree.h"
#include "BinaryTreeInterface.h" 
#include "BinaryNode.h"
#include "BinaryNodeTree.h" 
#include "NotFoundException.h" 
#include "PrecondViolatedExcept.h" 
#include <memory>
#include <stdexcept>
#include <iostream>
//Constructor
template <typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(){
	rootPtr = nullptr;
}
//Param Constructor
template <typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem){
	
}
//Copy Constructor
template <typename ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree){
	
}
//Destructor
template <typename ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree(){
	
}
//PLACE NODE
template <typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode){
	if (subTreePtr == nullptr)
		return newNode;
	else if (subTreePtr->getItem() > newNode->getItem())
	{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else
	{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}
//REMOVE VALUE
template <typename ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool & isSuccessful)/* override*/{
	if (subTreePtr == nullptr){
		isSuccessful = false;
	}
	else if (subTreePtr->getItem() == target){
		subTreePtr = removeNode(subTreePtr);
		isSuccessful = true;
	}
	else if (subTreePtr->getItem() > target){
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
		subTreePtr->setLeftChildPtr(tempPtr);
	}
	else{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
		subTreePtr->setRightChildPtr(tempPtr);
	}
	return subTreePtr;
}
//REMOVE NODE
template <typename ItemType>
auto BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr){
	
}
//REMOVE LEFTMOST NODE
template <typename ItemType>
auto BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr, ItemType& inorderSuccessor){
	if (subTreePtr->getLeftChildPtr() == nullptr){
		inorderSuccessor = subTreePtr->getItem();
		return removeNode(subTreePtr);
	}
	else{
		std::shared_ptr<BinaryNode<ItemType>> tempPtr = removeLeftMostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
		subTreePtr->setLeftChildPtr(tempPtr);
		return subTreePtr;
	}
}
//FIND NODE
template <typename ItemType>
auto BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const{
	if (treePtr == nullptr){
		return nullptr;
	}
	// Not found
	else if (treePtr->getItem() == target){
		return treePtr;
	}
	// Found
	else if (treePtr->getItem() > target){
	// Search left subtree
		return findNode(treePtr->getLeftChildPtr(), target);
	}
	else{
	// Search right subtree
		return findNode(treePtr->getRightChildPtr(), target);
	}
}



template <typename ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const{

}
template <typename ItemType>
int BinarySearchTree<ItemType>::getHeight() const{
	return getHeightHelper(rootPtr);
}
template <typename ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const{

}
template <typename ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept){

}
template <typename ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData){

}
//Basic add function.
template <typename ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry){
	auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
	rootPtr = placeNode(rootPtr, newNodePtr);
	return true;
}

template <typename ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target){
	bool flag = false;
	rootPtr = removeValue(rootPtr, target, flag);
	return flag;
}
template <typename ItemType>
void BinarySearchTree<ItemType>::clear(){

}
template <typename ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException){

} 
template <typename ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const{
	
}
//Prints value from root, then right, then left.
template<typename ItemType>
void BinarySearchTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const{
	if(treePtr != nullptr){
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}
}
//Calls preorder
template <typename ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
	preorder(visit, rootPtr);
}
//Prints data from left, then root, then right.
template<typename ItemType>
void BinarySearchTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const{
	if (treePtr != nullptr){
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}
}
//calls inorder
template <typename ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const{
	inorder(visit, rootPtr);
}
//Prints data from left, then right, then root.
template<typename ItemType>
void BinarySearchTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const{
	if (treePtr!=nullptr){
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType item = treePtr->getItem();
		visit(item);
	}
}
//calls postorder
template <typename ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const{
	postorder(visit, rootPtr);
}
template <typename ItemType>
BinarySearchTree<ItemType> & BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide){

}
//Get height helper, recursively adds.
template<typename ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const{
	if (subTreePtr == nullptr){
		return 0;
	}
	else{
		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
	}
}
