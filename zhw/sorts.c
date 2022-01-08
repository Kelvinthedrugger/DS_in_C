// from textbook
// check typing again 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // for memcpy

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct element element;
struct element{
	int key;
};

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

// quick sort
void quickSort(element a[], int left, int right){
	int pivot, i, j;
	element temp;
	if(left < right){
			i = left;
			j = right + 1;
      pivot = a[left].key;
			do{
				do i++; while(a[i].key < pivot);
				do j-=1; while(a[j].key > pivot);
				if(i < j) SWAP(a[i],a[j],temp);
			}while(i < j);
		
		SWAP(a[left],a[j],temp);
		quickSort(a,left,j-1);
		quickSort(a,j+1,right);
	}
}



// merge sort
// so troublesome compare with geohotz's solution
// george hotz
void my_mergesort(element *arr, int len) {
  //printf("%p %d\n", arr, len);
  if (len == 1) { return; }
  if (len == 2) {
    if (arr[0].key > arr[1].key) {
      /*
      int t = arr[1];
      arr[1] = arr[0];
      arr[0] = t;*/
      element t;
      SWAP(arr[0],arr[1],t);
    }
  }

  int p = len/2;
  element *arr1 = arr;
  element *arr2 = arr+p;

  my_mergesort(arr1, p);
  my_mergesort(arr2, len-p);

  element *t = malloc(sizeof(int)*len);
  element *rt = t;
  while (1) {
    if (arr1 < arr+p && arr2 < arr+len) {
      if (arr1[0].key <= arr2[0].key) {
        *t = *arr1;
        arr1++;
      } else {
        *t = *arr2;
        arr2++;
      }
    } else if(arr1 < arr+p) {
      *t = *arr1;
      arr1++;
    } else if(arr2 < arr+len) {
      *t = *arr2;
      arr2++;
    } else {
      break;
    }
    t++;
  }

  memcpy(arr, rt, sizeof(element)*len);
  free(rt);
}
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

void permute(element a[], int n){
	// random permutation generator
	int i,j;
	element temp;
	for(i = n; i >= 2; i--){
		j = rand() % i + 1;
		SWAP(a[j],a[i],temp);
	}
}
//void printarray(int *arr, int len){
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
	
  printarray(aa, len);
  printf("\ninsertion sort:\n");
  insertionSort(aa,len-1);
  printarray(aa,len);
  printf("\nquick sort:\n");
  quickSort(aa, 1, len-1);
  printarray(aa,len);   
  // above done
  printf("\nmerge sort:\n");
  // somehow mergesort overflows
  //mergeSort(aa, len);
  // let's use geohotz's
  my_mergesort(aa,len);
  printarray(aa,len);   

  printf("\nheap sort:\n");
  heapSort(aa,len-1);
  printarray(aa,len);   
	
  return 0;

}
