// Fibonacci Heap:: double ended priority heap
// all min heaps
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
	Node *prev; // double ended
	Node *child;
	int degree; // number of child
};

Node *newNode(int num){
	Node *tnode;
	Malloc(tnode,1);
	tnode->data = num;
	tnode->degree = 0;   // number of child, binomial, fibonacci
	tnode->child = NULL; // point to one of its child
	tnode->prev = NULL;
	tnode->link = NULL;  // to maintain sibling
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
	printf("list: ");
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
	target->prev = *ind;
	(*ind)->link = target->link;
}

// append node at tail of linked list 
// should change rok to Node ** so that chains/trees can be merged
void appendList(Node *head, Node *rok){
	Node **ind = &head;
	// if ind points to head
	// 	does not enter the while loop
	while((*ind)->link != head){
		ind = &((*ind)->link);
	}
	rok->link = head;
	(*ind)->link = rok;
	rok->prev = *ind;
}

void CirList(Node *head){
	head->link = head;
	head->prev = head; // not sure if this line is needed in D lktlist
}

void test1(){
	Node *root = newNode(1);
	CirList(root);
	appendList(root,newNode(2));
	appendList(root,newNode(3));
	printList(root);
	removefromList(root,root->link->link);
	appendList(root,newNode(4));
	printList(root);
	Node *n1 = newNode(5);
	CirList(n1);
	appendList(n1,newNode(6));
	printList(n1);
	appendList(root,n1);
	printList(root);
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
	adjustMin(&(Min->child),Xnode);
	/*
	if(x < Min->child->data){
		Min->child = Xnode;
	}*/
}

# define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

// merge two heap to the same heap
//  only the heaps with the same height can be merged?
void meldTwoHeaps(Node *h1, Node *h2){
	if (h1->degree != h2->degree){
		printf("binomial heap can be merged only for the nodes with same height aka degree");
	}
	// keep h1.data < h2.data
	if(h1->data > h2->data){
		Node *temp;
		SWAP(h1,h2,temp);
	}
	appendList(h1->child,h2);
	h1->degree += h2->degree + 1; // since degree is initialized as 0
}

# define Compare(x,y)((x)>(y)?1:(x)==(y)?0:-1)

# define maxlen 20

void push(Node **stack,Node *node, int *top){
	stack[*top] = node;
	*top += 1;
}
Node *view(Node **stack, int *top){
	return *(stack+*top);
}

void pop(Node **stack, int *top){
	top -= 1;
	if(top < 0){
		fprintf(stderr,"cudkjfl");
		exit(EXIT_FAILURE);
	}
}
int empty(Node **stack, int *top){
	return *top <= -1;
}
// pop the node pointed by min and adjust the structure
void deleteMin(Node *Min){
	// pop node pointed by Min: do nothing
	
	// use stack ? 
	// loop until no trees with same height
	//    pair the trees in top list according to height
	//    merge the pairs

	//Stack TopList;
	Node **TopList;
	Malloc(TopList,maxlen);
	int top = 0;
	Node *cur = Min->child->link;
	push(TopList,Min->child, &top);

	// candidate of the pointed-by-Min node
	Node *tobeMin = cur;

	// merge trees and find min simultaneously to reach fewer total steps in this program
	for(; !empty(TopList,&top); cur = cur->link){
		Node *inList = view(TopList, &top);
		if(inList->degree == cur->degree){
			meldTwoHeaps(inList,cur);
			pop(TopList,&top);
		}
		else{
			push(TopList,cur,&top);
		}
		// if tobeMin is not the smallest
		if(!Compare(cur->data,tobeMin->data)){
			tobeMin = cur;
		}
	}
	// point min to the node (one of the tree roots) with the smallest data 
	Min->child = tobeMin;
}

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
	test1();
	return 0;
}
