// min binomial heaps
// degree not done
#include<stdio.h>
#include<stdlib.h>

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*n))){ \
		fprintf(stderr,"bbllhshs");\
		exit(EXIT_FAILURE); \
	}

typedef struct Node Node;
struct Node{
	int degree; // the number of children it has
	struct Node *child;// points to one of its children 
	struct Node *link; // siblings: singly linked circular list
	int data;
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

// circular singly linked list

void removefromList(Node *head, Node *target){
	Node **indirect = &head;
	while((*indirect)->link != target){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = target->link;
}

// should add degree support?
// definitely should add child support
void appendList(Node *head, Node *rookie){

	if (head->link == NULL){
		head->link = head;
	}

	if (head->link == head){
		head->link = rookie;
		rookie->link = head;
		return;
	}
	
	Node **indirect = &head;
	while((*indirect)->link != head){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = rookie;
	(*indirect)->link->link = head; // rookie points to head
}

void printList(Node *head){
	printf("list: ");
	printf("%d ",head->data);
	if(!head->link){
		return;
	}
	if(head->link == head){
		return;
	}

	Node **indirect = &(head->link);
	while((*indirect) != head){
		printf("%d ",(*indirect)->data);
		indirect = &(*indirect)->link;
	}
}

void test1(){
	Node *root = newNode(1);
	//printf("%d\n",root->data);
	//printf("%u",root->link);
	//return;
	printList(root);
	printf("\n");
	appendList(root,newNode(2));
	appendList(root,newNode(3));
	appendList(root,newNode(4));
	printList(root);
	printf("\n");
	removefromList(root,root->link->link);
	printList(root);
}

// below not tested
// min heap: not necessary the one using array
// can be generalised tree instead of just binary tree
void insertHeap(Node *Minroot, int x){
	Node *Xnode = newNode(x);
	//insert Xnode into cir lnkt list pointed by Min
	appendList(Minroot->child,Xnode);
	// what does "min is 0" means?
	if(Xnode->data < Minroot->child->data || Minroot->child->data == 0){
		Minroot->child = Xnode;
	}
}

// adjust the node pointed by Minroot to the node with the smallest data in the top linkedlist
void meldHeaps(Node *Minroot){
	Node *head = Minroot->child;
	Node **indirect = &(head->link);
	Node *tmp = head; // candidate top node with smallest data
	
	while(*indirect != head){
		if(tmp->data > (*indirect)->data){
			tmp = *indirect;
		}
		indirect = &((*indirect)->link);
	}
	
	Minroot->child = tmp;
}

// we didn't join the trees with same degree!
void deleteMinEle(Node *Minroot){
	// access the top linked list
	Node *head = Minroot->child->link;
	// remove min element in binHeap
	Minroot->child = Minroot->child->child;
	// add child of the orginal min element into top linked list
	appendList(head,Minroot->child->child);
	// determine the new min element
	meldHeaps(Minroot);
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
	test1();
	return 0;
}
