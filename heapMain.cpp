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

     cout << "  This program generates an array and then turns that array into a heap." << endl;
     cout << "  The program assumes sanitized user input." << endl;
     cout << "  Erroneous user input is not handled by this program." << endl
          << endl;

     cout << "Unsorted Array: " << endl
          << "\t";
     H.printArray(mainArr, n);

     cout << "Enter 0 to build a max_heap, enter 1 to build a min heap: ";
     input = getUserInput();
     while (input != 0 && input != 1)
          input = getUserInput();
     cout << endl;

     // Max Heap
     if (input == 0)
     {
          bool run = true;
          while (run)
          {
               cout << "1: Add a value to heap" << endl;
               cout << "2: Remove max number" << endl;
               cout << "3: Sort Heap" << endl;
               cout << "4: Exit" << endl
                    << endl;
               cout << "Enter choice: ";

               input = getUserInput();

               if (input == 1)
               {
                    cout << "Enter a value: ";
                    input = getUserInput();
                    H.insert_value_maxHeap(mainArr, input, n);
                    cout << "Heap:" << endl << "\t";
                    H.printArray(mainArr, n);
                    cout << endl;
               }
               if (input == 2)
               {
                    H.extract_maximum(mainArr, n);
                    cout << "Heap:" << endl << "\t";
                    H.printArray(mainArr, n);
                    cout << endl;
               }
               if (input == 3)
               {
                    H.ascendingHeapSort(mainArr, n);
                    cout << "Heap:" << endl << "\t";
                    H.printArray(mainArr, n);
                    cout << endl;
               }
               if (input == 4)
                    run = false;
          }
     }

     // Min Heap
     if (input == 1)
     {
          bool run = true;
          while (run)
          {
               cout << "1: Add a value to heap" << endl;
               cout << "2: Remove max number" << endl;
               cout << "3: Sort Heap" << endl;
               cout << "4: Exit" << endl
                    << endl;
               cout << "Enter choice: ";

               input = getUserInput();

               if (input == 1)
               {
                    cout << "Enter a value: ";
                    input = getUserInput();
                    H.insert_value_minHeap(mainArr, input, n);
                    cout << "Heap:" << endl << "\t";
                    H.printArray(mainArr, n);
                    cout << endl;
               }
               if (input == 2)
               {
                    H.extract_minimum(mainArr, n);
                    cout << "Heap:" << endl << "\t";
                    H.printArray(mainArr, n);
                    cout << endl;
               }
               if (input == 3)
               {
                    H.descendingHeapSort(mainArr, n);
                    cout << "Heap:" << endl << "\t";
                    H.printArray(mainArr, n);
                    cout << endl;
               }
               if (input == 4)
                    run = false;

               if (input <1 || input >5)
                    cout << "Enter a valid choice" << endl;

          }
     }

     cin.get();
     return 0;
}

int getUserInput()
{
     string sInput;
     int input;
     getline(cin, sInput);
     input = stoi(sInput);
     return input;
}