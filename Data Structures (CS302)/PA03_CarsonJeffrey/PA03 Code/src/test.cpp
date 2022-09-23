/*
	Jeffrey Carson
	CS302
	10/26/20
	Test File 
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>

#include "BinaryNodeTree.cpp"
#include "BinarySearchTree.cpp"

using namespace std;

template<typename ItemType>
void visit(const ItemType data){
	cout << data << " ";
}

int main(){

	srand(time(NULL));
	int height, temp = 201;
	bool flag;
	std::vector<int> vec;
	BinarySearchTree<int> tree;

	//Generating random numbers
	//Inserting into an std::vector, then inserting into BST structure.
	cout << "Generating 100 unique random numbers (1-200):\n";
	temp = rand() % 200;
	vec.push_back(temp);
	while(vec.size() != 100){
		temp = rand() % 200;
		if (std::find(vec.begin(), vec.end(), temp) != vec.end()){

		}
		else {
			vec.push_back(temp);
		}
	}
	//Adding values from vector into tree
	for (int i = 0; i < 100; ++i){
		cout << vec[i] << " ";
		tree.add(vec[i]);
	}
	//Height of tree
	cout << "\n\nHeight of tree: ";
	height = tree.getHeight();
	cout << height;

	//PREORDER
	cout << "\n\nPreorder Traverse of the Tree: \n";
	tree.preorderTraverse(visit);
	//INORDER
	cout << "\n\nInorder Traverse of the Tree: \n";
	tree.inorderTraverse(visit);
	//POSTORDER
	cout << "\n\nPostorder Traverse of the Tree: \n";
	tree.postorderTraverse(visit);
	cout << endl;



	return 0;
}
