// from textbook
// check typing again 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // for memcpy

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

// insertion sort
// 1 to n
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
// 1 to n
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
// 1 to n
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

// perform sort on a[1:n]
// actually 0 to n
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

void permute(element a[], int n){
	// random permutation generator
	int i,j;
	element temp;
	for(i = n; i >= 2; i--){
		j = rand() % i + 1;
		SWAP(a[j],a[i],temp);
	}
}

element *get_array(int epoch, int len){
  element *aa;
  Malloc(aa,len);
  // length might be a problem
  int i;
	for(i = 0; i < len ; i++){
		aa[i].key = i;
	}
  permute(aa,len);
  return aa;
}

void solve(){
  int epoch = 0;
  int nn[] = {500,1000,2000,3000,4000};
  clock_t start_t, end_t;
  double total1, total2, total3, total4;

  double result[20] = {};
  int j = 0;  

  for(;epoch < 5; epoch ++){
    element *arr = get_array(epoch, nn[epoch]);
    
    start_t = clock();
    insertionSort(arr, nn[epoch]-1);
    end_t = clock();
    total1 = (double)(end_t - start_t)/CLOCKS_PER_SEC;
 

    //arr = get_array(epoch, nn[epoch]);
    permute(arr,nn[epoch]);
    start_t = clock();
    quickSort(arr, 1, nn[epoch]-1);
    end_t = clock();
    total2 = (double)(end_t - start_t)/CLOCKS_PER_SEC;

    //arr = get_array(epoch, nn[epoch]);
    permute(arr,nn[epoch]);
    start_t = clock();
    my_mergesort(arr, nn[epoch]);
    end_t = clock();
    total3 = (double)(end_t - start_t)/CLOCKS_PER_SEC;
    
    //arr = get_array(epoch, nn[epoch]);
    permute(arr,nn[epoch]);
    start_t = clock();
    heapSort(arr, nn[epoch]);
    end_t = clock();
    total4 = (double)(end_t - start_t)/CLOCKS_PER_SEC;

    result[j] = total1;
    result[j+1] = total2;
    result[j+2] = total3;
    result[j+3] = total4;
    j += 4;

  }

  // print result
  printf("\n");
  int k;
  for(k = 0; k < j; k += 4){
   printf("n = %d\n", nn[(k+4)/5]);
   printf("time of insertion sort: %lf\n", result[k]);  
   printf("time of quick sort:     %lf\n", result[k+1]);
   printf("time of merge sort:     %lf\n", result[k+2]);
   printf("time of heap sort:      %lf\n", result[k+3]);
   printf("\n");
  }
}

int main(void){
    solve();
    return 0;
}
