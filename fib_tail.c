// fibanacci series using tail recursion
#include<stdio.h>
#include<stdlib.h>

int fib(int n, int a, int b){
	if(n == 0) return a;
	return fib(n-1,b,a+b);
}

int main(void){

	int n = 5; // 0,1,1,2,3,5,...
	printf("%d",fib(n,0,1));

	return 0;
}
