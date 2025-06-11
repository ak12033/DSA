#include <iostream>
#include <vector>
using namespace std;

//                                    Selection Sort

// Selection sort is not stable because a sorting algorithm is considered 
// stable if two equal elements retain their relative order after sorting.

// Example 1 - arr = [3,2,1a,4,1b]
// Output - arr = [1a,1b,2,3,4]

// Example 2 - arr = [2a,4,3,2b,1]
// Output - arr = [1,2b,2a,3,4]

/*
void selectionSort(vector<int>& arr, int n){   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    
    selectionSort(arr, n);
    
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
*/



