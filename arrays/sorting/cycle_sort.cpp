#include<iostream>
#include<vector>
using namespace std;

/** 
 * Cycle Sort alogrithm: Start at zero find its true index then start cycle till true index is same as current index
 * cycle_sort(arr, size)
 *      for i=0 to arr.size-2
 *          current = arr[i]
 *          pos = i
 *          for j=i+1 to arr.size-1
 *              if(arr[j] < current)
 *                  pos++
 *          if(pos == i)
 *              continue
 *          while(arr[pos] == current)
 *              pos++        
 *              swap(arr[pos], current)
 *              while(pos != i) 
 *                  pos = i
 *              for j=i+1 to arr.size-1
 *                  if(arr[j] < current)
 *                      pos++
 *              while(arr[pos] == current)
 *                  pos++
 *            
 *              swap(arr[pos], current)
 * 
 */

void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

void cycle_sort(vector<int>& arr, int size) {
    // Sort code
    for (int start = 0; start < size - 1; start++) {
        int pos = start;
        int current = arr[start];

        for (int i = start + 1; i < size; i++) 
            if(arr[i] < current)
                pos++;
        
        if(pos == start)
            continue;
        
        while(arr[pos] == current)
            pos++;

        swap(arr[pos], current);
        while(pos != start) {
            pos = start;

            for (int i = start + 1; i < size; i++) 
                if(arr[i] < current)
                    pos++;

            while(arr[pos] == current)
                pos++;

            swap(arr[pos], current);        
        }
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    cycle_sort(arr, arr.size());
    print_arr(arr);
}