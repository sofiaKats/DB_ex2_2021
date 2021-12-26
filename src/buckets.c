#include "buckets.h"
#include "bucket_list.h"
#include "string.h"
#include "math.h"

#define BLOCK_CAPACITY 8

int hash_function(int id, int depth){
  
  int i =2;
  int j =32;
  int hashed_value = (int) (id*2654435761 % (int)pow(i,j));
  return hashed_value;
}

int find_index(int hashed_value,int depth){
  int index = hashed_value >> (32-depth); 
  return index;
}

int bucket_insert(Record record, BucketNode* bucket_node){
    if (bucket_node->block->no_of_records == BLOCK_CAPACITY) return -1;     //block is full, record doesn't fit
    for (int i=0; i<BLOCK_CAPACITY; i++){
        Record* r = bucket_node->block->records_arr[i];
        if (r == NULL){
           r = malloc(sizeof(Record));
           strcpy(r->city,record.city);
           strcpy(r->name,record.name);
           strcpy(r->surname,record.surname);
           r->id = record.id;
           bucket_node->block->no_of_records++;
           break;
        }
    }
    return 1;
}