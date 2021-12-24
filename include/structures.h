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

// Representation of Buckets
struct BucketNode
{
    int bucket_index; // (00, 01, 10, 11) but represented as 0,1,2,3..etc depending on depth
    Block* block;     // pointer to block of records
    BucketNode* next;
};

typedef struct Block0
{
    int global_depth;
    int num_of_index; // plh8os eurethriwn
} Block0;

struct Block
{
    int block_id;           // = bucket index
	int local_depth;
    Record records_arr[8];	// array that will hold the 8 records  
};

// List to hold all blocks with records
typedef struct BlockNode
{
    Block* block;
    struct BlockNode* next; 
}BlockNode;

#endif // STRUCTURES_H