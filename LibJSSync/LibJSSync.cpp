// LibJSSync.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
