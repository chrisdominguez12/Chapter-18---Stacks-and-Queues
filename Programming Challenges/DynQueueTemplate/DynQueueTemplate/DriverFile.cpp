#include <iostream>
#include "DynQueueTemplate.h"

using namespace std;

int main() {

	DynQueueTemplate<class T> queue;

	cout << "Enqueuing 5 items...\n";

	//enqueue 5 items
	for (int i = 1; i <= 5; i++) {

		queue.enqueue(i*i);
	}

	//Dequeue and retreive all items in the queue
	cout << "The values in the queue were: \n";
	while (!queue.isEmpty()) {

		int value;
		queue.dequeue(value);
		cout << value << " ";
	}

	system("pause");
	return 0;
}