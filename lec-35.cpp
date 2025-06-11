#include <bits/stdc++.h>
using namespace std;

//                                          TUF
//                                      Merge sort
/*
void merge(vector<int> &arr, int low, int mid, int high) {

    // Temporary Array
    vector<int> temp; 
    
    // Starting index of left half of arr
    int left = low; 

    // Starting index of right half of arr
    int right = mid + 1;   

    // Storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // If elements on the left half are still left 
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    // If elements on the right half are still left 
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // Transfering all elements from temporary to arr 
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
    // Reason for line no. 41
    // let arr = [4,3,2,1] For the second half temp array is temp = [1,2]. While copying elements of 
    // temp to arr low = 2 and high = 3 but temp index starts from 0, 1. Therefore,
    // arr[2] = temp[2-2](not temp[2]) & arr[3] = temp[3-2](not temp[3])
}
void mergeSort(vector<int> &arr, int low, int high) {

    if (low >= high){
        return;
    }
    int mid = (low + high) / 2 ;

    // Left Half
    mergeSort(arr, low, mid);  

    // Right Half
    mergeSort(arr, mid + 1, high); 

    // Merging Sorted Halves
    merge(arr, low, mid, high);  
}
int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;

    return 0 ;
}
*/

//                                  Count Inversions
/*
int merge(vector<int> &arr, int low, int mid, int high) {

    int cnt = 0;

    // Temporary Array
    vector<int> temp; 
    
    // Starting index of left half of arr
    int left = low; 

    // Starting index of right half of arr
    int right = mid + 1;   

    // Storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
            right++;
        }
    }
    // If elements on the left half are still left 
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    // If elements on the right half are still left 
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // Transfering all elements from temporary to arr 
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high) {

    int cnt = 0;

    if (low >= high){
        return cnt;
    }
    int mid = (low + high) / 2 ;

    // Left Half
    cnt += mergeSort(arr, low, mid);  

    // Right Half
    cnt += mergeSort(arr, mid + 1, high); 

    // Merging Sorted Halves
    cnt += merge(arr, low, mid, high);  

    return cnt;
}
int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;

    int ans = mergeSort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;

    cout <<"inversion count " << ans << endl ;

    return 0;
}
*/
