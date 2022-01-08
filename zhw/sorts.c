// from textbook
#include<stdio.h>
#include<stdlib.h>

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
		while(left < right){
			i = left;
			j = right + 1;
			do{
				do i++; while(a[i].key < pivot);
				do j-=1; while(a[j].key > pivot);
				if(i < j) SWAP(a[i],a[j],temp);
			}while(i < j);
		}
		SWAP(a[left],a[j],temp);
		quickSort(a,left,j-1);
		quickSort(a,j+1,right);
	}
}

// merge sort
// so troublesome compare with geohotz's solution
#define MAX_SIZE 100

// merge 2 sorted list
void merge(element initList[], element mergedList[], int i, int m, int n){
	int j = m+1, k=i, t;
	while(i <= m && j <= n){
		if(initList[i].key <= initList[j].key){
			mergedList[k++] = initList[i++];
	}
		else{
			mergedList[k++] = initList[j++];
		}
	}
	if(i < m){
		for(t = j; t <= n; t++){
			mergedList[t] = initList[t];
		}
	}
	else{
		for(t = i; t <= m; t++){
			mergedList[k+t-i] = initList[t];
		}
	}
}

void mergePass(element initList[], element mergedList[], int n, int s){
	int i;
	for(i = 1; i <= n-2*s+1; i += 2*s){
		merge(initList, mergedList, i, i+s-1, i + 2*s -1);
	}
	if(i + s - 1 > n){
		merge(initList, mergedList, i, i+s-1, n);
	}
	else{
		int j;
		for(j = i; j <= n; j++){
			mergedList[j] = initList[j];
		}
	}
}


void mergeSort(element a[], int n){
	int s = 1;
	element extra[MAX_SIZE];
	while(s < n){
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;
	}
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
void heapsort(element a[], int n){
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

void printarray(int *arr, int len){
    printf("length: %d\n", len);
    int i;
    for(i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(void){
	int a[] = {5,9,1,3,4,6,6,3,2};
	int len = sizeof(a)/sizeof(int);
	
    printarray(a, len);
    
	return 0;

}
