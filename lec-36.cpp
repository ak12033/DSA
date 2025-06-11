#include<iostream>
#include<vector>
using namespace std;

//                                     Quich Sort
/*
int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high) {

    // Base Case
    if(low >= high){
        return ;
    }
    // Partition Karenge
    int p = partition(arr, low, high);

    // Left Part Sort Karo
    quickSort(arr, low, p-1);

    // Right Part Sort Karo
    quickSort(arr, p+1, high);
}
int main() {

    vector<int> arr = {2,4,42,23,4,3,2,12,3,4};
    int n = arr.size();

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;

    return 0;
}
*/

//                      Why is Quick Sort preferred for arrays?

// Quick Sort is generally preferred for arrays because it has good cache 
// locality and can be easily implemented in-place, which means it doesn’t 
// require any extra memory space beyond the original array. In Quick Sort, 
// we can use the middle element as the pivot and partition the array into 
// two sub-arrays around the pivot. This can be done by swapping elements, 
// and the pivot can be placed in its final position in the sorted array. 

//                      Why is Merge Sort preferred for Linked Lists?

// The advantage of Merge Sort for linked lists is that it doesn’t require random access
// to elements, which is not efficient for linked lists since we need to traverse the list
// linearly. Also, Merge Sort is a stable sort, which means it maintains the relative order
// of equal elements in the sorted list. This is important for linked lists, where the 
// original order of equal elements may be significant. However, Merge Sort requires extra 
// memory space for the merge step, which can be a disadvantage in some cases.