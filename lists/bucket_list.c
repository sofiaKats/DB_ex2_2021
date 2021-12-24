#include "buckets.h"

// inserts an item at the end of the list
void InsertLastInBucketList(BucketNode **list, Block* block, int bucket_index)
{
  BucketNode* newnode;
  BucketNode* current;

  newnode = malloc (sizeof (struct BucketNode));
    if (newnode == NULL) return;

  newnode->block = block;
  newnode->bucket_index = bucket_index;
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
void PrintBucketList(BucketNode* list)
{
// now we print the nodes
  BucketNode* current;
  current = list;
  while (current != NULL)
  {
    printf("bucket_index:%d and block_id:%d",current->bucket_index,current->block->block_id);
    if (current->next != NULL)
      printf("->");
    current = current->next;
  }
  printf("\n");
}

BucketNode* SearchIndex(BucketNode* list, int item){
  BucketNode* current;
  current = list;
  while (current != NULL)
  { // we search all the nodes of the list
    if (item == current->bucket_index)
      return current; // if we find it then we keep the node
    else
      current = current->next; // else we keep searching
  }
  return NULL; // if we dont then item in not in the list
}

// deletes one item from the list
void deleteNodeInBucket(BucketNode **head_ref, int key)
{
  // Store head node
  BucketNode *temp = *head_ref;
  BucketNode *prev = NULL;

  // If head node itself holds
  // the key to be deleted
  if (temp != NULL && temp->bucket_index == key)
  {
    *head_ref = temp->next; // Changed head
    free(temp);            // free old head
    return;
  }

  // Else Search for the key to be deleted,
  // keep track of the previous node as we
  // need to change 'prev->next' */
  while (temp != NULL && temp->bucket_index != key)
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
void DeleteBucketList(BucketNode **list)
{
  /* deref head_ref to get the real head */
  BucketNode* current = *list;
  BucketNode* next;

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