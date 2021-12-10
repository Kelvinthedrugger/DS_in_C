#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node{
	int data;
	struct Node* link;
};

Node *newNode(int num){
	Node *tnode = (Node*)malloc(sizeof(Node));
	tnode->data = num;
	tnode->link = NULL;
	return tnode;
}

void printlist(Node *head){
	Node **indirect = &head;
	printf("list: ");
	while(*indirect){
		printf("%d ",(*indirect)->data);
		indirect = &(*indirect)->link;
	}
	printf("\n");
}

typedef struct List List;
struct List{
	Node **head;
	Node **last;
};

List *newList(void){
	List *list = (List*)malloc(sizeof(List));
	(list->head) = (Node**)malloc(sizeof(Node*));
	(list->last) = (Node**)malloc(sizeof(Node*));
	*(list->head) = NULL;
	*(list->last) = NULL;
	return list;
}

void append(List *list, int num) {
	Node *roo = newNode(num);
	if(*(list->head) == NULL){
		(*(list->head)) = roo;
		(*(list->last)) = roo;
		printf("exe");
	}
	else{
		printf("\nnot head: ");
		(*(list->last))->link = roo;		
	}
	
}

int main(void){
	List *list1 = newList();
	append(list1,1);
	printlist(*(list1->head));
	append(list1,2);
	printlist(*(list1->head));
	
	list1->last = &(*(list1->last))->link;
	append(list1,3);
	printlist(*(list1->head));
	return 0;
	list1->last = &(*(list1->last))->link;
	append(list1,4);
	printlist(*(list1->head));
	return 0;
	// works
	int i;
	Node *root = newNode(1);
	list1->head = &root;
	list1->last = &root;
	printlist(*(list1->head));
	for(i = 2 ; i < 4;i++){
		Node *n = newNode(i);
		(*(list1->last))->link = n;
		list1->last = &(*(list1->last))->link;
		printlist(*(list1->head));
	}
	printlist(*(list1->head));

	return 0;
	append(list1,1);
	printlist(*(list1->head));
	append(list1,2);
	printlist(*(list1->head));
	append(list1,3);
	printlist(*(list1->head));
	
	return 0;
}
