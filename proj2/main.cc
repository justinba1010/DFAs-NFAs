// main.cc
// Justin Baum
// CSCE355
// 7 March 2020
//
#include <stdlib.h>
#include <vector>
#include <iostream>

#include "structure.cc"


using std::cout;
using std::cin;
using std::vector;

#define SIZESTR 65536
#define MAXBYTELENGTH 65536
#define MAXNLENGTH 65536

void prettyPrinter(struct DFA dfa);
int lookup(char *alphabet, char transition);
bool accepted(int state, vector<int> acceptedStates);
int strLen(char *array);

int main(int argc, char **argv) {
  char input[SIZESTR];
  scanf("%s", input);
  int numStates = strLen(input) + 1;
  char* alphabet = "abcdefghijklmnopqrstuvwxyz";
  vector<int> acceptingStates;
  int alphabetLength = 26;
  acceptingStates.push_back(numStates - 1);
  int transitions[numStates*alphabetLength];
  for (int i = 0; i < numStates; ++i) {
    for (int j = 0; j < alphabetLength; ++j) {
      if (i == (numStates - 1)) {
        transitions[i*alphabetLength+j] = 1;
      } else {
        transitions[i*alphabetLength+j] = 0;
      }
    }
  }
  for (int i = 0; i < numStates-1; ++i) {
    int state = lookup(alphabet, input[i]);
    transitions[i*alphabetLength + state] = i + 1;
  }
  struct DFA dfa;
  dfa.numStates = numStates;
  dfa.alphabet = alphabet;
  dfa.numAccepting = 1;
  dfa.acceptingStates = acceptingStates;
  dfa.alphabetLength = alphabetLength;
  dfa.transitions = (int*)transitions;
  prettyPrinter(dfa);
  return 0;
}

void prettyPrinter(struct DFA dfa) {
  cout << "Number of states: " << dfa.numStates << "\n";
  cout << "Accepting states: ";
  for(int i = 0; i < dfa.numAccepting; ++i) {
    cout << dfa.acceptingStates[i] << " ";
  }
  cout << "\n";
  cout << "Alphabet " << dfa.alphabet << "\n";
  cout << "Alphabet Length: " << dfa.alphabetLength << "\n";
  for(int i = 0; i < dfa.numStates; ++i) {
    for(int j = 0; j < dfa.alphabetLength; ++j) {
      cout << ((int*)dfa.transitions)[i*dfa.alphabetLength+j] << " ";
    }
    cout << "\n";
  }
}

int lookup(char *alphabet, char transition) { 
  for(int i = 0; i < MAXBYTELENGTH; ++i) {
    if (alphabet[i] == 0) return -1;
    if (alphabet[i] == transition) return i;
  }
  return -1;
}

bool accepted(int state, vector<int> acceptedStates) {
  for(auto it = acceptedStates.begin(); it != acceptedStates.end(); ++it) {
    if (*it == state) return true;
  }
  return false;
}

int strLen(char* array) {
  for (int i = 0; i < MAXNLENGTH; ++i) {
    if (array[i] == 0) {
      return i;
    }
  }
  return MAXNLENGTH;
}
