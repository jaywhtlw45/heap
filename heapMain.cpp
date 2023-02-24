// Jason Whitlow 108698011
// csci115 lab4 HeapSort
// heapMain.cpp
// 

#include <iostream>
#include "HeapSortHeader-1.h"
using namespace std;

int main()
{
    Heap H;             // create new heap
    int mainArr[100];   // 
    int n = 0;          // heap size
    int i;              // index
    int val;            // value to be inserted

    for (size_t i = 0; i < 11; i++)
    {
        mainArr[i] = 20-i*2;
        n += 1;
    }

    H.printArray(mainArr, n);
    H.descendingHeapSort(mainArr, n); 
    H.printArray(mainArr, n);

    

    // H.buildMaxHeap(mainArr, n);
// for (size_t i = 0; i < 10; i++)
// {
//     val = i*2;
//     H.insert_value_maxHeap(H.Arr, val, n);
// }

    //H.printArray(H.Arr, n);

    // i = 2;
    // H.Arr[i] = 3;
    // H.max_heapify(H.Arr, i, n);
    // H.printArray(H.Arr, n);

    // cout << "max: " << H.extract_maximum(H.Arr, n) << endl;
    // H.printArray(H.Arr, n);
    

    // H.modifyValMax(H.Arr, n, i, val);
    // cout << "n: " << n << endl;
    // cout << "Arr[ " << i << "]: " << H.Arr[i] << endl;

        cin.get();
    return 0;
}