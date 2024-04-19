#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>"
#include "llist.h"
#include "Heuristics.h"

//Luke Bettendorf
// CSCN 215 (003)
// Programming Assignment 4: Self-Organizing Lists
// Last Modified: 4/18/2024
//Source File


using namespace std;
void wait();

int main() {
    //Display the header
    cout << "Luke Bettendorf - CSCN 215 (003)\n";
    cout << "Programming Assignment 4: Self - Organizing Lists\n\n";
    cout << "Test #1: Demonstrate the heuristics with a list of characters\n\n";

    //---------------------------------------------------------------------------------------
    // Test #1: Demonstrate the heuristics with a list of characters
    char input[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    char search[14] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' };

    //Original List:
    LList<char> list;
    //Add each member of the input array to the list
    for (int i = 0; i < 8; i++) {
        list.append(input[i]);
    }
    //Print the list
    cout << "My starting list structure for all heuristics is:\n";
    list.print();
    cout << endl;

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

    bool isfound = false;

    //Search for each element in the list
    for (int i = 0; i < 14; i++) {
        isfound = count.find(search[i]);
        isfound = moveToFront.find(search[i]);
        isfound = transpose.find(search[i]);
    }

    //Print the lists
    //Count Heuristic
    count.printlist();
    //Move to Front Heuristic
    moveToFront.printlist();
    //Transpose Heuristic
    transpose.printlist();

    //---------------------------------------------------------------------------------------
    //Test #2: Read from a file
    cout << "\n\nTest #2: Demonstrate each heuristic with strings from a file:\n\n";

    //Open the file
    ifstream infile;
    infile.open("test.txt");

    //Check if the file was opened successfully
    if (!infile) {
        cout << "Unable to open file";
        return 0;
    }

    //Initialize a vector to store the words
    string line;
    vector<string> words;

    //Read the file line by line and add each word to the vector
    while (getline(infile, line)) {
        //Initialize a string stream to read the line
        stringstream ss(line);
        string word;
        //Read the line word by word
        while (ss >> word) {
            words.push_back(word);
        }
    }
    //Initizlize 3 lists, one for each heuristic
    Heuristics<string> countList(1);
    Heuristics<string> moveToFrontList(2);
    Heuristics<string> transposeList(3);


    //Search for each word in each list
    for (int i = 0; i < words.size(); i++) {
        countList.find(words[i]);
        moveToFrontList.find(words[i]);
        transposeList.find(words[i]);
    }

    //Print the lists
    countList.printlist(10);
    moveToFrontList.printlist(10);
    transposeList.printlist(10);

    wait();
    return 0;
}

//Wait Function
//Used in CSCN 111-112
void wait()
{
    //The following if-statement checks to see how many characters are in cin's buffer
    //If the buffer has characters in it, the clear and ignore methods get rid of them.
    if (std::cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clear the input buffer 
    }
    std::cout << "Press the Enter key to continue ... ";
    std::cin.get();
}