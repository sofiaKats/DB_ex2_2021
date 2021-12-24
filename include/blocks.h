#ifndef BLOCKS_H
#define BLOCKS_H

#include "hash_file.h"

typedef struct Block Block;

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

#endif // BLOCKS_H