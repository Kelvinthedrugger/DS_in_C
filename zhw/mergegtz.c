#include<stdio.h>
#include<stdlib.h>
#include<string.h> // for memcpy

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

typedef struct element element;
struct element{
	int key;
};

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

  printf("\ngtz merge: ");
  my_mergesort(aa,len);
  printarray(aa,len);

  printf("\n");
  return 0;
}
