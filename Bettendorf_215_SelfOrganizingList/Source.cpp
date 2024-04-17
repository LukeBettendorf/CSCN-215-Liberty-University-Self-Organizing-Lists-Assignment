#include <iostream>
#include <string>
#include <vector>
#include "llist.h"
#include "Heuristics.h"


using namespace std;

int main() {
    char input[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    char search[14] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' };
    //Heuristic Demonstrations
    Heuristics<char> count(1);
    Heuristics<char> moveToFront(2);
    Heuristics<char> transpose(3);
    //Add each member of the array to the list.
    for (int i = 0; i < 8; i++) {
		count.add(input[i]);
        moveToFront.add(input[i]);
        transpose.add(input[i]);
	}
    cout << "Original List:\n";
    //print the list
    count.printlist();

    bool isfound = false;

    for (int i = 0; i < 14; i++) {
		isfound = count.find(search[i]);
        isfound = moveToFront.find(search[i]);
        isfound = transpose.find(search[i]);
	}
    //print the lists
    cout << "Count Heuristic:\n";
    count.printlist();

    return 0;
}