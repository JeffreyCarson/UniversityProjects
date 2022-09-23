/*
	Jeffrey Carson
	CS302
	10/26/20
	Binary Node Header FIle
*/
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <memory>
template<typename ItemType>
class BinaryNode{
	public:
		BinaryNode();
		BinaryNode(const ItemType & anItem);
		BinaryNode(const ItemType & anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr, std::shared_ptr<BinaryNode<ItemType>> rightPtr);
		void setItem(const ItemType& anItem); ItemType getItem() const;
		bool isLeaf() const;
		std::shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;
		std::shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;
		void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
		void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
	private:
		ItemType item;
		std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
		std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;
};

#endif
