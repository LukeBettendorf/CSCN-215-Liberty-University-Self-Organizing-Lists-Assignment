#include <iostream>
#include <string>
#include <vector>
#include "llist.h"
#include "Heuristics.h"


using namespace std;

int main() {
    char array[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    //Count Heuristic
    Heuristics<char> count(3);
    //Add each member of the array to the list.
    for (int i = 0; i < 8; i++) {
		count.add(array[i]);
	}
    count.printlist();
    bool isfound = false;
    isfound = count.find('C');
    cout << "Is C in the list? " << isfound << endl;
    //print the list
    count.printlist();

    return 0;
}