#include<iostream>
#include<vector>
using namespace std;

/**
 * Insertion Sort algorithm: Same like sorting cards
 * Take 2 stacks of cards one sorted and one unsorted, pick one element from unsorted and insert it into correct path in sorted
 * Take 1st element as sorted element
 * insertion_sort(arr, size)
 *      for i=1 to i=size-1
 *          key = arr[i]
 *          j=i-1
 *          while j >= 0 && key > arr[j]
 *              arr[j+1] = arr[j]
 *              j--;
 *          arr[j] = key
 *
 */
void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

void insertion_sort(vector<int>& arr, int size) {
    // Sort code
    for (int i = 1; i < size+1; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        print_arr(arr);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    insertion_sort(arr, arr.size());
    print_arr(arr);
}