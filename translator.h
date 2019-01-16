//Author: Thomas Dattilo
//Assignment 1 for BU MET CS472 Spring 2017
//2/9/2017

#ifndef TRANSLATOR
#define TRANSLATOR

#include <string>

class Translator{
	private:
		int originalValue, opCode, instructionCount;
		std::string output;
	public:
		Translator(int);
		void findOp();
		void run(int);
		std::string getResult();
};
#endif