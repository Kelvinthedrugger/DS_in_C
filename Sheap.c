// singly ended priority queue
// e.g. binomial heap
#include<stdio.h>
#include<stdlib.h>

// Memory allocation
#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct Node Node;
struct Node{
	int data;
	Node *link; // sibling
	Node *child;
	int degree; // number of child
};

Node *newNode(int num){
	Node *tnode;
	Malloc(tnode,1);
	tnode->data = num;
	tnode->degree = 0; // shoud we #define maxdeg 20 ?
	tnode->child = NULL;
	tnode->link = NULL;
	return tnode;
}


int main(void){
	return 0;
}
