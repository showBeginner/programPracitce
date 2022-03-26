#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}ListNode;

int AddInTail(ListNode **head,int value){
	ListNode *targetNode;
	targetNode = (ListNode*)malloc(sizeof(ListNode));
	if(targetNode==NULL)
		return 0;
	targetNode->data = value;
	targetNode->next = NULL;
	if((*head) == NULL){
		*head = targetNode;
		return 1;
	}
	while((*head)->next != NULL)
		head = &(*head)->next;
	(*head)->next = targetNode;
	return 1;
}

ListNode *research_value(ListNode *head,int value){
	ListNode *current = head->next;
	while(current!= NULL){
		if(current->data == value)
			return current;
	}
	return NULL;
	
}
int Insertafter(ListNode *head,int tar_value,int add_value){
	ListNode *current=head,*NewNode;
	NewNode = (ListNode*) malloc(sizeof(ListNode));
	if(NewNode == NULL)
		return 0;
	current = research_value(current,tar_value);
	if(current == NULL){
		free(NewNode);
		return 0;
	}
	NewNode->data = add_value;
	NewNode->next = current->next;
	current->next = NewNode;
	return 1;

}

void Print_List(ListNode *head){
	ListNode *current = head;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

void CountofList(ListNode *head){
	printf("Count:%d\n",head->data);
}


int main(){
	ListNode *my_linkList=NULL;

	printf("是否成功新增：%d\n",AddInTail(&my_linkList,10));
	printf("是否成功新增：%d\n",AddInTail(&my_linkList,2));
	printf("是否成功新增：%d\n",AddInTail(&my_linkList,9));
	printf("是否成功新增：%d\n",AddInTail(&my_linkList,5));

	Print_List(my_linkList);


	return 0;
}
