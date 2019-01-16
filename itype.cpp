//Author: Thomas Dattilo
//Assignment 1 for BU MET CS472 Spring 2017
//2/9/2017

#include <string>
#include <sstream>
#include <iomanip>
#include "itype.h"
#include <iostream>

using namespace std;

iType::iType(int value, int place){
	instructionCount=place;
	//Calculates values for function, source1, source2, and offset using masks (bitwise & and bitwise right shift)
	function=(value>>26)&0x3F;
	source1=(value & 0x3E00000)>>21;
	source2=(value & 0x1F0000)>>16;
	offset=value & 0xFFFF;
	//Decodes hex function code to function name
	switch(function){
		case 0x23:
			functionName="lw";
			break;
		case 0x2b:
			functionName="sw";
			break;
		case 0x4:
			functionName="beq";
			break;
		case 0x5:
			functionName="bne";
			break;
	}
}

string iType::out(){
	stringstream output;
	//Starts formatting decoded output
	output<<hex<<instructionCount-4<<" "<<functionName<<dec<<" $"<<source1<<",";
	//Determines what offset field is used for, and applies accordingly. If is for branch operations, else is for lw/sw 
	if(function==0x4||function==0x5){
		//Shifts left two bits for truncated branch offset
		offset=offset<<2;
		
		output<<" $"<<source2<<", address "<<hex<<offset+instructionCount<<endl;
		//Sets new instruction count based on branch
	}
	else{
		output<<" "<<offset<<"($"<<source2<<")"<<endl;
	}
	return output.str();
}