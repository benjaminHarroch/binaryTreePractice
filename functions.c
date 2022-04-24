#include "Header.h"



Tree *BuildTreeFromArray(int* arr, int  size) {

	Tree* tr;
	tr = (Tree*)malloc(sizeof(Tree));
	TreeNode* damy;
	 helper( tr->root,arr, size,&damy);
	return tr;

}



//function helper :
//the function get the arr and "cut" him every itaration at half is size
//so that every iteration he take ths mide data in the array and put in the newnode
//if the num is -1 he put a null value into the node

void helper(TreeNode *root,int* arr, int size,TreeNode *ptr) {

	TreeNode *left, *right;
	int mide = size / 2;
	root = (TreeNode*)malloc(sizeof(TreeNode));

	if  (size == 0) {
		return;

	}

	if (size == 1) {
		 
		root->data = arr[0];
		root->left = NULL;
		root->right = NULL;

		return;
	}
	else {

		helper(root->left, arr, size / 2,&left);
		helper(root->right, arr + mide, size / 2,&right);

		if (arr[mide] != -1) {
			root->data = arr[mide];
		}

		ptr = root;
		root->left = left;
		root->right = right;
		
	}
		

}

TreeNode* createNode(int data, TreeNode* left, TreeNode* right) {

	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;

}

void freeTree(Tree tr){

	FreeTreehelper(tr.root);
}

void  FreeTreehelper(TreeNode* root){
	
	if (root == NULL) {
		return;
	}
	else {

		FreeTreehelper(root->left);
		FreeTreehelper(root->right);
		free(root);
	}
}

void chekeMemoryAllocation(void* ptr) {

	if (ptr == NULL) {
		printf("the allocation is faile");
		exit(1);
	}
}

void helperToPrint(TreeNode* root) {

	if (root == NULL) {
		return;
	}

	else {
		//pritn all the left side and the root and the right side.
		helperToPrint(root->left);
		printf("%d ", root->data);
		helperToPrint(root->right);

	}

}


void printTreeInorder(Tree tr) {

	helperToPrint(tr.root);

}

