#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct element element;
struct element{
	int key;
};

// heap sort
// use max heap
void adjust(element a[], int root, int n){
	element temp;
	temp = a[root];
	int rootkey = a[root].key;
	int child = 2*root;
	while(child <= n){
		if((child < n) && (a[child].key < a[child+1].key)){
			child ++;
		}
		if(rootkey > a[child].key){
			break;
		}
		else{
			a[child/2] = a[child];
			child *= 2;
		}
	}
	a[child/2] = temp;
}
// perform sort on a[1:n]
void heapSort(element a[], int n){
	int i,j;
	element temp;
	for(i = n/2; i > 0; i--){
		adjust(a,i,n);
	}
	for(i = n - 1; i > 0; i--){
		SWAP(a[1],a[i+1],temp);
		adjust(a,1,i);
	}
}

void printarray(element *arr, int len){
    printf("length: %d\n", len-1);
    int i;
    for(i = 1; i < len; i++)
        printf("%d ",arr[i].key);
    printf("\n");
}


int main(void){
int a[] = {0,5,9,1,6,4,7,8,3,2};
  //int a[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(a)/sizeof(int);

	element aa[len];
	int i;
	for(i = 0; i < len ; i++){
		aa[i].key = a[i];
	}
  printarray(aa,len);
  printf("\nheap sort:\n");
  heapSort(aa,len);
  printarray(aa,len+1);   
	
  return 0;

}
