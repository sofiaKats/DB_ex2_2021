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
    Record records_arr[8];	// array that will hold the 8 records  
};

// List to hold all blocks with records
typedef struct BlockNode
{
    Block* block;
    struct BlockNode* next; 
}BlockNode;

// inserts an item at the end of the list
void InsertLastInBlockList(BlockNode **list, Block* block);

// prints the entire list
void PrintBlockList(BlockNode* list);

// deletes one item from the list
void deleteNodeInBlockList(BlockNode **head_ref, int key);

// deletes the entire list
void DeleteBlockList(BlockNode **list);

#endif // BLOCKS_H