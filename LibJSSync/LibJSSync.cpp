// LibJSSync
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

// All terms etc.
const char* ignore = " \t\n";
const char* bMBegin = "/**";
const char* bMEnd = "/*";
const char* termBegin = "ASYNC BEGIN";
const char* termEnd = "ASYNC END";
const char* mainTerm = "ASYNC";


bool state[16];
int stateCounter = 0;


int pushState(bool newState) {
	state[stateCounter] = newState;
	int i = stateCounter;
	stateCounter++;
	return i;
}
void resetState() {
	stateCounter = 0;
}
bool getState(int i) {
	return state[i];
}
/*Sets state and returns old state*/
bool setState(int i, bool newState) {
	bool oldState = state[i];
	state[i] = newState;
	return oldState;
}
/*Measures where bMBegin is and inserts result in state slot 0*/

/*Ignores certain characters like white space*/
bool inIgnoreList(char c) {
	int ignoreListLen = 3;
	for (int i = 0; i < ignoreListLen; i++) {
		if (c == ignore[i]) {
			return true;
		}
	}
}
int main(int argc, char** argv){
	char* inFile = argv[1];
	printf("Options\n|\n|\nV\n");
	printf("Input File: %s\n", inFile);
	ifstream is;
	is.open(inFile);
	int c;
	
	
	
	int v = 0;
	while (is.good()) {
		c = is.get();
		

	}
}


