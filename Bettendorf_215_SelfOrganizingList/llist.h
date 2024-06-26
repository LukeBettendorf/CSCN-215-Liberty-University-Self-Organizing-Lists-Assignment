#pragma once

#include "book.h"
#include "link.h"
#include "list.h"
#include <iostream>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Modified 11/30/2023 -- Prof Sipantzi

// This is the file to include in your code if you want access to the
// complete LList template class

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for LList. It is split into two parts
// because it is too big to fit on one book page
// Linked list implementation
template <class E> 
class LList : public List<E> {
private:
    Link<E>* head;       // Pointer to list header
    Link<E>* tail;       // Pointer to last element
    Link<E>* curr;       // Access to current element
    int cnt;    	       // Size of list

    void init() {        // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }

    void removeall() {   // Return link nodes to free store
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList() { init(); }    // Constructor
    ~LList() { removeall(); }                   // Destructor

    // Print list contents 
    void print() const {
        Link<E>* temp = head;
        while (temp->next != NULL) {
            if (temp->next != NULL) {
                int count = temp->next->getCount();
                std::cout << temp->next->element << " - " << count << " ";
                temp = temp->next;
            }
        }
        std::cout << endl;
    }
    //This function prints the first n elements of the list
    void print(int n) const {
        Link<E>* temp = head;
        for (int i = 0; i < n; i++) {
			int count = temp->next->getCount();
			std::cout << temp->next->element << " - " << count << " ";
			temp = temp->next;
		}
		std::cout << endl;
    }


    void clear() { removeall(); init(); }       // Clear list

  // Insert "it" at current position
  void insert(const E& it) {
    curr->next = new Link<E>(it, curr->next);  
    if (tail == curr) tail = curr->next;  // New tail
    //Update the head if it was inserted at the beginning
    cnt++;
  }

  void append(const E& it) { // Append "it" to list
	tail = tail->next = new Link<E>(it, NULL);
    cnt++;
  }

  // Remove and return current element
  E remove() {
    Assert(curr->next != NULL, "No element");
    E it = curr->next->element;      // Remember value
    Link<E>* ltemp = curr->next;     // Remember link node
    if (tail == curr->next) tail = curr; // Reset tail
    curr->next = curr->next->next;   // Remove from list
    delete ltemp;                    // Reclaim space
    cnt--;			     // Decrement the count
    return it;
  }

  void moveToStart() // Place curr at list start
    { curr = head; }

  void moveToEnd()   // Place curr at list end
    { curr = tail; }

  // Move curr one step left; no change if already at front
  void prev() {
    if (curr == head) return;       // No previous element
    Link<E>* temp = head;
    // March down list until we find the previous element
    while (temp->next!=curr) temp=temp->next;
    curr = temp;
  }

  // Move curr one step right; no change if already at end
  void next()
    { if (curr != tail) curr = curr->next; }

  int length() const  { return cnt; } // Return length

  // Return the position of the current element
  int currPos() const {
    Link<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->next;
    return i;
  }

  // Move down list to "pos" position
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }

  const E& getValue() const { // Return current element
    Assert(curr->next != NULL, "No value");
    return curr->next->element;
  }


  //Get the number of times the data at the current position has been accessed
  int getCount() const {
      Assert(curr->next != NULL, "No value");
	  int count = curr->next->getCount();
      return count;
  }
  //Increment the count of the data at the current position
  void incrementCount() {
      Assert(curr->next != NULL, "No value");
      curr->next->incrementCount();
  }

  //Set the count of the data at the current position
  void setCount(int c) {
     Assert(curr->next != NULL, "No value");
     curr->next->setCount(c);
  }

  // Swap the data at the current position with the data at the next position
  void swap() {
      Assert(curr->next != NULL, "No value");
      Link<E>* temp = curr->next;
      curr->next = temp->next;
      temp->next = temp->next->next;
      //Update the tail if the tail was swapped.
      if (tail == curr->next) {
          tail = temp;
      }
      //Update the head if the head was swapped.
      if (head == curr->next) {
		  head = temp;
	  }
      curr->next->next = temp;
  }

};
