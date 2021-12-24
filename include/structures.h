#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "hash_file.h"

typedef struct BucketNode BucketNode;
typedef struct Block Block;

// Array of open files (MAX 20)
typedef struct Fileindex
{
  int filedesc;
  int flag;
  int buckets;
  char filename[20];
} Fileindex; 

// List of bucket nodes
typedef struct BucketList
{
    BucketNode* bucket;
    struct BucketList* next;
}BucketList;

// Representation of Buckets
struct BucketNode
{
    int bucket_index; // (00, 01, 10, 11) but represented as 0,1,2,3..etc depending on depth
    Block* block;     // pointer to block of records
    BucketNode* next;
};

struct Block
{
    int block_id;
	int local_depth;
    Record records_arr[8];	// array that will hold the 8 records  
};

// List to hold all blocks with records
typedef struct BlockList
{
    Block* block;
    struct BlockList* next; 
}BlockList;



#endif // STRUCTURES_H