// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t peak = num;
    uint64_t cur = num;
    while (cur != 1) {
        if (cur % 2 == 0) {
            cur = cur >> 1;
        } else {
            cur = cur * 3 + 1;
        }
        if (cur > peak) {
            peak = cur;
        }
    }
  return peak;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int steps = 0;
    uint64_t val = num;
    do {
        if (val & 1) {
            val = val * 3 + 1;
        } else {
            val = val / 2;
        }
        ++steps;
    } while (val != 1);
  return steps+1;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  unsigned int longest = 0;
  unsigned int best_num = 0;
  for (uint64_t start = lbound; start <= rbound; ++start) {
      unsigned int len = collatzLen(start);     
      if (len > longest) {
            longest = len;
            best_num = start;
        }
    }
  *maxlen = longest;
  return best_num;
}
