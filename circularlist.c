// circular linked list 
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

// start w/o circular part
Node **head;
Node **last;

void append(Node **last, int num, Node *root){
	Node *newbie = newNode(num);
	printf("last: %d; ",(*last)->data);
	(*last)->link = newbie;
	// new inserted node removed, which is not desired
	last = &(*last)->link; // or just simply last = &newbie ?
	printf("after append, last: %d; ",(*last)->data);
}

int main(void){
	Node *root = newNode(1);
	printlist(root);
	Node ***last;
	last = (Node***)malloc(sizeof(Node**));
	*last = &root;
	append(*last,2,root);
	printlist(root);
	// last not updated
	append(*last,3, root);
	printlist(root);

	return 0;
	/*
	Node *root = newNode(1);
	printlist(root);
	Node **last;
	last = &root;
	append(last,2);
	printlist(root);
	append(last,3);
	printlist(root);
	return 0;
	append(&root,2);
	printlist(root);
	append(&root->link,3);
	printlist(root);
	return 0;
	*/
}
