#include "header.h"


BOOL buildExpressionTree(char* str, Tree* tr) {

	BOOL bracketGood, digitGood, operatorGood;
	int sizeStr = strlen(str);

	bracketGood =chekeDigiteNums(str,sizeStr);
	digitGood=chekeBracket(str,sizeStr);
	operatorGood = chekeOperators(str,sizeStr);

	if (bracketGood && digitGood && operatorGood) {
		*tr=helperBuildTree(str,sizeStr);
		return TRUE;
	}else {
		return FALSE;
	}

}

Tree helperBuildTree(char *str,int size) {


	int index = findIndexOperators(str,size );
	Tree tr;

	if (index == -1) {

		return;
	}
	else {

		tr.root = createNode(str[index], NULL, NULL);
		chekeMemoryAllocation(tr.root);
		

		if (str[index + 1] >= 48 && str[index + 1] <= 57) {
			tr.root->right = createNode(str[index + 1], NULL, NULL);
		}
		else {
			tr.root->right=helperBuildTree(str + index +1, size - index-1).root;
		}
		if (str[index - 1] >= 48 && str[index - 1] <= 57) {
			tr.root->left = createNode(str[index -1], NULL, NULL);
		}
		else {
			tr.root->left = helperBuildTree(str+1, index-1).root;
		}

		return tr;
	}

}


int calcExpression(Tree tr) {

	float sum;
	float dummyptr;
	sum = 0;

	helperCalcExpression(tr.root, &sum,&dummyptr);

	return (int)sum;
}

void helperCalcExpression(TreeNode *root, float *sum,float *ptr) {

	float sumL, sumR;

	if (root == NULL) {
		*ptr = 0;
		return;
	}
	else {

		helperCalcExpression(root->left, sum, &sumL);
		helperCalcExpression(root->right, sum,&sumR);
		
		*ptr = calculeSum(root->data, sumL, sumR);
		*sum = *ptr;
	}
}

BOOL  chekeDigiteNums(char* str,int size) {

	int i;
	BOOL flage = 1;

	//ASCII value of 0 = 48, 9 = 57. So if value is outside of numeric range then fail
	for (i = 0; i < size; i++) {
		
		if (str[i] >=48 && str[i] <= 57) {

			if (str[i+1] >= 48 && str[i+1] <= 57) {
				flage = 0;
				return flage;
			}
		}
	}

	return flage;
}

BOOL chekeBracket(char *str,int size) {

	int i,counterOpenBrasket,counterCloseBrasket;
	counterCloseBrasket = 0;
	counterOpenBrasket = 0;
	

	for (i = 0; i < size; i++) {

		if (str[i] == '(' ) {
			counterOpenBrasket++;
		}
		if (str[i] == ')') {
			counterCloseBrasket++;
		}
	}

	if (counterCloseBrasket == counterOpenBrasket)
		return TRUE;

	return FALSE;

}

BOOL chekeOperators(char *str,int size) {

	int i;
	BOOL flage;
	flage = 1;

	for (i = 0; i < size; i++) {

		//if this is a different operator and this not number so thie char is not available
		if (str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '%') {
			if (str[i] < 48 && str[i]>57) {
				flage = 0;
				return flage;
			}
		}
	}

	return flage;

}

TreeNode* createNode(char data, TreeNode* left, TreeNode* right) {

	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	chekeMemoryAllocation(newNode);

	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;

}

int findIndexOperators(char* str, int size) {
	
	int openBracketsCounter = 0;
	int operatorsCounter = 0;
	int index = 0;
	BOOL flage;
	flage = TRUE;

	while (index < size) {

		if (*(str + index) == '(') {

			openBracketsCounter++;
		}

		else if (*(str + index) == '+' || *(str + index) == '-' || *(str + index) == '*' || *(str + index) == '/' ||
			*(str + index) == '%')
			operatorsCounter++;

		if (openBracketsCounter == operatorsCounter) {

			return index;
		}

		index++;
	}

	return -1;
}

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

float  calculeSum(char oper, char num1, char num2) {

	float newNum1 = num1 - '0';
	float newNum2 = num2 - '0';
	float sum = 0;

	if (oper == '+') {

		sum = newNum1 + newNum2;
	}
	else if (oper == '-') {

		sum = newNum1 - newNum2;
	}
	else if (oper == '/') {

		sum = newNum1 / newNum2;
	}
	else if (oper == '*') {

		sum = newNum1 * newNum2;
	}
	else if (oper == '%') {

		sum = (int)newNum1 % (int)newNum2;
	}
	else {
		//if this is not a operator so this a number
		//so return the value of the num

		sum = oper - '0';
	}

	return sum;
}