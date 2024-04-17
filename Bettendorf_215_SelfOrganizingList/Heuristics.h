#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"

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
		// Start at the beginning of the list.
		list.moveToStart();

		// If the list is empty, add 'it' to the list and return false.
		if (listSize == 0) {
			add(it);
			return false;
		}

		// If the list is not empty, search for 'it'.
		for (int i = 0; i < listSize; i++) {
			if (list.getValue() == it) {
				list.incrementCount();
				if (isCount) {
					// Count Heuristic Logic
					int count1 = list.getCount();
					list.prev();
					int count2 = list.getCount();
					// If the count of 'it' is greater than the count of the node before it, swap them
					if (count1 > count2 && list.currPos() + 1 > 0) {
						list.swap();
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
					// If 'it' is not the first element in the list, swap it with the node before it
					if (list.currPos() > 0) {
						list.prev();
						list.swap();
					}
					return true;
				}
			}
			list.next();
		}

		// If 'it' is not found and the list is full, add it at the end
		add(it);
		return false;

	}
	//Functions from SelfOrderedListADT
	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.

	 //Appends the 'it' to the list
	void add(const E& it) {
		list.moveToEnd();
		list.insert(it);
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

	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	void printlist() const {
		list.print();
	}
	void printlist(int n) const {
		list.print(n);
	}
};