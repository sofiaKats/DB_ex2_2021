#ifndef BLOCK_LIST_H
#define BLOCK_LIST_H
#include "blocks.h"

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

#endif