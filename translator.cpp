//Author: Thomas Dattilo
//Assignment 1 for BU MET CS472 Spring 2017
//2/9/2017

#include "translator.h"
#include <string>
#include "rtype.h"
#include "itype.h"

using namespace std;

Translator::Translator(int place){
	instructionCount=place;
}
void Translator::findOp(){
	//Determines whether code is r type or itype, then passes to appropriate object for decoding
	opCode=originalValue>>26;
	if(opCode==0){
		rType remainder(originalValue, instructionCount);
		//Takes decoded R-Type instructions from R-Type object and appends to output
		output.append(remainder.out());
	}
	else{
		iType remainder(originalValue, instructionCount);
		//Takes decoded I-Type instructions from I-Type object and appends to output
		output.append(remainder.out());
	}
}
void Translator::run(int val){
	//Increments instruction count, takes passed in hex-coded instructions
	instructionCount+=4;
	originalValue=val;
	findOp();
}
string Translator::getResult(){
	//Returns fully-formatted string of all decoded codes
	return output;
}