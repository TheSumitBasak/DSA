#include<iostream>
#include<vector>
using namespace std;

/**
 * Quick sort algorithm: Take pivot(left, rifht, middle) find its true index by creating a number series like thing, 
 * less then values on left and greater then values on right
 * 
 * partition(arr, left, right, current)
 *      i=left-1
 *      j=0
 *      pivot = arr[current]
 *      for j=left+1 to j=right
 *          if arr[j] < pivot
 *              i++
 *              swap(arr[j], arr[i+1])
 *      swap(arr[i+1], arr[current]) 
 *      return i+1
 * 
 * quick_sort(arr, left, right)
 *      if(left >= right) return
 *      part = partition(arr, left, right, right)
 *      quick_sort(arr, left, part-1)
 *      quick_sort(arr, part+1, right)
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int left, int right, int current) {
    int i = left - 1;
    int pivot = arr[current];
    for (int j = left; j < right; j++)
    {
        if(arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[current]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int left, int right) {
    // Sort code
    if(left >= right)
        return;
    int part = partition(arr, left, right, right);
    quick_sort(arr, left, part - 1);
    quick_sort(arr, part + 1, right);
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    quick_sort(arr, 0, arr.size()-1);
    print_arr(arr);
}