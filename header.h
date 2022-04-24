
#define _CRT_SECURE_NO_WARNINGS
#define LEFT  0
#define RIGHT 1
#define SIZE 100


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct listNode {
	int data;
	struct listNode* next;
} ListNode;

typedef struct list {
	ListNode* head;
	ListNode* tail;
} List;

typedef struct  treeNode {
	int data;
	struct treeNode* parent;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;

typedef struct tree {
	TreeNode* root;
	List leafList;   /*רשימה מקושרת של כל העלים בעץ*/
} Tree;


void freeTree(Tree tr);
void  FreeTreehelper(TreeNode* root);
void chekeMemoryAllocation(void* ptr);
void helperToPrint(TreeNode* root);
void printTreeInorder(Tree tr);
Tree helper(int* arr, int size);
TreeNode* createNode(int data, TreeNode* left, TreeNode* right, TreeNode* parent);
Tree BuildTreeFromArray(int* arr, int size);
Tree BuildTreeFromArrayWithLeafList(int *arr, int size);
void makeEmptyList(List* lst);
void buildList(TreeNode* root, List* lst);
ListNode* insertNodeToList(List* lst, int data);
ListNode* creatNodeList(int data, ListNode* next);
TreeNode* findParent(Tree tr, int parentData, int branchSelect);
void helperFindParent(TreeNode* root, int parenData, int branchSelect, TreeNode** parent);
Tree AddLeaf(Tree tr, TreeNode* p, int branchSelect, int data);
/*void removeLeafAndAddNewLeaf(List* lst, TreeNode* p, int data);
void removeFromStart(List* lst, ListNode* cur);
void removeFromTail(List* lst, ListNode* prev);
void removeFromPlace(List* lst, ListNode* prev, ListNode* cur);
void addNodeToHead(List* lst, ListNode* newNode);
void addNodeToTail(List* lst, ListNode* newNode);
void addNodeToplace(List* lst, ListNode* newNode, ListNode* prev);*/
ListNode* createNodeList(int data, ListNode* next);
void printLeafList(Tree tr);
void freeList(ListNode* cur);