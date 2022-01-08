#include<stdio.h>
#include<stdlib.h>

#define Malloc(p,s) if(!((p)=malloc(sizeof(*(p))*(s)))) exit(EXIT_FAILURE)

typedef struct patriciaTree *patricia;
struct patriciaTree{
  int bitno;
  int data; // element data
  patricia left, right;
};

patricia root;


unsigned int int_to_int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
}

int pows(int a, int b){
  int i;
  int base = a;
  for(i = 1; i < b; i++){
    a *= base;
  }
  return a;
}

unsigned int logs(unsigned num){
  unsigned int i = 0;
  int base = 1;
  while(base < num){
    base *= 10;
    i += 1;
  }
  return i;
}

int bit(unsigned k, int bitno){
  // return 1 or 0
  // returns the kth bit of the key k
  // aka kth bit of bitnumber ?

  // convert bit number to binary representation
  // , use Xor (binary ops) ?
  /*
    then for loop
    int i;
    for(i = 0; i < length of bitno in binary; i++){
      if (ith answer of XOR == 1)
        return i;
    }
    // else
    return 0;
  */

  // or for loop:
  // k starts from 1
  // count kth bit

  // return kth bit 
  unsigned newk = int_to_bit(k);
  int exp = logs(newk);

  // get kth bit == 1
  int ans  = newk / pows(10,logs(newk));
  while (ans != 1){
    // remove the highest digit
    newk -= pows(10,logs(newk));
    ans  = newk / pows(10,logs(newk));
  }
  
  return 0;
}

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

void deleteNode(int key);


int main(void){
  return 0;
}

