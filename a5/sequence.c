#include "sequence.h"
#include <stdio.h>
#include <assert.h>

const int SEQUENCE_MAXLEN = 1024;

// sequence_init() creates and returns an initialized seq to be empty
//   with maximum capacity SEQUENCE_MAXLEN
struct sequence sequence_init(){
    struct sequence s = {0, SEQUENCE_MAXLEN, {0}};
    return s;
}

// sequence_length(seq) returns the number of items in seq
int sequence_length(const struct sequence seq){
    return seq.len;
}

// sequence_item_at(seq, pos) returns the item in seq at position pos
// requires: 0 <= pos < sequence_length(seq)
int sequence_item_at(const struct sequence seq, int pos){
    return seq.data[pos];
}

// sequence_insert_at(seq, pos, val) inserts(adds) a new item with value val
//   at position pos in seq
// note: changes the position of items that were at position >= pos
// requires: 0 <= pos <= sequence_length(seq) < SEQUENCE_MAXLEN
struct sequence sequence_insert_at(struct sequence seq, int pos, int val){
    for (int i = seq.len; i > pos; i--){
        seq.data[i]=seq.data[i-1];
    }
    seq.data[pos] = val;
    seq.len++;
    return seq;
}

// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the updated sequence
// note: changes the position of items that were at position > pos
// requires: 0 <= pos < sequence_length(seq)
struct sequence sequence_remove_at(struct sequence seq, int pos){
    for (int i = seq.len-2; i >= pos ; i++){
        seq.data[i]=seq.data[i+1];
    }
    seq.len--;
    return seq;
}

//////////////////////////////////////////////////////////////////////////
// The above are the typical operations (functions) for a Sequence Struct. //
// You must also complete the following "Advanced" operations.          //
//////////////////////////////////////////////////////////////////////////

// sequence_equiv(seq1, seq2) determines if seq1 and seq2 are equivalent
//   (they both have the same length and have identical sequences of items)
bool sequence_equiv(const struct sequence seq1, const struct sequence seq2){
    if (seq1.len!=seq2.len) return false;
    for (int i = 0; i < seq1.len; i++){
        if (seq1.data[i]!=seq2.data[i]) return false;
    }
    return true;
}

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0,item_1,...,item_last]\n"
//   or "[empty]\n"
// examples: [1,3,7]
//           [42]
//           [empty]
// effects: produces output
void sequence_print(const struct sequence seq){
    if (seq.len == 0) {
        printf("[empty]\n");
    } else {
        printf("[%d", seq.data[0]);
        for (int i=1; i<seq.len; i++){
            printf(",%d", seq.data[i]);
        }
        printf("]\n");
    }
    return;
}


// sequence_append(seq1, seq2) returns a new sequence with all items from seq1 
//     followed by all items from seq2
// requires: seq1 and seq2 are different sequences
//           sequence_length(seq1) + sequence_length(seq2) <= SEQUENCE_MAXLEN
struct sequence sequence_append(struct sequence seq1, const struct sequence seq2){
    struct sequence seq3 = seq1;
    for (int i = seq1.len; i < seq1.len+seq2.len; i++){
        seq3.data[i] = seq2.data[i-seq1.len];
    }
    seq3.len = seq1.len+seq2.len;
    return seq3;
}

// sequence_remove_dups(seq) creates a new copy of seq after removeing all duplicates from seq
//   (keeping each first occurrence)
// examples: [1,3,7] => [1,3,7]
//           [1,1,3,1,7,1,3] => [1,3,7]
struct sequence sequence_remove_dups(struct sequence seq){
    struct sequence s = {0, SEQUENCE_MAXLEN, {0}};
    bool unique = true;
    for (int i=0; i<seq.len; i++){
        int j=0;
        while(j<s.len && unique){
            if (seq.data[i]==s.data[j]) unique = false;
            j++;
        }
        if (unique){
            s.data[s.len]=seq.data[i];
            s.len++;
        }
        unique = true;
    }
    return s;
}

/*
int main(void) {
  // struct sequence s1 = {0};
  struct sequence s1 = sequence_init();
  s1 = sequence_insert_at(s1, 0, 1);
  sequence_print(s1); 

  // struct sequence s2 = {0};
  struct sequence s2 = sequence_init();
  sequence_print(s2); 
  s2 =sequence_insert_at(s2, 0, 1);
  sequence_print(s2); 
  
  assert(sequence_equiv(s1, s2));
  
  assert(sequence_length(s1) == 1);
  s1 = sequence_remove_at(s1, 0);
  assert(sequence_length(s1) == 0);
  struct sequence s_append = sequence_append(s2, s2);
  sequence_print(s_append); 
  assert(sequence_length(s_append) == 2);

  // struct sequence s3 = {0};
  struct sequence s3 = sequence_init();
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 1);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 1);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 2);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 3);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 4);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 3, 5);
  sequence_print(s3); 
  assert(sequence_length(s3) == 6);
  s3 = sequence_append(s3, s3);
  sequence_print(s3); 
  
  assert(sequence_length(s3) == 12);
  
  struct sequence s4 = sequence_init();
  s4 = sequence_remove_dups(s3);
  
  sequence_print(s4);
  
  assert(sequence_length(s4) == 5);
  s4 = sequence_remove_dups(s4);
  assert(sequence_length(s4) == 5);
  
  
  return 0;
}
*/