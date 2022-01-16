// binomial heap again
#include<stdio.h>
#include<stdlib.h>

#define Malloc(p,n) if(!((p)=malloc(sizeof(*(p))*(n)))) exit(EXIT_FAILURE)

#define Swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

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
  tnode->link = NULL; // linkedlist
  tnode->child = NULL;// point to one of children if any
  tnode->degree = 1; // number of child
  return tnode;
}

Node *min;
// circular linked list

void removefromList(Node *head, Node *tar){
  if(head->link == head){
    free(head); // not sure
    return;
  }
  // below worked
  Node **ind = &head;
  while((*ind)->link != tar){
    ind = &(*ind)->link;
  }
  // the tar node is removed from the list
  (*ind)->link = tar->link;
  // idk should we free Node *tar
}

void initList(Node *head){
  head->link = head;
}

// done, eventually, failed a class 
void insertList(Node *head, Node *tar){
  if(head->link == NULL){
    initList(head);
  }
  Node **ind = &head;
  // should not be entered for a single-node-list
  while((*ind)->link != head){
    ind = &(*ind)->link;
  }
  (*ind)->link = tar;
  //branch here: concept: tar->link = head;
  // tar is a single node
  if(tar->link == NULL){
    tar->link = head;
    return;
  }
  // tar is not head of a list
  Node **ind2 = &tar;
  while((*ind2)->link != tar){
    ind2 = &(*ind2)->link;
  }
  (*ind2)->link = head;
}

// print the linked list
// worked 
void printList(Node *head){
  printf("\nlist: ");
  printf("%d ",head->data);

  Node **ind = &head;
  ind = &(*ind)->link;
  while((*ind) != head){
    printf("%d ",(*ind)->data);
    ind = &(*ind)->link;
  }
  printf("\n");
}

// heap: min heap for example
// insert node to the binomial min heap:
//    add new node to the top list
//    exam whether it's smaller than the min node
//    and make it the new min node if that's the case
// call: insertHeap(min, rookie_node);
void insertHeap(Node *min, Node *tar){
  insertList(min,tar);
  // change node if new node data is less than min node data
  // ( i mean the node pointed by min )
  if(min->data > tar->data){
    min = tar;
  }
}

// meld the two heaps with the same height
// and make the smaller node to be root 
// in this context (min heap)
void meldTwoHeaps(Node *head1, Node *head2){
  // error message
  if(head1->degree != head2->degree){
    printf("height not the same, exit meld()");
    return;
  }
  
  // naive way
  if(head1->data > head2->data){
    insertList(head2->child,head1);
    head2->degree += head1->degree;
    return;
  }
  insertList(head1->child,head2);
  head1->degree += head2->degree;
}

// remove the node pointed by min from top list (from b-heap)
// meld pairs of heap(subtree with same height)
// build top list
// pointed min to the node with smallest data
//  , in the top list (hence the smallest node 
//  of the whole bheap
void popfromHeap(Node *min){
  Node *tmphead; // so to not lose the toplist
  Malloc(tmphead,1); // marked
  tmphead = min->link;

  removefromList(min, min);

  // loop throu subtrees, hard!

  
}

void test(){
  min = newNode(0);
  Node *a = newNode(1);
  min->link = a;
  a->link = min;
  // 0, 1, 0
  printf("%d, %d, %d\n",min->data, min->link->data, min->link->link->data);
  // 0 1
  printList(min);
  removefromList(min,a);
  // 0 0
  printf("%d, %d\n",min->data,min->link->data);
  // 0
  printList(min);

  // insert starts from here
  Node *b = newNode(2);
  insertList(min,b);
  // 0 2
  printList(min);

  Node *c = newNode(3);
  Node *d = newNode(4);
  //c -> link = d;
  //d -> link = c;
  insertList(c,d);
  // 3 4
  printList(c);

  insertList(min,c);
  // 0 2 3 4
  printList(min);
}

int main(void){
  test();
  return 0;
}
