// generate random numbers
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

// for validation, since it's the most stable one so far
// insertion sort
void insert(element e, element a[], int i){
	a[0] = e;
	while(e.key < a[i].key){
		a[i+1] = a[i];
		i -= 1;
	}
	a[i+1] = e;
}
void insertionSort(element a[], int n){
	int j;
	for(j = 2; j <= n; j++){
		element temp = a[j];
		insert(temp,a,j-1);
	}
}

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
You are required to submit a report that states the
1. clock accuracy

2. the number of random permutations tried for heap sort

3. The worst-case data for merge sort and how you generated it

4. A table of times for the above values of , the times for the narrowed ranges, the graph, and
a table of times for the composite function.

5. In addition, your report must be accompanied by a 
    complete listing of the program used by you
  (this includes the sorting functions and the 
    main program for timing and test-data)
*/


int main(void){
  int r; 
  int i;
  for(i = 0; i < 10; i++){
    r = rand() % 500;
    printf("i: %d, r: %d\n",i, r);
  }
  return 0;
}

