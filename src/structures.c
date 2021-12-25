#include "structures.h"

int initialise_structure(Structures* structure, int global_depth){
  structure->global_depth = global_depth;
  structure->num_of_dir_blocks = 0;// No bucket exists yet
  structure->block_list = NULL;    // Initialize head of blocks list to NULL
  structure->bucket_list = NULL;   // Initialize head of buckets list to NULL
}