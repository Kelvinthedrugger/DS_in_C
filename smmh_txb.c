// symmetric min max tree
// from textbook
#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 100
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
typedef struct {
	int key;
}element;

element heap[MAXLEN];
void show(element heap[], int n){
	int i;
	printf("idx: ");
	for(i = 1; i < n+1; i+=1){
		printf("%3d ",i);
	}
        printf("\nkey: ");	
	for(i = 1; i < n+1; i+=1){
		printf("%3d ",heap[i]);
	}
        printf("\n");	
}
void verifymax(element heap[], int i, element item);
void verifymin(element heap[], int i, element item);
int level(int ele); 
void minmaxInsert(element heap[], int *n, element item){
	int parent;
	(*n)++;
	if(*n == MAXLEN){
		fprintf(stderr,"flah");
		exit(1);
	}
	parent = (*n)/2;
	if(!parent)
		heap[1] = item;
	else switch(level(parent)){
		case 0: // min level
			if(item.key < heap[parent].key){
				heap[*n] = heap[parent];
				verifymin(heap,parent,item);
			}
			else{
				verifymax(heap,*n,item);
			}
			break;
		case 1: // max level
			if(item.key > heap[parent].key){
				heap[*n] = heap[parent];
				verifymax(heap,parent,item);
			}
			else{
				verifymin(heap,*n,item);
			}
	}
	level(parent)?printf("\nlevel: min\n"):printf("\nlevel: max\n");
}

void verifymax(element heap[], int i, element item){
	int grandparent = i/4;
	while(grandparent){
		if(item.key > heap[grandparent].key){
			heap[i] = heap[grandparent];
			i = grandparent;
			grandparent /= 4;
		}
		else
			break;
	}
	heap[i] = item;
}

void verifymin(element heap[], int i, element item){
	int grandparent = i/4;
	while(grandparent){
		if(item.key < heap[grandparent].key){
			heap[i] = heap[grandparent];
			i = grandparent;
			grandparent /= 4;
		}
		else
			break;
	}
	heap[i] = item;
}

int level(int h){
	// 1 if max, 0 if min level
	int exp = 0, base=1;
	while(base <= h){
		base *= 2;
		exp += 1;
	}
	return !(exp % 2);
}

int minChildGnd(element heap[], int nodeI, int len){
	// returns the child/grandchild of nodeI with smallest key

	// heap is globally defined douche
	/*
	int i;
	int minval;
       	minval = heap[nodeI*4].key;
	// travels on next min level
	// doesn't need to travel down even more as long as nodeI*8 < len
	// since it's been taken care of in deleteMin()
	for(i = nodeI*4; i < nodeI*8; i++){
		if(minval < heap[i].key)
			minval = heap[i].key;
	}
	*/
	return 0;
}

element deleteMin(element heap[], int *n){
	int i, last, k, parent;
	element temp, x;
	if(!(*n)){
		fprintf(stderr, "ff");
		heap[0].key = INT_MAX;// the error key in heap[0]
		return heap[0];
	}
	heap[0] = heap[1];
	x = heap[(*n)--];
	for(i = 1; last = (*n)/2; i <= last){
		k = minChildGnd(heap, i, *n);
		if(x.key <= heap[k].key)
			break;
		// case b or c
		heap[i] = heap[k];
		// b
		if(k <= 2*i + 1){
			i = k;
			break;
		}
		// c
		parent = k/2;
		if(x.key > heap[parent].key)
			SWAP(heap[parent],x,temp);
		i = k;
	}
	heap[i] = x;
	return heap[0];
}

void deleteMax(element heap[], int *n);

/* hw requirement
function has parenthesis
commands:
	insert(int x)
	delete_min()
	delete_max()
	show()
	quit: terminate program, has nothing to do with the tree
*/

// it works fk huge waste of time on tiny bug stupid closed interval
// page 435
int main(void){
	int n = 0;
	int i;
	int arr[] = {5,70,40,30,9,7,15};
	for(i = 0; i < 7; i++){
		printf("\nheap at epoch %d\n",i+1);
		element a;
		a.key = arr[i];
		minmaxInsert(heap,&n,a);
		show(heap,n);
	}
	return 0;
}

