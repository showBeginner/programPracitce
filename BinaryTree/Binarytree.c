#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
	int data;
	struct TreeNode* leftNode;
	struct TreeNode* rightNode;
}TNode;

TNode *InsertTree(TNode *root,TNode *p)
{
	TNode *r,*q;
	char direction; 					//1:left 0:right
	p->leftNode = p->rightNode = NULL;
	if(root = NULL)
		p = root;
	else
	{
		q = t;
		while(q != NULL)
		{
			if(p->data < q->data)
			{
				direction = 1;
				r = q;
				q = q->leftNode;
			}
			else if(p->data > q->data)
			{
				direction = 0;
				r = q;
				q = q->rightNode;
			}
			else
			{
				return root;
			}
		}
		if(direction==1)
			r->leftNode = p;
		else
			r->rightNode = p;
	}
	return root;
}

int main()
{
	return 0;
}
