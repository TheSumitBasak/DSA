#include<iostream>
#include<vector>
using namespace std;

/**
 * Bubble Sort Algorithm: Compare with the next element and swap if current is greater,
 * after each iteration n-i will have largest val.
 * bubble_sort(arr, size)
 *      for i=0 to i=size-1
 *          for j=0 to j=size-i-2
 *              if(arr[j] > arr[j+1])
 *                  swap(arr[j], arr[j+1])
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

void bubble_sort(vector<int>& arr, int size) {
    // Sort code
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    bubble_sort(arr, arr.size());
    print_arr(arr);
}