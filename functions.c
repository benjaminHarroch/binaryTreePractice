
#include "header.h"

void freeTree(Tree tr) {

	FreeTreehelper(tr.root);
}

void  FreeTreehelper(TreeNode* root) {

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

Tree BuildTreeFromArrayWithLeafList(int* arr, int  size) {

	Tree tr;
	tr = BuildTreeFromArray(arr, size);
	makeEmptyList(&tr.leafList);
	buildList(tr.root, &tr.leafList);
	return tr;
}

Tree  BuildTreeFromArray(int* arr, int  size) {

	Tree tr;
	tr = helper(arr, size);
	return tr;
}


//function helper :
//the function get the arr and "cut" him every itaration at half is size
//so that every iteration he take ths mide data in the array and put in the newnode
//if the num is -1 he put a null value into the node

Tree helper(int* arr, int size) {

	Tree tr, treeLeft, treeRight;
	int mide = size / 2;
	tr.root = (TreeNode*)malloc(sizeof(TreeNode));

	if (size == 0) {
		return;

	}

	if (size == 1) {

		tr.root->data = arr[0];
		tr.root->left = NULL;
		tr.root->right = NULL;
		tr.root->parent = NULL;

		return tr;
	}
	else {

		tr.root->data = arr[mide];

		if (arr[mide / 2] != -1) {

			treeLeft = helper(arr, size / 2);
			tr.root->left = treeLeft.root;
			tr.root->left->parent = tr.root;
		}
		else {
			tr.root->left = NULL;
		}

		if (arr[mide + (mide / 2) + 1] != -1) {
			treeRight = helper(arr + mide + 1, mide);
			tr.root->right = treeRight.root;
			tr.root->right->parent = tr.root;
		}
		else {
			tr.root->right = NULL;
		}

	}
	return tr;
}

TreeNode* createNode(int data, TreeNode* left, TreeNode* right,TreeNode* parent) {

	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;
	newNode->parent = parent;

	return newNode;

}


void makeEmptyList(List* lst) {

	lst->head = lst->tail = NULL;
}

void buildList(TreeNode* root, List* lst) {

	if (root == NULL) {
		return;
	}

	else {

		buildList(root->left, lst);
		buildList(root->right, lst);

		if (root->left == NULL && root->right == NULL) {
			insertNodeToList(lst, root->data);
		}
	}
}

//if the list is empty change ths tail and the head els change only the tail
//this is the insertNode TO TAIL
ListNode* insertNodeToList(List* lst, int data) {

	ListNode* node;
	node=createNodeList(data, NULL);
	
	if (lst->head == NULL) {
		lst->head =lst->tail= node;
	}
	else {
		lst->tail->next = node;
		lst->tail = node;
	}
	return node;
}
 

ListNode* creatNodeList(int data, ListNode* next) {

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	newNode->data = data;
	newNode->next = next;

	return newNode;
}


TreeNode* findParent(Tree tr, int parentData,int branchSelect) {

	TreeNode* parent;
	parent = (TreeNode*)malloc(sizeof(TreeNode));
	helperFindParent(tr.root, parentData, branchSelect,&parent);
	return parent;
}

void helperFindParent(TreeNode* root, int parenData, int branchSelect,TreeNode **parent) {


	if (root == NULL) {
		return;
	}
	else {

		helperFindParent(root->left, parenData, branchSelect,parent);
		helperFindParent(root->right, parenData, branchSelect,parent);

		if (root->data == parenData) {

			if (branchSelect == 0) {

				if (root->left == NULL) {

					*parent = root;

				}

			}else{

				if (root->right == NULL) {

					*parent = root;
					
				}
			}
			
		}

	}
}


//p is the parent that is already in the tree
Tree AddLeaf(Tree tr,TreeNode* p,int branchSelect,int data) {


	if (branchSelect == 0) {
		p->left = createNode(data, NULL, NULL, p);
	}
	else if (branchSelect == 1) {
		p->right = createNode(data, NULL, NULL,p);

	}

	freeList(tr.leafList.head);
	makeEmptyList(&tr.leafList);
	buildList(tr.root, &tr.leafList);

	return tr;

}


ListNode* createNodeList(int data, ListNode* next) {

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	newNode->data = data;
	newNode->next = next;
	return newNode;
}

void printLeafList(Tree tr) {

	ListNode* cur;

	cur = tr.leafList.head;

	while (cur != NULL) {

		printf(" %d ", cur->data);

		cur = cur->next;
	}

}

void freeList(ListNode* cur) {

	if (cur == NULL) {
		return;
	}
	else {

		freeList(cur->next);
		free(cur);
	}

}