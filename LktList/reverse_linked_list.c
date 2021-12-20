/* Worked!
 * time complexity: O(n), use recursion
 * space complexity; 0, didn't use any local/global variable
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node{
	int data;
	Node* next;
};

Node* newNode(int num){
	Node* tnode = (Node*)malloc(sizeof(Node));
	tnode->data = num;
	tnode->next = NULL;
	return tnode;
}

typedef struct SinglyLinkedList SinglyLinkedList;
struct SinglyLinkedList{
	Node* head;
};

SinglyLinkedList* newlinkedlist(Node* head){
	SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	list->head = head;
	return list;
}

void dfs(Node* node,SinglyLinkedList* list){
	if(node->next == NULL){
		list->head = node;
		return;
	}
	else
		dfs(node->next,list);
	node->next->next = node;
	node->next = NULL;
}

void reverse_linked_list(SinglyLinkedList* list){
	dfs(list->head,list);
}

void print_list(Node* node){
	Node** tmp = &node;
	while(*tmp!= NULL){
		printf("%d ",(*tmp)->data);
		tmp = &(*tmp)->next;
	}
}

int main(void){
	Node* node1 = newNode(1);
	Node* node2 = newNode(2);
	Node* node3 = newNode(3);

	node1->next = node2;
	node2->next = node3;

	SinglyLinkedList *list1 = newlinkedlist(node1);

	printf("list: ");
	print_list(list1->head);

	printf("\nreversed: ");
	reverse_linked_list(list1);
	print_list(list1->head);


	return 0;
}
