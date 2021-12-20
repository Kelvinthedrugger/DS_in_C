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
	tnode->degree = 0;
	tnode->child = NULL;
	tnode->link = NULL;
	return tnode;
}


// linked list, needs to be circular!
//  to be convenient to travel down the top list

// can be used in below ?
Node *traverse(Node *start, Node *tar){
	Node **ind = &start;
	while((*ind)->link != tar){
		ind = &((*ind)->link);
	}
	return *ind;
}

void printList(Node *head){
	// print head node
	printf("%d ",head->data);

	// traverse down
	Node **ind = &(head->link);
	while((*ind) != head){
		printf("%d ",(*ind)->data);
		ind = &((*ind)->link);
	}
}
void removefromList(Node *head, Node *target){
	Node **ind = &head;
	while((*ind)->link != target){
		ind = &((*ind)->link);
	}
	(*ind)->link = target->link;
}

// append node at tail of linked list 
void appendList(Node *head, Node *rok){
	Node **ind = &head;
	while((*ind)->link != head){
		ind = &((*ind)->link);
	}
	rok->link = (*ind)->link;
	(*ind)->link = rok->link;
}

// binomial heap
// Pass by reference is Hard

// have Min node points to the node w/ smallest value 
void adjustMin(Node **Min, Node *Rok){
	if((*Min)->data > Rok->data){
		*Min = Rok;
	}
}


// insert new node to the bin heap
void insertHeap(Node *Min, int x){
	Node *Xnode = newNode(x);

	// add Xnode to top list
	appendList(Min->child,Xnode);

	// check node pointed by Min
	if(x < Min->child->data){
		Min->child = Xnode;
	}
}

// merge two heap to the same heap
//  only the heaps with the same height can be merged?
void meldTwoheaps(Node *h1, Node *h2);


// pop the node pointed by min and adjust the structure
void deleteMin(Node *Min);

/*
   before forming cir lktlist, we join pairs of min tree
   that have same degree until there aren't any

min: 0: empty binHeap
   else: points to the node with the smallest value
insert:
	first putting x into a newNode()
	-> insert node into cir lktlist pointer by min
	-> if node < min or min == 0: update min to node
	time: O(1)
meld:
	meld the top linked lists into 1 singly cir lktlist
	-> make the smaller one to be min node
	time: O(1)
delete:
	min is removed from its cir lktlist
	-> new b-heap consists of the remaining subtrees

 summary steps:
 	1. merge the trees
	2. form singly cir lktlists
	3. declare min and point it

	void joinMinTree(root_large, root_small): 
		make root_large the child of root_small

	A single node can be viewed as tree ?

*/



int main(void){
	return 0;
}
