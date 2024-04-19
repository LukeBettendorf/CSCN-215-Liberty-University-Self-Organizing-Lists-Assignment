#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>


//Heuristics class
// Last Modified: 04/18/2024
// Author: Luke Bettendorf

//This class is used to implement the three self-ordering heuristics: 
// Count, Move to Front, and Transposition.
template<class E>
class Heuristics : public SelfOrderedListADT<E> {
private:
	//List of elements
	LList<E> list;
	//Determines which heuristic to use
	bool isCount;
	bool isMoveToFront;
	bool isTranspose;

	//Number of comparisons
	int compares;

	//Size of the list
	int listSize;

	//This function is used to insert an element at the front of the list.
	//It is a helper function for reorder.
	void insertFront(E it) {
		// Move 'it' to the front of the list
		list.moveToStart();
		list.insert(it);
		listSize++;
	}


	//This function is used to reorder the list based on the heuristic used.
	//It is a helper function for find.
	bool reorder(const E& it) {

		// If the list is not empty, search for 'it'.
		for (int i = 0; i < listSize; i++) {
			list.moveToPos(i);
			compares++;
			//If 'it' is found in the list, increment the count of 'it' 
			// and reorder the list based on the heuristic used.
			if (list.getValue() == it) {
				list.incrementCount();
				if (isCount) {
					// Count Heuristic Logic
					int count1 = list.getCount();
					list.prev();
					int count2 = list.getCount();

					// Count Heuristic Logic
					// If the count of 'it' is greater than the count of the node before it,
					// Move it  towards the front.
					while (count1 > count2 && list.currPos() >= 0) {
						list.swap();
						list.prev();
						count2 = list.getCount();
					}
					return true;
				}
				else if (isMoveToFront) {
					// Move to Front Heuristic Logic
					// Get the count of the node
					int count = list.getCount();
					// Move 'it' to the front of the list
					list.moveToStart();
					list.insert(it);
					// Set the count of 'it' to the count of the node that was removed
					list.setCount(count);
					// Remove the duplicate 'it' from the list
					list.moveToPos(i + 1);
					list.remove();
					return true;
				}
				else if (isTranspose) {
					// Transposition Logic
					// If 'it' is not the first element in the list, swap it with the element before it.
					if (list.currPos() > 0 && listSize > 1) {
						list.prev();
						list.swap();
						return true;
					}
					else {
						return true;
					}
				}
			}
			list.next();
		}
		// If 'it' is not found in the list, add it to the list
		if (isCount == true || isTranspose == true) {
			add(it);
			return false;
		}
		else if (isMoveToFront == true) {
			insertFront(it);
			return false;
		}
	}


public:

	//Constructor
	//1 = Count Heuristic (default) 2 = Move to Front Heuristic 3 = Transposition Heuristic
	Heuristics(int heuristic=1) {

		//Initialize list / Variables
		LList<E> list;
		isCount = false;
		isMoveToFront = false;
		isTranspose = false;
		compares = 0;
		listSize = 0;
		if (heuristic == 1) {
			isCount = true;
		}
		else if (heuristic == 2) {
			isMoveToFront = true;
		}
		else if (heuristic == 3) {
			isTranspose = true;
		}
	}
	~Heuristics() {
		list.clear();
	}


	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	bool find(const E& it) {

		bool isfound = false;
		// If the list is empty, add 'it' to the list and return false.
		if (listSize == 0) {
			add(it);
			return isfound;
		}
		isfound = reorder(it);

		return isfound;

	}

	//Functions from SelfOrderedListADT
	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.

	 //Appends the 'it' to the list
	void add(const E& it) {
		list.append(it);
		listSize++;
	}

	//Returns the number of accumulated compares
	int getCompares() const {
		return compares;
	}
	//Returns the size of the list
	int size() const {
		return listSize;
	}

	//Prints the type of heuristic used
	void printType() const {
		//Type of Heuristic
		if (isCount) {
			std::cout << "Count Heuristic:" << endl;
		}
		else if (isMoveToFront) {
			std::cout << "Move to Front Heuristic:" << endl;
		}
		else if (isTranspose) {
			std::cout << "Transpose Heuristic:" << endl;
		}
	}

	//Print the entire list.
	void printlist() const {
		printType();
		std::cout << "The number of compares is: " << compares << endl;
		std::cout << "My final list structure with frequencies is:\n";
		list.print();
		std::cout << "My list size is: " << listSize << endl << endl;

	}
	//Print n nodes of the list.
	void printlist(int n) const {
		printType();
		std::cout << "The number of compares is: " << compares << endl;
		std::cout << "My final list structure with frequencies is:\n";
		list.print(n);
		std::cout << "My list size is: " << listSize << endl << endl;
	}

};