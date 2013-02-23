//simple test for Linked List

#include "LList.h"
#include <iostream>


void main() {

	//new list
	LList myList;
	int listCount;
	
	
	myList.Append(456);
	myList.Append(22);
	myList.Append(4);
	myList.Append(1095);
	myList.Append(1888);
	
	//myList.AppendMiddle(499, -1);	//test for entering negative position

	//myList.AppendMiddle(423, 4);

	myList.Print();
	cout << "Number of items in list: " << myList.ListLength() << endl << endl;
	
	cout << "Deleting a node... " << endl;
	myList.Delete(456);
	cout << "\n\n";
	myList.Delete(10);		//test for deleting a non-existent node
	cout << "Number of items in list: " << myList.ListLength();
	cout << "\n\n";
	myList.Print();
	

	cout << "\nTail: " << myList.Tail()->Data();

	//reverse the list
	myList.reverse();
	cout << "\n\nList reversed: ";
	myList.Print();
	cout << "Head: " << myList.Head()->Data();		//returns the head of the list
	
	getchar();		//pause console exit to examine output
}
