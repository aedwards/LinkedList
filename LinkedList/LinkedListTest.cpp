//simple test for Linked List

#include "LList.h"
#include <iostream>


int main() {

	//new list
	LList myList;
	int listCount;

	myList.Append(456);
	myList.Append(22);
	myList.Append(4);
	myList.Append(1095);
	myList.Append(188);
	
	myList.AppendMiddle(423, -1);	//test for entering negative position

	myList.AppendMiddle(423, 4);

	myList.Print();
	cout << "Number of items in list: " << myList.ListLength() << endl << endl;

	cout << "Deleting a node... " << endl;
	myList.Delete(95);		//test for deleting a non-existent node
	myList.Print();
	cout << "Number of items in list: " << myList.ListLength();

	

	getchar();		//pause console exit to examine output
	return 0;
}
