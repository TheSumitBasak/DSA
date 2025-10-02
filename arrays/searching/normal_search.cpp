#include<iostream>
#include<vector>
using namespace std;

/**
 * Normal search alogrithm: iteritare through arr and check one by one
 * search(arr, size, x)
 *      for i=0 to size-1
 *          if(arr[i] == x)
 *              return i
 *      return -1
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

int search(vector<int>& arr, int size, int x) {
    for (int i = 0; i < size; i++)
        if(arr[i] == x)
            return i;
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 2, 4, 6, 9};
    cout << search(arr, arr.size(), 2) << endl;
    cout << search(arr, arr.size(), 4) << endl;
    cout << search(arr, arr.size(), 5) << endl;

    return 0;
}