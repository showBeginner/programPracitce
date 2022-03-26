#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct List{
	struct Node *head;
}List;

int AddInTail(List *list,int value){
  	Node *targetNode = (Node*)malloc(sizeof(Node));
	Node **head = &list->head;
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

Node *research_value(List *list,int value){
	Node *current = list->head;
	while(current!= NULL){
		if(current->data == value)
			return current;
		current = current->next;
	}
	return NULL;
	
}
int Insertafter(List *list,int tar_value,int add_value){
	Node *NewNode=NULL;
	Node **indirect = &list->head;
	Node *target = research_value(list,tar_value);
	if(target == NULL){
		return 0;
	}
	NewNode = (Node*) malloc(sizeof(Node));
	if(NewNode == NULL)
		return 0;
	while( *indirect != target)
		indirect = &(*indirect)->next;
	NewNode->data = add_value;
	NewNode->next = (*indirect)->next;
	(*indirect)->next = NewNode;
	return 1;

}

void removeNode(List *list,Node *target){
	Node **indirect = &list->head;

	while(*indirect != target)
		indirect = &(*indirect)->next;
	*indirect = target->next;
	
}

int removenode(List *list,int value){

	Node *targetNode = research_value(list,value);
	if(targetNode==NULL)
		return 0;
	removeNode(list,targetNode);
	return 1;
}

void Print_List(List *list){
	Node *current = list->head;
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

void CountofList(Node *head){
	printf("Count:%d\n",head->data);
}


int main(){

	int n,a,b;
	List *my_Listhead = (List*) malloc(sizeof(List));
	printf("是否成功新增：%d\n",AddInTail(my_Listhead,10));
	printf("是否成功新增：%d\n",AddInTail(my_Listhead,2));
	printf("是否成功新增：%d\n",AddInTail(my_Listhead,9));
	printf("是否成功新增：%d\n",AddInTail(my_Listhead,5));

	Print_List(my_Listhead);

	printf("Please enter targetNode and insert value :");
	scanf("%d %d",&a,&b);
	printf("Insert true or false:%d\nnumber is: %d\n",Insertafter(my_Listhead,a,b),b);
	Print_List(my_Listhead);
	printf("Please enter remove value:");
	scanf("%d",&n);
	printf("remove true or false:%d\nnumber is:%d\n",removenode(my_Listhead,n),n);
	Print_List(my_Listhead);



	return 0;
}
