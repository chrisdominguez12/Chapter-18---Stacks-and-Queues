#pragma once
#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H

#include <iostream>
using namespace std;

//CONCEPT: A stack may be implemented as a linked list, and expand or shrink with each push or 
//pop operation

class DynIntStack {

private: 

	class StackNode {

		friend class DynIntStack;
		int value;
		StackNode *next;

		//Constructor
		StackNode(int value, StackNode *next = NULL) {

			this->value = value;
			this->next = next;
		}
	};


	StackNode *top;				//In terms of a linked list, this would be the head of the list

public:


	//Constructor
	DynIntStack() {

		top = NULL;
	}



	//Member function push will push the arugment onto the stack. 
	//It creates a new node whose value is the number to be pushed onto the stack and whose
	//successor pointer is the node that is currently the top of the stack, and then makes
	//the newly created node the new top of the stack.
	void push(int num) {

		//NOTE: This works even if the stack was empty previous to the push operation,
		//because in that case the successor to the new node at the top of the stack will be correctly
		//set to NULL
		top = new StackNode(num, top);
	}


	//function 'pop' will remove the value at the top of the stack 
	//and copy it into the variable passed as an argument. 
	//'pop' will delete nodes at the head of the list.
	void pop(int &num) {

		StackNode *temp;

		//function calls isEmpty first to determine whether there are any nodes in the stack.
		if (isEmpty()) {

			cout << "The stack is empty.\n";
			//exit(1);
		}

		else {

			//Pop value off top of stack
			num = top->value;
			temp = top;
			top = top->next;
			delete temp;
		}
	}



	//Function 'isEmpty' returns true if the stack is empty
	//or false otherwise
	bool isEmpty() {

		if (!top) {

			return true;
		}

		else {

			return false;
		}
	}


};
#endif // !DYNINTSTACK_H
