#ifndef BLOCKS_H
#define BLOCKS_H

#include <stdio.h>
#include <stdlib.h>

#include "hash_file.h"

typedef struct Block Block;

struct Block
{
    int block_id;           // = bucket index
	int local_depth;
    int no_of_records;
    Record* records_arr[8];	// array that will hold the 8 records  
};

void initialise_block(int id, int global_depth, Block* b);

#endif // BLOCKS_H