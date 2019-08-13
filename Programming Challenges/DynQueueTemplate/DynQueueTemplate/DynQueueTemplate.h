#pragma once
#ifndef DYNQUEUETEMPLATE_H
#define DYNQUEUETEMPLATE_H	

#include <iostream>
#include <cstdlib>

using namespace std;



//This header file demonstrates the use of templates for a dynamic queue. 
//This allows the header file to be used by various data types instead of only one.


template <typename T>
class DynQueueTemplate {

private: 

	struct queueNode {

		T data;				//Node value
		queueNode *next;	//Pointer to next node
	};

	queueNode *front;			//Pointer to the front of the queue
	queueNode *back;			//Pointer to the end of the queue


	int numNodes;				//Tracks the number of items in queue


public:

	//Constructor
	DynQueueTemplate() {

		front = NULL;
		back = NULL;
		numNodes = 0;
	}

	/*
	~DynQueueTemplate() {

		clear();
	}
	*/
	template<class T>
	void enqueue(T value) {

		if (isEmpty()) {

			front = new queueNode(value);
			back = front;
		}


		else {

			back->next = new queueNode(value);
			back = back->next;
		}
	}


	template<class T>
	void dequeue(T &value) {

		queueNode *temp;
		if (isEmpty()) {

			cout << "\n\nThe queue is empty.";
		}

		else {

			value = front->value;
			temp = front;
			front = front->next;
			delete temp;
		}
	}
	

	bool isEmpty() {

		if (front == NULL) {

			return true;
		}

		else {

			return false;
		}
	}



	template<typename T>	
	void clear() {

		T value;

		while (!isEmpty()) {

			dequeue(value);
		}

	}
};
#endif // !DYNQUEUETEMPLATE_H

