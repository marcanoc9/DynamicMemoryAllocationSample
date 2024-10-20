#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Allocate the array memory dynamically, using a pointer to an integer array
    int* myNumbers = new int;
    // declare variables
    string fileName;
    int totalNumbersToRead;
    int searchNumber;

    // prompts the user for a filename
    cout << "Filename? ";
    getline(cin, fileName);
    // ask the user how many numbers to read
    cout << "How many numbers to read from the file? ";
    cin >> totalNumbersToRead;
    // display message
    cout << "Read " << totalNumbersToRead << " numbers from " << fileName << endl;
    cout << "Which number should I look for? ";
    cin >> searchNumber;
    // opening the file to read using input stream object
    ifstream inFile(fileName);

    // If the input file could not be opened
    if (!inFile) {
        //  output an error message to cout
        cout << "The file \"" << fileName << "\" could not be opened.";
        return -1;
    }
    int index = 0;
    bool found = false;
    // iterate and read till the total numbers
    while (index < totalNumbersToRead) {
        double number;
        // read the number from file
        inFile >> number;
        // store in array
        myNumbers[index] = number;
        // check if number found in array
        if (myNumbers[index] == searchNumber) {
            cout << searchNumber << " is in the array." << endl;
            found = true;
            break;
        }
        index++;
    }
    // Closing input streams
    inFile.close();
    if (!found) {
        cout << searchNumber << " not found in the array." << endl;
    }

    //  free the memory with delete
    delete myNumbers;
    return 0;
}
