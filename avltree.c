// AVL Tree (from txb mostly)
// aka binTree ver of red-black tree
#include<stdio.h>
#include<stdlib.h>

#define isFull(ptr) (!(ptr))

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct Node Node;
struct Node{
	Node *leftchild;
	int data;
	short int bf;
	Node *rightchild;
};


void left_rotation(Node **parent,int *unbalanced){
	Node *child, *grandchild;
	child = (*parent)->leftchild;
	if(child->bf == 1){
		// LL
		(*parent)->leftchild = child->rightchild;
		child->rightchild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else{
		// LR
		grandchild = child->rightchild;
		child->rightchild = grandchild->leftchild;
		grandchild->leftchild = child;
		(*parent)->leftchild = grandchild->rightchild;
		grandchild->rightchild = *parent;
		switch(grandchild->bf){
			case 1:
				(*parent)->bf = -1;
				child->bf = 0;
				break;
			case 0:
				(*parent)->bf = 0;
				child->bf = 0;
				break;
			case -1:
				(*parent)->bf = 0;
				child->bf = 1;
		}
		*parent = grandchild;
	}
	(*parent)->bf = 0;
	*unbalanced = 0;
}
void right_rotation(Node **parent,int *unbalanced){
	Node *child, *grandchild;
	child = (*parent)->rightchild;
	if(child->bf == 1){
		// RR
		(*parent)->rightchild = child->leftchild;
		child->leftchild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else{
		// RL
		grandchild = child->leftchild;
		child->leftchild = grandchild->rightchild;
		grandchild->rightchild = child;
		(*parent)->rightchild = grandchild->leftchild;
		grandchild->leftchild = *parent;
		switch(grandchild->bf){
			case 1:
				(*parent)->bf = -1;
				child->bf = 0;
				break;
			case 0:
				(*parent)->bf = 0;
				child->bf = 0;
				break;
			case -1:
				(*parent)->bf = 0;
				child->bf = 1;
		}
		*parent = grandchild;
	}
	(*parent)->bf = 0;
	*unbalanced = 0;
}

void avlInsert(Node **parent, int x, int *unbalanced){
	if(!(*parent)){
		*unbalanced = 1;
		//*parent = (Node*)malloc(sizeof(Node));
		Malloc(parent,1);
		if(isFull(*parent)){
			fprintf(stderr,"fff");
			exit(1);
		}
		(*parent)->leftchild = NULL;
		(*parent)->rightchild = NULL;
		(*parent)->bf = 0;
		(*parent)->data = x;
	}
	else if (x < (*parent)->data){
		avlInsert(&(*parent)->leftchild,x,unbalanced); // unbalanced being a pointer in this scope
		if(*unbalanced){
			switch((*parent)->bf){
				case -1: 
					(*parent)->bf = 0;
					*unbalanced = 0;
					break;
				case 0:
					(*parent)->bf = 1;
					break;
				case 1:
					left_rotation(parent,unbalanced);
			}
		}
	}
	else if(x > (*parent)->data){
		avlInsert(&(*parent)->rightchild,x,unbalanced); // unbalanced being a pointer in this scope
		if(*unbalanced){
			switch((*parent)->bf){
				case -1: 
					(*parent)->bf = 0;
					*unbalanced = 0;
					break;
				case 0:
					(*parent)->bf = 1;
					break;
				case 1:
					right_rotation(parent,unbalanced);
			}
		}
	}
	else {
		*unbalanced = 0;
		printf("The is already in the tree");
	}
}

int main(void){
	return 0;
}
