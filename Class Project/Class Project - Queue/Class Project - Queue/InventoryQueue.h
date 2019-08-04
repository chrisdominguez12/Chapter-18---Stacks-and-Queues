#pragma once
#ifndef INVENTORYQUEUE_H
#define INVENTORYQUEUE_H

#include <iostream>
#include <string>

using namespace std;

class InventoryQueue {

private: 

	class QueueNode {

		friend class InventoryQueue;
		
		int serialNum;					//A part's serial number
		int lotNum;						//A part's lot number
		string manufactDate;			//A part's date of manufacture

		QueueNode *next;				//Pointer variable


		//Constructor for QueueNode
		QueueNode(int serialNum, int lotNum, string manufactDate, QueueNode *next = NULL) {

			this->serialNum = serialNum;
			this->lotNum = lotNum;
			this->manufactDate = manufactDate;
			this->next = next;

		}
	};

	//Pointer variables to keep track of the front and rear of the queue
	QueueNode *front;
	QueueNode *rear;



public: 

	//Constructor for InventoryQueue
	InventoryQueue() {

		front = NULL;
		rear = NULL;

	}

	//Destructor for InventoryQueue
	~InventoryQueue() {

		clear();
	}


	//Function 'enqueue' inserts the value at the rear of the queue
	void enqueue(int serialNum, int lotNum, string manufactDate) {

		if (isEmpty()) {

			front = new QueueNode(serialNum, lotNum, manufactDate);
			rear = front;
		}

		else {

			rear->next = new QueueNode(serialNum, lotNum, manufactDate);
			rear = rear->next;
		}
	}



	//Function 'dequeue' removes the value at the front of queue and copies
	//the data into the arguments
	void dequeue(int &serialNum, int &lotNum, string &manufactDate) {

		QueueNode *temp;

		if (isEmpty()) {

			cout << "The queue is empty!\n";
		}

		else {

			serialNum = front->serialNum;
			lotNum = front->lotNum;
			manufactDate = front->manufactDate;
			temp = front;
			front = front->next;
			delete temp;
		}
	}


	//Function 'isEmpty' returns true if the queue is empty and false otherwise
	bool isEmpty() {

		if (front == NULL) {

			return true;
		}

		else {

			return false;
		}
	}


	//Function 'clear' dequeus all the elements in the queu
	void clear() {

		int serial;
		int lot;
		string date;

		while (!isEmpty()) {

			dequeue(serial, lot, date);
		}
	}


};
#endif // !INVENTORYQUEUE_H
