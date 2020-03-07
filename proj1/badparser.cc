// badparser.cc
// Justin Baum
// CSCE355
// 7 March 2020

#include <stdlib.h>
#include <vector>
#include <cstring>
#include <stdio.h>

#include "structure.cc"

#ifndef __baumdfa_badparser_cc__
#define __baumdfa_badparser_cc__

//using std::cin;
//using std::out;
using std::vector;

#define MAXBYTELENGTH 65536
#define MAXNLENGTH 32

void reset0(char* array) {
  for (int i = 0; i < MAXNLENGTH; ++i) array[i] = 0;
}

int strLen(char* array) {
  for (int i = 0; i < MAXNLENGTH; ++i) {
    if (array[i] == 0) {
      return i;
    }
  }
  return MAXNLENGTH;
}

vector<int> parseInts(char *string) {
  char number[MAXNLENGTH];
  reset0(number);
  vector<int> ret;
  int x = 0;
  for (int i = 0; i < MAXBYTELENGTH; ++i) {
    if (string[i] == 0) break;
    if (string[i] == ' ') {
      int y = atoi(number);
      ret.push_back(y);
      x = 0;
      reset0(number);
      continue;
    }
    number[x++] = string[i];
  }
  ret.push_back(atoi(number));
  return ret;
}


void parse(struct DFA &dfa) {
  // State: Number of states
  scanf("Number of states: %d\n", &dfa.numStates);
  char junkString[MAXBYTELENGTH], alphabet[MAXBYTELENGTH], word[MAXBYTELENGTH];
  scanf("Accepting states: %[^\n]\n", junkString);
  dfa.acceptingStates = parseInts(junkString);
  scanf("Alphabet: %[^\n]\n", alphabet);
  dfa.alphabetLength = strLen(alphabet);
  dfa.alphabet = alphabet;
  vector<struct Delta> transitions;
  for(int i = 0; i < dfa.numStates; ++i) {
    struct Delta delta;
    scanf("%[^\n]\n", junkString);
    delta.transition = parseInts(junkString);
    transitions.push_back(delta);
  }
  dfa.transitions = transitions;
  scanf("%[^\n]\n", word);
  dfa.word = word;
}
#endif

#if 0
int main(int argc, char** argv) {
  struct DFA dfa;
  parse(dfa);
  return 0;
}
#endif
