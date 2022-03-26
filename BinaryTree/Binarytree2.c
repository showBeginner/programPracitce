#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int value;
	struct TreeNode* leftNode;
	struct TreeNode* rightNode;
}Node;

Node *createNode(int value){
	Node *newNode  = (Node *) malloc(sizeof(Node));
	newNode->value = value;
	newNode->leftNode = NULL;
	newNode->leftNode = NULL;

	return newNode;
}

Node *minValueNode(Node *node){      //右子樹的最小值
	Node *current = node;			//刪除的節點有兩個child需要使用

	while(current->leftNode != NULL){
		current = current->leftNode;
	}

	return current;
}

Node *InsertTree(Node *root,int value)
{
	if(root == NULL)
		return createNode(value);


	if( value < root->value)
		root->leftNode = InsertTree(root->leftNode,value);
	else if(value > root->value)
		root->rightNode = InsertTree(root->rightNode,value);
	else
		return root;

	return root;
}

Node *deleteNode(Node *root,int value){

	if(root == NULL)
		return root;

	
	if( value < root->value)
		root->leftNode = InsertTree(root->leftNode,value);
	else if(value > root->value)
		root->rightNode = InsertTree(root->rightNode,value);
	else{
		if(root->leftNode == NULL || root->rightNode == NULL){
			Node *temp = root->leftNode? root->leftNode:root->rightNode;

			if(temp == NULL){
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;

			free(temp);
		}
		else{
			Node *temp = minValueNode(root->rightNode);
			root->value = temp->value;
			
			root->rightNode = deleteNode(root->rightNode,temp->value);
		}
	}

	return root;
}

int main()
{
	return 0;
}
