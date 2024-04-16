#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"

template<class E>
class Heuristics : public SelfOrderedListADT<E> {
private:
	//List of elements
	LList<E>* list;
	//Determines which heuristic to use
	bool isCount;
	bool isMoveToFront;
	bool isTransposition;

	//Number of comparisons
	int compares;

	//Size of the list
	int listSize;

public:

	//Constructor
	//1 = Count Heuristic (default) 2 = Move to Front Heuristic 3 = Transposition Heuristic
	Heuristics(int heuristic=1) {

		//Initialize list / Variables
		list = new LList<E>();
		isCount = false;
		isMoveToFront = false;
		isTransposition = false;
		compares = 0;
		listSize = 0;
		if (heuristic == 1) {
			isCount = true;
		}
		else if (heuristic == 2) {
			isMoveToFront = true;
		}
		else if (heuristic == 3) {
			isTransposition = true;
		}
	}
	~Heuristics() {
		//Delete list
		list->clear();
	}


	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	bool find(const E& it) {
		return true;
	}

	//Functions from SelfOrderedListADT
		//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.
	void add(const E& it) {} //Add new 'it' to the list

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

	}
	void printlist(int n) const {

	}

};