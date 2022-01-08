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

patricia t;

// string to int
unsigned int stringToInt(char *key){
  int number = 0;
  while(*key){
    number += *key;
    *key += 1;
  }
  return number;
}

unsigned int int_to_bit(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bit(k / 2)));
}
// use atoi() to convert char *bitno into int::bitnumber ?
int bit(int key, char *bitnumber);

// declares one key-val insertion
void insertTree(char *key, int value);

/*
void insertNode(patricia *t, int key){
  patricia cur, parent, last, rok;// rookie
  if(!(*t)){
    Malloc(*t,1);
    (*t)->bitno = 0;
    (*t)->data = key;
    (*t)->left = *t;
  }
  last = search(*t, key);
  if(key == last->data){
    fprintf(stderr,"The key is in the tree. Insertion fails.\n");
    exit(1);
  }
  // finds the 1st bit that's differ
  int i;
  for(i=1; bit(key,i) == bit(last->data, i); i++);

  // search tree using the first i-1 bits
  cur = (*t)->left; 
  parent = *t;
  while(cur->bitno > parent->bitno && cur->bitno < i){
    parent = cur;
    cur = (bit(key, cur->bitno))?cur->right:cur->left;
  }

  // insert key as child of parent
  Malloc(rok, 1);
  rok->data = key;
  rok->left = (bit(key,i))  ? cur:rok;
  rok->right = (bit(key,i)) ? rok:cur;
  if(cur == parent->left){
    parent->left = rok;
  }
  else{
    parent->right = rok;
  }
}
*/

// one key search op
patricia search(int key){
  patricia cur, nxt;
  if(!t){
    return NULL; // empty tree
  }
  nxt = t->left;
  cur = t;
  while(nxt->bitno > cur->bitno){
    cur = nxt;
    nxt = (bit(key,nxt->bitno)) ? nxt->right:nxt->left;
  }
  return nxt;
}
/*
patricia search(patricia t, unsigned k){
  patricia cur, nxt;
  if(!t){
    return NULL; // empty tree
  }
  nxt = t->left;
  cur = t;
  while(nxt->bitno > cur->bitno){
    cur = nxt;
    nxt = (bit(k,nxt->bitno)) ? nxt->right:nxt->left;
  }
  return nxt;
}
*/
// one key-value deletion
void deletefromTree(char *key);

// quit(): exit the program, just use if-else in main()

int main(void){
  int ops;
  scanf("%d",&ops);
  int i;
  for(i = 0; i < ops; i++){
    char *cmd; 
    Malloc(cmd,7);
    scanf("%[^\n]s",cmd);
    if(strcmp(cmd,"insert") == 0){
      printf("insert -> ");
    }
    else if(strcmp(cmd,"search")== 0){
       printf("search -> ");   
    }
    else if(strcmp(cmd,"delete")== 0){
          printf("delete -> ");
    }
    else if(strcmp(cmd,"quit") == 0){
      break;
    }
  }
  return 0;
}
