//Author: Thomas Dattilo
//Assignment 1 for BU MET CS472 Spring 2017
//2/9/2017

#ifndef ITYPE
#define ITYPE

#include <string>

class iType{
	private:
		int function, source1, source2, instructionCount;
		short offset;
		std::string functionName;
	public:
		iType(int, int);
		std::string out();
};
#endif