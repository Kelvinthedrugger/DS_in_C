for(;epoch < 5; epoch++){
    
    // insertion sort
    start_t = clock();

    element *ins_arr = get_array(epoch, nn[epoch]);
    s1(ins_arr, nn[epoch]);

    end_t = clock();
    total1 = (double)(end_t - start_t)/CLOCKS_PER_SEC;

    // quick sort
    start_t = clock();

    element *q_arr = get_array(epoch, nn[epoch]);
    s12(q_arr, nn[epoch]);

    end_t = clock();
    total2 = (double)(end_t - start_t)/CLOCKS_PER_SEC;

    // merge
    start_t = clock();

    element *m_arr = get_array(epoch, nn[epoch]);
    s13(m_arr, nn[epoch]);

    end_t = clock();
    total3 = (double)(end_t - start_t)/CLOCKS_PER_SEC;

    // heap
    start_t = clock();

    element *h_arr = get_array(epoch, nn[epoch]);
    s14(h_arr, nn[epoch]);

    end_t = clock();
    total4 = (double)(end_t - start_t)/CLOCKS_PER_SEC;
   
    
    // store result
    result[j] = total1;
    result[j+1] = total2;
    result[j+2] = total3;
    result[j+3] = total4;

    j += 4;
  }


void println(){printf("\n");}
void s1(element *aa, int len){
  //println();
  //printarray(aa, len);
  //printf("insertion sort:\n");
  insertionSort(aa,len-1);
  //printarray(aa,len);

}

void s12(element *aa, int len){
  // println(); 
  //printarray(aa, len);
  //printf("quick sort:\n");
  quickSort(aa,1,len-1);
  //printarray(aa,len);

}
void s13(element *aa, int len){
  //println();
  //printarray(aa, len);
  //printf("merge sort:\n");
  my_mergesort(aa,len);
  //printarray(aa,len);
}
void s14(element *aa, int len){
  //println();
  //printarray(aa, len);
  //printf("heap sort:\n");
  heapSort(aa,len);
  //printarray(aa,len+1);
}



/*
void s2(){
  int a[] = {0,5,9,1,6,4,7,8,3,2};
  //int a[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(a)/sizeof(int);

	element aa[len];
	int i;
	for(i = 0; i < len ; i++){
		aa[i].key = a[i];
	}

  printf("\nquick sort:\n");
  quickSort(aa, 1, len-1);
  printarray(aa,len);   


}

void s3(){
  int a[] = {0,5,9,1,6,4,7,8,3,2};
  //int a[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(a)/sizeof(int);

	element aa[len];
	int i;
	for(i = 0; i < len ; i++){
		aa[i].key = a[i];
	}
  printf("\nmerge sort:\n");
  // somehow mergesort overflows
  //mergeSort(aa, len);
  // let's use geohotz's
  my_mergesort(aa,len);
  printarray(aa,len);   
}
void s4(){
  int a[] = {0,5,9,1,6,4,7,8,3,2};
  //int a[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(a)/sizeof(int);

	element aa[len];
	int i;
	for(i = 0; i < len ; i++){
		aa[i].key = a[i];
	}
  printf("\nheap sort:\n");
  heapSort(aa,len);
  printarray(aa,len+1);   
	
}

void debug(){
//    s1();
    s2();
    s3();
    s4();
}
*/


