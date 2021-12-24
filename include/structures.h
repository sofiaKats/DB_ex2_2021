#ifndef STRUCTURES_H
#define STRUCTURES_H

// Array of open files (MAX 20)
typedef struct Fileindex
{
  int filedesc;
  int flag;
  int buckets;
  char filename[20];
} Fileindex; 

typedef struct Block0
{
    int global_depth;
    int num_of_index; // plh8os eurethriwn
} Block0;

#endif // STRUCTURES_H