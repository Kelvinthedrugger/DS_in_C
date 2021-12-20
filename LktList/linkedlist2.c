// linked list w/ tail pointer
// , and nice encapsulation works
// for circular lktlist: see bottom
#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node{
	int data;
	Node *link;
};

Node *newNode(int num){
	Node *tnode = (Node*)malloc(sizeof(Node));
	tnode->data = num;
	tnode->link = NULL;
	return tnode;
}

// w/o tail pointer
void pop(Node *head, Node *target){
	Node **indirect = &head;
	while(*indirect != target){
		indirect = &(*indirect)->link;
	}
	*indirect = target->link;
}

void printlist(Node *head){
	Node **indirect = &head;
	printf("list: ");
	while(*indirect){
		printf("%d ",(*indirect)->data);
		indirect = &(*indirect)->link;
	}
	printf("\n");
}

// pass by pointer of pointer of tail node is important
void append(Node **tail, int num){
	(*tail)->link = newNode(num);
	*tail = (*tail)->link;
}

// worked
void remove_node(Node *head, Node *target, Node **tail){
	Node **indirect = &head;
	while((*indirect)->link != target){
		indirect = &(*indirect)->link;
	}
	if(*tail == target){
		*tail = *indirect;
		(*tail)->link = target->link;
		return;
	}
	// normal case
	// iterate to target
	indirect = &(*indirect)->link;
	// , and get rid of it
	*indirect = target->link;
}

int main(void){
	
	Node *root = newNode(1);
	Node *tail = root;
	append(&tail,2);
	append(&tail,3);
	printlist(root);
	remove_node(root,tail,&tail);
	printlist(root);
	printf("tail: %d\n",tail->data);
	append(&tail,4);
	printlist(root);
	printf("tail: %d\n",tail->data);

	return 0;
}


// inorder to do a circular list:

// tail originally points to head
/*
   (*tail)->link = newNode();
   (*tail)->link->link = *tail; // newnode points back to head
   *tail = (*tail)->link; // iterate *tail to newnode
   // printlist() should be modified a bit so that it won't
   // loop infinitely 
*/
