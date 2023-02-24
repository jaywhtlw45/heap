// Jason Whitlow 108698011
// csci115 lab4 HeapSort
// heapMain.cpp
// This program demonstrates the functionality of the HeapSortHeader-1.h class.
// NOTE: This program assumes sanitized input from user. Incorrect input will crash the program.

#include <iostream>
#include <string>
#include "HeapSortHeader-1.h"
using namespace std;

int getUserInput();

int main()
{
    Heap H; // create heap object
    int mainArr[100] = {6, 9, 10, 15, 8, 7, 2, 11, 13, 17};
    int n = 10; // heap size
    int i;      // index i
    int val;    // value to be inserted into heap
    int input;  // user input

    cout << "This program generates an array and then turns that array into a heap. The program assumes sanitized user input.Erroneous user input is not handled by this program." << endl
         << endl;

    cout << "Unsorted Array: " << endl
         << "\t";
    H.printArray(mainArr, n);

    cout << "Enter 0 to build a max_heap, enter 1 to build a min heap: ";
    input = getUserInput();
    cout << endl;

    // Max Heap
    if (input == 0)
    {
        cout << "Building a Max Heap: " << endl
             << "\t";
        H.buildMaxHeap(mainArr, n);
        H.printArray(mainArr, n);

        cout << "Adding 16 to the heap: " << endl
             << "\t";
        H.insert_value_maxHeap(mainArr, 16, n);
        H.printArray(mainArr, n);

        cout << "Extracting maximum from heap: " << endl
             << "\t";
        H.extract_maximum(mainArr, n);
        H.printArray(mainArr, n);

        cout
            << "Sorting a Max Heap: " << endl
            << "\t";
        H.ascendingHeapSort(mainArr, n);
        H.printArray(mainArr, n);
    }

    // Min Heap
    if (input == 1)
    {
        cout << "Building a Min Heap: " << endl
             << "\t";
        H.buildMinHeap(mainArr, n);
        H.printArray(mainArr, n);

        cout << "Adding 5 to the heap: " << endl
             << "\t";
        H.insert_value_minHeap(mainArr, 5, n);
        H.printArray(mainArr, n);

        cout << "Extracting minimum from heap: " << endl
             << "\t";
        H.extract_minimum(mainArr, n);
        H.printArray(mainArr, n);

          // cout
          //     << "calling buildMinHeap(): " << endl
          //     << "\t";
          // H.buildMinHeap(mainArr, n);
          // H.printArray(mainArr, n);

        cout << "Sorting a Min Heap: " << endl
             << "\t";
        H.descendingHeapSort(mainArr, n);
        H.printArray(mainArr, n);
    }

    cin.get();
    return 0;
}

int getUserInput()
{
    try
    {
        string sInput;
        int input;
        getline(cin, sInput);
        input = stoi(sInput);

        if (input != 0 && input != 1)
            throw input;

        return input;
    }
    catch (int input)
    {
        cout << "Enter a 0 or 1: ";
        getUserInput();
    }
}