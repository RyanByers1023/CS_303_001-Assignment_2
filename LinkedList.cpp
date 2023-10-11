#include "LinkedList.h"

void LinkedList::push_front(int data) { //push element to front of list (new header pointer)
	Node* newNode = new Node(data);
	if (headerPtr == NULL) { //list is empty
		headerPtr = newNode;
		tail = newNode;
		numItems++;
	}
	else { //redefine headerPtr with new value
		newNode->nextNode = headerPtr;
		headerPtr = newNode;
		numItems++;
	}
}

void LinkedList::push_back(int data) { //push element to back of list
	Node* newNode = new Node(data);
	if (headerPtr == NULL) { //list is empty
		headerPtr = newNode;
		tail = newNode;
		numItems++;
		return;
	}
	Node* temp = headerPtr;
	while (temp->nextNode != NULL) { //traverse to end of list
		temp = temp->nextNode;
	}
	temp->nextNode = newNode; //make previously last value point to new last value that has just been created
	tail = newNode; //redefine tail;
	numItems++;
}

void LinkedList::pop_front() { //remove element from front of list
	if (headerPtr == NULL) { //list is empty
		cout << "pop_front attempted, but list was empty." << endl;
		return;
	}
	else if (headerPtr->nextNode == NULL) { //only 1 item in list
		delete headerPtr;
		headerPtr = NULL;
		tail = NULL;
		numItems--;
	}
	else {
		Node* temp = headerPtr;
		headerPtr = headerPtr->nextNode; //second value in list is now the first value in the list
		delete temp; //delete original first value
		numItems--;
	}
}

void LinkedList::pop_back() {
	if (headerPtr == NULL) { //list is empty
		cout << "pop_back attempted, but list was empty." << endl;
		return;
	}
	if (headerPtr->nextNode == NULL) { //only 1 item in list
		delete headerPtr;
		headerPtr = NULL;
		tail = NULL;
		numItems--;
		return;
	}
	Node* temp1 = headerPtr;
	while (temp1->nextNode->nextNode != NULL) { //traverse to second to last item in list
		temp1 = temp1->nextNode;
	}
	delete tail; //delete previous last item
	tail = temp1; //make item previous to final item the new final item
	numItems--;
}

int LinkedList::front() { //returns the header pointer of the list
	if (headerPtr == NULL) {
		return -1;
	}
	else {
		return headerPtr->data;
	}
	
}

int LinkedList::back() { //returns the tail of the list
	if (headerPtr == NULL) {
		return -1;
	}
	else {
		return tail->data;
	}
}

bool LinkedList::empty() { //returns a boolean (list empty (T) or not? (F))
	if (headerPtr == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void LinkedList::insert(int index, int data) { //insert user specified element at user specified index
	Node* newNode = new Node(data);
	if (headerPtr == NULL) { //list is empty, index does not matter, insert at beginning
		headerPtr = newNode;
		numItems++;
		return;
	}
	else if (index == 0) { //inserting item at beginning of list
		Node* tempHeader = headerPtr;
		headerPtr = newNode;
		newNode->nextNode = tempHeader;
		numItems++;
		return;
	}
	Node* currentNode = headerPtr;
	Node* prevNode = headerPtr;
	int currentIndex = 0;
	while (currentNode->nextNode != NULL) { //traverse to end of list or specified index, whichever comes first
		prevNode = currentNode;
		currentNode = currentNode->nextNode;
		currentIndex++;
		if (currentIndex == index) {
			break;
		}
	}
	if (index >= numItems - 1) { //index out of range or index == numItems - 1 (last index of list), either way, insert value at end of list. (temp1 will always end up being the last item in this particular case)
		currentNode->nextNode = newNode;
		tail = newNode;
		numItems++;
		return;
	}
	else { //inserting item into middle of list
		prevNode->nextNode = newNode;
		newNode->nextNode = currentNode;
		numItems++;
	}

}

bool LinkedList::remove(int index) { //remove element at user specified index
	if (headerPtr == NULL) { //list is empty, item not removed, return false
		cout << "remove attempted, but list was empty." << endl;
		return false;
	}
	else if (index > numItems - 1) { //index out of range
		cout << "remove attempted, but provided index was out of range." << endl;
		return false;
	}
	else if (headerPtr->nextNode == NULL) { //there is only 1 item in list. delete headerPtr
		delete headerPtr;
		headerPtr = NULL;
		tail = NULL;
		numItems--;
		return true;
	}
	else if (index == 0) { //remove 1st item in list
		Node* temp = headerPtr;
		headerPtr = headerPtr->nextNode;
		delete temp;
		numItems--;
		return true;
	}
	Node* currentNode = headerPtr;
	Node* prevNode = headerPtr; //keeps track of the node that is before currentNode
	int currentIndex = 0; //this will be incremented to assist in finding the element that needs to be removed (if currentIndex == user supplied index, currentNode == the element that needs removing)
	while (currentNode->nextNode != NULL) {
		prevNode = currentNode;
		currentNode = currentNode->nextNode;
		currentIndex++;
		if (currentIndex == index) { //the index that the user wishes to remove an element from has been reached
			break;
		}
	}
	if (currentNode->nextNode == NULL) { //index to remove is the last item in the list--need to redefine tail in this instance
		prevNode->nextNode = NULL; //the item before the last item in the list now points to nothing as the next item (it is now the last item)
		tail = prevNode; //redefine tail as prevNode
		numItems--; //decrement number of items in the list
		delete currentNode; //delete last item in list
		return true;
	}
	else { //the item that is needing removing is somewhere in the middle of the list
		prevNode->nextNode = currentNode->nextNode; //these variables are now ordered as follows: prevNode ---> nextNode
		delete currentNode; //this points to the item at user supplied index, delete it
		numItems--; //decrement the number of items in the list
		return true;
	}
}

int LinkedList::find(const int item) { //returns -1 if item not found
	if (headerPtr == NULL) { //list is empty, no point in searching
		cout << "find attempted, but list was empty" << endl;
		return -1;
	}
	else if (item == headerPtr->data) { //item is the first item in the list, no need to do any searching
		return 0;
	}
	//we need to search the list for the item
	int index = 0; //this will be the value that is returned, will iterate as list is searched through
	Node* temp = headerPtr;
	while (temp != NULL) {
		if (temp->data == item) {
			return index; //item found, return current value of index
		}
		temp = temp->nextNode; //item not found yet, continue searching
		index++;
	}
	return -1; //item was not found
}

void LinkedList::print() { //this is just for testing purposes; prints linked list
	Node* temp = headerPtr;
	if (temp == NULL) {
		cout << "List is empty." << endl;
	}
	else {
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->nextNode;
		}
	}
	cout << endl;
}