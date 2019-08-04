//This program will use the 'InventoryQueue' header file to implement a Dynamic Queue for 
//inventory parts. User will be prompted to fill the queue and given a list of options for 
//what to do with those parts.

#include "InventoryQueue.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	InventoryQueue mainQueue;
	InventoryQueue tempQueue;

	int serialNum;				//Part's serial number
	int lotNum;					//part's lot number
	string manufactDate;		//Date manufactured

	int userChoice;				//Used for menu selection
	char yORn;					//yes or no

	cout << "\n\n\nWelcome to the Inventory Bin Program!";

	cout << "\n\nWhat would you like to do?";

	do {

		cout << "\n\n\nMENU";
		cout << "\n-------------------------------------------------------------";
		cout << "\n1. Add inventory item";
		cout << "\n2. Remove first item entered";
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

			mainQueue.enqueue(serialNum, lotNum, manufactDate);

			cout << "\n\nItem added!";
			break;

		case 2:

			cout << "\n\nRemoving last item entered...";

			mainQueue.dequeue(serialNum, lotNum, manufactDate);

			cout << "\n\nItem Serial Number: " << serialNum;
			cout << "\nItem Lot Number: " << lotNum;
			cout << "\nItem Manufacture Date: " << manufactDate;

			cout << "\n\n\nItem removed!";
			break;

		case 3:

			cout << "\n\n\nItems in inventory will be displayed one by one in order of how they were entered.";
			cout << "\nIf the item you wish to remove appears, simply press Y to have it removed from the list.";


			while(!mainQueue.isEmpty()) {

				mainQueue.dequeue(serialNum, lotNum, manufactDate);

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
					tempQueue.enqueue(serialNum, lotNum, manufactDate);
				} //end of else if

			} //end of for


			//This loop will return any elements moved back to their original position in main queue from temp queue
			while (!tempQueue.isEmpty()) {

				tempQueue.dequeue(serialNum, lotNum, manufactDate);
				mainQueue.enqueue(serialNum, lotNum, manufactDate);

			} //end of for

			break;


		case 4:


			while (!mainQueue.isEmpty()) {

				mainQueue.dequeue(serialNum, lotNum, manufactDate);
				cout << "\n\n\nItem Serial Number: " << serialNum;
				cout << "\nItem Lot Number: " << lotNum;
				cout << "\nItem Manufacture Date: " << manufactDate << endl;
			}

			break;
		}

	} while (userChoice != 4);

	system("pause");
	return 0;
}
