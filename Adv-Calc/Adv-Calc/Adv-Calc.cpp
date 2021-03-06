// Adv-Calc.cpp : Defines the entry point for the console application.
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
	while (cont) {
		float outnum = 0.0;
		string instr;
		cout << "Enter a calculation: ";
		cin >> instr;

		float rightbuf = 0.0;
		float leftbuf = 0.0;

		if (instr[0] == 'q') {
			cont = false;
		}
		else {
			float numbuf = 0.0;
			vector<float> numlist;
			vector<char> oplist;
			float deccnt = 0.0;
			for (int i = 0; i < instr.length(); i++) {
				if (isdigit(instr[i])) {
					//if its a number
					if (numbuf == 0.0) {
						numbuf = (float)(instr[i] - '0');
					}
					else {
						if (deccnt > 0) {
							numbuf = numbuf + ((float)(instr[i] - '0') / deccnt);
							deccnt = deccnt * 10;
						}
						else {
							numbuf = numbuf * 10.0 + (float)(instr[i] - '0');
						}
					}
				}
				else {
					//if its a symbol
					if (instr[i] == '.') {
						deccnt = 10.0;
					}
					else {
						numlist.push_back(numbuf);
						oplist.push_back(instr[i]);
						numbuf = 0.0;
						deccnt = 0.0;
					}
				}
			}
			numlist.push_back(numbuf);

			//Multiplier loop
			int mlooplen = oplist.size();
			for (int f = 0; f < mlooplen; f++) {
				if (oplist[f] == '*') {
					numlist[f] = numlist[f] * numlist[f + 1];
					numlist[f + 1] = 0.0;
					oplist[f] = '\0';
					oplist.erase(oplist.begin() + f);
					numlist.erase(numlist.begin() + f + 1);
					f--;
					mlooplen--;
				}
			}

			int divlooplen = oplist.size();
			for (int f = 0; f < divlooplen; f++) {
				if (oplist[f] == '/') {
					numlist[f] = numlist[f] / numlist[f + 1];
					numlist[f + 1] = 0.0;
					oplist[f] = '\0';
					oplist.erase(oplist.begin() + f);
					numlist.erase(numlist.begin() + f + 1);
					f--;
					divlooplen--;
				}
			}

			int addlooplen = oplist.size();
			for (int f = 0; f < addlooplen; f++) {
				if (oplist[f] == '+') {
					numlist[f] = numlist[f] + numlist[f + 1];
					numlist[f + 1] = 0.0;
					oplist[f] = '\0';
					oplist.erase(oplist.begin() + f);
					numlist.erase(numlist.begin() + f + 1);
					f--;
					addlooplen--;
				}
			}

			int minlooplen = oplist.size();
			for (int f = 0; f < minlooplen; f++) {
				if (oplist[f] == '-') {
					numlist[f] = numlist[f] - numlist[f + 1];
					numlist[f + 1] = 0.0;
					oplist[f] = '\0';
					oplist.erase(oplist.begin() + f);
					numlist.erase(numlist.begin() + f + 1);
					f--;
					minlooplen--;
				}
			}

			outnum = numlist[0];
			//cout << instr << endl;
			cout << outnum << endl;
		}
	}
	cout << "Thank you for using me!" << endl;

    return 0;
}

