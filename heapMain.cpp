#include <iostream>
#include "HeapSortHeader-1.h"
using namespace std;

int main()
{
    Heap H;        // create new heap
    int n = 0;     // heap size
    int i;         // index
    int val;       // value to be inserted

for (size_t i = 0; i < 10; i++)
{
    val = i*2;
    H.insert_value_maxHeap(H.Arr, val, n);
}

    //H.printArray(H.Arr, n);

    i = 2;
    H.Arr[i] = 3;
    H.max_heapify(H.Arr, i, n);
    H.printArray(H.Arr, n);

    cout << "max: " << H.extract_maximum(H.Arr, n) << endl;
    H.printArray(H.Arr, n);
    

    // H.modifyValMax(H.Arr, n, i, val);
    // cout << "n: " << n << endl;
    // cout << "Arr[ " << i << "]: " << H.Arr[i] << endl;

        cin.get();
    return 0;
}