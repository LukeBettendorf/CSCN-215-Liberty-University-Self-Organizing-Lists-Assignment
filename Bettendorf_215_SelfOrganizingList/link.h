#pragma once

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Modified 11/30/2023 -- Prof Sipantzi

// Singly linked list node
template <class E> 
class Link {
private:
    //Count of the number of times the element has been accessed
    int count;
public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list
  // Constructors
  Link(const E& elemval, Link* nextval =NULL)
  {
      element = elemval;  next = nextval; count = 0;
  }
  Link(Link* nextval = NULL) { next = nextval; count = 0; }

  //Increment count
  void incrementCount() {
	count++;
  }
  void setCount(int c) {
      count = c;
  }

  //Get count
  int getCount() const {
      return count;
  }
};
