// single/double ended priority queue
// return node address approach
#include<stdio.h>
#include<stdlib.h>
//#include<string.h> // for memcpy()

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void println(void){
	printf("\n");
}

typedef struct Node Node;
struct Node{
	int data;
	Node *link;
	Node *child;
	int degree;
};

Node *newNode(int num){
	Node *tnode;
	Malloc(tnode,1);
	tnode->data = num;
	tnode->degree = 0;   // number of child, binomial, fibonacci
	tnode->child = NULL; // point to one of its child
	tnode->link = NULL;  // to maintain sibling
	return tnode;
}

void printinfo(Node *node){
	printf("Node info: data: %d, degree: %d, has child: %d, has link: %d\n",node->data, node->degree, !(node->child == 0), !(node->link == 0));
}

/* CIRCULAR linked list*/

// return the address of the last node in linkedlist
Node *trav(Node *head){
	Node **ind = &head;
	//printf("list: %d ",(*ind)->data);
	while((*ind)->link != NULL){
		ind = &(*ind)->link;
		//printf("%d ",(*ind)->data);
	}
	return *ind;
}

void appendList(Node *head, Node *rok){
	Node *tail = trav(head);
	tail->link = rok;
}

void printList(Node *head){
	//trav(head);
  Node **ind = &head;
	printf("list: %d ",(*ind)->data);
	while((*ind)->link != NULL){
		ind = &(*ind)->link;
		printf("%d ",(*ind)->data);
	}
}

void removefromList(Node *head, Node *target){
	Node **ind = &head;
	//printf("list: %d ",(*ind)->data);
	while((*ind)->link != target){
		ind = &(*ind)->link;
		//printf("%d ",(*ind)->data);
	}
	// remove the target node from the list
	(*ind)->link = target->link;
}


// above worked!

void meldTwoTrees(Node *top1, Node *top2){
  /*
    merge the two trees with the same height at a time
      
      the node w/ smaller value as new root

  */
  // error checking
  if(top1->data != top2->data){
    printf("\nsubtree w/ root %d and %d are not mergeable\n",top1->data, top2->data);
    return;
  }
	// keep top1.data > top2 
	if(top1->data <= top2->data){
		Node *tmp;
		SWAP(top1,top2,tmp);
	}

	appendList(top1->child,top2);
	
	// degree is init as 0
	top1->degree += top2->degree+1;
}

void test2();
void test();

int main(void){
	//test();
  test2();
	return 0;
}
void test2(){
  Node *root = newNode(1);
  root->link = newNode(2);
  Node *r2 = newNode(3);
  r2->link = newNode(4);
  appendList(root,r2);
  printList(root);
  println();
  removefromList(root,r2);
  printList(root);
}
void test(){
	// init list
	Node *root = newNode(1);
	//root->link = root;
	Node *n2 = newNode(2);
	root->link = n2;
	trav(root);
	Node *n3 = newNode(3);
	Node *n4 = newNode(4);
	n3->link = n4;
	println();
	trav(n3);
	println();
	root->link->link = n3;
	trav(root);
	Node *n5 = newNode(5);
	Node *n6 = newNode(6);
	appendList(n5,n6);
	println();
	printList(n5);
	appendList(root,n5);
	println();
	printList(root);
	removefromList(root,n5);
	println();
	printList(root);
}

