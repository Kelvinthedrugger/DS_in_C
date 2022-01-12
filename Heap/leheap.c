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
	tnode->degree = 1; // deal with the height problem of subtree
	return tnode;
}

void printList(Node *head){
	Node **indirect = &head;
	while((*indirect)){
		printf("%d ",(*indirect)->data);
		indirect = &((*indirect)->link);
	}
}


/* If Minroot is the root per se, run: %s/Minroot->child/Minroot/g */

// NO circular here
// we should do a doubly circular linked list

void appendList(Node *head, Node *rookie){
	// add circular
	if(!head->link){
		head->link = rookie;
		rookie->link = head;
		rookie->prev = head;
		return;
	}
	Node **indirect = &(head->link);
	while((*indirect)->link != head){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = rookie;
	rookie->prev = *indirect;
	rookie->link = head;
}

void insertHeap(Node *Minroot, int x){
	Node *Xnode = newNode(x);
	appendList(Minroot->child,Xnode);

	// what does minroot == 0 means?
	if(Minroot->child->data > Xnode->data){
		Minroot->child = Xnode;
	}
	Minroot->child->degree += 1;
}

void adjustMin(Node *Minroot){
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

void meldTwoHeaps(Node *Minroot, Node *heap2){
	// merge child of minroot and heap2 into same linkedlist
	appendList(Minroot->child,heap2);
	// adjust so that it's a real bin/finheap
	adjustMin(Minroot);
}


void removefromList(Node *head, Node *target){
	Node **indirect = &head;
	while((*indirect)->link != target){
		indirect = &((*indirect)->link);
	}
	(*indirect)->link = target->link;
	target->prev = (*indirect)->prev;
}

void deleteMin(Node *Minroot){
	// circular so that won't be NULL
	Node *newhead = Minroot->child->link;
	// remove minNode from heap
	Node *head2 = Minroot->child->child;
	Minroot->child = NULL;
	// merge the trees with same degree, a pair at a time
	/*
	
	Stack roots;

	loop until there aren't trees with same degree
	aka first loop through newhead, then head2

		if roots[degree] is None:
			insert(tree with degree degree, roots[tree->degree])
		else:
			meldTwoHeaps(roots[tree->degree], tree with degree degree)

	*/	

	// minroot points to the smallest node
	Minroot->child = newhead;
	adjustMin(Minroot);
}


//fib

void deleteAny(Node *Minroot, Node *target){
	if(Minroot->child == target){
		deleteMin(Minroot);
		return;
	}

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
