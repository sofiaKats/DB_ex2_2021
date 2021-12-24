#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "hash_file.h"
#include "structures.h"
#define MAX_OPEN_FILES 20

#define CALL_BF(call)       \
{                           \
  BF_ErrorCode code = call; \
  if (code != BF_OK) {         \
    BF_PrintError(code);    \
    return HP_ERROR;        \
  }                         \
}

//Declaration of a global array (for opening files).
Fileindex files[MAX_OPEN_FILES];

HT_ErrorCode HT_Init() {
  //Initialization of members of struct Fileindex.
  for(int i=0;i<MAX_OPEN_FILES;i++)
  {
    files[i].flag=0;
    files[i].filedesc=0;
    files[i].buckets=0;
    strcpy(files[i].filename,"0");
  }
  return HT_OK;
}

HT_ErrorCode HT_CreateIndex(const char *filename, int depth) {
  //insert code here
  return HT_OK;
}

HT_ErrorCode HT_OpenIndex(const char *fileName, int *indexDesc){
  //insert code here
  return HT_OK;
}

HT_ErrorCode HT_CloseFile(int indexDesc) {
  //insert code here
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

