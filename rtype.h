//Author: Thomas Dattilo
//Assignment 1 for BU MET CS472 Spring 2017
//2/9/2017

#ifndef RTYPE
#define RTYPE
#include <string>

class rType{
	private:
		int source1, source2, destination, function, instructionCount;
		std::string functionName;
	public:
		rType(int, int);
		std::string out();	
};

#endif