#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct element element;
struct element{
	int key;
};

void permute(element a[], int n){
	// random permutation generator
	int i,j;
	element temp;
	for(i = n; i >= 2; i--){
		j = rand() % i + 1;
		SWAP(a[j],a[i],temp);
	}
}
/*
// come back at 19:00?
create element a[n], n = 500, 1000, ...
 and insert numbers (just insert from 1 to n-1)

call permute(a, len)

tic time // use clock_t ?  
  whatever sort(a,len);
toc time

do the report
*/

void printarray(element *arr, int len){
    printf("length: %d\n", len);
    int i;
    for(i = 0; i < len; i++)
        printf("%d ",arr[i].key);
    printf("\n");
}

int main(void){
  // int lens[] = {500, 1000, ..};
  int n = 500;
  element a[n];
  int i;
  for(i = 0 ; i < n; i++){
    a[i].key = i+1;
  }
  // timeit % !!!
  // Sort(a,lenght);
  printarray(a,n);
  
  
  return 0;
}
