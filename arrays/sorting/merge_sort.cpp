#include<iostream>
#include<vector>
using namespace std;

/**
 * Merge sort Algorithm: Divide array into 2 parts sort each one and merge em
 * merge(arr, left, mid, right)
 *      n1 = mid - left + 1
 *      n2 = right - mid;
 *      arr_l = arr[left]...arr[mid]
 *      arr_r = arr[mid+1]...arr[right]
 *
 *      i = 0 j = 0 k = left
 *      while(i < n1 && j < n2)
 *          if(arr[i] > arr[j])
 *              arr[k] = r[j]
 *              j++
 *          else
 *              arr[k] = l[i]
 *              i++
 *          k++
 *
 *      while(i<n1)
 *          arr[k] = l[i]
 *          i++
 *          k++
 *      while(j<n2)
 *          arr[k] = r[j]
 *          j++
 *          k++
 *
 * merge_sort(arr, left, right)
 *      if(left >= rigth) return;
 *      mid = (left + right) / 2
 *      merge_sort(arr, left, mid)
 *      merge_sort(arr, mid+1, right)
 *      merge(arr, left, mid, right)
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1], r[n2];

    for (int i = 0; i < n1; i++)
        l[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        r[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(l[i] > r[j]) {
            arr[k] = r[j];
            j++;
        }
        else {
            arr[k] = l[i];
            i++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    // Sort code
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    merge_sort(arr, 0, arr.size()-1);
    print_arr(arr);
}