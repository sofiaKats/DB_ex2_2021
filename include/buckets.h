#ifndef BUCKETS_H
#define BUCKETS_H

#include <stdio.h>
#include <stdlib.h>

#include "blocks.h"
#include "bucket_list.h"


int hash_function(int id,int depth);

int find_index(int hashed_value,int depth);

int bucket_insert(Record record, BucketNode* bucket_node);

#endif // BUCKETS_H