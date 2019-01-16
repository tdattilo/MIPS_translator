//Author: Thomas Dattilo
//Assignment 1 for BU MET CS472 Spring 2017
//2/9/2017


#include "translator.h"
#include <fstream>

using namespace std;

int main(){
	int inputs[11]={0x022DA822, 
		0x8EF30018, 0x12A70004, 0x02689820, 
		0xAD930018, 0x02697824, 0xAD8FFFF4, 
		0x018C6020, 0x02A4A825, 0x158FFFF6, 
		0x8E59FFF0};
	int instructionCounter=0x7A060;
	Translator codeTranslator(instructionCounter);
	string fileoutput="";
	//Runs calculations to decode each hex instruction
	for (int x=0; x<11; x++){
		codeTranslator.run(inputs[x]);
	}
	//Gets string output from object, covering all inputs
	fileoutput.append(codeTranslator.getResult());
	//Outputs string output to text file.
	ofstream outputFile;
	outputFile.open("output.txt");
	outputFile<<fileoutput;
	outputFile.close();
	return 0;
}