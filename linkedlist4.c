// doubly linked list implementation
#include<stdio.h>
#include<stdlib.h>

// checkout malloc in macro
//#define Malloc(var,size)

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

void printlist(Node *head);
void append(Node *tail, Node *newbie);

void remove_node(Node *head, Node *tail, Node *tar);

int main(void){
	return 0;
}
