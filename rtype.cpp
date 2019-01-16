//Author: Thomas Dattilo
//Assignment 1 for BU MET CS472 Spring 2017
//2/9/2017

#include "rtype.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

rType::rType(int value, int place){
	//Calculates values for function, source1, source2, and destination using masks (bitwise & and bitwise right shift)
	source1=(value&0x3E00000)>>21;
	source2=(value&0x1F0000)>>16;
	destination=(value&0xF800)>>11;
	function=(value&0x3F);
	instructionCount=place;
	//Decodes hex function code to function name
	switch (function){
		case 0x20:
			functionName="add";
			break;
		case 0x22:
			functionName="sub";
			break;
		case 0x24:
			functionName="and";
			break;
		case 0x25:
			functionName="or";
			break;
		case 0x2a:
			functionName="slt";
			break;
	}
}

string rType::out(){
	//Formats decoded instruction and returns as a string
	stringstream output;
	output<<hex<<instructionCount-4<<" ";
	output<<functionName<<" "<<"$"<<dec<<destination<<", $"<<source1<<", $"<<source2<<endl;
	return output.str();
}