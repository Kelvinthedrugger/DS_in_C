#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int num){
	Node* tnode = (Node*)malloc(sizeof(Node));
	tnode->data = num;
	tnode->left = NULL;
	tnode->right = NULL;
	return tnode;
}

void preorder(Node *node){
	if(node == NULL) return;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node *node){
	if(node == NULL) return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}

typedef struct BinaryTree BinaryTree;
struct BinaryTree{
	Node *root;
};
BinaryTree *newTree(Node *root){
	BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	tree->root = root;
	return tree;
}

void swap_node();

void dfs(Node *node, BinaryTree *tree){
	if(node == NULL) return;
	swap_node(&(node->left),&(node->right));
	dfs(node->left,tree);
	dfs(node->right,tree);
}

void reverse_tree(BinaryTree *tree){
	dfs(tree->root, tree);
}

int main(void){
	Node *node1 = newNode(1);
	BinaryTree *tree = newTree(node1);
	printf("%d",tree->root->data);
	

	return 0;
}

