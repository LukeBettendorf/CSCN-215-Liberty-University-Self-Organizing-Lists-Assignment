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
	

};