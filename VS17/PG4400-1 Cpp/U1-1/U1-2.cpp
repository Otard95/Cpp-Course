// U1-1.cpp : Defines the entry point for the console application.
//
// Iterate and print all ASCII char's fronm 33-255

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {

	for (int i = 0; i < 255; i++) {

		cout << (i + 33) << ": " << static_cast<char>(i + 33) << "  ";

		if (i % 10 == 0 && i != 0) {
			cout << endl;
		}

	}

	cout << endl << endl;

	system("pause");

	return 0;
}

