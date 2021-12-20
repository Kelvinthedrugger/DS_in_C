// even better encapsulation: 
// put every member function inside the typedef struct
// , which can't be done w/p .h file in C
#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node{
	int data;
	Node *link;
};

// newnode()
// printlist()
// append()
// pop()
// remove()
// head, tail pointer


int main(void){

	return 0;
}
