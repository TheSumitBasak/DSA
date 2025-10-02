#include<iostream>
#include<vector>
using namespace std;

/**
 * heap sort alogrithm: 
 * 
 * Max Heap: A type of binary tree where each parent node is higher then that of its child value
 * 
 * heapify(arr, size, l)
 *      largest = l
 *      left = (largest * 2) + 1
 *      right = (largest * 2) + 2
 * 
 *      if(left < size && arr[left] > arr[largest])
 *          largest = left
 *      if(right < size && arr[right] > arr[largest])
 *          largest = right
 *      
 *      if(largest != l)
 *          swap(arr[largest], arr[l])
 *          heapify(arr, size, largest)
 * 
 * heap sort: create heap then swap 1st and last element ~ iteritate n times
 * 
 * build_heap(arr, size)
 *      for i=(n/2)-1 to 0
 *          heapify(arr, size, i)
 * 
 * heap_sort(arr, size)
 *      build_heap(arr, size)
 *      for i=size-1 to 0
 *          swap(arr[0], arr[i])
 *          heapify(arr, size, i) 
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

void heapify(vector<int>& arr, int size, int largest) {
    int lrgst = largest;
    int l = (largest * 2) + 1;
    int r = (largest * 2) + 2;
    
    if(l < size && arr[l] > arr[lrgst])
        lrgst = l;
    if (r < size && arr[r] > arr[lrgst])
        lrgst = r;
    
    if(lrgst != largest) {
        swap(arr[lrgst], arr[largest]);
        heapify(arr, size, lrgst);
    }
}

void build_heap(vector<int>& arr, int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void heap_sort(vector<int>& arr, int size) {
    // Sort code
    build_heap(arr, size);
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    heap_sort(arr, arr.size());
    print_arr(arr);
}