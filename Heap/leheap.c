// min binheap and fibheap
// start from the basic building blocks
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
	Node *child;
	Node *link;
	Node *prev;
	int degree;
};

Node *newNode(int num){
	Node *tnode;
	Malloc(tnode,1);
	tnode->data = num;
	tnode->child = NULL;
	tnode->link = NULL;
	tnode->prev = NULL;
	tnode->degree = 0;
	return tnode;
}

void printList(Node *head){
	Node **indirect = &head;
	while((*indirect)){
		printf("%d ",(*indirect)->data);
		indirect = &((*indirect)->link);
	}
}

void appendList(Node *head, Node *rookie){
	Node **indirect = &head;
	while((*indirect)->link){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = rookie;
	rookie->prev = *indirect;
}

void removefromList(Node *head, Node *target){
	Node **indirect = &head;
	while((*indirect)->link != target){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = target->link;
	target->prev = (*indirect)->prev;
}

// merge the trees with same degree, a pair at a time
void deleteMin();

void meldTwoHeap(Node *heap1, Node *heap2);
//fib
void mergeList(Node *a, Node *b){
	// default: a->b
	Node **indirect = &head;
	while((*indirect)->link){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = b; // merged
}


/*
   
insertHeap(Node *heap, int x)
deleteMin(Heap)
meldHeaps()

deleteEle(Heap, Node *ele)

*/
int main(void){

	return 0;
}
