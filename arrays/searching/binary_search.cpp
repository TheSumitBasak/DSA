#include<iostream>
#include<vector>
using namespace std;

/**
 * Binary search alogrithm: get mid index compare if same,
 * if not then if less than compare with mid section of left side or
 * if greater then compare with mid of ridght side until index is found or whole mid is same as start or end
 *
 * binary_search(arr, low, high, x)
 *      if(low > high) return -1;
 * 
 *      mid = low + (high - low) / 2
 *      if(arr[mid] == x)
 *          return mid
 * 
 *      if(arr[mid] > x) 
 *          return binary_search(arr, low, mid-1, x)
 * 
 *      if(arr[mid] < x)
 *          return binary_search(arr, mid+1, high, x)
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

int binary_search(vector<int>& arr, int low, int high, int x) {
    if(high >= low) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == x)
            return mid;

        if(arr[mid] > x)
            return binary_search(arr, low, mid - 1, x);
        return binary_search(arr, mid + 1, high, x);
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 2, 4, 6, 9};
    cout << binary_search(arr, 0, arr.size()-1, 2) << endl;
    cout << binary_search(arr, 0, arr.size()-1, 4) << endl;
    cout << binary_search(arr, 0, arr.size()-1, 5) << endl;

    return 0;
}