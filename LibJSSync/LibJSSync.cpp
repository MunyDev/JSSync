// LibJSSync
#define _CRT_SECURE_NO_WARNINGS
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
const char* termBegin = "BEGIN";
const char* termEnd = "END";
const char* mainTerm = "ASYNC";

FILE* f = fopen("log.txt", "w+");
bool state[16];
int stateCounter = 0;

/*Ignores certain characters like white space*/
bool inIgnoreList(char c) {
	int ignoreListLen = 3;
	for (int i = 0; i < ignoreListLen; i++) {
		if (c == ignore[i]) {
			return true;
		}
	}
	return false;
}
int pushState(bool newState) {
	state[stateCounter] = newState;
	int i = stateCounter;
	stateCounter++;
	return i;
}
void resetState() {
	stateCounter = 0;
	memset(state, 0, sizeof(state));
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
void error(const char *str) {
	cerr << str << endl;
	exit(-1);

}
bool beginsWith(string term, string str) {
	for (int i = 0; i < term.length(); i++) {
		
		if (term[i] != str[i]) return false;
	}
	return true;
}
bool endsWidth(string ending, string str) {
	int off = str.length() - ending.length() - 1;
	
	for (int i = off; i < str.length(); i++) {
		
		if (str[i] != ending[i - off]) return false;
	}
	return true;
}
/*Reads command and returns string. Also sets the state in specified slot to be false if no command was defined in this line*/
void readCommand(string line, int slot, string& result) {
	if (line.length() < 3) {
		return;
	}
	
	if (beginsWith("/**", line)) {

		
		// This is where we start skipping and trimming whitespace to read the command
		int off = 2;

		//The variable below represents the offset of the command
		int commandOff = off;
		while (inIgnoreList(line[commandOff])) { commandOff++; }

		commandOff +=7;
		while (inIgnoreList(line[commandOff])) { commandOff++; }

		int off2 = commandOff;
		
		while (!(inIgnoreList(line[off2])||line[off2] == '*')) { off2++; }
		fprintf(f, "[DEBUG] Command: %s\n", line.substr(commandOff, off2 - commandOff).c_str());
		result = line.substr(commandOff, off2 - commandOff).c_str();
		setState(slot, true);
		return;

	}
	result = "";
	setState(slot, false);

	
}

/*Measures where bMBegin is and inserts result in state slot 0*/
bool checkForBMBegin(string str) {
	if (getState(0)) {
		error("Already began! Do not do the same command twice. Exiting!");

	}
	else {
		
	}
	return false;
}



int main(int argc, char** argv){
	if (argc <= 1) {
		cout << "Not enough arguments!" << endl;
		return 0 ;
	}
	char* inFile = argv[1];
	printf("Options\n|\n|\nV\n");
	printf("Input File: %s\n\n\n\n\n", inFile);
	ifstream is(inFile);
	int c;
	
	
	
	int v = 0;
	string line;
	string curCommand;
	while (getline(is, line)) {
		
		
		readCommand(line, 0, curCommand);
		cout << curCommand << " " << getState(0) << endl;

	}
	is.close();
	fclose(f);
}


