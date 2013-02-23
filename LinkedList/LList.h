//custom List class
#include <iostream>
using namespace std;
#include "Node.h"

class LList { 


	Node *head;

public:
	
	LList() {

		head = NULL;
	}

	
	void Append(int data) {

		// Create a new node
		Node* newNode = new Node();
		newNode->SetData(data);
		newNode->SetNext(NULL);

		// Create a temp pointer
		Node *tmp = head;

		if ( tmp != NULL ) {
			// Nodes already present in the list
			// Parse to end of list
			while ( tmp->Next() != NULL ) {
				tmp = tmp->Next();
			}

			// Point the last node to the new node
			tmp->SetNext(newNode);
		}
		else {
			// First node in the list
			head = newNode;
		}
	}
	
	void AppendMiddle(int data, int position) {
		Node *newNode;
		Node *nodePtr;
		Node *previousNode = NULL;

		if(position < 0) {
			cout << "Cannot enter " << data << " into list." << endl;
			cout << "Please enter a position larger than or equal to 0." << endl;
			return;
		}

		newNode = new Node();
		
		newNode->SetData(data);
		nodePtr = head;

		//iterate to the two nodes you want to insert in between
		for(int i = 0; i < position; i++) {
			previousNode = nodePtr;
			nodePtr = nodePtr->Next();
		}
		if(previousNode) {    //if there is a previous node
			previousNode->SetNext(newNode);		//set previousNode's next pointer to the newNode that will be inserted
			newNode->SetNext(nodePtr);		//set the newly inserted newNode's next pointer to  nodePtr which has been iterated one step AFTER where we inserted our newNode.
		}
		else {        //there is no previous node, nodePtr must be head
			head = newNode;		//point the head to the new node
			newNode->SetNext(nodePtr);		//point next to the old first
		}
	}


	//Delete a node from the list based on the list item supplied by the user
	void Delete(int data) {

		Node *currentNode = head;	//initialize a pointer to the head node as a starting point
		Node *previousNode = NULL;
		
		//no nodes
		if(currentNode == NULL) {
			cout << "List is empty." << endl;
			return;
		}
		//Deleting the first node
		if(currentNode->Data() == data) {
			previousNode = currentNode;		//keep track of the previous node
			currentNode = currentNode->Next();	//move the current node to the next node
			head = currentNode;		//update the head value.
			delete previousNode;	//finally delete the previousNode since it will not be linked to anything.
			return;
		}
		else {
			///If not at the first node, traverse the list until found.
			while(currentNode->Next() != NULL) {
				if(currentNode->Data() == data) {   //if found, break out of the while loop.
					break;
				}
				previousNode = currentNode;		//record the current node as the previous node
				currentNode = currentNode->Next();	//move the current node forward by one to facilitate list traversal.
			}

			/*If the traversal from the while loop still fails to find anything, return an error message
			and break completely out of the else block. If data is found, the statement in the if evaluation will be false. 
			and this block will be skipped.*/
			if(currentNode->Data() != data) {
				cout << "Invalid search: Item does not exit. Returning original, unaltered list." << endl;
				return;
			}

			/*Set the previous node to point to the node after the node we're trying to delete.*/
			previousNode->SetNext(currentNode->Next());
			delete currentNode;		//finally delete the node from which we have removed all links.
		}
		
	}
	

	int ListLength() {
		Node *current = head;
		int count = 0;

		while(current != NULL) {
			count++;
			current = current->Next();
		}
		return count;
	}

	//Iterative function to reverse a list
	void reverse() {

		Node* currentLink = head;
		Node* nextLink = NULL;
		Node* prevLink = NULL;

		while(currentLink != NULL){ 
			head = currentLink;
			nextLink = currentLink->Next();
			currentLink->SetNext(prevLink);
			prevLink = currentLink;
			currentLink = nextLink;
		}
	}

	Node* Head() {
		Node* currentNode = head;
		return currentNode;
	}

	Node* Tail() {
		Node* tail = head;

		while(tail->Next() != NULL) {
			tail = tail->Next();
		}
		return tail;
	}
	
	
	//Print the contents of the list
	void Print() {

		/*create a temporary node that will point to the head node,
		so that we can have a starting point to perform traversal operations.
		*/
		Node *temp = head;

		//No nodes case
		if(temp == NULL) {
			cout << "List is empty" << endl;
			return;
		}

		//one node in the lsit
		if (temp->Next() == NULL) {
			cout << temp->Data();
			cout << " --> ";
			cout << "NULL" << endl;
		}
		else {
			//parse and print the list
			while(temp != NULL) {
				cout << temp->Data();
				cout << " --> ";
				temp = temp->Next();
			}
			cout << "NULL" << endl << endl;
		}

	}


};