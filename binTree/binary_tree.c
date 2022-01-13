// binary tree ssss
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int value) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void build_tree(struct Node* root,struct Node* node){
	if(root->data > node->data){
		if(root->left == NULL){
			root->left = node;
			return;
		}
		build_tree(root->left,node);	
	}
	if(root->data < node->data){
		if(root->right == NULL){
			root->right = node;
			return;
		}
		build_tree(root->right,node);	
	}
}

void preorder(struct Node* node){
	if(node == NULL) return;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}

void postorder (struct Node* node){
	if(node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
}
void print_tree(struct Node* root){
	printf("\npreorder\n");
	preorder(root);
	printf("\npostorder\n");
	postorder(root);
	printf("\n");
}
typedef struct StackNode{
	struct Node* tree_node;//pass by reference
	struct StackNode* next;
};

struct StackNode* newStackNode(struct Node* tree_node){
	struct StackNode* stacknode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stacknode->tree_node = tree_node;// points to the address
	stacknode->next = NULL;
	return stacknode;
}

void normal();
void weird_tree(){
	int inputs[] = {1,2,3,-1,-1,4};
	
	struct Node* root = newNode(inputs[0]);
	struct Node* node1 = newNode(inputs[1]);
	root->left = node1;
	// need to implement stack to store the branch points
	struct StackNode* head = newStackNode(root);
	printf("%d\n",head->tree_node->data); // value is correct
	printf("%u,  %u",root,&(head->tree_node));// head->tree_node = root + 32
	struct StackNode* b1 = newStackNode(node1);
	printf("%d\n ",b1->tree_node->data);
	print_tree(root);
}

int main(void){

	//normal();
	weird_tree();


	return 0;
}
void normal(){

	int arr[] = {3,4,1,2,6,7,5};
	
	int i;
	struct Node* root = newNode(arr[0]);
	printf("%d %u %u\n",root->data,root->left,root->right);
	for(i = 1; i < 7; i++)
		build_tree(root,newNode(arr[i]));
	
	printf("preorder\n");
	preorder(root);
	printf("\npostorder\n");
	postorder(root);
	printf("\n");
	
}
