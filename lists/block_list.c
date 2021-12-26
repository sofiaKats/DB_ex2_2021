#include "blocks.h"
#include "block_list.h"

// inserts an item at the end of the list
void InsertLastInBlockList(BlockNode **list, Block* block)
{
  BlockNode* newnode;
  BlockNode* current;

  newnode = malloc (sizeof (struct BlockNode));
    if (newnode == NULL) return;

  newnode->block = block;
  newnode->next = NULL;

  if (*list == NULL)
    *list = newnode;
  else
  {
    current = *list;
    while (current->next != NULL) current = current->next;
    current->next = newnode;
  }
}

// prints the entire list
void PrintBlockList(BlockNode* list)
{
  BlockNode* current;
  current = list;
  while (current != NULL)
  {
    printf("id: %d depth:%d",current->block->block_id, current->block->local_depth);
    if (current->next != NULL)
      printf("->");
    current = current->next;
  }
  printf("\n");
}

// deletes one item from the list
void deleteNodeInBlockList(BlockNode **head_ref, int key)
{
  // Store head node
  BlockNode *temp = *head_ref;
  BlockNode *prev = NULL;

  // If head node itself holds
  // the key to be deleted
  if (temp != NULL && temp->block->block_id == key)
  {
    *head_ref = temp->next; // Changed head
    free(temp);            // free old head
    return;
  }

  // Else Search for the key to be deleted,
  // keep track of the previous node as we
  // need to change 'prev->next' */
  while (temp != NULL && temp->block->block_id != key)
  {
    prev = temp;
    temp = temp->next;
  }

  // If key was not present in linked list
  if (temp == NULL)
    return;

  // Unlink the node from linked list
  prev->next = temp->next;

  // Free memory
  free(temp);
}

// deletes the entire list
void DeleteBlockList(BlockNode **list)
{
  /* deref head_ref to get the real head */
  BlockNode* current = *list;
  BlockNode* next;

  while (current != NULL)
  {
    next = current->next;
    free(current); //free(current);
    current = next;
  }

  /* deref head_ref to affect the real head back
    in the caller. */
  *list = NULL;
}