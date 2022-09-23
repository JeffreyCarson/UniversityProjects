/*
	Jeffrey Carson
	UNR CS 302
	11/28/20
	LLBT Project main file
*/

#include <iostream>
#include "LeftLeaningRedBlack.h"

using namespace std;


int main(){
	
	LeftLeaningRedBlack tree;
	
	int array[10] = {1, 2, 9, 4, 6, 3, 7, 11, 5, 8};
	LLTB_t temp;


	std::cout << "\n***TESTING LLRBT WITH 10 VALUES***\n(*Parent and Node values are relative to state of tree during that insertion.)\n\n";


	for(int i = 0; i < 10; ++i){
		temp.Ref.Key = array[i];
		std::cout << i+1 << "] Inserting Value " << temp.Ref.Key;
		tree.Insert(temp.Ref);
		LLTB_t * tColor = tree.locateNode(temp.Ref);
		
		if (tColor->IsRed == false){
			std::cout << ": Color = Black\n";
		}
		else {
			std::cout << ": Color = Red\n";
		}
				
		LLTB_t * parentNode = tree.locateParent(temp.Ref);

		if (parentNode != nullptr){
			std::cout << "Parent Value " << parentNode->Ref.Key;
			if(parentNode->IsRed == false){
				std::cout << ": Color = Black\n";
			}
			else{
				std::cout << ": Color = Red\n";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "-Inorder Traversal:\n";
	tree.Traverse();

	tree.Delete(array[3]);

	std::cout << "-Inorder Traversal After Deleting 4th Inserted element:\n";

	tree.Traverse();
	std:cout << "\n";

	return 0;
}
