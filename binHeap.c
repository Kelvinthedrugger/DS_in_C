// min binomial heaps
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int degree; // the number of children it has
	struct Node *child;// points to one of its children 
	struct Node *link; // siblings: singly linked circular list
	int data;
}Node;

Node *newNode(int num){
	Node *tnode = (Node*)malloc(sizeof(Node));
	tnode->data = num;
	tnode->degree = 0; // shoud we #define maxdeg 20 ?
	tnode->child = NULL;
	tnode->link = NULL;
	return tnode;
}

// linkedlist2.c for cir list imp.
/*
   before forming cir lktlist, we join pairs of min tree
   that have same degree until there aren't any

min: 0: empty binHeap
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
