// useful macros and functions for avoiding re-typing everything
#include<stdio.h>
#include<stdlib.h>

# define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))


// w/o tmp var ver. for basic types
void swap(int *a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

// to pass compiling process
int main(void){
	return 0;
}
