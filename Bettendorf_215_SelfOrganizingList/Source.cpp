#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>"
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

    bool isfound = false;

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
    //Test with a file
    ifstream infile;
    infile.open("test.txt");

    //Check if the file was opened successfully
    if (!infile) {
        cout << "Unable to open file";
        return 0;
    }

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

    return 0;
}
