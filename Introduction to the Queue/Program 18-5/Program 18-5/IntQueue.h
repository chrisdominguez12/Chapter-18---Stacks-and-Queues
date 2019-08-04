#pragma once
#ifndef INTQUEUE_H
#define INTQUEUE_H

#include <iostream>

using namespace std;

//CONCEPT: A queue is a data structure that stores and retrieves items in a a first in, first out manner. 
//Queues may be implemented as arrays or as linked lists. Dynamic queues do not need a size declared before
//initializing. 

//The two primary ooperations of a queue are 'enqueue' (to insert element at the reat) and 'dequeue'
//(to remove an element from the front of a queue)


class IntQueue {

private: 

	int *queueArray; 
	int queueSize;
	int front; 
	int rear;
	int numItems;

public: 
	
	//Constructor
	IntQueue(int s) {

		queueArray = new int[s];
		queueSize = s;
		front = -1;
		rear = -1;
		numItems = 0;
	}


	//Destructor
	~IntQueue() {

		delete[] queueArray;
	}

	

	//Function enqueue inserts the value in num at the rear of the queue
	void enqueue(int num) {

		if (isFull()) {

			cout << "The queue is full.\n";
		}

		else {

			//Calculate the new rear position
			rear = (rear + 1) % queueSize;

			//Insert new item
			queueArray[rear] = num;

			//Update item count
			numItems++;
		}
	}


	//Function dequeue removes the value at the front of the queue 
	//and copies it into num
	void dequeue(int &num) {

		if (isEmpty()) {

			cout << "The queue is empty.\n";

		}

		else {

			//Move front
			front = (front + 1) % queueSize;

			//Retrieve the front item
			num = queueArray[front];

			//update item count
			numItems--;
		}
	}


	//Function 'isEmpty' returns true if the queue is empty
	//and false otherwise
	bool isEmpty() {

		if (numItems > 0) {

			return false;
		}

		else {

			return true;
		}
	}



	//Function isFull returns true if the queue if full
	//and false otherwise
	bool isFull() {

		if (numItems < queueSize) {

			return false;
		}

		else {

			return true;
		}
	}


	//Function 'clear' resets the front and rear indices and sets numItems to 0
	void clear() {

		front = -1;
		rear = -1;
		numItems = 0;
	}
};
#endif // !INTQUEUE_H

