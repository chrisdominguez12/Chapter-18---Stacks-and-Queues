//This program illustrats IntStack exception handling
#include "IntStack.h"
#include <iostream>

using namespace std;

//NOTE: Programs using stack SHOULD NOT USE try/catch statements to handle underflow. 
//They should always check by using an isEmpty function to ensure that underflow cannot 
//happen before calling pop.

int main() {

	IntStack stack(5);
	int values[] = { 5, 10, 15, 20, 25 };
	int value;

	try {

		cout << "Pushing...\n";
		for (int k = 0; k < 5; k++) {

			cout << values[k] << " ";
			stack.push(values[k]);
		}

		cout << "\nPushing value after stack is full...";
		stack.push(30);
		cout << "\nYou should not see this!";
		cout << endl;
	}

	catch (IntStack::Overflow) {

		cout << "\nAn Overflow exception occured.\n";
	}

	system("pause");
	return 0;
}