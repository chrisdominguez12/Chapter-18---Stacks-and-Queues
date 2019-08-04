#pragma once
#ifndef INVENTORYSTACK_H
#define INVENTORYSTACK_H

#include <iostream>
#include <string>

using namespace std;

//This class will allow for a Dynamic Stack to be created during program execution.
//Dynamic stack allows for the stack to expand with the push function or shrink with the
//pop function.

class InventoryStack {

private: 

	class StackNode {

		friend class InventoryStack;
		int lotNum;						//Integer that holds a part's lot number
		int serialNum;					//Integer value that holds a part's serial number
		string manufactDate;			//Holds the date that the part was manufactured
		StackNode *next;				//Pointer variable


		//Constructor for 'StackNode' class
		StackNode(int serialNum, int lotNum, string manufactDate, StackNode *next = NULL) {

			this->serialNum = serialNum;
			this->lotNum = lotNum;
			this->manufactDate = manufactDate; 
			this->next = next;

		}
	};

	//Pointer variable for the top of the stack (head of the linked list)
	StackNode *top; 



public: 

	//Constructor for 'InventoryStack' class
	InventoryStack() {

		top = NULL;
	}


	//**********************************************************
	//Member Function 'push'
	//Will push the argument passed onto the stack.
	//This is done by creating a new node whose data is to be pushed onto the stack and
	//whose successor pointer is the node that was currently the top of the stack. 
	//The newly created node becomes the NEW top of the stack.
	//***********************************************************

	void push(int serialNum, int lotNum, string manufactDate) {

		top = new StackNode(serialNum, lotNum, manufactDate, top);
	}


	//*********************************************************
	//Member function 'pop'
	//Function will remove the value at the top of the stack and 
	//copy it into the variable passed as an argument.
	//'pop' will delete nodes at the head of the list
	//*********************************************************
	
	void pop(int &serialNum, int &lotNum, string &manufactDate) {
	
		StackNode *temp; 

		//Function call to 'isEmpty' to determine whether or not there are any nodes
		//left in the stack to be popped (removed)
		if (isEmpty()) {

			cout << "The stack is empty!\n";
		
		}

		else {

			//Pop nodes off the stack
			serialNum = top->serialNum;
			lotNum = top->lotNum;
			manufactDate = top->manufactDate;
			temp = top; 
			top = top->next; 
			delete temp;

		}
	} 


	//*******************************************
	//Member function 'isEmpty'
	//Function returns true if the stack is empty
	//or false otherwise
	//*******************************************

	bool isEmpty() {

		if (top == NULL) {

			return true;
		}

		else {

			return false;
		}
	}

};


#endif // !INVENTORYSTACK_H

