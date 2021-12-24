#ifndef BUCKETS_H
#define BUCKETS_H

#include "blocks.h"

typedef struct BucketNode BucketNode;

// Representation of Buckets
struct BucketNode
{
    int bucket_index; // (00, 01, 10, 11) but represented as 0,1,2,3..etc depending on depth
    Block* block;     // pointer to block of records
    BucketNode* next;
};


#endif // BUCKETS_H