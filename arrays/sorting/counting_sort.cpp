#include<iostream>
#include<vector>
using namespace std;

/**
 * Counting sort algorithm: Creates map like arr of max element then stores count of each element.
 * Generates prefix sum of the count array to get the position of each element in the sorted array.
 *
 * counting_sort(arr, size)
 *      max = find_max(arr)
 *      count[max+1] = {0}
 *
 *      for i=0 to size-1
 *          count[arr[i]]++
 * 
 *      for i=1 to max
 *          count[i+1] += count[i]
 * 
 *      temp = arr
 *      for i=0 to size-1
 *          arr[count[temp[i]-1]] = temp[i]
 *          count[temp[i]--
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

int find_max(vector<int>& arr) {
    int mx = -1;
    for (int i = 0; i < arr.size(); i++) {
        if(mx < arr[i])
            mx = arr[i];
    }
    return mx;
}

void counting_sort(vector<int>& arr, int size) {
    // Sort code
    int mx = find_max(arr);
    int count_arr[mx+1] = {0};

    for (int i = 0; i < size; i++)
        count_arr[arr[i]]++;

    for (int i = 1; i <= mx; i++)
        count_arr[i + 1] += count_arr[i];

    vector<int> ar = arr;
    for (int i = size-1; i >= 0; i--) {
        arr[count_arr[ar[i]]-1] = ar[i];
        count_arr[ar[i]]--;
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    counting_sort(arr, arr.size());
    print_arr(arr);
}