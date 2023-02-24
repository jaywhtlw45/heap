// Jason Whitlow 108698011
// csci115 lab4 HeapSort
// HeapSortHeader-1.h
// This class converts an unsorted array into an heap.
// NOTE: ascendingHeapSort and descendingHeapsort were modified to sort the heap without printing.

#include <iostream>
using namespace std;

const int HEAP_SIZE = 100;

class Heap
{
public:
    int Arr[HEAP_SIZE];
    Heap() {}

    void printArray(int Arr[], int n);

    // Max heap
    void modifyValMax(int Arr[], int n, int i, int val);   // Modify value
    void insert_value_maxHeap(int Arr[], int val, int &n); // Adds value at the end of array and calls max_heapify
    void max_heapify(int Arr[], int i, int n);             // Maintains the max heap property
    int extract_maximum(int Arr[], int &n);                // Return the maximum element in heap and swap last element with first element
    void ascendingHeapSort(int Arr[], int n);              // Sorts the array in ascending order
    void buildMaxHeap(int Arr[], int n);                   // Heapifies entire list

    // Min Heap
    void modifyValMin(int Arr[], int n, int i, int val);   // Modify value
    void insert_value_minHeap(int Arr[], int val, int &n); // Adds value at the end of array and calls min_heapify
    void min_heapify(int Arr[], int i, int n);             // Maintains min heap property
    int extract_minimum(int Arr[], int &n);                // Return the minimum element in heap and swap last element with first element
    void descendingHeapSort(int Arr[], int n);             // Sorts the array in descending order
    void buildMinHeap(int Arr[], int n);                   // Heapifies entire list
};

void Heap::printArray(int Arr[], int n)
{
    if (n < 1 || n > HEAP_SIZE)
    {
        cout << "printArray() error" << endl;
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        //cout << "Arr[" << i << "]=" << Arr[i] << endl;
        cout << Arr[i] << " ";
    }
    cout << endl;
}

//*************************************************
// Max Heap functions()
//*************************************************

// Modifies the value of an 'existing' element.
void Heap::modifyValMax(int Arr[], int n, int i, int val)
{
    if ((i < 0) || (i > HEAP_SIZE) || (i > n - 1))
    {
        cout << "modifyValMax() error" << endl;
        return;
    }

    Arr[i] = val;
    max_heapify(Arr, i, n);
}

// Inserts a new node at the end of the heap and increases the heap size 'n' by 1.
void Heap::insert_value_maxHeap(int Arr[], int val, int &n)
{
    if (n < 0 || n >= HEAP_SIZE)
    {
        cout << "insert_value_maxHeap() error" << endl;
        return;
    }

    // add new node to heap
    n += 1;
    Arr[n - 1] = val;

    // compare parent node to child node and swap positions if child > parent
    int parent = n / 2 - 1; 
    int child = n - 1;      
    while (parent >= 0 && Arr[child] > Arr[parent])
    {
        int temp = Arr[parent];
        Arr[parent] = Arr[child];
        Arr[child] = temp;

        child = parent;
        parent = (parent - 1) / 2;
    }
}

// Ceates a sub heap using index 'i'.
void Heap::max_heapify(int Arr[], int i, int n)
{
    if (n < 1 || n > HEAP_SIZE)
    {
        cout << "max_heapify() error" << endl;
        return;
    }
    if (n == 1)
        return;

    int left = i * 2 + 1;       // left child of i
    int right = i * 2 + 2;      // right child of i
    int largest;

    // find the largest between i, left, and right
    if (left <= (n - 1) && Arr[left] > Arr[i])
        largest = left;
    else
        largest = i;

    if (right <= (n - 1) && Arr[right] > Arr[left])
        largest = right;

    if (largest != i)
    {
        int temp = Arr[largest];
        Arr[largest] = Arr[i];
        Arr[i] = temp;

        max_heapify(Arr, largest, n);
    }
}

// Returns and removes the root of the heap.
int Heap::extract_maximum(int Arr[], int &n)
{
    if (n < 1 || n > HEAP_SIZE)
    {
        cout << "extract_maximum() error" << endl;
        return INT_MAX;
    }
    if (n == 1)
    {
        n = 0;
        return Arr[0];
    }

    // swap first and lest node of heap
    int temp = Arr[n - 1];
    Arr[n - 1] = Arr[0];
    Arr[0] = temp;

    // remove last node and heapify the root
    n -= 1;
    max_heapify(Arr, 0, n);

    // NOTE: Arr[n] has already been removed from the heap
    return Arr[n];
}

// Sorts the heap by swapping the root and last element, then calling max_heapify().
void Heap::ascendingHeapSort(int Arr[], int n)
{
    if (n < 1 || n > HEAP_SIZE)
    {
        cout << "ascendingHeapSort() error" << endl;
        return;
    }
    if (n == 1)
        return;

    // heap sort the list
    buildMaxHeap(Arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        int temp = Arr[i];
        Arr[i] = Arr[0];
        Arr[0] = temp;

        max_heapify(Arr, 0, i);
    }

    // reverse the list order
    for (size_t i = 0; i < n / 2; i++)
    {
        int temp = Arr[i];
        Arr[i] = Arr[n - i - 1];
        Arr[n - i - 1] = temp;
    }
}

// Converts an array into a heap.
void Heap::buildMaxHeap(int Arr[], int n)
{
    if (n < 1 || n > HEAP_SIZE)
    {
        cout << "buildMaxHeap() error" << endl;
        return;
    }
    if (n == 1)
        return;

    for (int j = n / 2 - 1; j >= 0; j--)
    {
        int i = j;
        max_heapify(Arr, i, n);
    }
}

//*******************************************************
// Min Heap Functions
//*******************************************************

// Modifies the value of an 'existing' element.
void Heap::modifyValMin(int Arr[], int n, int i, int val)
{
    if ((i < 0) || (i > HEAP_SIZE) || (i > n - 1))
    {
        cout << "modifyValMin() error" << endl;
        return;
    }

    Arr[i] = val;
    min_heapify(Arr, i, n);

}

// Inserts a new node at the end of the heap and increases the heap size 'n' by 1.
void Heap::insert_value_minHeap(int Arr[], int val, int &n)
{
      if (n < 0 || n >= HEAP_SIZE)
    {
        cout << "insert_value_minHeap() error" << endl;
        return;
    }

    // add new node to heap
    n += 1;
    Arr[n - 1] = val;

    // compare parent node to child node and swap positions if child > parent
    int parent = n / 2 - 1; // parent node
    int child = n - 1;      // child node
    while (parent >= 0 && Arr[child] < Arr[parent])
    {
        int temp = Arr[parent];
        Arr[parent] = Arr[child];
        Arr[child] = temp;

        child = parent;
        parent = (parent - 1) / 2;
    }
}

// Ceates a sub heap using index 'i'.
void Heap::min_heapify(int Arr[], int i, int n)
{
     if (n < 1 || n > HEAP_SIZE)
    {
        cout << "min_heapify() error" << endl;
        return;
    }
    if (n == 1)
        return;

    int left = i * 2 + 1;  // left child of i
    int right = i * 2 + 2; // right child of i
    int smallest;

    // find the largest between i, left, and right
    if (left <= (n - 1) && Arr[left] < Arr[i])
        smallest = left;
    else
        smallest = i;

    if (right <= (n - 1) && Arr[right] < Arr[left])
        smallest = right;

    if (smallest != i)
    {
        int temp = Arr[smallest];
        Arr[smallest] = Arr[i];
        Arr[i] = temp;

        min_heapify(Arr, smallest, n);
    }
}

// Returns and removes the root of the heap.
int Heap::extract_minimum(int Arr[], int &n)
{
      if (n < 1 || n > HEAP_SIZE)
    {
        cout << "extract_minimum() error" << endl;
        return INT_MAX;
    }
    if (n == 1)
    {
        n = 0;
        return Arr[0];
    }

    // swap first and lest node of heap
    int temp = Arr[n - 1];
    Arr[n - 1] = Arr[0];
    Arr[0] = temp;

    // remove last node and heapify the root
    n -= 1;
    min_heapify(Arr, 0, n);

    // NOTE: Arr[n] has already been removed from the heap
    return Arr[n];
}

// Sorts the heap by swapping the root and last element, then calling min_heapify().
void Heap::descendingHeapSort(int Arr[], int n)
{
     if (n < 1 || n > HEAP_SIZE)
    {
        cout << "descendingHeapSort() error" << endl;
        return;
    }
    if (n == 1)
        return;

    // heap sort the list
    buildMinHeap(Arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        int temp = Arr[i];
        Arr[i] = Arr[0];
        Arr[0] = temp;

        min_heapify(Arr, 0, i);
    }

    // reverse the list order
    for (size_t i = 0; i < n / 2; i++)
    {
        int temp = Arr[i];
        Arr[i] = Arr[n - i - 1];
        Arr[n - i - 1] = temp;
    }
}

// Converts an array into a heap.
void Heap::buildMinHeap(int Arr[], int n)
{
    if (n < 1 || n > HEAP_SIZE)
    {
        cout << "buildMinHeap() error" << endl;
        return;
    }
    if (n == 1)
        return;

    for (int j = n / 2 - 1; j >= 0; j--)
    {
        int i = j;
        min_heapify(Arr, i, n);
    }
}