#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int value;
	int color;				// 0:black 1:red
	struct Node  *leftchild,*rightchild;
	struct Node *parent;
}Node;

typedef struct RBtree{
	Node *root;
}RBtree;

RBtree *tree=NULL;

void leftRotation(Node *node);
void rightRotation(Node *node);

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->value = value;
	newNode->color = 1;
	newNode->parent = NULL;
	newNode->leftchild = NULL;
	newNode->rightchild = NULL;

	return newNode;
}

Node *minValueNode(Node *node){
	Node *current = node;
	while(current->leftchild != NULL){
		current = current->leftchild;
	}
	return current;
}
Node *trav(Node *node,int value){
	Node *current = node;

	while(current != NULL)
	{
		if(value < current->value)
			current = current->leftchild;
		else if(value > current->value)
			current = current->rightchild;
		else
			break;
	}
	return current;
}


void fixup(Node *node){
	
	Node *parent_pt=NULL;
	Node *grand_parent_pt=NULL;

	while((node != tree->root) &&(node->color != 0)
			&& (node->parent->color == 1))
	{
		parent_pt = node->parent;
		grand_parent_pt = node->parent->parent;

		/*  Case : A
             Parent of pt is left child
             of Grand-parent of
           pt */
		if(parent_pt == grand_parent_pt->leftchild)
		{
			Node *uncle_pt = grand_parent_pt->rightchild;

			/* Case : 1
                The uncle of pt is also red
                Only Recoloring required */
			if(uncle_pt != NULL && uncle_pt->color == 1)
			{
				grand_parent_pt->color = 1;
				parent_pt->color = 0;
				uncle_pt->color = 0;
				node = grand_parent_pt;
			}
			else
			{
				/* Case : 2
                     pt is right child of its parent
                     Left-rotation required */
				if(node == parent_pt->rightchild)
				{
					leftRotation(parent_pt);
					node = parent_pt;
					parent_pt = node->parent;
				}

				rightRotation(grand_parent_pt);
				int t = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = t;
				node = parent_pt;
			}
		}

		/* Case : B
             Parent of pt is right
             child of Grand-parent of
           pt */

		else
		{
			Node *uncle_pt = grand_parent_pt->leftchild;

			/*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
			if((uncle_pt != NULL) && (uncle_pt->color == 1))
			{
				grand_parent_pt->color = 1;
				parent_pt->color = 0;
				uncle_pt->color = 0;
				node = grand_parent_pt;
			}
			else
			{
				 /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
				   if(node == parent_pt->leftchild)
				   {
				   		rightRotation(parent_pt);
						node = parent_pt;
						parent_pt = node->parent;
				   }

				   /* Case : 3
                     pt is right child of its parent
                     Left-rotation required */
					leftRotation(grand_parent_pt);
					int t = parent_pt->color;
					parent_pt->color = grand_parent_pt->color;
					grand_parent_pt->color = t;
					node = parent_pt;
			}
		}
	}
	tree->root->color = 0;
}


Node *BSTinsert(Node *node , int value){
	
	
	if(node==NULL)
		return createNode(value);

	if(value < node->value){
		node->leftchild = BSTinsert(node->leftchild,value);
		node->leftchild->parent = node;
		tree->root->color = 0;
	}
	else if(value > node->value){
		node->rightchild = BSTinsert(node->rightchild,value);
		node->rightchild->parent = node;
		tree->root->color = 0;
	}



	return node;
}

Node *DeleteNode(Node *node,int value){


	if(node == NULL)
		return node;

	if(value < node->value)
		node->leftchild = DeleteNode(node->leftchild,value);
	else if(value > node->value)
		node->rightchild = DeleteNode(node->rightchild,value);
	


	Node *targetNode = trav(tree->root,value);
	Node *parentNode = targetNode->parent;

	//only one child or no child
	if(targetNode->leftchild==NULL || targetNode->rightNode==NULL){
		Node *temp = targetNode->leftchild? targetNode->leftchild:targetNode->rightchild;
		

		//判斷有無child和有無parent
		if(parentNode && !temp){
			if(targetNode->value < parentNode->value){
				temp = targetNode;
				parentNode->leftchild = NULL;
			}else{
				temp = targetNode;
				parentNode->rightchild = NULL
			}
		}
		else if(!parentNode && temp){
			*tree->root = *temp;
		}
		else{
			tree->root = NULL;
		}


		free(temp);
	}
	else{
		Node *temp = minValueNode(targetNode->rightchild);
		targetNode->value = temp->value;
	}
}

void leftRotation(Node *node){
	Node *y = node->rightchild;
	
	node->rightchild = y->leftchild;
	if(y->rightchild)
		y->rightchild->parent = y;
	y->parent = node->parent;
	if(!y->parent)
		tree->root = y;
	else if(node == node->parent->leftchild)
		node->parent->leftchild = y;
	else
		node->parent->rightchild = y;

	y->leftchild = node;
	node->parent = y;

}

void rightRotation(Node *node){

	Node *y = node->leftchild;
	
	node->leftchild = y->rightchild;
	if(y->leftchild)
		y->leftchild->parent = y;
	y->parent = node->parent;
	if(!y->parent)
		tree->root = y;
	else if(node == node->parent->leftchild)
		node->parent->leftchild = y;
	else
		node->parent->rightchild = y;

	y->rightchild = node;
	node->parent = y;

}

void inorder(Node *node){
	if(node == NULL)
		return;
	inorder(node->leftchild);
	printf("%d ",node->value);
	inorder(node->rightchild);
}

int main(){
	tree = (RBtree*)malloc(sizeof(RBtree));
	tree->root=NULL;

	for(int i=7;i>=1;i--){
		tree->root= BSTinsert(tree->root,i);
		Node *temp = trav(tree->root,i);
		fixup(temp);
		inorder(tree->root);
		printf("\n");
	}
	return 0;
}
