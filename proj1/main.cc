// main.cc
// Justin Baum
// CSCE355
// 7 March 2020
//
#include <stdlib.h>
#include <vector>
#include <iostream>

#include "structure.cc"
#include "badparser.cc"


using std::cout;
using std::cin;
using std::vector;

void prettyPrinter(struct DFA dfa);
int lookup(char *alphabet, char transition);
bool accepted(int state, vector<int> acceptedStates);

int main(int argc, char **argv) {
  struct DFA dfa;
  parse(dfa);
  // Initial State
  int state = 0;

  //prettyPrinter(dfa);
  int symbol;
  for(int i = 0; dfa.word[i] != '\0'; ++i) {
    //cout << "Current State: " << state << "\n";
    symbol = lookup(dfa.alphabet, dfa.word[i]);
    state = dfa.transitions[state].transition[symbol];
  }
  cout << "This string is: " << (accepted(state, dfa.acceptingStates) ? "accepted" : "rejected") << " by this automata.\n";
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
      cout << dfa.transitions[i].transition[j] << " ";
    }
    cout << "\n";
  }
  cout << "Word: " << dfa.word << "\n";
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
