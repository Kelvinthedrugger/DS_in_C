#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef struct Node{
	int data;
	Node* next;
};

void remove_list_node(List* list,Node* target);

int main(void){
	
	return 0;
}

void remove_list_node(List* list, Node* target){
	Node** indirect = &list->head;
	while(*indirect != target)
		indirect = &(*indirect)->next;
	*indirect = target->next;
}

