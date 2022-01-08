#include<stdio.h>
#include<stdlib.h>

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}




int main(void){
  printf("ff");


  printf("\n");
  return 0;
}

