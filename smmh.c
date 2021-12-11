// symmetric min max tree
#include<stdio.h>
#include<stdlib.h>

/*
function has parenthesis
commands:
	insert(int x)
	delete_min()
	delete_max()
	show()
	quit: terminate program, has nothing to do with the tree
*/
#define arrlen 32 // max heap size + 1

void swap(int *a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

// still a complete binary tree
int *heap;
int top;

void insert(int x);
void deletemin();
void deletemax();
void show(int *heap);

void init_heap(int *heap){
	heap = (int*)malloc(sizeof(arrlen));
	top = 0;
}

int main(void){
	init_heap(heap);
	return 0;
}
