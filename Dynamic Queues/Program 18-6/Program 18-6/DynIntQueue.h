#pragma once
#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H
#include <iostream>

using namespace std;

//CONCEPT: A queue may implemented as a linked list, and expand or shrink with each enqueue/dequeue
//operation.

class DynIntQueue {

private: 

	class QueueNode {

		friend class DynIntQueue;
		int value;
		QueueNode *next; 
		QueueNode(int value, QueueNode *next = NULL) {
			
			this->value = value;
			this->next = next;
		}
	};


	QueueNode *front;
	QueueNode *rear;

public: 

	//Constructor
	DynIntQueue() {

		front = NULL;
		rear = NULL;
	}


	//Destructor
	~DynIntQueue() {

		clear();
	}


	//Function enqueue inserts the value in num at the rear of the queue
	void enqueue(int num) {

		if (isEmpty()) {

			front = new QueueNode(num);
			rear = front;
		}

		else {

			rear->next = new QueueNode(num);
			rear = rear->next;
		}
	}


	//Function dequeue removes the value at the front of the queue, 
	//and copies it into num
	void dequeue(int &num) {

		QueueNode *temp;
		if (isEmpty()) {

			cout << "The queue is empty.\n";
		}

		else {

			num = front->value;
			temp = front;
			front = front->next;
			delete temp;
		}
	}


	//Function isEmpty returns true if the queue is empty, and false otherwise
	bool isEmpty() {

		if (front == NULL) {

			return true;

		}

		else {

			return false;

		}
	}



	//Function clear dequees all the elements in the queue
	void clear() {

		int value;			//Dummy variable for dequeue

		while (!isEmpty()) {

			dequeue(value);
		}
	}

};
#endif // !DYNINTQUEUE_H
