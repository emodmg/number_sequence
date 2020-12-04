
#include <assert.h>
#include "sequence.h"

int main(void) {
  /*struct sequence *seq = sequence_create();
  assert(sequence_length(seq) == 0);
  sequence_insert_at(seq, 0, 27);
  assert(sequence_item_at(seq, 0) == 27);
  assert(sequence_length(seq) == 1);
  sequence_print(seq);
  sequence_destroy(seq);*/
  
  struct sequence *seq2 = sequence_create();
  assert(sequence_length(seq2) == 0);
  sequence_insert_at(seq2, 0, 27);
  sequence_insert_at(seq2, 1, 28);
  sequence_insert_at(seq2, 2, 29);
  sequence_insert_at(seq2, 3, 30);
  sequence_print(seq2); 
  sequence_insert_at(seq2, 3, 31);
  sequence_print(seq2);
  sequence_insert_at(seq2, 2, 32);
  sequence_print(seq2);
  sequence_insert_at(seq2, 2, 33);
  sequence_print(seq2);
  sequence_insert_at(seq2, 2, 34);
  sequence_print(seq2);  
  
  sequence_remove_at(seq2, 2);
  sequence_print(seq2);
  sequence_remove_at(seq2, 0);
  sequence_print(seq2);
  assert(sequence_length(seq2) == 6);
  assert(sequence_item_at(seq2, 0) == 28);
  
  sequence_remove_at(seq2, 5);
  sequence_print(seq2);
  assert(sequence_item_at(seq2, 4) == 31);
  assert(sequence_length(seq2) == 5);
  sequence_print(seq2);
  
  sequence_insert_at(seq2, 0, 1080);
  sequence_print(seq2);
  sequence_insert_at(seq2, 0, 750);
  sequence_print(seq2);
  sequence_insert_at(seq2, 7, 2070);
  sequence_print(seq2);
  sequence_insert_at(seq2, 8, 3080);
  sequence_print(seq2);
  assert(sequence_length(seq2) == 9);
  
  sequence_destroy(seq2);
}
