#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int value;
	int height;
	int BF;
	struct Node* leftNode;
	struct Node* rightNode;
}Node;

typedef struct AVLTree{
	struct Node *root;
}AVLTree;

int max(int a,int b);

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->value = value;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->height = 1;

	return newNode;
}

int getHeight(Node *node){
	
	if(node == NULL)
		return 0;
	return node->height;

}

int max(int a,int b){

	return (a>b)? a : b ;
}

int BalanceTree(Node *node){
	if(node == NULL)
		return 0;
	return getHeight(node->leftNode)-getHeight(node->rightNode);
}

Node *leftRotation(Node *node){
	Node *y = node->rightNode;
	Node *T2 = node->rightNode->leftNode;

	y->leftNode = node;
	node->rightNode = T2;

	node->height = 1+max(getHeight(node->leftNode),
						getHeight(node->rightNode));
	
	y->height = 1+max(getHeight(y->leftNode),
					getHeight(y->rightNode));
	

	return y;
}

Node *rightRotation(Node *node){
	Node *y = node->leftNode;
	Node *T2 = node->leftNode->rightNode;

	y->rightNode = node;
	node->leftNode = T2;

	node->height = 1+max(getHeight(node->leftNode),
						getHeight(node->rightNode));
	
	y->height = 1+max(getHeight(y->leftNode),
					getHeight(y->rightNode));
	

	return y;
}

Node* insert(Node *node,int value){

	if(node==NULL)
		return createNode(value);

	
	if(value < node->value)
		node->leftNode = insert(node->leftNode,value);
	else if(value > node->value)
		node->rightNode = insert(node->rightNode,value);
	else
		return node;

	node->height = 1+max(getHeight(node->leftNode),
							getHeight(node->rightNode));
	

	node->BF = BalanceTree(node);

	if(node->BF >1 && value < node->leftNode->value)
		return rightRotation(node);
	if(node->BF < -1 && value > node->rightNode->value)
		return leftRotation(node);

	if(node->BF >1 && value > node->leftNode->value){
		node->leftNode = leftRotation(node->leftNode);
		return rightRotation(node);
	}
	if(node->BF < -1 && value < node->rightNode->value){
		node->rightNode = rightRotation(node->rightNode);
		return leftRotation(node);
	}

	return node;
	

}

Node *minValueNode(Node *node){
	Node *current = node;

	while(current->leftNode != NULL)
		current = current->leftNode;

	return current;
}

Node *deleteNode(Node *root,int value){
	
	if(root == NULL)
		return root;
	
	if(value < root->value)
		root->leftNode = deleteNode(root->leftNode,value);
	else if(value > root->value)
		root->rightNode = deleteNode(root->rightNode,value);
	else{
			//only one child or no child
		if(root->leftNode == NULL || root->rightNode == NULL){
			Node *temp = root->leftNode? root->leftNode : root->rightNode;

			//No child
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

	if(root == NULL)
		return root;

	root->height = 1+max(getHeight(root->leftNode),
							getHeight(root->rightNode));

	root->BF = BalanceTree(root);

	if(root->BF >1 && BalanceTree(root->leftNode) >= 0)
		return rightRotation(root);
	if(root->BF < -1 && BalanceTree(root->rightNode) <= 0)
		return leftRotation(root);

	if(root->BF >1 && BalanceTree(root->leftNode) < 0){
		root->leftNode = leftRotation(root->leftNode);
		return rightRotation(root);
	}
	if(root->BF < -1 && BalanceTree(root->rightNode) > 0){
		root->rightNode = rightRotation(root->rightNode);
		return leftRotation(root);
	}

	return root;

}

void preOrder(Node *root){
	if(root != NULL){
		printf("%d ",root->value);
		preOrder(root->leftNode);
		preOrder(root->rightNode);
	}
}

int main()
{
	Node *root = NULL;

	root = insert(root,9);
	preOrder(root);
	printf("\n");
	root = insert(root,5);
	preOrder(root);
	printf("\n");
	root = insert(root,10);
	preOrder(root);
	printf("\n");
	root = insert(root,0);
	preOrder(root);
	printf("\n");
	root = insert(root,6);
	preOrder(root);
	printf("\n");
	root = insert(root,11);
	preOrder(root);
	printf("\n");
	root = insert(root,-1);
	preOrder(root);
	printf("\n");
	root = insert(root,1);
	preOrder(root);
	printf("\n");
	root = insert(root,2);
	preOrder(root);
	printf("\n");


	root = deleteNode(root,10);
	preOrder(root);
	printf("\n");

	return 0;
}
