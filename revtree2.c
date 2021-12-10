// swap tree but simpler

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int num){
	Node *tnode = (Node*)malloc(sizeof(Node));
	tnode->data = num;
	tnode->left = NULL;
	tnode->right = NULL;
	return tnode;
}
void preorder(Node *node);
void inorder(Node *node);
void print_tree(Node *node);
Node **stack;
int top;
void init_stack(int size){
	top = -1;
	stack = (Node**)malloc(size*sizeof(Node*));
}
void push(Node *node){
	top += 1;
	*(stack+top) = node;
}
Node *view(){
	return *(stack+top);
}
void pop(){
	top -= 1;
}
int isempty(){
	return (top == -1);
}
void fill_in(Node *tbd){
	Node *cur = view();
	if(!cur->left){
		cur->left = tbd;
		if(tbd->data != -1){
			push(tbd);
		}
		return;
	}
	else if(!cur->right){
		cur->right = tbd;
		if(tbd->data != -1){
			push(tbd);
		}
		return;
	}
	else{
		pop();
		fill_in(tbd);
	}
}
Node *create(int *arr,int len){
	Node *root = newNode(*arr);
	push(root);
	// insert other ele in arr
	int i;
	for(i = 1; i < len; i++){
		Node *tbd = newNode(*(arr+i));
		fill_in(tbd);
	}
	return root;
}
void ss(Node **le, Node **rr){
	Node *tmp = newNode(-2);
	tmp->left = *le;
	*le = *rr;
	*rr = tmp->left;
	free(tmp);
}
void reverse(Node *root){
	if(!root) return;
	ss(&root->left,&root->right);
	reverse(root->left);
	reverse(root->right);
}
void print_arr(int *arr,int len);
void print_stack();
int *input;
// 13
// 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
int main(void){
	int n;
	scanf("%d",&n);
	input = (int*)malloc(n*sizeof(int));
	init_stack(n);

	int i;
	for(i = 0; i < n; i++){
		scanf("%d",input+i);
	}
	Node *root = create(input,n);
	print_tree(root);

	printf("\nshould be reversed\n");
	reverse(root);
	print_tree(root);
	
	return 0;
}

void preorder(Node *node){
	if(!node) return;
	if(node->data!=-1){
		printf("%d ", node->data);
	}
	preorder(node->left);
	preorder(node->right);
}
void inorder(Node *node){
	if(!node) return;
	inorder(node->left);
	if(node->data!=-1){
		printf("%d ",node->data);
	}
	inorder(node->right);
}
void print_tree(Node *root){
	printf("preorder:\n");
	preorder(root);
	printf("\ninorder:\n");
	inorder(root);
	printf("\n");
}
void print_arr(int *arr, int len){
	printf("array: ");
	int i;
	for(i = 0; i<len;i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
void print_stack(){
	printf("stack vals: ");
	int i;
	for(i = 0; i < top; i++){
		printf("%d ", (*(stack+i))->data);
	}
	printf("\n");
}
