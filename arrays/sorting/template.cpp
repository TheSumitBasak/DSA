#include<iostream>
#include<vector>
using namespace std;


void print_arr(vector<int>& arr) {
    for(int ele: arr) {
        cout << ele <<  " ";
    }
    cout << endl;
}

void _sort(vector<int>& arr, int size) {
    // Sort code
}

int main() {
    vector<int> arr = {1, 4, 2, 6, 9, 2};
    _sort(arr, arr.size());
    print_arr(arr);
}