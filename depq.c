// test passed
// double ended priority queue
// circular linked list !!
#include<stdio.h>
#include<stdlib.h>
// #include<string.h> // memcpy()

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// input variable instead of its address
# define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

typedef struct Node Node;
struct Node{
  int data;
  Node *child; // point to child if any
  Node *link; // siblings, circular linked list
  int degree; // number of child aka height ?
};

Node *newNode(int num){
  Node *tnode;
  Malloc(tnode,1);
  tnode->child = NULL;
  tnode->link = NULL;
  tnode->degree = 0;
  tnode->data = num;
  return tnode;
}

void removefromList(Node *head, Node *target){
  Node **ind = &head;
  // idk if the conditioning works
  while((*ind)->link != target){
    //printf("%d ", (*ind)->data);
    ind = &((*ind)->link);
  }
  (*ind)->link = target->link;
}

void printList(Node *head){
  printf("list: %d ",head->data);
  Node **ind = &(head->link);

  // only one node in the list
  if(*ind == head){
    return;
  }

  while(*ind != head){
    printf("%d ", (*ind)->data);
    ind = &((*ind)->link);
  }
}

void appendList(Node *head, Node *rot){
  Node **ind = &head;
  // idk if the conditioning works
  while((*ind)->link != head){
    //printf("%d ", (*ind)->data);
    ind = &((*ind)->link);
  }
  (*ind)->link = rot;

  // if rot is a single node
  // , aka :: node->link != node !!!!
  if(!rot->link){
    rot->link = head;
    return;
  }

  // else: find tail of rot since it might be head of another list
  Node **tail = &rot;
  while((*tail)->link != rot){
    tail = &((*tail)->link);
  }
  (*tail)->link = head;

}

void initList(Node *head){
  // for circular
  if(head->link){
    printf("the list has been initialised");
    return;
  }
  head->link = head;
}

// *****above works MOFO *****


// B heap

void insertTree(Node *Min, Node *rot){
  /*
    insert rot to top list

    check if rot->data < Min->data
    if yes: Min points to rot
    else: do nothing
  */  
  appendList(Min,rot);

  if(Min->data > rot->data){
    Min->link = rot;
  }
}


void meldTwoTrees(Node *h1, Node *h2){
  if(h1->degree != h2->degree){
    printf("height are %d != %d, cannot be merged!");
    return;
  }
  
  // maintain h1->data < h2->data
  if(h1->data >= h2->data){
    Node *temp;
    Malloc(temp,1);
    SWAP(h1,h2,temp);
  }

  // join h2 to h1's child list
  appendList(h1->child,h2);

  // degree is initialised as 0
  h1->degree += h2->degree + 1;
}


void popfromTree(Node *Min){
  /*
    remove node pointed by Min from the top list

    // below i'm not sure
    add child of node pointed by Min to top list

    points Min to the smallest node in top list
  */

  Node *children = Min->child;
  Node *listhead = Min->link;
  removefromList(Min, Min);
  
  // for loop through children
  // not sure how to do it
  
  Node *idx;
  for(idx = children; idx; idx = idx->link->link){
    meldTwoTrees(idx,idx->link);
    appendList(listhead,idx);
  }


  // the Min deciding part
  Min = listhead;
  for(idx = listhead->link; idx; idx = idx->link){
   if(idx->data < Min->data) {
      Min = idx;
   }
   // check if all the node in top list is visited
   if(idx == listhead){
      break;
   }
  }
}


// for F heap only
// since it's double ended, we can remove node even it's not at root
void removeLeNode();

void cascadecut();


void testlist(void){
  Node *root = newNode(1);
  initList(root);
  printList(root);
  Node *n2 = newNode(2);
  root->link = n2;
  n2->link = root;
  printf("\n");
  printList(root);
  removefromList(root,n2);
  printf("\n");
  printList(root);
  Node *n3 = newNode(3);
  appendList(root,n3);
  printf("\n");
  printList(root);
  
  Node *head2 = newNode(4);
  initList(head2);
  appendList(head2,newNode(5));
  printf("\n");
  printList(head2);
  

  appendList(root,head2);
  printf("\n");
  printList(root);

}


int main(void){
  testlist();
	return 0;
}

