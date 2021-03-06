// U1-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Calc.h"
#include <iostream>

using namespace std;

void DisplayHelp(); 

int main() {

	Calc calc = Calc();
	bool running = true;

	// Print help before we start
	DisplayHelp();

	while (running) {

	Start:

		int n1, n2; // numbers one and two
		char o_char; // char representation of opperation

		// If calc has number from last operation use that if not get the first
		if (calc.HasLast()) {
			cin >> o_char >> n2;
		} else {
			cin >> n1 >> o_char >> n2;
		}

		switch (o_char) {

		case '+':
			calc.SetOp(add);
			break;

		case '-':
			calc.SetOp(sub);
			break;

		case '*':
			calc.SetOp(mult);
			break;

		case '/':
			calc.SetOp(division);
			break;

		case 'h':
			DisplayHelp();
			goto Start;

		case 'r':
			calc.Reset();
			system("clear");
			goto Start;

		case 'x':
			running = false;
			break;

		default:
			cout << "Unknown operator." << endl << endl;
			running = false;
			break;
		}

		// Again use last if it exists
		if (calc.HasLast()) {
			calc.AddNum(n2);
		} else {
			calc.AddNum(n1); calc.AddNum(n2);
		}

		cout << " = " << calc.Answer() << endl << endl;

	}

	system("pause");

	return 0;
}

void DisplayHelp() {

	cout 
		<< "General use \"<number><operator><number>\", though if you calculated something before you omit the firt number.\n"
		<< "You can substitute the operator for any one of these commands.\n"
		<< "When you do the nunber(s) is/are ignored and you will only execute the command\n"
		<< "  h - Show this help text.\n"
		<< "  r - Reset the calculator.\n"
		<< "  x - Exit.\n"
		<< endl;

}
