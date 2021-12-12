// AVL Tree (from txb mostly)
// aka binTree ver of red-black tree ?
#include<stdio.h>
#include<stdlib.h>

#define isFull(ptr) (!(ptr))

typedef struct Node Node;
struct Node{
	Node *leftchild;
	int data;
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

void avlInsert(Node **parent, int x, int *unbalanced){
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
	// overflow ? 
	Node *root = NULL;
	avlInsert(&root, 2, 0);
	printf("%d",root->data);
	return 0;
}
