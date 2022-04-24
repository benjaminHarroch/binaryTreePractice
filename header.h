
#define FALSE 0
#define TRUE 1
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct treeNode
{
    char data;
    struct treeNode* left;
    struct treeNode* right;

}TreeNode;

typedef struct tree
{
    TreeNode* root;
}Tree;

typedef int BOOL;


 BOOL buildExpressionTree(char* str, Tree* tr);
 Tree helperBuildTree(char* str, int size);
 int calcExpression(Tree tr);
 BOOL  chekeDigiteNums(char* str, int size);
 BOOL chekeBracket(char* str, int size);
 BOOL chekeOperators(char* str, int size);
 TreeNode* createNode(char data, TreeNode* left, TreeNode* right);  
 int findIndexOperators(char* str, int size);
 void freeTree(Tree tr);
 void  FreeTreehelper(TreeNode* root);
 void chekeMemoryAllocation(void* ptr);
 float  calculeSum(char oper, char num1, char num2);
 void helperCalcExpression(TreeNode* root, float* sum, float* ptr);