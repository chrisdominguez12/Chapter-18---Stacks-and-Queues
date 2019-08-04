#pragma once
#ifndef INTSTACK_H
#define INTSTACK_H


//NOTE: Even though the constructor dynamically allocates the stack array, it is still considered a static
//stack since the size of the stack does not change once it is allocated. 

class IntStack {

private:

	int *stackArray;
	int capacity;
	int top;

public:

	//Constructor
	IntStack(int capacity) {

		this->capacity = capacity;
		stackArray = new int[capacity];
		top = 0;
	}

	~IntStack() {

		delete[] stackArray;
	}

	//Adds a value to the stack
	void push(int value) {

		if (top == capacity) {

			throw Overflow();
		}

		stackArray[top] = value;
		top++;
	}


	//Removes a value from the stack and returns it
	//Value is passed by reference so that it can be used later in the program
	void pop(int &value) {

		if (isEmpty()) {

			throw Underflow();
		}

		top--;
		value = stackArray[top];
	}


	//Determines whether the stack is empty
	bool isEmpty() {

		if (top == 0) {

			return true;
		}

		else {

			return false;
		}
	}


	//Stack Exceptions

	//Overflow exception exception occurs during a call to push if there is no more room on the stack
	class Overflow {};


	//Underflow exception occurs when there is nothing on the stack for pop to return
	class Underflow {};
};

#endif 
