#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct treeNode
{
    unsigned int data;
    struct treeNode* left;
    struct treeNode* right;

}TreeNode; 

typedef struct tree
{
    TreeNode* root;
}Tree;


Tree* BuildTreeFromArray(int* arr, int  size);
TreeNode* createNode(int data, TreeNode* left, TreeNode* right);
void freeTree(Tree tr);
void  FreeTreehelper(TreeNode* root);
void chekeMemoryAllocation(void *ptr);
void helper(TreeNode *root,int* arr, int size,TreeNode *ptr);
void helperToPrint(TreeNode* root);
void printTreeInorder(Tree tr);
