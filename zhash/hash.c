// just check out hashg.c
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
element *ht(int);

void insert();
void deletes();
// since it's linear probing, we should only look at Program 8.3
element *search(int k){
  int home, cur;
  home = h(k);
  for(cur = home; ht[cur] && ht[cur]->key != k;){
    cur = (cur + 1) % b;
    if(cur == home){
      return NULL;
    }
  }
  if(ht[cur]->key == k){
    return ht[cur];
  }
  return NULL;
}

int main(void){
  return 0;
}

