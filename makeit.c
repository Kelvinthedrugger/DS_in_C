// dump way to do make on windows
// and it turned out to be slow
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// should we add run?
//  .. && filename.exe
int main(void){
	int len = 20;
	char name[len];
	scanf("%[^\n]",name);
	printf("%s",name);
	char c1[len];
	c1[0] = 'g';
	c1[1] = 'c';
	c1[2] = 'c';
	c1[3] = ' ';
	c1[len-1] = '\0';
	printf("%s",c1);
	char namm[len];
	strcpy(namm,name);

	// add run
	char nrun[len];
	strcpy(nrun,name);

	strcat(c1,name);
	printf("\n%s",c1);
	char c2[len];
	c2[0] = '.';
	c2[1] = 'c';
	c2[2] = ' ';
	c2[3] = '-';
	c2[4] = 'o';
	c2[5] = ' ';
	c2[len-1] = '\0';
	strcat(c2,namm);
	printf("\n%s",c2);
	strcat(c1,c2);
	printf("\n%s",c1);
	//system(c1);
	char crun[len];
	crun[0] = ' ';
	crun[1] = '&';
	crun[2] = '&';
	crun[3] = ' ';
	crun[len-1] = '\0';
	strcat(crun,nrun);

	strcat(c1,crun);
	printf("\n%s\n",c1);
	system(c1);
	return 0;
}
