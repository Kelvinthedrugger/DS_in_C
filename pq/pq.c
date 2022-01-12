// circular linked list is important
// we use 'single' so that the bugs would be lesser potentially
#include<stdio.h>
#include<stdlib.h>

// Memory allocation
#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

# define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

typedef struct Node Node;
struct Node{
	int data;
	Node *left, *right;
	Node *child;
	// num of child, treated as height of subtree
	int degree; 
};

Node *newNode(int num){
	Node *tnode;
	tnode->data = num;
	tnode->left = tnode->right = tnode->child = NULL;
	tnode->degree = 1;
	return tnode;
}

// binomial heap
// root of the whole heap
// define min root globally
Node *min;

void insertToHeap();

void meldTwoTree();

void popfromTree();

int main(void){
  printf("success\n");
  min = newNode(0);

  return 0;
}
