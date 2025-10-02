#include<iostream>
#include<vector>
using namespace std;

/**
 * Selection Sort Algorithm: Swap with the greatest element in the array with current index
 * selection_sort(arr, size)
 *      for i=0 to i=size-1
 *          for j=i+1 to j=size-2
 *              if arr[i] > arr[j]
 *                  swap(arr[j], arr[i])
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

void selection_sort(vector<int>& arr, int size) {
    for (int i = 0; i<size; i++) {
        for (int j = i + 1; j < size-1; j++) {
        if(arr[i] > arr[j])
            swap(arr[j], arr[i]);
    }
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    selection_sort(arr, arr.size());
    print_arr(arr);
}