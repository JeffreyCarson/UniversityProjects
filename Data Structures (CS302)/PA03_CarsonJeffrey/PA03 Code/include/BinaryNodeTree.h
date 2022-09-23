/*
	Jeffrey Carson
	CS302
	10/26/20
	Binary Node Tree Header FIle
*/

#ifndef BINARYNODETREE_H
#define BINARYNODETREE_H

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"

template<typename ItemType>
class BinaryNodeTree/* : public BinaryTreeInterface<ItemType>*/
{
	public:
		BinaryNodeTree();
		BinaryNodeTree(const ItemType& rootItem); 
		BinaryNodeTree(const ItemType& rootItem, const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr, const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr); 
		BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree);
		virtual ~BinaryNodeTree();
		bool isEmpty() const;
		int getHeight() const;
		int getNumberOfNodes() const;
		ItemType getRootData() const throw(PrecondViolatedExcept);
		bool add(const ItemType& newData);
		bool remove(const ItemType& data);
		void clear();
		ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException); 
		bool contains(const ItemType& anEntry) const;
	protected:
		int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
		int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

		auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
		auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful);
		auto moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
		auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target, bool& isSuccessful) const;
		auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
		void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

		void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const; 
		void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const; 
		void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	private:
		std::shared_ptr<BinaryNode<ItemType>> rootPtr;
};

#endif
