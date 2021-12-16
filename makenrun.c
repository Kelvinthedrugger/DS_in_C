// 1st call of this program: compile the C file and run the executable
//  and saves the full command of compile & run in a C file
//  so that the next time one can just run "makenrun filename" 
//  in the cmd prompt to compile and run the file on windows
//   which is not something new on unix-like system qq

# include<stdio.h>
# include<stdlib.h>
# include<string.h>

int main(void){
	int len = 100; // max file name length, can be changed manually
	// gcc filename.c -o filename && filename
	char name[len], name1[len], name2[len];
	scanf("%[^\n]",name);
	
	strcpy(name1,name);
	strcpy(name2,name);

	char c1[len];
	c1[0] = 'g';
	c1[1] = 'c';
	c1[2] = 'c';
	c1[3] = ' ';
	c1[len-1] = '\0';
	
	strcat(c1,name);


	char c2[len];
	c2[0] = '.';
	c2[1] = 'c';
	c2[2] = ' ';
	c2[3] = '-';
	c2[4] = 'o';
	c2[5] = ' ';
	c2[len-1] = '\0';
	
	strcat(c2,name1);
	strcat(c1,c2);
	

	char c3[len];
	c3[0] = ' ';
	c3[1] = '&';
	c3[2] = '&';
	c3[3] = ' ';
	c3[len-1] = '\0';
	
	strcat(c3,name2);
	strcat(c1,c3);

	printf("cmd: %s",c1);
	
	// write the file
	// i got entangled up since i stay up late for too much
	FILE *cmdfile;
	// problem: c1 is not the suitable filename
	// plus, filename should be specified type. e.g. yours.c 
	cmdfile = fopen(c1,"w");

	fprintf(cmdfile,"%s","\
		#include<stdlib.h>\
		int main(void){\
			system(");
	fprintf(cmdfile,"%s",c1);
	
	fprintf(cmdfile,"%s","\
		)\
		return 0;\
		}\
		");

	fprintf(cmdfile,"%s",c1);
	fclose(cmdfile);

	return 0;
}
