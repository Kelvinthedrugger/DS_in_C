// from https://github.com/jamesroutley/write-a-hash-table/tree/master/02-hash-table
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct element element;
struct element{
  int key;
  int item;
};

element *new_ht_ele(int k, int v){
  element *i;
  Malloc(i,1);
  i->key = k;
  i->item = v;
  return i;
}

typedef struct ht_table ht_table;
struct ht_table{
  int size;
  int count;
  element **items;
};

ht_table *new_ht(){
  ht_table *ht;
  Malloc(ht,1);
  ht->size = 53;
  ht->count = 0;
  ht->items = calloc((size_t)ht->size, sizeof(element));
  return ht;
}

// idk what happened
#define HT_PRIME_1 2
#define HT_PRIME_2 3

int pows(int a, int b){
  int i;
  int base = a;
  for(i = 1; i < b; i++){
    a *= base;
  }
  return a;
}

// convert integer to binary
unsigned int int_to_bin(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bin(k / 2)));
}

static int ht_hash(int s, const int a, const int m){
  long hash = 0;
  int i;
  // length of s in binary
  int len_s = int_to_bin(s);
  for(i = 0 ; i < len_s; i++){
    hash += (long) pows(a, len_s - (i+1)) * (s % (int)pows(10,len_s -i));
    hash = hash % m;
  }
  return (int)hash;
}

// check 1st arg
static int ht_get_hash(int s, const int buckets, const int attemp){
  const int a = ht_hash(s, HT_PRIME_1, buckets);
  const int b = ht_hash(s, HT_PRIME_2, buckets);

  return (a + (attemp * (b + 1))) % buckets;
}


void ht_insert(ht_table *ht, int key, int value){
  element *item = new_ht_ele(key, value);
  int idx = ht_get_hash(item->key, ht->size, 0);
  element *cur_item = ht->items[idx];
  int i = 1;
  while(cur_item != NULL){
    idx = ht_get_hash(item->key, ht->size, i);
    cur_item = ht->items[idx];
    i++;
  }
  ht->items[idx] = item;
  ht->count++;
}

// keys !!
int ht_search(ht_table *ht, int key){
  int idx = ht_get_hash(key, ht->size, 0);
  element *item = ht->items[idx];
  int i = 1;
  while(item != NULL){
    if(item->key == key){
      return item->item;
    }
    idx = ht_get_hash(key, ht->size, i);
    item = ht->items[idx];
    i++;
  }
  // what?
  return 0;
  //return NULL;
}

static void ht_del_item(element *i){
  free(i);
}

void ht_delete(ht_table *ht, int key){
  int idx = ht_get_hash(key, ht->size, 0);
  element *item = ht->items[idx];
  int i = 1;
  while(item != NULL){
    //if(item != &HT_DELETE_ITEM){
    if(item->key != 0 && item->item != 0){
      if (item->key == key){
        ht_del_item(item);
        //ht->items[idx] = &HT_DELETE_ITEM;
        ht->items[idx]->key = 0;
        ht->items[idx]->item = 0;
      }
    }
    idx = ht_get_hash(key, ht->size, i);
    item = ht->items[idx];
    i++;
  }
  ht->count-- ;
}

int main(void){
  return 0;
}

