//This program will use the 'InventoryStack' header file to implement a Dynamic Stack 
//of inventory parts. User will be prompted to fill the stack with parts and then given
//a list of options for what to do with the elements of the stack.

#include "InventoryStack.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;





int main() {

	InventoryStack mainStack;			//This will be the main stack where entries are added
	InventoryStack tempStack;			//This stack will only be used for the purposes of searching

	int serialNum;						//a part's serial number
	int lotNum;							//a part's lot number
	string manufactDate;				//manufacture date of part

	int userChoice;						//Used for menu selection
	char yORn = ' ';					//Used for yes or no questions
	
	cout << "\n\n\nWelcome to the Inventory Bin Program!"; 

	cout << "\n\nWhat would you like to do?";

	do {

		cout << "\n\n\nMENU";
		cout << "\n-------------------------------------------------------------";
		cout << "\n1. Add inventory item";
		cout << "\n2. Remove last item entered";
		cout << "\n3. Search for a specific item";
		cout << "\n4. Display all items in inventory and exit program";
		cout << "\n\nEnter Selection: ";
		cin >> userChoice;

		switch (userChoice) {

		case 1: 

			cout << "\n\nEnter item serial number: ";
			cin >> serialNum;

			cout << "\n\nEnter lot number: ";
			cin >> lotNum;

			cin.ignore();
			cin.clear();

			cout << "\n\nEnter manufacture date (MM/DD/YYYY): ";
			getline(cin, manufactDate);

			mainStack.push(serialNum, lotNum, manufactDate);

			cout << "\n\nItem added!";
			break;
		
		case 2: 

			cout << "\n\nRemoving last item entered...";

			mainStack.pop(serialNum, lotNum, manufactDate);

			cout << "\n\nItem Serial Number: " << serialNum;
			cout << "\nItem Lot Number: " << lotNum;
			cout << "\nItem Manufacture Date: " << manufactDate; 

			cout << "\n\n\nItem removed!";
			break;

		case 3: 

			cout << "\n\n\nItems in inventory will be displayed one by one in order of how they were entered.";
			cout << "\nIf the item you wish to remove appears, simply press Y to have it removed from the list.";


			while(!mainStack.isEmpty()) {

				mainStack.pop(serialNum, lotNum, manufactDate); 

				cout << "\n\nItem Serial Number: " << serialNum;
				cout << "\nItem Lot Number: " << lotNum;
				cout << "\nItem Manufacture Date: " << manufactDate;

				cout << "\n\n\nDo you wish to permanently remove item? (Y/N)";
				cin >> yORn;

				if (yORn == 'y' || yORn == 'Y') {

					cout << "\n\nItem removed!";
					break;

				} // end of if

				else if (yORn == 'n' || yORn == 'N') {

					cout << "\n\nNext item...";
					tempStack.push(serialNum, lotNum, manufactDate);

				} //end of else if
				
			} //end of for


			//This loop will return any elements moved back to their original position in main stack from temp stack
			while(!tempStack.isEmpty()) {

				tempStack.pop(serialNum, lotNum, manufactDate);
				mainStack.push(serialNum, lotNum, manufactDate);

			} //end of for

			break;


		case 4: 


			while(!mainStack.isEmpty()) {

				mainStack.pop(serialNum, lotNum, manufactDate);
				cout << "\n\n\nItem Serial Number: " << serialNum;
				cout << "\nItem Lot Number: " << lotNum;
				cout << "\nItem Manufacture Date: " << manufactDate;

			}

			break;
		}

	} while (userChoice != 4);

	system("pause");
	return 0;
}
