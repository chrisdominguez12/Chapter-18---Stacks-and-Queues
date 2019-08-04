//This program demonstrates the IntQueue class

#include <iostream>
#include "IntQueue.h"

using namespace std;

int main() {

	IntQueue queue(5);

	cout << "Enqueuing 5 items...\n";

	//Enqueue 5 items
	for (int i = 1; i <= 5; i++) {

		queue.enqueue(i*i);
	}

	//Dequeue and retrieve all items in the queue
	cout << "The values in the queue were: ";
	while (!queue.isEmpty()) {

		int value;
		queue.dequeue(value);
		cout << value << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}