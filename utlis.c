// useful macros and functions for avoiding re-typing everything
#include<stdio.h>
#include<stdlib.h>

// Memory allocation
#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define Calloc(p,n) \
	if(!((p) = calloc(n, sizeof(*(p))))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

#define Realloc(p,n) \
	if(!((p) = realloc((p),sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// useful stuff
# define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
// w/o tmp var ver. for basic types
void swap(int *a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

# define Compare(x,y)((x)>(y)?1:(x)==(y)?0:-1)

#define isFull(ptr) (!(ptr))


// string to int
unsigned int stringToInt(char *key){
  int number = 0;
  while(*key){
    number += *key;
    *key += 1;
  }
  return number;
}

unsigned int stringToInt2(char *key){
  int number = 0;
  while(*key){
    number += *key;
    *key += 1;
    if(*key){
      number += ((int) *key) << 8;
      *key += 1;
    }
  }
  return number;
}

unsigned int int_to_bit(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bit(k / 2)));
}

int pows(int a, int b){
  int i;
  int base = a;
  for(i = 1; i < b; i++){
    a *= base;
  }
  return a;
}

// to pass compiling process
int main(void){
	printf("\nrun passed");
  printf("\n%d -> %d", 8, int_to_int(8));
  int a = 2, b = 20;
  printf("\n %d ** %d = %d", a, b, pows(a,b));
  printf("\n");
	return 0;
}
