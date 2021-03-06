// SimpleCalc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int main()
{
	float outnum = 0.0;
	string instr;
	cout << "Enter a simple mathematical calculcation(.e.g 10+2, 4*4, 7/5, 1-3)\n";
	cout << "Limitations: \nPostive Numbers only\n*/+- observed only\n";
	cin >> instr;
	//cout << instr << endl;
	
	//cout << instr.length();

	//Failed implementation 1
	/*
	int calcbuff = 0;
	int calcbuff1 = 0;
	int leftval = 0;
	int rightval = 0;
	int op = 0;
	for (int i = 0; i < instr.length(); i++) {
		cout << instr[i];
		if (isdigit(instr[i])) {
			if (calcbuff = 0) {
				istringstream(instr[i]) >> calcbuff;
			}
			else {
				istringstream(instr[i]) >> calcbuff1;
				calcbuff = (calcbuff * 10) + calcbuff1;
			}
		}
		else {
			if (leftval == 0) {
				leftval = calcbuff;
			}
			else {
				switch (instr[i]) {
				case '+':
					leftval = leftval + calcbuff;
				case '-':
					leftval = leftval - calcbuff;
				case '*':
					leftval = leftval * calcbuff;
				case '/':
					leftval = leftval / calcbuff;
				}
			}
		}
	}

	outnum = leftval;
	*/

	//Failed Implementation 2
	//Using 2 Arrays, one representing the numbers, the next one representing the operations
	/*int arrlen = instr.length();
	float *numlist = new float[arrlen];
	float *oplist = new float[arrlen];
	float calcbuff = 0.0; 
	float calcbuff1 = 0.0;
	for (int f = 0; f < arrlen; f++) {
		cout << numlist[f] << endl;
	}
	/*for (int i = 0; i < instr.length(); i++) {
		if (isdigit(instr[i])) {
			if (calcbuff = 0) {
				istringstream(instr[i]) >> calcbuff;
			}
			else {
				istringstream(instr[i]) >> calcbuff1;
				calcbuff = (calcbuff * 10) + calcbuff1;
			}
		}
		else {
			for (int f = 0; f < arrlen; f++) {

			}
		}
	}*/

	//Failed Implementation 3
	//right to left, left val is modified by every right value
	/*
	int op = 0;
	int leftval = 0;
	int calcbuff = 0;
	int calcbuff1 = 0;
	for (int i = 0; i < instr.length(); i++) {
		//cout << instr[i];
		if (isdigit(instr[i])) {
			if (calcbuff = 0) {
				istringstream(instr[i]) >> calcbuff;
			}
			else {
				istringstream(instr[i]) >> calcbuff1;
				calcbuff = (calcbuff * 10) + calcbuff1;
				calcbuff1 = 0;
			}
		}
		else {
			if (leftval == 0) {
				leftval = calcbuff;
				calcbuff = 0;
			}
			else {
				switch (instr[i]) {
				case '+':
					op = 1;
					leftval = leftval + calcbuff;
				case '-':
					op = 2;
					leftval = leftval - calcbuff;
				case '*':
					op = 3;
					leftval = leftval * calcbuff;
				case '/':
					op = 4;
					leftval = leftval / calcbuff;
				}
				calcbuff = 0;
			}
			cout << i << endl;
			cout << leftval << endl;
			
		}
	}
	*/

	//Implementation 4
	//Actually doing the simple implementation, 1 operation, 2 numbers, 4 operators
	float leftbuf = 0;
	float rightbuf = 0;
	bool rswitch = false;
	char op = '\0';
	for (int i = 0; i < instr.length(); i++) {
		if (i == 0){
			leftbuf = instr[i] - '0';
		}
		else {
			if (isdigit(instr[i])) {
				if (!rswitch) {
					leftbuf = leftbuf * 10 + (instr[i] - '0');
				}
				else {
					if (rightbuf == 0) {
						rightbuf = instr[i] - '0';
					}
					else {
						rightbuf = rightbuf * 10 + (instr[i] - '0');
					}
				}
			}
			else {
				rswitch = true;
				op = instr[i];
			}
		}
	}

	switch (op) {
	case '+':
		outnum = leftbuf + rightbuf;
		break;
	case '-':
		outnum = leftbuf - rightbuf;
		break;
	case '*':
		outnum = leftbuf * rightbuf;
		break;
	case '/':
		outnum = leftbuf / rightbuf;
		break;
	}

	cout << outnum << endl;

	//cout << 9.0 / 2.0 << endl;

	return 0;
}

