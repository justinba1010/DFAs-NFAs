// badparser.cc
// Justin Baum
// CSCE355
// 7 March 2020

#include <stdlib.h>
#include <vector>

#ifndef __baumdfa_structure_cc__
#define __baumdfa_structure_cc__
using std::vector;

struct DFA {
  int numStates;
  int numAccepting;
  vector<int> acceptingStates;
  int alphabetLength;
  char* alphabet;
  int* transitions;
};

#endif

#if 0
int main(int argc, char **argv) {
  struct DFA x;
};
#endif
