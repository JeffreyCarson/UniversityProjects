/*
	Jeffrey Carson
	CS302
	10/26/20
	Binary Search Tree Header FIle
*/


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTreeInterface.h" 
#include "BinaryNode.h"
#include "BinaryNodeTree.h" 
#include "NotFoundException.h" 
#include "PrecondViolatedExcept.h" 
#include <memory>

template<typename ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
	private:
		std::shared_ptr<BinaryNode<ItemType>> rootPtr;
	protected:
		std::shared_ptr<BinaryNode<ItemType>> placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode);

		std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool & isSuccessful)/* override*/;

		auto removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);

		auto removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr, ItemType& inorderSuccessor);

		auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const;
		void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
		void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
		void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
		int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

	public:
		BinarySearchTree();
		BinarySearchTree(const ItemType& rootItem); 
		BinarySearchTree(const BinarySearchTree<ItemType>& tree); 
		virtual ~BinarySearchTree();

		bool isEmpty() const;
		int getHeight() const;
		int getNumberOfNodes() const;

		ItemType getRootData() const throw(PrecondViolatedExcept); 
		void setRootData(const ItemType& newData);

		bool add(const ItemType& newEntry);
		bool remove(const ItemType& target); 
		void clear();

		ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException); 
		bool contains(const ItemType& anEntry) const;

		void preorderTraverse(void visit(ItemType&)) const;
		void inorderTraverse(void visit(ItemType&)) const;
		void postorderTraverse(void visit(ItemType&)) const;

		BinarySearchTree<ItemType>&operator=(const BinarySearchTree<ItemType>& rightHandSide); 
}; 

#endif
