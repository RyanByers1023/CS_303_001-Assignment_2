#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* nextNode;

	Node() {
		data = 0;
		nextNode = NULL;
	}

	Node(int data) {
		this->data = data;
		this->nextNode = NULL;
	}
};

class LinkedList {
	Node* headerPtr;
	Node* tail;
	int numItems;
public:
	LinkedList() {
		headerPtr = NULL;
		tail = NULL;
		numItems = 0;
	}
	void push_front(int data); //places element in the front of the list
	void push_back(int data); //places element in the back of the list
	void pop_front(); //removes first element of the list
	void pop_back(); //removes last element of list
	int front(); //returns value of the first element in the list
	int back(); //returns value of the last element in the list
	bool empty(); //returns true if list is empty, false otherwise
	void insert(int index, int data); //Insert item at position index(starting at 0). Insert at the end if index is beyond the end of the list
	bool remove(int index); //Remove the item at position index. Return true if successful; return false if index is beyond the end of the list
	int find(const int item); //Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found
	void print(); //prints the list
};
