// AVL Tree (from txb) 
#include<stdio.h>
#include<stdlib.h>

#define isFull(ptr) (!(ptr))

// pls remove this and just use type int
typedef struct{
	int key;
}element;

typedef struct Node Node;
struct Node{
	Node *leftchild;
	element data;
	short int bf;
	Node *rightchild;
};

int unbalanced = 0;
Node *root = NULL;

void left_rotation(Node **parent,int *unbalanced){
	return;
}
void right_rotation(Node **parent,int *unbalanced){
	return;
}


void avlInsert(Node **parent, element x, int *unbalanced){
	if(!(*parent)){
		*unbalanced = 1;
		*parent = (Node*)malloc(sizeof(Node));
		if(isFull(*parent)){
			fprintf(stderr,"fff");
			exit(1);
		}
		(*parent)->leftchild = NULL;
		(*parent)->rightchild = NULL;
		(*parent)->bf = 0;
		(*parent)->data = x;
	}
	else if (x.key < (*parent)->data.key){
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
	else if(x.key > (*parent)->data.key){
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
		printf("The key is already in the tree");
	}
}

int main(void){
	return 0;
}
