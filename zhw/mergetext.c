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
	int i, j;
	for(i = 1; i <= n-2*s+1; i += 2*s){
		merge(initList, mergedList, i, i+s-1, i + 2*s -1);
	}
	if(i + s - 1 > n){
		merge(initList, mergedList, i, i+s-1, n);
	}
	else{
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


