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

// to pass compiling process
int main(void){
	printf("\nrun passed");
	return 0;
}
