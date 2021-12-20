// min Fibonacci heap
// involve doubly linked list
#include<stdio.h>
#include<stdlib.h>

#define Malloc(p,n) \
	if(!( (p) = malloc(sizeof(*(p))*n) )){ \
		fprintf(stderr,"Insufficient memory");\
		exit(EXIT_FAILURE); \
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

void appendList(Node *head, Node *rookie){
	Node **indirect = &head;
	while((*indirect)->link){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = rookie;
	rookie->prev = *indirect;
}

void printList(Node *head){
	Node **indirect = &head;
	while((*indirect)){
		printf("%d ",(*indirect)->data);
		indirect = &((*indirect)->link);
	}
}

void removefromList(Node *head, Node *target){
	Node **indirect = &head;
	while((*indirect)->link != target){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = target->link;
	target->prev = (*indirect)->prev;
}

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

void insertHeap(Node *Minroot, int x){
	Node *Xnode = newNode(x);
	appendList(Minroot->child, Xnode);
	meldHeaps(Minroot);
}

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

void deleteEle(Node *Minroot, Node *target){
	if(Minroot->child == target){
		deleteMinEle(Minroot);
		return;
	}
	// delete b from the doubly linked list it's in 
	removefromList(target,target);
	// combine b's children with the list of last step to from a list
	// , trees of same degree are not joined as in deleteMin()
	
	// dispose of b
}
/*
insert
delete min
delete any: delete specified element
decrease key: decrease the key of specified element
*/
/*
1. insert x val : Insert an element with key x
2. extract : Print out the minimum in the heap, and delete it from the heap.
3. delete x val : Delete the node with key x and value val . It is guaranteed that there will
	be at most 1 node matching the key and value.
4. decrease x val y : Decrease the key by y on the node that has key x and value y . It is
	guaranteed that there will be at most 1 node matching the key and value.
5. quit : Terminate your program.
*/
int main(void){
	return 0;
}
