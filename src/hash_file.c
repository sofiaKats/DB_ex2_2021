#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "hash_file.h"
#include "structures.h"
#define MAX_OPEN_FILES 20
#define GLOBAL_DEPT 2

#define CALL_BF(call)       \
{                           \
  BF_ErrorCode code = call; \
  if (code != BF_OK) {         \
    BF_PrintError(code);    \
    return HT_ERROR;        \
  }                         \
}

//Declaration of a global array (for opening files).
Fileindex files[MAX_OPEN_FILES];

HT_ErrorCode HT_Init() {
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
  //Initialization of members of struct Fileindex.
  for(int i=0;i<MAX_OPEN_FILES;i++)
  {
    files[i].flag=0;                          // This index of the files array is empty for now
    files[i].filedesc=0;
    strcpy(files[i].filename,"0");
    files[i].structure = NULL;
  }
  return HT_OK;
}

HT_ErrorCode HT_CreateIndex(const char *filename, int depth) {
  //Create a file with name filename.
  CALL_BF(BF_CreateFile(filename));
  return HT_OK;
}

int Position_In_Array()
{ // find first empty index in files array
  for(int i=0;i<MAX_OPEN_FILES;i++)
  {
    if(files[i].flag==0)
      return i;  
  }
}

HT_ErrorCode HT_OpenIndex(const char *fileName, int *indexDesc){
  //Open the file with name filename
  int file_desc;
  CALL_BF(BF_OpenFile(fileName,&file_desc));
  
  
  //Store filename,filedesc into the global array of opening files, and indexDesc.
  int pos = Position_In_Array();
  files[pos].flag=1;
  files[pos].filedesc=file_desc;
  strcpy(files[pos].filename,fileName);
  *indexDesc=pos;  //Return the position of this hash file into the global array to variable indexeDesc. 
  printf("\nHASH FILE WITH NAME %s HAS JUST STORED IN POSITION %d OF GLOBAL ARRAY\n",fileName,pos);
  
  // Initialize Structure
  files[pos].structure = malloc(sizeof (Structures));
  files[pos].structure->global_depth = GLOBAL_DEPT;
  files[pos].structure->num_of_dir_blocks = 0;// No bucket exists yet
  files[pos].structure->block_list = NULL;    // Initialize head of blocks list to NULL
  files[pos].structure->bucket_list = NULL;   // Initialize head of buckets list to NULL

  // Creation of buckets for the particular file
  // starting with 2^Global_depth number of buckets
  int num_of_buckets = 1 << GLOBAL_DEPT;
  for (int i= 0; i< 1 << GLOBAL_DEPT; i++) // 1<< global_depth = 2^(global_depth)
  {   
    BucketNode* newbucket = malloc(sizeof(struct BucketNode));
                /* in the beggining the buckets will be empty so block = NULL */
    InsertLastInBucketList(&(files[pos].structure->bucket_list),NULL,i);
  }

  return HT_OK;
}

HT_ErrorCode HT_CloseFile(int indexDesc) {
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //Close the file with a specific identical number
  CALL_BF(BF_CloseFile(files[indexDesc].filedesc));
  
  printf("\nHASH FILE WITH NAME %s IN POSITION %d OF GLOBAL ARRAY HAS JUST CLOSED\n",files[indexDesc].filename,indexDesc);

  //Change the values of struct to the default values.
  files[indexDesc].flag=0;
  files[indexDesc].filedesc=0;
  files[indexDesc].structure->global_depth = 0;
  files[indexDesc].structure->num_of_dir_blocks = 0;// No bucket exists yet
  char* c="0";
  strcpy(files[indexDesc].filename,c);
  files[indexDesc].structure->block_list = NULL;    // Initialize head of blocks list to NULL
  files[indexDesc].structure->bucket_list = NULL;   // Initialize head of buckets list to NULL
  return HT_OK;
}

HT_ErrorCode HT_InsertEntry(int indexDesc, Record record) {
  //insert code here
  return HT_OK;
}

HT_ErrorCode HT_PrintAllEntries(int indexDesc, int *id) {
  //insert code here
  return HT_OK;
}

