// implement max/min heap from scratch
// max heap first
// remeber it's a complete binary tree !
//  with level order traversal fk
#include<stdio.h>
#include<stdlib.h>

#define mxlen 50

int *heap;
int n; // number of element of heap

void print_heap(){
	printf("heap: ");
	int i;
	for(i = 1; i < n+1; i++){
		printf("%d ",heap[i]);
	}
	printf("\n");
}

/*
 n = 0;

insert: 
 n = 1
 i = 1: not looped
 heap[i] = n1
index: 0  1  2  3 
field: - n1 n2 n3
 */
void insert_heap(int ele){
	n += 1;
	int i = n;
	printf("increased n: %d, i: %d\n",n,i);
	while(ele > heap[i/2] && i != 1){
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = ele;
}

int pop_from_heap(){

	int parent = 1, child = 2;
	n -= 1;
	int ans = heap[parent];
	while(child <= n){
		if(child < n && heap[child] < heap[child+1]){
			child += 1;
		}
		if(heap[n] >= heap[child]){
			break;
		}
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = heap[n+1];
	return ans;
}

void change_priority(int ele, int idx){
	// change arbitrary node value and adjust the position of the heap
	return;
}

int main(void){

	n = 0;
	heap = (int*)malloc(mxlen*sizeof(int));
	insert_heap(1);
	print_heap();
	insert_heap(3);
	print_heap();
	insert_heap(5);
	print_heap();
	insert_heap(2);
	print_heap();
	insert_heap(4);
	print_heap();
	insert_heap(6);
	print_heap();
	int ans = pop_from_heap();
	printf("ans: %d ",ans);
	print_heap();

	return 0;
}

// example
/*
int pop(){
	int parent, child;
	int item = heap[1], temp = heap[n--];
	parent = 1;
	child = 2;
	while(child <= n){
		if(child < n && heap[child] < heap[child+1])
			child++;
		if(temp >= heap[child])
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
*/
