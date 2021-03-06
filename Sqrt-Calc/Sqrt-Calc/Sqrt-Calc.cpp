// Sqrt-Calc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	bool cont = true;
	cout << "Enter a number and this program will calculate the square root to 3 decimal places\n";
	cout << "Limitations: \nPositive Number only\nNeeds to be an integar(no decimal places)\nMax Number is - 4294967295\n";
	cout << "type q + enter to quit" << endl;
	while (cont) {
		float outnum = 0.0;
		string instr;
		unsigned int innum;
		stringstream ss;
		cout << "Enter a Number: ";
		cin >> instr;
		
		if (instr[0] == 'q') {
			cont = false;
		}
		else {
			ss << instr;
			ss >> innum;

			cout << "Your number is: " << innum << endl;
			int lowbuf = 1;
			int highbuf = 2;
			float outnum = 0.0;
			bool fit = true;
			bool dec = false;

			while (outnum == 0.0) {
				if (lowbuf * lowbuf == innum) {
					outnum = lowbuf;
				}
				else if (highbuf * highbuf == innum){
					outnum = highbuf;
				}
				else if (highbuf * highbuf < innum) {
					lowbuf = highbuf;
					highbuf = highbuf * 2;
				}
				else if (lowbuf * lowbuf < innum && highbuf * highbuf > innum) {
					cout << "high level binary search complete, the square root is between: ";
					cout << lowbuf;
					cout << " and ";
					cout << highbuf << endl;
					cout << "Moving to low level binary search";
					//outnum = (lowbuf + highbuf) / 2;
					while (outnum == 0.0) {
						int term = (lowbuf + highbuf) / 2;
						if (term * term == innum) {
							outnum = term;
						}
						else if (highbuf - lowbuf == 1) {
							cout << endl;
							cout << "Low Level Binary Search Complete, sqrt is between: " << lowbuf << " and " << highbuf << endl;
							float newhigh = (float)highbuf;
							float newlow = (float)lowbuf;
							while (outnum == 0.0) {
								float term = (newhigh + newlow) / 2;
								if (term * term == innum) {
									outnum == ceil(1000 * term)/1000;
								}
								else if (term * term < innum) {
									newlow = ceil(1000 * term) / 1000;
								}
								else if (term * term > innum) {
									newhigh = ceil(1000 * term) / 1000;
								} 
								if (newhigh == newlow || ceil(1000 * newhigh) / 1000 - ceil(1000 * newlow) / 1000 <= 0.0021) {
									outnum = ceil(1000 * newlow) / 1000;
								}
								cout << newlow << " " << newhigh << " " << term << " " << outnum << endl;
								cout << newhigh - newlow << endl;
							}
						}
						else if (term * term < innum) {
							lowbuf = term;
						}
						else if (term * term > innum){
							highbuf = term;
						}
						//cout << lowbuf << " " << highbuf << " " << outnum << endl;
					}
				}
			}

			cout << "Square Root of " << innum << "(to 3 decimal points) is: " << outnum << endl;
		}
		
	}
    return 0;
}

