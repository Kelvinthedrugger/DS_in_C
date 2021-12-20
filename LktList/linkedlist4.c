// doubly linked list implementation
#include<stdio.h>
#include<stdlib.h>

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct Node Node;
struct Node{
	int data;
	Node *prev;
	Node *link;
};

Node *newNode(int num){
	Node *tnode;
	Malloc(tnode,1);
	tnode->data = num;
	tnode->prev = NULL;
	tnode->link = NULL;
	return tnode;
}

void printlist(Node *head){
	Node **indirect = &head;
	while(*indirect){
		printf("%d ",(*indirect)->data);
		indirect = &((*indirect)->link);
	}
}


void append(Node **tail, Node *newbie){
	(*tail)->link = newbie;
	*tail = (*tail)->link;
}

void remove_node(Node *head, Node *tar, Node **tail){
	Node **indirect = &head;
	while((*indirect)->link != tar){
		indirect = &((*indirect)->link);
	}
	if(tar == *tail){
		*tail = *indirect;
	}
	(*indirect)->link = tar->link;
}

int main(void){
	
	Node *root = newNode(1);
	Node *tail = root;
	append(&tail,newNode(2));
	append(&tail,newNode(3));
	printlist(root);
	printf("tail: %d\n",tail->data);
	append(&tail,newNode(4));
	printlist(root);
	printf("tail: %d\n",tail->data);
	remove_node(root,tail,&tail);
	printlist(root);
	printf("tail: %d\n",tail->data);

	return 0;
}
