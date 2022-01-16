#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define len 20 

// string i/o in C is difficult

int main(void){

	system("python -m make");

	return 0;
	char *filename = (char*)malloc(len*sizeof(char));

	char *s1 = "gcc ";
	char *ss = ".c ";
	char *s2 = "-o ";
	char *full = (char*)malloc(2*len*sizeof(char));
	full = s1;
	/*
	full + 10 = s2;
	*/
	puts(full);
	return 0;
	scanf("%[^\n]%*c",filename);
	
	strcat(filename,s1);
	puts(filename);
	return 0;
}
