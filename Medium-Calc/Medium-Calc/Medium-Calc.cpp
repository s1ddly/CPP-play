// Medium-Calc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
using namespace std;


int main()
{
	bool cont = true;
	cout << "Enter a simple mathematical calculcation(.e.g 10+2-1, 4*4*9-1, 7/5+9-3, 1-3)\n";
	cout << "Limitations: \nPostive Numbers only\n*/+- observed only\n";
	cout << "type q + enter to quit" << endl;
	while(cont){
		float outnum = 0.0;
		string instr;
		cout << "Enter a calculation: ";
		cin >> instr;

		if (instr[0] == 'q') {
			cont = false;
		}
		else {
			float numbuf = 0.0;
			vector<float> numlist;
			vector<char> oplist;
			for (int i = 0; i < instr.length(); i++) {
				if (isdigit(instr[i])) {
					//if its a number
					if (numbuf == 0.0) {
						numbuf = (float)(instr[i] - '0');
					}
					else {
						numbuf = numbuf * 10.0 + (float)(instr[i] - '0');
					}
				}
				else {
					//if its a symbol
					numlist.push_back(numbuf);
					oplist.push_back(instr[i]);
					numbuf = 0.0;
				}
			}
			numlist.push_back(numbuf);


			//Below is for debugging purposes
			/*
			for (int x = 0; x < numlist.size(); x++) {
				cout << numlist[x] << endl;
			}

			for (int x = 0; x < oplist.size(); x++) {
				cout << oplist[x] << endl;
			}
			*/

			//Now that we have the list of inputs, split into a vector for numbers, and another for operations, we can now perform the calculations from left to right(order of operations is not observed, only left to right)
			float rightbuf = 0.0;
			float leftbuf = 0.0;
			for (int g = 0; g < oplist.size(); g++) {
				rightbuf = numlist[g + 1];
				if (g == 0) {
					//in first iteration of loop, initialize the right vector
					leftbuf = numlist[g];
				}
				switch (oplist[g]) {
				case '+':
					leftbuf = leftbuf + rightbuf;
					break;
				case '-':
					leftbuf = leftbuf - rightbuf;
					break;
				case '*':
					leftbuf = leftbuf * rightbuf;
					break;
				case '/':
					leftbuf = leftbuf / rightbuf;
					break;
				}
			}

			outnum = leftbuf;

			//cout << instr << endl;
			cout << outnum << endl;
		}
	}
	

	return 0;
}

