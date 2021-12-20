// implementation of leftist tree from textbook
#include<stdio.h>
#include<stdlib.h>

typedef struct leftist* leftistTree;
struct leftist{
	leftistTree leftchild;
	leftistTree rightchild;
	int data; // type:: struct element in textbook
	int shortest;
};

leftistTree newNode(int num){
	leftistTree tnode = (leftistTree)malloc(sizeof(leftistTree));
	tnode->leftchild=NULL;
	tnode->rightchild=NULL;
	tnode->data=num;
	tnode->shortest=1;
	return tnode;
}

// this worked
# define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

/*
ops:
   insert: 
   	number to be inserted as a tree
	-> meld it with the original tree
   delete:
   	meld left and right child of the root node
	and remove the root node
*/
void minMeld(leftistTree* a, leftistTree* b);
void minUnion(leftistTree* a, leftistTree* b);
void printTree(leftistTree tree);
void preorder(leftistTree tree);
void inorder(leftistTree tree);
void printit(leftistTree root){
	printf("\npreorder: ");
	preorder(root);
	printf("\ninorder: ");
	inorder(root);
	printf("\nnode and shortest:\n");
	printTree(root);
}
int main(void){
	
	// tree are not identical to that in textbook
	// since the determination of tree
	// is not unique
	leftistTree root = newNode(2);
	int arr1[] = {50,7,11,13,80};
	int i;
	for(i = 0; i < 5; i++){
		leftistTree tmp = newNode(arr1[i]);
		minMeld(&root,&tmp);
	}

	printit(root);

	leftistTree root2 = newNode(5);
	int arr2[] = {8,9,12,20,18,10,15};
	for(i = 0 ; i < 7; i++){
		leftistTree tmp = newNode(arr2[i]);
		minMeld(&root2,&tmp);
	}
	printit(root2);

	minMeld(&root,&root2);
	printit(root);

	return 0;
}

void minMeld(leftistTree* a, leftistTree* b){
	if(!*a) *a = *b;
	else if(*b) minUnion(a,b);
	*b = NULL;
}

// as a helper function
void minUnion(leftistTree* a, leftistTree* b){
	leftistTree temp;
	if((*a)->data > (*b)->data)
		SWAP(*a,*b,temp);

	if(!(*a)->rightchild)
		(*a)->rightchild = *b;
	else 
		minUnion(&(*a)->rightchild,b);

	// leftist tree property
	// if x is not None
	// shortest(x.left) >= shortest(x.right)
	if(!(*a)->leftchild){
		(*a)->leftchild = (*a)->rightchild;
		(*a)->rightchild = NULL;
	}
	else if((*a)->leftchild->shortest < (*a)->rightchild->shortest)
		SWAP((*a)->leftchild,(*a)->rightchild,temp);

	(*a)->shortest = (!(*a)->rightchild) ? 1 : (*a)->rightchild->shortest+1;
}

void printTree(leftistTree tree){
	if(!tree) return;
	printf("%d %d\n",tree->data,tree->shortest);
	printTree(tree->leftchild);
	printTree(tree->rightchild);
}
void preorder(leftistTree tree){
	if(!tree) return;
	printf("%d ",tree->data);
	preorder(tree->leftchild);
	preorder(tree->rightchild);
}
void inorder(leftistTree tree){
	if(!tree) return;
	inorder(tree->leftchild);
	printf("%d ",tree->data);
	inorder(tree->rightchild);
}
