#include<stdio.h>
#include<stdlib.h>

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}



typedef struct element element;
struct element{
  int key;
  int item;
};

int h(int);
element *hk(int);

void insert();
void deletes();
// since it's linear probing, we should only look at Program 8.3
element *search(int k);


int main(void){
  return 0;
}

