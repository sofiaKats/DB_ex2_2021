#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_OPEN_FILES 20

#include "buckets.h"
#include "blocks.h"

typedef struct Structures Structures;

// Array of open files (MAX 20)
typedef struct Fileindex
{
  int filedesc;
  int flag;
  char filename[20];
  Structures* structure; // each file includes: block0 | indexBlock (eurethrio) | Buckets, structure has all the above 
} Fileindex; 
/*
typedef struct Block0
{
    int global_depth;
    int num_of_dir_blocks; // plh8os eurethriwn
} Block0;*/

struct Structures
{
  //////// Block0 //////////
  int global_depth;
  int num_of_dir_blocks;
  /////////////////////////
  BucketNode* bucket_list; // head of bucket list
  BlockNode* block_list;   // head of block list
};

#endif // STRUCTURES_H