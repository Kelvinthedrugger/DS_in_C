// hw version
#include<stdio.h>
#include<stdlib.h>
#include<string.h> // since bit number utilizes string

#define Malloc(p,s) if(!((p)=malloc(sizeof(*(p))*(s)))) exit(EXIT_FAILURE)

typedef struct patriciaTree *patricia;
struct patriciaTree{
  char *bitno;
  int data; // element data
  patricia left, right;
};

unsigned int stringToInt(char *key){
  int number = 0;
  while(*key){
    number += *key;
    *key += 1;
  }
  return number;
}

// use atoi() to convert char *bitno into int::bitnumber ?
int bit(int key, int bitnumber);


// declares one key-val insertion
void insertTree(char *key, int value);

// one key search op
patricia search(char *key);

// one key-value deletion
void deletefromTree(char *key);

// quit(): exit the program, just use if-else in main()

int main(void){
  int ops;
  /*
  scanf("%d",&ops);
  int i;
  for(i = 0; i < ops; i++){
    char *cmd; 
    Malloc(cmd,7);
    scanf("%[^\n]s",cmd);
    if(strcmp(cmd,"insert") == 0){
      printf("insert -> ");
    }
    else if(strcmp(cmd,"search" == 0){
       printf("search -> ");   
    }
    else if(strcmp(cmd,"delete" == 0){
          printf("delete -> ");
    }
    else if(strcmp(cmd,"quit" == 0)){
      break;
    }

  }

  */

  return 0;
}
