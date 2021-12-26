#include "blocks.h"

void initialise_block(int id, int global_depth, Block* b){
    b->block_id = id;
    b->local_depth = global_depth;
    b->no_of_records = 0;
    for (int i = 0;i<8;i++){
        b->records_arr[i]=NULL;
    }
}