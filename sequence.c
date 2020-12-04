
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct sequence {
  int len;
  int maxlen;
  int *data;
};

// sequence_create() returns a pointer to a new (empty) sequence
// effects: allocates memory (caller must call sequence_destroy)
// time: O(1)
struct sequence *sequence_create(void) {
  struct sequence *result = malloc(sizeof(struct sequence));
  result->len = 0;
  result->maxlen = 1;
  result->data = malloc(sizeof(int) * result->maxlen);
  return result;
}


// sequence_destroy(seq) frees all dynamically allocated memory 
// effects: the memory at seq is invalid (freed)
// time: O(1)
void sequence_destroy(struct sequence *seq) {
  assert(seq);
  free(seq->data);
  free(seq);
}

// sequence_length(seq) returns the number of items in seq
// time: O(1)
int sequence_length(const struct sequence *seq) {
  assert(seq);
  return (seq->len);
}

// sequence_item_at(seq, pos) returns the item in seq at position pos
// requires: 0 <= pos < sequence_length(seq)
// time: O(1)
int sequence_item_at(const struct sequence *seq, int pos) {
  assert(seq);
  assert((pos >= 0) && (pos < seq->len));
  return *(seq->data + pos);
}

// sequence_insert_at(seq, pos, val) inserts a new item with value val
//   at position pos in seq
//   (changing the position of items at position >= pos)
// requires: 0 <= pos <= sequence_length(seq)
// effects: modifies seq
// time: O(n)
void sequence_insert_at(struct sequence *seq, int pos, int val) {
  assert(seq);
  assert((pos >= 0) && (pos <= seq->len));
  if (seq->len == seq->maxlen) {
    seq->maxlen *= 2;
    seq->data = realloc(seq->data, sizeof(int) * seq->maxlen);
  }
  for (int i = seq->len; i > pos; i -= 1) {
    *(seq->data + i) = *(seq->data + i - 1);
  }
  *(seq->data + pos) = val;
  seq->len += 1;
}

// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the removed value
//   (changing the position of items > pos)
// requires: 0 <= pos < sequence_length(seq)
// effects: modifies seq
// time: O(n)
int sequence_remove_at(struct sequence *seq, int pos) {
  assert(seq);
  assert((pos >= 0) && (pos < seq->len));
  int result = *(seq->data + pos);
  for (int i = pos; i < (seq->len - 1); i += 1) {
    *(seq->data + i) = *(seq->data + i + 1);
  }
  seq->len -= 1;
  return result; // 这里需要realloc以缩小内存heap嘛？？？
}

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0,item_1,...,item_last]\n"
//   or "[empty]\n"
// effects: produces output
// time: O(n)
void sequence_print(const struct sequence *seq) {
  assert(seq);
  if (seq->len == 0) {
    printf("[empty]\n");
    return;
  }
  printf("[");
  for (int i = 0; i < (seq->len - 1); i += 1) {
    printf("%d,", *(seq->data + i));
  }
  printf("%d]\n", *(seq->data + seq->len - 1));
}
    
  